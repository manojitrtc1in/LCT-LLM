








 
using INT128 =  __int128;
using INT64 = int64_t;
using INT32 = int32_t;
 
using namespace std;

bool DEBUG = false;

template <typename T>
T maxT(T a) {
  if (sizeof(T) >= 16) {
    INT128 temp = 1000'000'000'000'000'000;
    return temp*temp;
  }  else if (sizeof(T) >= 8) {
    return 1000'000'000'000'000'000;
  } else {
    return 1000'000'000;
  }
}

template <typename T>
T minT(T a) {
  return -maxT(a);
}


 
template <class T>
void print1(const vector<T> &a) {
  for(auto x: a) {
    cout << (INT64) x << " ";
  }
  cout << "\n";
}
 
 
 
template <class T>
void print2(const vector<T> &a) {
  for(auto x: a) {
    print1(x);
  }
}
 
 
 
template <typename T>
T sign(T val) {
  return (T(0) < val) - (val < T(0));
}
 
 
template <typename T>
T dot(const vector<T> &x, const vector<T> &y) {
  if (x.size() == y.size()) {
    T s = 0;
    for (size_t i = 0; i < x.size(); ++i) s += x[i] * y[i];
    return s;
  } else {
    cout << "Error: \n";
    print1(x);
    print1(y);
    throw invalid_argument("length of dot arguments must be equal");
  }
}
 
template <typename TX,  typename TY, typename TD>
TD dot(const vector<TX> &x, const vector<TY> &y, const TD &helper) {
  if (x.size() == y.size()) {
    TD s = 0;
    for (size_t i = 0; i < x.size(); ++i) s += TD(x[i]) * TD(y[i]);
    return s;
  } else {
    cout << "Error: \n";
    print1(x);
    print1(y);
    throw invalid_argument("length of dot arguments must be equal");
  }
}
 
 
 
 
template <typename T>
T abs(T x) {
  if (x >= T(0) ) {
    return x;
  } else {
    return -x;
  }
}

template <typename T>
vector<T> intsqrt(T a2) {
  if (a2 == 0) {
    return vector<T> {0};
  } else {
    T af = (T) sqrt( (double) a2 );
    while (af*af > a2 && af > 0) --af;
    while (af*af < a2) ++af;
    if (af*af == a2) {
      return vector<T> {af, -af};
    } else {
      return vector<T> {};
    }
  }
}
 

 
template <typename T> 
void add(const vector<T> &vec, const T cf, vector<T> &res) {
  if (vec.size() == res.size()) {
    for (size_t i = 0; i < vec.size(); ++i) {
      res[i] += vec[i] * cf;
    }
  } else {
    throw invalid_argument("length of source and target vectors in add must be equal");
  }
}
 
 
 
template <typename T> 
vector<T> wsum(const vector<vector<T>> &input, const vector<T> &cf) {
  if (input.size() == cf.size()) {
    if (input.size() > 0) {
      vector<T> res(input[0].size());
      for (size_t i = 0; i < input.size(); ++i) {
	add(input[i], cf[i], res);
      }
      return res;
    } else {
      throw invalid_argument("the dimension of the target is not defined because source is empty");
    }
  } else {
      throw invalid_argument("length of the source matrix and the coefficients covector must be equal");
  }
}
 
 
 
template <typename T>
vector<vector<T>> normalize2(const vector<vector<T>> &input) {
  

  

  if (DEBUG) {
    cout << "enter normalize2\n";
    print2(input);
  }
  if (input.size() < 2) {
    return input;
  } else {
    vector<vector<T>> e = input;
 
    if (dot(e[0],e[0]) > dot(e[1], e[1])) {
      swap(e[0], e[1]);
    }
    
    if (dot(e[0], e[0]) == 0) {
      return vector<vector<T>> {e[1]};
    } else {
      T norm = dot(e[1], e[1]);
      
      T n_ = (- dot(e[1],e[0])) / dot(e[0], e[0]);
      T n = n_ + sign(-dot(e[1],e[0]))*sign(dot(e[0],e[0]));
 
      vector<T> id2 = wsum( vector<vector<T>> {e[0], e[1]},
				 vector<T> {n_,1});
 
      vector<T> e1 = wsum( vector<vector<T>> {e[0], e[1]},
				 vector<T> {n,1});
 
      vector<vector<T>> res {};
      if (dot(e1,e1) <= dot(id2, id2)) {
	res = vector<vector<T>> {e[0], e1};
      } else {
	res = vector<vector<T>> {e[0], id2};
      }
      if (dot(res[1], res[1]) < norm) {
	return normalize2(res);
      } else {
	return res;
      }
    }
  }
}
 
 
template <typename T>
class Primes {
  vector<T> primes;
  T _n;
public:
  Primes(T n) {
    

    primes = vector<T> {};
    _n = n;
 
    vector<char> mask(n+1);
 
    for (int p = 2; p*p <= n; p++) {
      if (mask[p] == 0) {
	for (int i = p*p; i <= n; i += p) {
	  mask[i] = 1;
	}
      }
    }
    for (int p=2; p<=n; p++) {
      if (mask[p] == 0) {
	primes.push_back(p);
      }
    }
  }
 
  const int size() {
    return primes.size();
  }

  const T bound() {
    return _n;
  }
 
  const vector<T> all() {
    return primes;
  }
  
  T operator[](int i) {
    if (0 <= i && i < primes.size()) {
      return primes[i];
    } else {
      throw invalid_argument("wrong index");
    }
  }
};
 
