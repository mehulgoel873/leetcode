// https://leetcode.com/problems/median-of-two-sorted-arrays/ 

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int l1 = size(nums1);
    int l2 = size(nums2);
    int i1 = 0;
    int i2 = 0;
    int i = 0;

    vector<int> combined(l1 + l2, 0);
    while (i1 != l1 || i2 != l2) {
        if (i1 == l1) {
            combined[i++] = nums2[i2++];
        }
        else if (i2 == l2) {
            combined[i++] = nums1[i1++];
        }
        else if (nums1[i1] > nums2[i2]) {
            combined[i++] = nums2[i2++];
        }
        else {
            combined[i++] = nums1[i1++];
        }
    }

    int l = l1 + l2;
    if (l % 2 == 0) {
        int mid1 = combined[l / 2 - 1];
        int mid2 = combined[l / 2];
        return (mid1 + mid2) / 2.0;
    }
    else {
        return combined[l / 2];
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}
