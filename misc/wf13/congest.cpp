#include <bits/stdc++.h>

int32_t main(int32_t argc, char *argv[]) {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  int n, m, c;
  std::cin >> n >> m >> c;
  std::vector<std::tuple<int, int, int>> edges(m);
  std::vector<std::vector<int>> adj(n);
  {
    int cnt_edge = 0;
    for (auto &[u, v, w] : edges) {
      std::cin >> u >> v >> w;
      --u;
      --v;

      adj[u].push_back(cnt_edge);
      adj[v].push_back(cnt_edge);
      ++cnt_edge;
    }
  }
  std::vector<int> starts(c), cnt_starts(n);
  for (auto &start : starts) {
    std::cin >> start;
    --start;
    ++cnt_starts[start];
  }
  {
    const int64_t inf = 1e18 + 5;
    std::vector<int64_t> d(n, inf);
    using pq_type = std::pair<int64_t, int>;
    std::priority_queue<pq_type, std::vector<pq_type>, std::greater<pq_type>> pq;
    pq.emplace(0, 0);
    d[0] = 0;
    while (pq.size()) {
      auto [dist, u] = pq.top();
      pq.pop();
      if (dist != d[u])
        continue;

      for (auto idx : adj[u]) {
        auto [U, V, W] = edges[idx];
        int v = U + V - u;
        if (d[v] > d[u] + W) {
          d[v] = d[u] + W;
          pq.emplace(d[v], v);
        }
      }
    }

    std::sort(starts.begin(), starts.end(), [&](int u, int v) { return d[u] < d[v]; });

    /// imlement flow by hand
    std::vector<int> ori_cap;
    std::vector<int> cap;
    std::vector<std::vector<int>> g(n), eidx(n);
    std::vector<int> seen(n);

    const auto addEdge = [&](int u, int v) {
      g[u].push_back(v);
      eidx[u].push_back(cap.size());
      cap.push_back(1);
      g[v].push_back(u);
      eidx[v].push_back(cap.size());
      cap.push_back(0);
    };

    for (const auto &[u, v, w] : edges) {
      if (d[v] == d[u] + w) {
        addEdge(v, u);
      }
      if (d[u] == d[v] + w) {
        addEdge(u, v);
      }
    }

    auto flow = [&](auto &flow, int u) -> int {
      // std::cout << u << '\n';
      if (u == 0)
        return 1;
      if (seen[u])
        return 0;
      seen[u] = 1;
      for (int i = 0; i < g[u].size(); ++i) {
        // std::cout << i << ' ' << g[u][i] << '\n';
        if (cap[eidx[u][i]]) {
          if (flow(flow, g[u][i])) {
            cap[eidx[u][i]] = 0;
            cap[eidx[u][i] ^ 1] = 1;
            return true;
          }
        }
      }
      return false;
    };

    int ret = 0;
    ori_cap = cap;
    for (int i = 0; i < starts.size(); ++i) {
      if (i and d[starts[i]] != d[starts[i - 1]]) {
        cap = ori_cap;
      }

      seen = std::vector<int>(n, 0);
      // std::cout << starts[i] << '\n';
      ret += flow(flow, starts[i]);
    }
    std::cout << ret;
  }
}