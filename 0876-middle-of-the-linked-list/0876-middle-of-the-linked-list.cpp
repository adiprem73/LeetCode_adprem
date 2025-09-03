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
    ListNode *middleNode(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    // cout<<cnt;
    ListNode *temp2 = head;
    int cnt2 = 0;
    while (temp2)
    {
        cnt2++;
        if (cnt2 == cnt / 2 + 1)
            return temp2;
        temp2 = temp2->next;
    }

    return head;
}
};