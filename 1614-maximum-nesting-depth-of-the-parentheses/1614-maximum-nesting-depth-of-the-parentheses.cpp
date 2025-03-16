class Solution {
public:
    int maxDepth(string s) {
    int counter=0;
    int max_counter=0;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(') {
            counter++;
            max_counter=max(max_counter,counter);
        }
        else if(ch==')') counter--;
    }
    return max_counter;
}
};