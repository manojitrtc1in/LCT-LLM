
#include <bits/stdc++.h>


#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#include <set>

using namespace std;
#define output freopen("output.txt","w",stdout)
#define input freopen("input.txt","r",stdin)
#define inputfile(x) freopen(x,"r",stdin)
#define outpufile(x) freopen(x,"w",stdout)


#define pb(x)  push_back(x)
#define pf  printf
#define sc scanf
#define mxe(a,n)   (*max_element(a,a+n))
#define mne(a,n)   (*min_element(a,a+n))
#define SUM(a,n)   (accumulate(a,a+n,0))
#define countbit(x) __builtin_popcount(x)
#define lb  lower_bound 

#define ub  upper_bound 

#define bs  binary_search
#define SQ(a)  ((a)*(a))
#define _PI (acos(-1.0))
#define mid(l,r)    ((l+r)>>1)


#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


#define xx first
#define yy second
#define mp(x,y) make_pair(x,y)


#define si1(n) sc("%d",&n)
#define sl1(n) sc("%lld",&n)
#define slu1(n) sc("%llu",&n)
#define sd1(n) sc("%lf",&n)
#define ss1(n) sc("%s",n)


#define si2(n,m) sc("%d %d",&n,&m)
#define sl2(n,m) sc("%lld %lld",&n,&m)
#define slu2(n,m) sc("%llu %llu",&n,&m)
#define sd2(n,m) sc("%lf %lf",&n,&m)


#define si3(n,m,l) sc("%d %d %d",&n,&m,&l)
#define sl3(n,m,l) sc("%lld %lld %lld",&n,&m,&l)
#define slu3(n,m,l) sc("%llu %llu %llu",&n,&m,&l)
#define sd3(n,m,l) sc("%lf %lf %lf",&n,&m,&l)



#define pi1(n) pf("%d",n)
#define pl1(n) pf("%lld",n)
#define plu1(n) pf("%llu",n)
#define pd1(n,pre) pf("%.*f",pre,n)
#define ps1(n) pf("%s",n)


#define pi2(n,m) pf("%d %d",n,m)
#define pl2(n,m) pf("%lld %lld",n,m)
#define plu2(n,m) pf("%llu %llu",n,m)
#define pd2(n,m,pre) pf("%.*f %.*f",pre,n,pre,m)


#define pi3(n,m,l) pf("%d %d %d",n,m,l)
#define pl3(n,m,l) pf("%lld %lld %lld",n,m,l)
#define plu3(n,m,l) pf("%llu %llu %llu",n,m,l)


#define nln putchar(10)
#define sps putchar(' ')
#define pch(c) putchar(c)
int __TESTCASE=0;
#define tcsp pf("Case %d: ",++__TESTCASE)
#define tcnl pf("Case %d:\n",++__TESTCASE)
#define dg()   pf("-----------here\n")

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sc1(n) cin>>n
#define sc2(n,m) cin>>n>>m
#define sc3(n,m,k) cin>>n>>m>>k
#define sc4(n,m,k,l) cin>>n>>m>>k>>l

#define pr1(n) cout<<n
#define pr2(n,m) cout<<n<<" "<<m
#define pr3(n,m,k) cout<<n<<" "<<m<<" "<<k
#define pr4(n,m,k,l) cin<<n<<" "<<m<<" "<<k<<" "<<l
#define NL cout<<"\n"
#define SPS cout<<" "

#define setPre(x) setprecision(x)
#define fixP cout<<fixed





#define fr0(i,n) for(i=0;i<n;i++)
#define fr1(i,n) for(i=1;i<=n;i++)
#define FR(i,b,e) for(i=b;i<=e;i++)
#define FRR(i,e,b) for(i=e;i>=b;i--)


#define set0(x) memset(x,0,sizeof x)
#define setn1(x) memset(x,-1,sizeof x)
#define setinf(x) memset(x,125,sizeof x)
#define Mem(Array,Val,Size) memset(Array,Val,(Size)*(sizeof(Array[0])))



#define SZ(v)   ((int) (v).size())
#define all(v)  (v).begin(), (v).end()


#define On(x,i)  (x|=(1<<(i)))
#define Off(x,i) (x&= ~(1<<(i)))
#define isOn(x,i) (x&(1<<(i)))
#define Toggle(x,i) (x^=(1<<(i)))
#define tmod(x,i)  (x&(~(-1<<i)))



