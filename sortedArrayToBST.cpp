// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(vector<int>& nums, int left, int right) {
    if (left >= right) return NULL;
    int mid = (left + right)/2;
    return new TreeNode(nums[mid], helper(nums, left, mid), helper(nums, mid+1, right));
}

TreeNode* sortedArrayToBST(vector<int> nums) {
    return helper(nums, 0, nums.size());    
}

int main() {
    TreeNode* ans = NULL;
    vector<int> input = {-10, -3, 0, 5, 9};
    ans = sortedArrayToBST(input);
    return 0;
}