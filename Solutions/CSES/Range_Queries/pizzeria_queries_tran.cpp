#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, q, p[O], treeS[O * 4], treeB[O * 4];
 
void Build(int id, int l, int r){
    if (l == r){
        treeB[id] = p[l] + r;
        treeS[id] = p[r] - l;
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    treeS[id] = min(treeS[id << 1], treeS[id << 1 | 1]);
    treeB[id] = min(treeB[id << 1], treeB[id << 1 | 1]);
}
 
void Update(int id, int l, int r, int u, int x){
    if (l > u || r < u) return;
    if (l == r){
        treeS[id] += x;
        treeB[id] += x;
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u, x);
    Update(id << 1 | 1, mid + 1, r, u, x);
    treeS[id] = min(treeS[id << 1], treeS[id << 1 | 1]);
    treeB[id] = min(treeB[id << 1], treeB[id << 1 | 1]);
}
 
int GetS(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 1e18;
    if (u <= l && r <= v) return treeS[id];
    int mid = (l + r) / 2;
    return min(GetS(id << 1, l, mid, u, v), GetS(id << 1 | 1, mid + 1, r, u, v));
}
 
int GetB(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 1e18;
    if (u <= l && r <= v) return treeB[id];
    int mid = (l + r) / 2;
    return min(GetB(id << 1, l, mid, u, v), GetB(id << 1 | 1, mid + 1, r, u, v));
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> p[i];
 
    Build(1, 1, n);
    for (int i = 1; i <= q; ++ i){
        int k, l, r; cin >> k >> l;
        if (k == 1) cin >> r, Update(1, 1, n, l, -p[l]), Update(1, 1, n, l, r), p[l] = r;
        if (k == 2) cout << min(l + GetS(1, 1, n, 1, l), GetB(1, 1, n, l, n) - l) << "\n";
    }
}