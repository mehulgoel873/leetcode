//https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> n1(m, 0);
    for (int i = 0; i < m; i++) {
        n1[i] = nums1[i];
    }

    int ni = 0;
    int mi = 0;
    int i = 0;
    while (ni < n && mi < m) {
        if (n1[mi] < nums2[ni]) {
            nums1[i++] = n1[mi++];
        }
        else {
            nums1[i++] = nums2[ni++];
        }
    }
    while (ni < n) {
        nums1[i++] = nums2[ni++];
    }
    while (mi < m) {
        nums1[i++] = n1[mi++];
    }
}

int main() {
    vector<int> nums1 = {1,2,3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    merge(nums1, 3, nums2, 3);
    for (int n : nums1)  cout << n << ", ";

    return 0;
}