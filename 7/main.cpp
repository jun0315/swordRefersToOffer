#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//        TreeNode treeNode = TreeNode(-1);
        TreeNode *treeNode;
        treeNode = (TreeNode *) malloc(sizeof(TreeNode));
        if (preorder.size() == 0) {
            treeNode = NULL;
            return treeNode;
        }
        if (preorder.size() == 1) {
            treeNode->right = NULL;
            treeNode->left = NULL;
            treeNode->val = preorder[0];
            return treeNode;
        }
        int rootVal = preorder[0];
        int rootIndex;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        treeNode->val = inorder[rootIndex];
        vector<int> preorderLeft, preorderRight;
        vector<int> inorderLeft, inorderRight;
        for (int i = 0; i < preorder.size(); i++) {
            if (i < rootIndex) {
                inorderLeft.push_back(inorder[i]);
                preorderLeft.push_back(preorder[i + 1]);
            } else if (i > rootIndex) {
                inorderRight.push_back(inorder[i]);
                if (i < preorder.size() - 1) {
                    preorderRight.push_back(preorder[i + 1]);
                }
            } else {
                if (i < preorder.size() - 1) {
                    preorderRight.push_back(preorder[i + 1]);
                }
            }
        }
        treeNode->left = buildTree(preorderLeft, inorderLeft);
        treeNode->right = buildTree(preorderRight, inorderRight);
        return treeNode;
    }
};

int main() {
//    vector<int> preorder = {3, 9, 20, 15, 7};
//    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3};
    vector<int> inorder = {9};
    Solution solution;
    TreeNode *treeNode = solution.buildTree(preorder, inorder);
    cout << treeNode->val;
}
