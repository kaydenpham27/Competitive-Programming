#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, m, q, a[O], b[O], L[O], R[O], lab[O];
pair <int, int> Q[O];
vector <int> g[O];
 
int Find(int u){
    return lab[u] == 0 ? u : lab[u] = Find(lab[u]);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++ i){
        cin >> a[i] >> b[i];
    }
 
    for (int i = 1; i <= q; ++ i) cin >> Q[i].first >> Q[i].second;
 
    for (int i = 1; i <= q; ++ i) L[i] = 1;
    for (int i = 1; i <= q; ++ i) R[i] = m;
 
    while (true){
        bool flag = false;
 
        memset(lab, 0, sizeof(lab));
        for (int i = 1; i <= m; ++ i) g[i].clear();
 
        for (int i = 1; i <= q; ++ i){
            if (L[i] <= R[i]){
                int mid = (L[i] + R[i]) / 2;
                g[mid].push_back(i);
                flag = true;
            }
        }
 
        if (!flag) break;
 
        for (int i = 1; i <= m; ++ i){
            int u = Find(a[i]);
            int v = Find(b[i]);
 
            if (u != v) lab[u] = v;
 
            for (int j : g[i]){
                int x = Find(Q[j].first);
                int y = Find(Q[j].second);
 
                if (x == y){
                    R[j] = i - 1;
                }
                else{
                    L[j] = i + 1;
                }
            }
        }
    }
 
    for (int i = 1; i <= q; ++ i){
        /// L
        if (Q[i].first == Q[i].second) L[i] = 0;
 
        L[i] = L[i] > m ? -1 : L[i];
        cout << L[i] << "\n";
    }
 
}