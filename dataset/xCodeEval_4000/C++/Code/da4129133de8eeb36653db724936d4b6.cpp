#include<bits/stdc++.h>
#define ll long long

template <typename T>
class matrix{
private:
	static const int MAXN = 100000;
	static T **ptrpool, *Tpool;
	static int ptrsize, Tsize;
	
	T **a = nullptr;
	int n = 0, m = 0;
	T moder = 0;
	
	T **newptrs(int size){
		if (ptrsize < size){
			ptrpool = new T *[ptrsize = std::max((int) MAXN, size)];
		}	
		return ptrpool + (ptrsize -= size);
	}
	
	T *newTs(int size){
		if (Tsize < size){
			Tpool = new T[Tsize = std::max((int) MAXN, size)]();
		}
		return Tpool + (Tsize -= size);
	}
	
	ll getone(int n)const &{return 1;}
	
	T powermod(T a, T exp)const &{
		T ret = 1;
		auto one = getone(a);
		for ( ; exp; exp >>= 1){
			if (exp & 1){
				ret = one * ret * a % moder;
			}
			a = one * a * a % moder;
		}
		return ret;
	}
	
	void apply(int n, int m){
		if (!n || !m) return;
		a = newptrs(n);
		for (int i = 0; i < n; ++ i){
			a[i] = newTs(m);
		}
		this -> n = n, this -> m = m;
	}
	
	void InitMatrix(const matrix <T> &p){
		apply(p.n, p.m);
		moder = p.moder;
		for (int i = 0; i < n; ++ i){
			memcpy(a[i], p.a[i], sizeof(T) * m);
		}
	}
	
	void InitMatrix(matrix <T> &&p){
		a = p.a, n = p.n, m = p.m, moder = p.moder;
	}
	
public:
	matrix <T>():n(0), m(0), moder(0){a = nullptr;}
	matrix <T>(int n, int m, T moder):moder(moder){apply(n, m);}
	matrix <T>(const matrix <T> &p){InitMatrix(p);}
	matrix <T>(matrix <T> &&p){InitMatrix(std::move(p));}
	T *operator [](int n){return a[n];}
	int getline(){return n;}
	int getcolumn(){return m;}
	T getmod(){return moder;}
	void setmod(T moder){this -> moder = moder;}
	void clear(){a = nullptr; n = m = 0;}
	
	void resize(int n, int m){
		if (this -> n == n && this -> m == m) return;
		apply(n, m);
	}
	
	matrix <T> &operator = (const matrix <T> &p){
		if (&p != this) InitMatrix(p);
		return *this;
	}
	
	matrix <T> &operator = (matrix <T> &&p){
		InitMatrix(std::move(p));
		return *this;
	}
	
