#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
long long dp[100][25][11];
long long bit[100], bit1[100];
unordered_map<int, int> map;

long long go(char A[], int i, int pv, int v) {
    if (i == strlen(A)) {
        return pv == 0 ? 1 : 0;
    }
    if (dp[i][pv][v] != -1) {
        return dp[i][pv][v];
    }
    long long ans = 0;
    if (A[i] == '_') {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0) continue;
            int y = (pv * 10 + j) % 25;
            ans += go(A, i + 1, y, v);
        }
    } else if (A[i] == 'X') {
        if (v != 10) {
            ans += go(A, i + 1, (pv * 10 + v) % 25, v);
        } else {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0) continue;
                int y = (pv * 10 + j) % 25;
                ans += go(A, i + 1, y, j);
            }
        }
    } else {
        ans += go(A, i + 1, (pv * 10 + (A[i] - '0')) % 25, v);
    }
    return dp[i][pv][v] = ans;
}

void fill(long long dp[]) {
    fill(dp, dp + sizeof(dp) / sizeof(dp[0]), -1);
}

void fill(long long dp[][]) {
    for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++) {
        fill(dp[i], dp[i] + sizeof(dp[i]) / sizeof(dp[i][0]), -1);
    }
}

void fill(long long dp[][][]) {
    for (int i = 0; i < sizeof(dp) / sizeof(dp[0]); i++) {
        for (int j = 0; j < sizeof(dp[i]) / sizeof(dp[i][0]); j++) {
            fill(dp[i][j], dp[i][j] + sizeof(dp[i][j]) / sizeof(dp[i][j][0]), -1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ttt = 1;
    while (ttt-- > 0) {
        string input;
        cin >> input;
        char A[input.length() + 1];
        strcpy(A, input.c_str());
        
        if (input.length() == 1 && A[0] == '0') {
            cout << "1\n";
            return 0;
        }
        if (A[0] == '0') {
            cout << "0\n";
            return 0;
        }
        if (input.length() == 1) {
            if (A[0] == 'X' || A[0] == '_') {
                cout << "1\n";
                return 0;
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << go(A, 0, 0, 10) << "\n";
    }
    
    return 0;
}
