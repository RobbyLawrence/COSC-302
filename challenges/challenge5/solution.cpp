#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from;
    int vertex;
    int weight;
    bool operator>(Edge edge) const {
        return weight > edge.weight;
    }
    Edge(int fromn, int vertexn, int weightn) {
        from = fromn;
        vertex = vertexn;
        weight = weightn;
    }
};

vector<Edge> gen_mst(vector<vector<pair<int,int> > > &adjlist) {
    int n = adjlist.size();
    vector<bool> visited(n, false);
    vector<Edge> mst;
    priority_queue<Edge, vector<Edge>, greater<Edge> > frontier;

    visited[0] = true;

    // we start with the 0th vertex
    for (pair<int,int> &edge : adjlist[0]) {
        frontier.push(Edge(0, edge.first, edge.second));
    }

    while (!frontier.empty() && mst.size() < n - 1) {
        Edge edge = frontier.top();
        frontier.pop();

        // If the vertex is already in the MST, skip
        if (visited[edge.vertex]) {
            continue;
        }

        // Add the edge to the MST
        mst.push_back(edge);
        visited[edge.vertex] = true;

        // Add all edges from the newly added vertex
        for (pair<int,int> &nextEdge : adjlist[edge.vertex]) {
            if (!visited[nextEdge.first]) {
                frontier.push(Edge(edge.vertex, nextEdge.first, nextEdge.second));
            }
        }
    }

    // Check if the MST includes all vertices
    if (mst.size() != n - 1) {
        cerr << "Graph is not connected, cannot form a complete MST" << endl;
    }

    return mst;
}

int main() {
    int num_vertices;
    while (cin >> num_vertices) {
        // import graph
        vector<vector<pair<int,int> > > adjlist(num_vertices);
        int weight;
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                cin >> weight;
                if (weight == -1) {
                    continue;
                }
                if (i != j) {
                    adjlist[i].push_back(make_pair(j, weight));
                }
            }
        }

        vector<Edge> mst = gen_mst(adjlist);
        sort(mst.begin(), mst.end(), [](const Edge& a, const Edge& b) {
                return a.vertex > b.vertex;
        });
        int total_weight = 0;
        for (Edge &edge : mst) {
            total_weight += edge.weight;
        }
        cout << total_weight << endl;
        for (Edge &edge : mst) {
            cout << (char)(min(edge.from,edge.vertex) + 'A') << (char)(max(edge.from,edge.vertex) + 'A') << endl;
        }
        cout << '\n';
    }
    return 0;
}
