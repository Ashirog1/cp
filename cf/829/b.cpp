#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int n, x;
  std::cin >> n >> x;
  std::vector<int> A(n);
  std::vector<int> cnt(x + 5);
  for (auto &a : A) {
    std::cin >> a;
    cnt[a]++;
  }
  for (int i = 1; i < x; ++i) {
    if (cnt[i] % (i + 1) != 0) {
      std::cout << "NO";
      return 0;
    }
    cnt[i + 1] += cnt[i] / (i + 1);
  }
  std::cout << "YES";
}
