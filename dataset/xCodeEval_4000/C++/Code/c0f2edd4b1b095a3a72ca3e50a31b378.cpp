#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n';
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
bool toposort(int n, vector <vector <int> > &a){
    used[n] = 1;
    for(int elem : a[n]){
        if(!used[elem]){
            used[elem] = 1;
            if(toposort(elem, a)){
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
bool palindrom(int i, int j, vector <int> &h1, vector <int> &h2, vector <int> &pow){
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
vector <int> a;
vector <vector <int > > dp;
void build(int n){
    int ext = 1;
    int counter = 0;
    while(ext < n){
        ext*=2;
        ++counter;
    }
    dp.resize(ext, vector <int> (counter));
    for(int h = 1; (1 << h) < ext; ++h){
        int len = (1 << h);
        for(int rad = len; rad < ext; rad+=2*len){
            dp[rad][h] = a[rad];
            for(int curr  = rad+1; curr + rad < curr+len; ++ curr){
                dp[curr][h] = a[curr] + dp[curr][h];
            }
            dp[rad-1][h] = a[rad-1];
            for(int curr = rad-2; curr >= curr-len; --curr){
                dp[curr][h] = a[curr] + dp[curr][h];
            }
        }
    }
}
int l;
vector <vector <int> > e;
vector <vector <int> > upper;
vector <pair <int, int> > times;
int counter = 0;
vector <int> ans;
vector <int> ar1;
vector <int> ar2;
void ddfs(int v, int p){
    upper[v][0] = p;
    times[v].first = ++counter;
    for(int i  = 1; i <= l; ++i){
        upper[v][i] = upper[upper[v][i-1]][i-1];
    }
    for(int elem : e[v]){
        if(elem != p){
            ddfs(elem, v);
        }
    }
    times[v].second  = ++counter;
}
bool checked(int v1, int v2){
    return times[v1].first <= times[v2].first && times[v1].second >= times[v2].second;
}
int anc(int v1, int v2){
    if(checked(v1, v2)){
        return v1;
    }
    if(checked(v2, v1)){
        return v2;
    }
    for(int i = l; i >= 0; --i){
        if(!checked(upper[v1][i], v2)){
            v1 = upper[v1][i];
        }
    }
    return upper[v1][0];
}
struct seg_tree{
    int n;
    struct node{
        int left, right, mx;
        node *left_child, *right_child;
    };
    vector <node*> nodes;
    node* build(int l, int r, vector <int> &val, vector <int> &rev){
        if(l > r){
            return 0;
        }
        node *curr = new node;
        curr->left = l;
        curr->right = r;
        if(curr->left == curr->right){
            curr->mx = val[rev[l]];
            curr->left_child = curr->right_child = 0;
            return curr;
        }
        int mid = (l+r)/2;
        curr -> left_child = build(l, mid, val, rev);
        curr -> right_child = build(mid+1, r, val, rev);
        curr-> mx = max(curr->left_child->mx, curr->right_child->mx);
        return curr;
    }
    void build(int sz, vector <int> &val, vector <int> &rev, vector <pair <int, int> > &bounds){
        n = sz;
        nodes.resize(bounds.size());
        for(int i = 0; i < bounds.size(); ++i){
            nodes[i] = build(bounds[i].first, bounds[i].second, val, rev);
        }
        return;
    }
    void update(node* curr, int index, int val){
        if(curr->left == index && curr->right == index){
            curr->mx = val;
            return;
        }
        if(index <= curr->left_child->right){
            update(curr->left_child, index, val);
        }
        else{
            update(curr->right_child, index, val);
        }
        curr->mx = max(curr->left_child->mx, curr->right_child->mx);
    }
    int get_mx(node* curr, int ql, int qr){
        if(curr->left > qr || curr->right < ql){
            return -1;
        }
        if(ql <= curr->left && qr >= curr->right){
            return curr->mx;
        }
        return max(get_mx(curr->left_child, ql, qr), get_mx(curr->right_child, ql, qr));
    }
    void update(int ind, int val, int type){
        return update(nodes[type], ind, val);
    }
    int get_mx(int l, int r, int type){
        return get_mx(nodes[type], l, r);
    }
}tr;
struct hld{
    vector <int> tin, tout, s, p, head, rev;
    vector <pair <int, int> > bounds;
    vector <int> rooter;
    int counter = 0;
    int n;
    void sz(int v, int prev, vector <vector <int> > &e){
        s[v] = 1;
        p[v] = prev;
        for(int &elem : e[v]){
            sz(elem, v, e);
            s[v]+=s[elem];
            if(s[elem] > s[e[v][0]]){
                swap(elem, e[v][0]);
            }
        }
    }
    void hd(int v, vector <vector <int> > &g){
        rev[counter] = v;
        tin[v] = counter++;
        for(int elem : g[v]){
            head[elem] = ((elem == g[v][0]) ? head[v] : elem);
            hd(elem, g);
        }
        tout[v] = counter;
        return;
    }
    void build(int z, vector <vector <int> > &e, vector <int> &vals){
        n = z;
        tin.resize(n);
        tout.resize(n);
        p.resize(n);
        rev.resize(n);
        head.resize(n);
        head[0] = 0;
        s.resize(n);
        sz(0, 0, e);
        hd(0, e);
        rooter.resize(n);
        vector <bool> visited(n);
        int c = 0, temp;
        for(int i = 0; i < n; ++i){
            if(!visited[head[i]]){
                bounds.push_back({tin[head[i]], tin[i]});
                rooter[head[i]] = c;
                visited[head[i]] = true;
                c++;
            }
            else{
                temp = rooter[head[i]];
                bounds[temp].second = max(tin[i], bounds[temp].second);
            }
        }
        visited.clear();
        tr.build(n, vals, rev, bounds);
    }
    int anc(int v1, int v2){
        return tin[v1] <= tin[v2] && tout[v1] > tin[v2];
    }
    int up(int &a, int &b, int &ans){
        while(!anc(head[a], b)){
            ans = max(ans, tr.get_mx(tin[head[a]], tin[a], rooter[head[a]]));
            a = p[head[a]];
        }
    }
    int get_mx(int a, int b){
        int ans = -1;
        up(a, b, ans);
        up(b, a, ans);
        if(!anc(a, b)){
            swap(a, b);
        }
        ans = max(ans, tr.get_mx(tin[a], tin[b], rooter[head[a]]));
        return ans;
    }
    void update(int index, int val){
        tr.update(tin[index], val, rooter[head[index]]);
    }
}hl;
vector <int> visited;
void weird_dfs(int v, vector <vector <int> > &e1, vector <vector <int> > &e2){
    visited[v] = true;
    for(int elem : e1[v]){
        if(!visited[elem]){
            e2[v].push_back(elem);
            weird_dfs(elem, e1, e2);
        }
    }
}
vector <int> fen;
ll sum (int r)
{
    ll result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1){
        result+=fen[r];
    }
    return result;
}

void inc (int r, int delta)
{
    for(; r < fen.size(); r = (r |(r+1))){
        fen[r]+=delta;
    }
    return;
}
ll sum (int left, int right)
{
    return sum(right) - sum(left-1);
}

ll f(int x, int k){
    return (ll)(k - x%k)*(x/k)*(x/k) + (ll)(x % k)*(x/k + 1)*(x/k + 1);
}
void sol();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    for(int tt = 0; tt < t; ++tt){
        sol();
    }
    return 0;
}
void sol(){
    ll k, temp, temp1, temp2, m, n, k1, k2;
    cin >> n;
    vector <ll> a(n+1);
    a[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> temp;
        a[i] = temp;
    }
    cin >> m;
    ll l, r, lq, rr, md, mdd;
    l = -1;
    r = 1e18;
    while(l < r-1){
        temp1 = 0;
        md = (l+r)/2;
        for(int i = 1; i <= n; ++i){
            lq = 0;
            rr = a[i]-a[i-1];
            temp = a[i]-a[i-1];
            while(lq < rr-1){
                mdd = (lq+rr)/2;
                if(f(temp, mdd) - f(temp, mdd+1) < md){
                    rr = mdd;
                }
                else{
                    lq = mdd;
                }
            }
            temp1+=f(temp, rr);
        }
        if(temp1 > m){
            r = md;
        }
        else{
            l = md;
        }
    };
    ll ans = 0, counter = 0;
    md = r;
    for(int i = 1; i <= n; ++i){
        temp1 = a[i]-a[i-1];
        l = 0, r = temp1;
        while(l < r-1){
            mdd = (l+r)/2;
            if(f(temp1, mdd) - f(temp1, mdd+1) < md){
                r = mdd;
            }
            else{
                l = mdd;
            }
        }
        counter+=r-1;
        ans+=f(temp1, r);
    }
    cout << counter+(ans - m + md - 2)/(md-1);
    return;
}
