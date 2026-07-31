class Solution {
public:
     long long minCost(int m, int n, vector<vector<int>>& penalty) {

        
    long long nn = penalty.size(),mm = penalty[0].size();
    long long inf = 1e15;
    vector<vector<vector<long long>>> mn(nn,vector<vector<long long>>(mm,vector<long long>(2,inf)));
    mn[0][0][1] =1;
    priority_queue<vector<long long>,vector<vector<long long>>,greater<>> pq;
        pq.push({1,0,0,1});
    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        long long sm =it[0],a =it[1],b=it[2],p=it[3];
        if(sm > mn[a][b][p])continue;

        if(p%2==0){
            if(a-1>=0 && mn[a-1][b][1] > sm + (a)*(b+1)){
                pq.push({sm + (a)*(b+1),a-1,b,(p+1)%2});
                mn[a-1][b][1] = sm + (a)*(b+1);
            }
            if(b-1>=0 && mn[a][b-1][1] > sm + (a+1)*(b)){
                pq.push({sm + (a+1)*(b),a,b-1,(p+1)%2});
                mn[a][b-1][1] = sm + (a+1)*(b);
            }
            if(a+1<nn && mn[a+1][b][1] > sm + (a+1+1)*(b+1) + penalty[a][b]){
                pq.push({sm + (a+1+1)*(b+1) + penalty[a][b],a+1,b,(p+1)%2});
                mn[a+1][b][1] = sm + (a+1+1)*(b+1) + penalty[a][b];
            }
            if(b+1<mm && mn[a][b+1][1] >sm + (a+1)*(b+2) + penalty[a][b]){
                pq.push({sm + (a+1)*(b+2) + penalty[a][b],a,b+1,(p+1)%2});
                mn[a][b+1][1] = sm + (a+1)*(b+2) + penalty[a][b];
            }
        }
        else{
            if(a-1>=0 && mn[a-1][b][0] > sm + (a)*(b+1) + penalty[a][b]){
                pq.push({sm + (a)*(b+1) + penalty[a][b],a-1,b,(p+1)%2});
                mn[a-1][b][0] = sm + (a)*(b+1) + penalty[a][b];
            }
            if(b-1>=0 && mn[a][b-1][0] > sm + (a+1)*(b) + penalty[a][b]){
                pq.push({sm + (a+1)*(b) + penalty[a][b],a,b-1,(p+1)%2});
                mn[a][b-1][0] = sm + (a+1)*(b) + penalty[a][b];
            }
            if(a+1<nn && mn[a+1][b][0] > sm + (a+1+1)*(b+1) ){
                pq.push({sm + (a+1+1)*(b+1) ,a+1,b,(p+1)%2});
                mn[a+1][b][0] = sm + (a+1+1)*(b+1) ;
            }
            if(b+1<mm && mn[a][b+1][0] >sm + (a+1)*(b+2) ){
                pq.push({sm + (a+1)*(b+2) ,a,b+1,(p+1)%2});
                mn[a][b+1][0] = sm + (a+1)*(b+2) ;
            }
            
        }

        if(mn[a][b][(p+1)%2] > sm + penalty[a][b]){
                pq.push({sm + penalty[a][b] ,a,b,(p+1)%2});
                mn[a][b][(p+1)%2] = sm + penalty[a][b] ;

        }
        
    }


    long long f = min(mn[nn-1][mm-1][0],mn[nn-1][mm-1][1]);
    return f;
        
    }
};