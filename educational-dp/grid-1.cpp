/*
https://atcoder.jp/contests/dp/tasks/dp_h
*/
#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int dfs (const vector <vector <char>> &grid, int row, int col,
         vector <vector <int>> &ways) {
    if (row == grid.size() - 1 && col == grid[0].size() - 1) {
        return 1;
    }
    if (row >= grid.size() || col >= grid[row].size() || grid[row][col] == '#') {
        return 0;
    }

    if (ways[row][col] >= 0) {
        return ways[row][col];
    }
    unsigned long count = 0;
    for (const pair <int, int> &next : initializer_list <pair <int, int>> 
                                            {{row + 1, col}, {row, col + 1}}) {
        int r = next.first, c = next.second;
        count = ((count % mod) + (dfs(grid, r, c, ways) % mod));
    }
    ways[row][col] = count % mod;
    return ways[row][col];
}

int getNumWays (const vector <vector <char>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector <vector <int>> ways(rows, vector <int>(cols));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (r == 0 && c == 0) {
                ways[r][c] = 1;
            } else {
                if (grid[r][c] == '.') {
                    int topRow = r == 0 ? 0 : ways[r - 1][c];
                    int leftCol = c == 0 ? 0 : ways[r][c - 1];
                    ways[r][c] = (topRow + leftCol) % mod;
                }
            }
        }
    }
    return ways[rows - 1][cols - 1];
}

int  main () {
    int rows, cols;
    cin >> rows >> cols;
    vector <vector <char>> grid(rows, vector <char>(cols, '.'));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            char ch;
            cin >> ch;
            grid[r][c] = ch;
        }
    }
    vector <vector <int>> ways(rows, vector <int>(cols, -1));
    int result = dfs(grid, 0, 0, ways);
    cout << result << "\n";
    result = getNumWays(grid);
    cout << result << "\n";
    return 0;
}
