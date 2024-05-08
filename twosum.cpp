#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    set<int> s(nums.begin(), nums.end());

    vector<int> resNums;
    for (int x : s) {
        if (s.count(target - x) > 0) {
            resNums = {x, target - x};
        }
    }

    int first = -100;
    int second = -200;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == resNums[0] && first == -100) {
            first = i;
        }
        else if (nums[i] == resNums[1] && second == -200) {
            second = i;
        }
    }

    // Your implementation of the twoSum function goes here

    return {first, second};
}



int main()
{
    vector<int> nums = {3, 3};
    int target = 6; // Example target value

    vector<int> indices = twoSum(nums, target);

    // Output the result
    cout << "Indices of the two numbers: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
