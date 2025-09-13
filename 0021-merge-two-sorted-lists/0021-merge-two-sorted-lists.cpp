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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode* t1= list1;
    ListNode* t2= list2;
    ListNode* dummy = new ListNode(0);
    ListNode* ans= dummy;

    while(t1 && t2){
        if(t1->val<=t2->val){
            ans->next= t1;
            t1=t1->next;
        }else{
            ans->next= t2;
            t2=t2->next;
        }
        ans=ans->next;
    }
    ans->next= (t1)? t1:t2;
    return dummy->next;
}
};