

using namespace std;
typedef long long ll;









const int  inf = 0x3f3f3f3f;
int intcmp(const void *v1,const void *v2)
{
    return *(int *)v1-*(int *)v2;
}

inline int read()
{
    int x=0,f=1;
    char cc=getchar();
    while(cc<'0' || cc>'9')
    {
        if(cc=='-') f=-1;
        cc=getchar();
    }
    while(cc>='0' && cc<='9')
    {
        x=x*10+cc-'0';
        cc=getchar();
    }
    return x*f;
}
const int maxn = 200005;
int n,T;
vector<pair<int,int> >vec[maxn];
priority_queue<pair<int,int> >q;
 
int main()
{
    scanf("%d%d",&n,&T);
    for(int i=1; i<=n; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        vec[x].push_back(make_pair(y,i));
    }
    ll sum=0;
    for(int i=n; i>=0; i--)
    {
        for(auto u:vec[i])
        {
            q.push(u);
            sum+=u.first;
        }
        while(q.size()>i)
        {
            sum-=q.top().first;
            q.pop();
        }
        if(q.size()==i&&sum<=T)
        {
            printf("%d\n%d\n",i,i);
            while(q.size())
            {
                printf("%d ",q.top().second);
                q.pop();
            }
            puts("");
            return 0;
        }
    }
}