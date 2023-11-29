#include "bits/stdc++.h"

const int maxn = 1e5 + 5;

int nprime[maxn], cnt[15];

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  std::vector<int> pr;
  for (int i = 2; i < maxn; ++i) {
    if (not nprime[i]) {
      for (int j = i * 2; j < maxn; j += i) {
        nprime[j] = true;
      }
    }
  }
  for (int i = 2; i <= maxn; ++i) {
    if (not nprime[i]) pr.push_back(i);
  }

  int n, k; std::cin >> n >> k;
  int nn = n;

  for (int i = 0; i < (int)pr.size(); ++i) {
    if (pr[i] >= 10) {
      if (n % pr[i] == 0) {
        std::cout << -1;
        return 0;
      }
    } else {
      while (n % pr[i] == 0) {
        n /= pr[i];
      }
    }
  }

  if (n != 1) {std::cout << -1; return 0;}
  int cur = 0;
  for (int i = 9; i >= 2; --i) {
    while (nn % i == 0) {
      nn /= i;
      ++cur;
      ++cnt[i];
    }
  }

  if (cur > k) {
    std::cout << -1;
    return 0;
  }

  while (cur < k) {
    std::cout << 1;
    ++cur;
  }
  for (int i = 2; i <= 9; ++i) {
    while (cnt[i]) {
      std::cout << i;
      --cnt[i];
    }
  }

}
