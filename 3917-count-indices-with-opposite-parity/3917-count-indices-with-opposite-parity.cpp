class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int cntEven =0, cntOdd=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int score=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]%2 != nums[j]%2){
                    score++;
                }
            }
            ans.push_back(score);
        }
        return ans;
    }
};