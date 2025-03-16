class Solution {
public:
    string frequencySort(string s) {
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    multimap<int,char>mp2;
    for(auto it:mp){
        mp2.insert({it.second, it.first});
    }
    string ans;
    for(auto it:mp2){
        for(int i=0;i<it.first;i++){
            ans+=it.second;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
        
}
};