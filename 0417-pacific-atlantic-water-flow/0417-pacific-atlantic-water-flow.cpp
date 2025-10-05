class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int n=heights.size();
    if(!n)return {};
    int m=heights[0].size();
    set<pair<int,int>> pacific;
    set<pair<int,int>> atlantic;
    vector<int> dr={-1, 0 ,1,0};
    vector<int> dc={0,1,0, -1};

    // for column of pacific
    for(int i=0;i<n;i++){
        // [i][0]
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        q.push({{i,0}, heights[i][0]});
        vis[i][0]=1;
        pacific.insert({i,0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int r= it.first.first;
            int c= it.first.second;
            int h= it.second;

            for(int i=0;i<4;i++){
                int nr= r+dr[i];
                int nc= c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    int nh = heights[nr][nc];
                    if(nh>=h){
                        q.push({{nr, nc}, nh});
                        vis[nr][nc] = 1;
                        pacific.insert({nr, nc});
                    }
                    
                }
            }
        }
        // set<pair<int, int>> pacific_copy = pacific;
        // cout << "Pacific set:" << endl;
        // for (auto &p : pacific_copy)
        // {
        //     cout << "(" << p.first << "," << p.second << ") ";
        // }
        // cout << endl;
    }
    // cout<<m;
    // for row touching pacific
    for(int i=0;i<m;i++){
        // [0][i]
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({{0, i}, heights[0][i]});
        vis[0][i] = 1;
        pacific.insert({0, i});
        // cout<<"hello"<<endl;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int h = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 )
                {
                    int nh = heights[nr][nc];
                    if(h<=nh){
                        q.push({{nr, nc}, nh});
                        vis[nr][nc] = 1;
                        pacific.insert({nr, nc});
                    }
                    
                }
            }
        }
        // set<pair<int, int>> pacific_copy = pacific;
        // cout << "Pacific set:" << endl;
        // for (auto &p : pacific_copy)
        // {
        //     cout << "(" << p.first << "," << p.second << ") ";
        // }
        // cout << endl;
    }

    // for column touchgin atlantic
    for (int i = 0; i < n; i++)
    {
        // [i][m-1]
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({{i, m-1}, heights[i][m-1]});
        vis[i][m-1] = 1;
        atlantic.insert({i, m-1});
        // cout<<"hello"<<endl;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int h = it.second;
            // cout<<r<<" "<<c<<endl;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0)
                {
                    int nh = heights[nr][nc];
                    if(h<=nh){
                        q.push({{nr, nc}, nh});
                        vis[nr][nc] = 1;
                        atlantic.insert({nr, nc});
                    }
                    
                }
            }
        }
        // set<pair<int, int>> atlantic_copy = atlantic;
        // cout << "Atlantic set:" << endl;
        // for (auto &a : atlantic_copy)
        // {
        //     cout << "(" << a.first << "," << a.second << ") ";
        // }
        // cout << endl;
    }
    

    // for row touching atlantic
    for (int i = 0; i < m; i++)
    {
        // [n-1][i]
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({{n-1, i}, heights[n-1][i]});
        vis[n-1][i] = 1;
        atlantic.insert({n-1, i});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int h = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 )
                {
                    int nh = heights[nr][nc];
                    if(h<=nh){
                        q.push({{nr, nc}, nh});
                        vis[nr][nc] = 1;
                        atlantic.insert({nr, nc});
                    }
                    
                }
            }
        }
        // set<pair<int, int>> atlantic_copy = atlantic;
        // cout << "Atlantic set:" << endl;
        // for (auto &a : atlantic_copy)
        // {
        //     cout << "(" << a.first << "," << a.second << ") ";
        // }
        // cout << endl;
    }

    // set<pair<int,int>> pacific_copy = pacific;
    // set<pair<int,int>> atlantic_copy = atlantic;

    // cout << "Pacific set:" << endl;
    // for (auto &p : pacific_copy) {
    //     cout << "(" << p.first << "," << p.second << ") ";
    // }
    // cout << endl;

    // cout << "Atlantic set:" << endl;
    // for (auto &a : atlantic_copy) {
    //     cout << "(" << a.first << "," << a.second << ") ";
    // }
    // cout << endl;

    vector<vector<int>> ans;

    for(auto it: pacific){
        if(atlantic.find(it)!= atlantic.end()){
            ans.push_back({it.first, it.second});
        }
    }

    return ans;
}
};