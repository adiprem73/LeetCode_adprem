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
    void inorderHelper(TreeNode* root, vector<int> &nums){
    if(root==NULL){
        return;
    }

    inorderHelper(root->left, nums);
    nums.push_back(root->val);
    inorderHelper(root->right,nums);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nums;
    inorderHelper(root, nums);
    return nums;
}

};