// Name: Robby Lawrence
// Student ID: 000691931
// NetID: rlawren9
// Description: determines whether or not a string is a palindrome permutation
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>
using namespace std;

string clean(string word) {
    string result = "";
    for (char letter : word) {
        if (isalpha(letter)) {
            result += tolower(letter);
        }
    }
    return result;
}

unordered_map<char, int> make_letter_map(string word) {
    unordered_map<char, int> map;
    for (char letter : word) {
        map[letter]++;
    }
    return map;
}

bool is_palindrome_perm(string word) {
    word = clean(word); // remove spaces and turn capital letters into lowercase versions
    unordered_map<char, int> map = make_letter_map(word);

    if (word.length() % 2 == 0) {
        for (unordered_map<char,int>::iterator it = map.begin();it != map.end();it++) {
            if (it->second % 2 != 0) {
                return false;
            }
        }
        return true;
    } else {
        int num_bad_letters = 0;
        for (unordered_map<char,int>::iterator it = map.begin();it != map.end();it++) {
            if (it->second % 2 != 0) {
                num_bad_letters++;
            }
            if (num_bad_letters > 1) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    string word;
    vector<string> words;
    while (getline(cin, word)) {
        words.push_back(word);
    }
    for (const string& w : words) {
        bool val = is_palindrome_perm(w);
        if (val) {
            cout << '"' << w << '"' << " is a palindrome permutation" << '\n';
        } else {
            cout << '"' << w << '"' << " is not a palindrome permutation" << '\n';
        }
    }
    return 0;
}
