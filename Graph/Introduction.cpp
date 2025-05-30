#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> ans;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}

vector<int>dfs(int node , vector<vector<int>>adj,vector<int>&visited,vector<int>&ans){
    visited[node] = 1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,ans);
        }
    }

}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n); // 0-indexed

    cout << "Enter the edges (u, v) (0-indexed):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // validation to prevent segfault
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
            return 1;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> traverse = bfs(n, adj);

    cout << "BFS traversal of graph: ";
    for (int node : traverse) {
        cout << node << " ";
    }
    cout << endl;

    vector<int>visisted(n,0);
    vector<int>ans;
    dfs(0,adj,visisted,ans);
    cout << "DFS traversal of graph: ";
    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
