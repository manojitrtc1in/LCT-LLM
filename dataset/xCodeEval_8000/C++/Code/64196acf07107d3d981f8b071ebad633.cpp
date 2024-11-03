#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define faster() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define i64 long long
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
vector<int>c;
i64 l,w;
void check(int i){
	i64 z=l/i;
	i64 k=l-z*i;


	if(k==0){
	    if(w<i) return;	
	    if(i>2) if((w-2)%i!=0) return;
	}
	if(k==1){
		if(i>2) if((w-1)%i!=0) return;
	}
	if(k==2){
		if(w%i!=0) return;
	}
	if(k>2) return;
	c.pb(i);
}
int main(){
    faster();
    int t;
    cin>>t;
    while(t--){
        c.clear();
        cin>>l>>w;
        i64 are=l*w-(l-2)*(w-2);
        int z=min(l,w);
        for(int i=1;i<=sqrt(are);i++){
        	if(are%i==0){
        		if(i!=are/i){
        	    	check(i);
        	    	check(are/i);
			    }
			    else{
			    	if(i<=z){
			    		check(i);
					}
				}
			}
		}
		cout<<c.size()<<" ";
		sort(c.begin(),c.end());
		for(auto x:c) cout<<x<<" ";
		cout<<"\n";
	}
    return 0;
}

