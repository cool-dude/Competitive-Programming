#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(n + 1, vector<int>(m + 1));
  vector<pair<int, int>> moves;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (A[i][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j] == 1 && A[i + 1][j + 1] == 1) {
        B[i][j] = B[i][j + 1] = B[i + 1][j] = B[i + 1][j + 1] = 1;
        moves.emplace_back(i, j);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i][j] != B[i][j]) {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << moves.size() << "\n";
  for (auto [r, c] : moves) {
    cout << r << " " << c << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
