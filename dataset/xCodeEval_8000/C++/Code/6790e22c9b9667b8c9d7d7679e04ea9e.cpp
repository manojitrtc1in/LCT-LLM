#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
typedef map<int, int> mii;

#define rp(i, e) for (int (i) = 0; (i) < (int) (e); (i)+=1)
#define rp2(i, a, e) for (int (i) = (a); (i) < (int) (e); (i)+=1)
#define rp3(i, a, e, s) for (int (i) = (a); (i) < (int) (e); (i)+=(s))
#define rp4(i, a, e) for (int (i) = a; (i) > (int) (e); (i)-=1)
#define rp5(i, a, e, s) for (int (i) = a; (i) > (int) (e); (i)+=(s))
 
#define MP make_pair
#define vt vector
#define pb push_back
#define ins insert
#define sz(x) int(x.size())
#define len(x) sz(x)
#define str string
#define tstr(x) to_string(x)
#define all(x) (x).begin(),(x).end()
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fd(x, e) (x.find(e) != x.end())
#define rva(a, n) sort((a), (a)+(n)); reverse((a), (a)+(n));
#define rvs(s) reverse(all(s));
#define nr(a, b) for (int ar = 0; ar < b; ar++) {cin >> (a)[ar];}
#define nr1(a, b) for (int ar = 0; ar < b; ar++) {cin >> (a)[ar+1];}
#define nr2(a, n, m) rp(ii, n){rp(jj, m) cin >> (a)[ii][jj];}
#define nl endl
#define fs first
#define sc second
#define ub upper_bound
#define lb lower_bound

#define umax(x) *max_element(begin(a), end(a))
#define umin(x) *min_element(begin(a), end(a))

template <class T> void amin(T & a, const T & b) {if (a>b) a = b;}
template <class T> void amax(T & a, const T & b) {if (a<b) a = b;}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}



struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  

		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};


class mint {
public:
    static const int M0D = 1000000007;
    typedef long long ll;
    int u;
    mint(){}; 
    mint(int v):u(v){}   
    operator int&(){return u;}
    operator const int&() const {return u;}
    mint operator +(int v) const {return u+v<M0D?u+v:u+v-M0D;}
    mint operator -(int v) const {return u<v?u-v+M0D:u-v;}
    mint operator *(int v) const {return u*ll(v)%M0D;}
    mint operator /(int v) const {return u*inv(v)%M0D;}
    mint operator -() const {return u?M0D-u:0;}
    mint& operator +=(int v){u+=u+v<M0D?v:v-M0D; return *this;}
    mint& operator -=(int v){u-=u<v?v-M0D:v; return *this;}
    mint& operator *=(int v){u=u*ll(v)%M0D; return *this;}
    mint& operator /=(int v){u=u*inv(v)%M0D; return *this;}
    static ll inv(int x){return x>1?inv(M0D%x)*(M0D-M0D/x)%M0D:x;}
};


class segtree {
    public:
    struct node {
        long long add_k = 0;
        long long add_b = 0;
        long long sum_k = 0;
        long long sum_b = 0;

        void apply(int l, int r, long long vk, long long vb) {
            add_k += vk;
            add_b += vb;
            sum_k += vk * (r - l + 1);
            sum_b += vb * (r - l + 1);
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.sum_k = a.sum_k + b.sum_k;
        res.sum_b = a.sum_b + b.sum_b;
        return res;
    }

    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        if (tree[x].add_k != 0 || tree[x].add_b) {
            tree[x + 1].apply(l, y, tree[x].add_k, tree[x].add_b);
            tree[z].apply(y + 1, r, tree[x].add_k, tree[x].add_b);
            tree[x].add_k = tree[x].add_b = 0;
        }
    }

    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }

    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }

    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v...);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }

    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
           return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }

    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }

    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }

    

    


    int find_first(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }

    int find_last(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};





