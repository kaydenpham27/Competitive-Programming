#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 2e5 + 5;
const int base = 500;
const int mod = 998244353;

int n, q, s, t, temp, a[O], b[O];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q >> s >> t; s = -s;
    for (int i = 0; i <= n; ++ i){
        cin >> a[i];
        if (i){
            b[i] = a[i] - a[i - 1];
            temp += abs(b[i]) * (b[i] > 0 ? s : t);
        }
    }

    for (int i = 1; i <= q; ++ i){
        int l, r, x; cin >> l >> r >> x;

        temp -= abs(b[l]) * (b[l] > 0 ? s : t);
        b[l] += x;
        temp += abs(b[l]) * (b[l] > 0 ? s : t);

        if (r == n){
            cout << temp << "\n";
            continue;
        }

        temp -= abs(b[r + 1]) * (b[r + 1] > 0 ? s : t);
        b[r + 1] -= x;
        temp += abs(b[r + 1]) * (b[r + 1] > 0 ? s : t);

        cout << temp << "\n";
    }
}
/***
6 6
2 7 9 10 13 16
***/