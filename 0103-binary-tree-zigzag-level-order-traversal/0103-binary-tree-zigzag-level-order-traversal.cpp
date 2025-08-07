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
    vector<vector<int>> result; //ds to store the final answer
    if(root==NULL){ //if the tree is empty
        return result;
    }

    queue<TreeNode*> q; //queue to store temporarily the nodes
    q.push(root);
    bool flag= true; //true means left to right insertion and false will do right to left

    while(!q.empty()){
        int size=q.size();
        vector<int> lvl(size);

        for(int i=0;i<size;i++){
            TreeNode * node = q.front();
            q.pop();

            int index= flag ? i : (size-i-1); //this is where its decided whether to push from left to right or roght to left

            lvl[index] = node->val;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        flag= !flag;
        result.push_back(lvl);
    }

    return result;

}
};