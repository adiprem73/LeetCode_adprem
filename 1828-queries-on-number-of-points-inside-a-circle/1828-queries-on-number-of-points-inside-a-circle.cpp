class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto circle: queries){
            int cnt=0;
            for(auto point: points){
                int x = point[0];
                int y = point[1];
                if(pow(x-circle[0], 2) + pow(y-circle[1], 2)<=pow(circle[2], 2)){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};