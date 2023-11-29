#include "bits/stdc++.h"
using namespace std;
int a[105][105];
int main() {
  int n, m; cin >> n >> m;

  int id = 0;

  for (int i = 3; i <= m; i += 5) {
    for (int j = 1; j <= n; ++i) {
      a[j][i] = -1;
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (a[i][j] == -1) continue;
      if (a[i][j] != 0) continue;
      assert(a[i][j+1] == 0);
      ++id;
      a[i][j] =id; a[i][j+1] = id;
    }
  }
  
  for (int i = 1; i <= n; ++i) {for (int j = 1; j <= m; ++j) {
    cout << a[i][j] << ' ' ;
    }   
  cout << '\n';
  }
}