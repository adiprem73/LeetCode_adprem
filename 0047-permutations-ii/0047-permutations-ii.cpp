class Solution {
public:
    void func(vector<int> curr, vector<bool> & visit, vector<vector<int>> & ans, vector<int>& nums){
    if(curr.size()== nums.size() ){
        ans.push_back(curr);
        return;
    }

    for(int i=0;i<nums.size();i++){
        if (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == true)
            continue;
        if(visit[i]== false){
            curr.push_back(nums[i]);
            visit[i] = true;
            func(curr, visit, ans, nums);
            // backtracking
            curr.pop_back();
            visit[i]= false;
        }
    }
}   

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> curr;
    vector<vector<int>> ans;
    vector<bool> visit(nums.size(),false);
    sort(nums.begin(), nums.end());
    func(curr, visit, ans, nums);
    return ans;
}
};