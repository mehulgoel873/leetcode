//https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void rotate(vector<int>& nums, int k) {
    int starting = 0;
    int i = 0;
    int len = nums.size();
    int nextVal = nums[0];
    int t = 0;
    for (int c = 0; c < len; c++) {
        t = nums[(i + k)%len];
        nums[(i + k)%len] = nextVal;
        nextVal = t;

        i = (i +k)%len;
        if (i == starting) {
            i++;
            starting = i;
            if (starting != len) nextVal = nums[starting];
        }
        continue;
    }
}

int main() {
    vector<int> nums = {1};
    int k = 0;
    rotate(nums, k);
    for (int n : nums) {
        cout << n << ", ";
    }
    return 0;
}