#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 5e5 + 5;
const int inf = 1e9;
 
int n, m, lab[O];
vector <int> val;
 
int Find(int u){
    return lab[u] == 0 ? u : lab[u] = Find(lab[u]);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        int pu = Find(u);
        int pv = Find(v);
 
        if (pu != pv) lab[pu] = pv;
    }
 
    for (int i = 1; i <= n; ++ i){
        val.push_back(Find(i));
    }
 
    sort(val.begin(), val.end());
    int N = unique(val.begin(), val.end()) - val.begin();
    val.resize(N);
 
    cout << N - 1 << "\n";
    for (int i = 1; i < N; ++ i){
        cout << val[i - 1] << " " << val[i] << "\n";
    }
 
}
/**
7 6
1 2 1
2 3 2
3 4 3
4 5 3
5 6 2
6 7 1
**/