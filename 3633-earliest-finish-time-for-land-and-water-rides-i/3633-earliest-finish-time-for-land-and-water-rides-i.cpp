class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int time = INT_MAX;
        int m = landStartTime.size();
        int n = waterStartTime.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // considering land first
                int landEndTime = landStartTime[i]+landDuration[i];
                int wStart = max(waterStartTime[j],landEndTime);
                time = min(time, wStart+waterDuration[j]);

                int waterEndTime = waterStartTime[j]+waterDuration[j];
                int lStart= max(landStartTime[i], waterEndTime);
                time = min(time, lStart+landDuration[i]);
            }
        }
        return time;
    }
};