
using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const int p = 167;
const long long inf = 1e16;
void f(vector <int> &primes,int  n){
    vector <bool> visited(n+1, false);
    int temp;
    for(int i = 2; i <= n; ++i){
        if(!visited[i]){
            primes.push_back(i);
            for(int z = i*i; z <= n; z+=i){
                visited[z] = true;
            }
            if(i*i > n){
                temp = i+1;
                break;
            }
        }
    }
    while(temp <= n){
        if(!visited[temp]){
            primes.push_back(temp);
        }
        ++temp;
    }
    return;
}
int find_parent(int a, vector <int> &parent){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find_parent(parent[a], parent);
}
void unite(int a, int b, vector <int> &parent, vector <int> &s){
    a = find_parent(a, parent);
    b = find_parent(b, parent);
    if(a != b){
        if(s[a] < s[b]){
            swap(a, b);
        }
        parent[b] = a;
        s[a]+=s[b];
    }
}
int h(vector <int> &prefix, vector <int> &pw, int i, int j){
    return ((long long) prefix[j] - prefix[i] * pw[j-i+1] + mod) % mod;
}
bool same(int i, int j, vector <int> &parent){
    return (find_parent(i, parent) == find_parent(j, parent));
}
ll gcd(ll x, ll y){
    if(x < y){
        swap(x, y);
    }
    while(y){
        x %= y;
        swap(x, y);
    }
    return abs(x);
}
bool check(int a, int b){
    return a < b;
}
vector <int> topo;
vector <int> used;
vector <int> father;
bool id0(int n, vector <vector <int> > &a){
    used[n] = 1;
    for(int elem : a[n]){
        if(!used[elem]){
            used[elem] = 1;
            if(id0(elem, a)){
                return true;
            }
        }
        else if(used[elem] == 1){
            return true;
        }
    }
    used[n] = 2;
    topo.push_back(n);
    return false;
}
long long calc(int i, int j, vector <int> &ones, vector <int> &zeroes){
    return (long long) (ones[j]-ones[i])*(zeroes[j]-zeroes[i]);
}
const int base = 1000*1000*1000;
vector <int> sum(vector <int> a, vector <int> &b){
    int carry = 0;
    for (int i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
    return a;
}
void mult(vector <int> &a, int b){
    int carry = 0;
    for(int i = 0; i < a.size() || carry; ++i){
        if(i == a.size()){
            a.push_back(0);
        }
        long long cur = carry + (long long) a[i]*b;
        a[i] = int(cur % base);
        carry = int(cur/base);
    }
    while(a.size() > 1 && !a.back()){
        a.pop_back();
    }
    return;
}
void print(vector <int> &a){
    cout << (a.empty() ? 0 : a.back());
    for(int i = (int)a.size()-2; i >= 0; --i){
        printf("%09d", a[i]);
    }
    return;
}
int get_hash(vector <int> &h, int i, int j, vector <int> &pow){
    return (h[j] - (long long) h[i-1] * pow[j-i+1] % mod + mod) % mod;
}
bool id1(int i, int j, vector <int> &h1, vector <int> &h2, vector <int> &pow){
    int temp1, temp2;
    temp1 = get_hash(h1, i, j, pow);
    temp2 = get_hash(h2, h2.size() - j, h2.size()-i, pow);
    if(temp1 == temp2){
        return true;
    }
    return false;
}
bool check(char c1, char c2){
    return (c1 == '(' && (c2 == ')')) || (c1 == '[' && (c2 == ']'));
}
void to_print(int j, int i, vector <vector <int> > &op, string &s){
    if(j <= 0 || (i > s.size())){
        return;
    }
    if(op[j][i] > 0){
        to_print(op[j][i], i, op, s);
        to_print(j-op[j][i], i + op[j][i], op, s);
        return;
    }
    if(!op[j][i]){
        if(s[i-1] == '(' || s[i-1] == ')'){
            cout << "()";
        }
        else{
            cout << "[]";
        }
        return;
    }
    cout << s[i-1];
    to_print(j-2, i+1, op, s);
    cout << s[i+j-2];
    return;
}

vector <int> fen1;
vector <int> fen2;
int sum (int r, vector <int> &fen)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1){
        result+=fen[r];
    }
    return result;
}

