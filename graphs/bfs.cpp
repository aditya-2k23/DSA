#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ! BFS Traversal is the process of visiting all the nodes of a graph starting from a source node in such a way that all the nodes are visited level by level.

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int V, int s) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u])
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
    cout << endl;
}

void printList(vector<int> adj[], int V) {
    for (int i = 0; i < V; ++i) {
        cout << i << "-> ";
        for (auto v : adj[i])
            cout << v << " ";
        cout << endl;
    }
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
    cout << "Enter the starting vertex for BFS: ";
    cin >> start;

    if (start < 0 || start >= V) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    cout << "BFS Traversal starting from vertex " << start << ": " << endl;
    bfs(adj, V, start);

    printList(adj, V);

    return 0;
}
