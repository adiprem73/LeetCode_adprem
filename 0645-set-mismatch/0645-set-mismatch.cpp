class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums)
{
    int n= nums.size();
    vector<int> mp(n+1, 0);

    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }

    int missing, extra;
    for(int i=0;i<mp.size();i++){
        if(mp[i]==2){
            extra= i;
        }
        if(mp[i]==0){
            missing= i;
        }
    }
    return {extra, missing};
}
};