#include "bits/stdc++.h"

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  std::cout << 2 << ' ' << 1000 << ' ';
  for (int i = 1; i <= 1000; ++i) {
    std::cout << i << ' ' << i + 1000 << ' ';
  }
}
