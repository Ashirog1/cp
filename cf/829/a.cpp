#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int tc; std::cin >> tc;
  while (tc--) {
    int n; std::cin >> n;
    std::vector<int> A(n);
    int cnt = 0;
    std::vector<int> p;
    for (int i = 0; i < n; ++i) {
      std::cin >> A[i];
      if (A[i]) {
        p.push_back(i);
      }
    }
    if (p.size() & 1) {
      std::cout << -1 << '\n';
      continue;
    }
    std::vector<std::pair<int, int>> ans;
    if (p.size() == 0) {
      ans.emplace_back(0, n -1);
    } else {
      if (p[0] >= 1) {
        ans.emplace_back(0, p[0] - 1);
      }
    }
    for (int i = 0; i < (int)p.size(); i += 2) {
      int x = p[i], y = p[i + 1];

      int valx = A[x];
      int valy = A[y] * ((y - x) % 2 ? -1 : 1);

      int br = (i + 2 >= p.size() ? n - 1 : p[i + 2] - 1);
      if (valx + valy == 0) {
        ans.emplace_back(x, br);
      } else {
        ans.emplace_back(x, x);
        ans.emplace_back(x + 1, br);
      }
    }
    std::cout << ans.size() << '\n';
    for (const auto&[l, r] : ans) {
      std::cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }
}
