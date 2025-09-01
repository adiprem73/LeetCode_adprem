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
    TreeNode* insertIntoBST(TreeNode* root, int key){
    if(root==NULL)return new TreeNode(key);
    TreeNode* temp=root; //making a copy since we need ot return the root

    while(true){
        if(temp->val>key){
            if(temp->left!=NULL)temp=temp->left;

            else{
                temp->left= new TreeNode(key);
                break;
            }
        }
        else{
            if(temp->right!=NULL)temp=temp->right;

            else{
                temp->right= new TreeNode(key);
                break;
            }
        }
    }
    return root;
}
};