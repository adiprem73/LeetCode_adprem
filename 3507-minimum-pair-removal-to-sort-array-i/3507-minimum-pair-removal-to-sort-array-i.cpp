class Solution {
public:
    bool check(vector<int> nums){
    vector<int> temp = nums;
    sort(nums.begin(), nums.end());
    // vprint(temp);
    return temp==nums;
}

int minimumPairRemoval(vector<int>& nums){
    int cnt=0;
    while(!check(nums)){
        int mn= INT_MAX;
        int x, y;
        for(int i=0;i<nums.size()-1;i++){
            // cout<<"i : "<<i<<endl;
            // cout<<"n1: "<<nums[i]<<" n2: "<<nums[i+1]<<endl;
            int sum = nums[i]+nums[i+1];
            // cout<<"sum : "<<sum<<endl;
            if(sum<mn){
                mn=sum;
                x=i;
                y=i+1;
            }
        }
        // cout<<"mn : "<<mn<<endl;
        // cout<<x<<" "<<y<<endl;
        nums[x]=nums[x]+nums[y];
        nums.erase(nums.begin()+y);
        cnt++;
    }
    return cnt;
}
};