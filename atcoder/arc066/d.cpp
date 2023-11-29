#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int f[64][2][2];
int64_t n;
int calc(int pos, int add, int bigger) {
  if (pos == 60)
    return (add == 0 and bigger == 0);
  if (f[pos][add][bigger] != -1) return f[pos][add][bigger];
  // std::cout << pos << ' ' <<add << bigger << '\n';
  int ans = 0;
  for (int a = 0; a < 2; ++a) {
    for (int b = 0; b <= a; ++b) {
      int n_val = (n >> pos & 1);
      int cur_val = (a + b + add) % 2;
      int new_add = ((a + b + add) >= 2);
      int nbigger = bigger;
      if (cur_val < n_val) nbigger = 0;
      if (cur_val > n_val) nbigger = 1;
      ans += calc(pos + 1, new_add, nbigger);
      if (ans >= mod) ans -= mod;
    }
  }
  return f[pos][add][bigger] = ans;
}

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  memset(f, -1, sizeof f);
  std::cin >> n;
  std::cout << calc(0, 0, 0);
}