// Name: Robby Lawrence
// NetID: rlawren9
// Student ID: 000691931
// Description: program reads in DNA strings and
// outputs repeated substrings
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    string dna;
    map<string,int> substr_map; // chose to use map over unordered_map bc it would need to be sorted
    while (cin >> dna) {
        if (dna.length() < 9) {
            cout << -1 << '\n';
            continue;
        }
        for (size_t i = 0;i <= dna.size() - 9;i++) {
            string substring = dna.substr(i,9);
            map<string,int>::iterator it = substr_map.find(substring);
            if (it == substr_map.end()) {
                substr_map.insert(make_pair(substring,1)); // place substring in unordered map
            }
            else {
                it->second++; // increment the number of occurences
            }
        }
        // just check each element and output the repeated ones
        vector<string> elements;
        for (pair<string,int> element : substr_map) {
            if (element.second > 1) {
                cout << element.first << '\n';
            }
        }
        cout << -1 << '\n';
        substr_map.clear();
    }
    return 0;
}
