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
    void travel(TreeNode* node, int r, int c, map<int, map<int, multiset<int>>> &mp){
        if(node==nullptr)return;

        mp[c][r].insert(node->val);
        if(node->left){
            travel(node->left, r+1, c-1, mp);
        }
        if(node->right){
            travel(node->right, r+1, c+1, mp);
        }
    }



    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        travel(root, 0, 0, mp);      
        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> curr;
            for(auto itr: it.second){
                auto st = itr.second;
                while(st.size() != 0){
                    auto i = st.begin();
                    curr.push_back(*i);
                    st.erase(i);
                }            
            }
            ans.push_back(curr);
        }
        return ans;
    }
};