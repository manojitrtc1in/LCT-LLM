















































using namespace std;
 




 

 
bool ismulti = false;
 


 
template <typename tp1, typename tp2>
istream& operator >> (istream &in, pair<tp1, tp2> &p) {
    in >> p.first >> p.second;
    return in;
}
 
template <typename tp1, typename tp2>
ostream& operator << (ostream &out, const pair<tp1, tp2> &p) {
    out << p.first << " " << p.second;
    out.flush();
    return out;
}
 


 
template <typename type>
void read(type a[], int ed, int st = 1) {
    for (int i = st; i <= ed; i++)
        cin >> a[i];
}
 
template <typename type>
void read(vector<type> &v, int sz = 0) {
    if(sz) v.resize(sz);
    for (auto &p: v)
        cin >> p;
}
 
template <typename type>
istream& operator >> (istream &in, vector<type> &v) {
    for (auto &p: v)
        in >> p;
    return in;
}
 
template <typename type>
void write(type a[], int ed, int st = 1, string sep = " ", string last = "\n") {
    for (int i = st; i <= ed; i++)
        cout << a[i] << (i != ed? sep: last);
    cout.flush();
}
 
template <typename type>
void write(vector<type> v, string sep = " ", string last = "\n") {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << (i != v.size() - 1? sep: last);
    cout.flush();
}
 
template <typename type>
ostream& operator << (ostream &out, const vector<type> &v) {
    for (auto p: v)
        out << p << " ";
    out.flush();
    return out;
}
 


 
int gcd(int a, int b) {
    return !b? a: gcd(b, a % b);
}
 
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
 
int popcount(int x, int p = 2) {
    int count = 0;
    while(x) {
        count++;
        x /= p;
    }
    return count;
}
 
int lowbit(int x) {
    return x & (-x);
}
 
int isqrt(int x) {
    int l = 0, r = 3e9, ans = 0, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (mid * mid <= x) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return ans;
}
 
int ilog2(int x) {
    return popcount(x) - 1;
}
 
int ilog10(int x) {
    return popcount(x, 10) - 1;
}
 
int ilogk(int x, int k) {
    return popcount(x, k) - 1;
}
 
int qpow(int a, int b, int p) {
    if (b == 0) return 1 % p;
    if (b == 1) return a % p;
    int tmp = qpow(a, b / 2, p) % p;
    if (b % 2) return tmp * tmp % p * a % p;
    else       return tmp * tmp % p;
}
 
int binarySearch(int l, int r, bool (*check)(int), int ans = 0) {
    int mid = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    return ans;
}
 
double binarySearch(double l, double r, bool (*check)(double), double eps = 1e-6, double ans = 0) {
    double mid = 0;
    while(abs(l - r) > eps) {
        mid = (l + r) / 2;
        if (check(mid)) l = mid, ans = mid;
        else r = mid;
    }
    return ans;
}
 
int id0(int a[], int n, int cnt = 1) {
    int tmp = cnt;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            a[cnt++] = i;
            if (i * i != n)
                a[cnt++] = n / i;
        }
    cnt--;
        sort(a + tmp, a + cnt + 1);
        return cnt;
}
 
int id0(vector<int> &v, int n) {
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    sort(v.begin(), v.end());
        return v.size();
}
 


 
void yes(bool ex = (!ismulti)) {
    cout << "yes" << endl;
    if (ex) exit(0);
}
 
void Yes(bool ex = (!ismulti)) {
    cout << "Yes" << endl;
    if (ex) exit(0);
}
 
void YES(bool ex = (!ismulti)) {
    cout << "YES" << endl;
    if (ex) exit(0);
}
 
void no(bool ex = (!ismulti)) {
    cout << "no" << endl;
    if (ex) exit(0);
}
 
void No(bool ex = (!ismulti)) {
    cout << "No" << endl;
    if (ex) exit(0);
}
 
void NO(bool ex = (!ismulti)) {
    cout << "NO" << endl;
    if (ex) exit(0);
}
 
void yesno(bool flag, bool ex = (!ismulti)) {
    if (flag) cout << "yes" << endl;
    else cout << "no" << endl;
    if (ex) exit(0);
}
 
void YesNo(bool flag, bool ex = (!ismulti)) {
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    if (ex) exit(0);
}
 
void YESNO(bool flag, bool ex = (!ismulti)) {
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    if (ex) exit(0);
}
 


 
class DJU {
    private :
        std::vector<unsigned> f, sz;
    public :
        DJU() {
    }
    DJU(unsigned _sz) {
        f = sz = std::vector<unsigned> (_sz + 1);
        for (unsigned i = 1; i <= _sz; i++)
            f[i] = i, sz[i] = 1;
    }
    unsigned find(unsigned x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool same(unsigned x, unsigned y) {
        if (find(x) == find(y)) return true;
        else return false;
    }
    void merge(unsigned x, unsigned y) {
        unsigned fx = find(x);
        unsigned fy = find(y);
        f[fx] = fy;
        sz[fy] += sz[fx];
    }
    unsigned size(unsigned x) {
        return sz[find(x)];
    }
    };
 
template <typename tp>
class BIT {
private :
    vector<tp> c; 

