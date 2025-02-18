// Challenge 04: Graph Paths
// Name: Robby Lawrence
// NetID: rlawren9
// StudentID: 000691931
// Description: This program finds if a path exists between two vertices in a directed graph.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// normal BFS to exhaust all viable edges in connected component
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

int main() {
  int graph_counter = 1;
  int num_edges, num_paths;
  char source_char, destination_char;

  while (cin >> num_edges) {
      if (graph_counter > 1) {
        cout << endl;
      }
      vector<pair<int, int>> edges;
      int max_vertex = -1;

      // find the number of vertices
      for (int i = 0; i < num_edges; ++i) {
          cin >> source_char >> destination_char;
          int source = source_char - 'A';
          int destination = destination_char - 'A';
          edges.push_back(make_pair(source, destination)); // store edges in pair vect
          max_vertex = max({max_vertex, source, destination});
        }
        int num_vertices = max_vertex + 1;
        vector<vector<int>> adjmatrix(num_vertices, vector<int>(num_vertices, 0));
        // make an adjacency matrix
        for (pair<int,int> edge : edges) {
            int s = edge.first;
            int d = edge.second;
            if (s < num_vertices && d < num_vertices) {
                adjmatrix[s][d] = 1;
            }
        }
        cin >> num_paths;
        for (int i = 0; i < num_paths; ++i) {
            cin >> source_char >> destination_char;
            int source = source_char - 'A';
            int destination = destination_char - 'A';

            // error checking
            if (source < 0 || source >= num_vertices || destination < 0 || destination >= num_vertices) {
                cout << "In Graph " << graph_counter << " there is no path from " << source_char << " to " << destination_char << endl;
                continue;
            }
            vector<bool> visited(num_vertices, false);
            if (find_path(source, destination, adjmatrix, visited)) {
                cout << "In Graph " << graph_counter << " there is a path from " << source_char << " to " << destination_char << endl;
            } else {
                cout << "In Graph " << graph_counter << " there is no path from " << source_char << " to " << destination_char << endl;
            }
        }

        graph_counter++;
  }
  return 0;
}
