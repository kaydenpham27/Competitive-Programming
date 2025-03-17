#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 2e5 + 5 + 5;
const int base = 500;
const int mod = 998244353;

int n, a[O], b[O], suf[O], pref[O];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        b[i] = a[i] + i;
        a[i] -= i;
    }

    for (int i = 1; i <= n; ++ i){
        pref[i] = pref[i - 1] + max(0ll, a[i - 1] - a[i]);
    }

    for (int i = n; i >= 1; -- i){
        suf[i] = suf[i + 1] + max(0ll, b[i + 1] - b[i]);
    }

    int res = 1e18;
    for (int i = 1; i <= n; ++ i){
        //cout << "debug " << i << " " << pref[i] << " " << suf[i] << endl;
        res = min(res, max(pref[i], suf[i]));
    }

    cout << res;
}
/***
5 5
RGWRR
GRRGW
WRGWR
RGWRG
XWRGW
***/