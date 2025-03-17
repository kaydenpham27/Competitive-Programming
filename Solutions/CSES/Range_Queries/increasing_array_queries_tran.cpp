#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
//#define push_back emplace_back
#define list ll
 
using namespace std;
 
const int O = 2e5 + 5;
const int N = 4e5 + 5;
const int mod = 998244353;
const int inf = 2e9 + 5;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, q, a[O], R[O], sum[O], res[O], tree[O * 4], lazy[O * 4];
vector <pair <int, int>> Q[O];
 
void Push(int id, int l, int r){
    int &x = lazy[id];
    if (x == 0) return;
 
    int mid = (l + r) / 2;
    tree[id << 1] = x * (mid - l + 1);
    lazy[id << 1] = x;
 
    tree[id << 1 | 1] = x * (r - mid);
    lazy[id << 1 | 1] = x;
 
    x = 0; return;
}
 
void Update(int id, int l, int r, int u, int v, int x){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] = x * (r - l + 1);
        lazy[id] = x;
        return;
    }
    int mid = (l + r) / 2; Push(id, l, r);
    Update(id << 1, l, mid, u, v, x);
    Update(id << 1 | 1, mid + 1, r, u, v, x);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id, l, r);
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
 
    stack <int> s;
    for (int i = n; i >= 1; -- i){
        while (s.size() && a[s.top()] <= a[i]) s.pop();
        R[i] = s.size() ? s.top() : n + 1;
        s.push(i);
    }
 
    for (int i = 1; i <= q; ++ i){
        int l, r; cin >> l >> r;
        res[i] = -(sum[r] - sum[l - 1]);
        Q[l].push_back({r, i});
    }
 
    for (int i = n; i >= 1; -- i){
        Update(1, 1, n, i, R[i] - 1, a[i]);
        for (auto j : Q[i]){
            res[j.second] += Get(1, 1, n, i, j.first);
        }
    }
 
    for (int i = 1; i <= q; ++ i){
        cout << res[i] << "\n";
    }
}
/**
 
**/