


using namespace std;


















void solve() {
    ll n ; cin>>n;
    ll a[n],b[n];
    ll mx = INT_MIN;
    rep(i,0,n){
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    b[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i)
    {
        b[i] = max(a[i],b[i+1]);
    }
    bool  ok = false;
    set<ll> st;
    rep(i,0,n){
        if(ok == true and b[i]!=mx){
            st.insert(b[i]);
        }
        if(b[i] == mx)
            ok = true;
    }
    cout<<st.size()<<ml;
}
signed main() {
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 
    
    int t; cin>>t; 
    while(t--)
        solve();
    return 0;
}

