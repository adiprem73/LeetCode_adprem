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
    ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head;
    ListNode* temp = head;
    int n =0;
    while(temp!=nullptr){
        n++;
        temp=temp->next;
    }
    k = k % n;
    while (k--) {
        ListNode* last = head;
        ListNode* prev = nullptr;

        // find last and second last
        while (last->next) {
            prev = last;
            last = last->next;
        }

        // detach last
        prev->next = nullptr;

        // move last to front
        last->next = head;
        head = last;
    }

    return head;
}
};