class Solution {
public:
    int maximumCount(vector<int> &nums)
{
    int n = nums.size();
    int s=0;
    int e = n-1;
    int ans = n; // by default for not found

    // lower bound
    while(s<=e){
        int mid = s+(e-s)/2;
        // cout<<mid<<endl;
        if(nums[mid]>=0){
            ans = mid;
            e = mid -1;
        }else{
            s = mid +1;
        }
    }

    // upper bound
    s = 0;
    e = n - 1;
    int ans2= n;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid]>0){
            ans2 = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }

    // cout<<s<<endl;
    // cout<<n-s<<endl;
    // cout<<ans<<endl;
    // cout<<ans2<<endl;
    // int neg = ans;
    // int pos = n- ans2;
    return max(ans, n-ans2);
    // cout<<s<<endl;
}
};