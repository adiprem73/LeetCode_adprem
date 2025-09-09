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
    bool isPalindrome(ListNode *head)
{
    //finding the midpoint with tortoise and rabbit approach
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    //now we know that the slow node is the middle node. now we need to reverse the 2nd part of the ll

    ListNode* curr= slow->next;
    ListNode* prev= nullptr;
    if(slow->next==nullptr){
        if(slow->val==head->val)return true;
        return false;
    }
    // cout<<"middle: "<<slow->val<<endl;
    while(curr!= nullptr){
        ListNode* nextNode= curr->next;
        curr->next= prev;
        prev= curr;
        curr= nextNode;
    }
    // now the 2nd part of the loop is reversed

    ListNode* node1= head;
    ListNode* node2= prev;
    // cout<<"node1: "<<node1->val<<endl;
    // cout << "node2: " << node2->val<<endl;

    //comparing the two halves
    while(node2){ //since node 2 will always be the shorter half
        if(node1->val!=node2->val){
            return false;
        }
        node1=node1->next;
        node2=node2->next;
    }
    return true;
}
};