template <typename T, typename TP>       
vector<vector<T>> factors(T x, Primes<TP> &p) {
  

  int i = 0;
  vector<vector<T>> res {};
  
  while (i < p.size() && p[i] * p[i] <= x) {
    int cnt = 0;
    while (x % p[i] == 0) {
      x = x / p[i];
      ++cnt;
    }
    if (cnt > 0) {
      res.push_back(vector<T> {p[i], cnt});
    }
    ++i;
  }
 
  if (x != 1) {
    res.push_back(vector<T> {x,1});
  }


  if (res.size() > 0 && res[res.size()-1][0] > p.bound()) {
    if (res[res.size()-1][1] == 1) {
      T target = res[res.size()-1][0];
      vector<T> starget = intsqrt(target);
      if (starget.size() == 2) {
	res[res.size()-1][0] = starget[0];
	res[res.size()-1][1] = 2;
      }
    } else {
      throw invalid_argument("control flow error, multiplicity higher then 1 should not happen for non-tested prime");
    }
  }

  return res;
}
 
template <typename T, typename TP>
T mod(T x, TP p) {
  T a = x % p;
  if (a < 0) {
    return a + p;
  } else {
    return a;
  }
}

template <typename T>
vector<T> id7(vector<T> v, T p) {
  vector<T> res {};
  for (auto x: v) {
    T a = mod(x, p);
    if (abs(a - p) < abs(a)) {
      res.push_back(a - p);
    } else {
      res.push_back(a);
    }
  }
  return res;
}


template <typename T, typename TP>
T id16(T, T, Primes<TP> &primes);
 
template <typename T, typename TP>
T qres(T q, T p, Primes<TP> &primes) {
  

  

  q = mod(q, p);
  if (q == 0) {
    return 0;
  } else {
    vector<vector<T>> fs = factors(q, primes);
    T res = 1;
    for (auto f: fs) {
      T cur = id16(f[0], p, primes);
      if (cur == -1 && f[1] % 2 == 1) {
	res *= -1;
      }
    }
    return res;
  }
}
 
template <typename T, typename TP>
T id16(T q, T p, Primes<TP> &primes) {
  

  

  

  if (mod(q,p) == 2) {
    if (p % 8 == 1 || p % 8 == 7) {
      return 1;
    } else {
      if (p % 8 == 3 || p % 8 == 5) {
	return -1;
      } else {
	 cout << "unexpected q,p call of id16; q is not prime?";
	 cout << "(q,p): " << (INT64)q << "," << (INT64)p << "\n";
	throw -1;
      }
    }
  } else {
    T sfactor = (mod(q,4) == 3 && mod(p,4) == 3) ? -1 : 1;
    return sfactor*qres(mod(p,q), q, primes);
  }
}
 
template <typename T, typename TP, typename TA>
T id1(T x, TA a, TP p) {
  

  if (DEBUG) { cout << "x: " << (INT64) x << " a: " << (INT64) a << " p: " << (INT64) p;}
  T t = x;
  T res = 1;
  while (a > 0) {
    T d = a % 2;
    a = a / 2;
    if (d == 1) {
      res = mod(res * t, p);
    }
    t = mod(t*t, p);
  }
  if (DEBUG) {cout << " res " << (INT64) res << "\n";}
  return res;
}

template <typename T, typename TA>
T power(T x, TA a) {
  T t = x;
  T res = 1;
  for (TA i = 0; i < a; ++i) {res = res*x; }
  return res;
}

 
template <typename T, typename TP>
T imgunit(T p, T a, Primes<TP> &primes) {
  

  

  if (!(a > 0)) {
    cout << "a is " << INT64(a) << " but the power a of prime must be positive\n";
    throw -2;
  } else {
    if (p > 2 && p % 4 == 1) {
      for (T q = 2; q < p; ++q) {
	if (qres(q, p, primes) == -1) {
	  T degree = power(p, a - 1) * (p - 1) / 4;
	  T pa = power(p, a);
	  return id1(q, degree, pa);
	}
      }
      cout << "failed to find nonresidue for p " << INT64(p);
      throw -3;
    } else {
      cout << "for p = " << INT64(p) << " the imaginary unit is not implemented ";
      throw -4;
    }
  }
}
 
template <typename T>
vector<T> id12(T a, T b, T c) {
  

  if (a*a <= c && b*b <= c) {
    return vector<T> {a, b};
  } else {
    return id12(b, a % b, c);
  }
}
 
template <typename T> 
vector<T> id5(T a, T b) {
  

  

  if (b == 0) {
    return vector<T> {1, 0, a};
  } else {
    T r = a / b;
    T a_ = a - b*r;
    vector<T> res = id5(b, a_);
    T d = (res[0] - res[1]*r)  /  a;
    return vector<T> {res[1] + b*d, res[0] - res[1]*r - a*d, res[2]};
  }
}
 
 
template <typename T>
vector<T> egcd(T a, T b) {
  if (abs(a) >= abs(b)) {
    return id5(a, b);
  } else {
    vector<T> temp = id5(b, a);
    return vector<T> {temp[1], temp[0], temp[2]};
  }
}
 
