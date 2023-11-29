#include <bits/stdc++.h>
class RollingHash {
const int base = 37, mod = 1e9 + 9;
  std::vector<int64_t> h, POW;
public:
  RollingHash(const std::string & s) {
    h.assign(s.size(), 0); POW.assign(s.size() + 5, 0);
    POW[0] = 1;
    for (int i = 1; i < POW.size(); ++i) POW[i] = 1ll * POW[i-1] * base % mod;
    for (int i = 0; i < s.size(); ++i) {
      h[i] = ((i ? h[i - 1] : 0ll) * base + s[i] - 'a' + 1) % mod;
    }
  }
  int64_t getValue(int l , int r) {
    return ((h[r] - (l ? h[l - 1] : 0ll) * POW[r - l + 1]) + 1ll * mod * mod) % mod;
  }
};
int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  const auto factorize = [&](int w) {
    std::vector<int> d; d.push_back(1);
    for (int i = 2; i * i <= w; ++i) {
      if (w % i == 0) {
        d.push_back(i);
        if (i != w / i) d.push_back(w / i);
      }
    }
    return d;
  };
  std::string w; std::cin >> w;
  /// check all equal case
  {
    auto b = w[0];
    bool allEqual = true;
    for (auto c : w) {
      if (c != b) {
        allEqual = false;
      }
    }
    if (allEqual) {
      std::cout << w.size() << '\n' << 1;
      return 0;
    }
  }
  RollingHash h(w);
  auto lens = factorize(w.size());
  bool good = false;
  for (auto len : lens) {
    auto baseHash = h.getValue(0, len - 1);
    bool isEqual = true;
    for (int i = len; i + len - 1 < w.size(); i += len) {
      if (h.getValue(i, i + len - 1) != baseHash) isEqual = false;
    }
    if (isEqual) {good = true;}
  }
  if (good) {
    std::cout << 2 << '\n';
    /// @brief need to check for all sufix/prefix of w
    std::vector<bool> goodPrefix(w.size(), 1), goodSuffix(w.size(), 1);
    goodPrefix[0] = 1; goodSuffix[w.size() - 1] = 1;
    for (int len = 1; len * 2 <= w.size(); ++len) {
      auto baseHash = h.getValue(0, len - 1);
      bool stillEqual = true;
      for (int i = len; i + len - 1 < w.size(); i += len) {
        if (h.getValue(i, i + len - 1) != baseHash) {
          stillEqual = false;
          break;
        } else {
          goodPrefix[i + len - 1] = false;
        }
      }
      /// check suffix
      stillEqual = true;
      baseHash = h.getValue(w.size() - len, w.size() - 1);
      for (int i = w.size() - len - 1; i - len + 1 >= 0; i -= len) {
        if (h.getValue(i - len + 1, i) != baseHash) {
          stillEqual = false;
          break;
        } else {
          goodSuffix[i - len + 1] = false;
        }
      }
    }
    int ret = 0;
    #ifdef LOCAL
    for (auto c : goodPrefix) std::cout << c << " "; std::cout << '\n';
    for (auto c : goodSuffix) std::cout << c << " "; std::cout << '\n';
    #endif 
    for (int i = 0; i + 1 < w.size(); ++i) {
      if (goodPrefix[i] and goodSuffix[i + 1]) ++ret;
    }
    std::cout << ret;
  } else {
    std::cout << 1 << '\n' << 1;
  }
}