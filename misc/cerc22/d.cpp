#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int len[maxn];
vector<vector<pair<int, int>>> g(1);
int W;

pair<int, int> dfs(int u, int cur_len) {
  int cut = 0;
  int rem = -1;
  vector<int> a;
  for (auto [v, w] : g[u]) {
    auto tmp = dfs(v, w);
    cut += tmp.first;
    a.push_back(tmp.second);
  }
  sort(a.begin(), a.end());
  int sum = accumulate(a.begin(), a.end(), 0);
  while (sum > W) {
    sum -= a.back(); a.pop_back();
    ++cut;
  }
  int tot_len = sum + cur_len;
  while (tot_len > W) {
    ++cut;
    tot_len -= W;
  }
  rem = tot_len;

  return {cut, rem};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> W;
  int n = 0;
  function<void(int)> input = [&](int par) {
    int m, foo;
    cin >> m >> foo;
    if (par == -1) len[0] = m;
    if (par != -1)
      g[par].emplace_back(n, m);
    int now = n;
    while (foo--) {
      g.emplace_back();
      ++n;
      input(now);
    }
  };

  input(-1);
  auto ans =  dfs(0, len[0]);
  cout << ans.first + 1;
}
