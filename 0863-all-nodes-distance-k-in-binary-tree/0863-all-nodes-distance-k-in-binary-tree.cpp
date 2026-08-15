/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        // markign the parents-> we will need to use a BFS 
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto parent = q.front();
                q.pop();
                if(parent->left){
                    q.push(parent->left);
                    parentOf[parent->left] = parent;
                }
                if(parent->right){
                    q.push(parent->right);
                    parentOf[parent->right] = parent;
                }
            }
        }


        // now that the parent i smarked, we can move back from the child to the parent as well, and therefore, we can do proper breadth first search in the trrree

        queue<TreeNode*> qu;
        qu.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target]= true;
        int currLevel =0;
        while(!qu.empty()){
            int size = qu.size();
            if(currLevel==k)break;
            currLevel ++;
            for(int i=0;i<size;i++){
                auto node = qu.front();
                qu.pop();

                // moving left
                if(node->left != nullptr && !visited[node->left]){
                    qu.push(node->left);
                    visited[node->left]= true;
                }
                // moving right
                if(node->right != nullptr && !visited[node->right]){
                    qu.push(node->right);
                    visited[node->right]= true;
                }
                // parent check
                if(parentOf[node] && !visited[parentOf[node]]){
                    qu.push(parentOf[node]);
                    visited[parentOf[node]] = true;
                }
            }
        }

        vector<int> result;
        while(!qu.empty()){
            TreeNode* node = qu.front();
            qu.pop();
            result.push_back(node->val);
        }
        return result;
    }
};