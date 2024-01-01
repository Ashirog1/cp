#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int tc; std::cin >> tc;
  while (tc--) {
    int n; std::cin >> n;
    std::string s, t; std::cin >> s >> t;

    const auto val = [&](std::string s) {
      int cnt = 0, pref = 0;
      for (auto c : s) {
        pref ^= (c - '0');
        cnt += pref;
      }
      return std::min(cnt, n + 1 - cnt);
    };

    std::cout << (val(s) == val(t) ? "YES\n" : "NO\n");
  }
}