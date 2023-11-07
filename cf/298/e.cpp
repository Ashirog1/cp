#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);

  int n, m;
  std::cin >> n;
  std::vector<int64_t> d(n + 5), a(n + 5);
  for (int i = 1; i <= n; ++i) {
    std::cin >> d[i];
  }
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int v; std::cin >> v; a[v]++;
  }
  int64_t ans = 0;
  while (m > 2 * n - 2) {
    m -= 2 * n - 2;
    ans += 2 * (d[n] - d[1]);
    a[1]--; a[n]--;
    for (int i = 2; i < n; ++i) {
      a[i] -= 2;
    }
  }  

  if (m == 2 * n - 2) {
    int p = d[2] - d[1];
    for (int i = 1; i < n; ++i) {
      if (d[i + 1] - d[i] != p) {
        std::cout << -1;
        return 0;
      }
    }
    ans += 2ll * (d[n] - d[1]) - p;
    std::cout << ans;
    return 0;
  }

  if (a[1] == 0) {
    if (a[n] == 0) {
      int l = 1;
      while (a[l] == 0) ++l;
      int r = n;
      while (a[r] == 0) --r;
      ans += d[r] - d[l];
    } else {
      int l = 1;
      while (a[l] == 0) ++l;
      int r = l;
      while (r < n and a[r] == 1) ++r;
      ans += d[n] - d[l] + d[n] - d[r];
    }
  } else {
    if (a[n] == 0) {
      int r = n;
      while (a[r] == 0) --r;
      int l = 2;
      while (a[l] == 2) ++l; --l;
      ans += d[r] - d[1] + d[l] - d[1];
    } else {
      int l = 2;
      while (a[l] == 2) ++l; --l;
      int r = n - 1;
      while (a[r] == 2) --r; ++r;
      std::cout << l << ' ' << r << '\n';
      ans += d[n] - d[1] + d[n] - d[r] + d[l] - d[1];
    }
  }
  std::cout << ans;
}
