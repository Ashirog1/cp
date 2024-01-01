#include <bits/stdc++.h>
std::bitset<5 * 1000> comp[5 * 1000];
int N, M;
std::array<int, 4> dx = {1, -1, 0, 0};
std::array<int, 4> dy = {0, 0, -1, 1};
int index(int u, int v) { return u * M + v; }
bool inside(int u, int v) { return 0 <= u and u < N and 0 <= v and v < M; }
void solve() {
  std::cin >> N >> M;
  std::vector<std::string> S(N);
  for (auto &s : S)
    std::cin >> s;
  std::vector<int> vis(N * M);
  /// helper lambda
  int ncomp = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (S[i][j] == '.') {
        std::queue<std::pair<int, int>> Q;
        const auto conv = [&](int u, int v) { return (N + u - i - 1) * 2 * M + (M + v - j); };
        Q.emplace(i, j);
        comp[ncomp].set(conv(i, j));
        while (Q.size()) {
          auto [u, v] = Q.front();
          Q.pop();
          vis[index(u, v)] = true;
          // std::cout << u << ' ' << v << '\n';
          // ][(n+a-i-1)*2*m+(m+b-j-1
          for (int t = 0; t < 4; ++t) {
            int x = u + dx[t], y = v + dy[t];
            if (inside(x, y) and S[x][y] == '.' and comp[ncomp].test(conv(x, y)) == 0) {
              comp[ncomp].set(conv(x, y));
              Q.emplace(x, y);
            }
          }
        }
        ++ncomp;
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < ncomp; ++i) {
    bool good = true;
    /// test bit
    // std::string s = "";
    // for (int j = 0; j < 50; ++j) {
    //   s += (comp[i].test(j) ? '1' : '0');
    // }
    // std::cout << s << '\n';
    for (int j = 0; j < ncomp; ++j) {
      if (i == j)
        continue;
      if ((comp[i] & comp[j]) == comp[i])
        good = false;
    }
    if (good)
      ret++;
  }

  /// clean
  std::cout << ret << '\n';
  for (int c = 0; c < ncomp; ++c) {
    comp[c].reset();
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int tc;
  std::cin >> tc;
  while (tc--) {
    solve();
  }
}