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
    ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if(head==nullptr)return head;
    int size=0;
    ListNode* temp= head;
    while(temp!=nullptr){
        size++;
        temp=temp->next;
    }
    if(size==1){
        if(n<=size){
            return nullptr;
        }
    }
    if(size==2){
        if(n==1){
            head->next=nullptr;
            return head;
        }else if(n==2){
            ListNode* temp=head->next;
            head->next=nullptr;
            delete head;
            return temp;
        }
    }
    // cout<<size<<endl;
    int i= size-n-1;
    temp=head;
    while(i--){
        temp=temp->next;
    }
    ListNode* nodeDelete=temp->next;
    temp->next=temp->next->next;
    delete nodeDelete;
    return head;
}

};