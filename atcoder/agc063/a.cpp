#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  std::vector<int> cnt(n + 5);
  std::vector<int> posA, posB;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'A') posA.emplace_back(i);
    else posB.emplace_back(i);
  }
  std::reverse(posA.begin(), posA.end());
  std::reverse(posB.begin(), posB.end());
  int cur_mex = 0;
  for (int k = 1; k <= n; ++k) {
    if (k & 1) {
      if (posB.size()) {
        cnt[posB.back()]++;
        posB.pop_back();
      }
    } else {
      if (posA.size()) {
        cnt[posA.back()]++;
        posA.pop_back();
      }
    }
    while (cnt[cur_mex]) ++cur_mex;
    if (s[cur_mex] == 'A') std::cout << "Alice\n";
    else std::cout << "Bob\n";
  }
}
