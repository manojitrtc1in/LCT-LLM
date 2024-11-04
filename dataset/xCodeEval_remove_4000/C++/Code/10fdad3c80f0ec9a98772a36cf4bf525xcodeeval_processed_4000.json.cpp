




























using namespace std;






















































































































template< class T, class X > inline bool checkbit(T a, X pos) { T t=1;return ((a&(t<<pos))>0);  }
template< class T, class X > inline T      setbit(T a, X pos) { T t=1;return (a|(t<<pos));      }
template< class T, class X > inline T    resetbit(T a, X pos) { T t=1;return (a&(~(t<<pos)));   }
template< class T, class X > inline T   togglebit(T a, X pos) { T t=1;return (a^(t<<pos));      }




















template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> inline T GCD(T a,T b)              { if(a<0)return GCD(-a,b);  if(b<0)return GCD(a,-b);    return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T id3(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a)                         { if(a<0)return -a;else return a;}
LL Bigmod(LL base,LL power,LL _MOD)                      { LL ret=1;while(power){if(power & 1)ret=(ret*base)%_MOD;base=(base*base)%_MOD;power>>=1;}return ret;}
LL ModInverse(LL number,LL _MOD)                         { return Bigmod(number,_MOD-2LL,_MOD); }


template<typename T> double DIS(T x1,T y1,T x2, T y2)   { return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)      { return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c)             { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }










void BINARY(int n){  bitset<31>a=n;  cout << a << endl;}
void id2(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }
template<class T> inline void id0( vector<T> &vec ){ sort( vec.begin(), vec.end() ); vec.erase( unique( vec.begin(), vec.end() ), vec.end() ); }
template<class T> inline void id1( T *ar,int &n)   { sort(ar + 1, ar + n + 1); n = unique(ar + 1, ar + n + 1) - ar - 1; }








 int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };                                  






























pair<int,int>frog[MX];
pair<int,int>mos[MX];

int ar[MX];

LL tree[4*MX];

void build(rot)
{
    tree[idx]=-inf;
    if(s==e) return;
    SEG;
    build(lch);
    build(rch);
}

void update(rot,int pos,LL v) {
    if(s==e) {
        tree[idx]=v;
        return;
    }
    SEG;
    if(pos<=mid) update(lch,pos,v);
    else         update(rch,pos,v);
    tree[idx]=max(tree[l],tree[r]);
}

int query(rot,int x,int y,LL v)
{
    SEG;
    if(s==x && e==y)
    {
        if(tree[idx]<v) return -1;
        if(s==e) return s;
        if(tree[l]>=v) return query(lch,s,mid,v);
        else           return query(rch,mid+1,e,v);
    }
    if(y<=mid)          return query(lch,x,y,v);
    else if(mid<x)      return query(rch,x,y,v);
    else {
            int ret = query(lch,x,mid,v);
            if(ret!=-1) return ret;
            ret=query(rch,mid+1,y,v);
            return ret;
    }
}

LL st[MX];
LL ed[MX];

int res[MX];

int main()
{
    DII(n,m);

    rep(i,1,n) II(frog[i].X,frog[i].Y);
    rep(i,1,m) II(mos[i].X,mos[i].Y);


    int tot = 0;

    rep(i,1,n) ar[++tot]=frog[i].X;
    rep(i,1,m) ar[++tot]=mos[i].X;

    sort(ar+1,ar+1+tot);

    build(1,1,tot);

    rep(i,1,n)
    {
        int pos = LBB(ar,1,tot,frog[i].X);
        st[pos]=frog[i].X;
        ed[pos]=frog[i].X+frog[i].Y;
        update(1,1,tot,pos,ed[pos]);
    }

    set< pair<LL,int> >ss;

    ss.insert( MP( ((LL)(1e18)) , 0) );




    rep(i,1,m)
    {
        int lt  = LBB(ar,1,tot,mos[i].X);
        int pos = query(1,1,tot,1,lt,mos[i].X);
        if(pos==-1){
            ss.insert( MP( (LL)mos[i].X,i) );
        }
        else
        {



            res[pos]++;
            ed[pos]+=mos[i].Y;

            auto it = ss.lower_bound( MP(st[pos],0) );

            while( it->X<=ed[pos] ){

                res[pos]++;
                ed[pos]+=mos[it->Y].Y;
                ss.erase( MP( it->X , it->Y ) );


                it = ss.lower_bound( MP(st[pos],0) );
            }




            update(1,1,tot,pos,ed[pos]);

        }
    }

    rep(i,1,n) {
        int pos = LBB(ar,1,tot,frog[i].X);
        printf("%d %lld\n",res[pos],ed[pos]-st[pos]);
    }






    return 0;
}
