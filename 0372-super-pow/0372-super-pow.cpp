class Solution {
public:
    int modPow(int a, int b)
{

    int res = 1;

    a %= 1337;

    while (b)
    {

        if (b & 1)
            res = (res * 1LL * a) % 1337;

        a = (a * 1LL * a) % 1337;

        b >>= 1;
    }

    return res;
}

int func(int ind, int ans, int a, vector<int> &b)
{

    if (ind == b.size())
        return ans;

    ans = modPow(ans, 10);

    ans = (ans * 1LL * modPow(a, b[ind])) % 1337;

    return func(ind + 1, ans, a, b);
}

int superPow(int a, vector<int>& b){
    return func(0,1, a,b);
}
};