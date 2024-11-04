













































typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int q[100100],a[100100];
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>m;
    for (int i=0; i<m; ++i)
        cin>>q[i];
    sort(q, q+m);
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a, a+n);
    int now=0;
    int sum=0;
    bool flag=0;
    for (int i=n-1; i>=0; --i){
        if (now==q[0]){
            if (flag)
                now=0;
            else
                flag=1;
        }else{
            ++now;
            sum+=a[i];
            flag=0;
        }
    }
    cout<<sum<<en;
    return 0;
}
