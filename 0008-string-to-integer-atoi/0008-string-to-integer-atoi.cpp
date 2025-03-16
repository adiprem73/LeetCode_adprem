class Solution {
public:
    int myAtoi(string s) {
    int i = 0;
    int n = s.length();
    int sign = 1;
    int result = 0;

    // Ignore leading whitespace
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Handle sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Process digits
    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}
};