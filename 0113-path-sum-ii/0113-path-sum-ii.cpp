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
    void dfs(TreeNode* node, int targetSum, vector<int> curPath,  vector<vector<int>>& ans){
        // base case
        if(node==nullptr){
            return;
        }
        if(node->left == nullptr && node->right == nullptr){
            if(node->val == targetSum){
                curPath.push_back(node->val);
                ans.push_back(curPath);
                curPath.pop_back();
                return;
            }
        }

        // if(targetSum<0){
        //     return;
        // }

        if(node->left!= nullptr){
            curPath.push_back(node->val);
            dfs(node->left, targetSum-(node->val), curPath, ans);
            // backtracking
            curPath.pop_back();
        }
        if(node->right!= nullptr){
            curPath.push_back(node->val);
            dfs(node->right, targetSum-(node->val), curPath, ans);
            // backtracking
            curPath.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};