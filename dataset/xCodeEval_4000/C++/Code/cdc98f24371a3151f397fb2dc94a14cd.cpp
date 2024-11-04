#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define MOD (ll)1e18
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)



















































































































































































































































































































































































































































































































































int fx[] = {0,  0, 1, -1, 1,  1, -1, -1};
int fy[] = {-1, 1, 0,  0, 1, -1,  1, -1};
int n, m;
bool isValid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        return 1;
    }
    return 0;
}


int main() {

    _FastIO;

    while(cin >> n >> m){
        string grid[105];
        for(int i = 0; i < n; i++){
            cin >> grid[i];
        }
        bool ans = 1;
        for(int i = 0; i < n; i++){
            for(int k = 0; k < m; k++){

                if(grid[i][k] >= '1' && grid[i][k] <= '8' ){
                    int cnt = grid[i][k]-'0';
                    for(int j = 0; j < 8; j++){
                        int x = i+fx[j];
                        int y = k+fy[j];
                        if(isValid(x, y) && grid[x][y] == '*'){
                            cnt--;
                        }
                    }
                    if(cnt != 0){ 

                        ans = 0;
                        break;
                    }
                }
                else if(grid[i][k] == '.'){
                    int cnt = 0;
                    for(int j = 0; j < 8; j++){
                        int x = i+fx[j];
                        int y = k+fy[j];
                        if(isValid(x, y) && grid[x][y] == '*'){
                            cnt++;
                        }
                    }
                    if(cnt > 0){
                        ans = 0;
                        break;
                    }
                }

            }
        }
        if(ans){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}

