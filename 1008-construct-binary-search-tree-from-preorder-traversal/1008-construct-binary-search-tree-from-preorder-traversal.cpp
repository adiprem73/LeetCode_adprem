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
    TreeNode* insertion(TreeNode* root, int val){
    if(root==NULL) return new TreeNode(val);
    if(root->val>val){
        root->left= insertion(root->left, val);
    }else{
        root->right= insertion(root->right, val);
    }
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.size()==0)return nullptr;
    TreeNode* root= new TreeNode(preorder[0]);
    for(int i=0;i<preorder.size();i++){
        insertion(root, preorder[i]);
    }

    return root;
}
};