#include "bits/stdc++.h"
int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int N, L, Q; std::cin >> N;
  std::vector<int> X(N);
  for (auto &x : X) std::cin >> x; std::cin >> L; std::cin >> Q;
  std::vector<std::array<int, 20>> jump(N);
  for (int i = 0, j = 0; i < N; ++i) {
    if (j < i) j = i;
    while (j < N  and abs(X[j] - X[i]) <= L) {
      ++j;
    }
    jump[i][0] = (j < N ? j - 1 : N);
  }
  for (int s = 1; s < 20; ++s) {
    for (int i = 0; i < N; ++i) {
      if (jump[i][s-1] == N) jump[i][s] = jump[i][s-1];
      else jump[i][s] = jump[jump[i][s - 1]][s - 1];
    }
  }
  const auto go = [&](int a, int s) {
    for (int i = 0; i <= 19; ++i) {
      if (a < N and (s >> i & 1)) {
        a = jump[a][i];
      }
    }
    return a;
  };
  while (Q--) {
    int a, b; std::cin >> a >> b; --a; --b; if (a > b) std::swap(a, b);
    int l = 1 , r = N, mid;
    while (l <= r) {
      mid = (l + r) / 2;
      if (go(a, mid) < b) l = mid + 1;
      else r = mid - 1;
    }
    std::cout << l << '\n';
  }
}