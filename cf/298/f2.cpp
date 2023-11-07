#include "bits/stdc++.h"

int test(int x, int y) { return x >> y & 1; }

bool f[22][161052][1 << 5];
int n, m;
char ans[100][100];

class dp_state {
public:
  int col;
  int mask;
  int state;
};

char trace[22][161052][1 << 5];

const int base = 11;

int encode(std::vector<int> state) {
  while (state.size() < 5)
    state.push_back(0);
  int v = 0;
  for (int i = 0; i < state.size(); ++i) {
    v = v * base + state[i];
  }
  return v;
}

std::vector<int> decode(int v) {
  std::vector<int> state(5);

  for (int i = 4; i >= 0; --i) {
    state[i] = v % base;
    v -= state[i];
    v /= base;
  }

  return state;
}

dp_state next_state(dp_state cur, int mask) {
  dp_state ans = cur;
  ans.col = cur.col + 1;

  ans.mask = mask;

  auto state = decode(cur.state);

  for (int i = 0; i < n; ++i) {
    if (test(mask, i) == 1 and test(cur.mask, i) == 0) {
      state[i]++;
    }
  }
  ans.state = encode(state);
  return ans;
}

int calc(int mask) {
  int ans = test(mask, 0);
  for (int i = 1; i < n; ++i) {
    if (test(mask, i) == 1 and test(mask, i - 1) == 0) {
      ++ans;
    }
  }
  return ans;
}

std::vector<int> avail_mask[5];

int main(int argc, char*argv[]) {
  std::ios::sync_with_stdio(0);

  
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }

  std::cin >> n >> m;

  for (int mask = 0; mask < (1 << n); ++mask) {
    avail_mask[calc(mask)].push_back(mask);
  }

  std::vector<int> a(n + 5), b(m + 5);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  for (int i = 1; i <= m; ++i)
    std::cin >> b[i];

  std::vector<dp_state> current, next;

  current.reserve(100000); next.reserve(100000);

  const auto push = [&](dp_state cur, int mask) {
    if (f[cur.col][cur.state][cur.mask] == 1)
      return;
    /// compare with a
    auto s = decode(cur.state);
    for (int i = 0; i < 5; ++i) {
      if (s[i] > a[i]) return;
    }
    f[cur.col][cur.state][cur.mask] = 1;
    next.push_back(cur);
    trace[cur.col][cur.state][cur.mask] = mask;
  };

  push({0, 0, 0}, 0);
  std::swap(current, next);
  next.clear();

  for (int i = 0; i < m; ++i) {
    for (auto mask : avail_mask[b[i + 1]]) {
      // std::cout << mask << '\n';
      for (int j0 = 0; j0 <= (i + 1) / 2; ++j0) {
        for (int j1 = 0; j1 <= (i + 1) / 2; ++)
      }
    }
    // std::cout << '\n';
    std::swap(current, next);
    next.clear();
  }

  std::vector<int> tmp;
  for (int i = 0; i < n; ++i)
    tmp.push_back(a[i]);
  int cur_mask = -1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    if (f[m][encode(tmp)][mask] == 1) {
      cur_mask = mask;
      break;
    }
  }
  // assert(cur_mask!=-1);

  for (int j = m; j >= 1; --j) {
    for (int r = 1; r <= n; ++r) {
      ans[r][j] = (test(cur_mask, r - 1) ? '*' : '.');
    }
    // std::cout << cur_mask << '\n';
    int add_mask = trace[j][encode(tmp)][cur_mask];

    for (int i = 0; i < n; ++i) {
      if ((test(add_mask, i) == 0) and test(cur_mask, i))
        --tmp[i];
    }
    cur_mask = add_mask;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cout << ans[i][j];
    }
    std::cout << '\n';
  }
  std::cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
