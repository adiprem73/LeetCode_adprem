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
    int widthOfBinaryTree(TreeNode* root) {
        // we want to index it. so that we can just find the difference between the first node and last ndoe indexes and then add one to get the anser
        // HOW TO DO THE INDEXING?
        // we need to do BFS
        if(!root)return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans =0;
        while(!q.empty()){
            int size = q.size();
            long long levelMin= q.front().second;
            int last, first;
            for(int i=0;i<size;i++){
                auto temp = q.front();
                auto node = temp.first;
                auto ind = temp.second - levelMin;
                q.pop();
                // for finding the first and last in a lvel
                if(i==0) first = ind;
                if(i==size-1) last = ind;

                // treaversal
                if(node->left){
                    q.push({node->left, ind*2 + 1});
                }
                if(node->right){
                    q.push({node->right, ind*2 + 2});
                }
            }
            ans = max(ans, last - first +1);
        }
        return ans;
    }
};