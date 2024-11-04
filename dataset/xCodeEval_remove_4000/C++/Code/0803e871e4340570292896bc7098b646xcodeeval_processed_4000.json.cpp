


















using namespace std;










































template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}


void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}






std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int id0(int a, int b, int *x, int *y)  
{  
    

    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1; 

    int gcd = id0(b%a, a, &x1, &y1);  
  
    

    

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

vector<int> id1(string const& s) {
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
    ret += "
 
  ret += "
  return ret;
}
 
string id3(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int id2 = 2*C-i; 

    
    P[i] = (R > i) ? min(R-i, P[id2]) : 0;
    
    

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
const double EPS = 1e-9; 

struct PT
{
    double x,y;

    double length(){
        return sqrt(x*x+y*y);
    }
    int normalize() 

    {
        double l=length();
        if(fabs(l)<EPS) return -1;
        x/=l;y/=l;
        return 0;
    }

    PT operator-(PT a)
    {
        PT r;
        r.x=x-a.x;
        r.y=y-a.y;
        return r;
    }
    PT operator+(PT a)
    {
        PT r;
        r.x=x+a.x;
        r.y=y+a.y;
        return r;
    }
    PT operator*(double sc)
    {
        PT r;
        r.x=x*sc;
        r.y=y*sc;
        return r;
    }

    bool operator<(const PT& a) 
    {
        if(fabs(x-a.x)<EPS) return y<a.y;
        return x<a.x;
    }
    double dist(PT &a,PT &b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    }
    double dot(PT& a, PT& b)
    {
        return(a.x*b.x+a.y*b.y);
    }
    double cross(PT& a, PT& b)
    {
        return(a.x*b.y-b.x*a.y);
    }
    

    

    


     double trap(PT a,PT b)
     {
         return (0.5*(b.x - a.x)*(b.y + a.y));
     }
    double triarea(PT a, PT b, PT c) 
    {
         return fabs(trap(a,b)+trap(b,c)+trap(c,a)); 
    }
    
};


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
                    
                    C[i][j] %= mod;
                    
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
                    
                    C[i][j] %= mod;
                    
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
                
                C[i][j] %= mod;
                
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
                
                A[i][j] %= mod;
                
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
                
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                
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
                
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                
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
                
                A[i][j] %= mod;
                if(A[i][j] < 0)
                    A[i][j] += mod;
                
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

    

    Matrix transpose()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        return C;
    }

    

    void transposeInplace()
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

const int N=1e6+5;









ll val[N],op[N],rival[N],n;
vll imp(N,1);

vll g[N];

void dfs(ll u){
	

	
	if(op[u]==0)
	return;
	
	ll c1=g[u][0];
	dfs(c1);
	
	if(op[u]==4)
	{
		
		val[u]=!val[c1];
		return;		
	}
	
	
	ll c2=g[u][1];
	dfs(c2);
	
	if(op[u]==1){
		val[u]=val[c1]&val[c2];
	}
	
	if(op[u]==2){
		val[u]=val[c1]|val[c2];
	}
	
	if(op[u]==3){
		val[u]=val[c1]^val[c2];
	}
	
	
}

ll ass(ll u,ll p){
	
	if(p==u)
	return 1;
	
	if(!imp[p])
	return 0;
	
	if(op[p]==4){
		return 1;
		
	}
	
	
	
	ll r=rival[u];
	
	if(op[p]==1 and val[r]==0)
	return 0;
	
	if(op[p]==2 and val[r]==1)
	return 0;
	
	return 1;
	
	
}

void dfs2(ll u,ll p){
	
	imp[u]=ass(u,p);
	
	if(op[u]==0)
	{
		
		return;
	}
	
	ll c1=g[u][0];
	dfs2(c1,u);
	
	if(op[u]==4)
	{
		return;		
	}
	
	ll c2=g[u][1];
	
	dfs2(c2,u);
	
	
}

int32_t main()
{
    
	fast	
	cout << fixed << setprecision(12);
	cin>>n;
	string s;
	ll a,b;
	fore(i,1,n){
		cin>>s;
		
		

		if(s[0]=='I'){
			op[i]=0;
			cin>>val[i];
		}
		
		else if(s[0]=='N'){
			op[i]=4;
			cin>>a;
			g[i].pb(a);
		}
		
		else{
			cin>>a>>b;
			if(s[0]=='A')
				op[i]=1;
			
			if(s[0]=='O')
				op[i]=2;
				
			if(s[0]=='X')
				op[i]=3;
			
				
				
			g[i].pb(a);
			g[i].pb(b);
			
			rival[a]=b;
			rival[b]=a;
		}
		
	}
	
	

	if(1){	


		auto fml=[&](int x,int y){
			return x*x+y*y;

		};

		f(i,100) {

		int a1=fml(0,0);
		int a2=fml(1,1);

		vector<int> orz;
		orz.push_back(a1);
		orz.push_back(a2);

		

		

		sort(all(orz));

		}
	}
	
	
	dfs(1);
	
	
	dfs2(1,1);
	
	
	fore(i,1,n){
		if(op[i]==0){
			if(!imp[i])
			cout<<val[1];
			else
			cout<<(val[1]^1);
		}
		
		
	}



    

	return 0;
    
}