class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> & intervals){
    int n=intervals.size();
    vector<vector<int>> mergedIntervals;
    if(n==0){
        return mergedIntervals;
    }
    vector<int> tempInterval;
        sort(intervals.begin(), intervals.end());

    tempInterval = intervals[0];

    for(auto it: intervals){
        if(it[0]<=tempInterval[1]){
            tempInterval[1]= max(it[1], tempInterval[1]);
        }
        else{
            mergedIntervals.push_back(tempInterval);
            tempInterval=it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}
};