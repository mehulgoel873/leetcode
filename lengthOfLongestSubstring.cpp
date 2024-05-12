// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int length = 0;
    vector<int> counts(256, 0);
    for (char c : s) {
        if (counts[(int) c] != 0 ) {
            int count = counts[(int) c];
            for (int i = 0; i < 256; i++) {
                if (counts[i] >= count) {
                    length = max(length, counts[i]);
                    counts[i] = 0;
                }
                else if (counts[i] != 0) counts[i]++;
            }
            counts[(int) c]++;
        }
        else {
            counts[(int) c]++;
            for (int i = 0; i < 256; i++) {
                if (counts[i] != 0) counts[i]++;
            }
            counts[(int) c]--;
        }
    }
    for (int i = 0; i < 256; i++) {
        length = max(length, counts[i]);
    }
    return length;
}



int main()
{
    string s = " ";
    // Output the result
    cout << "Largest substring: " << lengthOfLongestSubstring(s);

    return 0;
}
