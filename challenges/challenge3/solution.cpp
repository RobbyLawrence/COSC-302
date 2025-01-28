#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>

using namespace std;

// Function to check if a string is a palindrome permutation
bool is_palindrome(const string &word) {
    unordered_map<char, int> char_count;

    // Count the frequency of each character (ignoring non-alphabetic characters)
    for (size_t i = 0;i<word.length()) {
        if (isalpha(ch)) {
            char_count[tolower(ch)]++;
        }
    }

    // Check the number of characters with odd counts
    int odd_count = 0;
    for (const auto& pair : char_count) {
        if (pair.second % 2 != 0) {
            odd_count++;
        }
    }

    // A string can be rearranged into a palindrome if at most one character has an odd count
    return odd_count <= 1;
}

int main() {
    string phrase;
    while (getline(cin, phrase)) {
        if (is_palindrome(phrase)) {
            cout << "\"" << phrase << "\" is a palindrome permutation" << endl;
        } else {
            cout << "\"" << phrase << "\" is not a palindrome permutation" << endl;
        }
    }
    return 0;
}
