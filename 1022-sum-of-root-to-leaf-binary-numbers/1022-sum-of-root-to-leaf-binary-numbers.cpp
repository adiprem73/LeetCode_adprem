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
    void dfs(TreeNode* node, int step, int num, vector<int>& ans){
    if(node == nullptr){
        return;
    }
    num= 2*num + node->val;
    // base case
    if(node->left== nullptr && node->right==nullptr){
        ans.push_back(num);
        return;
    }
    dfs(node->left, step+1, num, ans);
    dfs(node->right, step+1, num, ans);
}

int sumRootToLeaf(TreeNode *root)
{
    vector<int> nums;
    dfs(root, 0, 0, nums);
    int ans = accumulate(nums.begin(), nums.end(), 0);
    return ans;
}
};