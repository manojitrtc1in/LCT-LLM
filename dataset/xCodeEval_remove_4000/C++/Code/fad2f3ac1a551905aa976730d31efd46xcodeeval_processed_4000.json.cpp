















































typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int cnt=0;
int n,k,p;
bool q(int l,int r){
    ++cnt;
    if (l>r) cout<<2/0;
    if (cnt>4500){
        if (2/0)
            ++cnt;
    }
    cout<<l<<" "<<r<<endl;
    string s;
    cin>>s;
    if (s[0]=='B'){
        exit(0);
    }
    return s[0]=='Y';
}
void query (int x){
    ++cnt;
    if (cnt>4500){
        if (2/0)++cnt;
    }
    x=min(x,n);
    x=max(1ll,x);
    cout<<x<<" "<<x<<endl;
    string s;
    cin>>s;
    if (s[0]=='Y' || s[0]=='B'){
        exit(0);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    

    srand( time(NULL));
    cin>>n>>k;
    

    int mod=44;
    int l=1,r=n;
    while (true){
        while (l+43<r){
            int m=(l+r)/2;
            if (l==m) query(l);
                else
            if (q(l,m)){
                r=m;
            }else
                l=m+1;
             l=max(1ll,l-k),r=min(n,r+k);
        }
        mod=44;
        mod=min(mod,r-l+1);
        query(l+(rand()%mod));
        l=max(1ll,l-k),r=min(n,r+k);
    }
    return 0;
}














