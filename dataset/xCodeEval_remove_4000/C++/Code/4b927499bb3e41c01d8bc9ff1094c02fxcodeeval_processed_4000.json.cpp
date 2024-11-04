



 

using namespace std;


using namespace atcoder;

 
























 










template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T = int>
using VVV = std::vector<std::vector<std::vector<T>>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;


using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;


const int inf = 1e9;
const ll INF = 2e18;



void main_() {
	ll n;
	cin >> n;
	V<ll> p(n);
	REP(i,n) cin >> p[i];
	V<ll> l(n,1),r(n,1);
	REP(i,n-1){
	    if(p[i] < p[i+1]){
	        l[i+1] = l[i] + 1;
	    }
	}
	for(ll i = n-2;i>=0;i--){
	    if(p[i+1] < p[i]){
	        r[i] = r[i+1] + 1;
	    }
	}
	priority_queue<tuple<ll,ll,ll>> PQ;
	map<ll,ll> m;
	REP(i,n){
	    ll mx = max(r[i],l[i]);
	    ll mn = min(r[i],l[i]);
	    if(i != 0 && i != n-1){
	        

	    }
	    PQ.emplace(mx,mn,i);
	    
	}
	auto [x,y,z] = PQ.top();
	PQ.pop();
	if(x == y && x%2==1){
	    ll le = z - l[z] + 1;
	    ll ri = z + r[z] - 1;
	    ll s = 1;
	    ll t = 1;
	    for(ll i = le-1; i >= 0;i--){
	        if(p[i] > p[i+1]) s++;
	        else break;
	    }
	    for(ll i = ri + 1;i < n;i++){
	        if(p[i] > p[i-1]) t++;
	        else break;
	    }
	    if(s >= l[z] - 1 && s >= r[z]){
	        cout << 0 << endl;
	        return ;
	    }
	    if(t >= r[z] - 1 && t >= l[z]){
	        cout << 0 << endl;
	        return ;
	    }
	    if(!PQ.empty()){
	        auto [a,b,c] = PQ.top();
	        if(x > a){
	            cout << 1 << endl;
	        }
	        else{
	            cout << 0 << endl;
	        }
	    }
	    else{
	        cout << 1 << endl;
	    }
	}
	else{
	    cout << 0 << endl;
	}
}
 
int main() {
	int t = 1;
	

	while(t--) main_();
	return 0;
}