void inc (int r, int delta, vector <int> &fen)
{
    for(; r < fen.size(); r = (r |(r+1))){
        fen[r]+=delta;
    }
    return;
}
int sum (int left, int right, vector <int > &fen)
{
    return sum(right, fen) - sum(left-1, fen);
}
set <pair <ll, int> > divi;
void func(ll n){
    ll d = 2;
    int counter = 0;
    while(d*d <= n){
        counter = 0;
        while(n % d == 0){
            ++counter;
            n/=d;
        }
        if(counter != 0){
            divi.insert({d, counter});
        }
        ++d;
    }
    if(n != 1){
        divi.insert({n, 1});
    }
    else{
        divi.insert({1, 1});
    }
    return;
}
struct SegmentTree{
    struct node{
        ll mx, predmx, mn, predmn;
        ll sum, diff_g;
        int counter1, counter2;
        ll inc, eq;
    };
    vector <node> t;
    int n;
    void combine(int v){
        t[v].sum = t[2*v].sum + t[2*v+1].sum;
        t[v].mx = max(t[2*v].mx, t[2*v+1].mx);
        t[v].predmx = max(t[2*v].predmx, t[2*v+1].predmx);
        t[v].mn = min(t[2*v].mn, t[2*v+1].mn);
        t[v].predmn = min(t[2*v].predmn,t[2*v+1].predmn);
        t[v].counter1 = t[v].counter2 = 0;
        t[v].diff_g = gcd(t[2*v].diff_g, t[2*v+1].diff_g);
        if(t[v].mx == t[2*v].mx){
            t[v].counter1+=t[2*v].counter1;
        }
        else{
            t[v].predmx = max(t[v].predmx, t[2*v].mx);
        }
        if(t[v].mx == t[2*v+1].mx){
            t[v].counter1+=t[2*v+1].counter1;
        }
        else{
            t[v].predmx = max(t[v].predmx, t[2*v+1].mx);
        }
        if(t[v].mn == t[2*v].mn){
            t[v].counter2+=t[2*v].counter2;
        }
        else{
            t[v].predmn = min(t[v].predmn, t[2*v].mn);
        }
        if(t[v].mn == t[2*v+1].mn){
            t[v].counter2 += t[2*v+1].counter2;
        }
        else{
            t[v].predmn = min(t[v].predmn, t[2*v+1].mn);
        }

        ll left_d = t[2*v].predmx;
        ll right_d = t[2*v+1].predmx;

        if(left_d != -1e17 && left_d != t[2*v].mn && right_d != -1e17 && right_d != t[2*v+1].mn){
            t[v].diff_g = gcd(t[v].diff_g, left_d - right_d);
        }
        ll any = -1;
        if(left_d != -1e17 && left_d != t[2*v].mn){
            any = left_d;
        }
        else if(right_d != -1e17 && right_d != t[2*v+1].mn){
            any = right_d;
        }

        for (long long val : {t[2 * v].mn, t[2 * v].mx, t[2 * v + 1].mn, t[2 * v + 1].mx}) {
            if (val != t[v].mn && val != t[v].mx) {
                if (any != -1) {
                    t[v].diff_g = gcd(t[v].diff_g, val - any);
                } else {
                    any = val;
                }
            }
        }
        return;
    }
    void pushing_eq(int v, int l, int r, ll val){
        t[v].mx = t[v].mn = t[v].eq = val;
        t[v].predmx = -1e17;
        t[v].predmn = 1e17;
        t[v].counter1 = t[v].counter2 = r-l+1;
        t[v].diff_g = 0;
        t[v].inc = 0;
        t[v].sum = (ll)(r-l+1)*val;
        return;
    }
    void pushing_sum(int v, int l, int r, ll val){
        if(t[v].mx == t[v].mn){
            pushing_eq(v, l, r, t[v].mn+val);
            return;
        }
        t[v].mx += val;
        t[v].mn += val;
        if(t[v].predmx != -1e17){
            t[v].predmx+=val;
        }
        if(t[v].predmn != 1e17){
            t[v].predmn += val;
        }
        t[v].sum += (ll)(r-l+1)*val;
        t[v].inc+= val;
        return;
    }
    void pushing_mx(int v, int l, int r, ll val){
        if(t[v].mx <= val){
            pushing_eq(v, l, r, val);
        }
        else if(t[v].mn < val){
            t[v].sum-=(ll)(t[v].mn - val)*t[v].counter2;
            if(t[v].mn == t[v].predmx){
                t[v].predmx = val;
            }
            t[v].mn = val;
        }
    }
    void pushing_mn(int v, int l, int r, ll val){
        if(t[v].mn >= val){
            pushing_eq(v, l, r, val);
        }
        else if(t[v].mx > val){
            t[v].sum +=(ll)(val - t[v].mx)*t[v].counter1;
            if(t[v].mx == t[v].predmn){
                t[v].predmn = val;
            }
            t[v].mx = val;
        }
    }
    void push(int v, int l, int r){
        if(l == r){
            return;
        }
        if(t[v].eq != -1){
            int mid = (l+r)/2;
            pushing_eq(2*v, l, mid, t[v].eq);
            pushing_eq(2*v+1, mid+1, r, t[v].eq);
            t[v].eq = -1;
        }
        else{
            int mid = (l+r)/2;
            pushing_sum(2*v, l, mid, t[v].inc);
            pushing_sum(2*v+1, mid+1, r, t[v].inc);
            t[v].inc = 0;

            pushing_mn(2*v, l, mid, t[v].mx);
            pushing_mn(2*v+1, mid+1, r, t[v].mx);

            pushing_mx(2*v, l, mid, t[v].mn);
            pushing_mx(2*v+1, mid+1, r, t[v].mn);
        }
        return;
    }
    void build(int v, int l, int r, vector <int> &a){
        t[v].inc = 0;
        t[v].eq = -1;
        if(l == r){
            t[v].sum = a[l];
            t[v].counter1 = t[v].counter2 = 1;
            t[v].mn = t[v].mx = a[l];
            t[v].predmx = -1e17;
            t[v].predmn = 1e17;
            t[v].diff_g = 0;
        }
        else{
            int mid = (l+r)/2;
            build(2*v, l, mid, a);
            build(2*v+1, mid+1, r, a);
            combine(v);
        }
    }
    void build(vector <int> &a){
        n = a.size();
        t.resize(4*n);
        build(1, 0, n-1, a);
        return;
    }
    void update_mn(int v, int l, int r, int ql, int qr, ll x){
        if((ql > qr) || (t[v].mx <= x)){
            return;
        }
        if((l == ql) && (r == qr) && (t[v].predmx < x)){
            pushing_mn(v, l, r, x);
            return;
        }
        push(v, l, r);
        int mid = (l + r)/2;
        update_mn(2*v, l, mid, ql, min(mid, qr), x);
        update_mn(2*v+1, mid+1, r, max(ql, mid+1), qr, x);
        combine(v);
    }
    void update_mx(int v, int l, int r, int ql, int qr, ll x){
        if((ql > qr) || (t[v].mn >= x)){
            return;
        }
        if((l == ql) && (r == qr) && (t[v].predmn > x)){
            pushing_mx(v, l, r, x);
            return;
        }
        push(v, l, r);
        int mid = (l + r)/2;
        update_mx(2*v, l, mid, ql, min(qr, mid), x);
        update_mx(2*v+1, mid+1, r, max(mid+1, ql), qr, x);
        combine(v);
        return;
    }
    void update_sum(int v, int l, int r, int ql, int qr, ll x){
        if(ql > qr){
            return;
        }
        if(l == ql && r == qr){
            pushing_sum(v, l, r, x);
            return;
        }
        push(v, l, r);
        int mid = (l + r)/2;
        update_sum(2*v, l, mid, ql, min(mid, qr), x);
        update_sum(2*v+1, mid+1, r, max(ql, mid+1), qr, x);
        combine(v);
        return;
    }
    void update_eq(int v, int l, int r, int ql, int qr, ll x){
        if(ql > qr){
            return;
        }
        if(ql == l && qr == r){
            pushing_eq(v, l, r, x);
            return;
        }
        push(v, l, r);
        int mid = (l+r)/2;
        update_eq(2*v, l, mid, ql, min(mid, qr), x);
        update_eq(2*v+1, mid+1, r, max(ql, mid+1), qr, x);
        combine(v);
        return;
    }
    ll get_sum(int v, int l, int r, int ql, int qr){
        if(ql > qr){
            return 0;
        }
        if((l == ql) && (qr == r)){
            return t[v].sum;
        }
        push(v, l, r);
        int mid = (l + r)/2;
        return get_sum(v*2, l, mid, ql, min(mid, qr)) + get_sum(2*v+1, mid+1, r, max(mid+1, ql), qr);
    }
    ll get_gcd(int v, int l, int r, int ql, int qr){
        if(ql > qr){
            return 0;
        }
        if(ql == l && qr == r){
            ll ans = t[v].diff_g;
            if(t[v].predmx != -1e17){
                ans = gcd(ans, -t[v].predmx + t[v].mx);
            }
            if(t[v].predmn != 1e17){
                ans = gcd(ans, t[v].predmn - t[v].mn);
            }
            ans = gcd(ans, t[v].mx);
            return ans;
        }
        push(v, l, r);
        int mid = (l+r)/2;
        return gcd(get_gcd(2*v, l, mid, ql, min(qr, mid)), get_gcd(2*v+1, mid+1, r, max(ql, mid+1), qr));
    }
    ll get_mx(int v, int l, int r, int ql, int qr){
        if(ql > qr){
            return -1e17;
        }
        if(ql == l && qr == r){
            return t[v].mx;
        }
        push(v, l, r);
        int mid = (l+r)/2;
        return max(
        get_mx(2*v, l, mid, ql, min(mid, qr)),
        get_mx(2*v+1, mid+1, r, max(mid+1, ql), qr));
    }
    ll get_mn(int v, int l, int r, int ql, int qr){
        if(ql > qr){
            return 1e17;
        }
        if(ql == l && qr == r){
            return t[v].mn;
        }
        push(v, l, r);
        int mid = (l+r)/2;
        return min(
        get_mn(2*v, l, mid, ql, min(qr, mid)),
        get_mn(2*v+1, mid+1, r, max(ql, mid+1), qr));
    }
} tree;
const static int N = (1 << 20);
const static int lg = 20;
ll modulo = 764854400;

