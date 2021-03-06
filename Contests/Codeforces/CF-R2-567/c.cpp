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
  int n, I;
  cin >> n >> I;
  int bits = 8 * I;
  int k = bits / n;
  if (k >= 20) {
    cout << "0\n";
    return;
  }
  int unq = (1 << k);
  vector<int> A(n + 1);
  map<int, int> cnt;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    ++cnt[A[i]];
  }
  vector<pair<int, int>> b = {{-1, -1}};
  for (auto i : cnt) {
    b.emplace_back(i);
  }
  if ((int) b.size() - 1 <= unq) {
    cout << "0\n";
  } else {
    int tot = n;
    for (int i = 1; i <= unq; ++i) {
      tot -= b[i].second;
    }
    int res = tot;
    for (int i = unq + 1; i < (int) b.size(); ++i) {
      tot -= b[i].second;
      tot += b[i - unq].second;
      res = min(res, tot);
    }
    cout << res << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
