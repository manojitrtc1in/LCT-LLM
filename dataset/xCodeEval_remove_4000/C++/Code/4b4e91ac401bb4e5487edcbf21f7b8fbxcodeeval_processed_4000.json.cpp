


 

  

 

 

 

 



 

 

 

  






 








 
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
const ll INF = (ll) 1e9 + 1;

signed main() {      

    freopen(FILE_NAME".in", "r", stdin);
    freopen(FILE_NAME".out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    l--; r--;
    vector<int> a(n), b(n);
    for (int& x : a)
        cin >> x;
    for (int& x : b)
        cin >> x;
    int ok = false;
    for (int i = 0; i < l; i++)
        if (a[i] != b[i])
            ok = true;
    for (int i = r + 1; i < n; i++)
        if (a[i] != b[i])
            ok = true;
    if (ok)
        cout << "LIE";
    else
        cout << "TRUTH";
    return false;
}








 

