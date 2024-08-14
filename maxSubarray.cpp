// https://leetcode.com/problems/maximum-subarray/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

int maxSubarray(vector<int> &nums)
{
    int n = nums.size();
    int localMax = 0;
    int globalMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        localMax = max(nums[i], nums[i] + localMax);
        globalMax = max(globalMax, localMax);
    }

    return globalMax;
}

int main()
{
    vector<int> in = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int x = maxSubarray(in);
    return 0;
}