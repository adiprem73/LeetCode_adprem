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
        if (!head)
            return head;
        if (!head->next)
            return head;

        
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        k = k % size;

        if(k==0)return head;

        int x = size - k - 1;
        ListNode* temp2 = head;
        while (x--) {
            temp2 = temp2->next;
        }
        ListNode* tail = temp2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        ListNode* headNode = temp2->next;
        temp2->next = nullptr;
        tail->next = head;

        head = headNode;
        return head;
    }
};