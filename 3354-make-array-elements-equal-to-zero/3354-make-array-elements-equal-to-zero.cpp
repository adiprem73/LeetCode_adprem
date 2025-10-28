class Solution {
public:
    bool checkStartLeft(int pos, vector<int> nums){
    // left direction
    int n= nums.size();
    bool dir= false;// 1 for rigt and 0 for left
    while(pos<n && pos>=0){
        if (nums[pos]==0){
            if(dir){
                pos++;
            }
            else{
                pos--;
            }
        }
        else if(nums[pos]>0){
            nums[pos]--;
            dir=!dir;
            if(dir){
                pos++;
            }
            else{
                pos--;
            }
        }
    }
    for(int i=0;i<nums.size();i++){
        if(nums[i]){
            return false;
        }
    }
    return true;
}

bool checkStartRight(int pos, vector<int> nums)
{
    // right direction
    int n = nums.size();
    bool dir = true; // 1 for rigt and 0 for left
    while (pos < n && pos >= 0)
    {
        if (nums[pos] == 0)
        {
            if (dir)
            {
                pos++;
            }
            else
            {
                pos--;
            }
        }
        else if (nums[pos] > 0)
        {
            nums[pos]--;
            dir = !dir;
            if (dir)
            {
                pos++;
            }
            else
            {
                pos--;
            }
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
        {
            return false;
        }
    }
    return true;
}

int countValidSelections(vector<int>& nums) {
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            if(checkStartLeft(i, nums)){
                count++;
                // cout<<i<<endl;
                // cout<<checkStartLeft(i,nums)<<endl;
                // cout<<checkStartRight(i, nums)<<endl;
            }
            if (checkStartRight(i, nums))
            {
                count++;
                // cout<<i<<endl;
                // cout<<checkStartLeft(i,nums)<<endl;
                // cout<<checkStartRight(i, nums)<<endl;
            }
        }
    }
    return count;
}
};