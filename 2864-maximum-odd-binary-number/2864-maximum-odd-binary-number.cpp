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
        s1.append(ones-1, '1');
        s1.append(zeros, '0');
        s1.append(1, '1');
        return s1;
    }
};