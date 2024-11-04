








































using namespace std;
























































const int MOD = 1e9 + 7;
int fx[] = {-1,+0,+1,+0,+1,+1,-1,-1,+0};
int fy[] = {+0,-1,+0,+1,+1,-1,+1,-1,+0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


template <typename T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false); }
template <typename T> inline T GCD (T a,T b ) {a = abs(a);b = abs(b); if(a < b) swap(a, b); while ( b ) { a = a % b; swap ( a, b ); } return a;}
template <typename T> inline T EGCD(T a,T b,T &x,T &y){if(a == 0) {x = 0;y = 1;return b;}T x1, y1;T d = EGCD(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
template <typename T> inline T LCM(T x,T y){T tp = GCD(x,y);if( (x / tp) * 1. * y > 9e18) return 9e18;return (x / tp) * y;}
template <typename T> inline T BigMod(T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = MOD){return BigMod(A,M-2,M);}
template <typename T> void Compress(T * in, int n, int f = 0){vector <T> vv;for(int i = f; i < n + f; i++) vv.pb(in[i]);Unique(vv);for(int i = f; i < n + f; i++) in[i] = lower_bound(all(vv), in[i]) - vv.begin();}







template <typename T> T scani(T &n){n = 0;bool negative = false;char c = gc();while( c < '0' || c > '9'){if(c == '-') negative = true;c = gc();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = gc();}if(negative) n = ~(n-1);return n;}
template <typename T> void write(T n,int type = true){if(n<0) {pc('-');n = -n;}if(!n) {pc('0');if(type==32) pc(' '); else if(type) pc('\n'); return;}char buff[22];int len = 0;while(n) buff[len++] = n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);if(type==32) pc(' '); else if(type) pc('\n');}
int scans(char *a){int i=0;char c = 0;while(c < 33) c = gc();while(c > 33){a[i++] = c;c = gc();}a[i] = 0;return i;}




const int pSz = 2000006;
bool np[pSz + 10]; vi prime; int prime_size;void sieve(){np[0] = np[1] = 1;prime.pb(2);for(LL i = 4; i <= pSz; i+=2) np[i] = 1;for(LL i = 3; i <= pSz; i+=2){if(!np[i]){prime.pb(i);for(LL j = i * i; j <= pSz; j += (i << 1)) np[j] = 1;}}prime_size = prime.size();}



const int nSz = 2000006;
LL F[nSz + 1], tMod = MOD;
void Factorial(){ F[0] = 1; for(int i = 1; i <= nSz; i++) F[i] = (F[i - 1] * i) % tMod; }
inline LL nCr(int n, int r) { return (F[n] * InvMod((F[n - r] * F[r]) % tMod, tMod)) % tMod; }



void zAlgo(char *s, int *z){
    int L, R, sz; sz = strlen(s); z[0] = L = R = 0;
    For(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}void zAlgo(string &s, int *z){
    int L, R, sz; sz = s.size(); z[0] = L = R = 0;
    For(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}void zAlgo(int *s, int *z, int n){
    int L, R, sz; sz = n; z[0] = L = R = 0;
    For(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}






template <typename T> inline T id4(T x1, T y1, T x2, T y2){return SQR(x1 - x2) + SQR(y1 - y2);}
template <typename T> inline T Area2(T Ax, T Ay, T Bx, T By, T Cx, T Cy){T ret = Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By);
    if(ret < 0) return ret = -ret;
    return ret;
}

const int N = 200005; 
const int M = 200005;
const ULL hs = 3797;




struct complx{
    long double real, img;

    inline complx(){
        real = img = 0.0;
    }

    inline complx(long double x){
        real = x, img = 0.0;
    }

    inline complx(long double x, long double y){
        real = x, img = y;
    }

    inline void operator += (complx &other){
        real += other.real, img += other.img;
    }

    inline void operator -= (complx &other){
        real -= other.real, img -= other.img;
    }

    inline complx operator + (complx &other){
        return complx(real + other.real, img + other.img);
    }

    inline complx operator - (complx &other){
        return complx(real - other.real, img - other.img);
    }

    inline complx operator * (complx& other){
        return complx((real * other.real) - (img * other.img), (real * other.img) + (img * other.real));
    }
};
;

void FFT(vector <complx> &ar, int n, int inv){
    int i, j, l, len, len2;
    const long double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for(len = 2; len <= n; len <<= 1) {
        long double ang = 2 * PI / len * inv;
        complx wlen(cos(ang), sin(ang));
        for(i = 0; i < n; i += len) {
            complx w(1);
            for(j = 0; j < len / 2; j++) {
                complx u = ar[i + j];
                complx v = ar[i + j + len / 2] * w;
                ar[i + j] = u + v;
                ar[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }

    if (inv == -1){
        long double tmp = 1.0 / n;
        for (i = 0; i < n; i++) ar[i].real *= tmp;
    }
}


inline vector <complx> Mul(const vector <complx> &x, const vector <complx> &y) {
    int n = 1;
    while(n <= x.size() + y.size()) n = n * 2;
    vector <complx> A(n), B(n);
    Rep(i, x.size()) A[i] = x[i];
    Rep(i, y.size()) B[i] = y[i];
    FFT(A, n, 1);
    FFT(B, n, 1);
    Rep(i, n) A[i] = A[i] * B[i];
    FFT(A, n, -1);
    return A;
}

int in[N];
LL res[N];
string num;
vL numBs;
LL id0, base;

inline vL id2(vL &A, vL &B, LL bs = 10) {
    vL a = A, b = B; if(a.size() > b.size()) swap(a, b);
    vL r;
    LL carry = 0;
    LL m = a[0];
    for(int i = b.size() - 1, j = 0; i >= 0; i--) {
        LL cur = (carry + b[i] * m);
        r.pb(cur % bs);
        carry = cur / bs;
    }
    if(carry) r.pb(carry);
    reverse(all(r));
    return r;
}

inline vL id5(vL &a, vL &b, LL bs = 10) {
    if(min(b.size(), a.size()) == 1) return id2(a, b, bs);
    string r;
    int na = a.size();
    int nb = b.size();
    vector <complx> A(na), B(nb);
    for(int i = 0; i < na; i++) A[i] = complx(a[na - i - 1]);
    for(int i = 0; i < nb; i++) B[i] = complx(b[nb - i - 1]);

    int n = na + nb - 1;
    vector <complx> R = Mul(A, B);
    vector <LL> rs(n + 1, 0);
    for(int i = 0; i < n; i++) rs[i] = round(R[i].real);
    for(int i = 0; i < n; i++) {
        rs[i + 1] += rs[i] / bs;
        rs[i] %= bs;
    }
    while(n > 0 && rs[n] == 0) n--; n++;
    rs.resize(n);
    reverse(all(rs));
    return rs;
}

inline char id3(vL &a, vL &b) {
    if(a.size() == b.size()) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] < b[i]) return '<';
            if(a[i] > b[i]) return '>';
        }
        return '=';
    }
    return (a.size() < b.size()) ? '<' : '>';
}


vL bigPow(vL R, vL a, int b) {
    while(b) {
        if(b & 1) R = id5(R, a, base);
        a = id5(a, a, base);
        b = b / 2;
    }
    return R;
}

inline int ans_me() {
    int L = numBs.size();
    int P = (num.size() - 1) * log(10) / log(3);
    P = max(0, P - 1);
    int sum = 3 * P;
    int ret = inf;
    vL temp;
    vL b = vL {3};
    vL b2 = vL {2};
    vL b4 = vL {4};
    vL id1 = bigPow(vL {1}, b, P);

    while(id3(id1, numBs) == '<') {
        if(id3(temp = id5(id1, b2, base), numBs) != '<') ret = min(ret, sum + 2);
        if(id3(temp = id5(id1, b4, base), numBs) != '<') ret = min(ret, sum + 4);

        id1 = id5(id1, b, base);
        sum += 3;
    }
    ret = min(ret, sum);

    return ret;
}


inline vL convertBase(string nc, LL bs) {
    LL pw = 0, sv = bs;
    vL ret;
    while(sv % 10 == 0) pw++, sv /= 10;
    LL r = nc.size() % pw; r = (pw - r) % pw;
    while(r--) nc = '0' + nc;
    for(int i = 0; i < nc.size() / pw; i++) {
        int c = 0;
        for(int j = 0; j < pw; j++) c = c * 10 + nc[i * pw + j] - '0';
        ret.pb(c);
    }
    return ret;
}

int main()
{
    base = 10000;
    id0 = 1500000 * log(10) / log(3); id0++;
    cerr << id0 << "\n";

    cin >> num;
    numBs = convertBase(num, base);

    int res = ans_me();
    res = max(res, 1);

    cout << res << "\n";
    return 0;
}
