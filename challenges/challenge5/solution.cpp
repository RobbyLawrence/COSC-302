#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;

vector<int> gen_mst(vector<vector<int> > &adjmatrix, vector<int> &mst) {
    // we'll always start at 0, and assume the graph is connected
    // to represent the growing mst, we use a adjlist of pairs of ints
    // the index of the first vector represents the edge FROM
    // the index of the element in the vector represents the edge TO
    // the
}

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);
    int num_vertices;
    fin >> num_vertices;
    // we'll use an adjmatrix and let -1 imply that no edge exists
    vector<vector<int> > adjmatrix(num_vertices,vector<int>(num_vertices,-1));
    int edge_weight;
    for (int i = 0;i<num_vertices;i++) {
        for (int j = 0;j<num_vertices;j++) {
            fin >> edge_weight;
            adjmatrix[i][j] = edge_weight;
        }
    }
    // adjmatrix is constructed now
    vector<int> mst(num_vertices);
    gen_mst(adjmatrix,mst);
}
