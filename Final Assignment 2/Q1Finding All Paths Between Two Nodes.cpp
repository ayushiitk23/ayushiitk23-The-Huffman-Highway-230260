#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    void findAllPathsUtil(int u, int v, vector<bool>& visited, vector<int>& path);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void findAllPaths(int u, int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::findAllPathsUtil(int u, int v, vector<bool>& visited, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == v) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        for (int i : adj[u]) {
            if (!visited[i]) {
                findAllPathsUtil(i, v, visited, path);
            }
        }
    }

    path.pop_back();
    visited[u] = false;
}

void Graph::findAllPaths(int u, int v) {
    vector<bool> visited(V, false);
    vector<int> path;
    findAllPathsUtil(u, v, visited, path);
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int u, v;
    cout << "Enter the start and end nodes (format: u v): ";
    cin >> u >> v;

    g.findAllPaths(u, v);

    return 0;
}
