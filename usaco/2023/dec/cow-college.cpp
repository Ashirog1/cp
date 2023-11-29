#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int N; std::cin >> N;
  std::vector<int> A(N);
  for (auto&a : A) std::cin >> a;
  std::sort(A.begin(), A.end());
  int64_t ans = 0, tution = 0;
  for (int i = 0; i < N; ++i) {
    int64_t tmp = (int64_t)(N - i) * A[i];
    if (ans < tmp) {
      ans = tmp;
      tution = A[i];
    }
  }
  std::cout << ans << ' ' << tution;
}
