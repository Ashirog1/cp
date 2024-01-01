#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  const int mod = 1e9 + 9, base = 7;
  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector<int> POW(N + 5);
  POW[0] = 1;
  for (int i = 1; i < POW.size(); ++i)
    POW[i] = 1ll * base * POW[i - 1] % mod;
  std::vector<std::string> S(N);
  for (auto &s : S)
    std::cin >> s;
  std::vector<std::array<std::vector<int>, 4>> POS(M);
  std::vector<std::array<int, 4>> HASH(M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      POS[j][S[i][j] - 'A'].push_back(i);
    }
  }
  /// calc Hash
  for (int j = 0; j < M; ++j) {
    for (int t = 0; t < 4; ++t) {
      int h = 0;
      for (auto i : POS[j][t]) {
        (h += POW[i + 1]) %= mod;
        // std::cout << i << ' ';
      }
      // std::cout << '\n';
      HASH[j][t] = h;
    }
  }
  /// find answer
  int ret = -1;
  int hash_all = 0;
  for (int i = 0; i < N; ++i)
    (hash_all += 1ll * K * POW[i + 1] % mod) %= mod;
  for (int i = 0; i < N; ++i) {
    int req_hash = (hash_all - POW[i + 1] + mod) % mod;
    int sum_hash = 0;
    for (int j = 0; j < M; ++j) {
      for (char t = 'A'; t <= 'D'; ++t) {
        if (t != S[i][j]) {
          (sum_hash += HASH[j][t - 'A']) %= mod;
        }
      }
    }
    if (sum_hash == 1ll * K * req_hash % mod) {
      ret = i;
    }
  }
  // assert(ret != -1);
  std::cout << ret + 1;
}