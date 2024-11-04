



using namespace __gnu_pbds; 
using namespace std;
 









    



    


using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int grand(int x) { 

    return uniform_int_distribution<int>(0, x - 1)(rng);
}









typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int getInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}


ll gcd(ll x, ll y) {
    if (x < y) return gcd(y, x);
    if (y == 0) return x;
    return gcd(y, x % y);
} 

const ll mod = 1e9 + 7;

ll modexp(ll x, ll ex) {
    ll ans = 1ll;
    while (ex > 0) {
        if (ex & 1ll) ans = (ans * x) % mod;
        ex >>= 1ll;
        x = (x * x) % mod;
    }
    return ans;
}

const int maxn = 53;

const ll inf = 1e9 + 7;

int q = 0;

int ask(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return ask(x2, y2, x1, y1);
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    fflush(stdout);
    int r; cin >> r;
    

    return r;
}

int n;
int a[maxn][maxn];

void show() {
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    exit(0);
}

void flip() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1) {
                a[i][j] ^= 1;
            }
        }
    }
}

void fix1(int x, int y, int x2, int y2) {
    if (a[x2][y2] == a[x][y]) return;
    else flip();
}

void fix0(int x, int y, int x2, int y2) {
    if (a[x2][y2] == a[x][y]) flip();
    else return;
}

bool work1(int x, int y) {
    if (x + 2 > n || y + 1 > n) return false;
    if (a[x][y + 1] != a[x + 1][y]) {
        int r = ask(x, y, x + 2, y + 1);
        if (r) fix1(x, y, x + 2, y + 1);
        else fix0(x, y, x + 2, y + 1);
        return true;
    } else if (a[x + 2][y] != a[x + 1][y + 1]) {
        int r = ask(x, y, x + 2, y + 1);
        if (r) fix1(x, y, x + 2, y + 1);
        else fix0(x, y, x + 2, y + 1);
        return true;
    } else if (a[x][y] == a[x + 1][y + 1] && a[x + 1][y] == a[x + 2][y + 1]) {
        int r = ask(x, y, x + 2, y + 1);
        if (r) fix1(x, y, x + 2, y + 1);
        else fix0(x, y, x + 2, y + 1);
        return true;
    } else if (a[x][y] != a[x + 1][y + 1] && a[x + 1][y] != a[x + 2][y + 1]) {
        int r = ask(x, y, x + 2, y + 1);
        if (r) fix1(x, y, x + 2, y + 1);
        else fix0(x, y, x + 2, y + 1);
        return true;
    } else return false;
}

bool work2(int x, int y) {
    if (x + 1 > n || y + 2 > n) return false;
    if (a[x + 1][y] != a[x][y + 1]) {
        int r = ask(x, y, x + 1, y + 2);
        if (r) fix1(x, y, x + 1, y + 2);
        else fix0(x, y, x + 1, y + 2);
        return true;
    } else if (a[x][y + 2] != a[x + 1][y + 1]) {
        int r = ask(x, y, x + 1, y + 2);
        if (r) fix1(x, y, x + 1, y + 2);
        else fix0(x, y, x + 1, y + 2);
        return true;
    } else if (a[x][y] == a[x + 1][y + 1] && a[x + 1][y] == a[x + 1][y + 2]) {
        int r = ask(x, y, x + 1, y + 2);
        if (r) fix1(x, y, x + 1, y + 2);
        else fix0(x, y, x + 1, y + 2);
        return true;
    } else if (a[x][y] != a[x + 1][y + 1] && a[x + 1][y] != a[x + 1][y + 2]) {
        int r = ask(x, y, x + 1, y + 2);
        if (r) fix1(x, y, x + 1, y + 2);
        else fix0(x, y, x + 1, y + 2);
        return true;
    } else return false;
}

bool work3(int x, int y) {
    if (x - 2 < 1 || y - 1 < 1) return false;
    if (a[x][y - 1] != a[x - 1][y]) {
        int r = ask(x, y, x - 2, y - 1);
        if (r) fix1(x, y, x - 2, y - 1);
        else fix0(x, y, x - 2, y - 1);
        return true;
    } else if (a[x - 2][y] != a[x - 1][y - 1]) {
        int r = ask(x, y, x - 2, y - 1);
        if (r) fix1(x, y, x - 2, y - 1);
        else fix0(x, y, x - 2, y - 1);
        return true;
    } else if (a[x][y] == a[x - 1][y - 1] && a[x - 1][y] == a[x - 2][y - 1]) {
        int r = ask(x, y, x - 2, y - 1);
        if (r) fix1(x, y, x - 2, y - 1);
        else fix0(x, y, x - 2, y - 1);
        return true;
    } else if (a[x][y] != a[x - 1][y - 1] && a[x - 1][y] != a[x - 2][y - 1]) {
        int r = ask(x, y, x - 2, y - 1);
        if (r) fix1(x, y, x - 2, y - 1);
        else fix0(x, y, x - 2, y - 1);
        return true;
    } else return false;
}

