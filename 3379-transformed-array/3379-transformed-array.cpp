class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums){
    int n= nums.size();
    vector<int> results(n);
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            results[i]= nums[(i+nums[i])%n];
        }else if(nums[i]<0){
            results[i]= nums[(i-(abs(nums[i])%n)+n) % n];
        }else{
            results[i]= nums[i];
        }
    }
    return results;
}
};