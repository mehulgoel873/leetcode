//https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int canCompleteCircuit(vector<int>&gas, vector<int>& cost) {
    int len = gas.size();
    for (int i = 0; i < len; i++) {
        gas[i] -= cost[i];
    }

    for (int g : gas) {
        cout << g << ", ";
    }
    cout << "\n";

    int ix = 0;
    int tot = 0;
    int start = 0;
    for (int totalCounted = 0; totalCounted <= len; totalCounted++) {
        if (ix == len) ix = 0;
        tot += gas[ix];
        if (tot < 0) {
            if (ix < start) return -1;
            ix++;
            cout << start << "\n";
            start = ix;
            totalCounted = -1;
            tot = 0;
        }
        else {
            ix++;
        }
    }
    cout << "\n\n";
    return start;
}

int main() {
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    cout << canCompleteCircuit(gas, cost) << "\n"; 
    return 0;
}