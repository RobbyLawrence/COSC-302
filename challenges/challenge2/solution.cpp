#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int num_int;
  cin >> num_int;
  int diff,num;
  vector<int> numbers;
  vector<pair<int,int> > min_diff_pairs;
  int min_diff = INT_MAX;
  for (int i = 0;i<num_int;i++) {
    cin >> num;
    numbers.push_back(num);
  }
  sort(numbers.begin(),numbers.end()); // sort
  for (size_t i = 1;i<numbers.size();i++) { // compare elements next to each other
    diff = abs(numbers[i] - numbers[i - 1]);
    if (diff < min_diff) {
      min_diff_pairs.clear();
      min_diff = diff;
      min_diff_pairs.push_back(make_pair(numbers[i-1],numbers[i]));
    }
    else if (diff == min_diff) {
      min_diff_pairs.push_back(make_pair(numbers[i-1],numbers[i]));
    }
  }
  for (size_t i = 0;i<min_diff_pairs.size();i++) {
    cout << min_diff_pairs[i].first << " " << min_diff_pairs[i].second << '\n';
  }
}
