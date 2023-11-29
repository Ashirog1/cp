#include "bits/stdc++.h"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(0);
  int n = rng() % atoi(argv[1]) + 1;
  int m = rng() % (n * 5) + 1;
  std::vector<std::pair<int, int>> edges;
  std::cout << n << ' ';
  while (m--) {
    int u = rng() % n + 1, v = rng() % n + 1;
    if (u > v) std::swap(u, v);
    if (u != v) {
      edges.emplace_back(u, v);
    }
  }
  std::sort(edges.begin(), edges.end());
  edges.erase(std::unique(edges.begin(), edges.end()), edges.end());

  std::cout << edges.size() << '\n';
  for (const auto[x, y] : edges) {
    std::cout << x << ' ' << y << '\n';
  }
}

