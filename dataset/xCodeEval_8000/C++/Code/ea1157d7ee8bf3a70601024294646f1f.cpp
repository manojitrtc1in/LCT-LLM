#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 1e15 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3, log_n = 20;

int dx[]{-1, -1, 0, 1, 1, 1, 0, -1};
int dy[]{0, 1, 1, 1, 0, -1, -1, -1};
map<string, int> moves{{"Up", 0}, {"Up-Right", 1}, {"Right", 2}, {"Down-Right", 3}, 
{"Down", 4}, {"Down-Left", 5}, {"Left", 6}, {"Up-Left", 7}};

vector<pii> queen;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int king_move(int num, int dir) {
    int to_x = num / 8 + dx[dir], to_y = num % 8 + dy[dir];
    if (!check(to_x, to_y)) return -1;
    return to_x * 8 + to_y;
}

vector<int> king_move(int num) {
    vector<int> res;
    for (int d = 0; d < 8; ++d) {
        int v = king_move(num, d);
        if (v != -1) res.pb(v);
    }
    return res;
}
vector<int> queen_move(int num) {
    int x = num / 8, y = num % 8;
    vector<int> res;
    for (int d = 0; d < 8; ++d) {
        for (int i = 1; i < 8; ++i) {
            int to_x = x + dx[d] * i, to_y = y + dy[d] * i;
            if (check(to_x, to_y)) res.pb(to_x * 8 + to_y);
        }
    }
    return res;
}
vector<int> kmv[64], qmv[64];

vector<int> pl;

