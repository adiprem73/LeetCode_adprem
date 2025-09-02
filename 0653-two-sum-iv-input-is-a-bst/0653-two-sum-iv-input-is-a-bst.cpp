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
    void pushAllLeft(TreeNode* node, stack<TreeNode*> &st){
    while(node){
        st.push(node);
        node=node->left;
    }
}

void pushAllRight(TreeNode* node, stack<TreeNode*> &st){
    while(node){
        st.push(node);
        node=node->right;
    }
}


bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    pushAllLeft(root, st1); //smallest
    pushAllRight(root, st2); //largest
    while(!st1.empty() && !st2.empty() && st1.top()!=st2.top()){
        int sum=st1.top()->val + st2.top()->val;
        if(sum == k)return true;

        else if(sum<k){
            TreeNode* node=st1.top();
            st1.pop();
            pushAllLeft(node->right, st1);
        }

        else{
            TreeNode* node= st2.top();
            st2.pop();
            pushAllRight(node->left, st2);
        }
    }
    return false;
}
};