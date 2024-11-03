






using BIG =  __int128;
using LLONG =  __int128;
using PLONG =  int64_t;
using SMALL = int32_t;

using namespace std;


template <class T>
void print1(const vector<T> &a) {
  for(auto x: a) {
    cout << (PLONG) x << " ";
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
      T n = n_ + sign(n_);

      vector<T> id2 = wsum( vector<vector<T>> {e[0], e[1]},
				 vector<T> {n_,1});

      vector<T> e1 = wsum( vector<vector<T>> {e[0], e[1]},
				 vector<T> {n,1});

      vector<vector<T>> res {};
      if (dot(e1,e1) < dot(id2, id2)) {
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
public:
  Primes(T n) {
    

    primes = vector<T> {};

    vector<int> mask(n+1);

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

  const vector<T> all() {
    return primes;
  }
  
  T operator[](int i) {
    if (0 <= i && i < primes.size()) {
      return primes[i];
    } else {
      throw -1;
    }
  }
};

      


template <typename T> 
class id15 {
  vector<T> primes;
public:
  id15(T n) {
    

    primes = vector<T> {};
    if (n > 0) {
      primes.push_back(2);
    }
    T x = 3;
    while (primes.size() < n) {
      int i = 0;
      bool isprime = true;
      while (i < primes.size() && primes[i]*primes[i] <= x) {
	if (x % primes[i] == 0) {
	  isprime = false;
	  break;
	}
	++i;
      }
      if (isprime) {
	primes.push_back(x);
      }
      ++x;
    }
  }

  const int size() {
    return primes.size();
  }

  const vector<T> all() {
    return primes;
  }
  
  T operator[](int i) {
    if (0 <= i && i < primes.size()) {
      return primes[i];
    } else {
      throw -1;
    }
  }
};


vector<vector<LLONG>> factors(LLONG x, Primes<LLONG> &p) {
  

  int i = 0;
  vector<vector<LLONG>> res {};
  
  while (i < p.size() && p[i] * p[i] <= x) {
    int cnt = 0;
    while (x % p[i] == 0) {
      x = x / p[i];
      ++cnt;
    }
    if (cnt > 0) {
      res.push_back(vector<LLONG> {p[i], cnt});
    }
    ++i;
  }

  if (x != 1) {
    res.push_back(vector<LLONG> {x,1});
  }
  return res;
}

LLONG mod(LLONG x, LLONG p) {
  LLONG a = x % p;
  if (a < 0) {
    return a + p;
  } else {
    return a;
  }
}


LLONG id14(LLONG, LLONG, Primes<LLONG> &primes);

LLONG qres(LLONG q, LLONG p, Primes<LLONG> &primes) {
  

  

  q = mod(q, p);
  if (q == 0) {
    return 0;
  } else {
    vector<vector<LLONG>> fs = factors(q, primes);
    LLONG res = 1;
    for (auto f: fs) {
      LLONG cur = id14(f[0], p, primes);
      if (cur == -1 && f[1] % 2 == 1) {
	res *= -1;
      }
    }
    return res;
  }
}

LLONG id14(LLONG q, LLONG p, Primes<LLONG> &primes) {
  

  

  

  if (mod(q,p) == 2) {
    if (p % 8 == 1 || p % 8 == 7) {
      return 1;
    } else {
      if (p % 8 == 3 || p % 8 == 5) {
	return -1;
      } else {
	

	

	throw -1;
      }
    }
  } else {
    LLONG sfactor = (mod(q,4) == 3 && mod(p,4) == 3) ? -1 : 1;
    return sfactor*qres(mod(p,q), q, primes);
  }
}




LLONG id1(LLONG x, LLONG a, LLONG p) {
  

  LLONG t = x;
  LLONG res = 1;
  while (a > 0) {
    LLONG d = a % 2;
    a = a / 2;
    if (d == 1) {
      res = mod(res * t, p);
    }
    t = mod(t*t, p);
  }
  return res;
}

LLONG imgunit(LLONG p, LLONG a, Primes<LLONG> &primes) {
  

  

  if (!(a > 0)) {
    

    throw -1;
  } else {
    if (p > 2 && p % 4 == 1) {
      for (LLONG q = 2; q < p; ++q) {
	if (qres(q, p, primes) == -1) {
	  LLONG degree = id1(p, a - 1, id3) * (p - 1) / 4;
	  LLONG pa = id1(p, a, id3);
	  return id1(q, degree, pa);
	}
      }
      

      throw -1;
    } else {
      

      throw -1;
    }
  }
}

vector<LLONG> id11(LLONG a, LLONG b, LLONG c) {
  

  if (a*a <= c && b*b <= c) {
    return vector<LLONG> {a, b};
  } else {
    return id11(b, a % b, c);
  }
}


vector<LLONG> id5(LLONG a, LLONG b) {
  

  

  if (b == 0) {
    return vector<LLONG> {1, 0, a};
  } else {
    LLONG r = a / b;
    LLONG a_ = a - b*r;
    vector<LLONG> res = id5(b, a_);
    LLONG d = (res[0] - res[1]*r)  /  a;
    return vector<LLONG> {res[1] + b*d, res[0] - res[1]*r - a*d, res[2]};
  }
}



vector<LLONG> egcd(LLONG a, LLONG b) {
  if (abs(a) >= abs(b)) {
    return id5(a, b);
  } else {
    vector<LLONG> temp = id5(b, a);
    return vector<LLONG> {temp[1], temp[0], temp[2]};
  }
}


LLONG crm(LLONG x, LLONG p, LLONG y, LLONG q) {
  

  

  

  vector<LLONG> res = egcd(p, q);
  if (res[2] != 1) {
    

    

    throw -1; }
  else {
    return mod(res[0]*p*y + res[1]*q*x, p*q);
  }
}

LLONG crmv(const vector<LLONG> &x, const vector<LLONG> &p) {
  

  if (x.size() == 0 || x.size() != p.size() ) {
    

    

    

    throw -1;
  } else if (x.size() == 1) {
    return x[0];
  } else {
    LLONG hx = x[0];
    LLONG hp = p[0];
    for (int i = 1; i < x.size(); ++i) {
      hx = crm(hx, hp, x[i], p[i]);
      hp = hp*p[i];
    }
    return hx;
  }
}


vector<vector<LLONG>> product(const vector<vector<LLONG>> &data,  const vector<LLONG>& prefix, int offset) {
  if (offset == data.size()) {
    return vector<vector<LLONG>> {prefix};
  } else if (offset >= 0 && offset < data.size()) {
    vector<vector<LLONG>> res {};
    for (auto x: data[offset]) {
      vector<LLONG> nextprefix = prefix;
      nextprefix.push_back(x);
      vector<vector<LLONG>> temp = product(data, nextprefix, offset + 1);
      for (auto t: temp) {
	res.push_back(t);
      }
    }
    return res;
  } else {
    

    throw -1;
  }
}


vector<vector<LLONG>> primitive_pairs(LLONG z, Primes<LLONG> &primes) {
  

  

  if (z < 0) {
    

    throw -1;
  } else if (z == 0) {
    return vector<vector<LLONG>> {vector<LLONG> {0,0}};
  } else if (z == 1) {
    return vector<vector<LLONG>> {vector<LLONG> {0,1}};
  } else if (z == 2) {
    return vector<vector<LLONG>> {vector<LLONG> {1,1}};
  } else {
    vector<vector<LLONG>> fs  = factors(z, primes);
    bool good = true;
    for (auto f: fs) {
      if ((f[0] == 2 && f[1] > 1) || (f[0] % 4 == 3 && f[1] > 0)) {
	good = false;
	break;
      }
    }

    if (!good) {
      return vector<vector<LLONG>> {};
    } else {
      vector<vector<LLONG>> roots {};
      for (auto f: fs) {
	if (f[0] == 2) {
	  if (f[1] != 1) {
	    

	    

	    throw -1;
	  } else {
	    roots.push_back(vector<LLONG> {1});
	  }
	} else {
	  if (f[0] % 4 == 1 && f[1] > 0) {
	    LLONG temp = imgunit(f[0], f[1], primes);
	    roots.push_back(vector<LLONG> {temp, id1(f[0], f[1], id3) - temp});
	  } else {
	    

	    

	    throw -1;
	  }
	}
      }
      if (roots.size() != fs.size() ) {
	

	

	

	

	

	throw -1;
      } else {
	vector<vector<LLONG>> options = product(roots, vector<LLONG> {}, 0);
	vector<LLONG> comp {};
	for (auto f: fs) {
	  comp.push_back(id1(f[0], f[1], id3));
	}
	vector<vector<LLONG>> ans {};
	
	for (int i = 0; i < options.size() / 2; ++i) {
	  LLONG r = crmv(options[i], comp);
	  r = mod(r, z);
	  auto pa = id11(z, r, z);
	  sort(pa.begin(), pa.end());
	  ans.push_back(pa);
	}
	return ans;
      }
    }
  }
}


vector<LLONG> id12(const vector<vector<LLONG>> &fs, LLONG prefix, int offset) {
  

  
  if (offset == fs.size()) {
    return vector<LLONG> {prefix};
  } else {
    vector<LLONG> res {};
    for (LLONG i = 0; i <= fs[offset][1] / 2; ++i) {
      vector<LLONG> temp = id12(fs, prefix*id1(fs[offset][0],
							i, id3), offset+1);
      for (auto t: temp) {
	res.push_back(t);
      }
    }
    return res;
  }
}

vector<vector<LLONG>> qpairs(LLONG z, Primes<LLONG> &primes) {
  

  

  vector<vector<LLONG>> fs = factors(z, primes);
  vector<LLONG> qd = id12(fs, 1, 0);
  vector<vector<LLONG>> res {};
  for (auto d: qd) {
    for (auto p: primitive_pairs(z/(d*d), primes)) {
      res.push_back(vector<LLONG> {d*p[1], d*p[0]} );
    }
  }
  return res;
}


vector<vector<LLONG>> id6(LLONG z, Primes<LLONG> &primes) {
  vector<vector<LLONG>> res {};
  for (LLONG a = 0; a <= z/2; ++a) {
    for (auto pa: qpairs(a, primes)) {
      for (auto pb: qpairs(z - a, primes)) {
	if (pa[1] <= pb[0]) {
	  res.push_back(vector<LLONG> {pa[0], pa[1], pb[0], pb[1]});
	}
      }
    }
  }
  return res;
}


vector<vector<BIG>> id10(LLONG z, Primes<LLONG> &primes) {
  

  

  

  

  


  


  vector<vector<BIG>> res {};

  for (LLONG x0 = 1; x0*x0 <= z; ++x0) {
    for (LLONG x1 = 0; x0*x0 + x1*x1 <= z && x1 <= x0; ++x1) {
      for (auto p: qpairs(z - (x0*x0 + x1*x1), primes)) {
	if (p[0] <= x0) {
	for (LLONG s1 = 0; s1 < 2; ++s1) {
	  for (LLONG s2 = 0; s2 < 2; ++s2) {
	    for (LLONG s3 = 0; s3 < 2; ++s3) {
	      res.push_back( vector<BIG> {x0, (-1 + 2*s1)*x1, (-1+2*s2)*p[0], (-1+2*s3)*p[1]});
	      res.push_back( vector<BIG> {x0, (-1 + 2*s1)*x1, (-1+2*s2)*p[1], (-1+2*s3)*p[0]});
	    }
	  }
	}
	}
      }
    }
  }
  return res;
}

vector<vector<BIG>> id9(LLONG z, Primes<LLONG> &primes) {
  vector<vector<BIG>> res {};

  for (LLONG a0 = 0; a0*a0 <= z; ++a0) {
    for (auto p: qpairs( z - a0*a0, primes)) {
	for (LLONG s1 = 0; s1 < 2; ++s1) {
	  for (LLONG s2 = 0; s2 < 2; ++s2) {
	    for (LLONG s3 = 0; s3 < 2; ++s3) {
	      res.push_back( vector<BIG> {(-1 + 2*s1)*a0, (-1 + 2*s2)*p[0],  (-1 + 2*s3)*p[1]});
	      res.push_back( vector<BIG> {(-1 + 2*s1)*a0, (-1 + 2*s2)*p[1],  (-1 + 2*s3)*p[0]});
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
void id7(vector<vector<T>> &a, vector<vector<T>> &r, int i) {
  

  

  

    
  if (i >= a.size()) {
    return;
  } else {
    int n = r.size();
    int j = i;
    while (j < n && a[i][j] == 0) ++j;
    if (j == n) {
      a.erase(a.begin() + i);
      id7(a, r, i);
    } else {
      int j_ = j + 1;
      while (j_ < n && a[i][j_] == 0) ++j_;
      if (j_ == n) { 

	swap_columns(a, i, j);
	swap_columns(r, i, j);
	id7(a, r, i + 1);
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
	id7(a, r, i);
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







template <typename T>
vector<T> axv(const vector<T> &x, const vector<T> &v) {
  

  vector<T> res {};
  for (auto e: id4(x)) {
    res.push_back(dot(e, v));
  }
  return res;
}


template <typename T>
vector<T> cross(const vector<T> &a, const vector<T> &b)  {
  return vector<T> {  a[1]*b[2] - a[2]*b[1],
		        -a[0]*b[2] + a[2]*b[0],
			 a[0]*b[1] - a[1]*b[0]};
}

template <typename T>
vector<vector<T>> xlattice(const vector<T> &v, const vector<T> &u, T L) {
  

  if (dot(v,v) != L*L*dot(u,u)) {
    

    throw -1;
  } else {
    vector<BIG> b  = {v[0] + L*u[0],
			  v[1] + L*u[1],
			  v[2] + L*u[2]};
    vector<BIG> vminus = {v[0] - L*u[0],
			   v[1] - L*u[1],
			   v[2] - L*u[2]};
    vector<BIG> a = cross(vminus, b);

    BIG c = dot(b, b);

    int j = 0;
    while (j < 3 && b[j] == 0) ++j;
    if (j == 3) {
      return vector<vector<BIG>> {}; 

    } else {
      vector<vector<BIG>> eqs {};
      for (int i = 0; i < 3; ++i) {
	if (i != j) {
	  vector<BIG> eq(4);
	  eq[0] = a[i]*b[j]-a[j]*b[i];
	  eq[i+1] = -c*b[j];
	  eq[j+1] = c*b[i];
	  eqs.push_back(eq);
	}
      }
      vector<vector<BIG>> r = id<BIG>(4);
      id7(eqs, r, 0);
      int d = eqs.size();
      vector<vector<BIG>> res {};
      for (int i = d; i < 4; i++) {
	vector<BIG> temp(4);
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
    

    throw -1;
  }
}

vector<vector<BIG>> xgood(vector<vector<BIG>> &vs, vector<BIG> &x, BIG L) {

  vector<vector<BIG>> cur = {};
  bool OK = true;
  for (auto v: vs) {
    auto a = axv(x, v);
    

    

    if (!(a[0] % (L*L) == 0 && a[1] % (L*L) == 0 && a[2] % (L*L) == 0)) {
      OK = false;
      break;
    } else {
      auto a_ =  vector<BIG> {a[0] / (L*L), a[1] / (L*L), a[2] / (L*L)};
      cur.push_back(a_);
    }
  }
  if (OK) {
    return cur;
  } else {
    return vector<vector<BIG>> {};
  }
}
    




vector<vector<LLONG>> reduce2(const vector<vector<LLONG>> &basis_, const vector<LLONG> &v) {
  

  

  

  
  vector<vector<LLONG>> e = normalize2(basis_);

  if (e.size() == 1) {
    e.push_back(v);
    return normalize2(e);
  }
  else {
    LLONG original_norm = dot(e[0], e[0]) + dot(e[1], e[1]);
	
    BIG e00 = dot(e[0],e[0]);
    BIG e11 = dot(e[1],e[1]);
    BIG e01 = dot(e[0],e[1]);

    BIG det2 = e00*e11 - e01*e01;

    if (det2 == 0) {
      

      throw -1;
    }

    BIG v0 = dot(e[0], v);
    BIG v1 = dot(e[1], v);

    BIG nn0 =  (v0*e11 - v1*e01) / det2;
    BIG nn1 = (-v0*e01 + v1*e00) / det2;

    if (!(nn0 <= id3 && nn0 >= LLONG_MIN)) throw -1;
    if (!(nn1 <= id3 && nn1 >= LLONG_MIN)) throw -1;

    vector<LLONG> n = { (LLONG) nn0  ,(LLONG) nn1 };

    LLONG norm = id3;
    vector<LLONG> id13(v.size());
      
    for (int d0 = 0; d0 < 2; d0++) {
      for (int d1 = 0; d1 < 2; d1++) {
	vector<LLONG> n_ = { n[0] + sign(n[0]) * d0,
			    n[1] + sign(n[1]) * d1 };

	vector<LLONG> v_red = wsum(e, n_);

	add(v, BIG(-1), v_red);

	LLONG norm_cur = dot(v_red, v_red);
	if (norm_cur < norm) {
	  id13 = v_red;
	  norm = norm_cur;
	}
      }
    }

    if (norm == 0) {
      return e;
    } else {
      if (norm < e11) {
	return reduce2(vector<vector<LLONG>> {e[0],id13}, e[1]);
      } else {
	return vector<vector<LLONG>> {e[0],e[1],id13};
      }
    }
  }
}



vector<vector<LLONG>> reduce3(const vector<vector<LLONG>> &basis_, const vector<LLONG> &v_) {
  

  vector<vector<LLONG>> basis {};

  if (basis_.size() == 0) {
    return vector<vector<LLONG>> {v_};
  } else if (basis_.size() == 1) {
    return normalize2(vector<vector<LLONG>> {basis_[0], v_});
  } else if (basis_.size() == 2) {
    return reduce2(basis_, v_);
  } else if (basis_.size() == 3) {
    vector<vector<LLONG>> basis = reduce2(vector<vector<LLONG>> {basis_[0], basis_[1]} , basis_[2]);
    if (basis.size() != 3) {
      return reduce2(basis, v_);
    } else { 

      

      vector<BIG> v {};
      for (auto el: v_) v.push_back( (BIG) el);
      vector<vector<BIG>> e {};
      for (auto u: basis) {
	vector<BIG> u_ {};
	for (auto el: u) u_.push_back( (BIG) el);
	e.push_back(u_);
      }


      BIG det2 = e[0][2]*(-(e[1][1]*e[2][0]) + e[1][0]*e[2][1]) + e[0][1]*(e[1][2]*e[2][0] - e[1][0]*e[2][2]) + 
	e[0][0]*(-(e[1][2]*e[2][1]) + e[1][1]*e[2][2]);

      if (det2 == 0) {
	

	throw -1;
      }

      vector<BIG> b = {-(v[2]*e[1][1]*e[2][0]) + v[1]*e[1][2]*e[2][0] + v[2]*e[1][0]*e[2][1]
			    - v[0]*e[1][2]*e[2][1] - v[1]*e[1][0]*e[2][2] +  v[0]*e[1][1]*e[2][2],
			    v[2]*e[0][1]*e[2][0] - v[1]*e[0][2]*e[2][0] - v[2]*e[0][0]*e[2][1] +
			    v[0]*e[0][2]*e[2][1] +   v[1]*e[0][0]*e[2][2] - v[0]*e[0][1]*e[2][2],
			    -(v[2]*e[0][1]*e[1][0]) + v[1]*e[0][2]*e[1][0] + v[2]*e[0][0]*e[1][1] - 
			    v[0]*e[0][2]*e[1][1] - v[1]*e[0][0]*e[1][2] + v[0]*e[0][1]*e[1][2]};

      vector<LLONG> n = { LLONG (b[0] / det2),  LLONG (b[1] / det2),  LLONG  (b[2] / det2)};

      LLONG norm = id3;
      vector<LLONG> id13(v.size());

      for (int d0 = 0; d0 < 2; d0++) {
	for (int d1 = 0; d1 < 2; d1++) {
	  for (int d2 = 0; d2 < 2; d2++) {
	    vector<LLONG> n_ = { n[0] + sign(n[0]) * d0,
				    n[1] + sign(n[1]) * d1,
				    n[2] + sign(n[2]) * d2 };

	    vector<LLONG> v_red = wsum(basis, n_);
	    add(v_, BIG(-1), v_red);
	    LLONG norm_cur = dot(v_red, v_red);
	    if (norm_cur < norm) {
	      id13 = v_red;
	      norm = norm_cur;
	    }
	  }
	}
      }
      
      if (norm == 0) {
	return basis;
      } else {
	if (norm < dot(basis[2], basis[2])) {
	  return reduce3(vector<vector<LLONG>> {basis[0], basis[1], id13}, basis[2]);
	} else {
	  return basis;
	}
      }
    }
  } else {
    

    throw -1;
  }
}
    
    



vector<vector<LLONG>> id0(vector<vector<LLONG>> &data) {
  if (data.size() == 0) {
    

    throw -1;
  } else {
    vector<vector<LLONG>> basis {};

    int i = 0;

    while (i < min(int(data.size())-1,3))
      basis.push_back(data[i++]);


    while (i < data.size()) {
      basis = reduce3(basis, data[i++]);
    }
    return basis;
  }
}






  
int main() {
  Primes<BIG> primes(30000000);

  

  

  


  


  


  


  

  int n = 0;
  cin >> n;
  vector<vector<BIG>> data {};
  for (int i = 0; i < n; ++i) {
    vector<BIG> cur(3);
    for (int j = 0; j < 3; ++j) {
      long temp = 0;
      cin >> temp;
      cur[j] = BIG(temp);
    }
    data.push_back(cur);
  }
  

  
  


  auto basis =  id0(data);
  vector<vector<BIG>> vs {};

  for (auto e: basis) {
    vector<BIG> cur {};
    for (auto x: e) { cur.push_back(BIG(x));}
    vs.push_back(cur);
  }

  

  vector<BIG> bil {};
  for (int i = 0; i < vs.size(); ++i)
    for (int j = i; j < vs.size(); ++j)
      if (abs(dot(vs[i], vs[j])) != 0) {
	bil.push_back( abs(dot(vs[i], vs[j])));
      }
  if (bil.size() == 0) {
    throw invalid_argument("for zero lattice the result is not defined");
  }

  sort(bil.begin(), bil.end());

  

  
  vector<BIG> Ls {};
  auto fs = factors(bil[0], primes);
  

  vector<LLONG> Ls_raw = id12(fs , 1, 0);

  
  sort(Ls_raw.begin(), Ls_raw.end(),
       [](const BIG &a, const BIG &b) {return a>b;});
  for (auto L: Ls_raw) {
    int i = 1;
    while (i < bil.size() && bil[i] % (L*L) == 0) ++i;
    if (i == bil.size()) {
      Ls.push_back(L);
    }
  }
		   
  vector<vector<vector<BIG>>> id8 {};

  bool found = false;
  for (auto L: Ls) {
    if (found) { break; }
    if (L*L*L*L <= dot(vs[0], vs[0])) {
      

      for (auto x: id10(L, primes)) {
	auto cur = xgood(vs, x, L);
	if (cur.size() > 0) {
	  cur.push_back(x);
	  cur.push_back(vector<BIG> {L});
	  id8.push_back(cur);
	  found = true;
	  break;
	}
      }
    } else {
      BIG a2 = dot(vs[0], vs[0]) / (L*L);
      

      for (auto u: id9(a2, primes)) {
	

	if (found) { break; }
	auto res = xlattice(vs[0], u, L);
	

	res = normalize2(res);
	

	for (auto x: solutions(res, L)) {
	  

	  auto cur = xgood(vs, x, L);
	  if (cur.size() > 0) {
	    cur.push_back(x);
	    cur.push_back(vector<BIG> {L});
	    id8.push_back(cur);
	    found = true;
	    break;
	  }
	}
      }
    }
  }

  if (id8.size() != 1) {
    int temp  = 0;
    cout << 1/temp;
  }
  
  for (auto s: id8) {
    

    

    cout << PLONG((s[s.size()-1][0]*s[s.size()-1][0])) << "\n";
    print2(id4(s[s.size()-2]));
  }

}
