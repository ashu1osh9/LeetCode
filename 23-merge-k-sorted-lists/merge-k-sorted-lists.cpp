class Solution {
public:

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& a) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            cmp
        > q;

        for (auto x : a) {
            if (x) q.push(x);
        }

        ListNode* d = new ListNode(0);
        ListNode* t = d;

        while (!q.empty()) {

            auto x = q.top();
            q.pop();

            t->next = x;
            t = t->next;

            if (x->next) {
                q.push(x->next);
            }
        }

        return d->next;
    }
};