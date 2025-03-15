class Solution {
public:
    #define ll long long
#define push(a) push_back(a)
#define f(i, a, b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vprint(v) for (auto& elem : v) cout << elem << " "; cout << endl;
#define mprint(m) for (auto it:m) cout<<it.first<<" : "<<it.second<<endl; cout<<endl;
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

vector<int> rearrangeArray(vector<int>& nums){
    vint positive;
    vint negative;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            negative.push_back(nums[i]);
        }
        else {
            positive.push_back(nums[i]);
        }
    }
    int a=0,b=0;
    vint ans;
    for(int i=0;i<n;i++){
        if(i%2==0){
            ans.push_back(positive[a]);
            a++;
        }
        else{
            ans.push_back(negative[b]);
            b++;
        }
    }
    return ans;
}
};