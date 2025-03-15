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

void rotate(vector<int> &nums, int k){
    int n=nums.size();
    k=k%n;
    if (k==0){
        
    }
    else if(n==1){

    }
     else if(n==2&&k==0){

    }
    
    else if(n==2&&k==1){
        reverse(nums.begin(),nums.end());
    }
    else{
        k=k%n;
        vint newArray;
        newArray.push_back(nums[n-k]);
        for(int i=n-k+1;i<n;i++){
            newArray.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            newArray.push_back(nums[i]);
        }
        // vprint(newArray);
        nums=newArray;
    }
}
};