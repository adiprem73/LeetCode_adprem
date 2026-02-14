class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        int n = s.length();
        for(int i=0;i<n;i++){
            mp1[s[i]]=i;
            mp2[t[i]]=i;
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=abs(mp1[s[i]] - mp2[s[i]]);
        }return ans;

    }
};