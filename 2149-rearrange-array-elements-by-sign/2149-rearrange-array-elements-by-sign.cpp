class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len =nums.size();
        int p=-1,n=-1;
        for(int i=0;i<len;i++){
            if(p==-1 && nums[i] >0){
                p=i;
            }
            if(n==-1 && nums[i] <0){
                n=i;
            }
        }
        vector<int> ans;
        while(p<len ||   n<len){
            if(p<len){
                ans.push_back(nums[p]);
                p++;
                while(p<len && nums[p]<0){
                    p++;
                }
            }
            if(n<len){
                ans.push_back(nums[n]);
                n++;
                while(n<len && nums[n]>0){
                    n++;
                }
            }
        }
        return ans;
    }
};