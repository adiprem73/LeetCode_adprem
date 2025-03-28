class Solution {
public:
    bool isValid(string s){
        bool flag=true;
        vector<char> stacks;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(s.length()==1){
                flag= false;
                break;
            }
            if(c=='('||c=='{'||c=='['){
                // cout<<"hii"<<endl;
                stacks.push_back(c);
            }
            else if(c==')'){
                if(stacks.size()==0){
                    flag=false;
                    break;
                }

                else if(stacks[stacks.size()-1]=='('){
                    // cout<<"hlw"<<endl;
                    stacks.pop_back();
                }
                else{
                    flag=false;
                    break;
                }
            }
            else if(c=='}'){
                if(stacks.size()==0){
                    // cout<<"ehllo1";
                    flag=false;
                    break;
                }
                else if(stacks[stacks.size()-1]=='{'){
                    // cout<<"ehllo";
                    stacks.pop_back();

                }
                else{
                    // cout<<"4ehllo";
                    flag=false;
                    break;
                }
            }
            else if(c==']'){
                if(stacks.size()==0){
                    flag=false;
                    break;
                }
                else if(stacks[stacks.size()-1]=='['){
                    stacks.pop_back();

                }
                else{
                    flag=false;
                    break;
                }
            }
            // cout<<"i : "<<i<<" your stack: "<<endl;
            // for(int j=0;j<stacks.size();j++){
            //     cout<<stacks[j]<<" ";
            // }
            // cout<<endl;
        }
        if(stacks.size()==0){
            return flag;
        }
        else{
            return 0;
        }
    }
};