    unsigned sz;
    unsigned lowbit(unsigned x) {
        return x & (-x);
    }
 
public :
    BIT() {
    }
    BIT(unsigned _sz) {
        c = vector<tp> (_sz + 1);
        sz= _sz;
    }
    tp getsum(unsigned dx) { 

        tp ret = 0;
        while(dx) {
            ret += c[dx];
            dx -= lowbit(dx);
        }
        return ret;
    }
    tp sum(unsigned l,unsigned r) { 

        return getsum(r) - getsum(l - 1);
    }
    tp get(unsigned dx) { 

        return sum(dx,dx);
    }
    tp add(unsigned dx,tp val) { 

        unsigned tmp = dx;
        while(dx <= sz) {
            c[dx] += val;
            dx += lowbit(dx);
        }
        return c[tmp];
    }
    tp change(unsigned dx,tp val) { 

        return add(dx,val - get(dx));
    }
};
 
template <typename tp>
class id1 {
private :
    unsigned sz;
public :
    vector<vector<tp> > gv;
vector<tp>& operator [] (unsigned x) {
    return gv[x];
}
id1() {
}
~id1() {
    sz = 0;
    gv.resize(0);
}
id1(unsigned _sz) {
    sz = _sz;
    gv.resize(_sz + 1);
}
void readGraph(unsigned n, unsigned m, bool directed = false) {
    sz = n;
    gv.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        tp u, v;
        cin >> u >> v;
        gv[u].push_back(v);
        if (directed == false)
            gv[v].push_back(u);
    }
}
};
 
template <typename tp, typename tpw>
class authorizedGraph {
private :
    unsigned sz;
public :
    vector<vector<pair<tp, tpw> > > gv;
vector<pair<tp, tpw> >& operator [] (unsigned x) {
    return gv[x];
}
authorizedGraph() {
}
~authorizedGraph() {
    sz = 0;
    gv.resize(0);
}
authorizedGraph(unsigned _sz) {
    sz = _sz;
    gv.resize(_sz + 1);
}
void readGraph(unsigned n, unsigned m, bool directed = false) {
    sz = n;
    gv.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        tp u, v; tpw w;
        cin >> u >> v >> w;
        gv[u].push_back(make_pair(v, w));
        if (directed == false)
            gv[v].push_back(make_pair(u, w));
    }
}
};
 
class inverseElement {
private :
    unsigned n;
int p;
vector<int> fac;
void getFactorial(unsigned L, unsigned R, int P) {
    if (n >= R) return;
    n = R;
    fac.resize(n + 1);
    fac[0] = 1;
    for (unsigned i = L; i <= R; i++)
        fac[i] = fac[i - 1] * i % P;
}
public :
    inverseElement() {
}
inverseElement(int P) {
    p = P;
}
int C(unsigned N, unsigned M, int P = 0) {
    if (P == 0) P = p;
    if (M > N) throw "M cannot be greater than N!";
    if (n < N) getFactorial(n + 1, N, P);
    return fac[N] * qpow(fac[M], P - 2 , P) % P * qpow(fac[N - M], P - 2, P) % P;
}
int A(unsigned N, unsigned M, int P = 0) {
    if (P == 0) P = p;
    if (M > N) throw "M cannot be greater than N!";
    if (n < N) getFactorial(n + 1, N, P);
    return C(N, M, P) * fac[M] % P;
}
};
 


 
const int INF = 0x3f3f3f3f;
const int LONGINF = 0x3f3f3f3f3f3f3f3f;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const double PI = acos(-1.0);
const double E = 2.718281828;
const double PHI = (sqrt(5.0) - 1) / 2.0;
 


 
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef pair<int, pii> pipii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ppiii> vppiii;
typedef vector<pipii> vpipii;
typedef map<int, int> mii;
typedef map<int, vi> mivi;
typedef map<int, pii> mipii;
typedef map<pii, int> mpiii;
typedef map<char, int> mci;
typedef set<int> si;
typedef set<string> ss;
typedef set<pii> spii;
typedef set<ppiii> sppiii;
typedef set<pipii> spipii;
 



















 


 
pair<int, int> a[200001];
bool v1[200001], v2[200001], placed[200001];
int placedNum;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    multi {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v1[a[i].first] = v1[a[i].second] = 0;
            v2[a[i].first] = v2[a[i].second] = 0;
            placed[i] = 0;








        }
        for (int i = 1; i <= n; i++)
            if (a[i].first == a[i].second) {
                cout << "NO" << endl;
                goto end;
            }
        if (n == 200000) {
            cout << "YES" << endl;
            return 0;
        }






        placedNum = 0;
        while (placedNum <= n) {
            int fnp; 

            for (int i = 1; i <= n; i++)
                if (!placed[i]) {
                    fnp = i;
                    break;
                }
            v1[a[fnp].first] = v1[a[fnp].second] = 1;
            placed[fnp] = 1;
            placedNum++;
            while (true) {
                bool flag = false;
                for (int i = 1; i <= n; i++) {
                    if (!placed[i] && (v1[a[i].first] || v1[a[i].second])) {
                        if (v2[a[i].first] || v2[a[i].second]) {
                            cout << "NO" << endl;
                            goto end;
                        }
                        v2[a[i].first] = v2[a[i].second] = 1;
                        placed[i] = 1;
                        placedNum++;
                        flag = true;
                    }
                }
                for (int i = 1; i <= n; i++) {
                    if (!placed[i] && (v2[a[i].first] || v2[a[i].second])) {
                        if (v1[a[i].first] || v1[a[i].second]) {
                            cout << "NO" << endl;
                            goto end;
                        }
                        v1[a[i].first] = v1[a[i].second] = 1;
                        placed[i] = 1;
                        placedNum++;
                        flag = true;
                    }
                }
                if (!flag) break;
            }
        }
        cout << "YES" << endl;
        end:;
    }
    return 0;
}
