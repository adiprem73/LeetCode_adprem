class Solution {
public:
    int minimumSum(int num) {
    string s=to_string(num);
    vector<char> digits;
    digits.push_back(s[0]);
    digits.push_back(s[1]);
    digits.push_back(s[2]);
    digits.push_back(s[3]);
    sort(digits.begin(),digits.end());
    int count;
    for(int i=0;i<4;i++){
        if(digits[i]=='0'){
            count++;
        }
    }
    if(count==3){
        return digits[3]-'0';
    }
    else if(count==2){
        return (digits[2]-'0')+(digits[3]-'0');
    }
    else if(count==1){
        int a=digits[1]-'0';
        int b=digits[2]-'0';
        int c=digits[3]-'0';
        return min(min((10*a+b)+c, (10*b+c)+a), (10*c+a)+b);
    }
    else {
        int a=digits[0]-'0';
        int b=digits[1]-'0';
        int c=digits[2]-'0';
        int d=digits[3]-'0';
        return min(a*10+c+b*10+d , a*10+d+b*10+c);
    }

}

};