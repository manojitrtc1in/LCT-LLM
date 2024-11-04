





 
using namespace std;
using namespace __gnu_pbds;
 








typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
typedef vector<str> vestr;
typedef vector<int> vei;
typedef vector<vector<int>> veve;


void solve() {
    int n, k;
    cin>>n>>k;
    cout<<"? "<<1<<endl;
    int t;
    cin>>t;
    int cur = 0;
    int len = 0;
    for(int i = 0; i < 1000; ++i) {
        cur+=i;
        cur%=n;
        cout<<"? "<<cur + 1<<endl;
        cin>>t;
        len = i;
        if(t>k) break;
    }
    while(1) {
        cout<<"? "<<cur+1<<endl;
        cin>>t;
        if(t<k) {
            cout<<"! "<<(cur+1)%n+1;
            return;
        }
        cur = (cur - 1 + n) % n;
    }
}

signed main() {
    

    





    int tc = 1;
    

    for (int t = 1; t <= tc; t++) {
        

        solve();
    }
}