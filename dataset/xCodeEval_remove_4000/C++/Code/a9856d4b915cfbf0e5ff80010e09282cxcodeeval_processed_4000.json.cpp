































using namespace std;




typedef long long ll;
typedef long double lb;











const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 1e4;














































































































ll n, m, k, l, r, cnt, sum, flag, mid, ans, x, y;
ll arr[110][N];
char j;
string s;

void solve() {
    cin >> n >> m;
    rep(i, 0, m) { rep(j, 0, 100) arr[j][i] = 0; }
    rep(i, 1, n) {
        cin >> s;
        rep(j, 0, m - 1) arr[s[j] - 'a'][j]++;
    }
    rep(i, 1, n - 1) {
        cin >> s;
        rep(j, 0, m - 1) arr[s[j] - 'a'][j]--;
    }
    rep(i, 0, m) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (arr[j - 'a'][i]) {
                cout << j;
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    

    

    IOS int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}



































































































































































