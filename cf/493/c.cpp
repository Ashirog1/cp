#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include "bits/stdc++.h"
const int maxn = 1e6 + 5, mod = 998244353;
int add(int a, int b) { a += b; if (a >= mod) a -= mod; if ( a < 0) a += mod; return a;}
int mul(int a, int b) {return 1ll * a * b % mod; }
template<class T>
int fpow(T a, T b) {
  int c = 1;
  while (b > 0) {
    if (b&1) c = mul(c, a);
    a = mul(a, a);
    b/=2;
  }
  return c;
}
int fact[maxn], ifact[maxn];
int binom(int n, int k) {
  if (k > n or n < 0 or k < 0) return 0;
  return 1ll * fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) fact[i] = mul(i, fact[i-1]);
  ifact[maxn - 1] = fpow(fact[maxn-1], mod - 2);
  for (int i = maxn - 2; i >= 0; --i) ifact[i] = mul(ifact[i+1], i+1);
  int n; std::cin >> n;
  int ans = add(fpow(3, n * n), - fpow(add(fpow(3, n), -3), n));
  for (int i = 1; i <= n; ++i) {
    int val = 3ll * binom(n, i) * (
    ans = add(ans, val * ((i & 1) ? 1 : -1));
  }
  std::cout << ans;
}