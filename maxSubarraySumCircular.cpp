// https://leetcode.com/problems/maximum-sum-circular-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
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
    vector<int> in = {5, -3, 5};
    int x = maxSubarraySumCircular(in);
    return 0;
}