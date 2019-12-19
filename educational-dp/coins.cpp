/*
https://atcoder.jp/contests/dp/tasks/dp_i
*/
#include <iostream>
#include <vector>
using namespace std;

double getProbability (const vector <double> &p) {
    int n = p.size();
    vector <double> dp(n + 1);
    dp[0] = 1;
    /* dp[i] - probability of having i heads */
    for (int i = 1; i <= n; ++i) {
        vector <double> curr(n + 1);
        for (int j = 0; j <= i; ++j) {
            /* There can be 0 <= j <= n heads */
            if (j > 0) {
                curr[j] += dp[j - 1] * p[i - 1];
            }
            curr[j] += dp[j] * (1 - p[i - 1]);
        }
        dp = curr;
    }
    double result = 0;
    for (int heads = 0; heads <= n; ++heads) {
        int tails = n - heads;
        if (heads > tails) {
            result += dp[heads];
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector <double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    double result = getProbability(p);
    printf("%.10f\n", result);
    return 0;
}