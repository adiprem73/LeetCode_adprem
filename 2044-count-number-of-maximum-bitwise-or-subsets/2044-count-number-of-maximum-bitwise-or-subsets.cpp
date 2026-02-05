class Solution {
public:
    void makeSubsets(vector<int> currArray, int currOR, int &maxOR, int ind, vector<int> & nums, vector<vector<int>>& ans){
    if(ind == nums.size()){
        if(currOR> maxOR){
            maxOR = currOR;
            ans.clear();
            ans.push_back(currArray);
        }else if(currOR ==  maxOR){
            ans.push_back(currArray);
        }
        return;
    }

    currArray.push_back(nums[ind]);
    makeSubsets(currArray, currOR | nums[ind], maxOR, ind+1, nums, ans);

    // not-pick
    currArray.pop_back();
    makeSubsets(currArray, currOR, maxOR, ind+1, nums, ans);
}

int countMaxOrSubsets(vector<int> &nums)
{
    vector<int> currArray;
    vector<vector<int>> ans;
    int maxOR=INT_MIN;
    makeSubsets(currArray, 0, maxOR, 0, nums, ans);
    // for(auto it: ans){
    //     vprint(it);
    // }
    return ans.size();
}
};