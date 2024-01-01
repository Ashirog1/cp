#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<int>> dp(n + 1, vector<int> (n + 1));
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i-1]) {
      for (int j = 1; j < i; j++)
        dp[i][i-1] += dp[i-1][j];
    }
    else {
      for (int j = i-1, w = 2; j >= 1; j--, w += w) {
        dp[i][j] =( w - 1) * dp[i-1][j];
      }
    }
    for (int j = 1; j <= i; j++) {
      cout << dp[i][j] <<" ";
    }
    cout << endl;
  }
  cout << accumulate(dp[n].begin(), dp[n].end(), 0);
}