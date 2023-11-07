#include "bits/stdc++.h"
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int maxa = 1e6 + 5;
std::vector<int> primes;
int not_prime[maxa];
int main() {
  std::ios_base::sync_with_stdio(0);
  for (int i = 2; i < maxa; ++i) {
    if (not_prime[i]) continue;
    for (int64_t j = 1ll * i * i; j < maxa; j += i) {
      not_prime[j] = true;
    }
  }
  for (int i = 2; i < maxa; ++i) if (!not_prime[i]) primes.push_back(i);
  int n; std::cin >> n; std::vector<int64_t> a(n); 
  for (int i = 0; i < n; ++i) { std::cin >> a[i]; }
  std::shuffle(a.begin(), a.end(), rng);
  std::vector<int64_t> candidates;
  candidates.push_back(2);
  const auto scan = [&](int64_t v) {
    for (auto divs : primes) {
      if (v % divs == 0)  candidates.push_back(divs);
      if (divs > v) break;
      while (v % divs == 0) {
        v /= divs;
      }
    }
    if (v != 1) candidates.push_back(v);
  };
  for (int i = 0; i < 100 and i < n; ++i) {
    scan(a[i]); scan(a[i] + 1); if (a[i] > 2) scan(a[i] - 1);
  } 
  std::sort(candidates.begin(), candidates.end());
  candidates.erase(std::unique(candidates.begin(), candidates.end()), candidates.end());
  int64_t ans = n + 5;
  for (auto cand : candidates) {
    int64_t ret = 0;
    for (auto v : a) {
      ret += std::min((v / cand > 0 ? v % cand : INT_MAX), cand - (v % cand));
    }
    // std::cerr << cand << ' ' << ret << '\n';
    ans = std::min(ans, ret);
  }
  std::cout << ans;
}