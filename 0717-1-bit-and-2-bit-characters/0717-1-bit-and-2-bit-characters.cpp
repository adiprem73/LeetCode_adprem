class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n= bits.size();
        int s=0;
        while(s<n-1){
            if(bits[s]==1){
                s++;
            }
            s++;
        }
        cout<<s<<endl;
        if(s==n-1)return true;
        else return false;
    }
};