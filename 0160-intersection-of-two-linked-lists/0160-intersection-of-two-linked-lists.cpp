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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    vector<ListNode*> visited;
    ListNode* ans;
    while(headA || headB){
        if(headA){
            if(find(visited.begin(), visited.end(), headA)!=visited.end()){
                return headA;
            }
            visited.push_back(headA);
            headA=headA->next;
        }
        if(headB){
            if(find(visited.begin(), visited.end(), headB)!= visited.end()){
                return headB;
            }
            visited.push_back(headB);
            headB=headB->next;
        }
        
    }
    return nullptr;
}
};