class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans =0;
        if (hour == 12){
            hour = 0;
        }
        double angleMinutesHand = 6*minutes;
        double angleHourHand = hour*30 + minutes/2.0;
        ans = min(min(abs(angleMinutesHand - angleHourHand), abs(360.0-angleMinutesHand+ angleHourHand)), abs(360.0-angleHourHand + angleMinutesHand));
        return ans;
    }
};