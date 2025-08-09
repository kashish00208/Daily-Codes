#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> visited, stack<int> st, vector<vector<int>> adj)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, st, adj);
        }
    }
    st.push(node);
}
void toppLogicalSort(vector<vector<int>> adj, int nodes)
{
    stack<int> st;
    vector<int> visited = {0};
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        cout<<st.top()<<" ";
        st.pop();
    }
}


int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter the edges (u, v) (0-indexed):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // validation to prevent segfault   a`
        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
            return 1;
        }

        adj[u].push_back(v);
    }
    toppLogicalSort(adj,n);

    return 0;
}

