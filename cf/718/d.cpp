#include "bits/stdc++.h"

int n, m, k;
int cost_hori[505][505], cost_ver[505][505];
int dist[505][505][25], vis[505][505];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  std::cin >> n >> m >> k;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m; ++j) {
      std::cin >> cost_hori[i][j];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> cost_ver[i][j];
    }
  }

  if (k & 1) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        std::cout << -1 << ' ';
      }
      std::cout << '\n';
    }
    return 0;
  }
  memset(dist, -1, sizeof dist);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      dist[i][j][0] = 0;
  for (int s = 1; s <= k / 2; ++s) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (dist[i][j][s - 1] == -1)
          continue;
        for (int d = 0; d < 4; ++d) {
          std::pair<int, int> nxt = std::make_pair(i + dx[d], j + dy[d]);
          if (1 <= nxt.first and nxt.first <= n and 1 <= nxt.second and nxt.second <= m) {
            int w = 0;
            if (d == 0)
              w = cost_ver[i][j];
            else if (d == 1)
              w = cost_hori[i][j];
            else if (d == 2)
              w = cost_ver[nxt.first][nxt.second];
            else
              w = cost_hori[nxt.first][nxt.second];
            if (dist[nxt.first][nxt.second][s] == -1 or dist[nxt.first][nxt.second][s] > dist[i][j][s - 1] + w) {
              dist[nxt.first][nxt.second][s] = dist[i][j][s - 1] + w;
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cout << dist[i][j][k / 2] * 2 << ' ';
    }
    std::cout << '\n';
  }
}
