class Solution {
public:
    string toBinary(int n){
    string s;
    while(n>0){
        int x=n%2;
        s=s+to_string(x);
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

int hammingWeight(int n) {
    string b=toBinary(n);
    int count=0;
    for(int i=0;i<b.length();i++){
        if(b[i]=='1'){
            count++;
        }
    }
    return count;
}
};