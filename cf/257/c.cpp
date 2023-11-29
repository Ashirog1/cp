#include "bits/stdc++.h"
int main() {
  std::ios_base::sync_with_stdio(0);
  int n; std::cin >> n;
  std::vector<std::pair<int, int>> ret;
  std::vector<bool> is_prime(n + 5, 1), used(n + 5);
  is_prime[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    for (int j = i * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  for (int p = 3; p * 2 <= n; ++p) {
    if (not is_prime[p]) continue;
    int cnt = 0;
    for (int j = p; j <= n; j += p) {
      if (not used[j]) ++cnt;
    }
    bool skip = false;
    if (cnt&1)  skip = true;
    int last = -1;
    for (int j = p; j <= n; j += p) {
      if (j == 2 * p and skip) continue;
      if (used[j]) continue;
      used[j] = true;
      if (last == -1) last = j;
      else ret.emplace_back(last, j), last = -1;
    }
  }
  int last = -1;
  for (int j = 2; j <= n; j += 2) {
    if (used[j]) continue;
    if (last == -1) last = j;
    else ret.emplace_back(last, j), last = -1;
  }
  std::cout << ret.size() << '\n'; for (const auto[x, y] : ret) std::cout << x << ' ' << y << '\n';
}