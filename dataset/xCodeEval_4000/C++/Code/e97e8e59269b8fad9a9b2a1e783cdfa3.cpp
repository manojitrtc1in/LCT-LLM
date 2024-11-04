



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int long long
#define mod 1000000007 

#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f(i,n) for(ll i=0;i<n;i++)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define run main
#define pb push_back
#define ar array
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define vc vector
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define ms(v,n,x) fill(v,v+n,x);
#define init(c,a) memset(c,a,sizeof(c))
#define sll set<ll>
#define vll vector<ll>
#define vpll vector<pll>
#define nl "\n"
#define maxi(a,b,c) max(a,max(b,c))
#define maxii(a,b,c,d) max(max(a,b),max(c,d))
#define mini(a,b,c) min(a,min(b,c))

#define inf 9e18
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
#define cases ll T;cin>>T;while(T--)

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N=1<<20;

int gcdExtended(int a, int b, int *x, int *y)  
{  
    

    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1; 

    int gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    

    

    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  

struct state { 
    int len, link;
    map<char,int> next;
};

const int MAXLEN = 250000;
state st[MAXLEN*2];
int sz, last;

inline void sa_init() {
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}

inline void sa_extend (char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

string lcs (string & s, string & t) {
    sa_init();
    for (int i=0; i<(int)s.length(); ++i)
        sa_extend (s[i]);
  
    int v = 0,  l = 0,
        best = 0,  bestpos = 0;
    for (int i=0; i<(int)t.length(); ++i) {
        while (v && ! st[v].next.count(t[i])) {
            v = st[v].link;
            l = st[v].len;
        }
        if (st[v].next.count(t[i])) {
            v = st[v].next[t[i]];
            ++l;
        }
        if (l > best)
            best = l,  bestpos = i;
    }
    return (t.substr (bestpos-best+1, best));
}

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; 

    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    

    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    

    

    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  

  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

ll NCR(int n, int r) 
{ 
  
    long long p = 1, k = 1;   
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
  
            

            long long m = __gcd(p, k);   
           
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
  
      
    } 
  
    else
        p = 1; 
  
   return p;
} 

void sad(ll x){
    x=x*100+5000;
}
const double EPS = 1e-9; 



struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}


int32_t run()
{
    
	fast	
	cout << fixed << setprecision(12);
	
	ll x,d;
	cin>>x>>d;sad(1);
	vll ans;sad(1);
	ll y=1;sad(1);
	f(i,60){
		sad(1);
		if(x>>i&1){
			sad(1);
			f(k,i)ans.pb(y);
			sad(1);
			ans.pb(y+d);
			sad(1);
			y+=5*d;
		}
	}
	sad(1);
	cout<<ans.size()<<nl;sad(1);
	for(auto i:ans)cout<<i<<" ";

    

	return 0;
    
}
template <typename T>
class Matrix {

public:

    vector < vector <T> > A;
    int r,c;

    

    Matrix()
    {
        this->r = 0;
        this->c = 0;
    }

    

    Matrix(int r,int c)
    {
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    

    Matrix(int r,int c,const T &val)
    {

        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }

    

    Matrix(int n)
    {
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }

    

    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout << A[i][j] << " ";

            cout << endl;
        }
    }

    

    

    void input()
    {
        

        

        

    }

    

    

    Matrix operator * (const Matrix<T> &B)
    {
        
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                {
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }

        return C;
    }

    

    

    

    void operator *= (const Matrix<T> &B)
    {
        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                {
                    C[i][j] = (C[i][j] + ( (long long)A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }
        this->r = C.r;
        this->c = C.c;
        this->A = C.A;
    }

    

    

    Matrix operator + (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                #endif
            }

        return C;
    }

    

    

    

    void operator += (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                A[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                A[i][j] %= mod;
                #endif
            }
    }

    

    Matrix operator - ()
    {
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = -A[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }

    

    

    Matrix operator - (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }

    

    

    

    void operator -= (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                A[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                A[i][j] %= mod;
                if(A[i][j] < 0)
                    A[i][j] += mod;
                #endif
            }
    }

    

    

    Matrix operator ^ (long long n)
    {
        assert(r == c);

        int i,j;
        Matrix <T> C(r);

        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n)
        {
            if(n&1)
                C *= X;

            X *= X;
            n /= 2;
        }
        return C;
    }

    

    

    

    void operator ^= (long long n)
    {
        assert(r == c);

        int i,j;
        Matrix <T> C(r) ;

        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n)
        {
            if(n&1)
                C *= (*this);

            (*this) *= (*this);
            n /= 2;
        }
        this->A = C.A;
    }

    

    Matrix trrespose()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        return C;
    }

    

    void trresposeInplace()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        this->r = C.r;
        this->c = C.c;
        this->A = C.A;
    }

    

    

    

    

    

    vector<T>& operator [] (int i)
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    

    

    const vector<T>& operator [] (int i) const
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    

    

    

    friend ostream& operator << (ostream &out,const Matrix<T> &M)
    {
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }

};
