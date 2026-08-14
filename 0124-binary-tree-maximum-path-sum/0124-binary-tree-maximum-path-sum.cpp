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

    int func(TreeNode* root, int& maxi){
        if(root==nullptr){
            return 0;
        }
        int left=0, right=0;
        if(root->left!=nullptr){
            left = max(0, func(root->left, maxi));
        }
        if(root->right!=nullptr){
            right = max(0, func(root->right, maxi));
        }
        maxi=max(maxi, left+right+root->val);
        return max(left, right)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        func(root, maxi);
        return maxi;
    }
};