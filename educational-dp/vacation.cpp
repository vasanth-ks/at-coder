/*
https://atcoder.jp/contests/dp/tasks/dp_c
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMaxScore (vector <vector <int>> & scores) {
    if (scores.empty()) {
        return 0;
    }
    int n = scores.size();
    vector <int> curr(3), prev = scores[0];

    for (int i = 1; i < n; ++i) {
        curr[0] = max(prev[1] + scores[i][0], prev[2] + scores[i][0]);
        curr[1] = max(prev[0] + scores[i][1], prev[2] + scores[i][1]);
        curr[2] = max(prev[0] + scores[i][2], prev[1] + scores[i][2]);
        prev = curr;
    }
    return *max_element(prev.begin(), prev.end());
}

int  main () {
    int n = 0;
    scanf("%d", &n);
    vector <vector <int>> scores(n, vector <int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &scores[i][j]);
        }
    }
    printf("%d", getMaxScore(scores));
    return 0;
}