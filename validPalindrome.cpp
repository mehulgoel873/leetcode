//https://leetcode.com/problems/valid-palindrome/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
using namespace std;

bool isPalindrome(string s) {
    string sFiltered = "";
    for (char c : s) {
        if (iswalnum(c)) {
            sFiltered += (char)tolower(c);
        }
    }
    cout << sFiltered << "\n";
    s = sFiltered;
    int start = 0;
    int end = s.size() - 1;
    while (start <= end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    string s = " ";
    cout << (bool) isPalindrome(s) << "\n";
    return 0;
}