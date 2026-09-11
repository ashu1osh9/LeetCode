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
    vector<pair<int,ListNode*>> a;

    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;

        while(temp != NULL) {
            a.push_back({temp->val, temp});
            temp = temp->next;
        }

        sort(a.begin(), a.end());

        if(a.size() == 0) return NULL;

        for(int i = 0; i < a.size() - 1; i++) {
            a[i].second->next = a[i + 1].second;
        }

        a[a.size() - 1].second->next = NULL;

        return a[0].second;
    }
};