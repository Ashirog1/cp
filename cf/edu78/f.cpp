#include <bits/stdc++.h>
const int mod = 998244353;
int add(int x, int y) {x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; return x; }
int fpow(int x, int y) {
  int z = 1;
  while (y > 0) {
    if (y&1) z = 1ll * z * x % mod;
    x  = 1ll * x * x % mod;
    y/=2;
  }
  return z;
}
int inv(int x) {return fpow(x, mod - 2);}
const int maxn = 5005;
int f[maxn][maxn];

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  f[0][0] = 1;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= i; ++j) {
      f[i][j] = add(f[i][j], 1ll * f[i - 1][j - 1] * (n - (j - 1)) % mod);
      f[i][j] = add(f[i][j], 1ll * f[i - 1][j] * j % mod);
    }
  }

  int ans = 0;
  for (int j = 1; j <= k; ++j) {
    ans = add(ans, 1ll * f[k][j] * fpow(inv(m), j) % mod);
  }
  std::cout << ans;
}