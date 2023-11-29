#include "bits/stdc++.h"

std::vector<std::string> all_chr;

class lazySeg {

};

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  const auto crossing = [&](const std::string&a, const std::string&b) {
    std::string c;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) c += a[i];
      else {
        for (char v : {'J', 'O', 'I'}) {
          if (v == a[i] or v == b[i]) continue;
          c += v;
        }
      }
    }
    return c;
  };

  int n; std::cin >> n;
  {
    std::string str;
    std::cin >> str; all_chr.push_back(str);
    std::cin >> str; all_chr.push_back(str);
    std::cin >> str; all_chr.push_back(str);

    int tmp = 0;
    std::vector<std::string> nxt;
    while (true) {

      for (int i = 0; i < all_chr.size(); ++i) {
        auto c = crossing(all_chr[i], all_chr[tmp]);

        /// check
        bool oke = true;
        for (int j = 0; j < all_chr.size(); ++j) {
          if (all_chr[j] == c) oke = false;
        }
        if (oke) nxt.push_back(c);
      }

      for (auto c : nxt) {all_chr.push_back(c);}

      nxt.clear();

      ++tmp;
      if (tmp >= all_chr.size()) break;
    }


    assert(all_chr.size() <= 9);
    // for (auto c : all_chr) std::cerr << c << '\n';
  }

  int q; std::cin >> q;
  std::string str; std::cin >> str;
}
