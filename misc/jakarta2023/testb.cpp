#include <bits/stdc++.h>

using namespace std;

int main() {
  string s; cin >> s;
  const auto conv = [&](string s) {
    int m = 0;
    for (int i = 0; i < s.size(); ++i) {
      m += (s[i] == '1') * (1 << i);
    }
    return m;  
  };
  const auto conv2 = [&](int m) {
    string s="";
    for (int i = 0; i < s.size(); ++i) {
      s += ((m >> i & 1) == 1 ? '1' : '0');
    }
    return s;
  };
  int m = conv(s);
  vector<int> d(1 << s.size(), -1), par(1 << s.size(), 0);queue<int> Q;
  Q.push(m);
  d[m] = 0;
  while (Q.size()) {
    auto u = Q.front(); Q.pop();
    //cout << u << '\n';
    for (int i = 0; i < s.size(); ++i) cout << (u >> i & 1); cout << " trace ";
    for (int i = 0; i < s.size(); ++i) cout << (par[u] >> i & 1);

    cout << '\n';
    for (int i = 0; i < s.size(); ++i) {
      int nxtm = u;
      if (u >> i & 1) {
        if (i + 1 < s.size()) {
          nxtm ^= (1 << (i + 1));
        }
        if (i) {
          nxtm ^= (1 << (i - 1));
        }
        if (d[nxtm] == -1) {
          d[nxtm] = d[u] + 1;
          par[nxtm] = u;
          Q.push(nxtm);
        }
      }
    }
  }
  cout << "not\n";
  for (int u = 0; u < (1 << s.size()); ++u) {
    if (d[u] != -1) continue;
    for (int i = 0; i < s.size(); ++i) cout << (u >> i & 1) ; cout <<  "trace ";
    // for (int i = 0; i < s.size(); ++i) cout << (par[u] >> i & 1);

    cout << '\n';
  }
}