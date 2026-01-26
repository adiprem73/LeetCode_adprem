/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case: if the node is found to be wither p or q then we return p and q and if the node is null then we return null
        if(root == nullptr || root == p ||  root ==q){
            return root;
        }

        // normal
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p,q);

        if(left == nullptr)return right;
        else if(right == nullptr)return left;
        else{ // this is the case wehre neither the left nor the right is null and hence we return the root ot be the lca
            return root;
        }
    }
};