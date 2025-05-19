#include <bits/stdc++.h>
#define double long double
#define all(x) begin(x), end(x)
#define pii pair<int, int>
#define fi first
#define se second
 
using namespace std;
 
const int O = 2e5 + 5;
const int inf = 1e7;
 
int n, x[O], tree[O * 4];
 
void Build(int id, int l, int r){
    if (l == r){
        tree[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
void Update(int id, int l, int r, int u, int x){
    if (l == r){
        tree[id] = x;
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid) Update(id << 1, l, mid, u, x);
    else Update(id << 1 | 1, mid + 1, r, u, x);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int k){
    int l = 1, r = n, id = 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (tree[id << 1] >= k){
            id = id << 1;
            r = mid;
        }
        else{
            k -= tree[id << 1];
            id = id << 1 | 1;
            l = mid + 1;
        }
    }
    return l;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
 
    Build(1, 1, n);
 
    for (int i = 1; i <= n; ++ i){
        int p; cin >> p;
        int res = Get(p);
        Update(1, 1, n, res, 0);
        cout << x[res] << " ";
    }
 
}
/**
**/