template <typename T>
T egcd(const vector<T> &v) {
  if (v.size() == 0) {
    throw invalid_argument("empty set to reduce");
  } else {
    T res = v[0];
    for (int i = 1; i < v.size(); i++) {
      res = egcd(res, v[i])[2];
    }
    return res;
  }
}
 
 
template <typename T, typename TP>
T crm(T x, TP p, T y, TP q) {
  

  

  

  vector<T> res = egcd(T(p), T(q));
  if (res[2] != 1) {
    cout << "gcd of p, q is " << INT64(res[2]) << "\n";
   cout << "chinese remainder lemma is not implemented for gcd(p,q) != 1\n";
    throw -5; }
  else {
    return mod(res[0]*p*y + res[1]*q*x, T(p)*T(q));
  }
}
 
template <typename T, typename TP>
T crmv(const vector<T> &x, const vector<TP> &p) {
  

  if (x.size() == 0 || x.size() != p.size() ) {
    cout << "crmv must receive non-empty sets, but received: \n";
    print1(x);
    print1(p);
    throw -6;
  } else if (x.size() == 1) {
    return x[0];
  } else {
    T hx = x[0];
    T hp = p[0];
    for (int i = 1; i < x.size(); ++i) {
      hx = crm(hx, hp, x[i], p[i]);
      hp = hp*p[i];
    }
    return hx;
  }
}
 
template <typename T>
vector<vector<T>> product(const vector<vector<T>> &data,  const vector<T>& prefix, int offset) {
  if (offset == data.size()) {
    return vector<vector<T>> {prefix};
  } else if (offset >= 0 && offset < data.size()) {
    vector<vector<T>> res {};
    for (auto x: data[offset]) {
      vector<T> nextprefix = prefix;
      nextprefix.push_back(x);
      vector<vector<T>> temp = product(data, nextprefix, offset + 1);
      for (auto t: temp) {
	res.push_back(t);
      }
    }
    return res;
  } else {
    cout << "bad offset in product: " << offset << "\n";
    throw -7;
  }
}
 
template <typename T, typename TP>
vector<vector<T>> primitive_pairs(T z, Primes<TP> &primes) {
  

  

  if (z < 0) {
    cout << "not implemented for negative z" << "\n";
    throw -8;
  } else if (z == 0) {
    return vector<vector<T>> {vector<T> {0,0}};
  } else if (z == 1) {
    return vector<vector<T>> {vector<T> {0,1}};
  } else if (z == 2) {
    return vector<vector<T>> {vector<T> {1,1}};
  } else {
    vector<vector<T>> fs  = factors(z, primes);
    bool good = true;
    for (auto f: fs) {
      if ((f[0] == 2 && f[1] > 1) || (f[0] % 4 == 3 && f[1] > 0)) {
	good = false;
	break;
      }
    }
 
    if (!good) {
      return vector<vector<T>> {};
    } else {
      vector<vector<T>> roots {};
      for (auto f: fs) {
	if (f[0] == 2) {
	  if (f[1] != 1) {
	    cout << "control flow bug\n";
	    cout << "f[0] is " << (INT64) f[0] << " f[1] is " << (INT64) f[1] << "\n";
	    throw -9;
	  } else {
	    roots.push_back(vector<T> {1});
	  }
	} else {
	  if (f[0] % 4 == 1 && f[1] > 0) {
	    T temp = imgunit(f[0], f[1], primes);
	    roots.push_back(vector<T> {temp, power(f[0], f[1]) - temp});
	  } else {
	    cout << "control flow bug\n";
	    cout << "f[0] is " << (INT64) f[0] << " f[1] is " << (INT64) f[1] << "\n";
	    throw -10;
	  }
	}
      }
      if (roots.size() != fs.size() ) {
	cout << "roots computation bug\n";
	cout << "got roots\n";
	print2(roots);
	cout << "got factors\n";
	print2(fs);
	throw -11;
      } else {
	vector<vector<T>> options = product(roots, vector<T> {}, 0);
	vector<T> comp {};
	for (auto f: fs) {
	  comp.push_back(power(f[0], f[1]));
	}
	vector<vector<T>> ans {};
	
	for (int i = 0; i < options.size() / 2; ++i) {
	  T r = crmv(options[i], comp);
	  r = mod(r, z);
	  auto pa = id12(z, r, z);
	  sort(pa.begin(), pa.end());
	  ans.push_back(pa);
	}
	return ans;
      }
    }
  }
}
 
template <typename T, typename TP>
vector<TP> id13(const vector<vector<T>> &fs, TP prefix, int offset) {
  

  
  if (offset == fs.size()) {
    return vector<TP> {prefix};
  } else {
    vector<TP> res {};
    for (T i = 0; i <= fs[offset][1] / 2; ++i) {
      vector<TP> temp = id13(fs, prefix*TP(power(fs[offset][0],
						      i)), offset+1);
      for (auto t: temp) {
	res.push_back(t);
      }
    }
    return res;
  }
}
 
template <typename T, typename TP>
vector<vector<T>> qpairs(T z, Primes<TP> &primes) {
  

  

  if (DEBUG) { cout << "qpairs: z " << (INT64) z << "\n";};
  vector<vector<T>> fs = factors(z, primes);
  if (DEBUG) { cout << "z factors: "; print2(fs);};
  
  vector<T> qd = id13(fs, T(1), 0);
  vector<vector<T>> res {};
  for (auto d: qd) {
    for (auto p: primitive_pairs(z/(d*d), primes)) {
      res.push_back(vector<T> {d*p[1], d*p[0]} );
    }
  }
  return res;
}
 
 
template <typename T, typename TP>
vector<vector<T>> id6(T z, Primes<T> &primes) {
  vector<vector<T>> res {};
  for (T a = 0; a <= z/2; ++a) {
    for (auto pa: qpairs(a, primes)) {
      for (auto pb: qpairs(z - a, primes)) {
	if (pa[1] <= pb[0]) {
	  res.push_back(vector<T> {pa[0], pa[1], pb[0], pb[1]});
	}
      }
    }
  }
  return res;
}
 
