#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    bool isHamiltonianUtil(int pos, vector<bool>& visited, int count);

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isHamiltonian();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

bool Graph::isHamiltonianUtil(int pos, vector<bool>& visited, int count) {
    if (count == V) {
        return true;
    }

    for (int v = 0; v < V; v++) {
        if (adj[pos][v] && !visited[v]) {
            visited[v] = true;
            if (isHamiltonianUtil(v, visited, count + 1)) {
                return true;
            }
            visited[v] = false;
        }
    }

    return false;
}

bool Graph::isHamiltonian() {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        visited[i] = true;
        if (isHamiltonianUtil(i, visited, 1)) {
            return true;
        }
        visited[i] = false;
    }

    return false;
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

    if (g.isHamiltonian()) {
        cout << "Graph contains a Hamiltonian Path/Circuit" << endl;
    } else {
        cout << "Graph does not contain a Hamiltonian Path/Circuit" << endl;
    }

    return 0;
}
