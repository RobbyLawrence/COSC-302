#include <iostream>
#include <string>
using namespace std;

int time_to_seconds(string mss) {
  string mmss;
  char zero = '0';
  if (mss.length() == 4) { // if the string is in the form m:ss, we need it in mm:ss
    mmss = zero + mss;
  }
  else {
    mmss = mss;
  }
  int minutes = stoi(mmss.substr(0,2));
  int seconds = stoi(mmss.substr(3,2));
  int total_seconds = 60*minutes + seconds;
  return total_seconds;
}

int main(int argc, char* argv[]) {
  cout << "Enter your time: ";
  string time;
  cin >> time;
  int total_seconds = time_to_seconds(time);
  cout << "Number of seconds: " << total_seconds << endl;
  return 0;
}
