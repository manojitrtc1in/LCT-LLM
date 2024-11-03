#include <iostream>



using namespace std;






const int N = 2e5 + 7, INF = 1e9 + 7;

int v[N], dp[N], panta[N], start[N];
bool ans[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    dp[0] = INF;
    v[n + 1] = INF;
    for (int i = n; i >= 1; --i) {
        if (v[i] > v[i + 1])
            panta[i] = panta[i + 1];
        else
            panta[i] = i, start[i + 1] = i + 1;
    }
    for (int i = 2; i <= n; ++i)
        if (start[i] == 0)
            start[i] = start[i - 1];
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i)
        cout << start[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i)
        cout << panta[i] << ' ';
    cout << '\n';
    #endif
    v[0] = INF;
    int ceva(1);
    for (int i = 1; i <= n; ++i) {
        if (v[i] <= v[i - 1]) {
            if (start[i - 1] != 0 && v[start[i - 1] - 1] >= v[i])
                dp[i] = -1;
            else if (start[i - 1] != 0 && dp[start[i - 1] - 1] <= v[start[i]])
                dp[i] = -1;
            else
                dp[i] = v[i - 1];
            if (v[i] == v[i - 1])
                ceva = 0;
            if (dp[i] != -1)
                ceva = 1;
        }
        else {
            dp[i] = -1;
            if (start[i - 1] == i - 1) {
                if (dp[i - 2] > v[i - 1])
                    dp[i] = v[i - 1];
                dp[i] = max(dp[i], dp[i - 1]);
            }
            else {
                dp[i] = -1;
                if (dp[i - 1] != -1) {
                    ceva = 0;
                    dp[i] = dp[i - 1];
                    continue;
                }
                if (v[start[i - 1]] < v[i]) {
                    if (dp[start[i - 1]] > v[start[i - 1] + 1]) {
                        ceva = 0;
                        dp[i] = v[i - 1];
                        continue;
                    }
                }
                if (ceva) {
                    ceva = 0;
                    dp[i] = v[i - 1];
                    continue;
                }
                if (start[i - 1] != 0 && dp[start[i - 1] - 1] > v[start[i - 1]] && v[start[i - 1] - 1] < v[i]) {
                    ceva = 0;
                    dp[i] = v[i - 1];
                    continue;
                }
                ceva = 0;
            }
        }
    }
    #ifdef DEBUG

    for (int i = 1; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << '\n';

    #endif
    for (int i = 1; i <= n; ++i)
        ans[i] = 1;
    int cur(n), anterior = -1;
    bool sol(0);
    for (int i = n; i >= 0; --i) {

        if ((i == cur || dp[i] > v[i + 1]) && start[cur] <= i + 1 && v[i] < v[cur + 1] && dp[i] != -1 && (i == cur || v[cur] > anterior)) {
            if (i != n)
                anterior = -1;
            else if (i != cur)
                anterior = v[i + 1];
            cur = i - 1;
            ans[i] = 0;
            sol = 1;
        }
    }
    if (sol)
        cout << "YES\n";
    else {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}





