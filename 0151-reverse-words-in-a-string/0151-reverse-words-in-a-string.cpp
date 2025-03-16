class Solution {
public:
    vector<string> makewords(string s){
    s+=" ";
    vector<string> ans;
    string w;
    for(int i=0;i<s.length();i++){
        if(s[i]!=' '){
            w+=s[i];
        }
        else{
            ans.push_back(w);
            w="";
        }
    }
    return ans;
}

vector<string> filter(vector<string> vec){
    // cout<<vec.size()<<endl;
    vector<string> ans;
    int n=vec.size();
    for(int i=0;i<n;i++){
        // cout<<"vec["<<i<<"] : "<<vec[i]<<" & "<<"size : "<<vec[i].length()<<endl;

        if(vec[i].length()!=0){
            // vec.erase(vec.begin()+i);
            ans.push_back(vec[i]);
        }
    }
    // cout<<"After filtering : "<<endl;
    // for(int i=0;i<ans.size();i++){
    //     cout<<"ans["<<i<<"] : "<<ans[i]<<" & "<<"size : "<<ans[i].length()<<endl;
    // }
    // cout<<"stop"<<endl;
    return ans;
}



string reverseWords(string s) {
    vector<string> vec=makewords(s);
    vec=filter(vec);
    reverse(vec.begin(),vec.end());
    string ans;
    for(int i =0;i<vec.size();i++){
        if(i==vec.size()-1){
            ans+=vec[i];
        }
        else{
            ans+=vec[i]+" ";
        }
        
    }
    return ans;


}
};