#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 2e5 + 5;
const int inf = 1e18;

int n, h, add, a[O], p[O];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> h >> n;
    for (int i = 1; i <= 10 * n; ++ i){
        if (i > n) p[i] = p[i - n];
        if (i <= n) cin >> p[i];
        if (i <= n) add += p[i];
    }

    for (int i = 1; i <= 10 * n; ++ i){
        a[i] = max(0ll, a[i - 1] + p[i]);
        if (a[i] >= h){
            cout << i / n - (i % n == 0) << " " << (i - 1) % n;
            return 0;
        }
    }

    if (add <= 0) return cout << "-1 -1", 0;

    int day, phase; day = inf;
    for (int i = 9 * n + 1; i <= 10 * n; ++ i){
        int c = 9 + (h - a[i] + add - 1) / add;
        if (c < day){
            day = c;
            phase = i - 9 * n - 1;
        }
    }

    cout << day << " " << phase;
}