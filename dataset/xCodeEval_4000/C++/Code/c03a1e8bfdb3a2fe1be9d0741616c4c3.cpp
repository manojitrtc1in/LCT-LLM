






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
		














 









































































































































 




 

























































 


 








 




 
























 
 







template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    static int inv_mod(int a, int m = MOD) {
        

        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        

        

        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    _m_int inv() const {
        return inv_mod(val);
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
 
    friend int abs(const _m_int &m) {
        return m.val;
    }
};
 
extern const int MOD = 3;
using Mint = _m_int<MOD>;

int n, m; 

template <typename T> 





vector<T> gauss_elim(vector<vector<T>> a) {
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

	

	vector<T> x(cols, 0);
	for(int i = cols-1; i >= 0; --i) {
		if(where[i] < 0) continue; 
		
		r = where[i];

		T value = a[r][cols];
		for(int j = i+1; j < cols; ++j) {
			value -= a[r][j] * x[j]; 
		}  
		x[i] = value/a[r][i]; 
	}
	return x; 
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

	vector<Mint> answer = gauss_elim<Mint>(eqns); 
	
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
		trace(i, answer[i], abs(answer[i]), answer[i].val); 
		cout << (abs(answer[i]) == 0 ? 3 : abs(answer[i])) << ' '; 
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