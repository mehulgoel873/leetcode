//https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <unordered_map> 
using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> counts;
    for (char c : t) {
        if (counts.find(c) == counts.end()) {
            counts[c] = 1;
        }
        else {
            counts[c]++;
        }
    }
    return "";
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n";
    return 0;
}