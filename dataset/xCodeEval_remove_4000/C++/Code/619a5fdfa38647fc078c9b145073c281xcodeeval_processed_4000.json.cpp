











































typedef unsigned long long ull;
using namespace std;
int arr[555][555];
signed main(){
    int n,k;
    cin>>n>>k;
    int kk=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<k; ++j)
            arr[i][j]=++kk;
    for (int i=1; i<=n; ++i)
        for (int j=k; j<=n; ++j)
            arr[i][j]=++kk;
    int sum=0;
    for (int i=1; i<=n; ++i) sum+=arr[i][k];
    cout<<sum<<en;
    for (int i=1; i<=n; ++i){
        for (int j=1; j<=n; ++j)
            cout<<arr[i][j]<<" ";
        cout<<en;
    }
    return 0;
}
