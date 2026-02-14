class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;
        for(char ch: s){
            mp[ch]++;
        }
        int v=0, c=0;
        for(auto it: mp){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u' ){
                v= max(v, it.second);
            }else{
                c = max(c, it.second);
            }
        }
        cout<<v<<endl;
        cout<<c<<endl;
        return (v+c);
    }
};