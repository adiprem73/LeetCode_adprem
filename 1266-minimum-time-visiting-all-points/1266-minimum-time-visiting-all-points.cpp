class Solution {
public:
int findTime(int x1, int x2, int y1, int y2){
    int dx= abs(x1-x2);
    int dy= abs(y1-y2);

    return min(dx,dy) + abs(dx-dy);
}

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    int n= points.size();
    int time=0;
    for(int i=0;i<n-1;i++){
        int x1= points[i][0];
        int y1= points[i][1];
        int x2= points[i+1][0];
        int y2= points[i+1][1];

        time+=findTime(x1, x2, y1, y2);
    }
    return time;
}
};