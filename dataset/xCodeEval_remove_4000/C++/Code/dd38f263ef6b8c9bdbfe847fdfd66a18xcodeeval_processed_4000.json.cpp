






























































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;










int n,x1,x2;
pii c[300007];
bool COBET(pii a,pii b){return a>b;}

int main()
{
    scanf("%d%d%d",&n,&x1,&x2);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i].first);
        c[i].second=i+1;
    }
    

    sort(c,c+n,COBET);
    

    

    

    int chsn=0;
    for(;chsn<n;chsn++)
    {
        if((x1+chsn)/(chsn+1)<=c[chsn].first)
            break;
    }
    if(chsn<n-1)
    {
        chsn++;
        for(int i=0;chsn<n;i++,chsn++)
            if((x2+i)/(i+1)<=c[chsn].first)
            {
                puts("Yes");
                printf("%d %d\n",chsn-i,i+1);
                for(int j=0;j<chsn-i;j++)
                    printf("%d ",c[j].second);
                puts("");
                for(int j=chsn-i;j<=chsn;j++)
                    printf("%d ",c[j].second);
                puts("");
                return 0;
            }
    }
    

    

    chsn=0;
    for(;chsn<n;chsn++)
    {
        if((x2+chsn)/(chsn+1)<=c[chsn].first)
            break;
    }
    if(chsn<n-1)
    {
        chsn++;
        for(int i=0;chsn<n;i++,chsn++)
            if((x1+i)/(i+1)<=c[chsn].first)
            {
                puts("Yes");
                printf("%d %d\n",i+1,chsn-i);
                for(int j=chsn-i;j<=chsn;j++)
                    printf("%d ",c[j].second);
                puts("");
                for(int j=0;j<chsn-i;j++)
                    printf("%d ",c[j].second);
                puts("");
                return 0;
            }
    }
    

    OVER("No");
}