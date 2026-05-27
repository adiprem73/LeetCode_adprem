class Solution {
public:
    
void solve(int ind, string &nums, int target, string curr, vector<string> & ans, long prev, long res){
    // base case
    if(ind == nums.length()){
        if(res == target){
            ans.push_back(curr);
        }
        return;
    }

    string st ="";

    long currRes = 0;

    for(int i=ind;i<nums.length();i++){  // to take siungle diigits multiple digits etc
        if(i>ind && nums[ind]=='0')break;

        st+= nums[i];

        currRes = currRes*10 + (nums[i]-'0');
        if(ind ==0){
            solve(i+1, nums, target, st, ans, currRes, currRes);
        }

        else{
            solve(i+1, nums, target, curr+"+"+st, ans, currRes, res+currRes);
            solve(i + 1, nums, target, curr + "-" + st, ans,-currRes, res - currRes);
            solve(i+1, nums, target, curr+"*"+st, ans, prev*currRes, res-prev+(prev*currRes));
        }
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> ans;
    solve(0, num, target, "", ans, 0, 0);
    for(auto it: ans){
        cout<<it<<endl;
    }
    return ans;
}
};