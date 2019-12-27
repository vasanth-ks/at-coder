#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long getMaxDifference (const vector <int> &nums) {
    int n = nums.size();
    vector <vector <long long>> dp(n, vector <long long>(n));

    for (int left = n - 1; left >= 0; --left) {
        for (int right = left; right < n; ++right) {
            if (left == right) {
                dp[left][right] = nums[left];
            } else {
                dp[left][right] = max(nums[left] - dp[left + 1][right],
                                      nums[right] - dp[left][right - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int &i : nums) {
        cin >> i;
    }
    cout << getMaxDifference(nums) << "\n";
    return 0;
}
