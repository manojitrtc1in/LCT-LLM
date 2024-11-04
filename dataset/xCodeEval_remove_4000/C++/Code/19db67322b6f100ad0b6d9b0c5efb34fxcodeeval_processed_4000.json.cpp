
using namespace std;

template<typename T>
struct id0{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> _MOD_INV;
	constexpr id0(): value(){ }
	template<typename U> id0(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	id0 &operator+=(const id0 &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	id0 &operator-=(const id0 &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> id0 &operator+=(const U &otr){ return *this += id0(otr); }
	template<typename U> id0 &operator-=(const U &otr){ return *this -= id0(otr); }
	id0 &operator++(){ return *this += 1; }
	id0 &operator--(){ return *this -= 1; }
	id0 operator++(int){ id0 result(*this); *this += 1; return result; }
	id0 operator--(int){ id0 result(*this); *this -= 1; return result; }
	id0 operator-() const{ return id0(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename id0<U>::Type, int>::value, id0>::type &operator*=(const id0& rhs){
		
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename id0<U>::Type, int64_t>::value, id0>::type &operator*=(const id0 &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename id0<U>::Type>::value, id0>::type &operator*=(const id0 &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	id0 &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		id0 res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	id0 operator^(U e) const{
		return id0(*this) ^= e;
	}
	id0 &operator/=(const id0 &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)_MOD_INV.size()) return *this *= _MOD_INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	Type value;
};
template<typename T> bool operator==(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const id0<T>& lhs, U rhs){ return lhs == id0<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const id0<T> &rhs){ return id0<T>(lhs) == rhs; }
template<typename T> bool operator!=(const id0<T> &lhs, const id0<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const id0<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const id0<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const id0<T> &lhs, const id0<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> id0<T> operator+(const id0<T> &lhs, const id0<T> &rhs){ return id0<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator+(const id0<T> &lhs, U rhs){ return id0<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator+(U lhs, const id0<T> &rhs){ return id0<T>(lhs) += rhs; }
template<typename T> id0<T> operator-(const id0<T> &lhs, const id0<T> &rhs){ return id0<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator-(const id0<T>& lhs, U rhs){ return id0<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator-(U lhs, const id0<T> &rhs){ return id0<T>(lhs) -= rhs; }
template<typename T> id0<T> operator*(const id0<T> &lhs, const id0<T> &rhs){ return id0<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator*(const id0<T>& lhs, U rhs){ return id0<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator*(U lhs, const id0<T> &rhs){ return id0<T>(lhs) *= rhs; }
template<typename T> id0<T> operator/(const id0<T> &lhs, const id0<T> &rhs) { return id0<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator/(const id0<T>& lhs, U rhs) { return id0<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id0<T> operator/(U lhs, const id0<T> &rhs) { return id0<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, id0<T> &number){
	typename common_type<typename id0<T>::Type, int64_t>::type x;
	in >> x;
	number.value = id0<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const id0<T> &number){ return out << number(); }
template<typename T> vector<typename id0<T>::Type> id0<T>::_MOD_INV;
template<typename T>
void id1(int SZ){
	auto &inv = T::_MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((T::mod() - 1LL * T::mod() / (int)inv.size() * inv[T::mod() % (int)inv.size()]) % T::mod());
}
template<typename T>
vector<T> id3(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}





constexpr int mod = (119 << 23) + 1; 



using modular = id0<integral_constant<decay<decltype(mod)>::type, mod>>;



struct pq_tree{
	int n;
	bool id2 = false;
	vector<vector<int>> adj;
	
	vector<int> data;
	pq_tree(int n): n(n), adj(n + 1), data(n + 1), label(n + 1), in_s(n){
		adj[0].resize(n);
		iota(adj[0].begin(), adj[0].end(), 1);
		iota(data.begin() + 1, data.end(), 0);
	}
	operator bool(){
		return !id2;
	}
	int new_node(int type, int state){
		adj.emplace_back();
		data.push_back(type);
		label.push_back(state);
		return (int)adj.size() - 1;
	}
	
	vector<int> label, in_s;
	

	bool reduce(const vector<int> &s){
		if(id2) return false;
		if((int)s.size() == 1) return true;
		fill(in_s.begin(), in_s.end(), false);
		for(auto x: s) in_s[x] = true;
		bool done = false;
		auto dfs = [&](auto self, int u)->int{
			if(adj[u].empty()){
				

				return label[u] = in_s[data[u]];
			}
			int deg = (int)adj[u].size(), pertinence = 0;
			array<int, 3> count{};
			for(auto v: adj[u]){
				pertinence += self(self, v);
				if(id2 || done) return 0;
				++ count[label[v]];
			}
			bool is_root = pertinence == (int)s.size();
			if(data[u] == 0){
				

				if(count[0] == deg){
					

					label[u] = 0;
				}
				else if(count[1] == deg){
					

					label[u] = 1;
				}
				else if(count[0] + count[1] == deg){
					if(is_root){
						

						int u2 = new_node(0, 1);
						auto it = partition(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] == 0; });
						adj[u2].insert(adj[u2].end(), it, adj[u].end());
						adj[u].erase(it, adj[u].end());
						adj[u].push_back(u2);
					}
					else{
						

						array<int, 2> v;
						for(auto t = 0; t < 2; ++ t){
							if(count[t] == 1){
								v[t] = *find_if(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] == t; });
							}
							else{
								v[t] = new_node(0, t);
								auto it = partition(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] != t; });
								adj[v[t]].insert(adj[v[t]].end(), it, adj[u].end());
							}
						}
						adj[u] = {v[0], v[1]};
						data[u] = 1;
						label[u] = 2;
					}
				}
				else if(count[2] == 1){
					if(is_root){
						

						if(auto it = partition(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] != 1; }); adj[u].end() - it >= 2){
							int u2 = new_node(0, 1);
							adj[u2].insert(adj[u2].end(), it, adj[u].end());
							adj[u].erase(it, adj[u].end());
							for(auto v: adj[u]){
								if(label[v] == 2){
									if(label[adj[v].back()] != 1) reverse(adj[v].begin(), adj[v].end());
									adj[v].push_back(u2);
									break;
								}
							}
						}
						else if(adj[u].end() - it == 1){
							int u2 = adj[u].back();
							adj[u].pop_back();
							for(auto v: adj[u]){
								if(label[v] == 2){
									if(label[adj[v].back()] != 1) reverse(adj[v].begin(), adj[v].end());
									adj[v].push_back(u2);
									break;
								}
							}
						}
						if(count[0] == 0){
							int v = adj[u][0];
							adj[u] = adj[v];
							adj[v].clear();
							data[u] = 1;
							label[u] = 2;
						}
					}
					else{
						

						array<int, 2> v{-1, -1};
						for(auto t = 0; t < 2; ++ t){
							if(count[t] == 1) v[t] = *find_if(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] == t; });
							else if(count[t] >= 2){
								v[t] = new_node(0, t);
								for(auto w: adj[u]) if(label[w] == t) adj[v[t]].push_back(w);
							}
						}
						int pu = *find_if(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] == 2; });
						if(label[adj[pu][0]]) reverse(adj[pu].begin(), adj[pu].end());
						adj[u].clear();
						if(~v[0]) adj[u].push_back(v[0]);
						adj[u].insert(adj[u].end(), adj[pu].begin(), adj[pu].end());
						if(~v[1]) adj[u].push_back(v[1]);
						data[u] = 1;
						label[u] = 2;
					}
				}
				else if(count[2] == 2 && is_root){
					

					int v = -1;
					if(count[1] == 1){
						auto it = find_if(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] == 1; });
						v = *it;
						adj[u].erase(it);
					}
					else if(count[1] >= 2){
						v = new_node(0, 1);
						auto it = partition(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] != 1; });
						adj[v].insert(adj[v].end(), it, adj[u].end());
						adj[u].erase(it, adj[u].end());
					}
					array<int, 2> w;
					auto it = find_if(adj[u].begin(), adj[u].end(), [&](int v){ return label[v] == 2; });
					w[0] = *it;
					it = find_if(next(it), adj[u].end(), [&](int v){ return label[v] == 2; });
					w[1] = *it;
					if(label[adj[w[0]][0]] != 0) reverse(adj[w[0]].begin(), adj[w[0]].end());
					if(~v) adj[w[0]].push_back(v);
					if(label[adj[w[1]][0]] != 1) reverse(adj[w[1]].begin(), adj[w[1]].end());
					adj[w[0]].insert(adj[w[0]].end(), adj[w[1]].begin(), adj[w[1]].end());
					adj[w[1]].clear();
					adj[u].erase(it);
					count[1] = 0;
					if(count[1]) id2 = true;
				}
				else id2 = true;
			}
			else{
				

				if(count[0] == deg){
					

					label[u] = 0;
				}
				else if(count[1] == deg){
					

					label[u] = 1;
				}
				else{
					if(label[adj[u].back()] == 0) reverse(adj[u].begin(), adj[u].end());
					if(label[adj[u].front()] != 0 && label[adj[u].back()] == 2) reverse(adj[u].begin(), adj[u].end());
					int i = 0;
					while(label[adj[u][i]] == 0) ++ i;
					int j = i + 1;
					while(j < deg && label[adj[u][j]] == 1) ++ j;
					if(j == deg){
						

						if(label[adj[u][i]] == 2){
							int v = adj[u][i];
							auto it = adj[u].erase(adj[u].begin() + i);
							if(label[adj[v][0]] != 0) reverse(adj[v].begin(), adj[v].end());
							adj[u].insert(it, adj[v].begin(), adj[v].end());
							adj[v].clear();
						}
						label[u] = 2;
					}
					else{
						int k = j + 1;
						while(k < deg && label[adj[u][k]] == 0) ++ k;
						if(k == deg && is_root){
							

							if(i < j && label[adj[u][j]] == 2){
								int v = adj[u][j];
								auto it = adj[u].erase(adj[u].begin() + j);
								if(label[adj[v].front()] == 0) reverse(adj[v].begin(), adj[v].end());
								adj[u].insert(it, adj[v].begin(), adj[v].end());
								adj[v].clear();
							}
							if(label[adj[u][i]] == 2){
								int v = adj[u][i];
								auto it = adj[u].erase(adj[u].begin() + i);
								if(label[adj[v].back()] == 0) reverse(adj[v].begin(), adj[v].end());
								adj[u].insert(it, adj[v].begin(), adj[v].end());
								adj[v].clear();
							}
						}
						else id2 = true;
					}
				}
			}
			if(is_root) done = true;
			return pertinence;
		};
		dfs(dfs, 0);
		return !id2;
	}
	template<class T>
	T id4() const{
		if(id2) return 0;
		vector<T> fact(n + 1, 1);
		for(auto x = 1; x <= n; ++ x) fact[x] = fact[x - 1] * x;
		auto dfs = [&](auto self, int u)->T{
			T res = adj[u].empty() ? 1 : data[u] ? 2 : fact[(int)adj[u].size()];
			for(auto v: adj[u]) res *= self(self, v);
			return res;
		};
		return dfs(dfs, 0);
	}
	vector<int> frontier() const{
		vector<int> order;
		auto dfs = [&](auto self, int u)->void{
			if(adj[u].empty()) order.push_back(data[u]);
			for(auto v: adj[u]) self(self, v);
		};
		dfs(dfs, 0);
		return order;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	pq_tree pqt(n);
	for(auto i = 0; i < m; ++ i){
		int qn;
		cin >> qn;
		vector<int> q(qn);
		for(auto &u: q){
			cin >> u, -- u;
		}
		pqt.reduce(q);
	}
	for(auto x = 100; x --; );
	cout << pqt.id4<modular>() << "\n";
	return 0;
}












