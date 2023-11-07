#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  
  int n, m, p, q; std::cin >> n >> m >> p >> q;
  std::vector<std::string> A(n);
  std::vector<std::vector<std::pair<int, int>>> adj(n * m);
  const auto inside = [&](int a, int b) {
    return 0 <= a and a < n and 0 <= b and b < m;
  };
  const auto add_edge = [&](int a, int b, int c, int d, int cost) {
    if (not inside(a, b)) return;
    if (not inside(c, d)) return;
    assert(inside(a, b) and inside(c, d));
    if (A[a][b] == '#') return;
    if (A[c][d] == '#') return;
    adj[a * m + b].emplace_back(c * m + d, cost);
  };
  using pq_type = std::pair<int64_t, int>;
  std::priority_queue<pq_type, std::vector<pq_type>, std::greater<pq_type>> pq;
  std::vector<int64_t> D(n * m, 1e16);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (A[i][j] == 'L') {
        add_edge(i, j - 1, i, j + 1, q);
        add_edge(i, j + 2, i, j, q);
        add_edge(i - 1, j, i, j + 1, p);
        add_edge(i + 1, j, i, j + 1, p);
        add_edge(i - 1, j + 1, i, j, p);
        add_edge(i + 1, j + 1, i, j, p);
      } else if (A[i][j] == 'U') {
        add_edge(i - 1, j, i + 1, j, q);
        add_edge(i + 2, j, i, j, q);
        add_edge(i, j - 1, i + 1, j, p);
        add_edge(i, j + 1, i + 1, j, p);
        add_edge(i + 1, j - 1, i, j, p);
        add_edge(i + 1, j + 1, i, j, p);
      } else if (A[i][j] == '.') {
        D[i * m + j] = 0;
        pq.emplace(0, i * m + j);
      }
    }
  }
  while (not pq.empty()) {
    auto [dist, cur] = pq.top(); pq.pop();
    if (D[cur] != dist) continue;
    //std::cout << cur << ' ';
    for (const auto&[next, cost] : adj[cur]) {
      if (D[next] > dist + cost) {
        pq.emplace((D[next] = dist + cost), next);
      }
    }
  }
  int64_t ans = 1e18;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i + 1 < n) {
        if (A[i][j] != '#' and A[i + 1][j] != '#')
        ans = std::min(ans, D[i * m + j] + D[(i + 1) * m + j]);
      }
      if (j + 1 < m) {
        if (A[i][j] != '#' and A[i][j + 1] != '#')
        ans = std::min(ans, D[i * m + j] + D[i * m + j + 1]);
      }
    }
  } 
  if (ans >= 1e16) ans = -1;
  std::cout << ans;
}
