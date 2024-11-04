



































using namespace std;
















































































template<typename T> T  In()   {  char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }














template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }


template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> T GCD(T a,T b)                     { if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T id3(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}
LL Bigmod(LL base,LL power,LL _MOD)                      { LL ret=1;while(power){if(power & 1)ret=(ret*base)%_MOD;base=(base*base)%_MOD;power>>=1;}return ret;}
LL ModInverse(LL number,LL _MOD)                         { return Bigmod(number,_MOD-2LL,_MOD); }


template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }


const double PI = 2 * acos(0);
double DEG(double x) { return (180.0*x)/(PI*1.0);}
double RAD(double x) { return (x*(PI*1.0))/(180.0);}


void id2(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<class T> inline void id0( vector<T> &vec ){ sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); }
template<class T> inline void id1( T *ar,int &n)   { sort(ar + 1, ar + n + 1); n = unique(ar + 1, ar + n + 1) - ar - 1; }


int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };                                  

































struct two_sat{

    vector <int> out[maxn];
    vector <int> in[maxn];
    vector <int> stk;
    vector <int> n_com[maxn];

    int   component[maxn];
    bool  vis [maxn];

    int n;

    void init(int _n) {
        n=_n;


        for(int i=0; i<=2*_n; i++) {
            out[i].clear();
            in[i].clear();
            n_com[i].clear();
            vis[i]=false;
            component[i]=-1;
        }
        stk.clear();
    }
    

    void add_edge(int x,int y) {
        out[x].push_back(y);
        in[y].push_back(x);
    }

    

    

    

    

    void add_or(int x,int basex,int y,int basey) {
        x= x*2+basex;
        y= y*2+basey;
        add_edge(x^1,y);
        add_edge(y^1,x);
    }
    

    void add_con_1(int x,int y) {
        add_or(x,0,y,0);
    }
    

    void add_con_2(int x,int y) {
        x *=2;
        y *=2;
        add_edge(x^1,y^1);
        add_edge(y,x);
    }
    

    void add_and(int x,int y)
    {
        add_edge(x*2+0,y*2+0);
    }
    

    void add_con_3(int x,int y) {
        add_or(x,1,y,1);
    }
    

    void add_con_4(int x,int y) {
        add_or(x,0,y,0);
        add_or(x,1,y,1);
    }
    

    

    void add_con_5(int x,int y) {
        add_or(x,0,y,0);
    }
    

    void add_con_6(int x,int y) {
        add_or(x,0,y,1);
    }
    

    void add_con_7(int x,int y) {
        add_or(x,1,y,0);
    }
    

    void add_con_8(int x,int y) {
        add_or(x,1,y,1);
    }
    

    void add_con_9(int x,int y) {
        add_edge((x<<1) ,(y<<1));
        add_edge((y<<1)+1,(x<<1)+1) ;
    }
    

    void add_con_10(int x) {
        add_edge((x<<1),(x<<1)+1);
    }
    

    void add_con_11(int x,int y) {
        add_edge((x<<1)+1,(y<<1)+1);
        add_edge(y<<1,x<<1);
    }
    

    void add_con_12(int x) {
        add_edge((x<<1)+1,(x<<1));
    }
    

    void remove_edge(int x,int y) {
        out[x].pop_back();
        in[y].pop_back();
    }

    void remove_or(int x,int basex,int y,int basey) {
        x= x*2+basex;
        y= y*2+basey;
        remove_edge(x^1,y);
        remove_edge(y^1,x);
    }

    void dfs1(int x) {
        vis [x] = true;
        for(int i=0; i<out[x].size(); ++i) {
            int y=out[x][i];
            if(!vis [ y ])
                dfs1(y);
        }
        stk.push_back(x);
    }

    void dfs2(int x, int c) {


        component[x] = c;
        n_com[c].push_back(x);
        for(int i=0; i<in[x].size(); ++i) {
            int y = in[x][i];
            if(component[y]==-1)
                dfs2(y, c);
        }
    }

    bool solve() {
        int n=this->n*2;
        for(int i = 0; i < n; i++) n_com[i].clear();
        stk.clear();



        for(int i = 0; i < n; i++)
            if(!vis [i])
                dfs1(i);

        int c= 0;
        for(int i = stk.size() - 1; i >= 0; i--)
            if(component[ stk [i] ]==-1)
                dfs2(stk [i], c++);

        for(int i=0; i<n; ++i) {
            if(component[i] == component[i^1]) {
                return false;
            }
        }
        return true;
    }

    int check[maxn];

    void dfs3(int u ,int ss) {

        for(int i=0; i<n_com[u].size(); ++i) {
            check[ n_com[u][i] ]=ss;
        }

        for(int i=0; i<n_com[u].size(); ++i) {
            if(check[ n_com[u][i] ^1 ]== -1)
                dfs3(component[ n_com[u][i] ^1 ] , !ss);
        }
    }

    vector<int> solution() {

        for(int i=0; i<2*n; ++i) {
            check[i] = -1;
        }

        for(int i = stk.size() - 1; i >= 0; i--) {
            if(check[ stk[i] ] == -1) {
                dfs3(component[ stk[i] ], 0);
            }
        }

        vector<int> ret;

        for(int i=0; i<2*n; i+=2) {
            if(check[ i ] == 1) {
                ret.push_back(i/2);
            }
        }

        return ret;
    }

} solver;

int ar[MX];
int br[MX];


int ans[MX];

int main()
{


    DIII(n,a,b);

    map<int,int>mp;

    rep(i,0,2*n) ans[i]=1;

    rep(i,1,n)
    {
        I(ar[i]);
        mp[ar[i]];
    }

    int cnt=0;
    for( map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        mp[it->first] = cnt++;
    }

    solver.init(n);

    rep(i,1,n) {
        int flag = 0;
        if(mp.find(a-ar[i])!=mp.end()) {
            int x = mp[ar[i]];
            int y = mp[a-ar[i]];
            solver.add_con_9(x,y);
            flag = 1;
        } else { 

            int x = mp[ar[i]];
            solver.add_con_10(x);
        }

        if(mp.find(b-ar[i])!=mp.end()) {
            int x=mp[ ar[i] ];
            int y=mp[ b-ar[i] ];
            solver.add_con_11(x,y);
            flag=1;
        } else { 

            int x=mp[ ar[i] ];
            solver.add_con_12(x);
        }
        if(flag==0) {
            puts("NO");
            return 0;
        }
    }

    if( solver.solve() )
    {
        puts("YES");

        vector<int>res = solver.solution();

        repv(i,res){
            ans[ res[i] ]=0;
        }

        rep(i,1,n) {
            printf("%d ",ans[ mp[ar[i]] ]);
        }

    }
    else
    {
        puts("NO");
    }

}
