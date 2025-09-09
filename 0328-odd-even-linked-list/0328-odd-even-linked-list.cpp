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
    ListNode *oddEvenList(ListNode *head)
{
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr){
        return head;
    }
    if(head->next->next==nullptr){
        return head;
    }
    // we will maintain two seperate linked lists and then join them after the process
    int cnt=1;
    ListNode* temp=head;
    ListNode* odd=head;
    ListNode* even=head->next;
    ListNode* rememberEvenHead= even;
    temp=temp->next->next;
    while(temp!=nullptr){
        if(cnt%2==1){
            odd->next=temp;
            odd=odd->next;
        }else{
            even->next=temp;
            even=even->next;
        }
        temp=temp->next;
        cnt++;
    }
    even->next= nullptr;
    odd->next= rememberEvenHead;
    return head;

}
};