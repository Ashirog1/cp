#include "bits/stdc++.h"

int edge[1005][1005];
int size[1005][1005];
int adj_size[1005];

std::vector<int> adj[1005];

int root;

void dfs(int u, int p) {
  for (int v : adj[u])
    if (v != p) {
      if (root != u and edge[root][u] != edge[root][v]) {
        std::cout << -1;
        exit(0);
      }
      dfs(v, u);
    }
}

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  int n;
  std::cin >> n;
  for (int _ = 1; _ <= n; ++_) {
    std::string s;
    std::cin >> s;

    int k = 0;
    int i = 0;
    int index = 1;
    bool ele = false;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ',') {

      } else if (s[i] == '-') {
        ele = false;
        ++index;
      } else if (s[i] == ':') {
        ele = true;
      } else {
        int j = i;
        int tmp = 0;
        while (j < s.size() and '0' <= s[j] and s[j] <= '9') {
          tmp = tmp * 10 + s[j] - '0';
          ++j;
        }
        --j;
        i = j;

        if (ele) {
          edge[_][tmp] = index;
          size[_][index]++;
        }
        // std::cout << tmp << ' ';
      }
    }
    adj_size[_] = index;

    // std::cout << '\n';
  }
  // for (int i=0; i < n; ++i) {
  //   std::cout << adj[i].size() << '\n';
  //   for (auto se : adj[i]) {
  //     for (auto it : se) {
  //       std::cout << it << ' ';
  //     }
  //     std::cout << '\n';
  //   }
  //   std::cout << '\n';
  // }
  std::vector<bool> erased(n + 5);
  std::vector<int> cur_leaf;
  for (int i = 1; i <= n; ++i)
    if (adj_size[i] == 1) {
      // std::cout << i << '\n';
      cur_leaf.push_back(i);
    }

  std::vector<std::pair<int, int>> ans;

  for (int _ = 0; _ < cur_leaf.size(); ++_) {
    int leaf = cur_leaf[_];
    erased[leaf] = true;
    // std::cout << leaf << '\n';
    // for (int i = 0; i < cur_leaf.size(); ++i) std::cout << cur_leaf[i] << ' '; std::cout << '\n';
    for (int i = 1; i <= n; ++i) {
      int adj_cnt = 0;
      if (not erased[i]) {
        if (edge[i][leaf]) {
          int ind = edge[i][leaf];
          size[i][ind]--;
          if (size[i][ind] == 0) {
            adj_size[i]--;
            ans.emplace_back(leaf, i);
            if (adj_size[i] == 1)
              cur_leaf.push_back(i);
          }
        }
      }
    }
  }
  for (auto [x, y] : ans) { adj[x].push_back(y); adj[y].push_back(x); }
  for (int i = 1; i <= n; ++i) {
    root = i;
    dfs(i, -1);
  }

  if (ans.size() == n - 1) {
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans)
      std::cout << x << ' ' << y << '\n';
  } else {
    std::cout << -1;
  }
}
