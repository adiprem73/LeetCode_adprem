class Solution {
public:
    int totalWaviness(int num1, int num2) {
    int ans=0;
    for(int i=num1;i<=num2;i++){
        string s= to_string(i);
        int cnt=0;
        int len= s.length();
        if(len>=3){
            for(int i=1;i<len-1;i++){
                if(s[i]>s[i-1] && s[i]>s[i+1]){
                    cnt++;
                }
                else if(s[i]<s[i-1] && s[i]<s[i+1]){
                    cnt++;
                }
            }
            ans+=cnt;
        }
    }    
    return ans;   
}
};