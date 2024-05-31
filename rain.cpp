//https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>

using namespace std;

int trap(vector<int>& height) {
    int len = height.size();
    stack<int> maxHeights;
    maxHeights.push(-1);

    int maxHeight = -1;
    for (int i  = len - 1; i>= 0; i--) {
        if (height[i] >= maxHeight) {
            maxHeights.push(height[i]);
            maxHeight = height[i];
        }
    }
    
    int totWater = 0;
    int leftMax = -1;
    for (int i = 0; i < len; i++) {
        totWater += max(0, min(leftMax, maxHeights.top()) - height[i]);
        leftMax = max(leftMax, height[i]);
        if (height[i] == maxHeights.top()) {
            maxHeights.pop();
        }
    }

    return totWater;
}

int main() {
    vector<int> height = {4,2,0,3,2,5};
    cout << trap(height) << "\n";
    return 0;
}