class Solution {
public:
    double distance(vector<int> a, vector<int> b){
    int x=a[0]-b[0];
    int y=a[1]-b[1];
    x=x*x;
    y=y*y;
    double dist= sqrt(x+y);
    return dist;
}


double largestTriangleArea(vector<vector<int>>& points) {
    double ans=INT_MIN;
    int n=points.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                vector<int> p= points[i];
                vector<int> q = points[j];
                vector<int> r = points[k];
                double u= distance(p,q);
                double v= distance(q,r);
                double w= distance(r,p);
                double perimeter= (u+v+w)/2;
                double area= sqrt(perimeter*(perimeter-u)*(perimeter-v)*(perimeter-w));
                ans=max(ans, area);
            }
        }
    }
    return ans;
}
};