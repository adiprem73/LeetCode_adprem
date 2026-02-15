class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string w="";
        for(auto it: words){
            w=w+it[0];
        }
        return w==s;
    }
};