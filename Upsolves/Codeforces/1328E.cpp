#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> par(n + 1), tin(n + 1), tout(n + 1), dep(n + 1);
    int timer = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        tin[u] = ++timer;
        dep[u] = d;
        par[u] = p;
        for (auto &v : G[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
        tout[u] = ++timer;
    };
    dfs(1, 1, 0);
    auto is_anc = [&](int u, int v) { // u anc of v
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };
    while (m--) {
        int k;
        cin >> k;
        vector<int> V(k);
        int st = 1;
        int mx_dep = 0;
        for (int i = 0; i < k; ++i) {
            cin >> V[i];
            if (dep[V[i]] > mx_dep) {
                mx_dep = dep[V[i]];
                st = V[i];
            }
            V[i] = par[V[i]];
        }
        bool ok = true;
        for (auto &u : V) {
            ok = ok && (is_anc(u, st));
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

