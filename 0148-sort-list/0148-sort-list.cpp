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
    ListNode* findMiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* node1, ListNode* node2){
    //this is the part where we would merge two linked lists in merge sort fashio
    ListNode* dummy= new ListNode(0); //we often take a dummy list starting from 0 to properly store the answer. we will return dummy->next at the end of the program

    ListNode* temp=dummy; //this will basiclaly be used as a ptr to traverse on dummy
    while(node1 && node2){
        if(node1->val<node2->val){
            temp->next=node1;
            node1=node1->next;
        }else{
            temp->next=node2;
            node2=node2->next;
        }
        temp=temp->next; //after every assignment we move the temp forward
    }
    temp->next = (node1) ? node1 : node2;// this will append any remaining node. there will be atmoset 1 remaining node
    return dummy->next;
}


ListNode* sortList(ListNode *head){

    if(!head || !head->next)return head; //if the ll is empty or has only one node then return that only

    ListNode* mid= findMiddle(head);
    // cout<<mid->val<<endl;
    ListNode* righthalf= mid->next;
    mid->next= nullptr; //to split them into two halves

    ListNode* leftSorted= sortList(head);
    ListNode* rightSorted= sortList(righthalf);

    return merge(leftSorted, rightSorted);

}
};