template <typename T, typename TP>
vector<vector<T>> id11(T z, Primes<TP> &primes) {
  

  

  

  

  

 
  

 
  vector<vector<T>> res {};
 
  for (T x0 = 1; x0*x0 <= z; ++x0) {
    for (T x1 = 0; x0*x0 + x1*x1 <= z && x1 <= x0; ++x1) {
      for (auto p: qpairs(z - (x0*x0 + x1*x1), primes)) {
	if (p[0] <= x0) {
	for (T s1 = 0; s1 < 2; ++s1) {
	  for (T s2 = 0; s2 < 2; ++s2) {
	    for (T s3 = 0; s3 < 2; ++s3) {
	      res.push_back( vector<T> {x0, (-1 + 2*s1)*x1, (-1+2*s2)*p[0], (-1+2*s3)*p[1]});
	      res.push_back( vector<T> {x0, (-1 + 2*s1)*x1, (-1+2*s2)*p[1], (-1+2*s3)*p[0]});
	    }
	  }
	}
	}
      }
    }
  }
  return res;
}
 
template <typename T, typename TP>
vector<vector<T>> id10(T z, Primes<TP> &primes) {
  vector<vector<T>> res {};
 
  for (T a0 = 0; a0*a0 <= z; ++a0) {
    for (auto p: qpairs( z - a0*a0, primes)) {
	for (T s1 = 0; s1 < 2; ++s1) {
	  for (T s2 = 0; s2 < 2; ++s2) {
	    for (T s3 = 0; s3 < 2; ++s3) {
	      res.push_back( vector<T> {(-1 + 2*s1)*a0, (-1 + 2*s2)*p[0],  (-1 + 2*s3)*p[1]});
	      res.push_back( vector<T> {(-1 + 2*s1)*a0, (-1 + 2*s2)*p[1],  (-1 + 2*s3)*p[0]});
	    }
	  }
	}
    }
  }
  return res;
}
 
 
 
 
 
template <typename T>
vector<vector<T>> id(int n) {
  

  vector<vector<T>> res(n, vector<T>(n) );
  for (int i = 0; i < n; ++i) {
    res[i][i] = 1;
  }
  return res;
}
 
template <typename T> 
void swap_columns(vector<vector<T>> &a, int i, int j) {
  for (auto &v: a) {
    swap(v[i], v[j]);
  }
}
 
template <typename T>
void swap_rows(vector<vector<T>> &a, int i, int j) {
  swap(a[i], a[j]);
}
 
 
template <typename T>
void id8(vector<vector<T>> &a, vector<vector<T>> &r, int i) {
  

  

  

    
  if (i >= a.size()) {
    return;
  } else {
    int n = r.size();
    int j = i;
    while (j < n && a[i][j] == 0) ++j;
    if (j == n) {
      a.erase(a.begin() + i);
      id8(a, r, i);
    } else {
      int j_ = j + 1;
      while (j_ < n && a[i][j_] == 0) ++j_;
      if (j_ == n) { 

	swap_columns(a, i, j);
	swap_columns(r, i, j);
	id8(a, r, i + 1);
      } else {
	T ma = abs(a[i][j]);
	T tj = j;
	for (j_ = j; j_ < n; ++j_) {
	  if (abs(a[i][j_]) < ma && abs(a[i][j_]) != 0) {
	    tj = j_;
	    ma = abs(a[i][j_]);
	  }
	}
 
	for (j_ = 0; j_ < n; ++j_) {
	  if (j_ != tj) {
	  T c = a[i][j_] / a[i][tj];
	  for (int k = i; k < a.size(); ++k) {
	    a[k][j_] = a[k][j_] - c * a[k][tj];
	  }
	  for (int k = 0; k < n; ++k) {
	    

	    r[k][j_] = r[k][j_] - c * r[k][tj];	    
	  }
	  }
	}
	id8(a, r, i);
      }
    }
  }
}
 
 
template <typename T>
vector<vector<T>> id4(const vector<T> &x) {
  return vector<vector<T>>
  {{x[1]*x[1] - x[2]*x[2] - x[3]*x[3] + x[0]*x[0], 2*x[1]*x[2] - 2*x[3]*x[0], 
  2*(x[1]*x[3] + x[2]*x[0])}, {2*(x[1]*x[2] + x[3]*x[0]), 
  -x[1]*x[1] + x[2]*x[2] - x[3]*x[3] + x[0]*x[0], 2*x[2]*x[3] - 2*x[1]*x[0]}, 
 {2*x[1]*x[3] - 2*x[2]*x[0], 2*(x[2]*x[3] + x[1]*x[0]), 
     -x[1]*x[1] - x[2]*x[2] + x[3]*x[3] + x[0]*x[0]}};
}
 
 
 
 
 
 
 
 
template <typename T, typename TV>
vector<T> axv(const vector<T> &x, const vector<TV> &v) {
  

  vector<T> res {};
  for (auto e: id4(x)) {
    res.push_back(dot(e, v, T(0)));
  }
  return res;
}
 
 
template <typename T>
vector<T> cross(const vector<T> &a, const vector<T> &b)  {
  return vector<T> {  a[1]*b[2] - a[2]*b[1],
		        -a[0]*b[2] + a[2]*b[0],
			 a[0]*b[1] - a[1]*b[0]};
}
 
