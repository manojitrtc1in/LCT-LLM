

    



using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());







void solve()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    vector <int> pos(n);
    for (int i=0; i<n; i++){
        pos[a[i]]=i;
    }
    int l=n,r=-1;
    int ans=0;
    for (int i=0; i<n; i++){
        

        l=min(l,pos[i]);
        r=max(r,pos[i]);
        while (i+1<n && l<=pos[i+1] && pos[i+1]<=r){
            i++;
        }
        int cantl=-1;
        int cantr=n;
        if (i+1<n){
            if (pos[i+1]<l)cantl=pos[i+1];
            else cantr=pos[i+1];
        }
        int len=r-l+1;
        int canlen=2*(i+1);
        if (canlen<len)continue;
        cantr=min(cantr,l+canlen);
        cantl=max(cantl,r-canlen);
        int ans1=0;

        


        int can0=canlen-len+1;
        int cnt=l-cantl;
        ans1+=cnt*(can0+(can0-cnt+1))/2;

        int x=0;
        if (l+canlen-1<cantr){
            ans+=ans1;
            continue;
        }
        x=l+canlen-1-cantr+1;
        int cntbad=min(x,cnt);
        ans1-=cntbad*(x+(x-cntbad+1))/2;

        ans+=ans1;
    }
    cout << ans << endl;
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



