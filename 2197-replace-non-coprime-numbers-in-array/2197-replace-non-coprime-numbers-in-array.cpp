class Solution {

#define ll long long
public:
   vector<int> replaceNonCoprimes(vector<int> &nums)
{
    stack <ll> st;// to stroe the array after merging
    st.push(1LL*nums[0]);
    for(int i=1;i<nums.size();i++){
        ll cur= (ll)nums[i];

        while(!st.empty()){
            ll top= st.top();
            ll g= __gcd(top, cur);
            if(g==1) break; //coprime--> stop merging
            st.pop();

            cur= (top/g) * cur;
        }
        st.push(cur);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    // vprint(ans);
    return ans;
}
};