template <typename TV, typename TU, typename T>
vector<vector<T>> xlattice(const vector<TV> &v, const vector<TU> &u, T L) {
  

  if (dot(v,v, T(0)) != L*L*dot(u,u, T(0))) {
    cout << "(v,v) != L^2 (u,u) in the input of xlattice \n";
    throw -12;
  } else {
    vector<T> b  = {v[0] + L*u[0],
			  v[1] + L*u[1],
			  v[2] + L*u[2]};
    vector<T> vminus = {v[0] - L*u[0],
			   v[1] - L*u[1],
			   v[2] - L*u[2]};
    vector<T> a = cross(vminus, b);
 
    T c = dot(b, b);
 
    int j = 0;
    while (j < 3 && b[j] == 0) ++j;
    if (j == 3) {
      return vector<vector<T>> {}; 

    } else {
      vector<vector<T>> eqs {};
      for (int i = 0; i < 3; ++i) {
	if (i != j) {
	  vector<T> eq(4);
	  eq[0] = a[i]*b[j]-a[j]*b[i];
	  eq[i+1] = -c*b[j];
	  eq[j+1] = c*b[i];
	  eqs.push_back(eq);
	}
      }
      vector<vector<T>> r = id<T>(4);
      id8(eqs, r, 0);
      int d = eqs.size();
      vector<vector<T>> res {};
      for (int i = d; i < 4; i++) {
	vector<T> temp(4);
	for (int j = 0; j < 4; j++) {
	  temp[j] = r[j][i];
	}
	res.push_back(temp);
      }
      
      return res;
    }
  }
}
 
 
 
 
 
template <typename T>    
vector<vector<T>> solutions(vector<vector<T>> &basis, T L) {
  vector<vector<T>> res {};
  if (basis.size() == 0) {
    return res;
  } else if (basis.size() == 1) {
    T g = dot(basis[0], basis[0]);
    if (L % g != 0) {
      return res;
    } else {
      T a2 = L / g;
      for (auto a: intsqrt(a2)) {
	res.push_back( wsum(basis, vector<T> {a}) );
      }
      return res;
    }
  }  else if (basis.size() == 2) {
    T g00 = dot(basis[0], basis[0]);
    T g01 = dot(basis[0], basis[1]);
    T g11 = dot(basis[1], basis[1]);
    T d = g00 * g11 - g01*g01;
    for (T alpha = 0; alpha*alpha * d <= g11*L; ++alpha) {
      for (T si = -1; si <= 1; si = si+2) {
 
	for (T s: intsqrt( g11*L - alpha*alpha*d )) {
	  if ( (-si*g01*alpha + s) % g11 == 0) {
	    res.push_back( wsum(basis, vector<T> {si*alpha, (-g01*alpha*si + s) / g11}));
	  }
	}
      }
    }
    return res;
  } else {
    

    throw -13;
  }
}
 
