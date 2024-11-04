








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
        int n,m,r,c,max=0;
        cin>>n>>m>>r>>c;
        if(n-r+m-c>max){
            max= n - r + m - c;
        }
        if(r-1+m-c>max){
            max = r - 1 + m - c;
        }
        if(r-1+c-1>max){
            max = r - 1 + c - 1;
        }
        if(n-r+c-1>max){
            max= n - r + c - 1;
        }
        cout<<max<<endl;
    }
    return 0;
}