// https://leetcode.com/problems/combinations/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

vector<vector<int>> helper(int n, int k, int o)
{
    if (n < k)
        return {};
    if (k == 1)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++)
        {
            vector<int> pair(o, 0);
            pair[k - 1] = i;
            ans.push_back(pair);
        }
        return ans;
    }
    vector<vector<int>> finished = helper(n - 1, k, o);
    vector<vector<int>> unfinished = helper(n - 1, k - 1, o);
    for (int i = 0; i < unfinished.size(); i++)
    {
        unfinished[i][k - 1] = n;
    }
    finished.insert(finished.end(), unfinished.begin(), unfinished.end());
    return finished;
}

vector<vector<int>> combine(int n, int k)
{
    return helper(n, k, k);
}

int main()
{
    vector<vector<int>> res = combine(4, 2);
    return 0;
}