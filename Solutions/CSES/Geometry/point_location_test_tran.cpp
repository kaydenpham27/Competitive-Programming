#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e6 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n;
 
int ccw(int x0, int y0, int x1, int y1, int x2, int y2){
    return (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t --){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 
        int x = ccw(x3, y3, x1, y1, x2, y2);
        if (x > 0){
            cout << "LEFT\n";
        }
 
        if (x == 0){
            cout << "TOUCH\n";
        }
 
        if (x < 0){
            cout << "RIGHT\n";
        }
    }
}