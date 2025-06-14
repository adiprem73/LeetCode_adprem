class Solution {
public:
    int atMostkOdds(vector<int>& nums, int k) {
    int l=0,r=0,countofodd=0,count=0;
    while(r<nums.size()){
        if(nums[r]%2!=0){
            countofodd++;
        }

        while(countofodd>k){
            if(nums[l]%2!=0){
                countofodd--;
            }
            l++;
        }
        
        count+=r-l+1;
        r++;
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums,int k){
    return atMostkOdds(nums,k)-atMostkOdds(nums,k-1);
}
};