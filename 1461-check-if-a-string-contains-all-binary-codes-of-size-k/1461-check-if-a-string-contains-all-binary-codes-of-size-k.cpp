class Solution {
public:
    int makeDecimal(string s){
    int ans=0;
    int cnt =0;
    for(auto it: s){
        ans=ans+ (it-'0') * (1<<cnt);
        cnt++;
    }
    return ans;
}

bool hasAllCodes(string s, int k) {
    if(s.length() < k)return false;
    int n = 1<<k;
    vector<bool> seen(n, false);

    // now we need to make a sliding window in the string s and then check whether that is seen or not
    for(int i=0;i<s.length()-k+1;i++){
        string st = s.substr(i,k);
        int x = makeDecimal(st);
        seen[x]= true;
    }
    for(auto it: seen){
        if(!it)return false;
    }return true;
}

};