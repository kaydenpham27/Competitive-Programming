#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e5 + 5;
const int N = (1 << 10) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
const int base = 50;
const int K = 32;

int n, q, k, a[K][O], id[O], L[O], R[O], tree[O * 4];
long long sum[K][O];

void Del(int l){
    int block = l / base;

    int d = id[block];
    for (int i = 0; i < K; ++ i){
        int x = i + d >= K ? 0 : sum[i + d][block] - a[i + d][l];
        sum[i][block] = x;
    }
    return;
}

void Add(int l, int r){
    int block = l / base;

    a[0][l] = r;
    for (int i = 0; i < K; ++ i){
        if (i) a[i][l] = a[i - 1][l] / k;
        sum[i][block] += a[i][l];
    }
    return;
}

void Build(int id, int l, int r){
    if (l == r){
        tree[id] = a[0][r];
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

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
    cin >> n >> q >> k;
    for (int i = 0; i < n; ++ i){
        cin >> a[0][i];

        int block = i / base;
        R[block] = i;

        for (int j = 0; j < K; ++ j){
            if (j) a[j][i] = a[j - 1][i] / k;
            sum[j][block] += a[j][i];
        }
    }


    for (int i = n - 1; i >= 0; -- i){
        L[i / base] = i;
    }

    if (k == 1){
        n -= 1;
        Build(1, 0, n);
        for (int i = 1; i <= q; ++ i){
            int t, l, r; cin >> t >> l >> r;
            if (t == 1){
                l -= 1;
                Update(1, 0, n, l, r);
            }

            if (t == 3){
                l -= 1; r -= 1;
                cout << Get(1, 0, n, l, r) << "\n";
            }
        }

        return 0;
    }

    for (int _ = 1; _ <= q; ++ _){
        int t, l, r; cin >> t >> l >> r;
        l -= 1; r -= 1;

        if (t == 1){
            r += 1;
            Del(l);
            Add(l, r);

            int block = l / base, d = id[l / base];
            for (int i = L[block]; i <= R[block]; ++ i){
                if (i != l){
                    for (int j = 0; j < K; ++ j){
                        int x = j + d >= K ? 0 : a[j + d][i];
                        a[j][i] = x;
                    }
                }
            }

            id[block] = 0;
        }

        if (t == 2){
            for (int i = (l / base) + 1; i < (r / base); ++ i) id[i] = min(id[i] + 1, K - 1);

            for (int i = l; i <= min(R[l / base], r); ++ i){
                for (int j = id[l / base]; j < K; ++ j){
                    int x = j + 1 >= K ? 0 : a[j + 1][i];
                    sum[j][l / base] -= a[j][i];
                    sum[j][l / base] += x;
                    a[j][i] = x;
                }
            }

            if ((int)l / base != (int)r / base){
                for (int i = L[r / base]; i <= r; ++ i){
                    for (int j = id[r / base]; j < K; ++ j){
                        int x = j + 1 >= K ? 0 : a[j + 1][i];
                        sum[j][r / base] -= a[j][i];
                        sum[j][r / base] += x;
                        a[j][i] = x;
                    }
                }
            }
        }

        if (t == 3){
            long long res = 0;

            for (int i = l / base; i <= r / base; ++ i){
                res += sum[id[i]][i];
            }

            for (int i = L[l / base]; i < l; ++ i) res -= a[id[l / base]][i];
            for (int i = r + 1; i <= R[r / base]; ++ i) res -= a[id[r / base]][i];

            cout << res << "\n";
        }
    }

}
/**
4 9 2
1 1 1 1
2 2 3
3 2 3
2 2 3
3 2 3
2 2 3
3 2 3
1 2 11
3 1 3
3 2 3
**/