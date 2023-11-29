#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  /*max = [x/2] + y
    min = max([x/2], y)*/
  int mx, mn;
  cin >> mx >> mn;
  if (mn * 2 >= mx && mn <= mx) {
    /// y = mn; x = (mx - y)*2
    int y = mx - mn, x = mn * 2;
    vector<pair<int, int>> edges;
    for (int i = 0; i + 1 < x; i++) {
      edges.emplace_back(i + 1, (i + 1) % x + 1);
      // cout << i + 1 <<" " << (i + 1) % x + 1 << "\n";
    }
    if (x != 2) edges.emplace_back(1, x);
    for (int i = 0; i < y; i++) {
      if (mn != mx || i > 0)
        edges.emplace_back(x + i + 1, x + i);
      // cout << x + i + 1 <<" " << x + i << "\n";
    }
    int n = 0;
    for (auto &[x, y] : edges)
      n = max({n, x, y});
    cout << n << " " << edges.size() << "\n";
    for (auto &[x, y] : edges)
      cout << x << " " << y << "\n";
  } else
    cout << "-1";
}