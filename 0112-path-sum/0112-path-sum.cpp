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
    bool dfs(TreeNode* node, int targetSum, int curSum){
    if(node == nullptr)return false;

    curSum+=node->val;

    if(node->left==nullptr && node->right==nullptr){
        return curSum==targetSum;
    }

    return dfs(node->left, targetSum, curSum) || dfs(node->right, targetSum, curSum);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    if(root== nullptr) return false;
    // int curSum=root->val;
    return dfs(root, targetSum, 0);
}
};