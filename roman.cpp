//https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>

using namespace std;

int romanToInt(string s) {
    int count = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == 'I') {
            if (i < len - 1 && s[i + 1] == 'V') {
                count += 4;
                i++; 
            }
            else if (i < len - 1 && s[i + 1] == 'X') {
                count += 9;
                i++; 
            }
            else {
                count++;
            }
        }
        else if (c == 'V') {
            count += 5;
        }
        else if (c == 'X') {
            if (i < len - 1 && s[i + 1] == 'L') {
                count += 40;
                i++; 
            }
            else if (i < len - 1 && s[i + 1] == 'C') {
                count += 90;
                i++; 
            }
            else {
                count += 10;
            }
        }
        else if (c == 'L') {
            count += 50;
        }
        else if (c == 'C') {
            if (i < len - 1 && s[i + 1] == 'D') {
                count += 400;
                i++; 
            }
            else if (i < len - 1 && s[i + 1] == 'M') {
                count += 900;
                i++; 
            }
            else {
                count += 100;
            }
        }
        else if (c == 'D') {
            count += 500;
        }
        else if (c == 'M') {
            count += 1000;
        }
    }
    return count;
}

int main() {
    string s ="MCMXCIV";
    cout << romanToInt(s) << "\n";
    return 0;
}