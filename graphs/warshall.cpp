// ! Warshall Algorithm
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// ! Warshall Algorithm is used to find the shortest path between all pairs of vertices in a graph.
// ? It is also known as Floyd-Warshall Algorithm.

// * Time Complexity: O(V^3)
// * Space Complexity: O(V^2)

// TODO Implement Warshall Algorithm

void floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();

    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    if (V <= 0) {
        cout << "Number of vertices must be positive." << endl;
        return 1;
    }

    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));

    cout << "Enter the adjacency matrix of the graph (use INT_MAX for infinity):" << endl;
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    floydWarshall(graph);

    cout << "The shortest path matrix is:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}
