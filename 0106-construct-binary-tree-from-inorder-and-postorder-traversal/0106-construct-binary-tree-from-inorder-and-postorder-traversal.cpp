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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int>& mp){
        // base case
        if(inStart>inEnd || postStart > postEnd)return nullptr;
        int inRoot = mp[postorder[postEnd]];
        int shift = inEnd-inRoot;

        TreeNode* root = new TreeNode(inorder[inRoot]);

        root->left = build(inorder, postorder, inStart, inRoot-1, postStart, postEnd-shift-1, mp);
        root->right = build(inorder, postorder, inRoot+1, inEnd, postEnd-shift, postEnd-1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, mp);
    }
};