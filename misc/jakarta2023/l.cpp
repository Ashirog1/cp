#include <bits/stdc++.h>

int calc(std::string s) {
  int n = s.size();
  std::vector<std::vector<int>> f(n, std::vector<int>(n, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (i == j) {
        f[i][j] = 1;
      } else {
        f[i][j] = std::max(f[i + 1][j], f[i][j - 1]);
        if (s[i] == s[j]) f[i][j] = std::max(f[i][j], f[i + 1][j - 1] + 2);
      }
    }
  } 
  return f[0][n - 1];
}

int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  if (k < n / 2 or k == n) {
    std::cout << -1;
    return 0 ;
  }
  int need = n / 2;
  std::string ans;
  std::string L, R;
  int needl = (k - need) / 2;
  int needr = (k - need) - needl;
  for (int i = 0; i < needl; ++i) {
    L += "()";
  }
  for (int i = 0; i < needr; ++i) {
    R += "()";
  }
  int rem = (n - L.size() - R.size()) / 2;
  for (int i = 0; i < rem; ++i) {
    ans += '(';
  }
  for (int i = 0; i < rem; ++i) {
    ans += ')';
  }
  ans = L + ans + R;
  std::cout << ans << '\n';
  // std::cout << calc(ans);
}