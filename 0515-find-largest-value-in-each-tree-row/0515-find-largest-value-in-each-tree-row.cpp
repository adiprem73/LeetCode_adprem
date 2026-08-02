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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // vector<vector<int>> fin;
        while(!q.empty()){
            int size = q.size();
            int mx = INT_MIN;
            // vector<int> level={};
            for(int i=0;i<size;i++){
                auto f= q.front();
                q.pop();
                int val = f->val;
                mx= max(mx, val);
                // level.push_back(val);

                // left explore
                if(f->left != nullptr){
                    q.push(f->left);
                }
                
                //right explore
                if(f->right != nullptr){
                    q.push(f->right);
                }
            }
            // fin.push_back(level);
            ans.push_back(mx);

        }


        
        // for(auto it: fin){
        //     int mx = INT_MIN;
        //     for(auto itr: it){
        //         cout<<itr<<" ";
        //         mx= max(mx, itr);
        //     }
        //     cout<<endl;
        //     ans.push_back(mx);
        // }

        return ans;
    }
};