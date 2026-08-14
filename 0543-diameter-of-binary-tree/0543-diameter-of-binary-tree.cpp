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
    int findMaxi(TreeNode* root, int &maxi){
        // base case
        if(root==nullptr){
            return 0;
        }
        int lh=0, rh=0;

        if(root->left!=nullptr){
            lh = findMaxi(root->left, maxi);
        }
        if(root->right!=nullptr){
            rh = findMaxi(root->right, maxi);
        }
        maxi = max(maxi, lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi =0;
        findMaxi(root, maxi);
        return maxi;
    }
};