vector<vector<int>> lst{{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 27, 18, 18, 45, 6, 0, 18, 0, 27, 36, 36, 45, 6, 0, 2, 27, 0, 36, 36, 45, 6, 0, 2, 27, 36, 0, 36, 45, 6, 0, 2, 27, 36, 36, 0, 45, 6, 0, 45, 45, 45, 45, 45, 0, 54, 0, 54, 54, 54, 54, 45, 54, 0}, {0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 28, 28, 28, 6, 17, 0, 19, 0, 28, 28, 28, 6, 25, 0, 3, 28, 0, 28, 37, 6, 33, 0, 19, 28, 28, 0, 37, 6, 41, 0, 37, 37, 37, 37, 0, 46, 49, 0, 46, 46, 46, 46, 46, 0, 41, 0, 55, 55, 55, 55, 46, 46}, {0, 0, 10, 0, 0, 0, 0, 0, 9, 0, 0, 0, 20, 20, 20, 6, 0, 18, 0, 29, 0, 29, 29, 6, 1, 26, 0, 38, 38, 0, 29, 6, 1, 34, 0, 38, 38, 4, 0, 38, 1, 42, 0, 38, 38, 38, 5, 0, 1, 42, 0, 47, 47, 47, 47, 6, 50, 42, 0, 50, 50, 50, 50, 0}, {0, 0, 0, 11, 0, 0, 0, 0, 1, 10, 0, 0, 0, 21, 21, 6, 17, 0, 27, 0, 30, 0, 21, 6, 0, 2, 27, 0, 35, 35, 0, 30, 1, 2, 35, 0, 27, 4, 5, 0, 1, 43, 43, 0, 39, 39, 5, 6, 1, 43, 43, 0, 43, 43, 59, 6, 1, 51, 51, 0, 51, 51, 51, 0}, {0, 0, 0, 0, 12, 0, 0, 0, 1, 18, 18, 0, 0, 0, 13, 6, 1, 18, 0, 31, 0, 28, 0, 22, 25, 0, 36, 36, 0, 28, 5, 0, 0, 2, 36, 36, 0, 36, 5, 6, 1, 2, 36, 36, 0, 36, 5, 6, 1, 44, 44, 44, 0, 52, 44, 6, 1, 52, 52, 52, 0, 52, 52, 0}, {0, 0, 0, 0, 0, 13, 0, 0, 1, 23, 23, 19, 0, 0, 0, 14, 1, 26, 26, 0, 29, 0, 21, 0, 1, 26, 0, 37, 37, 0, 29, 6, 33, 0, 19, 37, 37, 0, 37, 6, 0, 2, 37, 37, 37, 0, 45, 6, 1, 45, 45, 45, 45, 0, 45, 6, 1, 53, 53, 53, 53, 0, 45, 53}, {0, 0, 0, 0, 0, 0, 14, 0, 1, 22, 22, 22, 20, 0, 0, 0, 1, 27, 27, 27, 0, 20, 0, 22, 1, 34, 27, 0, 27, 4, 0, 30, 1, 34, 0, 27, 27, 4, 0, 38, 41, 0, 34, 38, 38, 38, 0, 46, 0, 41, 46, 46, 46, 46, 0, 54, 41, 54, 54, 54, 54, 54, 0, 46}, {0, 0, 0, 0, 0, 0, 0, 15, 1, 23, 23, 23, 23, 21, 0, 0, 1, 42, 31, 31, 28, 0, 21, 0, 1, 42, 35, 35, 0, 28, 5, 0, 1, 42, 35, 0, 28, 4, 5, 0, 1, 42, 0, 35, 39, 39, 5, 0, 49, 0, 42, 47, 47, 47, 47, 0, 0, 49, 55, 55, 55, 55, 55, 0}, {0, 0, 10, 11, 12, 13, 14, 13, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 35, 26, 1, 53, 14, 0, 26, 0, 35, 35, 44, 53, 14, 0, 10, 35, 0, 35, 44, 53, 14, 0, 10, 35, 35, 0, 44, 53, 14, 0, 44, 44, 44, 44, 0, 53, 14, 0, 53, 53, 53, 44, 53, 0, 53}, {0, 0, 0, 11, 12, 13, 14, 13, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 36, 36, 45, 14, 25, 0, 27, 0, 36, 36, 45, 14, 33, 0, 27, 36, 0, 36, 45, 14, 41, 0, 27, 36, 36, 0, 45, 14, 49, 0, 45, 45, 45, 45, 0, 54, 41, 0, 54, 54, 54, 45, 54, 0}, {17, 0, 0, 0, 12, 13, 14, 13, 0, 0, 18, 0, 0, 0, 0, 0, 17, 0, 0, 0, 28, 28, 28, 14, 0, 26, 0, 28, 0, 28, 37, 14, 9, 34, 0, 28, 28, 0, 37, 14, 9, 42, 0, 37, 37, 37, 0, 46, 9, 42, 0, 46, 46, 46, 46, 0, 50, 55, 0, 55, 55, 55, 46, 46}, {10, 9, 0, 0, 0, 13, 14, 13, 0, 0, 0, 19, 0, 0, 0, 0, 9, 18, 0, 0, 0, 29, 29, 14, 25, 0, 27, 0, 35, 0, 29, 14, 0, 10, 35, 0, 27, 4, 0, 38, 9, 43, 43, 0, 38, 4, 13, 0, 9, 47, 47, 0, 47, 47, 47, 14, 9, 51, 51, 0, 51, 51, 51, 9}, {10, 9, 10, 0, 0, 0, 14, 13, 0, 0, 0, 0, 20, 0, 0, 0, 9, 26, 26, 0, 0, 0, 21, 14, 9, 26, 0, 36, 0, 28, 0, 30, 33, 0, 36, 36, 0, 36, 5, 0, 0, 10, 39, 39, 0, 36, 5, 14, 9, 44, 44, 44, 0, 52, 5, 14, 9, 52, 52, 52, 0, 52, 52, 9}, {10, 9, 10, 11, 0, 0, 0, 6, 0, 0, 0, 0, 0, 21, 0, 0, 9, 27, 27, 27, 0, 0, 0, 22, 9, 34, 27, 0, 27, 0, 29, 0, 9, 34, 0, 27, 27, 0, 37, 6, 41, 0, 34, 37, 37, 0, 45, 6, 0, 41, 45, 45, 45, 0, 45, 6, 41, 53, 53, 53, 53, 0, 45, 53}, {10, 9, 10, 11, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 9, 42, 30, 30, 28, 0, 0, 0, 9, 42, 35, 35, 0, 28, 0, 30, 9, 42, 35, 0, 28, 12, 0, 38, 9, 42, 0, 35, 38, 38, 0, 46, 49, 0, 42, 46, 46, 46, 0, 54, 0, 49, 54, 54, 54, 54, 0, 46}, {10, 9, 10, 11, 12, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 9, 50, 31, 31, 31, 29, 0, 0, 9, 50, 36, 36, 36, 0, 29, 0, 9, 50, 36, 36, 0, 36, 13, 0, 9, 43, 43, 0, 36, 36, 13, 0, 9, 50, 0, 43, 47, 47, 47, 0, 50, 0, 50, 55, 55, 55, 55, 0}, {0, 9, 0, 8, 8, 8, 8, 22, 0, 0, 18, 19, 20, 21, 21, 21, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 43, 0, 52, 61, 22, 0, 34, 0, 43, 8, 52, 61, 22, 0, 2, 43, 0, 43, 0, 61, 22, 0, 2, 43, 43, 0, 52, 0, 22, 0, 52, 52, 43, 52, 0, 52, 0}, {9, 0, 10, 0, 9, 9, 9, 22, 0, 0, 0, 19, 20, 21, 21, 21, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 35, 44, 53, 22, 33, 0, 35, 0, 35, 44, 53, 22, 41, 0, 35, 35, 0, 44, 53, 22, 49, 0, 44, 44, 44, 0, 53, 22, 41, 0, 53, 53, 44, 53, 0, 53}, {0, 9, 0, 11, 0, 10, 10, 22, 9, 0, 0, 0, 20, 21, 21, 21, 0, 0, 27, 0, 0, 0, 0, 0, 25, 0, 0, 0, 36, 36, 45, 22, 0, 34, 0, 36, 0, 36, 45, 22, 17, 42, 0, 36, 36, 0, 45, 22, 17, 42, 0, 45, 45, 45, 0, 54, 50, 54, 0, 54, 54, 45, 54, 0}, {17, 0, 10, 0, 12, 0, 11, 22, 18, 18, 0, 0, 0, 21, 21, 21, 0, 0, 0, 27, 0, 0, 0, 0, 17, 26, 0, 0, 0, 28, 5, 22, 33, 0, 35, 0, 28, 0, 37, 22, 0, 43, 43, 0, 37, 37, 0, 46, 17, 46, 46, 0, 46, 46, 46, 0, 17, 55, 55, 0, 55, 55, 46, 46}, {17, 12, 0, 11, 0, 13, 0, 13, 18, 18, 18, 0, 0, 0, 13, 13, 0, 0, 0, 0, 28, 0, 0, 0, 17, 34, 27, 0, 0, 0, 29, 6, 17, 34, 0, 36, 0, 36, 0, 38, 41, 0, 34, 38, 0, 36, 13, 0, 0, 41, 47, 47, 0, 47, 13, 6, 41, 52, 52, 52, 0, 52, 52, 6}, {17, 13, 13, 0, 12, 0, 14, 0, 18, 18, 18, 19, 0, 0, 0, 14, 0, 0, 0, 0, 0, 29, 0, 0, 17, 42, 35, 35, 0, 0, 0, 30, 17, 42, 35, 0, 28, 0, 37, 0, 17, 42, 0, 35, 39, 0, 45, 14, 49, 0, 42, 45, 45, 0, 45, 14, 0, 49, 53, 53, 53, 0, 45, 53}, {17, 14, 14, 14, 0, 13, 0, 14, 18, 18, 18, 19, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 17, 50, 36, 36, 36, 0, 0, 0, 17, 50, 19, 36, 0, 36, 0, 38, 17, 43, 43, 0, 36, 36, 0, 46, 17, 50, 0, 43, 46, 46, 0, 54, 50, 0, 50, 54, 54, 54, 0, 46}, {17, 15, 15, 15, 15, 0, 14, 0, 18, 18, 18, 19, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 17, 58, 51, 39, 39, 37, 0, 0, 17, 58, 19, 15, 44, 0, 37, 0, 17, 58, 7, 39, 0, 37, 21, 0, 17, 7, 47, 0, 44, 47, 47, 0, 7, 55, 0, 51, 55, 55, 55, 0}, {0, 8, 10, 0, 8, 8, 8, 8, 0, 17, 0, 16, 16, 16, 16, 30, 0, 0, 26, 27, 28, 28, 28, 30, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 27, 27, 60, 29, 30, 0, 42, 0, 27, 27, 0, 29, 30, 0, 42, 42, 0, 42, 42, 0, 30, 0, 42, 42, 51, 0, 51, 51, 0}, {17, 0, 9, 11, 0, 9, 9, 9, 9, 0, 18, 0, 17, 17, 17, 30, 0, 0, 0, 27, 28, 28, 28, 30, 0, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 27, 4, 61, 30, 41, 0, 43, 0, 43, 9, 61, 30, 49, 0, 43, 43, 0, 52, 9, 30, 41, 0, 52, 43, 52, 0, 52, 9}, {10, 18, 0, 10, 12, 0, 10, 10, 0, 18, 0, 19, 0, 18, 18, 30, 17, 0, 0, 0, 28, 28, 5, 30, 0, 0, 27, 0, 0, 0, 0, 0, 33, 0, 0, 0, 27, 12, 5, 30, 0, 42, 0, 35, 0, 44, 5, 30, 25, 42, 0, 44, 44, 0, 53, 30, 50, 53, 0, 53, 44, 53, 0, 53}, {0, 9, 11, 0, 11, 13, 0, 13, 9, 0, 18, 0, 20, 0, 13, 13, 25, 18, 0, 0, 0, 20, 20, 6, 0, 0, 0, 35, 0, 0, 0, 0, 25, 34, 0, 0, 0, 36, 13, 6, 41, 0, 43, 0, 36, 0, 45, 6, 0, 41, 45, 0, 45, 45, 0, 54, 41, 54, 54, 0, 54, 45, 54, 0}, {10, 0, 10, 12, 0, 12, 14, 0, 25, 10, 0, 19, 0, 21, 0, 14, 25, 27, 27, 0, 0, 0, 21, 21, 0, 0, 0, 0, 36, 0, 0, 0, 25, 42, 35, 0, 0, 0, 37, 14, 25, 42, 0, 35, 0, 37, 0, 46, 49, 0, 42, 46, 0, 46, 46, 0, 0, 49, 55, 55, 0, 55, 46, 46}, {13, 13, 0, 11, 13, 0, 21, 13, 25, 21, 21, 0, 20, 0, 21, 0, 25, 27, 27, 27, 0, 0, 0, 22, 0, 0, 0, 0, 0, 28, 0, 0, 25, 50, 27, 36, 0, 0, 0, 38, 25, 43, 43, 0, 36, 0, 45, 0, 25, 50, 0, 43, 47, 0, 45, 22, 50, 0, 50, 53, 53, 0, 45, 53}, {14, 14, 14, 0, 12, 14, 0, 22, 25, 22, 22, 22, 0, 21, 0, 14, 25, 27, 27, 27, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 25, 58, 27, 28, 28, 0, 0, 0, 25, 58, 27, 39, 0, 37, 0, 46, 25, 14, 46, 0, 44, 46, 0, 54, 14, 54, 0, 51, 54, 54, 0, 46}, {15, 15, 15, 15, 0, 13, 15, 0, 25, 23, 23, 23, 23, 0, 22, 0, 25, 27, 27, 27, 28, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 25, 26, 27, 28, 28, 52, 0, 0, 25, 26, 27, 39, 39, 0, 45, 0, 25, 7, 47, 47, 0, 45, 45, 0, 7, 55, 55, 0, 52, 55, 55, 0}, {0, 8, 8, 11, 0, 8, 8, 8, 0, 18, 18, 0, 16, 16, 16, 38, 0, 18, 0, 24, 24, 24, 37, 38, 0, 0, 34, 35, 36, 36, 37, 38, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 36, 36, 36, 38, 0, 41, 0, 35, 36, 36, 0, 38, 0, 41, 50, 0, 50, 50, 50, 0}, {17, 0, 9, 9, 12, 0, 9, 9, 9, 0, 26, 19, 0, 17, 17, 38, 17, 0, 26, 0, 25, 25, 5, 38, 0, 0, 0, 35, 36, 36, 5, 38, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 36, 36, 5, 38, 49, 0, 42, 0, 36, 36, 9, 38, 41, 0, 42, 51, 0, 51, 51, 9}, {10, 18, 0, 10, 10, 13, 0, 13, 18, 18, 0, 27, 20, 0, 13, 13, 0, 18, 0, 27, 0, 20, 20, 6, 25, 0, 0, 0, 36, 36, 13, 6, 0, 0, 35, 0, 0, 0, 0, 0, 41, 0, 0, 0, 36, 36, 13, 6, 0, 42, 0, 43, 0, 52, 18, 6, 50, 52, 0, 43, 52, 0, 52, 18}, {17, 11, 11, 0, 11, 11, 14, 0, 0, 17, 27, 0, 28, 21, 0, 14, 17, 0, 27, 0, 28, 0, 21, 21, 33, 26, 0, 0, 0, 28, 28, 14, 0, 0, 0, 27, 0, 0, 0, 0, 33, 42, 0, 0, 0, 36, 21, 14, 49, 0, 42, 0, 44, 0, 53, 14, 0, 49, 53, 0, 44, 53, 0, 53}, {0, 9, 12, 12, 0, 12, 12, 22, 9, 0, 18, 20, 0, 28, 22, 0, 33, 18, 0, 27, 0, 28, 0, 22, 33, 34, 27, 0, 0, 0, 29, 29, 0, 0, 0, 0, 28, 0, 0, 0, 33, 43, 43, 0, 0, 0, 45, 22, 33, 50, 0, 43, 0, 45, 0, 54, 50, 0, 50, 54, 0, 45, 54, 0}, {10, 0, 10, 13, 13, 0, 21, 13, 33, 10, 0, 19, 21, 0, 21, 21, 33, 34, 19, 0, 28, 0, 21, 0, 33, 34, 36, 35, 0, 0, 0, 30, 0, 0, 0, 0, 0, 36, 0, 0, 33, 58, 35, 35, 0, 0, 0, 46, 33, 21, 46, 0, 44, 0, 46, 0, 21, 55, 0, 51, 55, 0, 46, 46}, {14, 14, 0, 11, 14, 14, 0, 22, 33, 22, 22, 0, 20, 22, 0, 14, 33, 34, 30, 30, 0, 29, 0, 22, 33, 34, 36, 35, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37, 0, 33, 35, 35, 35, 36, 0, 0, 0, 33, 14, 47, 47, 0, 45, 0, 54, 14, 54, 54, 0, 52, 54, 0, 46}, {15, 15, 15, 0, 12, 15, 15, 0, 33, 23, 23, 23, 0, 21, 21, 0, 33, 34, 31, 31, 31, 0, 21, 0, 33, 34, 36, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 33, 35, 35, 35, 36, 37, 0, 0, 33, 7, 47, 47, 47, 0, 46, 0, 7, 55, 55, 55, 0, 53, 55, 0}, {0, 8, 8, 8, 12, 0, 8, 8, 0, 32, 26, 19, 0, 16, 16, 46, 0, 26, 26, 0, 24, 24, 5, 46, 0, 26, 0, 32, 32, 44, 5, 46, 0, 0, 19, 43, 44, 12, 5, 46, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 45, 45, 0, 49, 0, 43, 44, 45, 45, 46}, {17, 0, 9, 9, 9, 13, 0, 13, 9, 0, 27, 27, 20, 0, 13, 13, 17, 0, 27, 27, 0, 20, 20, 6, 25, 0, 27, 0, 27, 44, 13, 6, 0, 0, 0, 27, 27, 27, 13, 6, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 44, 45, 45, 6, 50, 0, 50, 0, 44, 45, 45, 46}, {10, 18, 0, 10, 10, 10, 14, 0, 18, 18, 0, 21, 28, 21, 0, 14, 18, 18, 0, 35, 28, 0, 21, 21, 0, 26, 0, 35, 0, 28, 28, 14, 33, 0, 0, 0, 35, 35, 21, 14, 0, 0, 34, 0, 0, 0, 0, 0, 49, 0, 0, 0, 44, 45, 45, 14, 0, 49, 0, 51, 0, 45, 45, 46}, {27, 11, 11, 0, 11, 11, 11, 22, 41, 27, 27, 0, 22, 29, 22, 0, 0, 27, 27, 0, 36, 29, 0, 22, 25, 0, 27, 0, 36, 0, 29, 29, 41, 34, 0, 0, 0, 36, 36, 22, 0, 0, 0, 35, 0, 0, 0, 0, 42, 42, 0, 0, 0, 45, 45, 22, 50, 0, 50, 0, 52, 0, 45, 46}, {17, 12, 12, 12, 0, 12, 12, 28, 0, 17, 20, 20, 0, 28, 28, 30, 17, 0, 26, 28, 0, 28, 28, 0, 41, 26, 0, 35, 0, 28, 0, 30, 41, 42, 35, 0, 0, 0, 37, 37, 0, 0, 0, 0, 36, 0, 0, 0, 42, 42, 42, 0, 0, 0, 45, 30, 41, 42, 0, 51, 0, 53, 0, 46}, {0, 9, 13, 13, 13, 0, 21, 13, 9, 0, 18, 21, 21, 0, 21, 21, 41, 18, 0, 27, 29, 0, 21, 21, 41, 42, 27, 0, 36, 0, 29, 0, 41, 42, 43, 36, 0, 0, 0, 38, 0, 0, 0, 0, 0, 37, 0, 0, 42, 42, 42, 43, 0, 0, 0, 54, 41, 42, 42, 0, 52, 0, 54, 0}, {10, 0, 10, 14, 14, 14, 0, 22, 41, 10, 0, 19, 22, 22, 0, 14, 41, 42, 19, 0, 28, 28, 0, 22, 41, 42, 43, 28, 0, 28, 0, 30, 41, 42, 43, 28, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45, 0, 42, 42, 42, 43, 44, 0, 0, 0, 41, 42, 42, 43, 0, 53, 0, 55}, {15, 15, 0, 11, 15, 15, 15, 0, 41, 23, 23, 0, 20, 23, 39, 0, 41, 42, 31, 31, 0, 29, 45, 0, 41, 42, 43, 39, 39, 0, 29, 0, 41, 42, 43, 43, 44, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 42, 42, 42, 43, 44, 45, 0, 0, 41, 42, 42, 43, 44, 0, 54, 0}, {0, 8, 8, 8, 8, 13, 0, 13, 0, 32, 27, 27, 20, 0, 13, 13, 0, 34, 27, 27, 0, 20, 20, 6, 0, 34, 27, 0, 27, 27, 13, 6, 0, 34, 0, 27, 27, 27, 13, 6, 0, 0, 34, 32, 32, 32, 13, 6, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 51, 52, 53, 54, 53}, {17, 0, 9, 9, 9, 9, 14, 0, 9, 0, 21, 21, 28, 21, 0, 14, 17, 0, 35, 35, 28, 0, 21, 21, 25, 0, 35, 35, 0, 28, 28, 14, 33, 0, 35, 0, 35, 35, 21, 14, 0, 0, 0, 35, 33, 35, 21, 14, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0, 51, 52, 53, 54, 53}, {10, 18, 0, 10, 10, 10, 10, 22, 18, 18, 0, 22, 22, 29, 22, 0, 18, 18, 0, 29, 36, 29, 0, 22, 26, 26, 0, 36, 36, 0, 29, 29, 0, 34, 0, 36, 0, 36, 36, 22, 41, 0, 0, 0, 36, 36, 36, 22, 0, 0, 42, 0, 0, 0, 0, 0, 57, 0, 0, 0, 52, 53, 54, 53}, {27, 11, 11, 0, 11, 11, 11, 35, 49, 27, 27, 0, 23, 23, 35, 30, 49, 27, 27, 0, 30, 37, 37, 0, 0, 50, 27, 0, 35, 44, 0, 30, 33, 0, 35, 0, 35, 0, 37, 37, 49, 42, 0, 0, 0, 44, 44, 30, 0, 0, 0, 43, 0, 0, 0, 0, 50, 49, 0, 0, 0, 53, 54, 53}, {36, 12, 12, 12, 0, 12, 12, 28, 49, 36, 20, 20, 0, 28, 28, 38, 0, 50, 28, 28, 0, 28, 28, 38, 25, 0, 36, 36, 0, 28, 45, 0, 49, 34, 0, 36, 0, 36, 0, 38, 49, 50, 43, 0, 0, 0, 45, 45, 0, 0, 0, 0, 44, 0, 0, 0, 50, 49, 50, 0, 0, 0, 54, 53}, {17, 13, 13, 13, 13, 0, 21, 13, 0, 17, 21, 21, 21, 0, 21, 21, 17, 0, 26, 29, 29, 0, 21, 21, 49, 26, 0, 35, 35, 0, 29, 29, 49, 50, 35, 0, 35, 0, 37, 0, 49, 50, 35, 35, 0, 0, 0, 46, 0, 0, 0, 0, 0, 45, 0, 0, 50, 49, 50, 51, 0, 0, 0, 46}, {0, 9, 14, 14, 14, 14, 0, 22, 9, 0, 18, 22, 22, 22, 0, 14, 49, 18, 0, 27, 30, 30, 0, 22, 49, 50, 27, 0, 36, 36, 0, 30, 49, 50, 51, 36, 0, 36, 0, 38, 49, 50, 38, 38, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 50, 49, 50, 51, 52, 0, 0, 0}, {10, 0, 10, 15, 15, 15, 15, 0, 49, 10, 0, 19, 23, 23, 39, 0, 49, 50, 19, 0, 28, 28, 53, 0, 49, 50, 51, 28, 0, 28, 53, 0, 49, 50, 51, 28, 28, 0, 37, 0, 49, 50, 39, 39, 39, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 50, 49, 50, 51, 52, 53, 0, 0}, {0, 8, 8, 8, 8, 8, 14, 0, 0, 32, 21, 21, 28, 21, 0, 14, 0, 42, 35, 35, 28, 0, 21, 21, 0, 42, 35, 35, 0, 28, 28, 14, 0, 42, 35, 0, 35, 35, 21, 14, 0, 42, 0, 35, 32, 35, 21, 14, 0, 0, 42, 40, 40, 40, 40, 14, 48, 0, 0, 0, 0, 0, 0, 0}, {17, 0, 9, 9, 9, 9, 9, 22, 9, 0, 22, 22, 22, 29, 22, 0, 17, 0, 29, 29, 36, 29, 0, 22, 25, 0, 43, 36, 36, 0, 29, 29, 33, 0, 43, 36, 0, 36, 36, 22, 41, 0, 43, 0, 36, 36, 36, 22, 0, 0, 0, 43, 41, 41, 41, 22, 0, 49, 0, 0, 0, 0, 0, 0}, {10, 18, 0, 10, 10, 10, 10, 42, 18, 18, 0, 23, 23, 23, 42, 30, 18, 18, 0, 30, 30, 37, 37, 0, 26, 26, 0, 37, 44, 44, 0, 30, 34, 34, 0, 50, 44, 0, 37, 37, 0, 42, 0, 44, 0, 44, 44, 30, 49, 0, 0, 0, 44, 42, 44, 30, 0, 0, 50, 0, 0, 0, 0, 0}, {27, 11, 11, 0, 11, 11, 11, 35, 57, 27, 27, 0, 19, 19, 35, 38, 57, 27, 27, 0, 31, 31, 45, 38, 57, 58, 27, 0, 35, 35, 45, 0, 0, 58, 35, 0, 35, 52, 0, 38, 41, 0, 43, 0, 43, 0, 45, 45, 57, 50, 0, 0, 0, 45, 45, 45, 0, 0, 0, 51, 0, 0, 0, 0}, {36, 12, 12, 12, 0, 12, 12, 28, 57, 36, 20, 20, 0, 28, 28, 46, 57, 58, 28, 28, 0, 28, 28, 46, 0, 58, 36, 36, 0, 28, 53, 46, 33, 0, 36, 36, 0, 36, 53, 0, 57, 42, 0, 44, 0, 44, 0, 46, 57, 42, 42, 0, 0, 0, 53, 53, 0, 0, 0, 0, 52, 0, 0, 0}, {45, 13, 13, 13, 13, 0, 21, 13, 57, 45, 21, 21, 21, 0, 21, 21, 0, 58, 29, 29, 29, 0, 21, 21, 25, 0, 43, 37, 37, 0, 29, 29, 57, 34, 0, 43, 53, 0, 37, 37, 57, 58, 43, 0, 37, 0, 45, 0, 57, 45, 45, 43, 0, 0, 0, 54, 0, 0, 0, 0, 0, 53, 0, 0}, {17, 14, 14, 14, 14, 14, 0, 22, 0, 17, 22, 22, 22, 22, 0, 14, 17, 0, 26, 30, 30, 30, 0, 22, 57, 26, 0, 35, 35, 44, 0, 30, 57, 58, 35, 0, 35, 60, 0, 38, 57, 58, 35, 35, 0, 44, 0, 46, 57, 46, 46, 46, 44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0}, {0, 9, 15, 15, 15, 15, 15, 0, 9, 0, 18, 23, 23, 23, 39, 0, 57, 18, 0, 27, 31, 31, 61, 0, 57, 58, 27, 0, 36, 36, 61, 0, 57, 58, 59, 36, 0, 36, 61, 0, 57, 58, 39, 39, 36, 0, 45, 0, 57, 47, 47, 47, 47, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55}};

int cnt_move = 0;

bool op_move(int qpl) {
    string s;
    cin >> s;
    if (s == "Done") return true;
    int dir = moves[s];
    vector<int> npl;
    for (int i : pl) {
        int num = king_move(i, dir);
        if (num != -1) {
            bool bad = false;
            for (int j : qmv[qpl]) {
                bad |= (j == num);
            }
            if (!bad) npl.pb(num);
        }
    }
    pl = npl;
    ++cnt_move;
    return false;
}

void run() {
    pl.resize(64);
    iota(all(pl), 0);

    cnt_move = 0;

    int qpl = 0;
    for (auto i : vector<int>{27, 45, 9, 11, 14}) {
        qpl = i;
        cout << qpl / 8 + 1 << " " << qpl % 8 + 1 << endl;
        if (op_move(qpl)) return;
    }

    while (true) {
        qpl = lst[qpl][pl[0]];
        cout << qpl / 8 + 1 << " " << qpl % 8 + 1 << endl;
        if (op_move(qpl)) {
            assert(cnt_move <= 15);
            return;
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    

    

#endif
    
    for (int i = 0; i < 64; ++i) {
        kmv[i] = king_move(i);
        qmv[i] = queen_move(i);
    }

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}