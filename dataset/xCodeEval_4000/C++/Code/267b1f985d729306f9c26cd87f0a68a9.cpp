

































































































































































































































































































































































































#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

using namespace std;


























vector<int> graph[1000005];

bool vis[1000005];
int dis[100005];

vector<int> ans1, ans2, final1, final2;



bool bfs(int src)
{
    ms(dis,0);
    vis[src]=1;
    dis[src]=1;
    queue<int>Q;
    Q.push(src);
    bool test=1;

    while(!Q.empty())
    {



        int u=Q.front();
        Q.pop();
        if(dis[u]==1)
        {
            ans1.pb(u);
        }
        else if(dis[u]==2)
        {
            ans2.pb(u);
        }


        for(int i=0; i<SZ(graph[u]); i++)
        {
            int v=graph[u][i];


            if(dis[v]==dis[u])
            {
                test=0;


            }
            if(vis[v]==0)
            {
                vis[v]=1;
                dis[v]=3-dis[u];
                Q.push(v);
            }
        }
    }
    return test;
}

int main()
{

    

    

    int n,m;
    sff(n,m);
    loop(i,m)
    {
        int a,b;
        sff(a,b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bool fuck=0;

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            ans1.clear();
            ans2.clear();
            if(bfs(i))
            {
                loop(j,SZ(ans1)) final1.pb(ans1[j]);
                loop(j,SZ(ans2)) final2.pb(ans2[j]);
                fuck=1;
            }
            else
            {fuck=0;
                break;
            }
        }
    }

    if(fuck)
    {
        cout<<SZ(final1)<<endl;

        cout<<final1[0];
        for(int i=1;i<SZ(final1);i++)
            cout<<" "<<final1[i];
        cout<<endl;

        cout<<SZ(final2)<<endl;

        cout<<final2[0];
        for(int i=1;i<SZ(final2);i++)
            cout<<" "<<final2[i];
        cout<<endl;
    }
    else
        printf("-1\n");
    return 0;
}

















































































































































































































































