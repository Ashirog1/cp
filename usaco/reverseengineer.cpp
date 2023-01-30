#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int tc; std::cin >> tc;
  while (tc--) {
    int N, M; std::cin >> N >> M;
    std::vector inputs(M, std::vector<bool>(N, false));
    std::vector<bool> outputs(M, false);
    for (int i = 0; i < M; ++i) {
      std::string in; char out; std::cin >> in >> out;
      for (int j = 0; j < N; ++j) {
        inputs[i][j] = (in[j] == '1');
      }
      outputs[i] = (out == '1');
    }
    std::vector<bool> passed(M);
    while (true) {
      bool foundcut = false;
      for (int bit = 0; bit < N; ++bit) {
        for (int v = 0; v < 2; ++v) {
          bool iscluster = true;
          bool isexist = false;
          bool out = false;
          for (int i = 0; i < M; ++i) {
            if (passed[i]) continue;

            if (inputs[i][bit] == v) {
              if (isexist == false) {
                isexist = true;
                out = outputs[i];
              } else {
                if (outputs[i] != out) {
                  iscluster = false;
                }
              }
            }
          }
          if (iscluster and isexist) {
            foundcut = true;
            for (int i = 0; i < M; ++i) {
              if (passed[i]) continue;
              if (inputs[i][bit] == v) {
                passed[i] = true;
              }
            }
          }
        }
      }
      if (not foundcut) break;
    }

    bool good = true;
    for (int i = 0; i < M; ++i) {
      if (not passed[i]) {
        good = false;
      }
    }
    std::cout << (good ? "OK\n" : "LIE\n");
  }

}
