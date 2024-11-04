





using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;


for(int i = 0; i <n; i++)

for(int i = n-1; i>=0; i--)

for(int i = int(a); i <= int(b); i++)

for(vi::iterator it = (c).begin(); it != (c).end(); it++)

for(vii::iterator it = (c).begin(); it != (c).end(); it++)

for(msi::iterator it = (c).begin(); it != (c).end(); it++)










struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

const int base = 1000000000;
const int base_digits = 9;
struct bigint {
    vector<int> a;
    int sign;
    
    int size(){
        if(a.empty())return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca)
            ans++,ca/=10;
        return ans;
    }
    bigint operator ^(const bigint &v){
        bigint ans=1,a=*this,b=v;
        while(!b.isZero()){
            if(b%2)
                ans*=a;
            a*=a,b/=2;
        }
        return ans;
    }
    string to_string(){
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof(){
        string s = to_string();
        int ans = 0;
        for(auto c : s)  ans += c - '0';
        return ans;
    }
    
    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        a.clear();
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            

        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    void operator*=(long long v) {
        if (v < 0)
            sign = -sign, v = -v;
        if(v > base){
            *this = *this * (v / base) * base + *this * (v % base);
            return ;
        }
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            

        }
        trim();
    }

    bigint operator*(long long v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll id0 = karatsubaMultiply(a1, b1);
        vll id2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) id0.size(); i++)
            r[i] -= id0[i];
        for (int i = 0; i < (int) id2.size(); i++)
            r[i] -= id2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) id0.size(); i++)
            res[i] += id0[i];
        for (int i = 0; i < (int) id2.size(); i++)
            res[i + n] += id2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};


const int mod = 998244353;
const int maxN = 3e5;
template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;
    static_assert(MOD_ > 0, "MOD must be positive");

private:
    using ll = long long;

    int v;

    static int minv(int a, int m) {
        a %= m;
        assert(a);
        return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
    }

public:

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
    explicit operator int() const { return v; }
    friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v ++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v --;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int(ll(v) * ll(o.v) % MOD);
        return *this;
    }
    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

struct node{
    int64_t val;
    node& operator=(const node& node){
        this->val = node.val;
        return *this;
    }
    node& operator+=(const node& node){
        this->val += node.val;
        return *this;
    }
    node& operator+=(int val){
        this->val += val;
        return *this;
    }
    node operator+(const node& node){
        return {this->val + node.val};
    }
};

int64_t MAX = 1e18;




struct SegmentTree{
    vector<node> lazy, seg;
    SegmentTree(int n){
        lazy.resize(4 * n);
        seg.resize(4 * n);
    }

    node combine(node x, node y){
        if (x.val < y.val){
            return {x.val};
        }
        else{
            return {y.val};
        }
    }

    void add(int root, int l, int r, int lq, int rq, int val){
        if (lq <= l && rq >= r){
            seg[root] += val;
            lazy[root] += val;
            return;
        }
        if (lq > r || rq < l){
            return;
        }
        if (root >= lazy.size()) return;
        int m = (l + r) >> 1;
        add(root * 2 + 1, l, m, lq, rq, val);
        add(root * 2 + 2, m+1, r, lq, rq, val);
        seg[root] = combine(seg[root * 2 + 1], seg[root * 2 + 2]);
    }
    node get(int root, int l, int r, int lq, int rq){
        if (rq <= l && rq >= r){
            return seg[root] + lazy[root];
        }
        if (lq > r || rq < l){
            return {MAX};
        }
        if (root >= lazy.size()) return {MAX};
        int m = (l + r) >> 1;
        push_down(root);
        node left = get(root * 2 + 1, l, m, lq, rq);
        node right = get(root * 2 + 2, m + 1, r, lq, rq);
        return combine(left, right);
    }
    void push_down(int root){
        lazy[root * 2 + 1] += lazy[root];
        lazy[root * 2 + 2] += lazy[root];
        seg[root] += lazy[root];
        lazy[root] = {0};
    }
};


struct LCA{
    vector<vector<int>>e;
    vector<vector<int>> table;
    vector<int> level;
    int lift;
    LCA(int n) {
        lift = (int)(log2(n))+1;
        e.resize(n, vector<int>());
        table.resize(n, vector<int>(lift + 1, -1));
        level.resize(n, 0);
    }

    void addEdge(int u, int v) {
        e[u].pb(v);
        e[v].pb(u);
    }

    void init(int root){ 

        dfs(root, -1);
    }

    void dfs(int root, int par){
        for (int next : e[root]){
            if (next != par){
                table[next][0] = root;
                level[next] = level[root] + 1;
                for (int i = 1; i <= lift; i++){
                    int t = table[next][i - 1];
                    if (t != -1){
                        table[next][i] = table[t][i - 1];
                    }
                }
                dfs(next, root);
            }
        }
    }

