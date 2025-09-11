class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        string v= "AEIOUaeiou";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(v.find(ch)!=string::npos){
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(), vowels.end());
        int ind=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(v.find(ch)!=string::npos){
                s[i]= vowels[ind];
                ind++;
            }
        }
        return s;
    }
};