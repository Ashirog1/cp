#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int n; std::cin >> n;
  std::vector<std::vector<int>> r(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for(int j = i; j < n; ++j) {
      std::cin >> r[i][j];
    }
  }

  std::vector<int> ans(n);
  ans[0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int d : {1, -1}) {
      ans[i] = ans[i - 1] + d * r[i - 1][i];
      int max = INT_MIN, min = INT_MAX;
      bool good = true;
      for (int j = i; j >= 0; --j) {
        max = std::max(max, ans[j]);
        min = std::min(min, ans[j]);

        if (max - min != r[j][i]) {
          good = false;
        }
      }
      if (good) break;
    }
  }
  for (int i = 0; i < n; ++i) {
    int max = INT_MIN, min = INT_MAX;
    bool good = true;
    for (int j = i; j < n; ++j) {
      max = std::max(max, ans[j]);
      min = std::min(min, ans[j]);

      assert(max - min == r[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i];
    if (i + 1 < n) std::cout << ' ';
  }
  std::cout << '\n';
}
