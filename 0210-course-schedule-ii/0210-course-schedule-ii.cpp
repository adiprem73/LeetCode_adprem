class Solution {
public:
    bool detect(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>> &graph, vector<int> &order) {
    vis[node] = 1;
    pathvis[node] = 1;

    for (auto it : graph[node]) {
        if (vis[it] == 0) {
            if (detect(it, vis, pathvis, graph, order))
                return true; // cycle found
        } 
        else if (pathvis[it] == 1) {
            return true; // cycle found
        }
    }

    pathvis[node] = 0;
    order.push_back(node); // add to topo order after visiting all dependencies
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto &p : prerequisites) {
        graph[p[1]].push_back(p[0]);
    }

    vector<int> vis(numCourses, 0), pathvis(numCourses, 0), order;
    
    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (detect(i, vis, pathvis, graph, order)) {
                return {}; // cycle detected
            }
        }
    }

    reverse(order.begin(), order.end()); // reverse for correct topological order
    return order;
}
};