#include <bits/stdc++.h>
int main() {    
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::map<int, int>> map(n);
  std::vector<std::tuple<int, int, int>> edges(m); 
  for (auto&[u,v,w] : edges) {
    std::cin >> u >> v >> w;
    --u; --v; --w;
    map[u][w] = 0; map[v][w] = 0;
  }
  int cnt = n;
  for (int i = 0; i < n; ++i) {
    for (auto&[k, v] : map[i]) {
      v = cnt++;
    }
  }
  std::vector<std::vector<std::pair<int, int>>> g(cnt);
  for (auto[u,v,w] : edges) {
    u = map[u][w]; v = map[v][w];
    g[u].emplace_back(v, 0);
    g[v].emplace_back(u, 0);
  }
  for (int i = 0; i < n; ++i) {
    for (auto[k, v] : map[i]) {
      g[i].emplace_back(v, 1);
      g[v].emplace_back(i, 0);
    }
  }
  std::vector<bool> vis(cnt, 0); std::vector<int> f(cnt, 1 << 30);
  f[0] = 0;
  std::deque<int> dq; dq.emplace_back(0);
  while (not dq.empty()) {
    int u = dq.front(); dq.pop_front();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (f[v] > f[u] + w) {
        f[v] = f[u] + w;
        if (w == 0) dq.emplace_front(v);
        else dq.emplace_back(v);
      }
    }
  }
  int res = f[n - 1]; if (not vis[n - 1]) res = -1;
  std::cout << res;}