
using namespace std;






























template<typename T> using minpq = pq<T, vector<T>, greater<T>>;
template<typename T> using maxpq = pq<T, vector<T>, less<T>>;
template<typename T1,typename T2,typename H1=hash<T1>,typename H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};



char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[_maxNumLength],_tempOutputBuf[_maxNumLength],_fill=' ';
const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id1=0,_cnt;ull _precisionBase=1000000;














void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}
template<typename T,typename...Ts>void read(T&&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}























void write(bool x){wb(x);}void write(int x){wi(x);}void write(uint x){wi(x);}void write(ll x){wll(x);}void write(ull x){wll(x);}void write(double x){wd(x);}void write(ld x){wld(x);}
void write(char x){wc(x);}void write(char*x){wcs(x);}void write(const char*x){wcs(x);}void write(string&x){ws(x);}
template<typename T,typename...Ts>void write(T&&x,Ts&&...xs){write(x);for(const char*_p=_delimiter;*_p;_putchar(*_p++));write(forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<typename...Ts>void writeln(Ts&&...xs){write(forward<Ts>(xs)...);_putchar('\n');}
void flush(){_flush();}class IOManager{public:~IOManager(){flush();}};unique_ptr<IOManager>id0;

const double EPS = 1e-9;

struct Vector {
private:
    int d;                          

    vector<double> data;            


public:
    Vector() {}

    
    Vector(int d) : d(d), data(d, 0.0) {}

    
    Vector(int d, double *a) : d(d), data(a, a + d) {}

    
    Vector(const vector<int> &v) : d(v.size()), data(v.begin(), v.end()) {}

    
    int dimension() const {
        return d;
    }

    
    double dot(const Vector &that) const {
        if (d != that.d) throw invalid_argument("Dimensions don't agree");
        double sum = 0.0;
        for (int i = 0; i < d; i++) sum = sum + (data[i] * that.data[i]);
        return sum;
    }

    
    double operator * (const Vector &that) const {
        return dot(that);
    }

    
    double cross2D(const Vector &that) const {
        if (d != 2 || that.d != 2) throw invalid_argument("Vectors must be 2-dimensional");
        return data[0] * that.data[1] - data[1] * that.data[0];
    }

    
    double operator | (const Vector &that) const {
        return cross2D(that);
    }

    
    Vector cross3D(const Vector &that) const {
        if (d != 3 || that.d != 3) throw invalid_argument("Vectors must be 3-dimensional");
        Vector c(d);
        c.data[0] = data[1] * that.data[2] - data[2] * that.data[1];
        c.data[1] = data[2] * that.data[0] - data[0] * that.data[2];
        c.data[2] = data[0] * that.data[1] - data[1] * that.data[0];
        return c;
    }

    
    Vector operator ^ (const Vector &that) const {
        return cross3D(that);
    }

    
    double magnitude() const {
        return sqrt(this->dot(*this));
    }

    
    double distanceTo(const Vector &that) const {
        if (d != that.d) throw invalid_argument("Dimensions don't agree");
        return minus(that).magnitude();
    }

    
    Vector plus(const Vector &that) const {
        if (d != that.d) throw invalid_argument("Dimensions don't agree");
        Vector c(d);
        for (int i = 0; i < d; i++) c.data[i] = data[i] + that.data[i];
        return c;
    }

    
    Vector operator + (const Vector &that) const {
        return plus(that);
    }

    
    Vector minus(const Vector &that) const {
        if (d != that.d) throw invalid_argument("Dimensions don't agree");
        Vector c(d);
        for (int i = 0; i < d; i++) c.data[i] = data[i] - that.data[i];
        return c;
    }

    
    Vector operator - (const Vector &that) const {
        return minus(that);
    }

    
    double cartesian(int i) const {
        return data[i];
    }

    

    double &operator [](int i) {
        return data[i];
    }

    

    double operator [](int i) const {
        return data[i];
    }

    
    Vector scale(double alpha) const {
        Vector c(d);
        for (int i = 0; i < d; i++) c.data[i] = alpha * data[i];
        return c;
    }

    
    Vector operator * (double alpha) const {
        return scale(alpha);
    }

    
    Vector operator / (double alpha) const {
        return scale(1.0 / alpha);
    }

    
    Vector direction() const {
        if (magnitude() <= EPS) throw runtime_error("Zero-vector has no direction");
        return scale(1.0 / magnitude());
    }

    
    double directionCosine(int i) const {
        return data[i] / magnitude();
    }

    
    Vector projectionOn(const Vector &that) const {
        if (d != that.d) throw invalid_argument("Dimensions don't agree");
        return that.scale(dot(that) / that.dot(that));
    }

    
    Vector rotate(Vector &that, double theta) const {
        if (d == 2 && that.d == 2) {
            Vector r(2);
            r.data[0] = that.data[0] + (data[0] - that.data[0]) * cos(theta) - (data[1] - that.data[1]) * sin(theta);
            r.data[1] = that.data[1] + (data[0] - that.data[0]) * sin(theta) + (data[1] - that.data[1]) * cos(theta);
            return r;
        } else if (d == 3 && that.d == 3) {
            return scale(cos(theta)).plus(that.direction().cross3D(*this).scale(sin(theta))).plus(that.direction().scale(that.direction().dot(*this)).scale(1.0 - cos(theta)));
        } else if (d == that.d) {
            throw invalid_argument("Vectors must be 2-dimensional or 3-dimensional");
        } else {
            throw invalid_argument("Dimensions don't agree");
        }
    }

    bool operator < (const Vector &that) const {
        for (int i = 0; i < d; i++) if (abs(data[i] - that.data[i]) > EPS) return data[i] < that.data[i];
        return false;
    }
};

Vector intersection(const pair<Vector, Vector> &a, const pair<Vector, Vector> &b) {
    Vector c = (b.f - a.f) ^ b.s;
    Vector d = (a.s ^ b.s);
    double alpha = (c.magnitude() * (c < Vector(3) ? -1 : 1)) / (d.magnitude() * (d < Vector(3) ? -1 : 1));
    return a.f + a.s * alpha;
}

void solve(const vector<Vector> &A, const vector<Vector> &B, vector<pair<Vector, pii>> &events, int id) {
    pair<Vector, Vector> H1 = {A[0], ((A[0] - A[1]) ^ (A[2] - A[0])).direction()}, H2 = {B[0], ((B[0] - B[1]) ^ (B[2] - B[0])).direction()};
    Vector cross = H1.s ^ H2.s;
    if (cross.magnitude() <= EPS) return;
    Vector cross2 = (cross ^ H1.s).direction();
    cross = cross.direction();
    pair<Vector, Vector> line = {H1.f + cross2 * (((H2.f - H1.f) * H2.s) / (cross2 * H2.s)), cross};
    vector<pair<Vector, pii>> v;
    FOR(i, sz(A)) {
        Vector a = A[i], b = A[(i + 1) % sz(A)];
        double dota = (a - line.f) * cross2, dotb = (b - line.f) * cross2;
        int signa = dota > EPS ? 1 : (dota < -EPS ? -1 : 0), signb = dotb > EPS ? 1 : (dotb < -EPS ? -1 : 0);
        if (signa != signb) {
            Vector POI = intersection({a, b - a}, line);
            if (signa != 0 && signb != 0) events.pb({POI, {signa, id}});
            else v.pb({POI, {signa, signb}});
        }
    }
    FOR(i, sz(v)) if (v[i].s.s == 0) if (v[i].s.f != v[(i + 1) % sz(v)].s.s) events.pb({v[i].f, {v[i].s.f, id}});
}

int main() {




    id0.reset(new IOManager());
    int N, M;
    vector<Vector> A, B;
    read(N);
    FOR(i, N) {
        A.pb(Vector(3));
        FOR(j, 3) read(A[i][j]);
    }
    read(M);
    FOR(i, M) {
        B.pb(Vector(3));
        FOR(j, 3) read(B[i][j]);
    }
    vector<pair<Vector, pii>> events;
    solve(A, B, events, 0);
    solve(B, A, events, 1);
    int ans = 0, cur = 0;
    sort(all(events));
    for (pair<Vector, pii> &e : events) {
        if (e.s.s == 1) cur += e.s.f;
        else if (cur != 0) ans += e.s.f;
    }
    writeln(ans == 0 ? "NO" : "YES");
    return 0;
}