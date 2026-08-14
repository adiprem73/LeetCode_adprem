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
    int getHeight(TreeNode* root){
        // base case
        if(root==nullptr){
            return 0;
        }


        int left=0, right=0;
        if(root->left){
            left = getHeight(root->left);
        }
        if(root->right){
            right = getHeight(root->right);
        }

        return max(left, right) + 1;
    }


    bool isBalanced(TreeNode* root) {
        // base case
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr)return true;

        int left =0;
        int right =0;

        if(root->left){
            left = getHeight(root->left);
        }
         
        if(root->right){
            right = getHeight(root->right);
        }
        
        return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};