template <typename TV, typename T, typename TL> 
vector<vector<TL>> xgood(vector<vector<TV>> &vs, vector<T> &x, TL L) {
 
  vector<vector<TL>> cur = {};
  bool OK = true;
  for (auto v: vs) {
    auto a = axv(x, v);
    

    

    if (!(a[0] % (L*L) == 0 && a[1] % (L*L) == 0 && a[2] % (L*L) == 0)) {
      OK = false;
      break;
    } else {
      vector<TL> a_(3);
      for (int i = 0; i < 3; ++i) {
	a_[i] = TL(a[i] / (L*L));
      }
      cur.push_back(a_);
    }
  }
  if (OK) {
    return cur;
  } else {
    return vector<vector<TL>> {};
  }
}
    
 
template <typename T>
vector<vector<T>> reduce2(const vector<vector<T>> &basis_, const vector<T> &v) {
  


  if (DEBUG) {
    cout << "enter reduce2 with: \n";
    print2(basis_);
    print1(v);
  }
  
  vector<vector<T>> e = normalize2(basis_);

  if (DEBUG) {
    cout << "normalized e:\n";
    print2(e);
  }
  if (e.size() == 1) {
    e.push_back(v);
    return normalize2(e);
  }
  else {
    T original_norm = dot(e[0], e[0]) + dot(e[1], e[1]);
	
    T e00 = dot(e[0],e[0]);
    T e11 = dot(e[1],e[1]);
    T e01 = dot(e[0],e[1]);
 
    T det2 = e00*e11 - e01*e01;
 
    if (det2 == 0) {
      cout << "bug in algorithm: normalize2(basis) was not supposed to return degenerate basis of length 2\n";
      throw -14;
    }
 
    T v0 = dot(e[0], v);
    T v1 = dot(e[1], v);
 
    T nn0 =  (v0*e11 - v1*e01) / det2;
    T nn1 = (-v0*e01 + v1*e00) / det2;
 
    if (!(nn0 <= maxT(T(0)) && nn0 >= minT(T(0)))) throw -15;
    if (!(nn1 <= maxT(T(0)) && nn1 >= minT(T(0)))) throw -16;
 
    vector<T> n = { (T) nn0  ,(T) nn1 };
 
    T norm = maxT(T(0));
    vector<T> id14(v.size());
      
    for (int d0 = 0; d0 < 2; d0++) {
      for (int d1 = 0; d1 < 2; d1++) {
	vector<T> n_ = { n[0] + sign(n[0]) * d0,
			    n[1] + sign(n[1]) * d1 };
 
	vector<T> v_red = wsum(e, n_);
 
	add(v, T(-1), v_red);
 
	T norm_cur = dot(v_red, v_red);
	if (DEBUG) {
	  cout << "norm_cur\n";
	  cout << (INT64) norm_cur << "\n";	    ;
	  cout << "norm\n";
	  cout << (INT64) norm << "\n";
	}
	if (norm_cur <= norm) {
	  id14 = v_red;
	  norm = norm_cur;
	}
      }
    }
 
    if (norm == 0) {
      return e;
    } else {
      if (norm < e11) {
	return reduce2(vector<vector<T>> {e[0],id14}, e[1]);
      } else {
	if (DEBUG) {cout << "returning..\n";
	  print1(id14);}
	return vector<vector<T>> {e[0],e[1],id14};
      }
    }
  }
}
 
 
template <typename T>
vector<vector<T>> reduce3(const vector<vector<T>> &basis_, const vector<T> &v_) {
  

  vector<vector<T>> basis {};
  if (DEBUG) {
    cout << "reducing basis: \n";
    print2(basis_);
  }
 
  if (basis_.size() == 0) {
    return vector<vector<T>> {v_};
  } else if (basis_.size() == 1) {
    return normalize2(vector<vector<T>> {basis_[0], v_});
  } else if (basis_.size() == 2) {
    return reduce2(basis_, v_);
  } else if (basis_.size() == 3) {
    vector<vector<T>> basis = reduce2(vector<vector<T>> {basis_[0], basis_[1]} , basis_[2]);
    if (basis.size() != 3) {
      return reduce2(basis, v_);
    } else { 

      

      vector<T> v {};
      for (auto el: v_) v.push_back( (T) el);
      vector<vector<T>> e {};
      for (auto u: basis) {
	vector<T> u_ {};
	for (auto el: u) u_.push_back( (T) el);
	e.push_back(u_);
      }
 
 
      T det2 = e[0][2]*(-(e[1][1]*e[2][0]) + e[1][0]*e[2][1]) + e[0][1]*(e[1][2]*e[2][0] - e[1][0]*e[2][2]) + 
	e[0][0]*(-(e[1][2]*e[2][1]) + e[1][1]*e[2][2]);
 
      if (det2 == 0) {
	cout << "unexpected singular basis of 3 elements\n";
	print2(basis);
	throw -1;
      }
 
      vector<T> b = {-(v[2]*e[1][1]*e[2][0]) + v[1]*e[1][2]*e[2][0] + v[2]*e[1][0]*e[2][1]
			    - v[0]*e[1][2]*e[2][1] - v[1]*e[1][0]*e[2][2] +  v[0]*e[1][1]*e[2][2],
			    v[2]*e[0][1]*e[2][0] - v[1]*e[0][2]*e[2][0] - v[2]*e[0][0]*e[2][1] +
			    v[0]*e[0][2]*e[2][1] +   v[1]*e[0][0]*e[2][2] - v[0]*e[0][1]*e[2][2],
			    -(v[2]*e[0][1]*e[1][0]) + v[1]*e[0][2]*e[1][0] + v[2]*e[0][0]*e[1][1] - 
			    v[0]*e[0][2]*e[1][1] - v[1]*e[0][0]*e[1][2] + v[0]*e[0][1]*e[1][2]};
 
      vector<T> n = { T (b[0] / det2),  T (b[1] / det2),  T  (b[2] / det2)};
 
      T norm = maxT(T(0));
      vector<T> id14(v.size());
 
      for (int d0 = 0; d0 < 2; d0++) {
	for (int d1 = 0; d1 < 2; d1++) {
	  for (int d2 = 0; d2 < 2; d2++) {
	    vector<T> n_ = { n[0] + sign(n[0]) * d0,
				    n[1] + sign(n[1]) * d1,
				    n[2] + sign(n[2]) * d2 };
 
	    vector<T> v_red = wsum(basis, n_);
	    add(v_, T(-1), v_red);
	    T norm_cur = dot(v_red, v_red);
	    if (norm_cur < norm) {
	      id14 = v_red;
	      norm = norm_cur;
	    }
	  }
	}
      }
      
      if (norm == 0) {
	return basis;
      } else {
	if (norm < dot(basis[2], basis[2])) {
	  return reduce3(vector<vector<T>> {basis[0], basis[1], id14}, basis[2]);
	} else {
	  return basis;
	}
      }
    }
  } else {
    cout << "unexpected basis_ size " << basis_.size() << "\n";
    throw -17;
  }
}
    
    
 
 
template <typename T>
vector<vector<T>> id0(vector<vector<T>> &data) {
  if (data.size() == 0) {
    cout << "impossible to reduce empty set of vectors\n";
    throw -18;
  } else {
    vector<vector<T>> basis {};
 
    int i = 0;
 
    while (i < min(int(data.size())-1,3))
      basis.push_back(data[i++]);
 
 
    while (i < data.size()) {
      basis = reduce3(basis, data[i++]);
    }
    return basis;
  }
}
 

