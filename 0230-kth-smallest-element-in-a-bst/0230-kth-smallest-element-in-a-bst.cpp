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
    void func(TreeNode* node, int &k, int &ans){
        // base case
        if(!node)return;
        
        // visit left
        func(node->left, k, ans);

        // if already found-> return
        if(k==0)return;

        k--;

        if(k==0){
            ans = node->val;
            return;
        }

        func(node->right, k, ans);

    }

    int kthSmallest(TreeNode* root, int k) {
        int ans =0;
        func(root, k, ans);
        return ans;
    }
};