#define CLPF fflush(stdout)
#define CLCT cout << flush
#define CLCT1 cout.flush()



typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<pii ,pii > ppii;
typedef set<int> si;
typedef set<ll> sl;
typedef map<int,int> mii;
typedef map<ll,int> mli;
typedef map<string,int> msi;
typedef long double LD;
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))




template <class _T>inline void ina(_T a[],int n){int i; fr0(i,n)sc1(a[i]);}
template <class _T>inline void outa(_T a[],int n){int i; fr0(i,n-1)pr1(a[i]),SPS;if(i)pi1(i);NL;}



const double EPS = 1e-9;
const int SIZE=1e6;











template<class _T>inline _T pow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans*=a,ans%=m;a*=a;a%=m;b>>=1;}return ans;}
template<class _T>inline _T pow(_T a,_T b){_T ans=1;while(b){if(b&1)ans*=a;a*=a;b>>=1;}return ans;}
template<class _T>inline _T add(_T a,_T b,_T m){return a>=m-b?a-(m-b):a+b;}

template<class _T>inline _T multiply(_T a,_T b,_T m){_T ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=add(ans,a,m);b>>=1;a=add(a,a,m);}return ans;}

template<class _T>inline _T bigpow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans=multiply(ans,a,m);a=multiply(a,a,m);b>>=1;}return ans;}
template<class _T>inline _T modinvers(_T a,_T m){return m>2000000000LL?bigpow(a,m-2,m):pow(a,m-2,m);}



template<class _T> _T _egcd(_T a, _T b, _T &x,_T &y){if(!b){x=1,y=0;return a;}_T _g=_egcd(b,a%b,x,y);_T xt=x;x=y,y=xt-(a/b)*y;return _g;}
template<class _T>inline _T fmodinvers(_T a,_T m){_T x,y;_egcd(a,m,x,y);x%=m;if(x<0)x+=m;return x;} 

template<class _T>inline _T _lcm(_T a, _T b){return (a*b)/__gcd(a,b);}


template<class _T>inline _T naturalSum(_T n){return (n*(n+1))/2;}
template<class _T>inline _T sqrSum(_T n){return (n * (n + 1) * (2*n + 1)) / 6;}
template<class _T>inline _T cubeSum(_T n){return  SQ((n*(n+1))/2);}




template<class _T>inline _T naturalSum(_T n,_T m){return ((n*(n+1))/2)%m;}
ll MOD_INV_OF_6;

template<class _T>inline _T sqrSum(_T n,_T m){n%=m;return ((( ((n * (n + 1))%m) * (( (2*n)%m + 1)%m)) %m )* MOD_INV_OF_6)%m;}
template<class _T>inline _T cubeSum(_T n,_T m){return  SQ(((n*(n+1))/2)%m)%m;}







const int MXS=1e7;



bool inside(pii r,int p)
{
    return p>=r.xx&&p<=r.yy;
}
typedef string T1;
typedef int  T2;


struct _node
{
    unordered_map<T1,T2> table;
    _node *l,*r;
    _node(){l=r=NULL;}
};

_node _ALL[MXS];

_node *_root[300099];

int _AV;
_node* insert(_node *nd, pii range,int point, pair<T1,T2> item)
{

    _node *nw=&_ALL[_AV++];
    if(nd!=NULL)
    {
        nw->l=nd->l;
        nw->r=nd->r;

    }else
    {
       nw->l=NULL;
        nw->r=NULL;
    }

    if(range.yy==range.xx)
    {

        if(nd)nw->table=unordered_map<T1,T2>(all(nd->table));
        nw->table[item.xx]=item.yy;

        

        return nw;
    }

    int md=mid(range.xx,range.yy);
    pii L={range.xx,md};
    pii R={md+1,range.yy};

    if(inside(L,point))
    {
        nw->l=insert(nw->l,L,point,item);
    }else nw->r=insert(nw->r,R,point,item);
    return nw;

}
_node* erase(_node *nd, pii range,int point, pair<T1,T2> item)
{

    _node *nw=&_ALL[_AV++];
    if(nd!=NULL)
    {
        nw->l=nd->l;
        nw->r=nd->r;

    }else
    {
       nw->l=NULL;
        nw->r=NULL;
    }

    if(range.yy==range.xx)
    {
        if(nd)nw->table=unordered_map<T1,T2>(all(nd->table));
        nw->table.erase(nw->table.find(item.xx));
        return nw;
    }

    int md=mid(range.xx,range.yy);
    pii L={range.xx,md};
    pii R={md+1,range.yy};

    if(inside(L,point))
    {
        nw->l=erase(nw->l,L,point,item);
    }else nw->r=erase(nw->r,R,point,item);
    return nw;

}


