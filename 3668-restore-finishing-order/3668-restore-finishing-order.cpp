class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        vector<int> hash(n+1,0);
        for(int i: friends){
            hash[i]++;
        }

        vector<int> ans;
        for(int i: order){
            if(hash[i]!=0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};