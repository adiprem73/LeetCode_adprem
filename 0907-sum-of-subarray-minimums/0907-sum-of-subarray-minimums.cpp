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

vector<int> nextSmallerElement(vector<int> nums)
{
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nse[i] = n;
        }
        else
        {
            nse[i] = st.top();
        }

        st.push(i);
    }
    return nse;
}

vector<int> previousSmallerElement(vector<int> nums)
{
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vint nse = nextSmallerElement(arr);
    vint pse = previousSmallerElement(arr);
    int total = 0;
    int left, right;
    for (int i = 0; i < n; i++)
    {
        left = i - pse[i];
        right = nse[i] - i;
        total = (total + (1LL*right * left * arr[i] ) % MOD) % MOD;
    }
    return total;
}
};