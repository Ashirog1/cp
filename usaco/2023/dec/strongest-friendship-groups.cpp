#include "bits/stdc++.h"

struct DSU {
  std::vector<int> p, deg;
  DSU(int n) {
    p.assign(n, -1);
  }
  int find(int u) { return (p[u] < 0) ? u : find(p[u]); }
  void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    if (p[u] > p[v]) std::swap(u, v);
    p[u] += p[v];
    p[v] = u;
  }
  int size(int u) { return -p[find(u)]; }
};

int main() {
  std::ios::sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> edges(m);
  std::vector<int> deg(n);
  std::vector<std::vector<int>> adj(n);
  for (auto &[u, v] : edges) {
    std::cin >> u >> v;
    --u; --v;
    deg[u]++; deg[v]++;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  std::vector<int> order;
  std::set<std::pair<int, int>> set_deg;
  std::vector<int> erased(n);
  for (int i = 0; i < n; ++i) {
    set_deg.insert({deg[i], i});
  }
  for (int i = 0; i < n; ++i) {
    auto it = set_deg.begin(); set_deg.erase(it);
    order.emplace_back(it->second);
    erased[it->second] = true;
    for (auto v : adj[it->second]) {
      if (erased[v]) continue;;
      set_deg.erase({deg[v], v});
      deg[v]--;
      set_deg.insert({deg[v], v});
    }
  }
  std::fill(deg.begin(), deg.end(), 0);
  std::reverse(order.begin(), order.end());
  int64_t ans = 0;
  DSU dsu(n);
  std::vector<int> big(n);
  for (auto u : order) {
    big[u] = true;
    for (auto v : adj[u]) {
      if (big[v]) {
        dsu.merge(u, v);
        ++deg[u]; ++deg[v];
      }
    }
    ans = std::max(ans, (int64_t)dsu.size(u) * deg[u]);
  }

  std::cout << ans << '\n';
}
