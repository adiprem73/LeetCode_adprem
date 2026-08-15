class Solution {
public:

    void travel(TreeNode* node, int r, int c,
                map<int, vector<pair<int,int>>>& mp) {

        if (!node) return;

        mp[c].push_back({r, node->val});

        travel(node->left, r + 1, c - 1, mp);
        travel(node->right, r + 1, c + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, vector<pair<int,int>>> mp;

        travel(root, 0, 0, mp);

        vector<vector<int>> ans;

        for (auto &col : mp) {

            auto &nodes = col.second;

            sort(nodes.begin(), nodes.end());

            vector<int> curr;

            for (auto &[row, value] : nodes) {
                curr.push_back(value);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};