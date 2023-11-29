#include "bits/stdc++.h"

char c[9 * 9];
int possible[9 * 9];
int a[9 * 9];
std::bitset<81> available, next;
std::bitset<81> near[9 * 9];

int conv(int u, int v) { return u * 9 + v; }

bool init() {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {

      /// find adj

      for (int k = 0; k < 9; ++k) {
        if (k != j)
          near[conv(i, j)].set(conv(i, k));
        if (k != i)
          near[conv(i, j)].set(conv(k, j));
      }
      for (int k = 0; k < 9; ++k) {
        for (int t = 0; t < 9; ++t) {
          if (k == i and t == j)
            continue;
          if (k / 3 == i / 3 and t / 3 == j / 3) {
            near[conv(i, j)].set(conv(k, t));
          }
          if ((k - i) * (k - i) + (t - j) * (t - j) == 5 or std::max(abs(k - i), abs(j - t)) == 1) {
            near[conv(i, j)].set(conv(k, t));
          }
        }
      }
    }
  }

  /// unvalid init state
  for (int i = 0; i < 81; ++i) {
    if (a[i] != 0) {
      for (int l = near[i]._Find_first(); l < near[i].size(); l = near[i]._Find_next(l)) {
        // std::cout << i << ' ' << l << '\n';
        if (a[l] == a[i]) return false;
        possible[l] &= ~(1 << a[i]); 

      }
    } else {
      available.set(i, 1);
    }
  }

  return true;
}

void print() {

    for (int i = 0; i < 81; ++i) {
      std::cout << a[i];
      if ((i + 1) % 9 == 0)
        std::cout << '\n';
    }
}

void attempt() {
  int best = -1;
  print(); std::cout << '\n';
  std::cout << available.to_string() << '\n';

  for (int i = available._Find_first(); i < available.size(); i = available._Find_next(i)) {
    if (best == -1 or __builtin_popcount(possible[i]) < __builtin_popcount(possible[best])) {
      best = i;
    }
  }
  if (best == -1) {
    if (available.count() != 0) return;
    print();
    exit(0);
  }
  next = available & near[best];
  available.set(best, 0);
  for (int v = 1; v <= 9; ++v) {
    if (possible[best] >> (v - 1) & 1) {
      a[best] = v;
      possible[best] &= ~(1 << (v - 1));
      for (int l = next._Find_first(); l < next.size(); l = next._Find_next(l)) {
        possible[l] &= ~(1 << (a[best] - 1));
      }
      attempt();


      possible[best] |= (1 << (v - 1));
      for (int l = next._Find_first(); l < next.size(); l = next._Find_next(l)) {
       possible[l] |= (1 << (a[best] - 1));
      }
      a[best] = 0;
    }
  }

  available.set(best, 1);
  a[best] = 0;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  for (int i = 0; i < 81; ++i) {
    std::cin >> c[i];
    a[i] = c[i] - '0';

    if (a[i] == 0)
      available.set(i, 1);
    
    possible[i] += (1 << 9) - 1;
  }
  /// check initial board
  if (not init()) {
    std::cout << "NO SOLUTION";
    return 0;
  }
  attempt();
  std::cout << "NO SOLUTION\n";
}