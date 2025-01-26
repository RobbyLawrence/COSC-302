#include <climits>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int num_int;
  cin >> num_int;
  int diff,num;
  vector<int> numbers;
  vector<pair<int,int> > min_diff_pairs;
  int min_diff = INT_MAX;
  bool val = false;
  for (int i = 0;i<num_int;i++) {
    cin >> num;
    numbers.push_back(num);
  }
  for (int i = 0;i<num_int;i++) {
    for (int j = 0;j<num_int;j++) {
      val = false;
      if (i == j) {
        continue;
      }
      for (size_t k = 0;k<min_diff_pairs.size();k++) {
        if (numbers[i] == min_diff_pairs[k].second && numbers[j] == min_diff_pairs[k].first) {
          val = true;
          break;
        }
      }
      if (val == true) {
        continue;
      }
      diff = abs(numbers[i] - numbers[j]);
      if (diff < min_diff) {
        min_diff_pairs.clear();
        min_diff = diff;
        min_diff_pairs.push_back(make_pair(numbers[i],numbers[j]));
      }
      else if (diff == min_diff) {
        min_diff_pairs.push_back(make_pair(numbers[i],numbers[j]));
      }
    }
  }
  for (size_t i = 0;i<min_diff_pairs.size();i++) {
    cout << min_diff_pairs[i].first << " " << min_diff_pairs[i].second << '\n';
  }
}
