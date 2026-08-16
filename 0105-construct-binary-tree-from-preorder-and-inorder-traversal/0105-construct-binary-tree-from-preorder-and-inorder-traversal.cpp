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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int>& mp){
        // base case
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]); // will always b the root node

        int inRoot = mp[preorder[preStart]];
        int numsToLeft = inRoot - inStart;

        root->left = build(preorder, inorder, preStart+1, preStart+numsToLeft, inStart, inRoot-1, mp);
        root->right = build(preorder, inorder, preStart+numsToLeft+1, preEnd, inRoot+1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // hashing
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
    }
};