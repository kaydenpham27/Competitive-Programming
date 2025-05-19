#include <bits/stdc++.h>
#include "secret.h"

using namespace std;

const int O = 2e3 + 5;
//const int N = (1 << 20) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e18;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
const double eps = 1e-10;

int n, a[O], mask[O], f[21][O];

/*int Secret(int x, int y){
    return x + (y / 2) * 2;
}*/

void DnC(int l, int r, int level){
    if (l == r){
        f[level][l] = a[l];
        return;
    }
    int mid = (l + r) / 2;

    f[level][mid] = a[mid];
    for (int i = mid - 1; i >= l; -- i) f[level][i] = Secret(a[i], f[level][i + 1]);

    f[level][mid + 1] = a[mid + 1];
    for (int i = mid + 2; i <= r; ++ i) f[level][i] = Secret(f[level][i - 1], a[i]);

    for (int i = mid + 1; i <= r; ++ i) mask[i] |= (1 << level);

    DnC(l, mid, level + 1);
    DnC(mid + 1, r, level + 1);

}

void Init(int N, int A[]){
    for (int i = 0; i < N; ++ i){
        a[i] = A[i];
        mask[i] = 0;
    }
    DnC(0, N - 1, 0);
}

int Query(int L, int R){
    if (L == R) return a[L];
    if (L + 1 == R){
        return Secret(a[L], a[R]);
    }
    int x = __builtin_ctz(mask[L] ^ mask[R]);
    //cout << x << " " << f[x][L] << " " << f[x][R] << endl;
    return Secret(f[x][L], f[x][R]);
}

/*main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << Secret(1, 4) << " " << Secret(7, 2) << endl;
    cin >> n;
    for (int i = 0; i < n; ++ i){
        cin >> a[i];
    }

    Init(n, a);

    int q; cin >> q;
    while (q --){
        int l, r; cin >> l >> r;
        cout << Query(l, r) << endl;
    }
}*/
/**
**/