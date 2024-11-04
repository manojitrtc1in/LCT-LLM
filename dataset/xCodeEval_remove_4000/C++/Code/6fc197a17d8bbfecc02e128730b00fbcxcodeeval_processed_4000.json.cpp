


 

  

 

 

 

 



 

 

 

  






 








 
using namespace std;


 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> Graph;

template<typename T> using Matrix = vector<vector<T>>;


 
template<typename T> bool relax(T& r, const T& x) {
    if (r > x) {
        r = x;
        return true;    
    }
    return false;
}
 
template<typename T> bool heavy(T& h, const T& x) {
    if (h < x) {
        return true;            
    }
    return false;
}
 
                                                          

const int BOUND = (int) 2e5 + 1;    
const double PI = acos(-1);
const ll INF = (ll) 1e15 + 1;

ll a[BOUND], sq[BOUND], sum[BOUND];
signed main() {      

    freopen(FILE_NAME".in", "r", stdin);
    freopen(FILE_NAME".out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) 
                continue;
            ans[i] |= a[i][j];
        }
    }
    for (int& x : ans)
        cout << x << " ";
    return false;
}








 

