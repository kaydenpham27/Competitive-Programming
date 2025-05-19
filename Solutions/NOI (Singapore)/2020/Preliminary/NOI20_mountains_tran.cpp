#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 3e5 + 5;

int n, a[O], tree[O * 4];
pair <int, int> b[O];

void Update(int id, int l, int r, int u, int x){
    if (l > u || r < u) return;
    if (l == r){
        tree[id] = x;
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u, x);
    Update(id << 1 | 1, mid + 1, r, u, x);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> b[i].first; b[i].second = i;
    }

    int res = 0;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++ i){
        int j = i;
        while (j < n && b[j + 1].first == b[i].first) j += 1;

        for (int z = i; z <= j; ++ z){
            int l = Get(1, 1, n, 1, b[z].second);
            int r = Get(1, 1, n, b[z].second, n);

            res += r * l;
        }

        for (int z = i; z <= j; ++ z){
            Update(1, 1, n, b[z].second, 1);
        }
        i = j;
    }

    cout << res;
}