























using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;
typedef long long int64; 

typedef unsigned long long uint64; 

const double pi = acos(-1.0); 

const double eps = 1e-11; 

const int MAXI = 1000000000;






















int compare (const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}

template<class T> inline void DebM(T A[], T ii, T jj){

    END;PRS("----------------DEBUG----------------");END;
    FORN (i,ii,jj) cout<<A[i]<<" ";
    END;PRS("-------------------------------------");END;
}

template<class T> inline void DebF(T n){

    END;PRS("----------------DEBUG----------------");END;
    cout<<n;
    END;PRS("-------------------------------------");END;
}

template<class T> inline bool id10(T n)

{
    if (n <= 1)return false;
    for (T i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

template<class T> inline void checkmin(T &a, T b) {
    if (b < a) a = b;
}


template<class T> inline void checkmax(T &a, T b) {
    if (b > a) a = b;
}


template<class T> inline T sqr(T x) {
    return x*x;
}


template<class T> inline T lowbit(T n) {
    return (n^(n - 1))&n;
}


template<class T> inline int countbit(T n) {
    return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}




template<class T> inline T gcd(T a, T b)

{
    if (a < 0)return gcd(-a, b);
    if (b < 0)return gcd(a, -b);
    return (b == 0) ? a : gcd(b, a % b);
}

template<class T> inline T lcm(T a, T b)

{
    if (a < 0)return lcm(-a, b);
    if (b < 0)return lcm(a, -b);
    return a * (b / gcd(a, b));
}

template<class T> inline T id9(T a, T b, T &x, T &y)

{
    if (a < 0) {
        T d = id9(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = id9(a, -b, x, y);
        y = -y;
        return d;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = id9(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}

template<class T> inline vector<pair<T, int> > factorize(T n)

{
    vector<pair<T, int> > R;
    for (T i = 2; n > 1;) {
        if (n % i == 0) {
            int C = 0;
            for (; n % i == 0; C++, n /= i);
            R.push_back(make_pair(i, C));
        }
        i++;
        if (i > n / i) i = n;
    }
    if (n > 1) R.push_back(make_pair(n, 1));
    return R;
}

template<class T> inline T id1(T n)

{
    vector<pair<T, int> > R = factorize(n);
    T r = n;
    for (int i = 0; i < R.size(); i++)r = r / R[i].first * (R[i].first - 1);
    return r;
}



const int id6 = 40; 


template<class T> inline void showMatrix(int n, T A[id6][id6])

{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << A[i][j];
        cout << endl;
    }
}

template<class T> inline T checkMod(T n, T m) {
    return (n % m + m) % m;
}


template<class T> inline void identityMatrix(int n, T A[id6][id6])

{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] = (i == j) ? 1 : 0;
}

template<class T> inline void addMatrix(int n, T C[id6][id6], T A[id6][id6], T B[id6][id6])

{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
}

template<class T> inline void subMatrix(int n, T C[id6][id6], T A[id6][id6], T B[id6][id6])

{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = A[i][j] - B[i][j];
}

template<class T> inline void mulMatrix(int n, T C[id6][id6], T _A[id6][id6], T _B[id6][id6])

{
    T A[id6][id6], B[id6][id6];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] = _A[i][j], B[i][j] = _B[i][j], C[i][j] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
}

template<class T> inline void id3(int n, T m, T C[id6][id6], T A[id6][id6], T B[id6][id6])

{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = checkMod(A[i][j] + B[i][j], m);
}

template<class T> inline void id2(int n, T m, T C[id6][id6], T A[id6][id6], T B[id6][id6])

{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = checkMod(A[i][j] - B[i][j], m);
}

template<class T> inline T multiplyMod(T a, T b, T m) {
    return (T) ((((int64) (a)*(int64) (b) % (int64) (m))+(int64) (m)) % (int64) (m));
}


template<class T> inline void id5(int n, T m, T C[id6][id6], T _A[id6][id6], T _B[id6][id6])

{
    T A[id6][id6], B[id6][id6];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] = _A[i][j], B[i][j] = _B[i][j], C[i][j] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) C[i][j] = (C[i][j] + multiplyMod(A[i][k], B[k][j], m)) % m;
}

template<class T> inline T powerMod(T p, int e, T m)

{
    if (e == 0)return 1 % m;
    else if (e % 2 == 0) {
        T t = powerMod(p, e / 2, m);
        return multiplyMod(t, t, m);
    } else return multiplyMod(powerMod(p, e - 1, m), p, m);
}



double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}


double distR(double x1, double y1, double x2, double y2) {
    return sqr(x1 - x2) + sqr(y1 - y2);
}


