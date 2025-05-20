class Solution {
public:
    #define ll long long
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define vmatprint(vv) for (auto& row : vv) { for (auto& elem : row) cout << elem << " "; cout << endl; } cout << endl;
#define mprint(m) for (auto it : m) cout << it.first << " : " << it.second << endl; cout << endl;
#define vint vector<int>
#define vstring vector<string>
#define vmat vector<vector<int>>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>

const int INF = 1e9;
const ll MOD = 1e9+7;

// int nextGreatElement(vint nums, int n){
//     bool flag=false;
//     int ans=-1;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]==n){
//             flag=true;
//         }
//         if(flag==true&&nums[i]>n){
//             return nums[i];
//         }
//     }
//     return -1;
// }

map<int,int> nge(vector<int> &nums2){
    stack<int> st;
    vint ans(nums2.size());
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty()&&st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty())ans[i]=-1;
        else ans[i]=st.top();
        st.push(nums2[i]);
    }
    // vprint(ans);
    map<int,int> result;
    for(int i=0;i<nums2.size();i++){
        result[nums2[i]]=ans[i];
    }
    // mprint(result);
    return result;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    vint ans;
    map<int,int> res=nge(nums2);
    for(int i=0;i<nums1.size();i++){
        ans.push_back(res[nums1[i]]);
    }
    return ans;
}
};