











































































































































































































































































































































































































































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

















































































































































































































































