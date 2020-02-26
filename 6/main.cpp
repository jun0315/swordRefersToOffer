#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> list;

    vector<int> reversePrint(ListNode *head) {
        // vector 反转
        /*
        vector<int> list1;
        if (head == NULL) {
            return list1;
        }
        list1.push_back(head->val);
        while ((head = head->next) != NULL) {
            list1.push_back(head->val);
        }
        vector<int> list2;
        for (int i = list1.size() - 1; i >= 0; i--) {
            list2.push_back(list1[i]);
        }
        return list2;

         */

        // 递归
        if (head == NULL) {
            return list;
        }
        reversePrint(head->next);
        list.push_back(head->val);
        return list;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
