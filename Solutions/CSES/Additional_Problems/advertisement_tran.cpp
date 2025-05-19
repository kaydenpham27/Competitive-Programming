#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 50;
const int inf = 1e9;
 
int n, a[O], L[O], R[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    stack <int> s;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
        while (s.size() && a[s.top()] >= a[i]) s.pop();
        L[i] = s.size() ? s.top() : 0;
        s.push(i);
    }
 
    while (s.size()) s.pop();
 
    for (int i = n; i >= 1; -- i){
        while (s.size() && a[s.top()] >= a[i]) s.pop();
        R[i] = s.size() ? s.top() : n + 1;
        s.push(i);
    }
 
    int res = 0;
    for (int i = 1; i <= n; ++ i){
        res = max(res, a[i] * (R[i] - L[i] - 1));
        //cout << i << " " << L[i]
    }
 
    cout << res;
}
/***
***/