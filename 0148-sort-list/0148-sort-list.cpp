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
private:
    ListNode* findMiddle(ListNode* node){
        ListNode* slow = node;
        ListNode* fast = node->next; // this is so sthat we get the first middle

        while(fast!= nullptr && fast->next != nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* node1, ListNode* node2){
        ListNode* p1= node1;
        ListNode* p2 = node2;
        // we will also use a dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val < p2->val){
                temp->next = p1;
                temp = p1;
                p1=p1->next;
            }else{
                temp->next = p2;
                temp = p2;
                p2 = p2->next;
            }
        }
        if(p1)temp->next = p1;
        else temp->next = p2;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);
        return mergeLists(left, right);
    }
};