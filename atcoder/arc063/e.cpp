#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<vector<int>> g(n);
  for  (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    g[u].push_back(v); g[v].push_back(u);
  }
  int k; cin >> k;
  vector<int> d(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < k; ++ i) {
    int v, p; cin >> v >> p; --v; d[v] = p;
    pq.emplace(d[v], v);
  }
  while (not pq.empty()) {
    int u = pq.top().second; pq.pop();
    for (int v : g[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        pq.emplace(d[v], v);
      } else {
        if (abs(d[v] - d[u]) != 1) {
          cout << "No\n";
          return 0;
        }
      }
    }
  }
  cout << "Yes\n";
  for (auto it : d) cout << it << '\n';
}