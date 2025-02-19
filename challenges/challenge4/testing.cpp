#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num_edges;
  char src_char, dest_char;
  int src, dest;
  cin >> num_edges;
  for (int i = 0;i<num_edges;i++) {
    cin >> src_char >> dest_char;
    src = src_char - 'A'; // makes 'A' to 0, 'B'
    dest = dest_char - 'A';
  }
}
