class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        int l=0;
        int r=n;
        vector<int> vec;
        for(char ch: s){
            if(ch=='I'){
                vec.push_back(l++);
            }else{
                vec.push_back(r--);
            }
        }
        vec.push_back(l);
        return vec;
    }
};