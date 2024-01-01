#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int n, m, c; std::cin >> n >> m >> c;
  std::vector<std::tuple<int, int, int>> edges(m);
  std::vector<std::vector<int>> adj(n);
  {
    int cnt_edge = 0;
    for (auto&[u, v, w] : edges) {
      std::cin >> u >> v >> w;
      --u; --v;

      adj[u].push_back(cnt_edge); adj[v].push_back(cnt_edge);
      ++cnt_edge;
    }
  }
  std::vector<int> starts(c), cnt_starts(n);
  for (auto&start : starts) {
    std::cin >> start; -- start; ++cnt_starts[start];
  }
  // {
  //   const int64_t inf = 1e18 + 5;
  //   std::vector<int64_t> d(n, inf);
  //   std::vector<int64_t> ways(n, 0);
  //   std::vector<bool> excced(n, 0); /// is ways(u) > n?
  //   using pq_type = std::pair<int64_t, int>;
  //   std::priority_queue<pq_type, std::vector<pq_type>, std::greater<pq_type>> pq;
  //   pq.emplace(0, 0); d[0] = 0;
  //   while (pq.size()) {
  //     auto [dist, u] = pq.top(); pq.pop();
  //     if (dist != d[u]) continue;

  //     for (auto )
  //   }
  // }
}