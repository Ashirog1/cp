#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 4;
  for (int m = 0; m < (1 << n); ++m) {
    for (int m2 = m + 1; m2 < (1 << n); ++m2) {
      if (__builtin_popcount(m^m2) == 1) {
        cout << m << ' ' << m2 << '\n';
      }
    }
  }  
}