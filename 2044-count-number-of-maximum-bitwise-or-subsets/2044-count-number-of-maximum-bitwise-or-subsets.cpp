class Solution {
public:
    void makeSubsets(int currOR, int &maxOR, int ind, vector<int> & nums, int & cnt){
    if(ind == nums.size()){
        if(currOR> maxOR){
            maxOR = currOR;
            cnt=1;
        }else if(currOR ==  maxOR){
            cnt++;
        }
        return;
    }

    
    makeSubsets(currOR | nums[ind], maxOR, ind+1, nums, cnt);

    // not-pick
    makeSubsets(currOR, maxOR, ind+1, nums, cnt);
}

int countMaxOrSubsets(vector<int> &nums)
{
    int cnt=0;
    int maxOR=INT_MIN;
    makeSubsets(0, maxOR, 0, nums, cnt);
    
    return cnt;
}
};