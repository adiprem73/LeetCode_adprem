class Solution {
public:
    void func(vector<int>& digits, int n, int noDigits, vector<bool>& used, int &cnt, vector<int>& visit){
    if (noDigits == 3)
    {
        if (n % 2 == 0 && visit[n] == 0)
        {
            cnt++;
            visit[n] = 1;
        }
        return;
    }

    // cout<<n<<endl;

    for(int i=0;i<digits.size();i++){
        if(used[i])continue; // this is so that the digits dont get used twixe

        if(noDigits == 0 && digits[i]==0)continue; // this will avoid all the leading zeroes

        used[i]= true; // this will mark the digits if it is used
        func(digits, n*10 + digits[i], noDigits+1, used, cnt, visit);
        used[i]= false; // this will do the backtracking
    }
}

int totalNumbers(vector<int> &digits)
{
    vector<bool> used(digits.size(), false);
    int cnt=0;
    vector<int> visit(1000,0);
    func(digits, 0, 0, used, cnt, visit);
    return cnt;
}
};