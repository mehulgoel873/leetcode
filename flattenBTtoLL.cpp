// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *flatten_tail(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    TreeNode *left_tail = flatten_tail(root->left);
    TreeNode *right_tail = flatten_tail(root->right);
    if (left_tail != NULL)
    {
        left_tail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    if (right_tail == NULL && left_tail == NULL)
        return root;
    else if (right_tail == NULL)
        return left_tail;
    else
        return right_tail;
}

void flatten(TreeNode *root)
{
    flatten_tail(root);
    cout << "FINISHED" << "\n";
}

int main()
{
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, NULL, new TreeNode(6)));
    flatten(root);
    return 0;
}