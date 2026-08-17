class Solution {
public:
    TreeNode* func(vector<int>& preorder, vector<int>& inorder,
                   int inStart, int inEnd,
                   int preStart, int preEnd,
                   unordered_map<int,int>& mp) {

        if (inStart > inEnd || preStart > preEnd)
            return nullptr;

        int rootValue = preorder[preStart];
        int inRoot = mp[rootValue];

        int numsToLeft = inRoot - inStart;

        TreeNode* node = new TreeNode(rootValue);

        node->left = func(
            preorder, inorder,
            inStart, inRoot - 1,
            preStart + 1,
            preStart + numsToLeft,
            mp
        );

        node->right = func(
            preorder, inorder,
            inRoot + 1, inEnd,
            preStart + numsToLeft + 1,
            preEnd,
            mp
        );

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        unordered_map<int,int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return func(
            preorder, inorder,
            0, inorder.size() - 1,
            0, preorder.size() - 1,
            mp
        );
    }
};