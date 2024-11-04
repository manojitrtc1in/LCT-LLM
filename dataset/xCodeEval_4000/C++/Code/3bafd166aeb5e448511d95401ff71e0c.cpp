






#include <bits/stdc++.h>






 
#define fix(f,n) std::fixed<<std::setprecision(n)<<f

typedef long long ll;

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, -1, 0, 1}; 
char direction[4] = {'D', 'L', 'U', 'R'}; 
 
using namespace std;


 




 





#ifdef ADD_TRACE
template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
 
}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif
		














 







































































































































const ll MOD = 3;
 




 


class Mint
{
	

	

	

	public:
	ll val;
	static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
	static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
	static ll modInverse(ll a) { return a; } 
	Mint(){	val = 0;} 
	Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
	Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
	Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
	Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
	Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
	Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
	Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
	Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
	Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
	Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
	bool operator ==(const Mint &other) const {   return val == other.val; }
	bool operator !=(const Mint &other) const { return val != other.val; }

	Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
	Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
	Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
	Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
 
	

 
	template<typename T>
	Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
	template<typename T>
	Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
 
	Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
	Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
 
	template<typename T>
	explicit operator T() {	return (T)val; }
	template<typename T>
	friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
	template<typename T>
	friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
	template<typename T>
	friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
	template<typename T>
	friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
	template<typename T>
	friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
 
 
	friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
	friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}
};







 










 








 




 






 










 




 












 










 










 


























 








 






 








 








 








 




 






 












 






 






 


 






 


 






 




 






 








 





int n, m; 

template <typename T> 





void gauss_elim(vector<vector<T>>& a, vector<T>& x) {
	int rows = (int)a.size();
	int cols = (int)a[0].size() - 1; 

	

	vector<int> where(cols, -1); 
	int r = 0; 
	for(int c = 0; c < cols && r < rows; ++c) {
		

		int sel = -1; 
		for(int i = r; i < rows; ++i) {
			if(a[i][c].val != 0) {
				sel = i; 
				break; 
			}
		}

		

		if(sel < 0) continue; 

		

		

		

		

		swap(a[sel], a[r]); 
		where[c] = r; 

		

		for(int i = r+1; i < rows; ++i) {
			if(a[i][c] == 0) continue;
			T mult = a[i][c]/a[r][c]; 
			for(int j = c; j <= cols; ++j) {
				a[i][j] -= a[r][j] * mult; 
			}
		}

		++r; 
	}

	

	

	for(int i = cols-1; i >= 0; --i) {
		if(where[i] < 0) continue; 
		
		r = where[i];

		T value = a[r][cols];
		for(int j = i+1; j < cols; ++j) {
			value -= a[r][j] * x[j]; 
		}  
		x[i] = value/a[r][i]; 
	}
	

}

void solve() {
	cin >> n >> m; 

	vector<int> color(m, -1); 
	vector<vector<int>> adj_mat(n, vector<int>(n, -1)); 
	vector<vector<Mint>> eqns;  

	int a, b, c; 
	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> c; 
		--a, --b; 
		adj_mat[a][b] = adj_mat[b][a] = i; 
		color[i] = c; 
	}

	for(int i = 0; i < m; ++i) {
		if(color[i] > 0) {
			vector<Mint> eq(m+1);
			eq[i] = 1;
			eq[m] = color[i];  
			eqns.push_back(eq);  
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) if(adj_mat[i][j] >= 0) {
			for(int k = j + 1; k < n; ++k) if(adj_mat[i][k] >= 0 && adj_mat[j][k] >= 0) {
				

				vector<Mint> eq(m+1);
				for(int e: {adj_mat[i][j], adj_mat[j][k], adj_mat[i][k]}) {
					eq[e] = 1; 
				} 
				eqns.push_back(eq); 
			}
		}
	}

	trace(eqns); 

	if(eqns.empty()) {
		for(int i = 0; i < m; ++i) {
			cout << "1 "; 
		}
		cout << '\n'; 
		return; 
	}

	vector<Mint> answer(m); 
	gauss_elim<Mint>(eqns, answer); 
	
	for(int i = 0; i < m; ++i) {
		if(color[i] > 0 && answer[i] != (color[i] % 3)) {
			cout << "-1\n"; 
			return; 
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = i+1; j < n; ++j) {
			for(int k = j+1; k < n; ++k) {
				if(adj_mat[i][j] >= 0 && adj_mat[j][k] >= 0 && adj_mat[k][i] >= 0) {
					if(answer[adj_mat[i][j]] + answer[adj_mat[k][j]] + answer[adj_mat[i][k]] != 0) {
						cout << "-1\n"; 
						return; 
					}
				}
			}
		}
	}
	
	for(int i = 0; i < m; ++i) {
		

		cout << ((answer[i].val) == 0 ? 3 : (answer[i].val)) << ' '; 
	}

	cout << '\n'; 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}