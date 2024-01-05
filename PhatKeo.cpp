#include <bits/stdc++.h>
#define int64_t long long
#define double long double
using namespace std;
using type = int64_t;

const long long mod = 998244353, inf = 1e18;
const int base = 33;
const int N = 3e5 + 10;
const int LG = 20;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, q;
int64_t st[10][4 * N];
void update(int type, int id, int l, int r, int i, int64_t val)
{
    if(i < l || i > r) return;
    if(l == r){
        st[type][id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(type, id * 2, l, mid, i, val);
    update(type, id * 2 + 1, mid + 1, r, i, val);
    st[type][id] = st[type][id * 2] + st[type][id * 2 + 1];
}

int64_t get(int type, int id, int l, int r, int u, int v)
{
    if(v < l || u > r) return 0;
    if(u <= l && r <= v){
        return st[type][id];
    }
    int mid = (l + r) >> 1;
    return get(type, id * 2, l, mid, u, v) +
            get(type, id * 2 + 1, mid + 1, r, u, v);
}

void Solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        int64_t x; cin >> x;
        string s = to_string(i);
        for(int j = 1; j <= 9; j ++){
            bool flag = (i % j == 0);
            for(char c : s) flag |= (c - '0' == j);
            if(flag) update(j, 1, 1, n, i, 2 * x);
            else update(j, 1, 1, n, i, x);
        }
    }
    while(q --){
        int t; cin >> t;
        if(t == 1){
            int i; int64_t c; cin >> i >> c;
            string s = to_string(i);
            for(int j = 1; j <= 9; j ++){
                bool flag = (i % j == 0);
                for(char c : s) flag |= (c - '0' == j);
                if(flag) update(j, 1, 1, n, i, 2 * c);
                else update(j, 1, 1, n, i, c);
            }
        }
        else{
            int l, r, k; cin >> l >> r >> k;
            cout << get(k, 1, 1, n, l, r) << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen("guard.in", "r")){
        freopen("guard.in", "r", stdin);
        freopen("guard.out", "w", stdout);
    }
    if(fopen("A.inp", "r")){
        freopen("A.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    int tc = 1;
    //cin >> tc;
    while(tc --){
        Solve();
    }
}

