/*
https://atcoder.jp/contests/dp/tasks/dp_f
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string buildSequence (const string &str1, const vector <vector <int>> &dp) {
    int r = dp.size() - 1, c = dp[0].size() - 1;
    string result;
    while (r > 0 && c > 0) {
        if (dp[r][c] != dp[r - 1][c]) {
            result += str1[r - 1];
            --r;
            --c;
        } else {
            if (dp[r - 1][c] > dp[r][c - 1]) {
                --r;
            } else {
                --c;
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

string getLCS (const string &str1, const string &str2) {
    int rows = str1.size(), cols = str2.size();

    vector <vector <int>> dp(rows + 1, vector <int>(cols + 1));

    for (int r = 1; r <= rows; ++r) {
        for (int c = 1; c <= cols; ++c) {
            if (str1[r - 1] == str2[c - 1]) {
                dp[r][c] = 1 + dp[r - 1][c - 1];
            } else {
                dp[r][c] = max(dp[r - 1][c], dp[r][c - 1]);
            }
        }
    }
    return buildSequence(str1, dp);
}

int  main () {
    string s, t;
    cin >> s >> t;
    cout << getLCS(s, t) << "\n";
    return 0;
}