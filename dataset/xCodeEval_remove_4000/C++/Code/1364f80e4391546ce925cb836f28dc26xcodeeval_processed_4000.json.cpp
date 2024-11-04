



























using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

template <typename MonoidType, typename OperatorType>
struct id6 {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;

    

    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    

    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        lazy = vector<OperatorType>(2*n-1, E1);
        need_update = vector<bool>(2*n-1, false);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    

    id6() {}
    id6(int n_, MonoidType id3, OperatorType id1,
                    MOtoM id0, MMtoM id5, OOtoO id2, OItoO id4,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E0(id3), E1(id1),
        upd_f(id0), cmb_f(id5), lzy_f(id2), acc_f(id4) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if(!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if(r - l > 1) {
            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);
            need_update[2*k+1] = need_update[2*k+2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if(b <= l or  r <= a) return;
        if(a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if(b <= l or  r <= a) return E0;
        eval(k, l, r);
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2*k+1);
        MonoidType vr = query(a, b, mid, r, 2*k+2);
        return cmb_f(vl, vr);
    }

    

    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    

    MonoidType query(int a, int b) {
        return query(a, b, 0, n, 0);
    }

    void dump() {
        fprintf(stderr, "[lazy]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(lazy[i] == E1) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", lazy[i]);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "[node]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(node[i] == E0) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", node[i]);
        }
        fprintf(stderr, "\n");
    }
};



template <typename T,typename E>
struct SegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}

  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(int k){
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(int a,int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,reflect(k));
      return check(acc)?k-n:-1;
    }
    eval(k);
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};













template <typename T, int h, int w>
struct Matrix {
    using array_type = array<T, h * w>;
    array_type mat;

    Matrix(T val = T(0)) { mat.fill(val); }
                                         
    size_t size() const { return h; }
    const T& at(int i, int j) const { return mat[i*w + j]; }
    T& at(int i, int j) { return mat[i*w + j]; }

    Matrix<T, h, w> &operator+=(const Matrix<T, h, w>& rhs) {
        for(size_t i=0; i<h; i++) {
            for(size_t j=0; j<w; j++) {
                this->at(i, j) += rhs.at(i, j);
            }
        }
        return *this;
    }

    Matrix<T, h, w> operator-() const {
        Matrix<T, h, w> res(*this);
        for(size_t i=0; i<h; i++) {
            for(size_t j=0; j<w; j++) {
                res.at(i, j) *= T(-1);
            }
        }
        return res;
    }

    Matrix<T, h, w> &operator-=(const Matrix<T, h, w>& rhs) {
        return (Matrix<T, h, w>(*this) += -rhs);
    }

    template <int wr>
    Matrix<T, h, wr> operator*(const Matrix<T, w, wr>& rhs) {
        size_t H = h, W = wr, C = w;
        Matrix<T, h, wr> res;
        for(size_t i=0; i<H; i++) {
            for(size_t j=0; j<W; j++) {
                for(size_t k=0; k<C; k++) {
                    res.at(i, j) += this->at(i, k) * rhs.at(k, j);
                }
            }
        }
        return res;
    }

    Matrix<T, h, w> operator+(const Matrix<T, h, w>& rhs) {
        return (Matrix<T, h, w>(*this) += rhs);
    }

    Matrix<T, h, w> operator-(const Matrix<T, h, w> &rhs) {
        return (Matrix<T, h, w>(*this) -= rhs);
    }

    bool operator==(const Matrix<T, h, w> &rhs) const {
        return this->mat == rhs.mat;
    }
    bool operator!=(const Matrix<T, h, w> &rhs) const {
        return !(*this == rhs);
    }
};

template <typename T, int h, int w>
Matrix<T, h, w> eigen() {
    Matrix<T, h, w> res(0);
    for(size_t i=0; i<h; i++) res.at(i, i) = T(1);
    return res;
}

