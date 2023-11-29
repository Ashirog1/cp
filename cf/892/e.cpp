#include "bits/stdc++.h"
template<class T>
void maximize(T&x, T y) {x = std::max(x, y);}
const int maxn = 3005;
/// @brief f(i, j, m): use open/close interval trick, m is current state of open interval
int64_t a[maxn], b[maxn]; int n, k;
int64_t f[maxn][maxn][5];
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie();
  int tc;
  std::cin >> tc;
  while (tc--) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
      std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
      std::cin >> b[i];
    for (int i = 0; i <= n+1; ++i)
      for (int j = 0; j <= n+1; ++j)
        for (int t = 0; t < 5; ++t) {
          f[i][j][t] = -1e17;
        }
    f[1][0][4] = 0;
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        // std::cout << f[i][j][4] << ' ';
        maximize(f[i+1][j][4], f[i][j][4]);
        /// open
        for (int t = 0; t < 4; ++t) {
          if (j+1<=k)
          maximize(f[i+1][j+1][t], f[i][j][4] + (t&1?a[i]:-a[i]) + (t&2?b[i]:-b[i]));
        }
        /// close
        for (int t = 0; t < 4; ++t) {
          if (j+1<=k)
          maximize(f[i+1][j+1][4], f[i][j][t] + (t&1?-b[i]:+b[i]) + (t&2?-a[i]:a[i]));
        }

        /// skip
        for (int t = 0; t < 4; ++t) {
          maximize(f[i+1][j+1][t], f[i][j][t]);
        }

        /// len=1
        if (j+1<=k)  {
          // std::cout << i << ' ' << j << '\n';
          maximize(f[i+1][j+1][4], f[i][j][4] + 2*abs(a[i]-b[i]));
        }
      }
      // std::cout << '\n';
    }
    std::cout << f[n+1][k][4] << '\n';
  }
}