bool work4(int x, int y) {
    if (x - 1 < 1 || y - 2 < 1) return false;
    if (a[x - 1][y] != a[x][y - 1]) {
        int r = ask(x, y, x - 1, y - 2);
        if (r) fix1(x, y, x - 1, y - 2);
        else fix0(x, y, x - 1, y - 2);
        return true;
    } else if (a[x][y - 2] != a[x - 1][y - 1]) {
        int r = ask(x, y, x - 1, y - 2);
        if (r) fix1(x, y, x - 1, y - 2);
        else fix0(x, y, x - 1, y - 2);
        return true;
    } else if (a[x][y] == a[x - 1][y - 1] && a[x - 1][y] == a[x - 1][y - 2]) {
        int r = ask(x, y, x - 1, y - 2);
        if (r) fix1(x, y, x - 1, y - 2);
        else fix0(x, y, x - 1, y - 2);
        return true;
    } else if (a[x][y] != a[x - 1][y - 1] && a[x - 1][y] != a[x - 1][y - 2]) {
        int r = ask(x, y, x - 1, y - 2);
        if (r) fix1(x, y, x - 1, y - 2);
        else fix0(x, y, x - 1, y - 2);
        return true;
    } else return false;
}
bool work5(int x, int y) {
    if (x + 3 > n) return false;
    if (a[x][y] == a[x + 2][y] && a[x + 1][y] != a[x + 3][y]) return false;
    if (a[x][y] != a[x + 2][y] && a[x + 1][y] == a[x + 3][y]) return false;
    int r = ask(x, y, x + 3, y);
    if (r) { fix1(x, y, x + 3, y); return true; }
    else { fix0(x, y, x + 3, y); return true; }
    return false;
}

bool work6(int x, int y) {
    if (x - 3 < 1) return false;
    if (a[x][y] == a[x - 2][y] && a[x - 1][y] != a[x - 3][y]) return false;
    if (a[x][y] != a[x - 2][y] && a[x - 1][y] == a[x - 3][y]) return false;
    int r = ask(x, y, x - 3, y);
    if (r) { fix1(x, y, x - 3, y); return true; }
    else { fix0(x, y, x - 3, y); return true; }
    return false;
}


bool work7(int x, int y) {
    if (y + 3 > n) return false;
    if (a[x][y] == a[x][y + 2] && a[x][y + 1] != a[x][y + 3]) return false;
    if (a[x][y] != a[x][y + 2] && a[x][y + 1] == a[x][y + 3]) return false;
    int r = ask(x, y, x, y + 3);
    if (r) { fix1(x, y, x, y + 3); return true; }
    else { fix0(x, y, x, y + 3); return true; }
    return false;
}

bool work8(int x, int y) {
    if (y - 3 < 1) return false;
    if (a[x][y] == a[x][y - 2] && a[x][y - 1] != a[x][y - 3]) return false;
    if (a[x][y] != a[x][y - 2] && a[x][y - 1] == a[x][y - 3]) return false;
    int r = ask(x, y, x, y - 3);
    if (r) { fix1(x, y, x, y - 3); return true; }
    else { fix0(x, y, x, y - 3); return true; }
    return false;
}


i32 main() {
    

    


    


    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = -1;
        }
    }

    a[1][1] = 1; a[n][n] = 0;
        
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                if (a[i][j] >= 0) continue;
                if (i >= 3) {
                    if (ask(i - 2, j, i, j)) a[i][j] = a[i - 2][j];
                    else a[i][j] = a[i - 2][j] ^ 1;
                } else if (j >= 3) {
                    if (ask(i, j - 2, i, j)) a[i][j] = a[i][j - 2];
                    else a[i][j] = a[i][j - 2] ^ 1;
                } else {
                    a[i][j] = ask(1, 1, 2, 2);
                }
            }
        }
    }
    a[1][2] = 1;
    a[2][3] = ask(1, 2, 2, 3);
    a[2][1] = ask(2, 1, 2, 3) ? a[2][3] : (a[2][3] ^ 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1) {
                if (a[i][j] >= 0) continue;
                if (i >= 3) {
                    if (ask(i - 2, j, i, j)) a[i][j] = a[i - 2][j];
                    else a[i][j] = a[i - 2][j] ^ 1;
                } else if (j >= 3) {
                    if (ask(i, j - 2, i, j)) a[i][j] = a[i][j - 2];
                    else a[i][j] = a[i][j - 2] ^ 1;
                } else {
                    assert(false);
                }
            }
        }
    }
    
    

    


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                bool ok = false;
                ok = ok || work2(i, j);
                if (ok) show();
                ok = ok || work1(i, j);
                if (ok) show();
                ok = ok || work3(i, j);
                if (ok) show();
                ok = ok || work4(i, j);
                if (ok) show();
                ok = ok || work5(i, j);
                if (ok) show();
                ok = ok || work6(i, j);
                if (ok) show();
                ok = ok || work7(i, j);
                if (ok) show();
                ok = ok || work8(i, j);
                if (ok) show();
            }
        }
    }

}


