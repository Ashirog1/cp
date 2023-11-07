#include "bits/stdc++.h"

int main() {
  std::ios::sync_with_stdio(0);
  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto&i : a) std::cin >> i;
  std::stack<int> st;
  int64_t ans = 0;
  for (int l = n - 1; l >= 0; --l) {
    st.push(l);
    if (a[l] == 1) {
      int prv = 1;
      while (not st.empty() and a[st.top()] == prv++) {
        st.pop();
      }
      int r = (not st.empty() ? st.top() : n);
      ans += r - l;
      //std::cerr << l << ' ' << r << '\n';
    }
  }
  std::cout << ans;
}
