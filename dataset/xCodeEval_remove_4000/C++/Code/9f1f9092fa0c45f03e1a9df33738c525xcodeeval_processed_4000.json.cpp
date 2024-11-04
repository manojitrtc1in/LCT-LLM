




































































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
    re(x >= 0 && y >= 0 && x < n&& y < m);
}


int tpp = 1;

ll mas[200500];
ll kol[15];

ll check(ll k) {
   

    int i = 0;
    set<int> bad;
    set<int> al;
    for (; i < k; i++) {
        kol[mas[i]]++;
        al.insert(mas[i]);
    }
    ll ans = 0;
    bool ch = 1;
    fr(k, 10)
        if (kol[k] > siz(al)) {
            ch = 0;
            break;
        }
    ans += (ch);
    for (int j = 0; i < n; j++, i++) {
        kol[mas[j]]--;
        kol[mas[i]]++;
        if (kol[mas[j]] == 0)
            al.erase(mas[j]);
        al.insert(mas[i]);
        
        bool ch = 1;
        fr(k, 10)
            if (kol[k] > siz(al)) {
                ch = 0;
                break;
            }
        ans += (ch);
    }
    fr(i, 10)
        kol[i] = 0;
    re ans;
}


void solve() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin >> n;
    string s;
    cin >> s;
    fr(i, n)
        mas[i] = s[i] - '0';
    ll kol = 0;
    frs(i, 1, min((ll)n + 1, (ll)102))
        kol += check(i);
    cout << kol << '\n';
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