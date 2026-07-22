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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    // Calculate the size of the linked list
    int size = 0;
    ListNode *temp = head;

    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }

    int partSize = size / k;
    int extra = size % k;

    vector<ListNode *> ans;

    for (int i = 0; i < k; i++)
    {
        // If there are no nodes left
        if (head == nullptr)
        {
            ans.push_back(nullptr);
            continue;
        }

        int currSize;
        if (i < extra)          // FIX 1: < instead of <=
            currSize = partSize + 1;
        else
            currSize = partSize;

        ListNode *temp = head;

        // Move to the last node of this part
        for (int j = 1; j < currSize; j++)   // or j = 0; j < currSize-1;
        {
            temp = temp->next;
        }

        ListNode *nextNode = temp->next;
        temp->next = nullptr;

        ans.push_back(head);

        head = nextNode;
    }

    return ans;
}
};