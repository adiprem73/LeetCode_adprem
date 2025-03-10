class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int c=count(ans.begin(),ans.end(),nums[i]);
            // cout<<"i : "<<i<<" nums[i]: "<<nums[i]<<"count : "<<c<<endl;
            if(c==0){
                ans.push_back(nums[i]);
            }
        

        }
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        nums=ans;
        return ans.size();
            
        }
};