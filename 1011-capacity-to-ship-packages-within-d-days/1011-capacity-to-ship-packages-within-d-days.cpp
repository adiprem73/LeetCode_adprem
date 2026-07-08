class Solution {
public:
    bool simulCheck(vector<int>weights, int days, int capacity){
    // cout<<"currently checking for capacity : "<<capacity<<endl;
    int i=0;
    int currShip=0;
    int daysTaken=1;
    for (int weight : weights)
    {
        if (currShip + weight <= capacity)
        {
            currShip += weight;
        }
        else
        {
            daysTaken++;
            currShip = weight;
        }
    }
    // cout<<"days taken : "<<daysTaken<<endl;
    return daysTaken<=days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int sumTotal=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, weights[i]);
        sumTotal+= weights[i];
    }
    int s = maxi;
    int e = sumTotal;
    int ans =INT_MAX;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(simulCheck(weights, days, mid)){
            ans = min(ans, mid);
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans;
}
};