


using namespace std;
using namespace __gnu_pbds;






typedef vector<i64> vi;
typedef pair<i64,i64> pii;
typedef double ld;
typedef unsigned long long ull;
typedef tree<i64, null_type, less_equal<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
struct DSU {
    vector<int> f, siz,Max,Min;
    DSU(int n) : f(n), siz(n, 1),Max(n),Min(n) {
	    iota(f.begin(), f.end(), 0);
	    iota(Max.begin(),Max.end(),0);
	    iota(Min.begin(),Min.end(),0);
	}
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        Max[x]=max(Max[x],Max[y]);
        Min[x]=min(Min[x],Min[y]);
        return true;
    }
    int size(int x){
	   return siz[leader(x)];
	}
    int getMax(int x){
    	return Max[leader(x)];
	}
	int getMin(int x){
		return Min[leader(x)];
	}
};
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
    public:
    int n;
    vector<vector<T>> mat;
    F func;
    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
           mat[j].resize(n - (1 << j) + 1);
           for (int i = 0; i <= n - (1 << j); i++) {
               mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
           }
        }
    }
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
template <typename T>
class fenwick{
    public:
        vector<T>bit;
        int n;
        fenwick(int _n):n(_n){
            bit.resize(n);
        }
        void update(i64 u,i64 v) {
            i64 idx=u;
            while(idx<n) {
                bit[idx]+=v;
                idx+=(idx&(-idx));
            }
        }
        T get(i64 id){
            i64 idx=id,ans=0;
            while(idx>0){
                ans+=bit[idx];
                idx-=(idx&(-idx));
            }
            return ans;
        }
};
vector<i64>fib(65),id0(65);
void solve(){
	int n;
        cin>>n;
        i64 a[n];
        for(auto &x:a) cin>>x;
        i64 sum=0;
        for(auto x:a) sum+=x;
        bool check=false;
        int mark;
        for(int i=1;i<=60;i++){
        	if(sum==id0[i]){
        		check=true;
        		mark=i;
			}
		}
		if(!check){
			cout<<"NO\n";
			return ;
		}
		int pre=-1;
		vector<pair<int,int>>p;
		for(int i=0;i<n;i++) p.pb({a[i],i});
		for(int i=mark;i>=1;i--){
			bool chek=false;
			sort(p.begin(),p.end(),[&](pair<int,int>&x,pair<int,int>&y){
				return x.fi>y.fi;
			});
			for(int j=0;j<n;j++){
				if(p[j].fi>=fib[i]){
					if(pre==p[j].se){
						continue;
					}
					else{
						pre=p[j].se;
						p[j].fi-=fib[i];
						chek=true;
						break;
					}
				}
			}
			if(!chek){
				cout<<"NO\n";
				return;
			}
		}
		cout<<"YES\n";
}
int main(){
    faster();
    int t;
    cin>>t;
    fib[1]=1;
    fib[2]=1;
    for(int i=3;i<=60;i++){
    	fib[i]=fib[i-1]+fib[i-2];
	}
	id0[1]=1;
	for(int i=2;i<=60;i++) id0[i]=id0[i-1]+fib[i];
    while(t--){
        solve();
	}
    return 0;
}
