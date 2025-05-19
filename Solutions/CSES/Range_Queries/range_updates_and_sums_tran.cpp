#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
const int N = (1 << 20) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, q, a[O];
int tree[O * 4], Set[O * 4], Add[O * 4];
 
void Build(int id, int l, int r){
    Add[id] = Set[id] = 0;
    if (l == r){
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
void PushAdd(int id, int l, int r){
    int &x = Add[id];
    if (x == 0) return;
    int mid = (r + l) / 2;
 
    tree[id << 1] += x * (mid - l + 1);
    Add[id << 1] += x;
 
    tree[id << 1 | 1] += x * (r - mid);
    Add[id << 1 | 1] += x;
    x = 0;
    return ;
}
 
void PushSet(int id, int l, int r){
    int &x = Set[id];
    if (x == 0) return;
    int mid = (l + r) / 2;
    tree[id << 1] = x * (mid - l + 1);
    Set[id << 1] = x;
    Add[id << 1] = 0;
 
    tree[id << 1 | 1] = x * (r - mid);
    Set[id << 1 | 1] = x;
    Add[id << 1 | 1] = 0;
    x = 0;
    return ;
}
 
void Push(int id, int l, int r){
    PushSet(id, l, r);
    PushAdd(id, l, r);
    return;
}
 
void UpdateSet(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] = val * (r - l + 1);
        Set[id] = val;
        Add[id] = 0;
        return;
    }
    int mid = (l + r) / 2; Push(id, l, r);
    UpdateSet(id << 1, l, mid, u, v, val);
    UpdateSet(id << 1 | 1, mid + 1, r, u, v, val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
void UpdateAdd(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] += val * (r - l + 1);
        Add[id] += val;
        return;
    }
    int mid = (l + r) / 2; Push(id, l, r);
    UpdateAdd(id << 1, l, mid, u, v, val);
    UpdateAdd(id << 1 | 1, mid + 1, r, u, v, val);
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
    for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    Build(1, 1, n);
 
    for (int i = 1; i <= q; ++ i){
        int k, x, y; cin >> k >> x >> y;
 
        if (k <= 2){
            int z; cin >> z;
            if (k == 1) UpdateAdd(1, 1, n, x, y, z);
            else UpdateSet(1, 1, n, x, y, z);
        }
        else{
            cout << Get(1, 1, n, x, y) << "\n";
        }
    }
}
/**
6 7
2 3 1 1 5 3
1 2 5 1
2 3 4 4
1 3 5 1
1 2 3 1
2 1 2 2
3 4 5
3 2 3
**/