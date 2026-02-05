class Solution {
public:
    void makeSubsets(vector<int> currArray, int currOR, int &maxOR, int ind, vector<int> & nums, int & cnt){
    if(ind == nums.size()){
        if(currOR> maxOR){
            maxOR = currOR;
            cnt=1;
        }else if(currOR ==  maxOR){
            cnt++;
        }
        return;
    }

    currArray.push_back(nums[ind]);
    makeSubsets(currArray, currOR | nums[ind], maxOR, ind+1, nums, cnt);

    // not-pick
    currArray.pop_back();
    makeSubsets(currArray, currOR, maxOR, ind+1, nums, cnt);
}

int countMaxOrSubsets(vector<int> &nums)
{
    vector<int> currArray;
    int cnt=0;
    int maxOR=INT_MIN;
    makeSubsets(currArray, 0, maxOR, 0, nums, cnt);
    
    return cnt;
}
};