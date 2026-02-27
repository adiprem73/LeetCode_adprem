class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // building the adjacency list(node, probability)
        vector<vector<pair<int,double>>> adj(n);
        for(int i =0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> prob(n, 0);
        priority_queue<pair<double,int>> pq; // (probability, node)
        pq.push({1,start_node});
        prob[start_node] = 1;
        while(!pq.empty()){
            auto [pr, nd] = pq.top();
            cout<<pr<<" "<<nd<<endl;
            pq.pop();
            if(nd == end_node){
                return pr;
            }
            for(auto nb: adj[nd]){
                int adjNode= nb.first;
                double adjProb= nb.second;
                cout<<adjNode<<"&"<<adjProb<<endl;
                if(pr*adjProb > prob[adjNode]){
                    prob[adjNode]= pr*adjProb;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        return 0;
    }
};