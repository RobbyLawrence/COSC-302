#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool is_palindrome(string word) {
  unordered_map<char,int> char_occur;
  unordered_map<char,int>::iterator it;
  // this creates a map that represents how many times each letter shows up in the word
  for (size_t i = 0;i<word.length();i++) {
    it = char_occur.find(word[i]);
    if (it == char_occur.end()) {
      char_occur.insert(make_pair(word[i],1));
    }
    else {
      it->second++;
    }
  }
  int num_bad_letters = 0;
  if (word.length() % 2 == 0) {
    for (unordered_map<char,int>::iterator it = char_occur.begin();it!=char_occur.end();it++) {
      if (it->second % 2 == 1) {
        return false;
      }
    }
    return true;
  }
  else {
    for (unordered_map<char,int>::iterator it = char_occur.begin();it!=char_occur.end();it++) {
      if (it->second % 2 == 1) {
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
  while(cin >> word) {
    words.push_back(word);
  }
  for (string word : words) {
    if (is_palindrome(word)) {
      cout << '"' << word << '"' << " is a palindrome permutation";
    }
    else {
      cout << '"' << word << '"' << " is not a palindrome permutation";
    }
  }
}
