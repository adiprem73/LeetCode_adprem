class Solution {
public:
    string toBinary(int n){
    string s="";
    while(n>0){
        int x=n%2;
        n/=2;
        s+=to_string(x);
    }
    reverse(s.begin(),s.end());
    return s;
}

string addLeadingZeroes(string binary,int n){
    while(binary.length()!=n){
        binary="0"+binary;
    }
    return binary;
}

int minBitFlips(int start, int goal) {
    string binStart=toBinary(start);
    string binGoal=toBinary(goal);
    int startLen=binStart.length();
    int goalLen=binGoal.length();

    if(startLen<goalLen){
        binStart=addLeadingZeroes(binStart,binGoal.length());

    }
    else{
        binGoal=addLeadingZeroes(binGoal, binStart.length());
    }
    // cout<<binStart<<endl;
    // cout<<binGoal<<endl;
    int count=0;
    for(int i=0;i<binGoal.length();i++){
        if(binGoal[i]!=binStart[i]){
            count++;
        }
    }
    return count;
}
};