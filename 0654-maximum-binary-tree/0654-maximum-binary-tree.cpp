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
    
TreeNode* construct(vector<int>&nums, int l, int r){
    if(l>r){
        return nullptr;
    }
    int mx=INT_MIN;
    int indMax;
    for(int i=l;i<=r;i++){
        if(nums[i]>mx){
            mx= nums[i];
            indMax= i;
        }
    }
    TreeNode* root = new TreeNode(mx);
    root->left= construct(nums, l, indMax-1);
    root->right= construct(nums, indMax+1, r);
    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return construct(nums, 0, nums.size()-1);
}
};