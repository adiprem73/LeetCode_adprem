class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int x;
        if(ruleKey == "type")x=0;
        else if(ruleKey == "color")x=1;
        else if(ruleKey == "name")x=2;
        int cnt=0;
        for(auto it: items){
            if(it[x]== ruleValue){
                cnt++;
            }
        }
        return cnt;
    }
};