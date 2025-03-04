#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <fstream>
#include <queue>
using namespace std;

bool find_path(int starting_vertex, int ending_vertex, const vector<vector<int>>& adjmatrix, vector<bool> visited) {
    if (starting_vertex == ending_vertex) {
        return true; // same node case
    }
    queue<int> q;
    q.push(starting_vertex);
    visited[starting_vertex] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (size_t i = 0; i < adjmatrix.size(); i++) {
            if (adjmatrix[current][i] == 1 && !visited[i]) {
                if (i == (size_t)ending_vertex) {
                    return true;
                }
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    int num_vertices;
    fin >> num_vertices;
    int edge_weight = -2;
    vector<vector<int> > matrix(num_vertices,vector<int>(num_vertices,0));
    vector<vector<int> > adjmatrix(num_vertices,vector<int>(num_vertices,0));
    vector<int> mst;
    for (int i = 0;i<num_vertices;i++) {
        for (int j = 0;j<num_vertices;j++) {
            fin >> edge_weight;
            matrix[i][j] = edge_weight;
        }
    }
    // we also need to construct an adjmatrix
    vector<pair<pair<int,int>,int> > weighted_edge_list;
    for (int i = 0;i<num_vertices;i++) {
        for (int j = i;j<num_vertices;j++) {
            edge_weight = matrix[i][j];
            if (edge_weight < 0) {
                continue;
            }
            weighted_edge_list.push_back(make_pair(make_pair(i,j),edge_weight));
        }
    }
    // lambda function to sort weighted_edge_list so we can use Kruskal's algorithm
    sort(weighted_edge_list.begin(),weighted_edge_list.end(),[](pair<pair<int,int>,int > a,pair<pair<int,int>,int> b) {
        return a.second < b.second;
    });

    for (pair<pair<int,int>,int> edge : weighted_edge_list) {
        vector<bool> visited(num_vertices,false);
        if (!(find_path(edge.first.first, edge.first.second, adjmatrix, visited))) {
            mst.push_back(edge.first.first);
            adjmatrix[edge.first.second][edge.first.first] = 1;
            adjmatrix[edge.first.first][edge.first.second] = 1;
            weighted_edge_list.erase(weighted_edge_list.begin());
        }
        weighted_edge_list.erase(weighted_edge_list.begin());
    }
    printf("Vertices in Minimum Spanning Tree: \n");
    for (int vertex : mst) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}
