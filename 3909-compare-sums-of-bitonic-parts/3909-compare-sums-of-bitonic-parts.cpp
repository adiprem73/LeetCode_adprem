class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                c = i;
                break;
            }
        }
        cout<<"c : "<<c<<endl;
        long long sum1=0, sum2=0;
        for(int i=0;i<n;i++){
            if(i<=c){
                sum1+=nums[i];
            }
            if(i>=c){
                sum2 += nums[i];
            }
        }
        cout<<sum1<<" & "<<sum2<<endl;
        if (sum1>sum2) return 0;
        else if(sum1<sum2) return 1;
        else return -1;
    }
};