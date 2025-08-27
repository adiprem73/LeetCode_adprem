class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    // if(n==0){
    //     intervals.push_back(newInterval);
    //     return intervals;
    // }
    // for(int i=0;i<n;i++){
    //     if(intervals[i][0]<=newInterval[0] && intervals[i][1]>=newInterval[0]){
    //         intervals[i][1] = max(intervals[i][1], newInterval[1]);
    //     }
    //     else{
    //         intervals.push_back(newInterval);
    //         sort(intervals.begin(), intervals.end());
    //     }
    // }   

    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    //now we need to fix the issue of overlapping intervals
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][1]>=intervals[i+1][0]){
            intervals[i][1]= max(intervals[i][1], intervals[i+1][1]);
            intervals.erase(intervals.begin()+i+1);
            i--;
        }
    }  
    return intervals;
}
};