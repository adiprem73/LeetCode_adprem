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
    ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = head; // when they meet we have to keep sloe there only and then take fast back to the start that is head of the linked list and then start moving them one step at a time. the pt where they meet now will be the start of the loop
            while (true)
            {
                if (slow == fast)
                {
                    return slow;
                }
                slow = slow->next;
                fast = fast->next;
                
            }
        }
        
    }return nullptr;
}

};