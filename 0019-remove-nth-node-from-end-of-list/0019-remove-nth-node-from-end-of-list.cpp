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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len =0; //5
        ListNode* temp = head;
        while(temp!= nullptr){
            temp = temp->next;
            len++;
        }
        // Removing head
        if (n == len) {
            return head->next;
        }


        if(len == 1 && n == 1)return nullptr;
        if(len == 1)return head;
        cout<<len<<endl;
        int nodeRemoved = len - n - 1;
        temp = head;
        while(nodeRemoved--){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};