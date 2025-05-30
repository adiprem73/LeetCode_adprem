class Solution {
public:
    int countKeyChanges(string s){
    int n=s.length();
    int count=0;
    for(int i=0;i<n-1;i++){
        char ch=s[i];
        char nch=s[i+1];
        if(toupper(ch)==toupper(nch)){}
        else count++;
    }
    return count;
}
};