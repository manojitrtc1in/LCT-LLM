





















































































































using namespace std;


typedef long long ll;
typedef long double lb;









const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;





































































ll n, m, k, l, r, cnt, sum, flag, mid, ans;
ll arr[N], brr[N], vis[N], vis1[N];
string s;

void cf() {
    cin >> n >> m;




    ans = n - m;
    rep(i, 1, 2 * m - 1 - n) cout << i << " ";
    cout << m << " ";
    rep(i,1,ans) cout<<m - i <<" ";
    cout<<endl;
}


int main() {
    IOS




    int T = 1;
    cin >> T;
    while (T--) {
        cf();
    }
    return 0;
}
			  	  						  	 			  				  	