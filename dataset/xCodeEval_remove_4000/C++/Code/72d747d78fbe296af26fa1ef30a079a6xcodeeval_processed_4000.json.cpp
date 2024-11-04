

    



using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());







int n;
vector <vector <int> > g;

void solve()
{
    int m;
    cin >> n >> m;
    g.resize(0);
    g.resize(n);
    for (int i=0; i<m; i++){
        int v,u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int k;
    cin >> k;
    vector <int> a(k);
    for (int i=0; i<k; i++){
        cin >> a[i];
        a[i]--;
    }
    int c;
    cin >> c;
    vector <int> b(c);
    vector <int> bad(n,0);
    for (int i=0; i<c; i++){
        cin >> b[i];
        b[i]--;
        b[i]=a[b[i]];
    }
    int now=0;
    vector <vector <int> > num(n);
    for (int i:b){
        bad[i]++;
        num[i].push_back(now++);
    }
    vector <vector <int> > can((1<<c),vector <int> (n,0));
    queue <int> q;
    q.push(0);
    vector <bool> was(n,0);
    vector <int> d(n,1000000);
    d[0]=0;
    for (int i=0; i<n; i++){
        can[0][i]=1;
    }
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (int u:g[v]){
            if (d[u]<d[v]+1)continue;
            d[u]=d[v]+1;
            if (!was[u]){
                was[u]=1;
                q.push(u);
            }
            int x=0;
            for (int y:num[u]){
                x+=(1<<y);
            }
            

            

            for (int l=0; l<(1<<c); l++){
                if ((l|x)!=x)continue;
                for (int m=0; m<(1<<c); m++){
                    if (!can[m][v])continue;
                    can[m|l][u]=1;
                }
            }
        }
    }

    vector <int> cc((1<<c),0);
    for (int j=0; j<(1<<c); j++){
        int jj=j;
        int cnt=0;
        for (int l=0; l<c; l++){
            if (jj%2==1)cnt++;
            jj/=2;
        }
        cc[j]=cnt;
    }
    
    vector <int> id0(n,0);
    for (int i:a)id0[i]++;
    for (int i:b)id0[i]--;
    a.resize(0);
    for (int i=0; i<n; i++){
        for (int j=0; j<id0[i]; j++){
            a.push_back(i);
        }
    }
    k=a.size();

    

    if (a.size()==0){
        cout << c << endl;
        return;
    }
    if (b.size()==0){
        cout << 0 << endl;
        return;
    }

    vector <vector <int> > dp((1<<c),vector <int> (k,0));
    for (int i=0; i<k; i++){
        for (int l=0; l<(1<<c); l++){
            if (!can[l][a[i]]){
                continue;
            }
            for (int j=0; j<(1<<c); j++){
                if (i!=0)dp[j][i]=max(dp[j][i],dp[(j|l)^l][i-1]+cc[l&j]);
                else {
                    dp[j][i]=max(dp[j][i],cc[l&j]);
                }
            }
        }
        
    }

    

    cout << c-dp[(1<<c)-1][k-1] << endl;
}


signed main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n=1;
    cin >> n;
    while (n--){
        solve();
    }
}
