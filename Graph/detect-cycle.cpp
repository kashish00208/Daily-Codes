#include <bits/stdc++.h>
using namespace std;

void build(int n , int m ,vector<vector<int>> &adj){
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
            break;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool detectCycleDFS(int node,int parent , vector<vector<int>>&adj,int n ){
    vector<int>visited(n,0);
    visited[node] = 1;
    for(auto neighbor : adj[node]){
        if(!visited[neighbor]){
            if(detectCycleDFS(neighbor,node,adj,n)==true){
                return true;
            }
            else if(neighbor!=parent){
                return true;
            }
        }
    }
    return false;
}

bool detectCycleBFS(int n, int m,vector<vector<int>> &adj) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<pair<int, int>> q;
            q.push({i, -1});
            visited[i] = 1;

            while (!q.empty()) {
                int currentNode = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int neighbor : adj[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push({neighbor, currentNode});
                    }
                    else if (neighbor != parent) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    build(n,m,adj);
    if (detectCycleBFS(n, m, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle" << endl;
    }
    return 0;
}