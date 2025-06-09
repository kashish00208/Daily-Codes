#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool detectCycle(int n, int m) {
    vector<vector<int>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
            return true;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

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
                        // Cycle detected
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
    if (detectCycle(n, m)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle" << endl;
    }
    return 0;
}
