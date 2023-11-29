#include "bits/stdc++.h"

int x[1005], y[1005], z[1005];
std::map<std::pair<int, int>, int> my;

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  int n, k;
  std::cin >> n >> k;
  int64_t ans = 0;
  int len = 0;
  for (int i = 0; i < k; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    bool ok = true;
    for (int j = 0; j < len; ++j) {
      if (a == x[j] and b == y[j] and c == z[j]) {
        ok = false;
      }
    }
    if (ok) {
      x[len] = a;
      y[len] = b;
      z[len] = c;
      ++len;

      ans += n;
    }
  }
  // std::cout << ans << '\n';

  std::vector<int> X, Y, Z;
  for (int i = 0; i < len; ++i) {
    if (x[i] == 0) X.push_back(i);
    else if (y[i] == 0) Y.push_back(i);
    else Z.push_back(i);
  }
  for (auto i : X) for (auto j : Y) if (z[i] == z[j]) --ans;
  for (auto i : X) for (auto j : Z) if (y[i] == y[j]) --ans;
  for (auto i : Y) for (auto j : Z) if (x[i] == x[j]) --ans;

  for (int i = 0; i < X.size(); ++i) {
    for (int j = 0; j < Z.size(); ++j) {
      if (y[X[i]] == y[Z[j]])
        my[{z[X[i]], x[Z[j]]}]++;
      // std::cerr << z[X[i]] << ' ' << x[Z[j]] << '\n';
    }
  }
  for (int i = 0; i < Y.size(); ++i) {
    ans += my[{z[Y[i]], x[Y[i]]}];
  }
  std::cout << ans << '\n';
}
