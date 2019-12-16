/*
https://atcoder.jp/contests/dp/tasks/dp_g
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dfs (const vector <vector <int>> &graph, int node, vector <int> &length,
         vector <bool> &visited) {
    if (visited[node]) {
        return length[node];
    }

    int len = 0;
    visited[node] = true;

    for (auto &neighbor : graph[node]) {
        len = max(len, 1 + dfs(graph, neighbor, length, visited));
    }
    length[node] = len;
    return length[node];
}

int getLongestPath (const vector <vector <int>> &graph) {
    int n = graph.size();
    vector <int> maxlength(n);
    vector <bool> visited(n);
    
    for (int i = 1; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        dfs(graph, i, maxlength, visited);
    }
    return *max_element(maxlength.begin(), maxlength.end());
}


int  main () {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> graph(n + 1, vector <int>());

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
    }
    cout << getLongestPath(graph) << "\n";
    return 0;
}