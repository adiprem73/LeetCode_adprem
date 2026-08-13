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
    bool isPalindrome(ListNode* head) {
        // optimal way to do this --> find the middle of the LL --> reverse the second half of the LL --> iteratre through the two halves and check if we find any mismatch

        // 1. to find the middle of the LL: tortoise and ahre appraoch
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= nullptr && fast->next != nullptr){
            slow= slow->next;
            fast= fast->next->next;
        }

        cout<<slow->val<<endl;
        // so slow s the middle of the ll
        // reversing the linked list

        ListNode* temp = slow;
        ListNode* prevNode = nullptr;
        while(temp!=nullptr){
            ListNode* nextNode = temp->next;
            temp->next = prevNode;
            prevNode=  temp;
            temp = nextNode;
        }



        ListNode* p1 = head;
        ListNode* p2 = prevNode;
        while(p1!=nullptr && p2!= nullptr){
            if(p1->val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};