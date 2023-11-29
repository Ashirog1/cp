#include "bits/stdc++.h"

int main() {
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    if (fork() == 0) {
      ans ++;
      std::cout << i << '\n';
      std::cout << "check\n";
    }
  }
}