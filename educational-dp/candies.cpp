/*
https://atcoder.jp/contests/dp/tasks/dp_m
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int modAdd (int a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
	return a;
}
int modSub (int a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
	return a;
}
template <class T>
void display (const vector <T> &arr) {
	for (T a : arr) {
		cout << a << " ";
	}
	cout << endl;
	return;
}

int getNumWays (const vector <int> &candies, int k) {
	int n = candies.size();
	vector <int> dp(k + 1);
	dp[0] = 1;
	// dp[i] - Total number of ways if i candies are used
	
	for (int i = 0; i < n; ++i) {
		vector <int> prefixSum(k + 1);
		for (int used = k; used >= 0; --used) {
			int minCandies = used + 1;
			int maxCandies = used + min(candies[i], k - used);
			// for (int j = minCandies; j <= maxCandies; ++j) {
			// 	dp[j] = (dp[j] + dp[used]) % mod;
			// }
			if (minCandies <= maxCandies) {
				prefixSum[minCandies] = modAdd(prefixSum[minCandies], dp[used]);
				if (maxCandies + 1 <= k) {
					prefixSum[maxCandies + 1] = modSub(prefixSum[maxCandies + 1], dp[used]);
				}
			}
		}
		int prefix = 0;
		for (int j = 0; j <= k; ++j) {
			prefix = modAdd(prefix, prefixSum[j]);
			dp[j] = modAdd(dp[j], prefix);
		}
	}
	return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> candies(n);
    for (int &c : candies) {
    	cin >> c;
    }
    int result = getNumWays(candies, k);
    cout << result << "\n";
    return 0;
}
