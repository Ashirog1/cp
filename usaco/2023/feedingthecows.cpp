#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int tc; std::cin >> tc;
  while (tc--) {
    int N, K; std::cin >> N >> K;
    std::string cows; std::cin >> cows;
    std::vector<char> field(N, '.');
    std::vector<bool> satisfy(N);
    for (int i = 0; i < N; ++i) {
      if (satisfy[i]) continue;
      int lim = 0;
      for (int j = i; j < N and j <= i + 2 * K; ++j) {
        if (cows[i] == cows[j]) {
          satisfy[j] = true;
          lim = std::max(lim, j);
        }
      }
      for (int j = std::max(0, i - K); j <= std::min(lim + K, N); ++j) {
        if (field[j] == '.' and i + K >= j and j + K >= lim) {
          field[j] = cows[i];
          break;
        }
      }
    }
    int ans = 0;
    for (auto it : field) if (it != '.') ++ans;
    std::cout << ans << '\n';
    for (auto it : field) std::cout << it;
    std::cout << '\n';
  }  
}

