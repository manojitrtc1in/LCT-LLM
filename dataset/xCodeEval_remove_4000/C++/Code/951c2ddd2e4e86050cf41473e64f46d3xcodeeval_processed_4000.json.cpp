


















using namespace std;









































































int id3=0;























































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





template <class _T>inline void ina(_T a[],int n){int i; fr0(i,n)sc1(a[i]);}
template <class _T>inline void outa(_T a[],int n){int i; fr0(i,n-1)pr1(a[i]),SPS;if(i)pi1(i);NL;}



const double EPS = 1e-9;
const int SIZE=1e6;











template<class _T>inline _T pow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans*=a,ans%=m;a*=a;a%=m;b>>=1;}return ans;}
template<class _T>inline _T pow(_T a,_T b){_T ans=1;while(b){if(b&1)ans*=a;a*=a;b>>=1;}return ans;}
template<class _T>inline _T add(_T a,_T b,_T m){return a>=m-b?a-(m-b):a+b;}

template<class _T>inline _T multiply(_T a,_T b,_T m){_T ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=add(ans,a,m);b>>=1;a=add(a,a,m);}return ans;}

template<class _T>inline _T bigpow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans=multiply(ans,a,m);a=multiply(a,a,m);b>>=1;}return ans;}
template<class _T>inline _T id0(_T a,_T m){return m>2000000000LL?bigpow(a,m-2,m):pow(a,m-2,m);}



template<class _T> _T id4(_T a, _T b, _T &x,_T &y){if(!b){x=1,y=0;return a;}_T _g=id4(b,a%b,x,y);_T xt=x;x=y,y=xt-(a/b)*y;return _g;}
template<class _T>inline _T id1(_T a,_T m){_T x,y;id4(a,m,x,y);x%=m;if(x<0)x+=m;return x;} 

template<class _T>inline _T _lcm(_T a, _T b){return (a*b)/__gcd(a,b);}


template<class _T>inline _T naturalSum(_T n){return (n*(n+1))/2;}
template<class _T>inline _T id2(_T n){return (n * (n + 1) * (2*n + 1)) / 6;}
template<class _T>inline _T cubeSum(_T n){return  SQ((n*(n+1))/2);}




template<class _T>inline _T naturalSum(_T n,_T m){return ((n*(n+1))/2)%m;}
ll id5;

template<class _T>inline _T id2(_T n,_T m){n%=m;return ((( ((n * (n + 1))%m) * (( (2*n)%m + 1)%m)) %m )* id5)%m;}
template<class _T>inline _T cubeSum(_T n,_T m){return  SQ(((n*(n+1))/2)%m)%m;}







const int MXS=1e7;



struct _node{

    bool end;
    int prio;
    _node *next[26];
    _node()
    {
        end=0;
        for(int i=0;i<26;i++)next[i]=NULL;
    }
};
_node _ALL[2000000];
_node *_root[300099];

int _AV;

_node* insert(_node* rt,string &s,int prio)
{

    

    _node *nw=&_ALL[_AV++];
    _node *nwrt=nw;
    if(rt)for(int j=0;j<26;j++)
    {
        nw->next[j]=rt->next[j];
        nw->end=rt->end;
        nw->prio=rt->prio;
    }

    for(int i=0;s[i];i++)
    {
        

        int to=s[i]-'a';
        _node *nwt=&_ALL[_AV++];
        

        if(nw->next[to])
        {
            for(int j=0;j<26;j++)nwt->next[j]=nw->next[to]->next[j];
            nwt->end=nw->next[to]->end;
            nwt->prio=nw->next[to]->prio;
        }

        nw->next[to]=nwt;
        nw=nwt;
    }
    nw->end=1;
    nw->prio=prio;

    return nwrt;

}
_node* erase(_node* rt,string &s)
{

    _node *nw=&_ALL[_AV++];
    _node *nwrt=nw;
    if(rt)for(int j=0;j<26;j++)
    {
        nw->next[j]=rt->next[j];
        nw->end=rt->end;
        nw->prio=rt->prio;
    }

    for(int i=0;s[i];i++)
    {
        int to=s[i]-'a';
        _node *nwt=&_ALL[_AV++];
        

        if(nw->next[to])
        {
            for(int j=0;j<26;j++)nwt->next[j]=nw->next[to]->next[j];
            nwt->end=nw->next[to]->end;
            nwt->prio=nw->next[to]->prio;
        }

        nw->next[to]=nwt;
        nw=nwt;
    }
    nw->end=0;

    return nwrt;

}

int fnd(_node *nd,string &s)
{
    if(!nd) return -1;
    for(int i=0;s[i];i++)
    {
        int to=s[i]-'a';
        nd=nd->next[to];
        if(!nd) return -1;
    }
    if(nd->end) return nd->prio;
    return -1;
}






bool inside(pii r,int p)
{
    return p>=r.xx&&p<=r.yy;
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
             int xp=fnd(_root[day-1],s);
             

             if(xp!=-1)
             {
                 root[day]=upd(root[day-1],priorange,xp,-1);
                 root[day]=upd(root[day],priorange,x,1);
             }else
             {
                 root[day]=upd(root[day-1],priorange,x,1);
             }

            _root[day]=insert(_root[day-1],s,x);

        }else if(com[0]=='r')
        {
            cin>>s;
            h=myhash(s);
            int x=fnd(_root[day-1],s);
            if(x!=-1)
            {
                root[day]=upd(root[day-1],priorange,x,-1);
                _root[day]=erase(_root[day-1],s);
            }else
            {
                root[day]=root[day-1];
                _root[day]=_root[day-1];

            }
            

        }else if(com[0]=='q')
        {
            cin>>s;
            h=myhash(s);
            x=fnd(_root[day-1],s);
            

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



