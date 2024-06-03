//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>

using namespace std;

int strStr(string haystack, string needle) {
    int hI = 0;
    while (hI < haystack.size()) {
        for (int j = 0; j <= needle.size(); j++) {
            if (j == needle.size()) return hI;
            if (hI + j >= haystack.size()) return -1;
            if (haystack[hI + j] != needle[j]) {
                break;
            }
        }
        hI++;
    }
    return -1;
}

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << strStr(haystack, needle) << "\n";
    return 0;
}