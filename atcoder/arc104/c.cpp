#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  const auto no_solution = [&]() {std::cout << "No"; exit(0);};
  int N; std::cin >> N;
  std::vector<int> A(N), B(N), belong(2 * N + 5, -1), match(2 * N + 5, -1);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i] >> B[i];
    if (A[i] != -1) {
      if (belong[A[i]] != -1) {
        no_solution();
      }
      belong[A[i]] = i;
    }
    if (B[i] != -1) {
      if (belong[B[i]] != -1) {
        no_solution();
      }
      belong[B[i]] = i;
    }
    if (A[i] != -1 and B[i] != -1) {
      if (A[i] > B[i]) no_solution();
      match[A[i]] = B[i];
      match[B[i]] = A[i];
    }
  }
  std::vector<bool> f(2 * N + 5);

  f[1] = 1;
  for (int i = 1; i <= 2 * N; ++i) {
    if (not f[i]) continue;
    for (int j = i + 1; j <= 2 * N; j += 2) {
      /// 
      int len = (j - i + 1) / 2;
      bool ok = true;
      for (int k = 0; k < len; ++k) {
        int p = i + k, q = i + len + k;
        if (match[p] != -1 and match[p] != q)
          ok = false;
        if (match[q] != -1 and match[q] != p)
          ok = false;
        if (belong[p] != -1 and belong[q] != -1 and belong[p] != belong[q])
          ok = false;
        /// if (p is r or q is l)
        if (belong[p] != -1 and B[belong[p]] == p) ok = false;
        if (belong[q] != -1 and A[belong[q]] == q) ok = false;
      }
      if (ok) {
        f[j + 1] = 1;
      }
    }
  }
  std::cout << (f[2 * N + 1] ? "Yes" : "No");
}