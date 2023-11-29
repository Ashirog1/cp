#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> A(n), f(n, -1), g(n, -1);
  std::vector<std::vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
    --A[i];
    if (i)
      adj[A[i]].push_back(i);
  }
  int ans = 0;
  if (A[0] != 0)
    ++ans, A[0] = 0;
  auto dfs = [&](auto dfs, int u) -> int {
    int ret = 0;
    for (int v : adj[u]) {
      int fv = dfs(dfs, v);
      if (u == 0 and fv == k) {
        ++ans;
      } else if (u != 0 and fv == k - 1) {
        ++ans;
      } else {
        ret = std::max(ret, fv + 1);
      }
    }
    return ret;
  };
  dfs(dfs, 0);
  std::cout << ans;
}