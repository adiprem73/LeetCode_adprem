/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // since we cannot delete normally, we would use copy the value to the rpesent node
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        nextNode->next = nullptr;
    }
};