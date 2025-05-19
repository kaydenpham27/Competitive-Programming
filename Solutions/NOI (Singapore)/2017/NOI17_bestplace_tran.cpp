#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e5 + 5;
const int inf = 1e18;

int n, a[O], b[O], sumA[O], sumB[O];

int solban(){
    int res = inf;
    for (int i = 1; i <= 100; ++ i){
        for (int j = 1; j <= 100; ++ j){
            int cost = 0;
            for (int z = 1; z <= n; ++ z){
                cost += abs(a[z] - i) + abs(b[z] - j);
            }
            res = min(res, cost);
        }
    }

    return res;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i] >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++ i){
        sumA[i] = sumA[i - 1] + a[i];
        sumB[i] = sumB[i - 1] + b[i];
    }

    int Max = inf, X = 0;
    for (int i = 1; i <= n; ++ i){
        int cost = a[i] * i - sumA[i] + sumA[n] - sumA[i] - a[i] * (n - i);
        if (cost < Max){
            Max = cost;
            X = a[i];
        }
    }

    Max = inf;
    int Y = 0;
    for (int i = 1; i <= n; ++ i){
        int cost = b[i] * i - sumB[i] + sumB[n] - sumB[i] - b[i] * (n - i);
        if (cost < Max){
            Max = cost;
            Y = b[i];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++ i) res += abs(X - a[i]) + abs(Y - b[i]);

    cout << X << " " << Y;
}