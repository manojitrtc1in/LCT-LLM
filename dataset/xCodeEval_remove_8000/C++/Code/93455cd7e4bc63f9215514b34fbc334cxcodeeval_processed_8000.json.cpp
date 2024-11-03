



































































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

int kol[50][500000];
int w[50][500000];



void solve() {
    FstPrt;

    cin >> n >> m;
    fr(i, 50)
        fr(j, m) {
        w[i][j] = 0;
        kol[i][j] = 0;
    }
    fr(i, n)
        fr(j, m) {
        char a;
        cin >> a;
        kol[a - 'a'][j]++;
    }
    fr(i, n - 1)
        fr(j, m) {
        char a;
        cin >> a;
        w[a - 'a'][j]++;
    }
    string ans;
    fr(j, m) {
        for (char i = 'a'; i <= 'z'; i++) {
            if (kol[i - 'a'][j] != w[i - 'a'][j]) {
                ans.ppb(i);
                break;
            }
        }
    }
    cout << ans << endl;
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