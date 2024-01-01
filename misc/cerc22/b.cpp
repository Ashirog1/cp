#include <bits/stdc++.h>
using namespace std;
int cache[1 << 10];
bool ban[1 << 10];
int f(int state) {
  if (cache[state]!=-1) return cache[state];
  int win = 1;
  for (int t = 0; t < n; ++t) {
    
  }
}
void solve() {
  fill(begin(ban),end(ban), 0);
  memset(cache, -1, sizeof cache);
  int n, c; cin >> n >> c;
  string s, t; cin >> s >> t;
  int init = 0;
  for (int i = 0; i < s.size(); ++i) {
    init += (s[i] == t[i]) * (1 << i);
  }
  cout << (f(init) ? "Alice\n" : "Bob\n");
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
}