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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    int left=0, top=0, right = n-1, down = m-1;

    vector<vector<int>> ans(m, vector<int>(n, -1));
    while (top <= down && left <= right &&  head!=nullptr)
    {
        for (int i = left; i <= right; i++)
        {
            if(head== nullptr)break;
            ans[top][i] = head->val;
            head=head->next;
        }
        top++;

        for (int i = top; i <= down; i++)
        {
            if(head== nullptr)break;
            ans[i][right] = head->val;
            head= head->next;
        }
        right--;

        if (top <= down)
        {
            for (int i = right; i >= left; i--)
            {
                if(head== nullptr)break;
                ans[down][i] = head->val;
                head = head->next;
            }
            down--;
        }

        if (left <= right)
        {
            for (int i = down; i >= top; i--)
            {
                if(head== nullptr)break;
                ans[i][left] = head->val;
                head= head->next;
            }
            left++;
        }
    }
    return ans;
}
};