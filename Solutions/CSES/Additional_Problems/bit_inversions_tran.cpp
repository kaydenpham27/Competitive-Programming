#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, m;
string a;
 
struct Node{
    int Max[2], pref[2], suf[2], sum;
} tree[O * 4];
 
Node Merge(Node x, Node y){
    Node z = x;
    for (int i = 0; i < 2; ++ i){
        z.pref[i] = x.pref[i] + (x.pref[i] == x.sum ? y.pref[i] : 0);
        z.suf[i] = y.suf[i] + (y.suf[i] == y.sum ? x.suf[i] : 0);
        z.Max[i] = max({z.pref[i], x.Max[i], y.Max[i], z.suf[i], x.suf[i] + y.pref[i]});
        z.sum = x.sum + y.sum;
    }
    return z;
}
 
void Build(int id, int l, int r){
    tree[id].sum = r - l + 1;
    if (l == r){
        int c = a[l] - '0';
        tree[id].Max[c] = tree[id].suf[c] = tree[id].pref[c] = 1;
        //cout << id << " " << l << " " << r << " : ";
        //cout << tree[id].pref[1] << " " << tree[id].suf[1] << " " << tree[id].Max[1] << endl;
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = Merge(tree[id << 1], tree[id << 1 | 1]);
    //cout << id << " " << l << " " << r << " : ";
    //cout << tree[id].pref[1] << " " << tree[id].suf[1] << " " << tree[id].Max[1] << endl;
}
 
void Update(int id, int l, int r, int u){
    if (l > u || r < u) return;
    if (l == r){
        swap(tree[id].Max[0], tree[id].Max[1]);
        swap(tree[id].suf[0], tree[id].suf[1]);
        swap(tree[id].pref[0], tree[id].pref[1]);
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u);
    Update(id << 1 | 1, mid + 1, r, u);
    tree[id] = Merge(tree[id << 1], tree[id << 1 | 1]);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    cin >> a; n = a.size(); a = " " + a;
    Build(1, 1, n);
 
    cin >> m;
    for (int i = 1; i <= m; ++ i){
        int x; cin >> x;
        Update(1, 1, n, x);
        cout << max(tree[1].Max[0], tree[1].Max[1]) << " ";
    }
}