template <typename T>
vector<vector<T>> get_data() {
  int n = 0;
  cin >> n;
  vector<vector<T>> data {};
  for (int i = 0; i < n; ++i) {
    vector<T> cur(3);
    for (int j = 0; j < 3; ++j) {
      INT64 temp;
      cin >> temp;
      cur[j] = T(temp);
    }
    data.push_back(cur);
  }
  return data;
}



template <typename T>
T id17(vector<vector<T>> vs) {
  vector<T> bil {};
  for (int i = 0; i < vs.size(); ++i)
    for (int j = i; j < vs.size(); ++j)
      if (abs(dot(vs[i], vs[j], T(0))) != 0) {
	bil.push_back( abs(dot(vs[i], vs[j], T(0))));
      }
  if (bil.size() == 0) {
    return 0; 
  } else {
    return egcd(bil);
  }
}

template <typename T, typename TP> 
bool id3(vector<vector<T>> &basis, T L, Primes<TP>& primes) {
  auto r = id<T>(3 + basis.size());
  auto dim = basis.size();
  T norm = 0;
  for (auto v: basis) {
    norm += dot(v, v, T(0));
  }
  if (DEBUG) {cout << "norm =  " << (INT64) norm << ", L = " << (INT64) L << " \n";};
  
  vector<vector<T>> a {};
  for (int i = 0; i < basis.size(); ++i) {
    vector<T> row = basis[i];
    for (int j = 0; j < i; ++j) {
      row.push_back(0);
    }
    row.push_back(L*L);
    for (int j = i+1; j < basis.size(); ++j) {
      row.push_back(0);
    }
    a.push_back(row);
  }
  id8(a, r, 0);

  if (DEBUG) {
  cout << "a:\n";
  print2(a);
  cout << "r:\n";
  print2(r);
  }

  for (int i = 0; i < basis.size(); ++i) {
    basis[i] = id7(basis[i], L*L);
  }
  for (int i = a.size(); i < a.size() + 3; ++i) {
    vector<T> cur {};
    for (int j = 0; j < 3; ++j) {
      cur.push_back(r[j][i]);
    }
    

    T cur2 = dot(cur, cur, T(0));

    auto c = mod(cur2, L*L);
    T temp = 1;
    if (c != 0) {
      auto Lfs = factors(L, primes);
      auto cfs = factors(c,  primes);
      for (auto e: Lfs) {
	T x = 0;
	for (auto e_: cfs) {
	  if (e_[0] == e[0]) {
	    x = e_[1];
	    break;
	  }
	}
      temp *= power(e[0], e[1] - (x / 2));
      }
    } else {if (DEBUG) {cout << "skip\n";}}
    vector<T> cur_scale(3);
    if (DEBUG) {cout << "temp: " << (INT64) temp << "\n";}
    add(cur, temp, cur_scale);
    cur_scale = id7(cur_scale, L*L);
    basis.push_back(cur_scale);
  }

  if (DEBUG) {
  cout << "new basis:\n";
  print2(basis);
  }

  auto new_basis = id0(basis);

  if (new_basis.size() < 3) {
    if (L <= 1000'000) {
      new_basis.push_back(vector<T> {L*L, 0, 0});
      new_basis.push_back(vector<T> {0, L*L, 0});
      new_basis.push_back(vector<T> {0, 0, L*L});
      new_basis = id0(new_basis);
    } else {
      cout << "stopped earlier because of int128 overflow\n";
      throw -25;
    }
  }

  if (DEBUG) {
  cout << "new basis reduced:\n";
  print2(new_basis);
  }
  
  T new_norm = 0;
  for (auto v: new_basis) {
    new_norm += dot(v, v, T(0));
  }

  if (DEBUG) {cout << "new norm: " << (INT64) new_norm << "\n";}
  
  if (new_basis.size() == dim && new_norm == norm) {
    basis = new_basis;
    bool is_good = (basis.size() == 3);
    for (auto v: basis) {
      is_good = is_good && (dot(v,v, T(0)) == L*L);
    }
    if (is_good) {
      return is_good;
    } else {
      if (DEBUG) {cout << "attempt reduce:\n";
	print2(basis);
      }
      for (int i = 0; i < 3; ++i) {
	for (int j = i+1; j < 3; ++j) {
	  if ( (dot(basis[i], basis[j], T(0)) == 0) &&
	       (dot(basis[i], basis[i], T(0)) == 2*L*L) &&
	       (dot(basis[j], basis[j], T(0)) == 2*L*L) &&
	       ((basis[i][0] + basis[j][0]) % 2 == 0) &&
	       ((basis[i][1] + basis[j][1]) % 2 == 0) &&
	       ((basis[i][2] + basis[j][2]) % 2 == 0)) {
	    if (DEBUG) {
	      cout << "condition fullfilled..\n";
	    }
	    vector<T> basisplus = {};
	    vector<T> basisminus = {};
	    for (int k = 0; k < 3; ++k) {
	      basisplus.push_back((basis[i][k]+basis[j][k])/2);
	      basisminus.push_back((basis[i][k]-basis[j][k])/2);
	    }
	    basis[i] = basisplus;
	    basis[j] = basisminus;
	  }
	}
      }
      return id3(basis, L, primes);
    }
  } else {
    basis = new_basis;
    return id3(basis, L, primes);
  }
}

