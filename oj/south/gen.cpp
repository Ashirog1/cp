#include "bits/stdc++.h"

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  std::vector<std::vector<int>> tmp;
  int n; std::cin >> n; n *= 2;
  for (int m = 0; m < (1 << n); ++m) {
    if (__builtin_popcount(m) != n/2) continue;

    std::vector<int> l, r;
    for (int i = 0; i < n; ++i) if (m >> i & 1) l.push_back(i + 1); else r.push_back(i + 1);
    bool ok = true;
    for (int i = 0; i < l.size(); ++i) {
      if (l[i] > r[i])  ok = false; }
      if (not ok) continue;
    for (auto i : r) l.push_back(i);
    tmp.push_back(l);
  }

  std::sort(tmp.begin(), tmp.end());
  for (auto v : tmp) {
    std::cout << 2 << ' ' <<n / 2 << ' ';
    for (auto i : v) std::cout << i << ' '; std::cout << '\n';
  }

}
