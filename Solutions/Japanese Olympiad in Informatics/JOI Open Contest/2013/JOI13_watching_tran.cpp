#include <bits/stdc++.h>

using namespace std;

const int O = 2e3 + 5;
const int base = 500;
const int mod = 998244353;

int n, p, q, a[O], f[O][O];

bool check(int mid){
    f[0][0] = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j <= min(i, q); ++ j){
            f[i][j] = 1e9;
            while (x < i && a[x + 1] < a[i] - 2 * mid + 1) x += 1;
            if (j) f[i][j] = min(f[i][j], f[x][j - 1]);

            while (y < i && a[y + 1] < a[i] - mid + 1) y += 1;
            f[i][j] = min(f[i][j], f[y][j] + 1);
        }
    }

    return f[n][q] <= p;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> p >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    sort(a + 1, a + n + 1);
    //for (int i = 1; i <= n; ++ i) cout << a[i] << " "; cout << endl;

    if (p + q >= n) return cout << 1, 0;

    int l = 0, r = 1e9;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }

    cout << l;
}