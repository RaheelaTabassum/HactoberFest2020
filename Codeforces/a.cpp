#include <bits/stdc++.h>

using namespace std;

void solve() {
    ll N;
    cin >> N;
    vll value(N + 1, 0);
    FOR(N - 1) {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vll ans(N + 1, 0);
    printLevels(N + 1, 1);
    ll val = 1;
    EACH(i, m) {
        EACH(it, i.second) {
            // cout << it << " ";
            if (val == 1) {
                ans[it] = 1;
            } else {
                ans[it] = 2;
            }
        }
        val ^= 1;
    }
    FOR(i, 1, N + 1) {
        cout << ans[i] << " ";
    }
    cout << endl;
    m.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
