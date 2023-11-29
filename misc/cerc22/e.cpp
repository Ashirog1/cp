#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
bool check(long double v) {
  int rv = round(v);
  return (abs(rv - v) <= eps);
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<long double> A(n), B(n), ret(n);
  vector<long long> res(n);
  for (auto&a:A) cin >> a;
  long double norm = *min_element(A.begin(), A.end());
  // cout << norm << '\n';
  for (int i = 0; i < n; ++i) {
    B[i] = (long double)1.0 * A[i] / norm;
  }
  const auto valid = [&]() {
    long double d = 0;
    long long gc = 0;
    for (int i = 0; i < n; ++i) {
      d += (long double)res[i] * res[i];
      gc = __gcd(gc, res[i]);
    }
    if (gc != 1) return false;
    d = (long double)sqrt((long double)1.0 * d);
    // cout << fixed << setprecision(10) << d << '\n';
    for (int i = 0; i < n; ++i) {
      long double v = 1.0 * (long double)res[i] / d;
      // cout << v << ' ';
      if (abs(v - A[i]) > eps) {
        return false;
      }
    }
    return true;
  };
  for (int k = 1; k <= 10000; ++k) {
    for (int i = 0; i < n; ++i) {
      ret[i] = 1.0 * B[i] * (long double)k;
      res[i] = round(ret[i]);
    }
    if (valid()) {
      for (auto&it : ret) {
        cout << round(it) << '\n';
      }
      return 0;
    }
  }
}