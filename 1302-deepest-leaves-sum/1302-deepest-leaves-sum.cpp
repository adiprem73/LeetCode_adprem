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
    int deepestLeavesSum(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> tree;
    while(!q.empty()){
        int size= q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            auto node= q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left!= nullptr){
                q.push(node->left);
            }
            if(node->right!= nullptr){
                q.push(node->right);
            }
        }
        tree.push_back(level);
    }
    auto lastLevel= tree[tree.size()-1];
    int sum = accumulate(lastLevel.begin(), lastLevel.end(), 0);
    return sum;
}
};