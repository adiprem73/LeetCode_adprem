class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for(int i= startIndex; i<n ; i++){
            if(words[i] == target){
                ans = min(ans, min(i-startIndex , startIndex + n-i));
            }
        }
        for(int i= startIndex; i>=0;i--){
            if(words[i] == target){
                ans = min(ans, min(startIndex - i, n - startIndex + i ));
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};