template <typename T, int h, int w>
Matrix<T, h, w> pow(Matrix<T, h, w> mat, long long int k) {
    Matrix<T, h, w> res = eigen<T, h, w>();
    for(; k>0; k>>=1) {
        if(k & 1) res = res * mat;
        mat = mat * mat;
    }
    return res;
}

template <typename T, int h, int w>
ostream& operator<< (ostream& out, Matrix<T, h, w> mat) {
    int H = mat.h, W = mat.w;
    out << "[" << endl;
    for(int i=0; i<H; i++) {
        out << "  [ ";
        for(int j=0; j<W; j++) out << mat.at(i, j) << " ";
        out << "]" << endl;
    }
    out << "]" << endl;
    return out;
}




using ll = long long;
template<ll mod>
struct ModInt {
    ll v;
    ll mod_pow(ll x, ll n) const {
        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;
    }
    ModInt(ll a = 0) {
        if(a <= -mod or mod <= a) {
            a %= mod;
            if(a < 0) a += mod;
        }
        v = a;
    }
    ModInt operator+ ( const ModInt& b ) const {
        return (v + b.v >= mod ? ModInt(v + b.v - mod) : ModInt(v + b.v));
    }
    ModInt operator- () const {
        return ModInt(-v);
    }
    ModInt operator- ( const ModInt& b ) const {
        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));
    }
    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}
    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2)) % mod;}
    
    bool operator== ( const ModInt &b ) const {return v == b.v;}
    bool operator!= ( const ModInt &b ) const {return !(*this == b); }
    ModInt& operator+= ( const ModInt &b ) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }
    ModInt& operator-= ( const ModInt &b ) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }
    ModInt& operator*= ( const ModInt &b ) {
        (v *= b.v) %= mod;
        return *this;
    }
    ModInt& operator/= ( const ModInt &b ) {
        (v *= mod_pow(b.v, mod-2)) %= mod;
        return *this;
    }
    ModInt pow(ll x) { return ModInt(mod_pow(v, x)); }
    

    

};

template<ll mod>
ostream& operator<< (ostream& out, ModInt<mod> a) {return out << a.v;}
template<ll mod>
istream& operator>> (istream& in, ModInt<mod>& a) {
    in >> a.v;
    return in;
}




int main() {
    using mint = ModInt<1000000007>;
    using Mat = Matrix<mint, 2, 2>;
    using Vec = Matrix<mint, 2, 1>;

    auto f = [](Vec a, Mat b) { return b * a; };
    auto g = [](Vec a, Vec b) {
        return a + b;
    };
    auto h = [](Mat a, Mat b) {
        return a * b;
    };
    auto p = [](Mat a, int x) {
        return a;
    };

    Vec E0; E0.at(0, 0) = 0, E0.at(1, 0) = 0;
    Mat E1;
    E1.at(0, 0) = 1, E1.at(0, 1) = 0;
    E1.at(1, 0) = 0, E1.at(1, 1) = 1;

    Mat fib;
    fib.at(0, 0) = fib.at(0, 1) = fib.at(1, 0) = 1;
    fib.at(1, 1) = 0;
    
    Vec vec;
    vec.at(0, 0) = 1, vec.at(1, 0) = 0;
    
    int N, Q; scanf("%d%d", &N, &Q);
    vector<Vec> matrices(N);
    for(int i=0; i<N; i++) {
        int v; scanf("%d", &v);
        Mat id7 = pow(fib, v - 1);
        matrices[i] = id7 * vec;
        

    }
    
    id6<Vec, Mat> seg(N, E0, E1, f, g, h, p, matrices);
    

    

    
    while(Q--) {
        int type; scanf("%d", &type);
        if(type == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x); l--;
            Mat id7 = pow(fib, x);
            seg.update(l, r, id7);
        }
        if(type == 2) {
            int l, r; scanf("%d%d", &l, &r); l--;
            auto res = seg.query(l, r);
            printf("%lld\n", res.at(0, 0).v);
        }
    }
    return 0;
}
