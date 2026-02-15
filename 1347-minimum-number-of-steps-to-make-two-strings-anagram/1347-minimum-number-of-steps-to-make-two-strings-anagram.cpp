class Solution {
public:
    int minSteps(string s, string t) {
    vector<int> sMap(26,0);
    vector<int> tMap(26, 0);
    for(auto it: s){
        sMap[it-'a']++;
    }
    for (auto it : t)
    {
        tMap[it - 'a']++;
    }

    int cnt=0;
    for(int i=0;i<26;i++){
        if(sMap[i]>tMap[i]){
            cnt+=sMap[i]-tMap[i];
        }
    }
    return cnt;
}
};