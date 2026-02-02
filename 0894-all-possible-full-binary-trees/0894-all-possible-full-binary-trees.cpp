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
    vector<TreeNode*> solve(int n){
    // base case
    if(n==1){
        return {new TreeNode(0)};
    }

    // make a vectore of treenodes to store the trees
    vector<TreeNode*> res;
    for(int leftNodes = 1;leftNodes<n;leftNodes+=2){
        int rightNodes = n-1-leftNodes;

        auto leftTrees = solve(leftNodes);
        auto rightTrees = solve(rightNodes);

        for(auto l : leftTrees){
            for(auto r : rightTrees){
                TreeNode* root = new TreeNode(0);

                root->left = l;
                root->right = r;
                res.push_back(root);
            }
        }
    }
    return res;
}


vector<TreeNode*> allPossibleFBT(int n) {
    vector<TreeNode*>  ans;
    if(n%2 == 0){
        return ans;
    }
    return solve(n);
}
};