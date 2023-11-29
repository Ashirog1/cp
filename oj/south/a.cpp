#include "bits/stdc++.h"

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  int tc; std::cin >> tc;
  while (tc--) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a) std::cin >> i;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) a[i] -= i + 1;
    std::sort(a.begin(), a.end());
    int l= 0, cnt = 0;
    while (l >= 0 and a[l] == a[n - 1]) --l, ++cnt;

    std::cout << (a[n - 1] == 0 ? "RR" : (cnt % 2 == 0 ? "Hieu" : "RR")) << '\n';
  }
}
