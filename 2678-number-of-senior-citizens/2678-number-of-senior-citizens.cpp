class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto it: details){
            string s = it.substr(11,2);
            if(stoi(s) > 60)cnt++;
        }
        return cnt;
    }
};