/*
https://atcoder.jp/contests/dp/tasks/dp_b
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMinCost (vector <int> &heights, int k) {
    int n = heights.size();
    if (n <= 1) {
        return 0;
    }
    vector <int> dp(n, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = max(0, i - k); j < i; ++j) {
            int cost = abs(heights[i] - heights[j]);
            dp[i] = min(dp[i], cost + dp[j]);
        }
    }
    return dp.back();
}

int  main () {
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    vector <int> heights(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &heights[i]);
    }
    printf("%d\n", getMinCost(heights, k));
    return 0;
}