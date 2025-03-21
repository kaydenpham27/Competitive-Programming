#include <bits/stdc++.h>
#define ll long long
#define st first
#define sc second
#define pb push_back
 
using namespace std;
const int maxn = 2e6 + 69;
const int base = 131;
const ll mod = 1e9 + 7;
 
ll a[maxn], st[4*maxn], st1[4*maxn];
int n, m;
 
void update(int id, int l, int r, int pos, int val)
{
    if(pos < l || pos > r) return;
    if(l == r){
        st[id] = val;
        return;
    }
    int mid = (l + r)/2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
 
ll get_min(int id, int l, int r, int p, int q)
{
    if(q < l || p > r) return 1e18;
    if(p <= l && r <= q){
        return st[id];
    }
    int mid = (l + r)/2;
    return min(get_min(id * 2, l, mid, p, q), get_min(id * 2 + 1, mid + 1, r, p, q));
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        st[i] = st[i - 1] ^ a[i];
    }
    for(int i = n; i >= 1; i --){
        st1[i] = st1[i + 1] ^ a[i];
    }
    while(m --){
        int p, q;
        cin >> p >> q;
        ll cur = st[n] ^ st[p - 1];
        cur = cur ^ st1[q + 1];
        cout << cur << "\n";
    }
 
}