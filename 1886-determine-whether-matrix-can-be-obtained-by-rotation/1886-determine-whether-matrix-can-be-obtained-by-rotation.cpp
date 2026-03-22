class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    // for (auto &it : mat)
    // {
    //     vprint(it);
    // }
    // cout<<endl;
    if(mat == target)return true;
    auto mat2= mat;
    int n = mat2.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat2[i][j], mat2[j][i]);
        }
    }
    auto mat3 = mat2;
    for (auto &it : mat2)
    {
        reverse(it.begin(), it.end());
        // vprint(it);
    }
    if(mat2 == target)return true;
    // cout << endl;
    reverse(mat.begin(), mat.end());
    for(auto & it: mat){
        reverse(it.begin(), it.end());
        // vprint(it);
    }
    if(mat == target)return true;
    // cout<<endl;
   
    reverse(mat3.begin(), mat3.end());
    if(mat3 == target)return true;
    // for (auto &it : mat3)
    // {
    //     // vprint(it);
    // }
    // cout << endl;
    return false;
}
};