class Solution {
public:
    int removeDuplicates(vector<int>& nums){
    int cnt=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            if(cnt==0){
                cnt++;
            }else{
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        else{
            cnt=0;
        }
    }
    return nums.size();
}

};