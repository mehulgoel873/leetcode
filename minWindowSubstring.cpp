//https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map> 
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> counts;
    unordered_set<char> need;
    for (char c : t) {
        if (counts.find(c) == counts.end()) {
            counts[c] = 1;
        }
        else {
            counts[c]++;
        }
        need.insert(c);
    }
    
    int l = 0;
    int r = 0;
    unordered_map<char, int> surp;
    while (!counts.empty()) {
        if (r >= s.size()) {
            return "";
        }
        if (counts.find(s[r]) != counts.end()) {
            if (counts[s[r]] == 1) {
                counts.erase(s[r]);
            }
            else counts[s[r]]--;
        }
        else if (need.find(s[r]) != need.end()) {
            surp[s[r]]++;
        }
        r++;
    }
    

    int len = r - l;
    int start = l;
    while (r <= s.size()) {
        if (need.find(s[l]) == need.end()) {
            l++;
        }
        else if (surp[s[l]] > 0) {
            surp[s[l]]--;
            l++;
        }
        else {
            while (r < s.size() && s[l] != s[r]) {
                if (need.find(s[r]) != need.end()) {
                    surp[s[r]]++;
                }
                r++;
            }
            if (r == s.size()) {
                return s.substr(start, len);
            }
            r++;
            l++;

        }
        if (r - l < len) {
            len = r - l;
            start = l;
        }
    }

    return s.substr(start, len);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n";
    return 0;
}