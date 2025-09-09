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
    ListNode *deleteMiddle(ListNode *head)
{
    //first find the middle using tortroise hare method
    if(head==nullptr){
        return nullptr;
    }
    if(head->next== nullptr){
        ListNode* ln= nullptr;
        return ln;
    }
    ListNode* fast=head;
    ListNode* slow=head;
    // we can modify the hare tortoise into givinf the node just before the slow node or the middle node

    ListNode* prev=nullptr;
    while(fast&& fast->next){
        prev=slow;
        slow = slow->next;
        fast=fast->next->next;
    }
    // now prev->next is the node to be delete
    // cout<<slow->val<<endl;
    ListNode* nodeToBeDeleted= prev->next;
    prev->next= prev->next->next;
    delete nodeToBeDeleted;
    return head;
}
};