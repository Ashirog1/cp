#include <bits/stdc++.h>

using namespace std;

map<pair<int64_t, int64_t>, bool> cache;

bool f(int64_t n, int64_t m) {
  if (n > m) swap(n, m);
  if (cache.find({n, m}) != cache.end()) return cache[{n, m}];
  if (m % n == 0) {
    return cache[{n, m}] = true;
  }
  bool good = false;
  for (int64_t tc = n; tc <= m; tc += n) {
    if (f(n, m - tc) == 0) {
      good = true;
    }
  }
  if (good) {
    return cache[{n, m}] = 1;
  }
  return cache[{n, m}] = 0;
}

int main() {
  for (int i = 1; i <= 10; ++i) {
    for (int j = i; j <= 50; ++j) {
      cout << f(i, j) << ' ' << i << ' ' << j << ' ' << __gcd(i, j) << '\n';
    }
  }
}