#include <bits/stdc++.h>
using namespace std;

class bigint {
  static const int base = 1000000000;
  static const int base_digits = 9;
  vector<int> a;
  int sign;
public:
  bigint() : sign(1) {}
  bigint(int x) {
    *this = x;
  }
  bigint(long long x) {
    *this = x;
  }
  bigint(const string &s) {
    *this = s;
  }
  bigint& operator = (int x) {
    return *this = (long long)x;
  }
  bigint& operator = (long long x) {
    sign = 1;
    a.clear();
    if(x < 0) sign = -1, x = -x;
    for(; x > 0; x /= base) {
      a.push_back(x % base);
    }
    return *this;
  }
  void trim() {
    while(!a.empty() && !a.back()) a.pop_back();
    if(a.empty()) sign = 1;
  }
  bigint& operator = (const string &s) {
    sign = 1;
    a.clear();
    int p;
    for(p = 0; p < (int)s.length() && (s[p] == '-' || s[p] == '+'); p++) {
      if(s[p] == '-') sign = -sign;
    }   
    for(int i = s.length() - 1; i >= p; i -= base_digits) {
      int x = 0;
      for(int j = max(p, i - base_digits + 1); j <= i; j++) {
        x = x * 10 + s[j] - '0';
      }
      a.push_back(x);
    }
    trim();
    return *this;
  }
  bigint& operator = (const bigint &b) {
    sign = b.sign;
    a = b.a;
    return *this;
  }
  bigint operator - () const {
    bigint res = *this;
    res.sign = -sign;
    return res;
  }
  bool operator < (int x) const {
    bigint b = x;
    return *this < b;
  }
  bool operator < (long long x) const {
    bigint b = x;
    return *this < b;
  }
  bool operator < (const bigint &b) const {
    if(sign != b.sign) return sign < b.sign;
    if(a.size() != b.a.size()) return a.size() * sign < b.a.size() * b.sign;
    for(int i = a.size() - 1; i >= 0; i--) {
      if(a[i] != b.a[i]) {
        return a[i] * sign < b.a[i] * sign;
      }
    }
    return false;
  }
  bool operator > (const bigint &b) const {
    return b < *this;
  }
  bool operator <= (const bigint &b) const {
    return !(b < *this);
  }
  bool operator >= (const bigint &b) const {
    return !(*this < b);
  }
  bool operator == (const bigint &b) const {
    return !(*this < b) && !(b < *this);
  }
  bool operator != (const bigint &b) const {
    return *this < b || b < *this;
  }
  bigint operator + (int x) const {
    bigint b = x;
    return *this + b;
  }
  bigint operator + (long long x) const {
    bigint b = x;
    return *this + b;
  }
  bigint operator + (const bigint &b) const {
    if(sign == b.sign) {
      bigint res = b;
      int sz = max(a.size(), b.a.size());
      for(int i = 0, carry = 0; i < sz || carry; i++) {
        if(i == (int)res.a.size()) res.a.push_back(0);
        res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
        carry = res.a[i] >= base;
        if(carry) res.a[i] -= base;
      }
      return res;
    }
    return *this - (-b);
  }
  bigint& operator += (int x) {
    return *this = *this + x;
  }
  bigint& operator += (long long x) {
    return *this = *this + x;
  }
  bigint& operator += (const bigint &b) {
    return *this = *this + b;
  }
  bigint operator - (int x) const {
    bigint b = x;
    return *this - b;
  }
  bigint operator - (long long x) const {
    bigint b = x;
    return *this - b;
  }
  bigint operator - (const bigint &b) const {
    if(sign == b.sign) {
      if(abs(*this) >= abs(b)) {
        bigint res = *this;
        for(int i = 0, carry = 0; i < (int)b.a.size() || carry; i++) {
          res.a[i] -= carry + (i < (int)b.a.size() ? b.a[i] : 0);
          carry = res.a[i] < 0;
          if(carry) res.a[i] += base;
        }
        res.trim();
        return res;
      }
      return -(b - *this);
    }
    return *this + (-b);
  }
  bigint& operator -= (int x) {
    return *this = *this - x;
  }
  bigint& operator -= (long long x) {
    return *this = *this - x;
  }
  bigint& operator -= (const bigint &b) {
    return *this = *this - b;
  }
  bigint operator * (int x) const {
    return *this * (long long)x;
  }
  bigint operator * (long long x) const {
    bigint res = *this;
    if(x < 0) res.sign = - res.sign, x = -x;
    for(int i = 0, carry = 0; i < (int)a.size() || carry; i++) {
      if(i == (int)a.size()) res.a.push_back(0);
      long long cur = res.a[i] * x + carry;
      carry = (int)(cur / base);
      res.a[i] = (int)(cur % base);
    }
    res.trim();
    return res;
  }
  static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for(int i = 1; i < (int)p.size(); i++) {
      p[i] = p[i - 1] * 10;
    }
    vector<int> res;
    long long cur = 0;
    int cur_digits = 0;
    for(int i = 0; i < (int)a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while(cur_digits >= new_digits) {
        res.push_back((int)(cur % p[new_digits]));
        cur /= p[new_digits];
        cur_digits -= new_digits;
      }
    }
    res.push_back((int)cur);
    while(!res.empty() && !res.back()) res.pop_back();
    return res;
  }
  static vector<long long> karatsuba_multiply(const vector<long long> &a, const vector<long long> &b) {
    int n = a.size();
    vector<long long> res(n + n);
    if(n <= 32) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    }
    int k = n >> 1;
    vector<long long> a1(a.begin(), a.begin() + k);
    vector<long long> a2(a.begin() + k, a.end());
    vector<long long> b1(b.begin(), b.begin() + k);
    vector<long long> b2(b.begin() + k, b.end());
    vector<long long> a1b1 = karatsuba_multiply(a1, b1);
    vector<long long> a2b2 = karatsuba_multiply(a2, b2);
    for(int i = 0; i < k; i++) {
      a2[i] += a1[i];
      b2[i] += b1[i];
    }
    vector<long long> r = karatsuba_multiply(a2, b2);
    for(int i = 0; i < (int)a1b1.size(); i++) {
      r[i] -= a1b1[i];
    }
    for(int i = 0; i < (int)a2b2.size(); i++) {
      r[i] -= a2b2[i];
    }
    for(int i = 0; i < (int)r.size(); i++) {
      res[i + k] += r[i];
    }
    for(int i = 0; i < (int)a1b1.size(); i++) {
      res[i] += a1b1[i];
    }
    for(int i = 0; i < (int)a2b2.size(); i++) {
      res[i + n] += a2b2[i];
    }
    return res;
  }
  static bigint karatsuba(const bigint &a1, const bigint &b1) {
    if(a1.size() <= 8 && b1.size() <= 8) {
      long long x = a1.to_longint(), y = b1.to_longint();
      bigint res = x * y;
      return res;
    }
    int sizea = a1.size(), sizeb = b1.size();
    int m = max(sizea, sizeb) / 2;
    string as = a1.to_string(), bs = b1.to_string();
    bigint a = as.substr(0, sizea - m);
    bigint b = as.substr(sizea - m);
    bigint c = bs.substr(0, sizeb - m);
    bigint d = bs.substr(sizeb - m);
    bigint z2 = karatsuba(a, c);
    bigint z0 = karatsuba(b, d);
    bigint z1 = karatsuba(a + b, c + d) - z0 - z2;
    string z2s = z2.to_string() + string(m * 2, '0');
    z2 = z2s;
    string z1s = z1.to_string() + string(m, '0');
    z1 = z1s;
    return z2 + z1 + z0;
  }
  bigint operator * (const bigint &x) const {
    vector<int> a6 = convert_base(a, base_digits, 6);
    vector<int> b6 = convert_base(x.a, base_digits, 6);
    vector<long long> a(a6.begin(), a6.end());
    vector<long long> b(b6.begin(), b6.end());
    while(a.size() < b.size()) a.push_back(0);
    while(a.size() > b.size()) b.push_back(0);
    while(a.size() & (a.size() - 1)) {
      a.push_back(0);
      b.push_back(0);
    }
    vector<long long> c = karatsuba_multiply(a, b);
    bigint res;
    for(int i = 0, carry = 0; i < (int)c.size(); i++) {
      long long cur = c[i] + carry;
      res.a.push_back((int)(cur % 1000000));
      carry = (int)(cur / 1000000);
    }
    res.a = convert_base(res.a, 6, base_digits);
    

    res.sign = sign * x.sign;
    res.trim();
    return res;
  }
  bigint& operator *= (int x) {
    return *this = *this * x;
  }
  bigint& operator *= (long long x) {
    return *this = *this * x;
  }
  bigint& operator *= (const bigint &b) {
    return *this = *this * b;
  }
  friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
    int norm = base / (b1.a.back() + 1);
    bigint a = abs(a1) * norm;
    bigint b = abs(b1) * norm;
    bigint q, r;
    q.a.resize(a.a.size());
    for(int i = a.a.size() - 1; i >= 0; i--) {
      r *= base;
      r += a.a[i];
      int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
      int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
      int d = ((long long)base * s1 + s2) / b.a.back();
      r -= b * d;
      while(r < 0) r += b, d--;
      q.a[i] = d;
    }
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }
  bigint operator / (int x) const {
    bigint res = *this;
    if(x < 0) res.sign = - res.sign, x = -x;
    for(int i = (int)a.size() - 1, rem = 0; i >= 0; i--) {
      long long cur = res.a[i] + rem * (long long)base;
      res.a[i] = (int)(cur / x);
      rem = (int)(cur % x);
    }
    res.trim();
    return res;
  }
  bigint operator / (const bigint &b) const {
    return divmod(*this, b).first;
  }
  bigint& operator /= (const bigint &b) {
    return *this = *this / b;
  }
  int operator % (int x) {
    if(x < 0) x = -x;
    int m = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
      m = (a[i] + m * (long long)base) % x;
    }
    return m * sign;
  }
  bigint operator % (const bigint &b) const {
    return divmod(*this, b).second;
  }
  int operator %= (int x) {
    return *this % x;
  }
  bigint& operator %= (const bigint &b) {
    return *this = *this % b;
  }
  bool is_zero() const {
    return a.empty() || (a.size() == 1 && !a.back());
  }
  int size() const {
    if(a.empty()) return 0;
    int res = (a.size() - 1) * base_digits;
    for(int x = a.back(); x; x /= 10) res++;
    return res;
  }
  long long to_longint() const {
    long long res = 0;
    for(int i = a.size() - 1; i >= 0; i--) {
      res = res * base + a[i];
    }
    return res * sign;
  }
  string to_string() const {
    stringstream ss;
    ss << *this;
    string s;
    ss >> s;
    return s;
  }
  friend bigint abs(const bigint &b) {
    bigint res = b;
    res.sign *= res.sign;
    return res;
  }
  friend bigint gcd(const bigint &a, const bigint &b) {
    return b.is_zero() ? a : gcd(b, a % b);
  }
  friend bigint sqrt(const bigint &a) {
    bigint g = string("1" + string(a.size() / 2, '0'));
    bigint gg = g * g;
    while(gg > a || a >= (gg + g * 2 + 1)) {
      g = (g + a / g) / 2;
      gg = g * g;
    }
    return g;
  }
  friend bigint pow(bigint &a, int n) {
    return pow(a, (long long)n);
  }
  friend bigint pow(bigint &a, long long n) {
    bigint res = 1;
    while(n) {
      if(n & 1) res *= a;
      a *= a, n >>= 1;
    }
    return res;
  }
  friend bigint pow(bigint &a, bigint &n) {
    bigint res = 1;
    while(!n.is_zero()) {
      if(n % 2) res *= a;
      a *= a, n /= 2;
    }
    return res;
  }
  friend istream& operator >> (istream &in, bigint &b) {
    string s;
    in >> s;
    b = s;
    return in;
  }
  friend ostream& operator << (ostream &out, const bigint &b) {
    if(b.sign == -1) out << '-';
    out << (b.a.empty() ? 0 : b.a.back());
    for(int i = b.a.size() - 2; i >= 0; i--) {
      out << setfill('0') << setw(base_digits) << b.a[i];
    }
    return out;
  }
};

int main() {
#ifdef LOCAL_DEFINE
  

  

  auto _start = chrono::high_resolution_clock::now();
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	bigint n, k;
	cin >> n >> k;
	if((k + 1) * k / 2 > n) {
		cout << "-1\n";
	} else {
		bigint kk = k * (k - 1) / 2;
		bigint ans = 1;
		for(bigint g = 2; g * g <= n; g += 1) {
			if(n % g.to_longint()) continue;
			bigint x = n / g - kk;
			if(x > k - 1) {
				ans = max(ans, g);
			}
			x = n / (n / g) - kk;
			if(x > k - 1) {
				ans = max(ans, n / g);
			}
		}
		for(long long i = 1; i < k.to_longint(); i++) {
			bigint res = ans * i;
			cout << res << ' ';
		}
		bigint x = n / ans - kk;
		cout << x * ans << '\n';
	}

#ifdef LOCAL_DEFINE
  auto _end = chrono::high_resolution_clock::now();
  cerr << "elapsed time: " << chrono::duration<double, milli>(_end - _start).count() << " ms\n";
#endif
	return 0;
}