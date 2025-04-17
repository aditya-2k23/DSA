#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int u, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u])
        if (!visited[v])
            dfs(adj, v, visited);
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    if (V <= 0) {
        cout << "Number of vertices must be positive." << endl;
        return 1;
    }

    vector<int> adj[V];

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v) with vertices numbered from 0 to " << V - 1 << ":" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= V || v >= V) {
            cout << "Invalid edge: (" << u << ", " << v << ")" << endl;
            continue;
        }
        addEdge(adj, u, v);
    }

    int start;
    cout << "Enter the starting vertex for DFS: ";
    cin >> start;

    if (start < 0 || start >= V) {
        cout << "Invalid starting vertex." << endl;
        return 1;
    }

    vector<bool> visited(V, false);
    dfs(adj, start, visited);

    return 0;
}
