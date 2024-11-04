








using namespace std;
typedef long long int ll;

typedef pair<double,double> pii;
vector<int>v;
double pi = 3.14159265358979323846264338327;
double EPS = 1e-7;

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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k,max=0,sc=0;
        vector<int>v;
        cin>>n>>k;
        v.resize(n);
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v[j]=a;
        }
        max=102000;
        for(int j=1;j<101;j++){
            int p1=j;
            sc=0;
            for (int j1 = 0; j1 < n; j1++) {
                if (v[j1] != p1) {
                    sc++;
                    j1 += (k - 1);
                }
            }
            if(sc<max){
                max=sc;
            }
        }
        
        cout<<max<<endl;
    }
    return 0;
}