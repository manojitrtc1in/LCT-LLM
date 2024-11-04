



using namespace std;





typedef long long ll;
typedef pair<int, int> ii;

int n, a[5000], dp[5001][5001], max_mod[7], ans = 2;
unordered_map<int, int> max_val;

inline void update(int &x, const int &val) {
    if(val > x)
        x = val;
}

void solve() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
        scanf("%d", &a[i]);
    for(int i = 1;i <= n;i++) {
        dp[0][i] = 1;
        for(int j = 1;j < i;j++)
            if(abs(a[i - 1] - a[j - 1]) == 1 || (a[i - 1] % 7) == (a[j - 1] % 7))
                update(dp[0][i], dp[0][j] + 1);
        dp[i][0] = dp[0][i];
    }
    for(int i = 1;i <= n;i++) {
        for(int k = 0;k < 7;k++)
            max_mod[k] = 0;
        for(const ii &e : max_val)
            if(e.Y != 0)
                max_val[e.X] = 0;
        for(int j = i - 1;j >= 0;j--) {
            update(max_mod[a[j - 1] % 7], dp[j][i]);
            update(max_val[a[j - 1]], dp[j][i]);
        }
        for(int j = i + 1;j <= n;j++) {
            const int &aj = a[j - 1];
            dp[i][j] = max(max(max_mod[aj % 7] + 1, max_val[aj + 1] + 1), max(max_val[aj - 1] + 1, dp[i][0] + 1));
            update(ans, dp[i][j]);
            update(max_mod[aj % 7], dp[i][j]);
            update(max_val[aj], dp[i][j]);
        }
    }
    printf("%d", ans);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}