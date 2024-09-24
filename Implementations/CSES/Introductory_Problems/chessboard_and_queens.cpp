#include<bits/stdc++.h>
#define ll long long
#define st first
#define nd second
using namespace std;
const int maxn = 4e6;
const int base = 31;
const long long mod = 1e9 + 11;
 
char grid[8][8];
int track[8][8];
long long ans = 0;
 
bool check(int x, int y){
    for(int i = 0; i < 8; i ++){
        if(i == y) continue;
        if(track[x][i] == 1) return false;
    }
    for(int i = 0; i < 8; i ++){
        if(i == x) continue;
        if(track[i][y] == 1) return false;
    }
    int x1 = x, y1 = y;
    while(x1 >= 0 && y1 >= 0){
        if(track[x1][y1] == 1) return false;
        x1 --;
        y1 --;
    }
    x1 = x, y1 = y;
    while(x1 < 8 && y1 < 8){
        if(track[x1][y1] == 1) return false;
        x1 ++;
        y1 ++;
    }
    x1 = x, y1 = y;
    while(x1 >= 0 && y1 < 8){
        if(track[x1][y1] == 1) return false;
        x1 --;
        y1 ++;
    }
    x1 = x, y1 = y;
    while(x1 < 8 && y1 >= 0){
        if(track[x1][y1] == 1) return false;
        x1 ++;
        y1 --;
    }
    return true;
}
 
void ways(int x, int y, int steps){
    if(steps == 8){
        ans ++;
        return;
    }
    for(int i = 0; i < 8; i ++){
        for(int j = steps; j < 8; j ++){
            if(grid[i][j] == '.' && track[i][j] == 0){
                if(check(i, j)){
                    track[i][j] = 1;
                    ways(i, j, steps + 1);
                    track[i][j] = 0;
                }
            }
        }
    }
}
 
void solve()
{
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            cin >> grid[i][j];
            track[i][j] = 0;
        }
    }
    for(int j = 0; j < 8; j ++){
        if(grid[j][0] == '.'){
            track[j][0] = 1;
            ways(j, 0, 1);
            track[j][0] = 0;
 
        }
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Tests = 1;
    while(Tests --){
        solve();
    }
}