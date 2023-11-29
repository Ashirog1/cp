#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<std::tuple<int, int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c, p; std::cin >> a >> b >> c >> p;
    --a; --b;
    adj[a].emplace_back(b, c, p);
    adj[b].emplace_back(a, c, p);
  }
  
}
