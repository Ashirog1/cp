#include "bits/stdc++.h"
using namespace std;

int d[105][105];

int main() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = 1e9;
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;

    d[x][y] = d[y][x] = 1;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int mx = 0, mi = 1e9;
  for (int i = 1; i <= n; ++i) {
    int ret = 0;
    for (int j = 1; j <= n; ++j) {
      ret = max(ret, d[i][j]);
    }
    mx = max(mx, ret); mi = min(mi, ret);
  }
  cout << mx << ' ' << mi << '\n';
}