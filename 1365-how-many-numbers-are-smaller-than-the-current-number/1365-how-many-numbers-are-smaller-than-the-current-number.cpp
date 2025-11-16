class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(101);
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
    }
    // vprint(freq);
    int rank = 0;
    map<int, int> mp;
    for(int i=1;i<=100;i++){
        if(freq[i]>0){
            mp[i]=rank;
            rank+=freq[i];
        }
    }
    // mprint(mp);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[nums[i]]);
    }
    return ans;
}
};