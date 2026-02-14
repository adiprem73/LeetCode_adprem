class Solution {
public:
    int maxDistinct(string s) {
    unordered_map<char,int>mp;       
    for(char ch: s){
        mp[ch]++;
    }
    return mp.size();
}
};