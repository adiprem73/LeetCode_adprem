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
    ListNode * getIntersectionNode(ListNode* headA, ListNode* headB){
    int sizeA=0; //5
    ListNode* t1= headA;
    while(t1){
        sizeA++;
        t1=t1->next;
    }
    int sizeB = 0; //5
    ListNode *t2 = headB;
    while (t2)
    {
        sizeB++;
        t2 = t2->next;
    }
    ListNode* temp = (sizeA>sizeB)? headA: headB;
    ListNode *temp2 = (sizeA < sizeB) ? headA : headB;
    if(sizeA== sizeB){
        temp= headA;
        temp2= headB;
    }
    int cnt=abs(sizeA-sizeB);
    while(cnt--){
        temp=temp->next;
    } 
    while(temp && temp2){
        if(temp==temp2){
            return temp;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return nullptr;
}
};