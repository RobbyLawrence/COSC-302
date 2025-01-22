// Challenge 01: Rotating Arrays; null solution
// Name: Robby Lawrence
// Description: accepts input of arrays, then performs rotations and outputs

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vect;
    size_t num_values,num_rotations,current_val;
    char direction;
    // first we collect the data from the input
    while(cin >> num_values >> num_rotations >> direction) {
      num_rotations %= num_values;
      for(size_t i = 0;i<num_values;i++) {
        cin >> current_val;
        vect.push_back(current_val);
      }
      // vector is now ready for rotation
      // we're going to calculate the offset and store the vector
      vector<int> placeholder = vect;
      if (direction == 'L') {
        for (size_t i = 0;i<vect.size();i++) {
          vect[(i + vect.size() - num_rotations) % vect.size()] = placeholder[i];
        }
      }
      else if (direction == 'R') {
        for (size_t i = 0;i<vect.size();i++) {
          vect[(i + num_rotations) % vect.size()] = placeholder[i];
        }
      }
      // output and cleanup
      for (size_t i = 0;i<vect.size() - 1;i++) {
        cout << vect[i] << " ";
      }
      cout << vect[vect.size() - 1] << endl;
      vect.clear();
    }
    return 0;
}
