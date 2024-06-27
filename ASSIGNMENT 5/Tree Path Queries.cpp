#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100005;  // Maximum number of nodes
const int LOG = 17;       // log2(MAXN)

vector<int> tree[MAXN];
int depth[MAXN], parent[MAXN][LOG];
int sumUp[MAXN][LOG], maxUp[MAXN][LOG], minUp[MAXN][LOG];
int value[MAXN];  // Store values of nodes

void dfs(int node, int par) {
    parent[node][0] = par;
    depth[node] = depth[par] + 1;
    sumUp[node][0] = value[node];
    maxUp[node][0] = value[node];
    minUp[node][0] = value[node];

    for (int i = 1; i < LOG; i++) {
        if (parent[node][i-1] != -1) {
            parent[node][i] = parent[parent[node][i-1]][i-1];
            sumUp[node][i] = sumUp[node][i-1] + sumUp[parent[node][i-1]][i-1];
            maxUp[node][i] = max(maxUp[node][i-1], maxUp[parent[node][i-1]][i-1]);
            minUp[node][i] = min(minUp[node][i-1], minUp[parent[node][i-1]][i-1]);
        }
    }

    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

pair<int, int> getLCA(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int sum = 0, maxi = INT_MIN, mini = INT_MAX;

    // Bring u and v to the same depth
    for (int i = LOG-1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            sum += sumUp[u][i];
            maxi = max(maxi, maxUp[u][i]);
            mini = min(mini, minUp[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) {
        sum += value[u];
        maxi = max(maxi, value[u]);
        mini = min(mini, value[u]);
        return {sum, u};
    }

    for (int i = LOG-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            sum += sumUp[u][i] + sumUp[v][i];
            maxi = max(maxi, max(maxUp[u][i], maxUp[v][i]));
            mini = min(mini, min(minUp[u][i], minUp[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    sum += sumUp[u][0] + sumUp[v][0] + value[parent[u][0]];
    maxi = max(maxi, max(maxUp[u][0], maxUp[v][0]));
    mini = min(mini, min(minUp[u][0], minUp[v][0]));
    return {sum, parent[u][0]};
}

tuple<int, int, int> query(int u, int v) {
    auto [pathSum, lca] = getLCA(u, v);
    int sum = pathSum - value[lca];
    int maxi = max(max(maxUp[u][0], maxUp[v][0]), value[lca]);
    int mini = min(min(minUp[u][0], minUp[v][0]), value[lca]);

    return {sum, maxi, mini};
}

int main() {
    int n, q;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));
    depth[0] = -1;

    dfs(1, 0);  // Assuming 1 is the root

    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    for (const auto& [u, v] : queries) {
        auto [sum, maxi, mini] = query(u, v);
        cout << "Sum: " << sum << ", Max: " << maxi << ", Min: " << mini << endl;
    }

    return 0;
}
