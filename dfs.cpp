#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX];  // adjacency list
bool visited[MAX];     // to keep track of visited nodes

// DFS function
void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (format: u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // for undirected graph
    }

    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    // Initialize visited array
    for (int i = 0; i < vertices; ++i)
        visited[i] = false;

    cout << "DFS traversal: ";
    DFS(start);

    return 0;
}
