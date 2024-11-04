


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <numeric>
#include <cmath>
#include <cstdlib>
using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
typedef long long ll;
typedef double D;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i = a;i<=(b);++i)
#define FORD(i,a,b) for(int i = a;i>=(b);--i)
#define FORE(a,b) for(vector<int>::iterator a = (b).begin();a!=(b).end();++a)


#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }



typedef long long LL;

struct BigNum {
#define REDUCE() while(len>1 && cyf[len-1]==0) len--;
        static const int BASE=1000000000, BD=9;
            int len, al;
                LL* cyf;
                    BigNum(int v=0, int l=2) {
                                len=1; al=l;
                                        cyf = new LL[al];
                                                REP(x,al) cyf[x]=0;
                                                        cyf[0]=v;
                                                                if (v>=BASE) przen(1);
                                                                    }
                        BigNum(const BigNum &a) {
                                    len=al=a.len;
                                            cyf = new LL[al];
                                                    REP(x,al) cyf[x]=a.cyf[x];
                                                        }
                            ~BigNum(){delete cyf;}
                                void Res(int l) {
                                            if (l>al) {
                                                            l=max(l,2*al);
                                                                        LL* n = new LL[l];
                                                                                    REP(x,l) n[x] = x>=al ? 0 : cyf[x];
                                                                                                delete cyf;
                                                                                                            cyf = n;
                                                                                                                        al = l;
                                                                                                                                }
                                                }
                                    void przen(int p) {
                                                int x=0;
                                                        for(;x<p || cyf[x]<0 || cyf[x]>=BASE;x++) {
                                                                        Res(x+2);
                                                                                    if(cyf[x]<0){LL i=(-cyf[x]-1)/BASE+1; cyf[x]+=i*BASE; cyf[x+1]-=i;}else
                                                                                                    if(cyf[x]>=BASE){LL i=cyf[x]/BASE; cyf[x]-=i*BASE; cyf[x+1]+=i;}
                                                                                            }
                                                                len=max(len,x+1);
                                                                        REDUCE();
                                                                            }
                                    
#define OPER1(op) bool operator op (const BigNum &a) const
                                       OPER1(==) {
                                                if(a.len!=len) return 0;
                                                        REP(x,len) if(cyf[x]!=a.cyf[x]) return 0;
                                                                return 1;
                                                                    }
                                          OPER1(<) { 
                                                    if(len!=a.len) return len<a.len;
                                                            int x=len-1;
                                                                    while(x && a.cyf[x]==cyf[x]) x--;
                                                                            return cyf[x]<a.cyf[x];
                                                                                }
                                              OPER1(>) { return a<*this; } 
                                                  OPER1(<=) { return !(a<*this); } 
                                                      OPER1(>=) { return !(*this<a); } 
                                                          OPER1(!=) { return !(*this==a); } 

                                                            
                                                              BigNum &operator=(int a) {
                                                                        REP(x,len) cyf[x]=0;
                                                                                len=1; cyf[0]=a; 
                                                                                        if (a>=BASE) przen(1);
                                                                                                return *this;
                                                                                                    }
                                                                  void operator+=(int a){cyf[0]+=a; przen(1);}
                                                                      void operator-=(int a){cyf[0]-=a; przen(1);}
                                                                          void operator*=(int a){REP(x,len) cyf[x]*=a; przen(len);}
                                                                              int operator/=(int a) { 
                                                                                        LL w=0;
                                                                                                FORD(p,len-1,0){w=w*BASE+cyf[p]; cyf[p]=w/a; w=w%a;}
                                                                                                        REDUCE();
                                                                                                                return w;
                                                                                                                    }
                                                                                  int operator%(int a) {
                                                                                            LL w=0;
                                                                                                    FORD(p,len-1,0) w=(w*BASE+cyf[p])%a;
                                                                                                            return w;
                                                                                                                }
                                                                                    
#define OPER2(op) BigNum& operator op (const BigNum &a)
                                                                                    OPER2(+=) {
                                                                                                Res(a.len);
                                                                                                        REP(x,a.len) cyf[x]+=a.cyf[x];
                                                                                                                przen(a.len);
                                                                                                                        return *this;
                                                                                                                          }
                                                                                        OPER2(-=) {
                                                                                                    REP(x,a.len) cyf[x]-=a.cyf[x]; 
                                                                                                            przen(a.len);
                                                                                                                    return *this;
                                                                                                                        }
                                                                                            OPER2(*=) {
                                                                                                    BigNum c(0,len+a.len);
                                                                                                            REP(x,a.len) {
                                                                                                                            REP(y,len) c.cyf[y+x]+=cyf[y]*a.cyf[x];
                                                                                                                                        c.przen(len+x);
                                                                                                                                                }
                                                                                                                    *this=c;
                                                                                                                            return *this;
                                                                                                                                }
                                                                                                OPER2(/=) { 
                                                                                                            int n=max(len-a.len+1,0);
                                                                                                                    BigNum d(0,n), prod;
                                                                                                                            FORD(i,n-1,0) {
                                                                                                                                            int l=0, r=BASE-1;
                                                                                                                                                        while(l<r) {
                                                                                                                                                                        int m=(l+r+1)/2;
                                                                                                                                                                                    if (*this < prod+(a*m<<i))
                                                                                                                                                                                                        r=m-1;
                                                                                                                                                                                                else
                                                                                                                                                                                                                    l=m;
                                                                                                                                                                                                            }
                                                                                                                                                                    prod+=a*l<<i;
                                                                                                                                                                                d.cyf[i]=l;
                                                                                                                                                                                            if (l) d.len = max(d.len, i+1);
                                                                                                                                                                                                    }
                                                                                                                                    *this=d;
                                                                                                                                            return *this;
                                                                                                                                                }
                                                                                                    OPER2(%=) { 
                                                                                                                BigNum v=*this;
                                                                                                                        v/=a;
                                                                                                                                v*=a;
                                                                                                                                        *this -= v;
                                                                                                                                                return *this;
                                                                                                                                                    }
                                                                                                        OPER2(=) {
                                                                                                                    Res(a.len);
                                                                                                                            FORD(x, len-1, a.len) cyf[x]=0;
                                                                                                                                    REP(x,a.len) cyf[x]=a.cyf[x];
                                                                                                                                            len=a.len;
                                                                                                                                                    return *this;
                                                                                                                                                     }
                                                                                                            
