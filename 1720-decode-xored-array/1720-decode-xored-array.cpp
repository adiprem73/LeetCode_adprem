class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first)
{
    int n= encoded.size();
    vector<int> nums (n+1);
    nums[0] = first;
    int x=0;
    for(int i=0;i<n;i++){
        nums[i+1]= nums[i]^encoded[i];
    }
    return nums;
}
};