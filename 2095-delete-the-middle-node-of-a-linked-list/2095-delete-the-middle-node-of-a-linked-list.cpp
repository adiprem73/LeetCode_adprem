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
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowTail = nullptr;
        while(fast!=nullptr && fast->next!= nullptr){
            slowTail = slow;
            slow = slow->next;
            fast = fast->next->next;
        }


        // now slow is the middle
        // we need to delete it

        // edge cases:
        if(head==nullptr)return nullptr;
        if(head->next == nullptr)return nullptr;
        

        slowTail->next = slowTail->next->next;
        slow->next = nullptr;

        return head;
    }
};