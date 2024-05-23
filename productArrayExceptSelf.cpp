//https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len, 1);
    for (int i = 1; i < len; i++) {
        ans[i] = ans[i-1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = len - 2; i >= 0; i--) {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);
    for (int a : ans) {
        cout << a << ", ";
    }
    return 0;
}