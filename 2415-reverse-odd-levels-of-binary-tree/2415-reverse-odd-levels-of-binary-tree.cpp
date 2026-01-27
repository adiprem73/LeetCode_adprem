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
    void reverse(vector<TreeNode*> &level){
    int s=0, e= level.size()-1;
    while(s<e){
        swap(level[s]->val, level[e]->val);
        s++;
        e--;
    }
}

TreeNode *reverseOddLevels(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    bool odd= false;
    while(!q.empty()){
        int size= q.size();
        vector<TreeNode*> level;
        for(int i=0;i<size;i++){
            auto node= q.front();
            q.pop();
            level.push_back(node);
            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }
        if(odd){
            reverse(level);
        }
        odd=!odd;
    }
    return root;
}
};