const int c=505;
int t, n, m, fix[c][c], ans[c][c], rotcnt, change, old_cl, new_cl;
int fix2[c][c], ans2[c][c];
void color_boundary() {
    for (int cnt=1; cnt<=2; cnt++) {
        for (int j=2; j<=m; j++) {
            if (!ans[1][j]) ans[1][j]=ans[1][j-1];
            if (ans[1][j]!=ans[1][j-1]) change++;
        }
        for (int i=2; i<=n; i++) {
            if (!ans[i][m]) ans[i][m]=ans[i-1][m];
            if (ans[i][m]!=ans[i-1][m]) change++;
        }
        for (int j=m-1; j>=1; j--) {
            if (!ans[n][j]) ans[n][j]=ans[n][j+1];
            if (ans[n][j]!=ans[n][j+1]) change++;
        }
        for (int i=n-1; i>=1; i--) {
            if (!ans[i][1]) ans[i][1]=ans[i+1][1];
            if (ans[i][1]!=ans[i+1][1]) change++;
        }
        if (!ans[1][1]) ans[1][1]=1;
        if (cnt==1) change=0;
    }
}
void rotate_90() {
    rotcnt++;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans2[i][j]=ans[i][j], fix2[i][j]=fix[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans[j][n+1-i]=ans2[i][j];
            fix[j][n+1-i]=fix2[i][j];
        }
    }
    swap(n, m);
}
void good_rotation() {
    for (int cnt=1; cnt<=4; cnt++) {
        bool same=1, opposite=0;
        for (int i=1; i<=n; i++) {
            if (ans[i][1]!=ans[1][1]) same=0;
            if (1<i && i<n && ans[1][1]!=ans[i][m]) opposite=1;
        }
        if (!same || !opposite) rotate_90();
    }
}
void color_the_stripes() {
    for (int i=2; i<n; i++) {
        for (int j=2; j<m; j++) {
            if (!fix[i][j]) {
                if (i%4==2 || i%4==3) ans[i][j]=old_cl;
                else ans[i][j]=new_cl;
            }
        }
    }
}
void avoid_touching() {
    for (int i=1; i<n; i++) {
        if (ans[i][m-1]==ans[i+1][m] && ans[i+1][m-1]==ans[i][m] && ans[i][m]!=ans[i+1][m]) {
            if (!fix[i][m]) ans[i][m]=3-ans[i][m];
            else ans[i+1][m]=3-ans[i+1][m];
        }
    }
}
void boundary_stripe_connection() {
    int first=0, last=0;
    for (int i=1; i<=n; i++) {
        if (ans[i][m]==new_cl) {
            if (!first) first=i;
            last=i;
        }
    }
    if (first==0 || (last>3 && first<n-2)) return;
    if (last<=3 && fix[4][m-1]==old_cl) {
        for (int i=3; i<=5; i++) {
            ans[i][m]=new_cl;
        }
        return;
    }
    if (first>=n-2 && fix[n-3][m-1]==old_cl) {
        for (int i=n-4; i<=n-2; i++) {
            ans[i][m]=new_cl;
        }
        return;
    }
    int x=(last<=3 ? 2 : n-2);
    for (int i=x; i<=x+1; i++) {
        for (int j=m-1; j<=m; j++) {
            if (!fix[i][j]) ans[i][j]=new_cl;
        }
    }
}
void connect_isolated_point(int x, int y) {
    if (ans[x-1][y]==new_cl || ans[x+1][y]==new_cl || ans[x][y+1]==new_cl) return;
    int x1=(x==2 ? 1 : n), x2=(x==2 ? 2 : n-1), x3=(x==2 ? 3 : n-2), x4=(x==2 ? 4 : n-3);
    if (y<=m-2 && ans[x1][y+2]==new_cl) {
        ans[x1][y]=new_cl;
        ans[x1][y+1]=new_cl;
        return;
    }
    if (y<=m-2 && ans[x2][y+2]==new_cl) {
        ans[x2][y+1]=new_cl;
        return;
    }
    if (fix[x4][y]!=old_cl) {
        ans[x3][y]=new_cl;
    } else {
        int y2=(y+1<m ? y+1 : y-1);
        ans[x2][y2]=new_cl;
        ans[x3][y2]=new_cl;
    }
}
void bridge_through_the_stripe(int x) {
    for (int j=2; j<=4; j++) {
        bool good=1;
        for (int i=x-1; i<=x+2; i++) {
            if (fix[i][j]==old_cl) good=0;
        }
        if (good) {
            ans[x][j]=new_cl;
            ans[x+1][j]=new_cl;
            return;
        }
    }
    for (int i=x-1; i<=x+2; i++) {
        if (!fix[i][3]) ans[i][3]=new_cl;
    }
    if (fix[x-1][3]) {
        ans[x-1][2]=old_cl;
        ans[x][4]=new_cl;
    }
    if (fix[x+2][3]) {
        ans[x+2][2]=old_cl;
        ans[x+1][4]=new_cl;
    }
    if (fix[x][3] || fix[x+1][3]) {
        ans[x][2]=new_cl;
        ans[x+1][2]=new_cl;
    }
}
int main()
{
    cin >> t;
    for (int tc=1; tc<=t; tc++) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                char c;
                cin >> c;
                fix[i][j]=(c=='B' ? 1 : c=='W' ? 2 : 0);
                ans[i][j]=fix[i][j];
            }
        }
        color_boundary();
        if (change>=4) {
            cout << "NO\n";
        } else {
            good_rotation();
            old_cl=ans[1][1], new_cl=3-ans[1][1];
            color_the_stripes();
            avoid_touching();
            boundary_stripe_connection();
            for (int j=2; j<m; j++) {
                if (fix[2][j]==new_cl) connect_isolated_point(2, j);
                if (fix[n-1][j]==new_cl) connect_isolated_point(n-1, j);
            }
            for (int i=6; i<=n-6; i+=4) {
                if (ans[1][1]==ans[i][m] || ans[1][1]==ans[i+1][m]) bridge_through_the_stripe(i);
            }
            while (rotcnt<4) rotate_90();
            cout << "YES\n";
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    cout << (ans[i][j]==1 ? "B" : "W");
                }
                cout << "\n";
            }
        }
        rotcnt=0, change=0;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                fix[i][j]=0, ans[i][j]=0;
                fix[j][i]=0, ans[j][i]=0;
            }
        }
    }
    return 0;
}