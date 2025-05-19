#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 5e5 + 5;
 
int n, a[O], sum[O], rsum[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        if (i < n) sum[i] = __builtin_ctz(i);
    }
 
    for (int i = n; i >= 1; -- i) rsum[i] = rsum[i + 1] + sum[i];
    for (int i = 1; i <= n; ++ i) sum[i] += sum[i - 1];
 
    int res = a[1];
    for (int i = 1; i < n; ++ i){
        if (rsum[n - i] == sum[i]) res ^= a[i + 1];
    }
 
    cout << res;
}
/**
aybabtu
**/