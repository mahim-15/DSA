#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, vector<string>> graph;
unordered_map<string, bool> visited;

void dfs(string node) {
    visited[node] = true;
    cout << node << " ";

    for (auto &nbr : graph[node]) {
        if (!visited[nbr]) {
            dfs(nbr);
        }
    }
}

int main() {
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (e.g., A B or 1 2):\n";
    for (int i = 0; i < edges; i++) {
        string u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    string start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);
    cout << endl;

    return 0;
}