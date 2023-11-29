#include "bits/stdc++.h"
const int maxn = 1e5 + 5;
std::vector<int> adj[maxn];
std::vector<std::pair<int, int>> edges;
bool isDel[maxn], vis[maxn];
int n;
std::vector<int> dels;
std::vector<std::pair<int, int>> adds;
std::vector<int> curComp;
void dfs(int u, int p = -1) {
  int child = 0;
  for (int i : adj[u]) {
    int v = edges[i].first + edges[i].second - u;
    if (i == p)
      continue;
    dfs(v, i);
    if (isDel[i]) continue;
    ++child;
  }
  if (child <= 1)
    return;
  if (child == 2) {
    if (p != -1) {
      isDel[p] = true;
      dels.emplace_back(p);
    }
  } else {
    int c = 0;
    if (p != -1) {
      dels.emplace_back(p);
      isDel[p] = true;
    }
    for (int i : adj[u]) {
      int v = edges[i].first + edges[i].second - u;
      if (isDel[i]) continue;
      if (i != p) {
        ++c;
        if (c <= child - 2) {
          dels.emplace_back(i);
          isDel[i] = true;
        }
      }
    }
  }
}
/// @brief find 2 leaf of a bamboo
/// @param u
/// @param p
/// @return
void dfs2(int u, int p = -1) {
  vis[u] = true;
  int c = 0;
  // std::cout << u << ' ' << p << '\n';
  for (int i : adj[u]) {
    if (isDel[i])
      continue;
    ++c;
    int v = edges[i].first + edges[i].second - u;
    if (v != p and not vis[v]) {
      dfs2(v, u);
    }
  }
  if (c <= 1)
    curComp.push_back(u);
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int tc;
  std::cin >> tc;
  while (tc--) {
    adds.clear(); dels.clear();
    edges.clear();
    std::cin >> n;
    for (int i = 0; i <= n; ++i)
      adj[i].clear(), isDel[i] = false, vis[i] = false;
    for (int i = 1; i < n; ++i) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(edges.size());
      adj[v].push_back(edges.size());
      edges.emplace_back(u, v);
    }
    dfs(1, -1);
    int last = -1;
    for (int i = 1; i <= n; ++i) {
      if (not vis[i]) {
        curComp.clear();
        dfs2(i, i);
        if (last != -1) {
          adds.emplace_back(last, curComp[0]);
        }
        if (curComp.size() > 1)
          last = curComp[1];
        else
          last = curComp[0];
      }
    }
    std::cout << adds.size() << '\n';
    for (int i = 0; i < adds.size(); ++i) {
      std::cout << edges[dels[i]].first << ' ' << edges[dels[i]].second << ' ' ;
      std::cout << adds[i].first << ' '
                << adds[i].second << ' ' << '\n';
    }
  }
}