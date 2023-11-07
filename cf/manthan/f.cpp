#include "bits/stdc++.h"

const int maxn = 1e5 + 5;

std::vector<int> a, par, vis;
std::vector<int> adj[maxn];
std::vector<int64_t> f, g, depth;

int deep_leaf = -1;

void prep(int u, int p, bool marked = false) {
  par[u] = p;
  if (p == -1)
    depth[u] = a[u];

  if (marked)
    vis[u] = true;

  if (deep_leaf == -1 or depth[deep_leaf] < depth[u]) {
    deep_leaf = u;
  }

  for (int v : adj[u]) {
    if (v == p or vis[v])
      continue;
    depth[v] = depth[u] + a[v];
    prep(v, u, marked);
  }
}
void dfs(int u, int p){
  f[u] = a[u];
  g[u] = a[u];
  std::vector<int> child;
  int64_t big1 = 0, big2 = 0;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u);
    f[u] = std::max(f[u], f[v]);

    if (big1 == -1 or g[v] >= big1) {
      std::swap(big1, big2);
      big1 = g[v];
    } else {
      if (big2 == -1 or g[v] > big2) {
        big2 = g[v];
      }
    }
  }
  g[u] = big1 + a[u];
  f[u] = std::max(f[u], big1 + big2 + a[u]);
};

std::vector<int64_t> diamater_dp(int root, int par = -1) {
  std::fill(f.begin(), f.end(), 0);
  std::fill(g.begin(), g.end(), 0);

  dfs(root, par);

  return f;
};

std::pair<int, int> diamater_dfs(int root, bool marked = false) {
  deep_leaf = -1;
  prep(root, -1);
  int x = deep_leaf;
  deep_leaf = -1;
  prep(x, -1, marked);

  int y = deep_leaf;

  return std::make_pair(x, y);
};

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  int n;
  std::cin >> n;
  a.resize(n);
  f.resize(n);
  g.resize(n);
  depth.resize(n);
  par.resize(n);
  vis.resize(n);

  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;

    --u;
    --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  /// find diamater

  int roota = 0, rootb = 0;

  int deep_leaf = -1;

  std::tie(roota, rootb) = diamater_dfs(0);
  int64_t diamater_len = depth[rootb];

  auto f1 = diamater_dp(roota);
  auto f2 = diamater_dp(rootb);
  int64_t ans = diamater_len;
  {
    vis[roota] = true; vis[rootb] = true;
    int u = rootb;
    while (u != -1) {
      int p = par[u];
      if (p != -1)
        ans = std::max(f1[u] + f2[p], ans);

      vis[u] = true;
      u = p;
    }
  }
  {
    for (int i = 0; i < n; ++i) {
      // std::cout << i << ' ' << vis[i] << '\n';
      if (vis[i])
        continue;
      auto [x, y] = diamater_dfs(i, true);
      // for (int j = 0; j < n; ++j) std::cout << vis[j] << ' '; std::cout << '\n';

      // std::cout << i << ' ' << depth[y] << '\n';

      ans = std::max(ans, diamater_len + depth[y]);
    }
  }

  std::cout << ans;
}
