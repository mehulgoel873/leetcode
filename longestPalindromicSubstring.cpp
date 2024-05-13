// https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

string longestPalindrome(string s) {
    int maxLength = 0;
    string sub = "";

    for (int i = 0; i < size(s); i++) {
        for (int len = 0; (i + len) < size(s) && (i - len) >= 0; len++) {
            if (s[i + len] != s[i - len]) {
                break;
            }
            if (2 * len + 1 > maxLength) {
                maxLength = 2 * len + 1;
                sub = s.substr(i - len, 2 * len + 1);
            }
        }

        for (int len = 0; (i + len + 1) < size(s) && (i - len) >= 0; len++) {
            if (s[i + len + 1] != s[i - len]) {
                break;
            }
            if (2 * len + 2 > maxLength) {
                maxLength = 2 * len + 2;
                sub = s.substr(i - len, 2 * len + 2);
            }
        }
    }
    return sub;
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s);
    return 0;
}
