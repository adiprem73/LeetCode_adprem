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
    bool hasCycle(ListNode *head) {
    vector<ListNode*> visited;
    while(head!=nullptr){
        if(find(visited.begin(), visited.end(), head)!= visited.end()){
            return true;
        }
        visited.push_back(head);
        head = head->next;
    }
    return false;
}
};