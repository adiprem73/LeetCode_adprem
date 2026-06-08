class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> answer;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                answer.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                answer.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};