class Solution {
public:
    map<char,int> hashed(string st){
    map<char,int>mp;
    for(char ch: st){
        mp[ch]++;
    }
    return mp;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<bool> used(strs.size(), false);
    vector<vector<string>> ans;
    for(int i=0;i<strs.size();i++){
        if(used[i]== false){
            vector<string> curr;
            auto m1 = hashed(strs[i]);
            for(int j=0;j<strs.size();j++){
                if(used[j]== false && hashed(strs[j])== m1){
                    used[j]= true;
                    curr.push_back(strs[j]);
                }
            }
            ans.push_back(curr);
        }
    }
    return ans;
}
};