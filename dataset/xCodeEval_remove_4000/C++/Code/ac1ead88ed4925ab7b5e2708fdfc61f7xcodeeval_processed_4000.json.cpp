



using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int INF = 1 << 30;

const int maxn = 55;
const int c = 28;

int n[2], d[maxn][maxn];
string s[2];
bool cv[2][maxn][maxn][c];
vector <string> vec[c];

int main() {

    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(6);

    for(int i = 0; i < 2; i++) {
        cin >> s[i];
        n[i] = s[i].size();
    }

    int q;
    cin >> q;

    while(q--) {
        string t;
        cin >> t;
        vec[t[0] - 'a'].push_back(t.substr(3));
    }

    for(int w = 0; w < 2; w++) {
        for(int r = 1; r <= n[w]; r++) {
            for(int l = r - 1; ~l; l--) {
                for(int c = 0; c < 26; c++) {
                    if(r - l == 1) {
                        cv[w][l][r][c] = s[w][l] - 'a' == c;
                    } else {
                        for(string t: vec[c]) {
                            for(int j = l; j + 1 < r; j++) {
                                cv[w][l][r][c] |= cv[w][l][j + 1][t[0] - 'a'] & cv[w][j + 1][r][t[1] - 'a'];
                            }
                        }
                    }
                }
            }
        }
    }

    memset(d, 63, sizeof d);
    d[0][0] = 0;

    for(int a = 1; a <= n[0]; a++) {
        for(int b = 1; b <= n[1]; b++) {
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++) {
                    for(int c = 0; c < 26; c++) {
                        if(cv[0][i][a][c] && cv[1][j][b][c])
                            d[a][b] = min(d[a][b], d[i][j] + 1);
                    }
                }
            }
        }
    }

    if(d[n[0]][n[1]] > 1e8)
        cout << "-1\n";
    else
        cout << d[n[0]][n[1]] << "\n";

}