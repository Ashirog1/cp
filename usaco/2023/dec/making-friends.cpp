#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::set<int>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v;
    --u; --v; if (u > v) std::swap(u, v);
    adj[u].insert(v);
  }
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    if (adj[i].empty()) continue;
    ans += adj[i].size();
    if (adj[i].empty()) continue;
    int j = *adj[i].begin();
    adj[i].erase(j);

    if (adj[i].size() > adj[j].size())
      std::swap(adj[i], adj[j]);
    for (auto x : adj[i]) {
      adj[j].insert(x);
    }
  }
  std::cout << ans - m; 
}
