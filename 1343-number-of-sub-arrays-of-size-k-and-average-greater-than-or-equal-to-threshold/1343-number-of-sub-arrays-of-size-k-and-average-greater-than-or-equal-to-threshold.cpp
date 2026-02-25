class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int n = arr.size();
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int cnt =0;
    if(sum/k >= threshold){
        cnt++;
    }
    for(int i=1;i<n-k+1;i++){
        sum-=arr[i-1];
        sum+=arr[i+k-1];
        if(sum/k >= threshold){
            cnt++;
        }
    }
    return cnt;
}
};