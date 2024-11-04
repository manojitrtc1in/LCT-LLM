


    



using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());








vector <int> p;
int get(int v)
{
    if (p[v]==v)return v;
    p[v]=get(p[v]);
    return p[v];
}
void update(int v, int u)
{
    v=get(v);
    u=get(u);
    p[v]=u;
}


void solve()
{
    int n;
    cin >> n;
    vector <pair <int,int> > a(n);
    for (int i=0; i<n; i++){
        cin >> a[i].f;
        a[i].s=i+1;
    }
    sort(a.rbegin(),a.rend());
    vector <int> pos(n,0);
    for (int i=0; i<n; i++){
        pos[a[i].s-1]=i;
    }
    p.assign(n,0);
    for (int i=0; i<n; i++){
        p[i]=i;
    }
    for (int i=0; i<n; i++){
        int j=get(i);
        if (i!=j)continue;
        for (int x=0; x<a[i].f; x++){
            cout << "? " << a[i].s << endl;
            int y;
            cin >> y;
            y=pos[y-1];
            y=get(y);
            if (y<i){
                update(i,y);
                break;
            }
            update(y,i);
        }
    }
    cout << "! ";
    for (int i=0; i<n; i++){
        cout << get(pos[i])+1 << " ";
    }
    cout << endl;
}


signed main()
{


    


    int n=1;
    cin >> n;
    while (n--){
        solve();
    }
}

