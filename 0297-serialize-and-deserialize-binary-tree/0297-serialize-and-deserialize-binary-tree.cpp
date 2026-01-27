class Codec
{
private:
    void dfs(TreeNode* root, string &ans){
        if(root== nullptr){
            ans+=",null";
            return;
        }
        ans+=","+ to_string(root->val) ;
        
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    vector<string> split(const string & s, char delimiter){
        vector<string> tokens;
        string token;
        stringstream ss(s);

        while(getline(ss, token, delimiter)){
            tokens.push_back(token);
        }
        return tokens;
    }

    TreeNode* build(vector<string>& nodes, int &i){
        if(nodes[i]== "null"){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root->left = build(nodes,i);
        root->right = build(nodes, i);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string st="";
        dfs(root, st);
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if(data.empty())return nullptr;
        if(data[0] == ',')data = data.substr(1);

        vector<string> nodes = split(data, ',');
        int idx=0;
        return build(nodes, idx);


    }
};