
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<pdb> vpd;

































void id0(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1};
ll nod(ll a, ll b) {
    if(b > a) {
        swap(a, b);
    }
    while(b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll nok(ll a,ll b) {
    return a * b / nod(a, b);
}
void sp(ll a,double b) {
    cout << fixed << setprecision(a) << b;
}
ll binpow (ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binpow (a, n - 1) * a;
    }
    else {
        ll b = binpow (a, n / 2);
        return b * b;
    }
}

template<class A> void read(vector<A>& v);
template<class A, size_t S> void read(array<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
	read(t...);
}
template<class A> void read(vector<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}
string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vector<bool> v) {
    string res;
	FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> string to_string(bitset<S> b) {
    string res;
	FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}
template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) {
    write(h);
    write(t...);
}
void print() {
     write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

void yes(bool ok) {
    print((ok ? "YES" : "Yes"));
}
void no(bool ok) {
    print((ok ? "NO" : "No"));

}


void solve() {
    string a, b;
    read(a, b);
    if(a == b) yes(1);
    else {
        if(sz(a) != sz(b)) no(1);
        else {
            int o = 0, z = 0;
            FOR(sz(a)) {
                if(a[i] == '1') o++;
                if(b[i] == '1') z++;
            }
            if((z && o)) yes(1);
            else no(1);
        }
    }
}
int main(){
    id0();
    ll t = 1;
    

    FOR(t) {
        

        solve();
    }
    r0;
}


