#include "bits/stdc++.h"

char f[22][11][11][11][11][11][32];
char ans[100][100];
int n, m, a[100], b[100];

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  for (int i = 1; i <= m; ++i)
    std::cin >> b[i];

  memset(f, -1, sizeof f);

  f[0][0][0][0][0][0][0] = 1;

  std::vector<int> prv;
  prv.push_back(0);

  for (int i = 0; i < m; ++i) {
    std::vector<int> avail;
    for (int mask = 0; mask < 32; ++mask) {
      int ret = 1;
      for (int j = 1; j < 5; ++j) {
        if ((mask >> j & 1) && !(mask >> (j - 1) & 1))
          ++ret;
      }
      if (ret == b[i + 1])
        avail.push_back(mask);
    }

    for (int j0 = 0; j0 <= (i + 1) / 2; ++j0) {
      for (int j1 = 0; j1 <= (i + 1) / 2; ++j1) {
        for (int j2 = 0; j2 <= (i + 1) / 2; ++j2) {
          for (int j3 = 0; j3 <= (i + 1) / 2; ++j3) {
            for (int j4 = 0; j4 <= (i + 1) / 2; ++j4) {
              for (auto cur_mask : prv) {
                if (f[i][j0][j1][j2][j3][j4][cur_mask] != -1) {
                  for (auto nxt_mask : avail) {
                    int i0 = j0, i1 = j1, i2 = j2, i3 = j3, i4 = j4;
                    for (int t = 0; t < 5; ++t) {
                      if (!(cur_mask >> t & 1) && (nxt_mask >> t & 1)) {
                        if (t == 0)
                          ++i0;
                        else if (t == 1)
                          ++i1;
                        else if (t == 2)
                          ++i2;
                        else if (t == 3)
                          ++i3;
                        else if (t == 4)
                          ++i4;
                      }
                    }
                    if (i0 <= a[0] and i1 <= a[1] and i2 <= a[2] and i3 <= a[3] and i4 <= a[4]) {
                      f[i + 1][i0][i1][i2][i3][i4][nxt_mask] = cur_mask;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    prv = avail;
  }
  int i0 = a[0], i1 = a[1], i2 = a[2], i3 = a[3], i4 = a[4], i = m, cur_mask = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (f[i][i0][i1][i2][i3][i4][mask] != -1) {
      cur_mask = mask;
    }
  }
  while (i > 1) {
    int nmask = f[i][i0][i1][i2][i3][i4][cur_mask];

    for (int j = 0; j < 5; ++j) if (cur_mask & 1 << j) ans[j][i] = '*';
    else ans[j][i] = '.';
    for (int j = 0; j < 5; ++j) if (!(nmask & 1 << j) && (cur_mask & 1 << j)) {
      if (j == 0)
        i0--;
      else if (j == 1)
        i1--;
      else if (j == 2)
        i2--;
      else if (j == 3)
        i3--;
      else if (j == 4)
        i4--;
    }
    i--;
    cur_mask = nmask;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cout << ans[i][j];
    }
    std::cout << '\n';
  }

  std::cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