const int k = 3;
struct vertex{
    vertex* to[k] = {0};
};
vertex* root = new vertex;
void add_string(string &s){
    vertex* v = root;
    int c;
    for(int i = 0; i < s.size(); ++i){
        c = s[i] - 'a';
        if(!v->to[c]){
            v->to[c] = new vertex;
        }
        v = v->to[c];
    }
    return;
}
bool get_x(vertex* v, int pos, string &s, bool stat){
    if(pos == s.size()){
        if(stat){
            return true;
        }
        return false;
    }
    int c;
    c= s[pos] - 'a';
    for(int i = 0; i < 3; ++i){
        if(v->to[i] && i == c && get_x(v->to[i], pos+1, s, stat)){
            return true;
        }
        else if(v->to[i] && i != c && !stat && get_x(v->to[i], pos+1, s, true)){
            return true;
        }
    }
    return false;
}
vector <pair <int, int> > moves = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int mn_x, mn_y, mx_x, mx_y;
vector <vector <bool> > vd;
int counter = 0;
int u_x, u_y;
vector <vector <bool> > q;
void dqs(int x, int y){
    ++counter;
    vd[x][y] = true;
    mn_x = min(x, mn_x);
    mx_x = max(x, mx_x);
    mn_y = min(mn_y, y);
    mx_y = max(mx_y, y);
    for(pair <int, int> elem : moves){
        x+=elem.first;
        y+=elem.second;
        if((x > u_x) || (x <= 0) || (y<= 0) || (y>u_y)){
            x-=elem.first;
            y-=elem.second;
            continue;
        }
        if(!vd[x][y] && q[x][y]){
            dqs(x, y);
        }
        x-=elem.first;
        y-=elem.second;
    }
}
void sol();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; ++tt){
        sol();
    }
    return 0;
}
void sol(){
    int k, temp, temp1, temp2, n, m;
    cin >> n >> m;
    u_x = n;
    u_y = m;
    char c;
    q.resize(n+1, vector <bool>(m+1));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> c;
            q[i][j] = c-'0';
        }
    }
    vd.assign(n+1, vector <bool>(m+1, false));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!vd[i][j] && q[i][j]){
                counter = 0;
                mn_x = 200;
                mn_y = 200;
                mx_x = -1;
                mx_y = -1;
                dqs(i, j);
                if(counter != (mx_y-mn_y+1)*(mx_x-mn_x+1)){
                    cout << "NO" << ln;
                    return;
                }
            }
        }
    }
    cout << "YES" << ln;
    return;
}
