#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
 
using namespace std;
 
const int O = 2e5 + 5;
const int N = 4e5 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, m, a[O], tree[O * 4];
 
void Build(int id, int l, int r){
    if (l == r){
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
 
void Update(int id, int l, int r, int u, int x){
    if (l == r){
        tree[id] -= x;
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid) Update(id << 1, l, mid, u, x);
    else Update(id << 1 | 1, mid + 1, r, u, x);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
 
int Get(int x){
    int l = 1, r = n, id = 1;
    while (l < r){
        int mid = (l + r) / 2;
 
        //cout << l << " " << mid << " " << r << " " << tree[id << 1] << endl;
 
        if (tree[id << 1] >= x){
            r = mid;
            id = id << 1;
        }
        else{
            l = mid + 1;
            id = id << 1 | 1;
        }
    }
    //cout << l << endl;
    return a[l] >= x ? l : 0;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    Build(1, 1, n);
 
    //Get(1);
 
    for (int i = 1; i <= m; ++ i){
        int x; cin >> x;
        int res = Get(x);
 
        if (res) Update(1, 1, n, res, x);
 
        cout << res << " ";
        a[res] -= x;
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