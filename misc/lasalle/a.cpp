#include "bits/stdc++.h"
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0); std::cin.tie(0);
  int n; cin >> n;

  int64_t f = 0, g = 0;  
  const auto get = [&](int64_t f, char c, int64_t v) {
    if (c == '+') return f+v;
    if (c == '-') return f-v;
    else return f*v;
  };

  for (int i = 1; i <= n; ++i) {
    char c1, c2; int v1, v2;

    cin >> c1 >> v1 >> c2 >> v2;

    std::vector<int64_t> tmp{get(f,c1,v1), get(f,c2,v2), get(g,c1,v1), get(g,c2,v2)};
    sort(tmp.begin(), tmp.end()); f = tmp[3]; g = tmp[0];
  }
  cout << f;
}