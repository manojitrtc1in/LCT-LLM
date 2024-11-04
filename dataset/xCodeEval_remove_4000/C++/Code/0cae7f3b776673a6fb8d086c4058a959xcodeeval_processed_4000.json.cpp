













using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;





















































































































    unsigned char mask[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
    
    
    
    

    

    void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, sum = 0;
        for (i = 0; i <= K; i++)
            bkt[i] = 0; 

        for (i = 0; i < n; i++)
            bkt[chr(i)]++; 

        for (i = 0; i <= K; i++) {
            sum += bkt[i];
            bkt[i] = end ? sum : sum - bkt[i];
        }
    }
    

    void id2(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end); 

        for (i = 0; i < n; i++) {
            j = SA[i] - 1;
            if (j >= 0 && !tget(j))
                SA[bkt[chr(j)]++] = j;
        }
    }
    

    void id1(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
        int i, j;
        getBuckets(s, bkt, n, K, cs, end); 

        for (i = n - 1; i >= 0; i--) {
            j = SA[i] - 1;
            if (j >= 0 && tget(j))
                SA[--bkt[chr(j)]] = j;
        }
    }

    

    

    

    void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
        int i, j;
        unsigned char *t = (unsigned char *) malloc(n / 8 + 1); 

        

        tset(n-2, 0);
        tset(n-1, 1); 

        for (i = n - 3; i >= 0; i--)
            tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
        

        

        int *bkt = (int *) malloc(sizeof(int) * (K + 1)); 

        getBuckets(s, bkt, n, K, cs, true); 

        for (i = 0; i < n; i++)
            SA[i] = -1;
        for (i = 1; i < n; i++)
            if (isLMS(i))
                SA[--bkt[chr(i)]] = i;
        id2(t, SA, s, bkt, n, K, cs, false);
        id1(t, SA, s, bkt, n, K, cs, true);
        free(bkt);
        

        

        int n1 = 0;
        for (i = 0; i < n; i++)
            if (isLMS(SA[i]))
                SA[n1++] = SA[i];
        

        for (i = n1; i < n; i++)
            SA[i] = -1; 

        int name = 0, prev = -1;
        for (i = 0; i < n1; i++) {
            int pos = SA[i];
            bool diff = false;
            for (int d = 0; d < n; d++)
                if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                    diff = true;
                    break;
                } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                    break;
            if (diff) {
                name++;
                prev = pos;
            }
            pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
            SA[n1 + pos] = name - 1;
        }
        for (i = n - 1, j = n - 1; i >= n1; i--)
            if (SA[i] >= 0)
                SA[j--] = SA[i];
        

        

        int *SA1 = SA, *s1 = SA + n - n1;
        if (name < n1)
            SA_IS((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
        else
            

            for (i = 0; i < n1; i++)
                SA1[s1[i]] = i;
        

        bkt = (int *) malloc(sizeof(int) * (K + 1)); 

        

        getBuckets(s, bkt, n, K, cs, true); 

        for (i = 1, j = 0; i < n; i++)
            if (isLMS(i))
                s1[j++] = i; 

        for (i = 0; i < n1; i++)
            SA1[i] = s1[SA1[i]]; 

        for (i = n1; i < n; i++)
            SA[i] = -1; 

        for (i = n1 - 1; i >= 0; i--) {
            j = SA[i];
            SA[i] = -1;
            SA[--bkt[chr(j)]] = j;
        }
        id2(t, SA, s, bkt, n, K, cs, false);
        id1(t, SA, s, bkt, n, K, cs, true);
        free(bkt);
        free(t);
    }

    int sa[MAXN];
    int lcp[MAXN];
    int rankk[MAXN];
    unsigned char *s;
    int n;

    void id0(){
        int i, j, k;
        for(j = rankk[lcp[i = k = 0] = 0]; i < n - 1; i++, k++)
            while(k >= 0 && s[i] != s[sa[j - 1] + k])
                lcp[j] = (k--), j = rankk[sa[j] + 1];
    }

    void build(string str)
    {
        n = str.size();
        s = (unsigned char*) str.c_str();
        SA_IS(s, sa, n + 1, 256, 1);
        for (int i = 0; i < n; ++i){
            sa[i] = sa[i + 1];
            rankk[sa[i]] = i;
        }
        id0();
    }





int rmq[MAXN][21];
int lg[MAXN];

char sssxxx[MAXN];
int ps[MAXN];
pii pieces[MAXN];
ll res[MAXN];
int dp[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);




    int n;
    scanf("%d",&n);
    string s="";
    for(int i=0;i<n;i++)
    {
        scanf("%s",sssxxx);
        int pos=0;
        ps[i]=s.size();
        while(sssxxx[pos]!='\0')
        {
            s.push_back(sssxxx[pos]);
            pos++;
        }
        s.push_back('0');
    }
    ps[n]=s.size();

    int* isa=rankk;
    build(s);
    lg[0]=-1;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        rmq[i][0]=lcp[i];
        lg[i+1]=lg[i]+!((i+1)&(i));
    }
    for(int j=1;j<=lg[len];j++)
        for(int i=0;i+(1<<j)<=len;i++)
            rmq[i][j]=(rmq[i][j-1]<rmq[i+(1<<(j-1))][j-1]) ? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1];

    auto cmp=[&](pii a,pii b)
    {
        int w1=a.f;
        int p1=a.s;
        int w2=b.f;
        int p2=b.s;

        int l1=min(p1,p2);
        int x1=ps[w1];
        int x2=ps[w2];




        int l=isa[x1];
        int r=isa[x2];
        if(l>r)
        {
            l^=r;
            r^=l;
            l^=r;
        }
        int x;
        if(l!=r)
        {
            int po=lg[r-l];
            x=min(rmq[l+1][po],rmq[r-(1<<po)+1][po]);
            if(x<l1)
                return isa[x1]<isa[x2];
        }


        bool ok=0;
        if(p1>p2)
        {
            x1^=x2;
            x2^=x1;
            x1^=x2;

            p1^=p2;
            p2^=p1;
            p1^=p2;

            w1^=w2;
            w2^=w1;
            w1^=w2;

            ok=1;
        }
        int c1=ps[w1+1]-ps[w1]-1;
        int c2=ps[w2+1]-ps[w2]-1;
        int l2=min(c1-p1-(p1!=c1),p2-p1);




        l=isa[x1+p1+1];
        r=isa[x2+p1];
        if(l>r)
        {
            l^=r;
            r^=l;
            l^=r;
        }
        if(l!=r)
        {
            int po=lg[r-l];
            x=min(rmq[l+1][po],rmq[r-(1<<po)+1][po]);
            if(x<l2)
                return (bool)((isa[x1+p1+1]<isa[x2+p1])^ok);
        }


        int l3=min(c1-p1-(p1!=c1)-l2,c2-p2-(p2!=c2));




        l=isa[x1+p1+l2+1];
        r=isa[x2+p2+1];
        if(l>r)
        {
            l^=r;
            r^=l;
            l^=r;
        }
        if(l!=r)
        {
            int po=lg[r-l];
            x=min(rmq[l+1][po],rmq[r-(1<<po)+1][po]);
            if(x<l3)
                return (bool)((isa[x1+p1+1+l2]<isa[x2+p2+1])^ok);
        }
        if((c1-(c1!=p1))!=(c2-(c2!=p2)))
            return (bool)((((c1-(c1!=p1)))<((c2-(c2!=p2))))^ok);
        return (bool)(a<b);
    };

    int pp=0;












































    for(int i=0;i<ps[1];i++)
        dp[0][i]=1;
    for(int i=1;i<n;i++)
    {
        int ne=i&1;
        int act=1-ne;


        pp=0;
        for(int j=ps[i-1];j<ps[i];j++)
        {
            pieces[pp]=pii(i-1,j-ps[i-1]);
            pp++;
        }
        for(int j=ps[i];j<ps[i+1];j++)
        {
            pieces[pp]=pii(i,j-ps[i]);
            pp++;
        }
        sort(pieces,pieces+pp,cmp);

        int ac=0;
        for(int j=0;j<pp;j++)
        {
            pii y=pieces[j];
            int t=y.f;
            int p=y.s;
            if(t==i)
                dp[ne][p]=ac;
            else
            {
                ac+=dp[act][p];
                if(ac>=mod)
                    ac-=mod;
            }
        }
    }

    ll res=0;
    for(int i=ps[n-1];i<ps[n];i++)
        res=(res+dp[(n-1)&1][i-ps[n-1]])%mod;
    db(res)

    return 0;
}

