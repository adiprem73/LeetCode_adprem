class Solution {
public:
    int check(vector<int> nums, int x){
    //x is the limit for each subarray sum
    int cnt=1;
    int bag= nums[0];
    for(int i=1;i<nums.size();i++){
        if(bag+nums[i]<=x){
            bag+=nums[i];
        }else{
            cnt++;
            bag=nums[i];
        }
    }
    return cnt;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    // cout<<"low : "<<low<<" high : "<<high<<endl;
    while(low<=high){
        int mid= low +(high-low)/2;

        if(check(nums,mid)<=k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
};