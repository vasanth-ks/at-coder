#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const long long INF = 1e18L + 7;

struct Knapsack {
    int weight, value;
    Knapsack () : weight(-1) , value(-1) {}
    Knapsack (int w, int v) : weight(w), value(v) {}
};

long long getMaxValue (vector <Knapsack> &knapsack, int capacity) {
    if (knapsack.empty()) {
        return 0;
    }
    int n = knapsack.size(), totalValue = 0;

    for (auto &k : knapsack) {
        totalValue += k.value;
    }
    vector <long long> dp(totalValue + 1, INF);
    dp[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        int currWeight = knapsack[i].weight;
        int currValue = knapsack[i].value;
        for (int v = totalValue; v >= currValue; --v) {
            dp[v] = min(dp[v], dp[v - currValue] + currWeight);
        }
    }
    long long result = 0;

    for (long long v = 0; v <= totalValue; ++v) {
        if (dp[v] <= capacity) {
            result = max(result, v);
        }
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