template<class T> T cross(T x0, T y0, T x1, T y1, T x2, T y2) {
    return (x1 - x0)*(y2 - y0)-(x2 - x0)*(y1 - y0);
}


int crossOper(double x0, double y0, double x1, double y1, double x2, double y2)

{
    double t = (x1 - x0)*(y2 - y0)-(x2 - x0)*(y1 - y0);
    if (fabs(t) <= eps) return 0;
    return (t < 0) ? -1 : 1;
}

bool isIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)

{
    return crossOper(x1, y1, x2, y2, x3, y3) * crossOper(x1, y1, x2, y2, x4, y4) < 0 && crossOper(x3, y3, x4, y4, x1, y1) * crossOper(x3, y3, x4, y4, x2, y2) < 0;
}

bool isMiddle(double s, double m, double t) {
    return fabs(s - m) <= eps || fabs(t - m) <= eps || (s < m) != (t < m);
}




bool id8(char c) {
    return c >= 'A' && c <= 'Z';
}


bool id11(char c) {
    return c >= 'a' && c <= 'z';
}


bool isLetter(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}


bool isDigit(char c) {
    return c >= '0' && c <= '9';
}


char id4(char c) {
    return (id8(c)) ? (c + 32) : c;
}


char id7(char c) {
    return (id11(c)) ? (c - 32) : c;
}


template<class T> string toString(T n) {
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}


int toInt(string s) {
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}


int64 id0(string s) {
    int64 r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}


double toDouble(string s) {
    double r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}


template<class T> void stoa(string s, int &n, T A[]) {
    n = 0;
    istringstream sin(s);
    for (T v; sin >> v; A[n++] = v);
}


template<class T> void atos(int n, T A[], string &s) {
    ostringstream sout;
    for (int i = 0; i < n; i++) {
        if (i > 0)sout << ' ';
        sout << A[i];
    }
    s = sout.str();
}


template<class T> void atov(int n, T A[], vector<T> &vi) {
    vi.clear();
    for (int i = 0; i < n; i++) vi.push_back(A[i]);
}


template<class T> void vtoa(vector<T> vi, int &n, T A[]) {
    n = vi.size();
    for (int i = 0; i < n; i++)A[i] = vi[i];
}


template<class T> void stov(string s, vector<T> &vi) {
    vi.clear();
    istringstream sin(s);
    for (T v; sin >> v; vi.push_bakc(v));
}


template<class T> void vtos(vector<T> vi, string &s) {
    ostringstream sout;
    for (int i = 0; i < vi.size(); i++) {
        if (i > 0)sout << ' ';
        sout << vi[i];
    }
    s = sout.str();
}




template<class T> struct Fraction {
    T a, b;
    Fraction(T a = 0, T b = 1);
    string toString();
}; 


template<class T> Fraction<T>::Fraction(T a, T b) {
    T d = gcd(a, b);
    a /= d;
    b /= d;
    if (b < 0) a = -a, b = -b;
    this->a = a;
    this->b = b;
}

template<class T> string Fraction<T>::toString() {
    ostringstream sout;
    sout << a << "/" << b;
    return sout.str();
}

template<class T> Fraction<T> operator+(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.b + q.a * p.b, p.b * q.b);
}

template<class T> Fraction<T> operator-(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.b - q.a * p.b, p.b * q.b);
}

template<class T> Fraction<T> operator*(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.a, p.b * q.b);
}

template<class T> Fraction<T> operator/(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.b, p.b * q.a);
}



ii hash[MAXN];
vi b, tree(MAXN, 0), L(MAXN, 0), R(MAXN, 0);
int64 ans = 0;
int n;

int get(int idx){
    int kq = 0;
    while (idx){
        kq += tree[idx];
        idx -= (idx & -idx);
    }
    return kq;
}

void insert(int idx){
    while (idx <= n){
        tree[idx]++;
        idx += (idx & -idx);
    }
}

int main(){
    

    SC(n);
    FORN (i, 1, n + 1){
        int a;
        SC(a);
        hash[i] = MP(a, i);
    }
    sort(hash + 1, hash + n + 1);
    b.resize(n + 1);
    FORN (i, 1, n + 1) b[hash[i].se] = i;
    FORN (i, 1, n + 1){
        insert(b[i]);
        L[i] = i - get(b[i]);
    }
    FORN (i, 0, MAXN) tree[i] = 0;
    RFORN (i, n + 1, 1){
        R[i] = get(b[i] - 1);
        insert(b[i]);
    }
    
    FORN (i, 1, n + 1)
        ans += (int64)(L[i]) * (R[i]);
    printf("%I64d", ans);
}