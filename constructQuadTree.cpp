// https://leetcode.com/problems/construct-quad-tree/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *helper(vector<vector<int>> &grid, int topRow, int topCol, int botRow, int botCol)
{
    bool isLeaf = true;
    int val = grid[topRow][topCol];
    for (int r = topRow; r <= botRow; r++)
    {
        for (int c = topCol; c <= botCol; c++)
        {
            if (val != grid[r][c])
            {
                isLeaf = false;
                break;
            }
        }
        if (!isLeaf)
            break;
    }

    if (isLeaf)
    {
        return new Node(val == 1, isLeaf);
    }

    int mR = (topRow + botRow) / 2;
    int mC = (topCol + botCol) / 2;
    return new Node(false, false, helper(grid, topRow, topCol, mR, mC), helper(grid, topRow, mC + 1, mR, botCol), helper(grid, mR + 1, topCol, botRow, mC), helper(grid, mR + 1, mC + 1, botRow, botCol));
}

Node *construct(vector<vector<int>> &grid)
{
    int n = grid.size();
    return helper(grid, 0, 0, n - 1, n - 1);
}

int main()
{
    vector<vector<int>> in = {{0, 1}, {1, 0}};
    Node *ans = construct(in);
    return 0;
}