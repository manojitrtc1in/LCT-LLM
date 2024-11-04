



































































using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef string stirng;






















struct tre {
    ll fi, se, tr;
};


struct way {
    int X, Y;
    int stp, mood, K, D, h, id, mh;
};





ll n, m;

bool in_field(int x, int y) {
    re(x >= 0 && y >= 0 && x < 8 && y < 8);
}


int tpp = 1;



int a[101];
int b[101];




void solve() {
    FstPrt;

    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        cin >> b[i];
    vector<pii> ans;
    bool ch = 1;
    while (ch) {
        ch = 0;
        frs(i, 1, n) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                swap(b[i], b[i - 1]);
                ans.pb(i, i - 1);
                cont;
            }
            if (a[i] == a[i - 1]) {
                if (b[i] < b[i - 1]) {
                    swap(b[i], b[i - 1]);
                    ans.pb(i, i - 1);
                }
            }
        }
        frs(i, 1, n) {
            if (a[i] < a[i - 1])
                ch = 1;
        }
        if (!ch)
            frs(i, 1, n)
            if (a[i] == a[i - 1] && b[i] < b[i - 1])
                ch = 1;
    }
    frs(i, 1, n)
        if (b[i] < b[i - 1]) {
            cout << -1 << '\n';
            re;
        }
    cout << siz(ans) << '\n';
    for (auto i : ans)
        cout << i.fi + 1 << " " << i.se + 1 << '\n';
}




int main() {
    


    freopen("INPUT.txt", "r", stdin);
    freopen("INPUT.txt", "w", stdout);

    FstPrt;



    cin >> tpp;
    while (tpp--) {
        solve();
    }

}