class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    int n = asteroids.size();
    if(n==1)return mass>=asteroids[0];
    long long curr = mass;
    sort(asteroids.begin(), asteroids.end());
    for(int i=0;i<=n-1;i++){
        if (curr >= asteroids[i])
            curr += asteroids[i];
        else return false;

        // if(curr < asteroids[i+1])return false;
    }
    if(curr>=asteroids.back())return true;
    return false;
}
};