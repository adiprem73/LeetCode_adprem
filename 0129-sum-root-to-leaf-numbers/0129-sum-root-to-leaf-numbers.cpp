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
    void helper(TreeNode* root, vector<int> &currentPath, vector<vector<int>>& paths){
    // base case
    if(root==nullptr){
        return;
    }
    currentPath.push_back(root->val);
    if(root->left==nullptr && root->right==nullptr){
        paths.push_back(currentPath);
    }

    
    if(root->left){
        helper(root->left, currentPath, paths);
    }

    if(root->right){
        helper(root->right, currentPath, paths);
    }
    currentPath.pop_back();
}

int sumNumbers(TreeNode *root)
{
    vector<vector<int>> paths;
    vector<int> currentPath;
    
    helper(root, currentPath, paths);
    int sum=0;
    for(auto it: paths){
        int num=0;
        for(auto itr: it){
            num=num*10 + itr;
        }
        sum+=num;
    }return sum;
}
};