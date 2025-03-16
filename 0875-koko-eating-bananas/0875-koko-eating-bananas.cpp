class Solution {
public:
    int feasibleSpeed(vector<int>&piles,int k,int h){
    int totalTime=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        totalTime+=piles[i]/k;
        if(piles[i]%k!=0){
            totalTime+=1;
        }
    }
    return totalTime;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int s = 1; // minimum eating speed
    auto e = *max_element(piles.begin(), piles.end());
    if (piles.size() == 1)
    {
        // cout << ceil(piles[0] / h) << endl;
        return ceil((piles[0] + h - 1) / h);
    }

    while (s < e)
    {
        int mid = s + (e - s) / 2;
        int totalTime = feasibleSpeed(piles, mid, h);

        if (totalTime <= h)
        {
            e=mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}
};