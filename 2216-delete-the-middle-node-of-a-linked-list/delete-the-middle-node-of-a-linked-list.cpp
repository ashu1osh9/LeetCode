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
    ListNode* deleteMiddle(ListNode* head) {

        // single node case
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* temp = head;
        int count = 0;

        // count nodes
        while(temp){
            count++;
            temp = temp->next;
        }

        int mid = count / 2;

        temp = head;
        ListNode* prev = NULL;

        // reach middle node
        for(int i = 0; i < mid; i++){
            prev = temp;
            temp = temp->next;
        }

        // delete middle
        prev->next = temp->next;
        delete temp;

        return head;
    }
};