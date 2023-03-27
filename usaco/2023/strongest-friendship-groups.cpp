#include "bits/stdc++.h"

struct DSU {
  std::vector<int> p, deg;
  using pq_type = std::pair<int, int>;
  std::vector<
      std::priority_queue<pq_type, std::vector<pq_type>, std::greater<pq_type>>>
      min_deg;
  DSU(int n) {
    p.assign(n, -1);
    deg.assign(n, 0);
    min_deg.resize(n);
    for (int i = 0; i < n; ++i) min_deg[i].emplace(0, i);
  }
  int find(int u) { return (p[u] < 0) ? u : find(p[u]); }
  std::pair<int, int> get_min(int u) {
    u = find(u);
    while (not min_deg[u].empty()) {
      auto [d, v] = min_deg[u].top();
      /// std::cerr << d << ' ' << deg[v] << ' ' << v << '\n';
      if (d != deg[v]) {
        min_deg[u].pop();
      } else {
        return {d, v};
      }
    }
    assert(false);
    return {-1, -1};
  }
  void merge_min_deg(int u, int v) {
    while (not min_deg[v].empty()) {
      min_deg[u].emplace(get_min(v));
      min_deg[v].pop();
    }
  }
  void merge(int u, int v) {
    deg[u]++; deg[v]++;
    u = find(u); v = find(v);
    min_deg[u].emplace(deg[u], u);
    min_deg[u].emplace(deg[v], v);

    if (u == v) return;

    if (p[u] > p[v]) std::swap(u, v);
    p[u] += p[v];
    p[v] = u;
    merge_min_deg(u, v);
  }
  int size(int u) { return -p[find(u)]; }
};

int main() {
  std::ios::sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> edges(m);
  std::vector<int> deg(n);
  for (auto &[u, v] : edges) {
    std::cin >> u >> v;
    --u; --v;
    deg[u]++; deg[v]++;
  }
  std::sort(edges.rbegin(), edges.rend(), [&](auto e1, auto e2) {
    return std::min(deg[e1.first], deg[e1.second]) <
           std::min(deg[e2.first], deg[e2.second]);
  });
  int64_t ans = 0;
  DSU dsu(n);

  for (const auto &[u, v] : edges) {
    dsu.merge(u, v);
    ans = std::max(ans, (int64_t)dsu.get_min(u).first * dsu.size(u));
  }
  std::cout << ans;
}
