#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e6 + 5;
 
int n, p[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        int x; cin >> x;
        p[x] += 1;
    }
 
    int res = 0;
    for (int i = 1; i <= 1000000; ++ i){
        int j = 2 * i;
        while (p[i] < 2 && j < O){
            p[i] += p[j];
            j += i;
        }
 
        if (p[i] >= 2) res = i;
    }
 
    cout << res;
 
}