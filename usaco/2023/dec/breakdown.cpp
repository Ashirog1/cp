#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int N, K;
  std::cin >> N >> K;
  std::vector<std::vector<int>> weight(N, std::vector<int>(N, -1));
  auto current = weight;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> weight[i][j];
    }
  }
  std::vector<std::pair<int, int>> query;
  for (int i = 0; i < N * N; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    query.emplace_back(u, v);
  }
  std::reverse(query.begin(), query.end());
  std::vector<std::array<int, 8>> f(N, std::array<int, 8>{1e8 + 5});
  auto g = f;
  std::vector<std::vector<int>> best(N, std::vector<int>(N, 1e8 + 5));
  std::vector<int> ans;
  for (const auto &[u, v] : query) {
    for (int k = 1; k < K; ++k) {
      
    }
    current[u][v] = weight[u][v];
  }
}
