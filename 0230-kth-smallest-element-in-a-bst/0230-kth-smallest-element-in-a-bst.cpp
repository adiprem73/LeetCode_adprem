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
    int inorder(TreeNode* root, int &cnt, int k){
    if(root==NULL)return -1 ;
    int left=inorder(root->left, cnt, k);
    if(left!=-1) return left;

    cnt++;
    if(cnt==k){
        return root->val;
    }
    // cout<<root->val<<endl;
    return inorder(root->right, cnt, k);

}

int kthSmallest(TreeNode* root, int k) {
    int cnt=0;
    return inorder(root, cnt, k);
}
};