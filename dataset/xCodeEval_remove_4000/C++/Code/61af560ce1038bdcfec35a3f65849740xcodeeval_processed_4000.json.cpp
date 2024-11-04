




using namespace std;

int h, w, x, y, ans = 999999999;
int a[1000], p[1000];
char st[1001];
int dp[1000][1001][2];
int mn[1000][2];

int getSum(const int &i, const int &j) {
    return p[j] - (i ? p[i - 1] : 0);
}

void calc(const int &k, const int &s, const bool &c) {
    if (k < s - 1)
        dp[k][s][c] = 999999999;
    else if (k == s - 1) {
        if (c == 0)
            dp[k][s][c] = getSum(0, k);
        else
            dp[k][s][c] = h * s - getSum(0, k);
    } else {
        dp[k][s][c] = mn[k - s][1 - c];
        if (c == 0)
            dp[k][s][c] += getSum(k - s + 1, k);
        else
            dp[k][s][c] += h * s - getSum(k - s + 1, k);
    }
    if (x <= s && s <= y) {
        if (mn[k][c] != -1)
            mn[k][c] = min(mn[k][c], dp[k][s][c]);
        else
            mn[k][c] = dp[k][s][c];
    }
}

void solve() {
    scanf("%d %d %d %d ", &h, &w, &x, &y);
    for (int i = 0; i < h; i++) {
        gets(st);
        for (int j = 0; j < w; j++)
            a[j] += (st[j] == '
    }
    for (int i = 0; i < 1000; i++) {
        mn[i][0] = mn[i][1] = -1;
        for (int j = 0; j < 1001; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
    }
    p[0] = a[0];
    for (int i = 1; i < w; i++)
        p[i] = p[i - 1] + a[i];

    for (int k = 0; k < w; k++)
        for (int s = 1; s <= y; s++) {
            calc(k, s, 0);
            calc(k, s, 1);
        }
        
    for (int s = x; s <= y; s++)
        ans = min({ans, dp[w - 1][s][0], dp[w - 1][s][1]});
    printf("%d", ans);
}

int main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false);
    if (!ONLINE_JUDGE) {





    } else
        freopen("input.txt", "r", stdin);


    solve();
    return 0;
}