                                                                                                            void read(const vector<int> &v,int p) { 
                                                                                                                        *this=0;
                                                                                                                                FORD(x,v.size()-1,0) {
                                                                                                                                                *this *= p;
                                                                                                                                                            *this += v[x];
                                                                                                                                                                    }
                                                                                                                                    }
                                                                                                                BigNum &operator=(string a) { 
                                                                                                                            int s=a.length();
                                                                                                                                    *this=0;
                                                                                                                                            Res(len=s/BD+1);
                                                                                                                                                    REP(x,s) cyf[(s-x-1)/BD]=10*cyf[(s-x-1)/BD]+a[x]-'0';
                                                                                                                                                            REDUCE();
                                                                                                                                                                    return *this;
                                                                                                                                                                        }
                                                                                                                    void write() const {
                                                                                                                                printf("%d", int(cyf[len-1]));
                                                                                                                                        FORD(x,len-2,0) printf("%0*d", BD, int(cyf[x]));
                                                                                                                                            }
                                                                                                                        void write(char *buf) const {
                                                                                                                                    int p = sprintf(buf, "%d", int(cyf[len-1]));
                                                                                                                                            FORD(x,len-2,0) p += sprintf(buf+p, "%0*d", BD, int(cyf[x]));
                                                                                                                                                }
                                                                                                                            vector<int> write(int pod) const { 
                                                                                                                                        vector<int> w;
                                                                                                                                                BigNum v;
                                                                                                                                                        v=*this;
                                                                                                                                                                while(v.len>1 || v.cyf[0]) w.PB(v/=pod);
                                                                                                                                                                        return w;
                                                                                                                                                                    }
                                                                                                                                 
                                                                                                                                BigNum &operator<<=(int ile) {
                                                                                                                                            if(cyf[0]==0 && len==1) return *this;
                                                                                                                                                    Res(len+ile);
                                                                                                                                                            FORD(x,len-1,0) cyf[x+ile]=cyf[x];
                                                                                                                                                                    REP(x,ile) cyf[x]=0;
                                                                                                                                                                            len+=ile;
                                                                                                                                                                                    return *this;
                                                                                                                                                                                        }
                                                                                                                                    BigNum &operator>>=(int ile) {
                                                                                                                                                if(ile>=len) ile=len;
                                                                                                                                                        REP(x,len-ile) cyf[x]=cyf[x+ile];
                                                                                                                                                                FOR(x,len-ile,ile) cyf[x]=0;
                                                                                                                                                                        len-=ile;
                                                                                                                                                                                if(len==0) len=1;
                                                                                                                                                                                        return *this;
                                                                                                                                                                                            }
                                                                                                                                        BigNum sqrt() { 
                                                                                                                                                    int n=(len+1)/2;
                                                                                                                                                            BigNum a(0,n), sq;
                                                                                                                                                                    FORD(i,n-1,0) {
                                                                                                                                                                                    int l=0, r=BASE-1;
                                                                                                                                                                                                while(l<r) {
                                                                                                                                                                                                                    int m=(l+r+1)/2; 
                                                                                                                                                                                                                                    if (*this < sq+(a*2*m<<i)+(BigNum(m)*m<<2*i))
                                                                                                                                                                                                                                                            r=m-1;
                                                                                                                                                                                                                                                    else
                                                                                                                                                                                                                                                                            l=m;
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                            sq+=(a*2*l<<i)+(BigNum(l)*l<<2*i);
                                                                                                                                                                                                                        a.cyf[i]=l; a.len=n;
                                                                                                                                                                                                                                }
                                                                                                                                                                            return a;
                                                                                                                                                                               }
#define OPER3(op) BigNum operator op(const BigNum &a) const {BigNum w=*this;  w op ## = a;  return w; }
#define OPER4(op) BigNum operator op(int a) {BigNum w = *this; w op ## = a; return w; }
                                                                                                                                            OPER3(+); 
                                                                                                                                                OPER3(-); 
                                                                                                                                                    OPER3(*); 
                                                                                                                                                        OPER3(/); 
                                                                                                                                                            OPER3(%); 
                                                                                                                                                                OPER4(<<); 
                                                                                                                                                                    OPER4(>>); 
};

#define M 713

VI v[M];
BigNum w[M][M];
int d[M];

void dfs(int x, int o = -1)
{
    w[x][1] = 1;
    d[x] = 1;
    FORE(i,v[x]) if(*i != o) 
    {
        dfs(*i, x);
        d[x] += d[*i]; 
        FORD(j,d[x],0)
        {
           int o =  min(d[*i], j) + 1, k = 0;
           if(o > 5) 
           {
               o = 5;
               k = 5;
           }
           REP(u, o) w[x][j] = max(w[x][j], w[x][j-u] * w[*i][u] );
           REP(u, k) w[x][j] = max(w[x][j], w[x][u] * w[*i][j-u] );
        }
    }
    REP(j,d[x]+1)
        w[x][0] = max(w[x][0], w[x][j] * j);
   

}

int main()
{
    int n;
    scanf("%d",&n);
    REP(i,n-1)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(1);
    w[1][0].write();
    puts("");
    

    return 0;
}
