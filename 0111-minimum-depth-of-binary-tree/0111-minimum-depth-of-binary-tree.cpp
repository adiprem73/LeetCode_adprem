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
    int minDepth(TreeNode* root) {
    if(!root) return 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,1});
    int cnt=0;
    int ans=INT_MAX;
    // cout<<"Hello"<<endl;
    while(!q.empty()){
        
        int size= q.size();
        for(int i=0;i<size;i++){
            auto node = q.front();
            q.pop();
            // cout<<node.first->val<<" "<<node.second<<endl;
            if(node.second!=1 && node.first->left==nullptr && node.first->right==nullptr){
                // cout<<"prem"<<endl;
                return node.second;
                break;
            }
            if(node.first->left){
                q.push({node.first->left, node.second+1});
            }
            if(node.first->right){
                q.push({node.first->right, node.second+1});
            }

        }
    }
    return 1;
}
};