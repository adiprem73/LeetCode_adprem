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
    int countNodes(TreeNode* root) {
        // visit node and find lheight and rheight. if htey are equal then use formuale. if not equal. add 1 and traverse leftt and right

        if(root == nullptr)return 0;
        // cout<<"Height : "<<findHeight(root);
        int lh = findLHeight(root);
        int rh = findRHeight(root);

        if(lh == rh)return (1<<lh)-1;

        return 1+ countNodes(root->left) + countNodes(root->right);
    }

    int findLHeight(TreeNode* root){
        int hght =0;

        while(root){
            hght++;
            root= root->left;
        }
        return hght;
    }

    int findRHeight(TreeNode* root){
        int hght =0;

        while(root){
            hght++;
            root= root->right;
        }
        return hght;
    }
};