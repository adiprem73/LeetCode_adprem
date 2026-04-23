class Solution {
public:
    vector<long long> getDistances(vector<int>& nums) {
    int n = nums.size();
    vector<long long> arr(n);
    unordered_map<int, vector<int>> mp;

    for(int i = 0; i < n; i++){
        mp[nums[i]].push_back(i);
    }

    for(auto &it : mp){
        vector<int> &vec = it.second;
        int m = vec.size();

        if(m == 1){
            arr[vec[0]] = 0;
            continue;
        }

        // prefix sum
        vector<long long> pref(m);
        pref[0] = vec[0];
        for(int i = 1; i < m; i++){
            pref[i] = pref[i-1] + vec[i];
        }

        for(int i = 0; i < m; i++){
            long long left = 0, right = 0;

            if(i > 0){
                left = 1LL * i * vec[i] - pref[i-1];
            }

            if(i < m-1){
                right = (pref[m-1] - pref[i]) - 1LL * (m - i - 1) * vec[i];
            }

            arr[vec[i]] = left + right;
        }
    }

    return arr;
}
};