// https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

vector<vector<int>> permHelper(vector<int> &nums, unordered_set<int> &used)
{
    if (nums.size() == used.size())
        return {{}};
    vector<vector<int>> ans;
    for (int n : nums)
    {
        if (used.find(n) != used.end())
            continue;
        used.insert(n);
        vector<vector<int>> a = permHelper(nums, used);
        for (vector<int> res : a)
        {
            res.push_back(n);
            ans.push_back(res);
        }
        used.erase(n);
    }
    return ans;
}

vector<vector<int>> permute(vector<int> &nums)
{
    unordered_set<int> n;
    return permHelper(nums, n);
}

int main()
{
    vector<int> in = {1, 2, 3};
    vector<vector<int>> ans = permute(in);
    return 0;
}