#include "bits/stdc++.h"

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int a[505][505], d[505][505];
int n, G, p;
int vis[505][505];

void bfs(int lim) {
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = -1, vis[i][j] = 0;

  std::deque<std::pair<int, int>> pq;

  d[1][1] = (lim > a[1][1] ? 1 : 0);
  pq.push_back({1, 1});

  while (pq.size()) {
    auto c = pq.front(); pq.pop_front();

    // if (_ != d[c.first][c.second]) continue;

    if (vis[c.first][c.second]) continue;
    vis[c.first][c.second] = true;

    for (int t = 0; t < 4; ++t) {
      int nx = c.first + dx[t], ny = c.second + dy[t];

      if (1 <= nx and nx <= n and 1 <= ny and ny <= n) {
        int cost = (lim > a[nx][ny] ? 1 : 0);
        if (d[nx][ny] == -1 or d[nx][ny] > d[c.first][c.second] + cost) {
          d[nx][ny] = d[c.first][c.second] + cost;
          if (cost == 0)
          pq.push_front({nx, ny});
          else pq.push_back({nx, ny});
        }
      }
    }
  }

}

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

   std::cin >> p;
  if (p == 1) {
    std::cin >> n >> G;
  } else {
    std::cin >> n;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> a[i][j];
    }
  }

  if (p == 1) {
    bfs(G);
    std::cout << d[n][n] << '\n';
  } else {
    int l = 1, r = 1e4;
    while (l <= r) {
      int mid = (l + r) / 2;
      bfs(mid);

      if (d[n][n] == 0) l = mid + 1;
      else r = mid - 1;
    }
    std::cout << r;
  }
}
