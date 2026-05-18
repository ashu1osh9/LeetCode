/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) {
            return head;
        }

        ListNode* left = head;
        ListNode* right = left->next;

        while(right != NULL) {

            if(left->val == right->val) {

                right = right->next;
            }
            else {

                left->next = right;
                left = right;
                right = right->next;
            }
        }

        left->next = NULL;

        return head;
    }
};