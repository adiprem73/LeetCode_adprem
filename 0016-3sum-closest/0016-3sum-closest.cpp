class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int closest= nums[0]+nums[1]+nums[2];
    for( int i=0;i<nums.size();i++){
        int x=nums[i];
        int newtarget= target-x;
        int s=i+1;
        int e=nums.size()-1;
        while(s<e){
            
            int sum= nums[i]+nums[s]+nums[e];

            if(abs(target-sum)<abs(target-closest)){
                closest=sum;
            }


            if(sum == target){
                return sum;
            }
            else if (sum<target){
                s++;
            }
            else{
                e--;
            }
        }
    }
    return closest;
}
};