int fnd(_node *nd,pii range,int point,T1 key)
{
    if(nd==NULL) return -1;

    if(range.xx==range.yy)
    {
        return nd->table.find(key)!=nd->table.end()?nd->table[key]:-1;
    }
    int md=mid(range.xx,range.yy);
    pii L={range.xx,md};
    pii R={md+1,range.yy};
    if(inside(L,point)) return fnd(nd->l,L,point,key);
    else return fnd(nd->r,R,point,key);
}






struct node
{
    int sum;
    node *l,*r;
    node(){l=r=NULL;}
};

node ALL[MXS];
node *root[300099];
int AV;
node * upd(node *nd, pii range,int point,int val)
{
    node *nw=&ALL[AV++];
    if(nd!=NULL)
    {
        nw->l=nd->l;
        nw->r=nd->r;
        nw->sum=nd->sum;

    }else
    {
       nw->l=NULL;
        nw->r=NULL;
        nw->sum=0;
    }

    if(range.yy==range.xx)
    {
        nw->sum+=val;
        return nw;
    }

    int md=mid(range.xx,range.yy);
    pii L={range.xx,md};
    pii R={md+1,range.yy};

    if(inside(L,point))
    {
        nw->l=upd(nw->l,L,point,val);
    }else nw->r=upd(nw->r,R,point,val);

    nw->sum=(nw->l?nw->l->sum:0)+(nw->r?nw->r->sum:0);
    return nw;

}

int qry(node *nd,pii range,int RR)
{
    if(nd==NULL) return 0;
    if(range.xx>RR) return 0;
    if(range.yy<=RR) return (nd->sum);

    int md=mid(range.xx,range.yy);
    pii L={range.xx,md};
    pii R={md+1,range.yy};
    return qry(nd->l,L,RR)+qry(nd->r,R,RR);
}


int mod=100003 ;



size_t myhash(string &s)
{
    size_t h=0;

    for(char c:s)
    {
        h*=26;
        h+=(c-'a');
        h%=mod;
    }
    return h;
}

int main()
{
    root[0]=NULL;
    _root[0]=NULL;
    int day=1;
    pii hashrange={0,mod-1};
    pii priorange={1,1000000000};
    int q,p,x,h;
    si1(q);
    string com,s;
    while(q--)
    {
        cin>>com;

        if(com[0]=='s')
        {
            

            cin>>s>>x;
             h=myhash(s);
             int xp=fnd(_root[day-1],hashrange,h,s);
             if(xp!=-1)
             {
                 root[day]=upd(root[day-1],priorange,xp,-1);
                 root[day]=upd(root[day],priorange,x,1);
             }else
             {
                 root[day]=upd(root[day-1],priorange,x,1);
             }

            _root[day]=insert(_root[day-1],hashrange,h,mp(s,x));

        }else if(com[0]=='r')
        {
            cin>>s;
            h=myhash(s);
            int x=fnd(_root[day-1],hashrange,h,s);
            if(x!=-1)
            {
                root[day]=upd(root[day-1],priorange,x,-1);
                _root[day]=erase(_root[day-1],hashrange,h,mp(s,x));
            }else
            {
                root[day]=root[day-1];
                _root[day]=_root[day-1];

            }
            

        }else if(com[0]=='q')
        {
            cin>>s;
            h=myhash(s);
            x=fnd(_root[day-1],hashrange,h,s);
            

            if(x==-1)pf("-1\n");
            else pf("%d\n",qry(root[day-1],priorange,x-1));
            CLPF;

            root[day]=root[day-1];
            _root[day]=_root[day-1];
            

        }else
        {
            

            int d;
            cin>>d;
            root[day]=root[max(day-d-1,0)];
            _root[day]=_root[max(day-d-1,0)];

        }
        

        day++;
    }



    return 0;
}


