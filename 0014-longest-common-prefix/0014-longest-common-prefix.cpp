class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs[0].length();
    for(int i=0;i<strs.size();i++){
        if (len>strs[i].length()){
            len=strs[i].length();
        }
    }
    // cout<<len;
    string s="";
    for(int i=0;i<len;i++){
        bool flag=true;
        for(int j=0;j<strs.size()-1;j++){
            // s+=strs[0][i];
            if(strs[j][i]!=strs[j+1][i]){
                flag=false;
                break;
            }
            
            

        }
        if(flag==true){
            s+=strs[0][i];
            // cout<<s<<endl;
        }
        else if(flag==false){
            break;
        }
    }
    return s;
    }
};