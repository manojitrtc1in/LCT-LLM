#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#include<utility>
#include<climits>
#include<vector>
#include<map>
#include<iterator>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define nl '\n'
#define MOD ((ll) 1e9 + 7)

void file_fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
}


int main(){
    file_fastIO();

    int t; cin >> t;
    while(t--) {
        int r, c;
        cin >> r >> c;
        char grid[r][c];

        for (auto &i: grid) {
            for (auto &j: i) cin >> j;
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }
        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }


        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }


        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }

        for(int j = 0; j < c; j++){
            for(int i = 0; i < r - 1; i++){
                if(grid[i][j] == '*' and grid[i + 1][j] == '.')
                    swap(grid[i][j], grid[i + 1][j]);
            }
        }


        for(auto& i : grid){
            for(auto& j : i){
                cout << j;
            }
            cout << nl;
        }
        cout << nl;
    }

    return 0;
}