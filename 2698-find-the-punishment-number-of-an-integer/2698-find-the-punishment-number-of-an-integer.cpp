class Solution {
public:
    void split(int ind, string & s, vector<string> & curr, vector<vector<string>> & ans){
    if(ind == s.length()){
        ans.push_back(curr);
        return;
    }

    // trying all possible subsring starting at index
    for(int i= ind; i<s.length();i++){
        string part = s.substr(ind, i-ind+1);
        curr.push_back(part);
        split(i+1, s, curr, ans);
        curr.pop_back(); // nacktrack
    }
}

bool check(int n){
    int square = n*n;
    string s= to_string(square);
    vector<vector<string>> all ;
    vector<string> curr;
    split(0, s, curr, all);

    for(auto it: all){
        int sum=0;
        for(auto itr: it){
            sum+=stoi(itr);
        }
        if(sum == n)return true;
    }return false;
}

int punishmentNumber(int n)
{
    int ans=0;

    for(int i=1;i<=n;i++){ // we need to check all number from 1 to n
        if(check(i)){
            ans+=i*i;
        }
    }
    return ans;
}

};