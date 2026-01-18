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
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> & inmap)
{

    if(postStart>postEnd || inStart> inEnd)return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int ind_root = inmap[root->val];
    int numsRight = inEnd - ind_root;
    root->right = buildTree(inorder, ind_root+1, inEnd, postorder, postEnd- numsRight , postEnd-1, inmap);

    root->left = buildTree(inorder,inStart ,ind_root-1 , postorder, postStart , postEnd-numsRight-1 , inmap);

    return root;
}

TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder)
{
    // the very first thing we need to do is to hash map the inorder 
    map<int,int> inmap;
    for(int i=0;i<inorder.size();i++){
        inmap[inorder[i]]=i;
    }

    TreeNode *root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inmap);
    return root;
}
};