	bool operator == (const matrix <T> &p)const &{
		if (n != p.n || m != p.m) return false;
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < m; ++ j){
				if (a[i][j] != p.a[i][j]) return false;
			}
		}
		return true;
	}
	
	matrix <T> operator + (const matrix <T> &p)const &{
		if (n != p.n || m != p.m) assert(("Invalid matrix addition!", 0));
		matrix <T> ret(n, m, moder);
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < m; ++ j){
				ret.a[i][j] = a[i][j] + p.a[i][j];
				ret.a[i][j] -= ret.a[i][j] >= moder ? moder : 0;
			}
		}
		return ret;
	}
	
	matrix <T> operator - (const matrix <T> &p)const &{
		if (n != p.n || m != p.m) assert(("Invalid matrix subtraction!", 0));
		matrix <T> ret(n, m, moder);
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < m; ++ j){
				ret.a[i][j] = a[i][j] - p.a[i][j];
				ret.a[i][j] += ret.a[i][j] < 0 ? moder : 0;
			}
		}
		return ret;
	}
	
	matrix <T> operator - ()const &{
		matrix <T> ret(n, m, moder);
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < m; ++ j){
				ret.a[i][j] = ret.a[i][j] ? moder - ret.a[i][j] : 0;
			}
		}
		return ret;
	}
	
	matrix <T> operator * (const matrix &p)const &{
		if (m != p.n) assert(("Invalid matrix multiplication!", 0));
		matrix <T> ret(n, p.m, moder);
		auto one = getone(moder);
		for (int k = 0; k < m; ++ k){
			for (int i = 0; i < n; ++ i){
				for (int j = 0; j < p.m; ++ j){
					ret.a[i][j] = (ret.a[i][j] + one * a[i][k] * p.a[k][j]) % moder;
				}
			}
		}
		return ret;
	}
	
	matrix <T> operator * (T &p)const &{
		matrix <T> ret(n, m);
		auto one = getone(moder);
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < m; ++ j){
				ret.a[i][j] = one * p * a[i][j] % moder;
			}
		}
		return ret;
	}
	
	friend matrix <T> operator * (const T &p, const matrix <T> &mat){return mat * p;}
	matrix <T> &operator += (const matrix &p){*this = *this + p; return *this;}
	matrix <T> &operator -= (const matrix &p){*this = *this - p; return *this;}
	matrix <T> &operator *= (const T &p){*this = *this * p; return *this;}
	
	template <typename K>
	matrix <T> power(K exp)const &{
		if (n != m) assert(("Invalid matrix power!", 0));
		matrix <T> ret(matrixI(n, moder)), aux(*this);
		for ( ; exp; exp >>= 1){
			if (exp & 1){
				ret = ret * aux;
			}
			aux = aux * aux;
		}
		return ret;
	}
	
	template <typename K>
	matrix <T> powersum(K exp)const &{
		if (n != m) assert(("Invalid matrix powersum!", 0));
		matrix <T> ret(matrixI(n, moder)), aux(*this);
		matrix <T> unit(ret);
		K exp1 = 1;
		for (++ exp; exp > 1; exp1 = exp1 << 1 | exp & 1, exp >>= 1)
			;
		for ( ; exp1 > 1; exp1 >>= 1){
			ret = ret * (aux + unit);
			aux = aux * aux;
			if (exp1 & 1){
				ret += aux;
				aux = aux * *this;
			}
	    }
	    return ret;
	}
	
	T det()const &{
		if (n != m) assert(("Invalid matrix det!", 0));
		matrix aux(*this);
		T ret = 1;
		auto one = getone(a[0][0]);
		for (int i = 0; i < aux.n; ++ i){
			int sit = -1;
			for (int j = i; j < aux.n; ++ j){
				if (aux.a[j][i]){
					sit = j;
					break;
				}
			}
			if (!~sit) return 0;
			if (sit != i){
				for (int j = i; j < aux.n; ++ j){
					std::swap(aux.a[i][j], aux.a[sit][j]);
				}
				ret = ret ? moder - ret : 0;
			}
			for (int j = i + 1; j < n; ++ j){
				for (int now = j, pre = i; aux.a[pre][i]; std::swap(now, pre)){
					T coe = aux.a[now][i] / aux.a[pre][i];
					for (int k = i; k < n; ++ k){
						aux.a[now][k] = (aux.a[now][k] - one * coe * aux.a[pre][k] % moder + moder) % moder;
					}
				}
				if (!aux.a[i][i]){
					ret = ret ? moder - ret : 0;
					for (int k = i; k < n; ++ k){
						std::swap(aux.a[i][k], aux.a[j][k]);
					}
				}
			}
		}
		for (int i = 0; i < n; ++ i){
			ret = one * ret * aux.a[i][i] % moder;
		}
		return ret;
	}
	
	matrix <T> gauss(const matrix <T> &p)const &{
		matrix aux1(*this), aux2(p);
		int *aux = new int [aux1.m];
		if (aux1.n != aux2.n) assert(("Invalid matrix equation!", 0));
		for (int i = 0; i < aux1.m; ++ i){
			aux[i] = i;
		}
		int zero = aux1.n;
		for (int i = 0; i < aux1.n; ++ i){
			int sit = -1, sit1 = -1;
			for (int j = i; j < aux1.n; ++ j){
				for (int k = i; k < aux1.m; ++ k){
					if (aux1.a[j][k]){
						sit = j, sit1 = k;
						break;
					}
				}
				if (~sit) break;
			}
			if (!~sit){
				zero = i;
				break;
			}
			if (sit1 != i){
				std::swap(aux[i], aux[sit1]);
				for (int j = 0; j < aux1.n; ++ j){
					std::swap(aux1.a[j][i], aux1.a[j][sit1]);
				}
			}
			T inv = powermod(aux1.a[sit][i], moder - 2);
			auto one = getone(a[0][0]);
			for (int j = i; j < aux1.m; ++ j){
				std::swap(aux1.a[i][j], aux1.a[sit][j]);
				aux1.a[i][j] = one * aux1.a[i][j] * inv % moder;;
			}
			for (int j = 0; j < aux2.m; ++ j){
				std::swap(aux2.a[i][j], aux2.a[sit][j]);
				aux2.a[i][j] = one * aux2.a[i][j] * inv % moder;
			}
			for (int j = 0; j < aux1.n; ++ j){
				if (j == i) continue;
				T coe = aux1.a[j][i];
				for (int k = i; k < aux1.m; ++ k){
					aux1.a[j][k] = ((aux1.a[j][k] - one * coe * aux1.a[i][k]) % moder + moder) % moder;
				}
				for (int k = 0; k < aux2.m; ++ k){
					aux2.a[j][k] = ((aux2.a[j][k] - one * coe * aux2.a[i][k]) % moder + moder) % moder;
				}
			}
		}
		for (int i = zero; i < aux1.n; ++ i){
			for (int j = 0; j < aux2.m; ++ j){
				if (aux2.a[i][j]) return delete [] aux, matrix(0, 0, 0);
			}
		}
		matrix ret(aux1.m, (n - zero + 1) * aux2.m, aux1.moder);
		for (int i = 0; i < zero; ++ i){
			memcpy(ret.a[aux[i]], aux2.a[i], sizeof(T) * aux2.m);
			for (int j = zero; j < aux1.m; ++ j){
				for (int k = 0; k < aux2.m; ++ k){
					ret.a[aux[i]][(j - zero + 1) * aux2.m + k] = aux1.a[i][j] ? moder - aux1.a[i][j] : 0;
				}
			}
		}
		for (int i = zero; i < aux1.n; ++ i){
			for (int j = 0; j < aux2.m; ++ j){
				ret.a[aux[i]][(i - zero + 1) + j] = 1;
			}
		}
		delete [] aux;
		return ret;
	}
	
	matrix <T> inv()const &{
		if (n != m) assert(("Invalid matrix inv!", 0));
		matrix <T> aux(matrixI(n, moder));
		return gauss(aux);
	}
	
	static matrix <T> matrixI(int n, int moder){
		matrix <T> ret(n, n, moder);
		for (int i = 0; i < n; ++ i){
			ret.a[i][i] = 1;
		}
		return ret;
	}
};

