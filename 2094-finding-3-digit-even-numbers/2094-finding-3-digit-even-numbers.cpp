class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int n= digits.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[digits[i]]++;
        }
        for(int i=100;i<=999;i++){
            if(i%2==0){
            int x=i;
            map<int,int> mp2;
            while(x>0){
                int d=x%10;
                mp2[d]++;
                x=x/10;
            }
            bool flag= true;
            for(auto it: mp2){
                if(it.second>mp[it.first]){
                    flag= false;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
        }
        return ans;
    }
};