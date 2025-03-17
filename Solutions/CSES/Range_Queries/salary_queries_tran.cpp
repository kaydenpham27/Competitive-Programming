#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
 
using namespace std;
 
const int O = 6e5 + 5;
const int N = 2e5 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, m, q, p[O], tree[O * 4];
vector <int> val;
 
struct query{
    char k;
    int x, y;
} Q[O];
 
void Update(int id, int l, int r, int u, int x){
    if (l == r){
        tree[id] += x;
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid) Update(id << 1, l, mid, u, x);
    else Update(id << 1 | 1, mid + 1, r, u, x);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}
 
void Upd(int u, int x){
    Update(1, 1, m, u, x);
    return;
}
 
int Get(int l, int r){
    return Get(1, 1, m, l, r);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i){
        cin >> p[i];
        val.push_back(p[i]);
    }
 
    for (int i = 1; i <= q; ++ i){
        char c; cin >> c;
        int x, y; cin >> x >> y;
 
        if (c == '!'){
            val.push_back(y);
        }
 
        if (c == '?'){
            val.push_back(x);
            val.push_back(y);
        }
 
        Q[i] = {c, x, y};
    }
 
    sort(all(val));
    m = unique(all(val)) - val.begin();
    val.resize(m);
 
    for (int i = 1; i <= n; ++ i){
        int id = upper_bound(all(val), p[i]) - val.begin();
        Upd(id, 1);
    }
 
    for (int i = 1; i <= q; ++ i){
        if (Q[i].k == '!'){
            int id = upper_bound(all(val), p[Q[i].x]) - val.begin();
            Upd(id, -1);
 
            p[Q[i].x] = Q[i].y;
            id = upper_bound(all(val), Q[i].y) - val.begin();
            Upd(id, +1);
        }
 
        if (Q[i].k == '?'){
            int l = upper_bound(all(val), Q[i].x) - val.begin();
            int r = upper_bound(all(val), Q[i].y) - val.begin();
            cout << Get(l, r) << "\n";
        }
    }
}
/**
fffefff
0 1 1 2 2 3
0 -1 6
1 0 6
2 0 6
3 2 6
4 2 6
5 4 6
debug 0 0
debug 1 15
debug 3 6
49
aaazaaa
**/