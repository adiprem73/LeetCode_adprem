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
const long long MOD = 1e9+7;
public:
    void postOrderSum(TreeNode* root, long long &totalSum){
    if(root== nullptr)return;

    postOrderSum(root->left, totalSum);
    postOrderSum(root->right, totalSum);
    totalSum+=root->val;
}

long long maxSum(TreeNode* root, long long sum, long long totalSum, long long &ans){
    if(root == nullptr)return 0;
    long long leftSum= maxSum(root->left, sum, totalSum, ans);
    long long rightSum= maxSum(root->right, sum, totalSum, ans);
    sum=root->val + leftSum + rightSum;
    long long sum2= totalSum-sum;
    ans= max(ans, (sum*sum2));
    return sum;
}

int maxProduct(TreeNode *root)
{
    long long totalSum=0;
    postOrderSum(root, totalSum);
    long long sum=0;
    long long ans= LLONG_MIN;
    maxSum(root, sum, totalSum, ans);
    return (int)(ans%MOD);
}
};