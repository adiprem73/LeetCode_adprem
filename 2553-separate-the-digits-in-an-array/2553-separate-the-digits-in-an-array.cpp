class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto it: nums){
            vector<int> temp;
            while(it>0){
                int d=it%10;
                temp.push_back(d);
                it = it/10;
            }
            reverse(temp.begin(), temp.end());
            for(auto itr: temp){
                ans.push_back(itr);
            }
        }
        return ans;
    }
};