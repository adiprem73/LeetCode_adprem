class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time=0;
        int n = timeSeries.size();
        for(int i=0;i<n-1;i++){
            time+= min(duration, timeSeries[i+1]-timeSeries[i]);
        }
        time+=duration;
        return time;
    }
};