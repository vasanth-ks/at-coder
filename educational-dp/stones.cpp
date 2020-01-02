/*
https://atcoder.jp/contests/dp/tasks/dp_k
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <bool> dp(k + 1);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int stone = 0; stone <= k; ++stone) {
        for (int i : a) {
            if (stone - i >= 0 && !dp[stone - i]) {
                dp[stone] = true;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second") << "\n";
    return 0;
}