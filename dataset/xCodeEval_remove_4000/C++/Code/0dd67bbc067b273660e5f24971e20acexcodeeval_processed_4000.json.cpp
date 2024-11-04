
















































































































using namespace std;

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T id2(T a,T b,T &x,T &y) {if(a<0){T d=id2(-a,b,x,y);x=-x;return d;}   if(b<0){T d=id2(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=id2(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }

int    Set(int N,int pos){ return N=N | (1<<pos);}
int  Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
































const int N = (int)6e5 + 7;

char s[MX];
string ss[MX];

int SA[MX],      

    tmpSA[MX],   

    Grp[MX],     

    tmpGrp[MX],  

    GrpSt[MX],   

    Counting[MX],

    Rank[MX],    

    LCP[MX];     



void id0(int L){
    int k = 0;

    for (int i=0;i<L;i++){
        if (k)  k--;

        int j = SA[Rank[i]-1];
        while (i+k < L && j+k < L && s[i+k] == s[j+k])  k++;
        LCP[ Rank[i] ] = k;
    }
}

int SuffixArray(int mxAlpha){
    int L = 0;

    for (int i=0;i<mxAlpha;i++)     Counting[i] = 0;
    for (L=0;s[L];L++)              Counting[ s[L] ]++;
    for (int i=1;i<mxAlpha;i++)     Counting[i] += Counting[i-1];
    for (int i=L-1;i>=0;i--)        SA[ Counting[ s[i] ]-- ] = i,Rank[i] = Counting[ s[i] ]+1;

    int gNo = 0; GrpSt[0] = 0;
    tmpSA[0] = SA[0] = L;
    Grp[L] = 0; tmpGrp[L] = 0;

    for (int i=1;i<=L;i++){
        if (s[ SA[i] ] != s[ SA[i-1] ])     gNo++, GrpSt[ gNo ] = i;
        Grp[ SA[i] ] = gNo;
    }
    
    int x=0;
    for (int d=1;d<L;d<<=1){
        x++;
        for (int i=L-d;i<L;i++)     tmpSA[ GrpSt[ Grp[i] ]++ ] = i;
        for (int i=1;i<=L;i++)
            if (SA[i] >= d)         tmpSA[ GrpSt[ Grp[ SA[i]-d ] ]++ ] = SA[i]-d;

        gNo = 0; GrpSt[0] = 0;

        for (int i=1;i<=L;i++){
            if ( Grp[ tmpSA[i] ] != Grp[ tmpSA[i-1] ] )             gNo++, GrpSt[gNo] = i;
            else if (tmpSA[i]+d >= L)                               gNo++, GrpSt[gNo] = i;
            else if (tmpSA[i-1]+d >= L)                             gNo++, GrpSt[gNo] = i;
            else if ( Grp[ tmpSA[i]+d ] != Grp[ tmpSA[i-1]+d ] )    gNo++, GrpSt[gNo] = i;

            SA[i] = tmpSA[i];
            Rank[ SA[i] ] = i;
            tmpGrp[ SA[i] ] = gNo;
        }

        if (gNo == L)     break;

        for (int i=0;i<L;i++)   Grp[i] = tmpGrp[i];
    }

    id0(L);
    return L;
}

int sqz;

struct Query{
    int l,r,id;
    int ll,rr;

    Query(){}

    Query(int _l,int _r,int _id,int _ll,int _rr){
        l = _l;
        r = _r;
        id= _id;
        ll= _ll;
        rr= _rr;
    }

    bool operator< (const Query& p)const{
        if (l/sqz < p.l/sqz)    return true;
        else if (l/sqz == p.l/sqz)
            return r<p.r;
    }
};

Query q[N];
PII ans[N];
int id[N];
PII Tree[4*N];
int cntt;

void Build(int idx,int l,int r){
    if (l == r){
        Tree[idx] = MP(LCP[l],l);
        return;
    }

    Build(lft,l,mid);
    Build(rgt,mid+1,r);

    Tree[idx] = min(Tree[lft],Tree[rgt]);
}

void Clear(int idx,int l,int r){
    if (l == r){
        Tree[idx] = MP(0,-l);
        return ;
    }

    Clear(lft,l,mid);
    Clear(rgt,mid+1,r);

    Tree[idx] = max(Tree[lft],Tree[rgt]);
}

void Update(int idx,int l,int r,int p,int v){
    if (l == r) {Tree[idx].X += v;return;}

    if (p <= mid)   Update(lft,l,mid,p,v);
    else            Update(rgt,mid+1,r,p,v);

    Tree[idx] = max( Tree[lft],Tree[rgt] );
}

bool flg;

int FindLeft(int idx,int l,int r,int s,int e,int v){
    if (s > e)                  return 0;
    if (l == s && r == e){
        if(Tree[idx].X >= v)    return 0;
        if(l == r)              {while(flg);return l;}
        if(Tree[rgt].X < v)     return FindLeft(rgt,mid+1,r,mid+1,e,v);
        if(Tree[lft].X < v)     return FindLeft(lft,l,mid,s,mid,v);
        return 0;
    }

    if (e <= mid)               return FindLeft(lft,l,mid,s,e,v);
    else if (s > mid)           return FindLeft(rgt,mid+1,r,s,e,v);
    else{
        int q = FindLeft(rgt,mid+1,r,mid+1,e,v);

        if (q == 0)    q = FindLeft(lft,l,mid,s,mid,v);

        return q;
    }
}

int FindRight(int idx,int l,int r,int s,int e,int v){
    if (s > e)                  return MOD;
    if (l == s && r == e){
        if (Tree[idx].X >= v)   return MOD;
        if (l == r)             return l;
        if (Tree[lft].X < v)    return FindRight(lft,l,mid,s,mid,v);
        if (Tree[rgt].X < v)    return FindRight(rgt,mid+1,r,mid+1,e,v);
        return MOD;
    }

    if (e <= mid)               return FindRight(lft,l,mid,s,e,v);
    else if (s > mid)           return FindRight(rgt,mid+1,r,s,e,v);
    else{
        int q = FindRight(lft,l,mid,s,mid,v);

        if (q == MOD)    q = FindRight(rgt,mid+1,r,mid+1,e,v);

        return q;
    }
}

PII QueryMX(int idx,int l,int r,int s,int e){
    if (l == s && r == e)   return Tree[idx];

    if (e <= mid)           return QueryMX(lft,l,mid,s,e);
    else if (s > mid)       return QueryMX(rgt,mid+1,r,s,e);
    else{
        PII q1 = QueryMX(lft,l,mid,s,mid);
        PII q2 = QueryMX(rgt,mid+1,r,mid+1,e);

        return max(q1,q2);
    }
}

Query tq[N];
int countt[N];

void id1(int n,int m){
    for (int i=0;i<=m;i++)  countt[i] = 0;
    for (int i=1;i<=n;i++)  countt[ q[i].r ]++;
    for (int i=1;i<=m;i++)  countt[i] += countt[i-1];
    for (int i=n;i>=1;i--)  tq[ countt[ q[i].r ]-- ] = q[i];
    
    for (int i=0;i<=m;i++)  countt[i] = 0;
    for (int i=1;i<=n;i++)  countt[ tq[i].l/sqz ]++;
    for (int i=1;i<=m;i++)  countt[i] += countt[i-1];
    for (int i=n;i>=1;i--)  q[ countt[ tq[i].l/sqz ]-- ] = tq[i];
}

int main(){
    S("%s",s);
    ss[0] = s;

    DI(n);

    for (int i=1;i<=n;i++){
        S("%s",s);
        ss[i] = s;
    }

    int l = 0;

    for (int i=0;i<=n;i++){
        for (int j=0;j<(int)ss[i].length();j++,l++){
            s[l] = ss[i][j];
            id[l] = i;
        }

        s[l] = '
        l++;
    }

    s[l] = 0;

    SuffixArray(300);
    Build(1,1,l);

    

        


        

            

        

    


    DI(m);
    sqz = sqrt(l)+3;
    
    

        


    for (int i=1;i<=m;i++){
        DII(l2,r2);
        DII(l1,r1);

        int len =r1-l1+1;
        l1--;
        
        cntt = 0;
        int x = FindLeft(1,1,l,1,Rank[l1],len);         x = max(x,1);
        int y = FindRight(1,1,l,Rank[l1]+1,l,len)-1;    y = min(l,y);

        q[i] = Query(x,y,i,l2,r2);

        

    }

    id1(m,l+3);
    


    


    Clear(1,1,l);



    int ii = 1,jj = 0;

    for (int i=1;i<=m;i++){
        while(jj < q[i].r){
            jj++;
            if (id[SA[jj]]) Update(1,1,l,id[SA[jj]],1);
        }

        while(jj > q[i].r){
            if (id[SA[jj]]) Update(1,1,l,id[SA[jj]],-1);
            jj--;
        }

        while(ii < q[i].l){
            if (id[SA[ii]]) Update(1,1,l,id[SA[ii]],-1);
            ii++;
        }

        while(ii > q[i].l){
            ii--;
            if (id[SA[ii]]) Update(1,1,l,id[SA[ii]],1);
        }

        ans[q[i].id] = QueryMX(1,1,l,q[i].ll,q[i].rr);
    }

    for (int i=1;i<=m;i++)  P("%d %d\n",-ans[i].Y,ans[i].X);
return 0;
}
