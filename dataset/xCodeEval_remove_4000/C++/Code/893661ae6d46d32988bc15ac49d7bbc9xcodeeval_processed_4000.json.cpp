













































typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int gcd(int a,int b){
    

    while (a && b){
        if (a>b) a=a%b;
        else b=b%a;
    }
    

    

    return a+b;
}
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int x;
    int gcdd=k;
    for (int i=0; i<n; ++i){
        cin>>x;
        x%=k;
        gcdd=gcd(gcdd,x);
       

    }
    cout<<k/gcdd<<en;
    for (int i=0; i*gcdd<k; ++i){
        cout<<i*gcdd<<" ";
    }
    return 0;
}
