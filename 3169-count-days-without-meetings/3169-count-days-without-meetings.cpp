class Solution {
public:
    int countDays(int days, vector<vector<int>> &meetings)
{
    vector<vector<int>> mergedIntervals;
    sort(meetings.begin(), meetings.end());
    mergedIntervals.push_back(meetings[0]);
    int n = meetings.size();
    for(int i=1;i<n;i++){
        if(meetings[i][0]<=mergedIntervals.back()[1]){
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], meetings[i][1]);
        }else{
            mergedIntervals.push_back(meetings[i]);
        }
    }
    int totalSpread =0;
    for(auto it: mergedIntervals){
        // vprint(it);
        int diff = it[1]-it[0]+1;
        totalSpread+=diff;
    }
    return days - totalSpread;
}
};