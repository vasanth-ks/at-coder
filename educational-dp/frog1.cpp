#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMinCost (vector <int> &heights) {
    int n = heights.size();
    if (n <= 1) {
        return 0;
    }
    vector <int> dp(n);

    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 2] + abs(heights[i - 2] - heights[i]), dp[i - 1] + abs(heights[i - 1] - heights[i]));
    }
    return dp.back();
}

int  main () {
    int n = 0;
    scanf("%d", &n);
    vector <int> heights(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &heights[i]);
    }
    printf("%d\n", getMinCost(heights));
    return 0;
}