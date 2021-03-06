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
  int nodes = 3 * n;
  vector<bool> taken(nodes + 1);
  vector<int> matching;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    if (!taken[u] && !taken[v]) {
      taken[u] = taken[v] = true;
      matching.emplace_back(i);
    }
  }
  if ((int) matching.size() >= n) {
    cout << "Matching\n";
    int done = 0;
    for (auto i : matching) {
      cout << i << " ";
      ++done;
      if (done == n) {
        break;
      }
    }
    cout << "\n";
  } else {
    cout << "IndSet\n";
    int done = 0;
    for (int i = 1; i <= nodes; ++i) {
      if (!taken[i]) {
        cout << i << " ";
        ++done;
        if (done == n) {
          break;
        }
      }
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
