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

    int findMaxPath(TreeNode* root, int& maxPath){
    if(root==NULL)return 0;
    int leftsum= max(0,findMaxPath(root->left, maxPath));
    int rightsum= max(0,findMaxPath(root->right, maxPath));
    maxPath= max(maxPath, leftsum+rightsum+root->val);
    return (root->val) + max(leftsum, rightsum);
}


int maxPathSum(TreeNode* root) {
    int maxPath=INT_MIN;
    findMaxPath(root, maxPath);
    return maxPath;
}
};