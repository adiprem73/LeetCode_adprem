class Solution {
public:
    int trap(vector<int>& height) {
        // all we have to find is next gretaer and previous rgeater elelemtns
        int max1=0;
        int n = height.size();
        vector<int> left, right;
        for(int i=0;i<n;i++){
            left.push_back(max1);
            max1 = max(max1, height[i]);
        }
        max1 =0;
        for(int i=n-1;i>=0;i--){
            right.push_back(max1);
            max1 = max(max1, height[i]);
        }
        reverse(right.begin(), right.end());
        int ans =0;
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            if( min(left[i], right[i])> height[i]){
                ans += min(left[i], right[i])  - height[i];
            }
            
        }
        return ans;
    }
};