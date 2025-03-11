#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
 
int n, m, a[O], f[O], rf[O];
vector <int> val;
int tree[O * 4];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
}
 
void Build(int id, int l, int r){
    if (l == r){
        tree[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = 0;
}
 
void Update(int id, int l, int r, int u, int val){
    if (l > u || r < u) return;
    if (l == r){
        Add(tree[id], val);
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u, val);
    Update(id << 1 | 1, mid + 1, r, u, val);
    tree[id] = tree[id << 1];
    Add(tree[id], tree[id << 1 | 1]);
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    int x = Get(id << 1, l, mid, u, v);
    Add(x, Get(id << 1 | 1, mid + 1, r, u, v));
    return x;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        val.push_back(a[i]);
    }
 
    sort(val.begin(), val.end());
 
    for (int i = 1; i <= n; ++ i) a[i] = upper_bound(val.begin(), val.end(), a[i]) - val.begin();
 
    int res = 0;
    Update(1, 0, n, 0, 1);
    for (int i = 1; i <= n; ++ i){
        int x = Get(1, 0, n, 0, a[i] - 1);
        Update(1, 0, n, a[i], x);
        Add(res, x);
        //cout << "f[i] : " << i << " " << f[i] << endl;
    }
 
    //int res = inf;
    //for (int i = 0; i <= n; ++ i) res = min(res, f[i] + rf[i + 1]);
 
    cout << res;
}