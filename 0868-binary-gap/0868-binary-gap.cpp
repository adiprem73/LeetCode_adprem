class Solution {
public:
    int binaryGap(int n) {
    string s;
    while(n>0){
        s += to_string(n%2);
        n /= 2;
    }

    int ans = 0, x = 0;
    bool counting = false;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            if(counting){
                ans = max(ans, x);
            }
            counting = true;
            x = 0;
        }
        else if(counting){
            x++;
        }
    }
    return ans==0? 0:ans+1;
}
};