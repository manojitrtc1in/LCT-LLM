













































































































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
template <typename T> T id5(T a,T b,T &x,T &y) {if(a<0){T d=id5(-a,b,x,y);x=-x;return d;}   if(b<0){T d=id5(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=id5(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }

int    Set(int N,int pos){ return N=N | (1<<pos);}
int  Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int id1(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}
int id4(char ch){return ch-'0';}
bool id2(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !id2(ch)) return true; return false;}

double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}





















struct Node{
    int x,y;
    int l,r,lz;

    Node(){
        x = y = l = r = lz = 0;
    }

    Node(int _,int __){
        x = l = r = lz = 0;
        y = (__ - _ + 1);
    }
};

const int N = int(1e5)+10;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n,m,p,q,id[N],len,a[N];
char str[N],s[N],ss[N];
int DP[20][N],lcp[N];
Node Tree[23*N];
int avail,Head[N];

int Propagate(int idx,int v,int l,int r){
    if (!idx){
        idx = ++avail;
        Tree[idx] = Node(l,r);
    }

    Tree[idx].x += v;
    Tree[idx].lz += v;

    return idx;
}

int Update(int idx,int l,int r,int st,int ed){
    if (!idx){
        idx = ++avail;
        Tree[idx] = Node(l,r);
    }

    if (l == st && r == ed){
        idx = Propagate(idx,1,l,r);
        return idx;
    }

    int mid = (l+r)>>1;

    if (Tree[idx].lz){
        Tree[idx].l = Propagate(Tree[idx].l,Tree[idx].lz,l,mid);
        Tree[idx].r = Propagate(Tree[idx].r,Tree[idx].lz,mid+1,r);

        Tree[idx].lz = 0;
    }

    if (ed <= mid)      Tree[idx].l = Update( Tree[idx].l,l,mid,st,ed );
    else if (st > mid)  Tree[idx].r = Update( Tree[idx].r,mid+1,r,st,ed );
    else{
        Tree[idx].l = Update( Tree[idx].l,l,mid,st,mid );
        Tree[idx].r = Update( Tree[idx].r,mid+1,r,mid+1,ed );
    }

    if (Tree[ Tree[idx].l ].x == Tree[ Tree[idx].r ].x){
        Tree[idx].x = Tree[ Tree[idx].l ].x;
        Tree[idx].y = Tree[ Tree[idx].l ].y + Tree[ Tree[idx].r ].y;
    }

    else if (Tree[ Tree[idx].l ].x > Tree[ Tree[idx].r ].x){
        Tree[idx].x = Tree[ Tree[idx].l ].x;
        Tree[idx].y = Tree[ Tree[idx].l ].y;
    }

    else{
        Tree[idx].x = Tree[ Tree[idx].r ].x;
        Tree[idx].y = Tree[ Tree[idx].r ].y;
    }

    return idx;
}

void Sparse(){
    for (int i=1;i<=n;i++)      DP[0][i] = height[i];

    for (int i=1;(1<<i)<=n;i++){
        for (int j=1;j+(1<<i)-1 <= n;j++){
            DP[i][j] = min( DP[i-1][j],DP[i-1][j+(1<<(i-1))] );
        }
    }
}

int Query(int st,int ed){
    if (ed < st)        return 0;
    int b = 31 - __builtin_clz(ed-st+1);
    return min( DP[b][st],DP[b][ ed-(1<<b)+1 ] );
}

int FindLeft(int ln,int x){
    int l = 1,h = x;

    while (l <= h){
        int mid = (l+h)>>1;

        if ( Query(mid,x) < ln )    l = mid+1;
        else                        h = mid-1;
    }

    return l-1;
}

int FindRight(int ln,int x){
    int l = x,h = n;

    while (l <= h){
        int mid = (l+h)>>1;

        if ( Query(x,mid) < ln )    h = mid-1;
        else                        l = mid+1;
    }

    return l-1;
}

int id3(int st){
    int l = 1,h = len - sa[st] - 1;

    while (l <= h){
        int mid = (l+h)>>1;

        int lpos = FindLeft( mid,st );
        int rpos = FindRight( mid,st+1 );

        int cnt = a[rpos] - a[lpos-1];

        if (cnt <= q)   h = mid-1;
        else            l = mid+1;
    }

    return l;
}

int id0(int st){
    int l = 1, h = len - sa[st] - 1;

    while (l <= h){
        int mid = (l+h)>>1;

        int lpos = FindLeft(mid,st);
        int rpos = FindRight(mid,st+1);

        int cnt = a[rpos] - a[lpos-1];

        if (cnt >= p)   l = mid+1;
        else            h = mid-1;
    }

    return l-1;
}

void Init(){
    while (s[len]){
        str[len] = s[len];
        data[len] = (int)str[len];
        len++;n++;
    }

    str[len] = '@';
    data[len] = (int)str[len];
    len++;n++;

    DA(data,sa,n+1,128);
    calheight(data,sa,n);

    for (int i=1;i<=n;i++){
        lcp[ sa[i] ] = height[i];
    }
}

int Deal ()
{
    n = len;
    for (int i=0;s[i];i++,n++){
        str[n] = s[i];
        data[n] = str[n];
    }

    data[n] = str[n] = 0;

    DA(data,sa,n+1,128);
    calheight(data,sa,n);
    Sparse();

    for (int i=1;i<=n;i++)      a[i] = (sa[i]>=len) + a[i-1];

    for (int i=1;i<=n;i++){
        if (sa[i] >= len-1)     continue;

        int st = id3( i );
        int ed = id0( i );

        if (ed < st )           continue;
        if (ed <= lcp[ sa[i] ]) continue;

        Head[sa[i]] = Update( Head[ sa[i] ],1,len,max( lcp[sa[i]]+1,st ),ed );
    }
}

int main(){
    S("%s",s);

    Init();
    S1(m);

    for (int i=1;i<=m;i++){
        S("%s%d%d",s,&p,&q);

        Deal();
    }

    LL ans = 0;

    if (m==0){
        for (int i=0;i<len-1;i++){
            ans += len-1 - i - lcp[i];
        }

        cout << ans << endl;
        return 0;
    }

    for (int i=0;i<len-1;i++){
        if (Tree[ Head[i] ].x == m)     ans += Tree[ Head[i] ].y;
    }

    cout << ans << endl;
return 0;
}