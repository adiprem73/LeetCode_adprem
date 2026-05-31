class Solution {
public:
    int timeConvert(string s) {
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[3] - '0';
        int d = s[4] - '0';

        int time = 0;
        time = a * 1000 + b * 100 + c * 10 + d;
        return time;
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> e1 = {timeConvert(event1[0]), timeConvert(event1[1])};
        vector<int> e2 = {timeConvert(event2[0]), timeConvert(event2[1])};
        vector<vector<int>> events = {e1, e2};
        sort(events.begin(), events.end());

        if (events[0][1] >= events[1][0])
            return true;
        else
            return false;
    }
};