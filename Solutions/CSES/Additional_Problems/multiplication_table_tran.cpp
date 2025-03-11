/// fptu UWR
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 3e5 + 5;
const int inf = 1e9;
 
int n, A, B, a[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("input.in", "r")){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
 
    cin >> n;
 
    int l = 1, r = 1e12;
    while (l <= r){
        int mid = (l + r) / 2;
 
        int dem = 0;
        for (int i = 1; i <= n; ++ i){
            dem += min(n, mid / i);
        }
 
        if (dem >= (n * n + 1) / 2) r = mid - 1;
        else l = mid + 1;
    }
 
    cout << l;
}