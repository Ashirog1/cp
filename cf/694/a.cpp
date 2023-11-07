#include "bits/stdc++.h"

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  int tc; std::cin >> tc;

  while (tc--) {
    int n, m; std::cin >> n >> m;
    std::vector<int> k(n), c(m);
    for (auto &it : k) std::cin >> it, --it;
    for (auto &it : c) std::cin >> it;

    std::vector<bool> taken(m + 5);
    std::sort(k.begin(), k.end());
    int64_t ans = 0;
    int j = 0;
    for (int i = (int)k.size() - 1; i >= 0; --i) {
      int add = c[k[i]];
      while (j < m and taken[j]) ++j;

      if (j >= m or add <= c[j]) ans += add;
      else {
        taken[j] = true;
        ans += c[j];
      }
    }
    std::cout << ans << '\n';
  }
}
