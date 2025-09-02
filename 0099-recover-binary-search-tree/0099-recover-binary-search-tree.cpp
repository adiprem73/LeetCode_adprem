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
    
void inOrderTraversal(TreeNode* root, vector<TreeNode*>& inOrder){
    if(root==nullptr)return;

    inOrderTraversal(root->left, inOrder);
    inOrder.push_back(root);
    inOrderTraversal(root->right, inOrder);
}

void recoverTree(TreeNode* root) {
    //first we will perform an inorder traversal on the tree
    vector<TreeNode*> inOrder;
    inOrderTraversal(root, inOrder);
    vector<TreeNode*> defects;
    for(int i=0;i<inOrder.size()-1;i++){
        if(inOrder[i]->val>inOrder[i+1]->val){
            defects.push_back(inOrder[i]);
            defects.push_back(inOrder[i+1]);
        }
    }
    if(defects.size()==2){
        swap(defects[0]->val, defects[1]->val);
    }
    else{
        swap(defects[0]->val, defects[3]->val);
    }
}
};