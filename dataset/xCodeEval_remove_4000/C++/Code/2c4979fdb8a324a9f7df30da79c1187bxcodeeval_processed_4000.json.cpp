









using namespace std;



void solve(){
    ll a, b, c, x, y;
    bool f=0;
    cin>>a>>b>>c>>x>>y;
    if(x>a)c-=(x-a);
    if(y>b)c-=(y-b);
    if(c<0)cout<<"NO\n";
    else    cout<<"YES\n";
}




int main(){
    fast;
    int t=1;
    cin>>t;
    while(t--)solve();

     }