int main() {
  int n = 0;
  DEBUG = false;
  auto data = get_data<INT128>();
  auto vs = id0(data);
  if (DEBUG) {print2(vs);}

  auto bil_work = id17(vs);
  INT128 id15 = INT128(cbrt(double(bil_work))) + 100;

  Primes<INT32> primes(id15);

  auto fs = factors(bil_work, primes);

  auto Ls = id13(fs, INT128(1), 0);

  if (DEBUG) {print1(Ls);}
  
  sort(Ls.begin(), Ls.end(),
       [](const INT128 &a, const INT128 &b) {return a>b;});

  for (auto L: Ls) {
    vector<vector<INT128>> basis {};
    for (auto v: vs) {
      basis.push_back(vector<INT128>(v.begin(), v.end()));
    }
    if (id3(basis, L, primes)) {
      cout << (INT64) (L*L) << "\n";
      print2(basis);
      break;
    }
  }
}


int main2() {
  auto answer = vector<vector<long>> { {2, 2, -1},
				       {2, -1, 2},
				       {-1, 2, 2}};

  //auto a = vector<vector<long>> {  {5, 8, -1, 9} };

  auto a = vector<vector<long>> { {5, 5,  2, 9, 0, 0},
				  {0, 3, -3, 0, 9, 0},
				  {3, 0, -3, 0, 0, 9} };
  
  auto r = id<long>(6);

  /*  {5, 8, -1}
  {0, -9, 0}
  {5, -1, -1}
  {-4, -1, -1}
  {1, -2, -2}
  {2, 5, -4} */
  

  id8(a, r, 0);
  cout << "a:\n";
  print2(a);

  cout << "r:\n";
  print2(r);
  return 0;

  /*  {65 (2); 80; -1; 26 (-1); */
    
}
 
  
int main3() {
 
  //auto v = vector<INT128> {-3688, 4288, 15556};
  //auto v = vector<INT128> {188900, 420872, 485178};
  // auto v = vector<INT128> {168385588, -6809558, 567030082};
 
  //auto u = vector<INT128> {8, -5, 10};   //auto L = (INT128) 1204L ;
 
  // optimization assumption v[0] has smalles norm
 
  //auto vs = vector<vector<INT128>> {{137, 134, 173}, {173, 209, 224}, {-86, 139, 43}};
 
  /*  vector<vector<INT128>> data =
    {{-122294, 617224, -367605}, {-1149835, 
  6131228, -3603304}, {974205, -4865748, 2922162}, {-854956, 
  4279106, -2564982}, {1828434, 2231143, 726250}, {6077, 16116, 
						   138}, {20607, 91473, -3881}};
    
  */
 
  auto data = get_data<INT128>();

  DEBUG  = true;
  if (DEBUG && data[0][0] == -184631) {
    DEBUG = true;
  }

  if (DEBUG) {
    print2(data);
  }
  auto vs =  id0(data);
  

  auto bil_work = id17(vs);
  
  INT128 id15 = max(INT128(cbrt(double(bil_work))) + 100,
			    INT128(sqrt(sqrt(double(dot(vs[0],vs[0],INT128(0)))))));
  //INT128 id15 = 300'000;

  if (DEBUG) {cout << "primes bound " << (INT64) id15 << "\n"; }
  
  Primes<INT32> primes(id15);
 
  auto fs = factors(bil_work, primes);

  if (DEBUG) print2(fs);
  
  

  
  
  

 
  
 
  if (DEBUG) {cout << "factors: "; print2(fs);}

  vector<INT64> Ls = id13(fs , INT64(1), 0);
  
  sort(Ls.begin(), Ls.end(),
       [](const INT64 &a, const INT64 &b) {return a>b;});

  if (DEBUG) {cout << "Ls: "; print1(Ls);}
  
  vector<vector<vector<INT64>>> id9 {};
 
  bool found = false;
  for (auto L: Ls) {
    if (found) { break; }
    if (INT128(L)*L*L*L <= dot(vs[0], vs[0], INT128(0))) {
      if (DEBUG) {cout << "L = "  << (INT64) L <<  " quadruples search \n";}
      for (auto x: id11(L, primes)) {
	auto cur = xgood(vs, x, L);
	if (cur.size() > 0) {
	  cur.push_back(x);
	  cur.push_back(vector<INT64> {L});
	  id9.push_back(cur);
	  found = true;
	  break;
	}
      }
    } else {
      INT64 a2 = dot(vs[0], vs[0], INT64(0)) / (L*L);
      if (DEBUG) {cout << "L = " << (INT64) L << " triples search \n";}
      for (auto u: id10(a2, primes)) {
	if (DEBUG) {cout << "u: "; print1(u);}
	if (found) { break; }
	auto res = xlattice(vs[0], u, INT128(L));
	if (DEBUG) {cout << "res: \n"; print2(res);}
	res = normalize2(res);
	if (DEBUG) {cout << "norm res: \n"; print2(res);}
	for (auto x: solutions(res, INT128(L))) {
	  if (DEBUG) {cout << "x: "; print1(x);}
	  vector<vector<INT64>> cur = xgood(vs, x, INT64(L));
	  if (cur.size() > 0) {
	    cur.push_back(vector<INT64>(x.begin(), x.end()));
	    cur.push_back(vector<INT64> {L});
	    id9.push_back(cur);
	    found = true;
	    break;
	  }
	}
      }
    }
  }
 
  if (id9.size() != 1) {
    int temp  = 0;
    cout << 1/temp;
  }
  
  for (auto s: id9) {
    

    

    cout << INT64((s[s.size()-1][0]*s[s.size()-1][0])) << "\n";
    print2(id4(s[s.size()-2]));
  }
  return 0;
}
