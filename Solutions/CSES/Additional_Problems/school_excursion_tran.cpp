#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e5 + 50;
 
int n, m, sz[O], dd[O], cnt[O], lab[O];
bitset <O> dp;
 
int Find(int u){
    return lab[u] == 0 ? u : lab[u] = Find(lab[u]);
}
 
void Merge(int u, int v){
    int pu = Find(u);
    int pv = Find(v);
 
    if (pu != pv){
        sz[pu] += sz[pv];
        lab[pv] = pu;
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) sz[i] = 1;
 
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        Merge(u, v);
    }
 
    vector <int> a;
    for (int i = 1; i <= n; ++ i){
        int u = Find(i);
        if (!dd[u]){
            dd[u] = true;
            a.push_back(sz[u]);
            cnt[sz[u]] += 1;
        }
    }
 
    sort(a.begin(), a.end());
    m = unique(a.begin(), a.end()) - a.begin();
    a.resize(m);
 
    dp.set(0);
    for (int i : a){
        for (int j = 1; j <= cnt[i]; j <<= 1){
            dp |= (dp << (j * i));
            cnt[i] -= j;
        }
        dp |= (dp << (cnt[i] * i));
    }
 
    for (int i = 1; i <= n; ++ i) cout << dp.test(i);
}
/***
***/