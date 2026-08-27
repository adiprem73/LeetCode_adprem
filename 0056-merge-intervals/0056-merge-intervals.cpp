class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            auto &curr = ans.back();
            if(curr[1] >= intervals[i][0]){
                curr[1] = max(curr[1] ,intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};