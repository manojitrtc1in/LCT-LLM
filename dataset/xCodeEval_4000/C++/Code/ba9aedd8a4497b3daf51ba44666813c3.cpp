






























































































































#include <bits/stdc++.h>
using namespace std;





#define n_l '\n'
#define check(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]) { return N; } template<typename T> int SIZE(const T &t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)),  __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += n_l; return res; } void dbgm() {;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cerr << to_string(H) << " | "; dbgm(T...); }
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl





#defineBhaag_Bhaag_DK_Bose ios_base::sync_with_stdio(false); cin.tie(0);
#defineBhaag_Bhaag_DK_Bose_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#defineLL long long
#definehack 1LL*
#definerep(i,a,b) for(int i=a;i<b;i++)
#definerepp(i,a,b) for(int i=a;i<=b;i++)
#definerepr(i,a,b) for(int i=a;i>=b;i--)
#definevi vector<int>
#definevLL vector<LL>
#definevii vector<vi>
#definevLLLL vector<vector<LL>>
#definevcc vector<vector<char>>
#definevp vector<pair<int,int>>
#definevc vector<char>
#definevb vector<bool>
#definevbb vector<vector<bool>>
#definemn INT_MIN+1
#definemod 1000000007
#definemx INT_MAX-1
#defineinf 1e18+4
#definestr string
#definefi first
#definese second
#definesot(w) sort(w.begin(),w.end())
#definersot(w) sort(w.rbegin(),w.rend())
#definepb push_back
#definemin_v(w) *min_element(w.begin(),w.end())
#definemax_v(w) *max_element(w.begin(),w.end())
#defineendl "\n"
#definemem(w,x) memset(w,x,sizeof(w))
#defineppb pop_back
#definepii pair<int,int>
#defineall(x) (x).begin(),(x).end()
#definecmax(x,y) x=x>y?x:y
#definecmin(x,y) x=x<y?x:y
#definesz(a) a.size()
#definesp <<" "<<
#definespp <<" "
#defineen <<endl

bool custom_compare(pair<LL, LL> &a, pair<LL, LL> &b) {
	return a.se < b.se;
}
bool custom_compare2(pair<int, int> &a, pair<int, int> &b) {
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


