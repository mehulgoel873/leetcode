// https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

string convert(string s, int numRows) {
    int len = size(s); 
    if (numRows == 1) {
        return s;
    }
    else if (numRows == 2) {
        string ret = s;
        for (int i = 0; i < len/2; i++) {
            ret[2 * i] = s[i];
            ret[2 * i + 1] = s[i + (len + 1)/2];
        }
        ret[len - 1] = s[len/2];
        return ret;
    }
    else {
        int zigZagLen = (numRows * 2) - 2;
        int zigZags = len/zigZagLen;

        string ret = s;
        for (int z = 0; z < zigZags; z++) {
            for (int i = 0; i < zigZagLen && z * zigZagLen + i < len; i++) {
                if (i == 0) {
                    ret[z * zigZagLen] = s[z];
                }
                else if (i == numRows) {
                    ret[z * zigZagLen + i] = s[]
                }
            }
        }
    }
    return "";

}

int main() {
    string s = "PYASAPL";
    int numRows = 2;
    cout << convert(s, numRows);
    return 0;
}