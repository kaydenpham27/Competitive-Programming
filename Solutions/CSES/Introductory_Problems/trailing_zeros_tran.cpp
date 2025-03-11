#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e6 + 2;
 
int n, cnt[O], dem[O];
vector <int> val;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
 
    int cur = 1, d = 0, res = 0;
 
    while (cur <= n){
        cur *= 5;
        d += 1;
    }
 
    int sum = 0;
    cur /= 5; d -= 1;
    for (; d >= 1; -- d, cur /= 5){
        int x = ((n / cur) - sum);
        sum += x;
        res += x * d;
    }
 
    cout << res;
}
