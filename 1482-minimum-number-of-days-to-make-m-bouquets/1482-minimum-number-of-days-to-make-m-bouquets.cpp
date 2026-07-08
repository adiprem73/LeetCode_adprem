class Solution {
public:
    bool simulCheck(const vector<int> &bloomDay, int m, int k, int day)
{
    int bouquets = 0;
    int current = 0;

    for (int bloom : bloomDay)
    {
        if (bloom <= day)
        {
            current++;

            if (current == k)
            {
                bouquets++;
                current = 0; // these k flowers are now used
            }
        }
        else
        {
            current = 0; // broken consecutive sequence
        }
    }

    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    int maxi =0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, bloomDay[i]);
    }
    int s=0;
    int e=maxi;
    int ans = INT_MAX;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(simulCheck(bloomDay, m, k, mid)){
            ans = min(ans, mid);
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    if(ans == INT_MAX)return -1;
    return ans;
}
};