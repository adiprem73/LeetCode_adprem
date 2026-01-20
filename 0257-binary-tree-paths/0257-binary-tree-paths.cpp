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
    void dfs(TreeNode* node, string cur, vector<string>& ans){
    if(!node){
        return;
    }

    cur = cur + "->" + to_string(node->val);
    if(node->left== nullptr && node->right==nullptr){
        ans.push_back(cur);
    }
    // cout << cur<< endl;

    
    dfs(node->left, cur, ans);
    dfs(node->right, cur, ans);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    // cout << "hello" << endl;
    string s= "";
    dfs(root, s, ans);
    for(string &s: ans){
        s= s.substr(2);
    }
    return ans;
}
};