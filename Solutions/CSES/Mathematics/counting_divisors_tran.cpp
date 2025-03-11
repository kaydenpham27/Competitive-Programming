#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e3 + 5;
 
int p[O];
vector <int> Prime;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 2; i < O; ++ i){
        if (!p[i]){
            Prime.push_back(i);
            for (int j = i * i; j < O; j += i) p[j] = 1;
        }
    }
 
    int t; cin >> t;
    while (t --){
        int x; cin >> x;
 
        int res = 1;
        for (int i = 0; Prime[i] * Prime[i] <= x && i < Prime.size(); ++ i){
            if (x % Prime[i] == 0){
                int d = 1;
                while (x % Prime[i] == 0){
                    d += 1;
                    x /= Prime[i];
                }
                res = res * d;
            }
        }
 
        if (x > 1) res = res * 2;
 
        cout << res << "\n";
    }
 
}