template <typename T> T **matrix <T>::ptrpool = nullptr;
template <typename T> T *matrix <T>::Tpool = nullptr;
template <typename T> int matrix <T>::ptrsize = 0;
template <typename T> int matrix <T>::Tsize = 0;

const int MAX = 1 << 16;
const int N = 50010;

int n, m, p;
ll k;
int s[N];
std::pair <ll, int> q[N];
matrix <int> seg[MAX << 1];

void build(){
	for (int i = 0; i < MAX << 1; ++ i){
		seg[i].resize(2, 2);
		seg[i].setmod(p);
		seg[i][0][0] = seg[i][1][1] = 1;
	}
}

void add(int sit, matrix <int> p){
	seg[sit += MAX] = p;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = seg[sit << 1 | 1] * seg[sit << 1];
	}
}

matrix <int> query(int l, int r){
	matrix <int> mat(2, 2, p);
	mat[0][0] = mat[1][1] = 1;
	matrix <int> mat1 = mat;
	if (l > r) return mat;
	for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			

			mat = seg[l ++] * mat;
		}
		if (r & 1){
			

			mat1 = mat1 * seg[--r];
		}
	}
	

	return mat1 * mat;
}

int main(){
	scanf("%I64d%d%d", &k, &p, &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &s[i]);
	}
	build();
	for (int i = 0; i < n; ++ i){
		matrix <int> mat(2, 2, p);
		mat[0][1] = 1;
		mat[1][0] = s[i];
		mat[1][1] = s[(i + 1) % n];
		add(i, mat);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++ i){
		ll j;
		int v;
		scanf("%I64d%d", &j, &v);
		q[i] = {j, v};
	}
	if (!k){
		return printf("0\n"), 0;
	}	
	std::sort(q, q + m);
	while (m && q[m - 1].first >= k){
		-- m;
	}
	if (q[m - 1].first != k - 1){
		q[m ++] = {k - 1, s[(k - 1) % n]};
	}
	ll now = 0;
	matrix <int> nowmat(2, 1, p);
	nowmat[1][0] = 1;
	for (int i = 0; i < m; ++ i){
		matrix <int> mat(2, 2, p);
		if (now / n >= (q[i].first - 2) / n){
			if (now <= q[i].first - 2){
				mat = query(now % n, (q[i].first - 2) % n);
				nowmat = mat * nowmat;
			}
		}
		else{
			

			

			

			nowmat = query(now % n, n - 1) * nowmat;
			nowmat = query(0, n - 1).power <ll> ((q[i].first - 2) / n - now / n - 1) * nowmat;
			nowmat = query(0, (q[i].first - 2) % n) * nowmat;
			now = q[i].first - 1;
		}
		

		if (now < q[i].first){
			mat[0][0] = 0;
			mat[0][1] = 1;
			mat[1][0] = s[(q[i].first - 1) % n];
			mat[1][1] = q[i].second;
			

			nowmat = mat * nowmat;
		}
		

		mat[0][0] = 0;
		mat[0][1] = 1;
		mat[1][0] = q[i].second;
		mat[1][1] = i < m - 1 && q[i].first + 1 == q[i + 1].first ? q[i + 1].second : s[(q[i].first + 1) % n];
		nowmat = mat * nowmat;
		now = q[i].first + 1;
	}
	printf("%d\n", nowmat[0][0]);
	return 0;
}