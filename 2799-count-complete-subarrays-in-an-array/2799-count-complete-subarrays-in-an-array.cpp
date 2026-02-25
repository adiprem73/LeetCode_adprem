class Solution {
public:
    int countCompleteSubarrays(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st;
    for (auto it : nums)
    {
        st.insert(it);
    }
    int k = st.size();
    int l = 0;
    int ans = 0;
    while (l < n)
    {
        // cout<<l<<endl;
        int i = l;
        int c = 0;
        unordered_set<int> st2;
        while (st2.size() < k && i < n)
        {
            st2.insert(nums[i]);
            i++;
        }
        if (st2.size() == k)
            ans += (n - i + 1);
        l++;
    }
    return ans;
}
};