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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // make a min heap
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        // push the head of each list into the pirority queue
        for (auto it : lists) {
            if (it != nullptr) {
                pq.push(it);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            auto node = pq.top(); // current smalles inside the priority queue
            pq.pop();

            temp->next = node;
            temp = temp->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};