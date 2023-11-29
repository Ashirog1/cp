#include <bits/stdc++.h>
 
using namespace std;
 
struct DSU {
  vector<int> e;
 
  DSU(int n) { e = vector<int>(n, -1); }
 
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
 
  bool same_set(int a, int b) { return get(a) == get(b); }
 
  int size(int x) { return -e[get(x)]; }
 
  bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y];
    e[y] = x;
    return true;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u];
    ++deg[v];
  }
  set<array<int, 2>> vertices;
  for (int i = 0; i < n; ++i) {
    vertices.insert({deg[i], i});
  }
  vector<int> order;
  vector<int> degrees;
  vector<bool> active(n, true);
  auto remove = [&]() {
    auto top = *vertices.begin();
    int u = top[1];
    int degree = top[0];
    order.push_back(u);
    degrees.push_back(degree);
    active[u] = false;
    for (int v : g[u]) {
      if (active[v]) {
        vertices.erase({deg[v], v});
        --deg[v];
        vertices.insert({deg[v], v});
      }
    }
    vertices.erase({deg[u], u});
  };
  for (int i = 0; i < n; ++i) {
    remove();
  }
  reverse(order.begin(), order.end());
  reverse(degrees.begin(), degrees.end());
  active.assign(n, false);
  DSU dsu(n);
  int mx = 1;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int u = order[i];
    active[u] = true;
    for (int v : g[u]) {
      if (active[v]) {
        dsu.unite(u, v);
        mx = max(mx, dsu.size(u));
      }
    }
    ans = max(ans, 1ll * mx * degrees[i]);
  }
  cout << ans << '\n';
  return 0;
}