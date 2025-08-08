/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root)
{
    if(!root)return{};
    // normal level order traversal
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> lvl;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            lvl.push_back(node->val);

            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
        ans.push_back(lvl);
    }
    vector<int> final;
    for (int i = 0; i < ans.size(); i++)
    {
        final.push_back(ans[i][ans[i].size() - 1]);
    }
    return final;
}
};