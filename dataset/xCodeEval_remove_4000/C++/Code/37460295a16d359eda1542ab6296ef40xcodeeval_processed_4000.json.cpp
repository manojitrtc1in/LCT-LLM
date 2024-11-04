




















using namespace std; 
typedef long double ld;
typedef pair<long long,long long> p32;
typedef pair<long long,long long> p64;
typedef pair<double,double> pdd;
typedef vector<long long> v64;
typedef vector<long long> v32;
typedef vector<vector<long long> > vv32;
typedef vector<vector<long long> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
long long MOD = 1e9+7;
double eps = 1e9+7;
















long long t;
const long long N = 200010;
const long long M = 998244353;




















































char arr[100][100];

void solve() {
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){cin>>arr[i][j];}
    }
    for(int i=0;i<8;i++){   
        int r=0; 
    for(int j=0;j<8;j++){
        
        if(arr[i][j]=='R')r++;
        if(r==8){cout<<"R"<<en;return;}
    }
}
    cout<<"B"<<en;
        
}

 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    

    cin>>t;
    for(long long i=0;i<t;i++){
         solve();
    }
    return 0;
}




