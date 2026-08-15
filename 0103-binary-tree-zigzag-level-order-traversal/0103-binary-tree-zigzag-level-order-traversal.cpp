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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // breadth first search
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> allLevels;
        int x=0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                int val = node->val;
                level.push_back(val);

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(x%2!=0){
                reverse(level.begin(), level.end());
            }
            allLevels.push_back(level);
            x++;
        }
        return allLevels;
    }
};