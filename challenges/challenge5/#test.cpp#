#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Edge {
    int weight;
    int vertex;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

void gen_mst(const vector<vector<int> > &graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> in_mst(n, false);
    vector<int> parent(n, -1);

    priority_queue<Edge, vector<Edge>, greater<Edge> > pq; // priority queue that keeps smallest element on top
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        if (in_mst[u]) continue;
        in_mst[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != -1 && !in_mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < n; ++i) {
        totalWeight += key[i];
    }

    cout << totalWeight << endl;
    for (int i = 1; i < n; ++i) {
        cout << static_cast<char>('A' + parent[i]) << static_cast<char>('A' + i) << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjmatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjmatrix[i][j];
        }
    }

    gen_mst(adjmatrix);

    return 0;
}
