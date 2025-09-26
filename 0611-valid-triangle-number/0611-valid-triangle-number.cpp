class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    int n= nums.size();
    int cnt=0;
    // what we will do is sort the array. them we will start by fixing biggest side k fromthe back side of the array. then we will take i and then j. i and j will be two pointers pointing at index i=0 and j=k-1;... then we willl simply check if nums[i]+nums[j]>nums[k]... if yes then we can simply say that cnt+=(j-1)... since anynumber ahead of i will obiviously be bigger thant the element at i. hence the conditionw ill hold for that also and  simply got so many contributuons. in this case we will subtract j to move it back by one place in order to look for a smaller sum

    // if that condition wasnt true then we could have simply increaseed i one place ahead and simply increasesthe sum and then tried again while(i<j)
    sort(nums.begin(),nums.end());
    for(int k=n-1;k>=2;k--){
        // cout<<"k : "<<k<<endl;
        int i=0;
        int j=k-1;
        while(i<j){
            if((nums[k]<nums[i]+nums[j])&& (nums[k]!=0)&& (nums[i]!=0)&& (nums[j]!=0)){
                cnt+=(j-i);
                j--;
            }else {
                i++;
            }
        }
    }

    return cnt;
}
};