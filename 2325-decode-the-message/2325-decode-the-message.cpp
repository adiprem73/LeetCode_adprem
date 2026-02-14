class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,int>mp;
        int x=0;
        for(auto ch : key){
            if(ch!=' '&& mp.find(ch)==mp.end()){
                cout<<x<<endl;
                mp[ch]=x++;
            }
        }
        for(auto it: mp){
            cout<<it.first<<" : "<<it.second<<endl;
        }
        string ans="";
        for(auto ch : message){
            if(ch == ' '){
                ans+=' ';
            }else{
                ans+='a' + mp[ch];
            }
        }
        return ans;
    }
};