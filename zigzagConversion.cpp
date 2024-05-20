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
            ret[i] = s[2 * i];
            ret[i + (len + 1)/2] = s[2 * i + 1];
        }
        if (len % 2 == 1) ret[len/2] = s[len - 1];
        return ret;
    }
    else {
        int zigZagLen = (numRows * 2) - 2;
        int zigZags = len/zigZagLen;
        int leftOverZig = len % zigZagLen;

        std::string res(len, '_');
        
        int row = 0;
        int z = 0;
        bool first = true;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (row == 0 || row == numRows - 1) {
                if (z < zigZags) {
                    res[i] = s[z * zigZagLen + row];
                    z++;
                }
                else if (z == zigZags && leftOverZig != 0) {
                    res[i] = s[z * zigZagLen + row];
                    leftOverZig--;
                    z++;
                }
                else {
                    row++;
                    z = 0;
                    i--;
                }
            }
            else {
                if (z < zigZags) {
                    if (first) {
                        res[i] = s[z * zigZagLen + row];
                        first = false;
                    }
                    else {
                        res[i] = s[z*zigZagLen + (zigZagLen - row)];
                        z++;
                        first = true;
                    }
                }
                else if (z == zigZags && leftOverZig != 0) {
                    res[i] = s[z * zigZagLen + row];
                    leftOverZig--;
                    if (leftOverZig > (2 * (numRows - row - 1)) - 1) {
                        i++;
                        res[i] = s[z * zigZagLen + (zigZagLen - row)];
                        leftOverZig--;
                    }
                    z++;
                }
                else {
                    row++;
                    z = 0;
                    i--;
                    first = true;
                }
            }
        }
        return res;
    }

}

int main() {
    string s = "ABCDE";
    int numRows = 4;
    cout << convert(s, numRows);
    return 0;
}