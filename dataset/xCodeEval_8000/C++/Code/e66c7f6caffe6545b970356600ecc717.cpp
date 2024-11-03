

#include <bits/stdc++.h>

#define x first 
#define y second 

using namespace std;

typedef pair<int, int> PII;
const double eps = 1e-4;
const int N = 200010;
 
int n, q, T;
map<int, PII> mp;

int main()
{ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        mp.clear();
        int t;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            if (!mp[t].x) mp[t].x = i;
            mp[t].y = i;
        }

        int a, b;
        while (q--) {
            cin >> a >> b;
            if (!mp[a].x || !mp[b].y) cout << "NO" << endl;
            else {
                if (mp[a].x <= mp[b].y) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }

    }
    return 0;
}
    



