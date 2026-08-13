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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        if(!head->next)return head;
        int size=0;
        ListNode* temp = head;
        while(temp!= nullptr){
            temp=temp->next;
            size++;
        }
        k = k%size;
        while (k--) {
            // rotating once

            ListNode* secondLastNode = head;
            while (secondLastNode!=nullptr && secondLastNode->next!=nullptr && secondLastNode->next->next != nullptr) {
                secondLastNode = secondLastNode->next;
            }
            ListNode* lastNode = secondLastNode->next;
            secondLastNode->next = nullptr;
            lastNode->next = head;
            head = lastNode;
        }
        return head;
    }
};