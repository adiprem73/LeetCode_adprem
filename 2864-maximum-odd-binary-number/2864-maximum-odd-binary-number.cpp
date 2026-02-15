class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zeros=0, ones=0;
        for(auto ch: s){
            cout<<ch<<endl;
            if(ch == '0')zeros++;
            else ones++;
        }
        cout<<"ones : "<<ones<<endl;
        string s1;
        string s2;
        for(int i=0;i<ones-1;i++){
            s1+='1';
        }
            for(int i=0;i<zeros;i++){
            s2+='0';
        }
        return s1+s2+'1';
    }
};