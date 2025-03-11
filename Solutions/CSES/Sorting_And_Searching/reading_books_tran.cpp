#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, a[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    sort(a + 1, a + n + 1);
 
    int sum = 0;
    for (int i = 1; i < n; ++ i) sum += a[i];
 
    if (a[n] > sum) cout << a[n] * 2;
    else cout << sum + a[n];
}