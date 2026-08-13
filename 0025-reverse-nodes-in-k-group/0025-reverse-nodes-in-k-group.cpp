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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(-1);
        ListNode* prevGroupPtr = dummy;
        dummy->next = head;
        ListNode* temp = dummy->next;

        while (temp != nullptr) {
            ListNode* kthNode = temp;
            for (int i = 1; i < k; i++) {
                if (kthNode == nullptr)
                    break;
                kthNode = kthNode->next;
            }
            if (kthNode == nullptr) {
                break;
            }
            ListNode* nextGroupNode = kthNode->next;
            // we have now preserved the next node to be used. now we can simply
            // reverse the node
            // kthNode->next = nullptr;

            // REVERSING
            ListNode* prevNode = nullptr;
            ListNode* curr = temp;
            while (curr != nextGroupNode) {
                ListNode* nextNode = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nextNode;
            }

            prevGroupPtr->next = kthNode;

            prevGroupPtr = temp;

            temp->next = nextGroupNode;


            temp = nextGroupNode;
        }
        return dummy->next;
    }
};