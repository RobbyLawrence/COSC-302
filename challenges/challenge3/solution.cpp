#include <iostream>
#include <unordered_map>
#include <vector>
#include <cctype>
using namespace std;

unordered_map<char,int> make_letter_map(string word) {
  unordered_map<char,int> map;
  for (size_t i = 0;i<word.length();i++) {
    if (isalpha(word[i])) {
      map[word[i]]++;
    }
  }
  return map;
}

bool is_palindrome_perm(string word) {
  unordered_map<char,int> map = make_letter_map(word);
  if (word.length() % 2 == 0) {
    for (unordered_map<char,int>::iterator it = map.begin();it != map.end();it++) {
      if (it->second % 2 != 0) {
        return false;
      }
    }
    return true;
  }
  else {
    int num_bad_letters = 0;
    for (unordered_map<char,int>::iterator it = map.begin();it != map.end();it++) {
      if (it->second % 2 != 0) {
        num_bad_letters++;
      }
      if (num_bad_letters > 1) {
        return false;
      }
    }
    if (num_bad_letters != 1) {
      return false;
    }
    return true;
  }
}
int main() {
  string word;
  vector<string> words;
  while (getline(cin,word)) {
    words.push_back(word);
  }
  for (string word : words) {
  bool val = is_palindrome_perm(word);
  if (val) {
    cout << '"' << word << '"' << " is a palindrome permutation" << '\n';
  }
  else {
    cout << '"' << word << '"' << " is not a palindrome permutation" << '\n';
  }
  }
  return 0;
}
