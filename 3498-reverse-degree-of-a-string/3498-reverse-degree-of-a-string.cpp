class Solution {
public:
    int reverseDegree(string s) {
        vector<int> hash(26);
        int x = 26;
        for(int i=0;i<26;i++){
            hash[i]=x;
            x--;
        }
        int score=0;
        for(int i=0;i<s.length();i++){
            cout<<hash[s[i]-'a']<<endl;
            score+=(hash[s[i]-'a']*(i+1));
        }
        return score;
    }
};