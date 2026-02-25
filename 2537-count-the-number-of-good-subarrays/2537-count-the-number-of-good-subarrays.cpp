class Solution {
public:
    long long countGood(vector<int> &nums, int k)
{
    // subarray, K count ---? sliding window
    // the idea is that the number of appearance of the elelment being added tells us how many pairs will be amde bcoz of that elelment
    int l =0;
    int n = nums.size();
    unordered_map<int,int> mp;
    long long numPairs=0;
    long long result =0;

    for(int r=0;r<n;r++){
        
            numPairs+= mp[nums[r]];
        
        mp[nums[r]]++;
        while(numPairs >= k){
            result += (n-r);
            
                mp[nums[l]]--;
numPairs -= mp[nums[l]];
            l++;
        }
    }
    return result;
}
};