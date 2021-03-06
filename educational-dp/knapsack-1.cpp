/*
https://atcoder.jp/contests/dp/tasks/dp_d
*/
#include <iostream>
#include <vector>

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
        for (int c = capacity; c >= currWeight; --c) {
            dp[c] = max(dp[c], dp[c - currWeight] + (long long)currValue);
        }
    }
    long long result = 0;
    for (long long v : dp) {
        result = max(result, v);
    }
    return result;
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