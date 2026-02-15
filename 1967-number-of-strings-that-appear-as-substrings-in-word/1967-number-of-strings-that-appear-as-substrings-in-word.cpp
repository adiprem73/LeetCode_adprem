class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(auto it: patterns){
            if(word.contains(it))cnt++;
        }
        return cnt;
    }
    
};