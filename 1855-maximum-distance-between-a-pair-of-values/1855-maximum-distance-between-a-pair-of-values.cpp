class Solution {
public:
  int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int ans = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i = 0; i < n1; i++)
    {
        int s = i;
        int e = n2-1;
        int best = i-1;
        while(s<=e){
            int mid = s + (e - s) / 2;
            if(nums1[i] <= nums2[mid]){
                s= mid+1;
                best = mid;
            }
            else{
                e = mid-1;
            }
        }
        ans = max(ans, best-i);
    }
    return ans;
}
};