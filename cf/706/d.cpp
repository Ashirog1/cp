#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  const int mod = 998244353;
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> dist(n), adj(n), ans(n, std::vector<int>(n));
  const auto bfs = [&](int src) {
    std::vector<int> D(n, -1);
    std::queue<int> Q;
    Q.push(src); D[src] = 0;
    while (not Q.empty()) {
      int u = Q.front(); Q.pop();
      for (int v : adj[u]) {
        if (D[v] == -1) {
          D[v] = D[u] + 1;
          Q.push(v);
        }  
      }
    }
    return D;
  };
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v;
    --u; --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (int i = 0; i < n; ++i) {
    dist[i] = bfs(i);
  }
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      int cnt = 0; 
      for (int i = 0; i < n; ++i) {
        if (dist[x][i] + dist[y][i] == dist[x][y]) {
          ++cnt; 
        }
      }
      int ans = 1;
      if (cnt != dist[x][y] + 1) ans = 0;
      w    
    }
  }
}
