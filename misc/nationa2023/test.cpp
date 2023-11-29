#include "bits/stdc++.h"

int main() {

  int x = (1 << 6) + (1 << 2) + (1 << 0);

  for (int y = x; y >= 0; ) {
    std::cout << __builtin_ctz(y) << '\n';
    y -= 1 << (__builtin_ctz(y));
  }
}