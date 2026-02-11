class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> answer(n);
        for(int i =0;i<n;i++){
            answer[i]= nums[i]%2;
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};