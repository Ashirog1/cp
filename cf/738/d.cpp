#include "bits/stdc++.h"

class DSU {
public:
  std::vector<int> lab;

  DSU(int n) {
    lab.assign(n + 5, -1);
  }

  int find(int u) { return lab[u] < 0 ? u : lab[u] = find(lab[u]); }

  bool merge(int u, int v) {
    u = find(u); v = find(v);

    if (u == v) return false;
    if (-lab[v] > -lab[u]) std::swap(u, v);
    lab[u] += lab[v]; lab[v] = u;
    return true;
  }

  bool same(int u, int v) { return find(u) == find(v); }
};

int main() {
  std::ios::sync_with_stdio(0);


  int n, m1, m2; std::cin >> n >> m1 >> m2;

  DSU d1(n), d2(n);
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < m1; ++i) {
    int u, v; std::cin >> u >> v;
    d1.merge(u, v);
  }
  for (int i = 0; i < m2; ++i) {
    int u, v; std::cin >> u >> v;
    d2.merge(u, v);
  }

  std::vector<int> t1, t2;
  for (int i = 1; i <= n; ++i) {
    if (d1.same(1, i) and d2.same(1, i)) continue;
    if (!d1.same(1, i) and !d2.same(1, i)) {
      d1.merge(1, i); d2.merge(1, i);

      ans.emplace_back(1, i);
    } else if (d1.same(1, i)) {
      t1.push_back(i); 
    } else {t2.push_back(i);}
  }

  while (true) {
    if (t1.empty() or t2.empty()) break;
    int u = t1.back(), v = t2.back();

    if (d2.same(1,u)) {
      t1.pop_back(); continue;
    }
    if (d1.same(1,v)) {
      t2.pop_back(); continue;
    }
    /// quen dsu :((
    
    d1.merge(u, v); d2.merge(u, v);

    ans.emplace_back(u, v); t1.pop_back(); t2.pop_back();
  }

  std::cout << ans.size() << '\n';
  for (auto [u,v] : ans) std::cout << u << ' ' << v << '\n';
}
