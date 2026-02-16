class Solution {
public:
    string concatHex36(int n)
{
    map<int, char> mp;
    for (int i = 0; i < 10; i++)
    {
        mp[i] = i+'0';
    }
    char ch = 'A';
    for (int i = 10; i < 36; i++)
    {
        mp[i] = ch;
        ch++;
    }

    string h1, h2;
    long long x = n * n;
    while (x > 0)
    {
        int remainder = x % 16;
        h1 += mp[remainder];
        x = x / 16;
    }
    long long y = n * n * n;
    while (y > 0)
    {
        int remainder = y % 36;
        h2 += mp[remainder];
        y = y / 36;
    }
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    return h1 + h2;
}
};