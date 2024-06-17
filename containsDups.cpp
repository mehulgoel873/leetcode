//https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map> 
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]].push_back(i);
    }
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        vector<int> arr = iter->second;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (abs(arr[i] - arr[i+1]) <= k) return true;
        }
    }
    return false;
}

int main() {
    cout << containsNearbyDuplicate({1, 2, 3, 1}, 3) << "\n";
    return 0;
}