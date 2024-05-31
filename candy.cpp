//https://leetcode.com/problems/candy/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int candy (vector<int> ratings) {
    int len = ratings.size();
    vector<int> candy(len, 0);
    for (int i = 1; i < len; i++) {
        if (ratings[i] > ratings[i-1]) {
            candy[i] = candy[i-1] + 1;
        }
    }

    int rightCount = 0;
    for (int i = len - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
            rightCount++;
            candy[i] = max(rightCount, candy[i]);
        }
        else {
            rightCount = 0;
        }
    }

    int tot = 0;
    for (int i = 0; i < len; i++) {
        tot += candy[i] + 1;
    }
    return tot;  
}

int main() {
    vector<int> ratings = {1, 2, 2};

    cout << candy(ratings) << "\n";
    return 0;
}