    int query(int u, int v) { 

        int lu = level[u];
        int lv = level[v];
        if (lu > lv){
            swap(u, v);
        }
        int diff = abs(lu - lv);
        for (int i = lift; i >= 0; i--){
            if (diff & (1 << i)){
                v = table[v][i];
            }
        }
        assert(level[u] == level[v]);
        if (u == v){
            return u;
        }
        for (int i = lift; i >= 0; i--){
            if (table[u][i] != table[v][i]){
                u = table[u][i];
                v = table[v][i];
            }
        }
        assert(table[u][0] == table[v][0]);
        return table[u][0];
    }

    void test() {
        while (true){
            int u, v;
            cin >> u >> v;
            cout << this->query(u, v) << "\n";
        }
    }
};

namespace KMP{
    vector<int> build(string s){
        int n = s.size();
        vector<int> Array(n);
        for (int i = 1; i < n; i++){
            if (s[i] == s[Array[i-1]]){
                Array[i] = Array[i-1] + 1;
                continue;
            }
            int j = Array[i-1];
            while (j >= 0){
                if (s[j] == s[i]){
                    Array[i] = j + 1;
                    break;
                }
                if (j == 0) break;
                j = Array[j]-1;
            }
        }
        return Array;
    }
}


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

struct double_pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<pair<T1, T2>,pair<T1, T2>> &p) const {
        auto h1 = pair_hash{}(p.first);
        auto h2 = pair_hash{}(p.second);
        return pair_hash{}(make_pair(h1,h2));
    }
};

template<class Fun>
class id4 {
    Fun fun_;
public:
    template<class T>
    explicit id4(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) id1(Fun &&fun) {
    return id4<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
struct Rho{
    int64_t Mul(int64_t a, int64_t b, int64_t mod){
        return a*b%mod;
    }
    int64_t Add(int64_t a, int64_t b, int64_t mod){
        a+=b; if (a>=mod) a-=mod;
        return a;
    }
    int64_t Pow(int64_t a, int64_t b, int64_t mod){
        if (b==0)return 1LL;
        int64_t au=Pow(a,b>>1,mod);
        au=Mul(au,au,mod);
        if(b^1)au=Mul(au,a,mod);
        return au;
    };
    int64_t F(int64_t x, int64_t c, int64_t mod){
        return Add(Pow(x,2,mod),c,mod);
    };
    int64_t FindOneDivisor(int64_t N){
        for (int ITER=0;ITER<3;ITER++){
            int64_t x=rand()%N;
            int64_t y=x;
            int64_t c=rand()%N;
            int64_t g=1;
            while (g==1){
                x=this->F(x,c,N);
                y=this->F(y,c,N);
                y=this->F(y,c,N);
                g=__gcd(abs(x-y),N);
            }
            if (g<N) return g;
        }
        return N; 

    }
};
const int N = 200001;
using Double = double;

struct Point{
    int x, y;
    bool operator< (const Point& p){
        if (this->x < p.x){return true;}
        if (this->x > p.x){return false;}
        return this->y <= p.y;
    }
    friend ostream& operator<< (ostream &os, const Point& p){
        return os << "{" << p.x << ", " << p.y <<  "}" << "\n";
    }
    friend Double getDist(Point p1, Point p2){
        long long int square = 1LL *(p1.x - p2.x) * (p1.x - p2.x) + 1LL * (p1.y - p2.y) * (p1.y - p2.y);
        return (double)sqrtl(square);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using Seg = pair<int,int>;
    int T; cin >> T;
    const int N = 2e5;
    vector<vector<int>> g(N, vector<int>());
    vector<int> color(N+1), v(N+1), t(N+1);
    bool id3;
    while (T--){
        int n, m; cin >> n >> m;
        id3 = true;
        for(int i=0;i<n;i++){
            g[i].clear(); color[i]=-1;
        }
        int64_t s1 = 0, s2=0;
        for(int i=0;i<n;i++){cin >> v[i];s1+=v[i];}
        for(int i=0;i<n;i++){cin >> t[i];s2+=t[i];}
        for(int i=0;i<m;i++){
            int u, v; cin >> u >> v;
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        color[0] = 0;
        auto dfs = id1([&](auto self, int root) -> void{
            for (int next : g[root]){
                if (color[next]==color[root]){
                    id3=false; break;
                }
                if (color[next]==-1){
                    color[next]=1-color[root];
                    self(next);
                }
            }
        });
        dfs(0);
        if (abs(s1%2)!=abs(s2%2)){
            cout<<"NO\n"; continue;
        }
        if (!id3){
            cout << "YES\n"; continue;
        }
        int64_t diff=0;
        for (int i=0;i<n;i++){
            assert(color[i]>=0);
            if (color[i]) diff+=v[i]-t[i];
            else diff+=t[i]-v[i];
        }
        if (diff==0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}










