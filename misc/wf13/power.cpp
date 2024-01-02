#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> p(2 * n * k);
  for (auto &i : p)
    std::cin >> i;
  std::sort(p.begin(), p.end());
  const auto check = [&](int diff) {
    int rem = 0, matched = 0;
    for (int i = 0; i + 1 < p.size(); ++i) {
      // std::cout << i << ' ' << matched << ' ' << rem << '\n';
      if (matched < n and p[i + 1] - p[i] <= diff) {
        ++matched;
        rem += 2 * k - 2;
        ++i;
      } else {
        --rem;
        if (rem < 0) break;
      }
    }
    if (matched != n) return false;
    if (rem < 0) return false;
    return true;
  };
  // check(1);
  // return 0;
  int l = 0, r = 1e9, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  std::cout << l << '\n';
}