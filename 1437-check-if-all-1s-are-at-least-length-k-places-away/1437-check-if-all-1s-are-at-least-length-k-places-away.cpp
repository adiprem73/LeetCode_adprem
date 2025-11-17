class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            
            if(nums[i]==1 && i!=n-1){
                int steps=0;
                i++;
                while(i<n && nums[i]==0){
                    steps++;
                    i++;
                }
                if(i<n && nums[i]==1){
                    if(steps<k)return false;
                }
                i--;
                cout<<steps<<endl;
                
            }
        }
        return true;
    }
};