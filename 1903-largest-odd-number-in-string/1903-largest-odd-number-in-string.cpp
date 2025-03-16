class Solution {
public:
    string largestOddNumber(string num) {
    reverse(num.begin(),num.end());
    int targetIndex=-1;
    for(int i=0;i<num.size();i++){
        char ch=num[i];
        int digit=ch-'0';
        if(digit%2==1){
            targetIndex=i;
            break;
        }
    }
    if(targetIndex==-1){
        return "";
    }
    string s=num.substr(targetIndex);
    reverse(s.begin(),s.end());
    return s;
}
};