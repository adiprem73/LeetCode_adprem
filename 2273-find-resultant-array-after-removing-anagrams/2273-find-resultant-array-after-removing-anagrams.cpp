class Solution {
public:
    bool check(string str1, string str2){
        map<char,int> mp1;
        map<char,int> mp2;
        for(char ch: str1){
            mp1[ch]++;
        }
        for(char ch: str2){
            mp2[ch]++;
        }
        return (mp1==mp2)? true: false;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();i++){
            if(check(words[i-1], words[i])){
                words.erase(words.begin()+i);
                i--;
            }
        }
        return words;
    }   
};