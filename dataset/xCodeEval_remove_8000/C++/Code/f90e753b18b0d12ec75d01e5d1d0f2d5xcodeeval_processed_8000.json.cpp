


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
int main(){
    faster();
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(auto &x:a) cin>>x;
        vector<set<int>>s(3001);
		for(int i=0;i<n;i++){
        	for(int j=1;j<=k;j++){
        		s[a[i]].insert(a[i]/j);
			}
		}
		int res=INT_MAX;
		for(int i=0;i<=3000;i++){
			int mn=3000,mx=-1;
			bool check=true;
			for(int j=0;j<n;j++){
				if(s[a[j]].lower_bound(i)==s[a[j]].end()){
					check=false;
				}
				int u=*s[a[j]].lower_bound(i);
				mx=max(mx,u);
				mn=min(mn,u);
			}
			

			if(check) res=min(res,mx-mn);
		}
		cout<<res<<"\n";
	}
    return 0;
}

