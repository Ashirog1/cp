#include "bits/stdc++.h"

const int mod = 998244353, maxn = 1e7 + 5;

int fib[maxn];

int main() {
  std::ios_base::sync_with_stdio(0);

  fib[0] = 1; fib[1] = 1;
  for (int i = 2; i < maxn; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  
  int n; std::cin >> n;
  int S = 0;
  for (int i = 0; i < (1 << n); ++i) {
    if (__builtin_popcount(i) == 0) continue;
    int gc = 0;
    for (int j = 1; j <= n; ++j) {
      if (i >> (j - 1) & 1) if (gc == 0) gc = j; else gc = std::gcd(gc, j);
    }
    S += fib[gc];
  }
  std::cout << S;
}