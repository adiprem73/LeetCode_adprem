class Solution {
public:

    int comp(int a, int b, int x){
        int diff = abs(a-b);
        if(diff%x !=0){
            return -1;
        }else return diff/x;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(auto it: grid){
            for(auto itr: it){
                nums.push_back(itr);
            }
        }
        sort(nums.begin(), nums.end());
        if(nums.size()%2!=0){ // for odd length arrays
            int c = nums.size()/2;
            int critical = nums[c];
            int ans =0;
            for(auto it: nums){
                int temp = comp(it, critical, x);
                if(temp == -1){
                    return -1;
                }else{
                    ans +=temp;
                }
            }
            return ans;
        }else{
            int c = nums.size()/2;
            int d = c-1;
            int ans =0, ans2= 0;
            int critical = nums[c];
            int critical2 = nums[d];
            for(auto it: nums){
                int temp = comp(it, critical, x);
                if(temp == -1){
                    return -1;
                }else{
                    ans +=temp;
                }
            }
            for(auto it: nums){
                int temp = comp(it, critical2, x);
                if(temp == -1){
                    return -1;
                }else{
                    ans2 +=temp;
                }
            }
            return min(ans, ans2);
        }
        return 0;
    }
};