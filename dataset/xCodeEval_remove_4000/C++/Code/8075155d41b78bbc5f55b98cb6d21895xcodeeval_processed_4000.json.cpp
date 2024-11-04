









































































































































using namespace std;







template <typename T, size_t N> int SIZE(const T (&t)[N]) { return N; } template<typename T> int SIZE(const T &t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int id0 = min(x1, SIZE(b)),  id2 = min(x2, SIZE(b) - 1); id0 <= id2; ++id0) { t += b[id0] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1 = 0, int x2 = 1e9, C... coords); int id1 = 0, id3 = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { id1++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; id1--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(id3, ' '); string res = ""; bool first = true; if (id1 == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; id1++; if (e != l) { if (rnk > 1) { res += n_l; id3 = id1; }; } else { id3 = 0; } res += to_string(*e, coords...); id1--; } res += "]"; if (id1 == 0) res += n_l; return res; } void dbgm() {;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cerr << to_string(H) << " | "; dbgm(T...); }














































bool custom_compare(pair<LL, LL> &a, pair<LL, LL> &b) {
	return a.se < b.se;
}
bool id4(pair<int, int> &a, pair<int, int> &b) {
	if (a.fi != b.fi) return a.fi < b.fi;
	else return a.se > b.se;
}

class dsu {
public:
	int parent[200005],rnk[200005];

	dsu(int n){
		repp(i,1,n)
			make_set(i);
	}
	void make_set(int v){
		parent[v]=v;
		rnk[v]=0;
	}
	int find_set(int v){
		if(v==parent[v])
			return v;
		return parent[v]=find_set(parent[v]);
	}
	void union_set(int a,int b){
		a=find_set(a);
		b=find_set(b);

		if(a!=b){
			if(rnk[a]<rnk[b])swap(a,b);
			parent[b]=a;
			if(rnk[a]==rnk[b]) rnk[a]++;
		}
	}
};

class sieve{ 					

public:
	vi spf,prime;
	set<int> s;

	sieve(int n):spf(n){ 

		spf[1]=1;
		repp(i,1,n) spf[i]=i;
		for(int i=4;i<=n;i+=2) spf[i]=2;

		for(int i=3;i*i<=n;i++){
			if(spf[i]==i){
				for(int j=i*i;j<n;j+=i){
					if(spf[j]==j) spf[j]=i;
				}
			}
		}
	}

	void createPrimeFactor(int n){ 

		while(n!=1){
			s.insert(spf[n]);
			n/=spf[n];
		}	
	}
};

LL calc_power(LL n, LL b, LL modd=-1) {	

	LL res = 1;
	while (b > 0) {
		if (b & 1){
			if(modd==-1)res = (res * n);	
			else res = (res*n) % modd;
		}
		if(modd==-1) n = n*n;
		else n = n * n %(modd);
		b >>= 1;
	}
	return modd==-1?res:res % modd ;
}

LL gcd(LL a, LL b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}






void testcase() {
	int n,t,k;
	cin>>n>>t>>k;

	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;

		cout<<"? "<<1<<" "<<mid;
		cout<<endl;
		
		int x;
		cin>>x;

		int curr_zero = mid-x;
		if(curr_zero<k) l=mid+1;
		else r=mid;
	}

	cout<<"! "<<r;
}

int main() {
	


	


	

	testcase();
}


