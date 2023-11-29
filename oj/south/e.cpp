#include "bits/stdc++.h"

const int maxn = 2000;
int a[5005];
int64_t f[5005][5005];
int pos[5005];
int64_t base = 1e9 + 5;

int64_t add(int64_t x, int64_t y) {
  int64_t z = x + y;
  if (z >= base) z = base;

  return z;
}

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }


  f[0][0] = 1;
  for (int i = 1; i <= maxn; ++i) {
    f[i][0] = f[i - 1][1];

    for (int j = 1; j <= 1000; ++j) {
      f[i][j] = add(f[i][j], f[i - 1][j - 1] + f[i - 1][j + 1]);
    }

  }

  // for (int i = 1; i <= 10; ++i) {

  //   for (int j = 1; j <= 10; ++j) {
  //     std::cerr << f[i][j] << ' ';
  //   }
  //   std::cerr << '\n';
  // }


  int p, n, k;
  while (std::cin >> p) {
    if (p == 1) {
      std::cin >> n >> k;
    } else {
      std::cin >> n;
      for (int i = 1; i <= 2 * n; ++i) {
        std::cin >> a[i];
        pos[a[i]] = i;
      }
    }

    if (p == 1) {
      for (int i = 1; i <= 2 * n; ++i) a[i] = 0, pos[i] = 0;
      int d = 0;
      for (int i = 1; i <= 2 * n; ++i) {
        if (d + 1 <= n and f[2 * n - i][d + 1] >= k) {
          /// open
          pos[i] = 1;
          ++d;
        } else {
          pos[i] = -1;
          if (d + 1 <= n)
            k -= f[2 * n -i][d + 1];
          --d; 
        }
      }
      std::vector<int> l, r;
      for (int i = 1; i <= 2 * n; ++i) {
        if (pos[i] > 0) l.push_back(i);
        else r.push_back(i);
      }
      for (auto i : l) std::cout << i << ' '; for (auto i : r) std::cout << i << ' '; std::cout << '\n';
    } else {
      int d = 0;
      int64_t ans = 0;
      for (int i = 1; i <= 2 * n; ++i) {
        if (pos[i] <= n) ++d;
        else {
          ans += f[2 * n - i][d + 1];
          --d;
          // std::cerr << i << ' ' << ans << '\n';
        }
      }
      std::cout << ans + 1 << '\n';
    }
  }  
}
