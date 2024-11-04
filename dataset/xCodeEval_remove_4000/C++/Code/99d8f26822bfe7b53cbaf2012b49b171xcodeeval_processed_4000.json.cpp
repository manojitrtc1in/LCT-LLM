




























using namespace std;
































































































































template<typename T> T POW(T base,T power)              { T ret=1; while(power)  { if(power & 1) ret=(ret*base); base=(base*base);  power>>=1; }return ret; }
template<typename T> inline T GCD(T a,T b)              { if(a<0)return GCD(-a,b);  if(b<0)return GCD(a,-b);    return (b==0)?a:GCD(b,a%b);}
template<typename T> T LCM(T a,T b)                     { if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/GCD(a,b));}
template<typename T> T id1(T a,T b,T &x,T &y)       { if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a){    if(a<0)return -a;    else return a;}




template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}




































































LL ar[MX];
LL br[MX];

LL xx[MX];
LL yy[MX];

LL dp[MX];

vector<LL>aa;
vector<LL>bb;


pair<int,LL> id0(vector<LL>&vec,LL v)
{
    pair<int,LL>ret(0,0);
    int low = 0;
    int high = vec.size()-1;
    while(low<=high){
        int mid =(low+high)>>1;
        if(vec[mid]<=v) ret.X=1,ret.Y=vec[mid] , low = mid+1;
        else high=mid-1;
    }
    return ret;
}

pair<int,LL>id2(vector<LL>&vec,LL v){
    pair<int,LL>ret(0,0);
    int low=0;
    int high=vec.size()-1;
    while(low<=high){
        int mid =(low+high)>>1;
        if(vec[mid]>=v) ret.X=1,ret.Y=vec[mid],high=mid-1;
        else low=mid+1;
    }
    return ret;
}


int main()
{
    DIII(n,m,q);

    LL tot = 0;
    LL mmm = 1;

    rep(i,1,n)
    {
         IL(ar[i]);
         tot+=mmm*ar[i];
         mmm*=-1;
    }

    LL a=-1;
    LL b=1;

    rep(i,1,m)
    {
        IL(br[i]);
        xx[i] = a*br[i]+xx[i-1];
        yy[i] = b*br[i]+yy[i-1];
        a*=-1;
        b*=-1;
    }

    int jj = m-n;

    rep(i,0,jj)
    {
        int pos = i+1;

        if(pos&1) dp[pos] = xx[pos+n-1]-xx[pos-1];
        else      dp[pos] = yy[pos+n-1]-yy[pos-1];


        if(dp[pos]<0)  aa.PB(-dp[pos]);
        else           bb.PB(dp[pos]);



    }

    int cnt = jj+1;

    sort( all(aa) );
    sort( all(bb) );




    rep(i,1,q+1)
    {
        LL x,y,v;
        v=0;
        x=0;
        y=0;

        if(i>1)
        {
             IIIL(x,y,v);
             if((y-x+1)%2==1)  {
                if(x&1) tot+=v;
                else    tot+=-v;
            }
        }






        LL ret=(1ULL<<63)-1;
        ret  =  1e18;










        











        if(tot>=0)
        {
            pair<int,LL> r   = id0(aa,tot);
            pair<int,LL> rr  = id2(aa,tot);

            if(r.X)  ret = min( ret, ABS(tot-r.Y) );
            if(rr.X) ret = min( ret, ABS(tot-rr.Y) );

            if(bb.size())ret = min(ret, ABS(tot+bb[0]) );
        }

        if(tot<=0)
        {
            pair<int,LL> r   = id0(bb,-tot);
            pair<int,LL> rr  = id2(bb,-tot);

            if(r.X)  ret = min( ret, ABS(tot+r.Y)  );
            if(rr.X) ret = min( ret, ABS(tot+rr.Y) );
            if(aa.size())ret = min(ret, ABS(tot-aa[ aa.size()-1 ] ) );
            if(aa.size())ret = min(ret, ABS(tot-aa[0])  );
        }




        PIL(ret);
    }



    return 0;
}
