// Name: Robby Lawrence
// Student ID: 000691931
// NetID: rlawren9
// Description: takes in lines of integers and returns the smallest difference between them
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int num_int;
  int diff,num;
  vector<int> numbers;
  vector<pair<int,int> > min_diff_pairs;
  int min_diff = INT_MAX; // INT_MAX ensures that ANY difference between two integers will take the new value
  while (cin >> num_int) {
    for (int i = 0;i<num_int;i++) {
      cin >> num;
      numbers.push_back(num);
    }
    sort(numbers.begin(),numbers.end()); // sort
    for (size_t i = 1;i<numbers.size();i++) { // compare elements next to each other
      diff = abs(numbers[i] - numbers[i - 1]);
      if (diff < min_diff) {
        min_diff_pairs.clear(); // reset the vector and min_diff
        min_diff = diff;
        min_diff_pairs.push_back(make_pair(numbers[i-1],numbers[i])); // add the new pair to the vector
      }
      else if (diff == min_diff) { // if the difference is the same as the current min_diff, add to vector
        min_diff_pairs.push_back(make_pair(numbers[i-1],numbers[i]));
      }
    }
    cout << min_diff_pairs[0].first << " " << min_diff_pairs[0].second; // output; if there's more than one element in the pair vector, output all of them
    if (min_diff_pairs.size() > 1) {
      for (size_t i = 1;i<min_diff_pairs.size();i++) {
        cout << " " << min_diff_pairs[i].first << " " << min_diff_pairs[i].second;
      }
    }
    cout << '\n';
    numbers.clear();
    min_diff = INT_MAX;
    min_diff_pairs.clear();
  }
}
