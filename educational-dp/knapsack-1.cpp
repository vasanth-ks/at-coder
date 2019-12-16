/*
https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Knapsack {
    int weight, value;
    Knapsack () : weight(-1) , value(-1) {}
    Knapsack (int w, int v) : weight(w), value(v) {}
};

long long getMaxValue (vector <Knapsack> &knapsack, int capacity) {
    if (knapsack.empty()) {
        return 0;
    }
    int n = knapsack.size();
    vector <long long> dp(capacity + 1);
    
    for (int i = 0; i < n; ++i) {
        int currWeight = knapsack[i].weight;
        int currValue = knapsack[i].value;
        vector <long long> curr(capacity + 1);
        for (int c = 1; c <= capacity; ++c) {
            if (c >= currWeight) {
                curr[c] = max(dp[c - currWeight] + currValue, dp[c]);
            } else {
                curr[c] = dp[c];
            }
        }
        dp = curr;
    }
    return dp.back();
}

int  main () {
    int n = 0, capacity = 0;
    scanf("%d%d", &n, &capacity);
    vector <Knapsack> knapsack;
    for (int i = 0; i < n; ++i) {
        int w, v;
        scanf("%d%d", &w, &v);
        knapsack.emplace_back(Knapsack{w, v});
    }
    printf("%llu\n", getMaxValue(knapsack, capacity));
    return 0;
}