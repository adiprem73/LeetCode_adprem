class Solution {
public:
    map<char,int> hashed(string s){
    map<char,int> mp;
    for(char ch: s){
        mp[ch]++;
    }

    return mp;
}

int countConsistentStrings(string allowed, vector<string>& words){
    map<char,int> mp= hashed(allowed);
    int cnt=0;

    for(auto it: words){
        auto hash = hashed(it);
        bool flag= true;
        for(auto ch: hash){
            if(mp.count(ch.first)==0){
                flag = false;
                break;
            }
        }
        if(flag)cnt++;

    }
    return cnt;
}
};