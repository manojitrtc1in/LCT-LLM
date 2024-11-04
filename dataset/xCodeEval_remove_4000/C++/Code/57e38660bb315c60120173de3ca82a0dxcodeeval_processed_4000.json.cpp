








using namespace std;
typedef long long int ll;



ll GCD(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}
ll LCM(ll a, ll b) {
    return a * b / GCD(a, b);
}




int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int m[100],ans[100];
        for(int j=0;j<n;j++){
            cin>>m[j];
        }
        for(int j=0;j<n/2;j++){
            if(m[j]>0){
                ans[j]=abs(m[n-j-1]);
            }
            else{
                ans[j] = -abs(m[n - j - 1]);
            }
            if(m[n-j-1] > 0){
                ans[n-j-1]= -abs(m[j]);
            }
            else{
                ans[n - j - 1] = abs(m[j]);
            }
        }
        for(int j=0;j<n;j++){
            cout<<ans[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
