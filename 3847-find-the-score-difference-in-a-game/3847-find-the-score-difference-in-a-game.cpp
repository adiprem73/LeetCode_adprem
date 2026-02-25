class Solution {
public:
    int scoreDifference(vector<int> &nums)
{
    int n = nums.size();
    int score1 = 0, score2 = 0;
    bool active1 = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 != 0)
        {
            active1 = !active1;
        }
        if ((i + 1) % 6 == 0)
        {
            active1 = !active1;
        }
        cout << "active1 : " << active1 << endl;
        if (active1 == true)
        {
            score1 += nums[i];
        }
        else
        {
            score2 += nums[i];
        }
        cout << "turn : " << i << " score1 : " << score1 << " score2 : " << score2 << endl;
    }
    return score1 - score2;
}

};