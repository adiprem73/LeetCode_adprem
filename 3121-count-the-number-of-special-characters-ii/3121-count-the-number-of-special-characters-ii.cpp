class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26,-1), firstUpper(26,-1);
        for(int i=0;i<word.length();i++){
            if(islower(word[i])){
                lastLower[word[i]-'a']=i;
            }
            else if(isupper(word[i]) && firstUpper[word[i]-'A']==-1){
                firstUpper[word[i]-'A']=i;
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lastLower[i]<firstUpper[i]&& lastLower[i]!=-1 && firstUpper[i]!=-1)cnt++;
        }
        return cnt;
    }
};