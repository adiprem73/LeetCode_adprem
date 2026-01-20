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
    void dfs(TreeNode* node, int targetSum, int curSum, vector<vector<int>>& ans, vector<int> curr){
    if (node == nullptr)
    {
        return;
    }

    curr.push_back(node->val);
    curSum+= node->val;

    // if leaf node
    if(node->left==nullptr && node->right== nullptr){
        if(curSum== targetSum){
            ans.push_back(curr);
        }
    }

    dfs(node->left, targetSum, curSum, ans, curr);
    dfs(node->right, targetSum, curSum, ans, curr);
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    if(root == nullptr)return ans;

    vector<int> curr;
    dfs(root, targetSum, 0, ans, curr);
    return ans;
}
};