class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0=0, cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num==0)cnt0++;
            else if(num==1)cnt1++;
            else cnt2++;
        }
        int i =0;
        while(cnt0!=0){
            nums[i]= 0;
            i++;
            cnt0--;
        }
        while(cnt1!=0){
            nums[i]=1;
            i++;
            cnt1--;
        }
        while(cnt2!=0){
            nums[i]=2;
            i++;
            cnt2--;
        }
    }
};