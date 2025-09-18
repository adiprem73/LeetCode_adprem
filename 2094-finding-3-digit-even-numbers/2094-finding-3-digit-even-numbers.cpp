class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n= digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]%2==0){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        if(digits[j]!=0 && j!=i && k!=j && k!=i){
                            int num=digits[j]*100 + digits[k]*10 + digits[i];
                            if(num>=100){
                                ans.insert(num);
                            }
                            
                        }
                    }
                }
            }
        }
        vector<int> result;
        for(auto it: ans){
            result.push_back(it);
        }
        return result;
    }
};