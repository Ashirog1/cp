#include "bits/stdc++.h"

int main() {
  std::ios_base::sync_with_stdio(0);
  const auto f = [&](int64_t b, int64_t n) {
    int64_t ans = 0;
    //std::cout << b << '\n';
    if (b == 1) return (int64_t)0;
    while (n) {
      ans += n % b;
      n /= b;
    }
    return ans;
  };
  const auto factorize = [&](int64_t n) {
    std::vector<int64_t> d; d.push_back(1);
    for (int i = 2; 1ll * i * i <= n; ++i) {
      if (n % i == 0)
        d.push_back(i);
    }
    if (n > 0)
    d.push_back(n);
    return d;
  };
  int64_t n, s;
  std::cin >> n >> s;


  for (int64_t b = 2; 1ll * b * b <= n; ++b) {
    if (f(b, n) == s) {
      std::cout << b;
      return 0;
    }
  }
  /*
    /// p x + q = n, p + q = s
    => p (x-1) = n - s
  */
  int64_t ans = -1;
  auto d = factorize(n - s);

  for (auto b : d) {
    if (f(b + 1, n) == s) {
      if (ans == -1) ans = b + 1;
      else ans = std::min(ans, b + 1);
    }
  }
  std::cout << ans;
}