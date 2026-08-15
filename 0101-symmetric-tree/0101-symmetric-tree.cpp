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
    bool check(TreeNode* ptr1, TreeNode* ptr2){
        // base cases
        if(ptr1 == nullptr && ptr2 == nullptr)return true;
        if(ptr1==nullptr && ptr2 != nullptr)return false;
        if(ptr1!=nullptr && ptr2 == nullptr)return false;

        if(ptr1->val != ptr2->val )return false;

        int one = check(ptr1->left, ptr2->right);
        int two = check(ptr1->right, ptr2->left);
        return one && two;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        if(root->left ==nullptr && root->right == nullptr)return true;

        return check(root->left, root->right);
    }
};