#include "bits/stdc++.h"
const int maxn = 1e5 + 5;
std::vector<int> adj[maxn];
int n;
int main() {
  std::ios_base::sync_with_stdio(0);
  int tc; while (tc--) {
    std::cin >> n;
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
      int u, v; std::cin >> u >> v;
      adj[u].push_back(v); adj[v].push_back(u);
    }
    
  }
}