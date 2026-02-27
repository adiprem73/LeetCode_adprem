/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void func(Node* root, int step, int& ans){
        ans = max(ans, step);
        auto vec = root->children;
        for(auto it: vec){
            func(it, step+1, ans);
        }
    }

    int maxDepth(Node* root) {
        int ans =0;
        if(root == nullptr)return 0;
        func(root, 1, ans);
        return ans;
    }
};