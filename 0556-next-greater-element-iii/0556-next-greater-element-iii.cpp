class Solution {
public:
    int nextGreaterElement(int n) {
        long num = n;
        int currDigit = -1, prevDigit = -1;
        vector<int> count(10);
        while (num > 0) {
            currDigit = (int)num % 10;
            num = num / 10;
            count[currDigit]++;
            if (prevDigit > currDigit) {
                int temp = currDigit + 1;
                while (count[temp] == 0)
                    temp++;
                num = num * 10 + temp;
                count[temp]--;
                for (int i = 0; i < 10; i++) {
                    while (count[i] != 0) {
                        num = num * 10 + i;
                        count[i]--;
                    }
                }
                return num>INT_MAX? -1: (int)num;
            }
            prevDigit = currDigit;
        }
        return -1;
    }
};