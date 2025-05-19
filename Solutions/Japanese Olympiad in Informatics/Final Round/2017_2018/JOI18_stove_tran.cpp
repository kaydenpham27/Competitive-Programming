#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 2e5 + 5;
const int base = 500;
const int mod = 998244353;

int n, k, a[O];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector <int> b;

    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        if (i > 1) b.push_back(a[i] - 1 - a[i - 1]);
        //if (i) cout << b.back() << endl;
    }

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    int res = 0;
    for (int i = 0; i < k - 1; ++ i){
        res += b[i];
        //cout << b[i] << endl;
    }

    cout << a[n] + 1 - a[1] - res;
}
/***
6 6
2 7 9 10 13 16
***/