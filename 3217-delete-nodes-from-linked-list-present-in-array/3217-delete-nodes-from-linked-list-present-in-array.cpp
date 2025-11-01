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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

    unordered_set<int> st(nums.begin(), nums.end());
    while (st.count(head->val))
    {
        ListNode* temp2= head;
        head=head->next;
        temp2->next=nullptr;
    }
    ListNode *temp = head;
    
    while(temp->next){
        int value= temp->next->val;
        if(st.count(value)){
            ListNode* temp3= temp->next; // this is the node that is to be deleted
            temp->next= temp->next->next; // skipped over the to be deleted node
            delete temp3;
        }else{
            temp=temp->next;
        }   
    }
    cout << "hello" << endl;
    return head;
}
};