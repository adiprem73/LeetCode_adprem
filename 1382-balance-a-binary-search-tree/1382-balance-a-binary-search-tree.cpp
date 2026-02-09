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
    void inOrder(TreeNode* root, vector<int>& vec){
    if(root== nullptr){
        return;
    }

    inOrder(root->left, vec);
    vec.push_back(root->val);
    inOrder(root->right, vec);
}

TreeNode* construct(vector<int> vec, int l, int r){
    // base case
    if(l>r){
        return nullptr;
    }
    int mid = (l+r)/2;
    TreeNode* node = new TreeNode(vec[mid]);
    node->left= construct(vec, l, mid-1);
    node->right = construct(vec, mid+1, r);
    return node;
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> inorderVector;
    inOrder(root, inorderVector);

    TreeNode* node = construct(inorderVector, 0, inorderVector.size()-1);
    return node;
}
};