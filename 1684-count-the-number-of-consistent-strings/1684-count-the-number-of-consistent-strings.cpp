class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words){
    vector<bool> hash(26,false);
    for(char ch: allowed){
        hash[ch-'a']=true;
    }
    int cnt=0;

    for(auto it: words){
        bool flag= true;
        for(auto ch: it){
            if(hash[ch-'a']== false){ // not found in allowede
                flag = false;
                break;
            }
        }
        if(flag)cnt++;
    }
    return cnt;
}
};