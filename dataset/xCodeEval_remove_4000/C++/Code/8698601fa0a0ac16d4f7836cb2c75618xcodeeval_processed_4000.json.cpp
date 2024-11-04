



































































using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef vector<long long> vii;
typedef pair<ll, ll> pii;
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
    re(x >= 0 && y >= 0 && x < n&& y < m);
}


int tp = 1;

bool A[301];


void solve() {
    FstPrt;

    cin >> n;
    ll f = 0;
    ll sum = 0;
    bool ch = 0;
    ll kol = 0;
    ll mi = 50000000000;
    ll mmi = mi;
    vector <ll> al;
    fr(i, n) {
        ll x;
        cin >> x;
        if (i == 0)
            f = x;
        else {
            if (x == 1)
                ch = 1;
            mi = min(mi, x);
        }
    }
    if (f == 1 || (f == 2 && !ch) || (f <= mi) || (f - 1 < mi)) {
        cout << "Bob" << '\n';
        re;
    }
    cout << "Alice" << '\n';
}





int main() {
    


    freopen("INPUT.txt", "r", stdin);
    freopen("INPUT.txt", "w", stdout);

    FstPrt;



    cin >> tp;
    while (tp--)
        solve();

}