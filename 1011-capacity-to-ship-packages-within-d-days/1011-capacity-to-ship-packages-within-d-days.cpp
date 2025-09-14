class Solution {
public:
    int shipWithinDays(vector<int> &weights, int days)
{
    int maxi=INT_MIN;
    int sum=accumulate(weights.begin(), weights.end(), 0);
    for(int x: weights){
        maxi=max(maxi,x);
    }
    int s=maxi;
    int e=sum;
    while(s<e){
        int mid= s+ (e-s)/2;

        int ship=0;
        int d=0;
        for(int i=0;i<weights.size();i++){
            if(ship+weights[i]<=mid){
                ship=ship+weights[i];
            }
            else{
                d++;
                ship=weights[i];
            }
        }
        ship++;
        if(d>=days){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;

}
};