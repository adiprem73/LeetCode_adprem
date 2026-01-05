class Solution {
public:
    int findShortestSubArray(vector<int> &nums)
{
    unordered_map<int,int> freq;
    unordered_map<int,int> firstAppearance;
    unordered_map<int,int> lastAppearance;

    for(int i=0;i<nums.size();i++){
        int element = nums[i];
        freq[element]++;

        if(!firstAppearance.count(element)){
            firstAppearance[element]= i;
        }
        lastAppearance[element] = i;
    }
    int maxFreq=-1;
    for(auto it: freq){
        if(it.second> maxFreq){
            maxFreq= it.second;
        }
    }

    // for(auto it: freq){
    //     cout<<it.first<<" : "<<it.second<<endl;
    // }
    // cout<<"first appearances : "<<endl;
    // for (auto it : firstAppearance)
    // {
    //     cout << it.first << " : " << it.second << endl;
    // }
    // cout<<"last appearances : "<<endl;
    // for (auto it : lastAppearance)
    // {
    //     cout << it.first << " : " << it.second << endl;
    // }
    int ans=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(freq[nums[i]]== maxFreq){
            ans= min(ans, lastAppearance[nums[i]]- firstAppearance[nums[i]]+1);
        }
    }
    return ans;
}
};