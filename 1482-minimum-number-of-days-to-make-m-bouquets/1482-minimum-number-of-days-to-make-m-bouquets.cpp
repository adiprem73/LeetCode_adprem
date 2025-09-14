class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k)
{
    if (1LL * m * k > (long long)bloomDay.size())
    {
        return -1;
    }
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    // here (mini. maxi) becomes the search space
    int s=mini;
    int e=maxi;
    while (s<e)
    {
        int mid= s +(e-s)/2;
        int cnt = 0; // count the consecutive bloomed flowers
        int b = 0;   // no. of bouqets being made
        // when bloomday[i]>= i then we can say that the flower is bloomed

        // cout<<"currenlty i : "<<i<<endl;
        for (int j = 0; j < bloomDay.size(); j++)
        {
            // cout << "j : " << j << endl;
            if (mid >= bloomDay[j])
            {
                cnt++;
            }
            else
            {
                int x = cnt / k;
                b += x;
                cnt = 0; // rest the counter since consecutivity has been broken
            }
        }
        if (cnt)
        {
            b += (cnt / k);
        }
        if (b >= m)
        {
            e = mid; // mid is feasible, try smaller...       If mid is feasible → we know the real answer is ≤ mid (so shrink e = mid).
        }else{
            s=mid+1; // If mid is not feasible → the real answer is > mid (so push s = mid + 1).
        } 
    }
    return s;
}
};