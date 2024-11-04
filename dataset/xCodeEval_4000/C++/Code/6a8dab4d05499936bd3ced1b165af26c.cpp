#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

bool works(int L, int U, int N, int M, vector<string> grid, pair<int, int> chosen, vector<char> moves) {
    
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < M; j++) {
            
            if (grid[i][j] == 'R' && make_pair(i, j) != chosen) {
                if (i - U < 0 || j - L < 0) {
                    
                    return 0;
                }
            }
        }
    }

    return 1;
}

bool solve(int N, int M, vector<string> grid, pair<int, int> chosen) {
    int U = abs(chosen.first - 0), L = abs(chosen.second - 0);
    
    std::vector<char> moves;

    for (int i = 0; i < U; i++) moves.push_back('U');

        
    for (int i = 0; i < L; i++) moves.push_back('L');

        

    sort(all(moves));

    do {

        
        if (works(L, U, N, M, grid, chosen, moves)) return 1;
    } while (next_permutation(moves.begin(), moves.end()));

    

    return 0;
}

void run() {
    int nn, mm;
    cin >> nn >> mm;
    vector<string> grid(nn);

    

    for (auto& el : grid)
        cin >> el;

    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; j++) {
            
            if (grid[i][j] == 'R') {
                if (solve(nn, mm, grid, make_pair(i, j))) {
                    cout << "YES" << '\n';
                    
                    return;
                }
            }
        }
    }

    cout << "NO" << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--) run();
    return 0;
}
