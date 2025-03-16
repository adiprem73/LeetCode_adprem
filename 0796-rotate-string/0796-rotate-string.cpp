class Solution {
public:
    bool rotateString(string s, string goal) {
    int k=s.size();
    for(int i=0;i<k;i++){
        string news=s.substr(1);
        news+=s[0];
        s=news;
        if(s==goal){
            return true;
        }
    }   
    return false; 
}
};