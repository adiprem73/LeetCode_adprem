class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int time = INT_MAX;
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int landEarliest=INT_MAX, waterEarliest= INT_MAX;
        for(int i=0;i<m;i++){
            landEarliest = min(landEarliest, landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<n;i++){
            time = min(time, max(landEarliest, waterStartTime[i]) + waterDuration[i]);
        }
        for(int i=0;i<n;i++){
            waterEarliest = min(waterEarliest, waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0;i<m;i++){
            time = min(time, max(waterEarliest, landStartTime[i])+ landDuration[i]);
        }
        return time;
    }
};