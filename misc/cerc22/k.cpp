#include <bits/stdc++.h>
#define set asdfadsfasfd
using namespace std;
const int maxn = 1e6 + 5;
int f[maxn][2];
void set(int&x, int y) {
  if (x == -1) x = y;
  else x = min(x, y);
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int64_t a, b, n;
  cin >> a >> b >> n;

  int64_t lm = a * b / __gcd(a, b); 

  int opa = 1e9, opb = 1e9;

  for (int i = a; i <= n; i += a) {
    if ((i + 1) % b == 0) {
      opb = i; break;
    }
  }

  for (int i = b; i <= n; i += b) {
    if ((i + 1) % a == 0) {
      opa = i; break;
    }
  }

  if (lm > n) {
    cout << n / a + n / b;
    return 0;
  }
  memset(f, -1, sizeof f); 
  f[lm][0] = f[lm][1] = 0;
  for (int i = lm; i <= n; ++i) {
    int rem = n - i;
    int costa = (opa + 1) / a + opa / b;
    int costb = (opb + 1) / b + opb / a;
    if (f[i][0] == -1) f[i][0] = 1e9;
    if (f[i][1] == -1) f[i][1] = 1e9;
    if (i + opa <= n) {
      set(f[i + opa][0], min(f[i][0], f[i][1]) + costa);
    } else {
      set(f[n][0], min(f[i][0], f[i][1]) + (rem + 1) / a + rem / b);
    }
    if (i + opb <= n) {
      set(f[i + opb][1], min(f[i][0], f[i][1]) + costb);
    } else {
      set(f[n][1], min(f[i][0], f[i][1]) + (rem + 1) / b + rem / a);
    }
    // cout << f[i][0] << ' ' << f[i][1] << '\n';
  }
  int ans = 1e9;
  if (f[n][0] != -1) ans = f[n][0];
  if (f[n][1] != -1) ans = min(f[n][1], ans);
  cout << min(f[n][0], f[n][1]) + lm / a + lm / b;
}