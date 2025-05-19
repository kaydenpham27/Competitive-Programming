#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e5 + 5;
 
int n, m, res, lab[O];
vector <tuple <int, int, int>> Edges;
 
int Find(int u){
    return lab[u] == 0 ? u : lab[u] = Find(lab[u]);
}
 
 
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v, c; cin >> u >> v >> c;
        Edges.push_back(make_tuple(c, u, v));
    }
 
    sort(Edges.begin(), Edges.end());
 
    int cnt = n;
    for (auto [c, u, v] : Edges){
        int pu = Find(u);
        int pv = Find(v);
 
        if (pu != pv){
            lab[pu] = pv;
            res += c;
            cnt -= 1;
        }
    }
 
    if (cnt > 1) return cout << "IMPOSSIBLE", 0;
    cout << res;
}
/**
10
1 1 1 1 1 1 1 1 1 1
**/