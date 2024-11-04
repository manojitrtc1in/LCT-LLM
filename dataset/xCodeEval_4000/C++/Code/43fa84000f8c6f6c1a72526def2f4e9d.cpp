#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned ll
#define uint unsigned int
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvvpii vector<vvpii>
#define pllll pair<ll,ll>
#define vpllll vector<pllll>
#define vvpllll vector<vpllll>
#define vvvpllll vector<vvpllll>

#define FOR(i, l, r) for(int i = (l); i < (r); i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define din(type, ...) DELIGATE(COUNT(__VA_ARGS__))(type, __VA_ARGS__)

#define DELIGATE(n) CATENATE(n)
#define CATENATE(n) DIN ## n
#define COUNT(...) VALUES(__VA_ARGS__, 5, 4, 3, 2, 1)
#define VALUES(n1, n2, n3, n4, n5, n, ...) n
#define DIN1(type, name) type name; cin >> name;
#define DIN2(type, name, ...) type name; cin >> name; DIN1(type, __VA_ARGS__)
#define DIN3(type, name, ...) type name; cin >> name; DIN2(type, __VA_ARGS__)
#define DIN4(type, name, ...) type name; cin >> name; DIN3(type, __VA_ARGS__)
#define DIN5(type, name, ...) type name; cin >> name; DIN4(type, __VA_ARGS__)

#define count_leading_zeros __builtin_clz
#define count_leading_zeros_ll __builtin_clzll
#define count_trailing_zeros __builtin_ctz
#define count_trailing_zeros_ll __builtin_ctzll
#define count_ones __builtin_popcountll

using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

template<typename T, typename C> istream& operator>>(istream& is, pair<T, C> &p){is >> p.first >> p.second       ; return is;}
template<typename T, typename C> ostream& operator<<(ostream& os, pair<T, C>  p){os << p.first << " " << p.second; return os;}
template<typename T> istream& operator>>(istream& is, vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T> ostream& operator<<(ostream& os, vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T> istream& operator>>(istream& is, deque<T> &d){for (auto& i : d) is >> i;        return is;}
template<typename T> ostream& operator<<(ostream& os, deque<T>  d){for (auto& i : d) os << i << ' '; return os;}

const ll kMod = 998244353;
const ll kMax = 1e9;
const ll kMin = -1e9;

struct cmp {
  bool operator()(const pllll& lhs, const pllll& rhs) const {
    return lhs.first == rhs.first && lhs.second == rhs.second;
  }
};


namespace {
class BigInt{
    string digits;
public:
 
    

    BigInt(unsigned long long n = 0);
    BigInt(string &);
    BigInt(const char *);
    BigInt(BigInt &);
 
    

    friend void divide_by_2(BigInt &a);
    friend bool Null(const BigInt &);
    friend int Length(const BigInt &);
    int operator[](const int)const;
 
               
 
    

    BigInt &operator=(const BigInt &);
 
    

    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int temp);
 
    

    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);
 
    

    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);
 
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);
 
    

    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);
 
    

    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);
 
    

    friend BigInt &operator^=(BigInt &,const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);
     
    

    friend BigInt sqrt(BigInt &a);
 
    

    friend ostream &operator<<(ostream &,const BigInt &);
    friend istream &operator>>(istream &, BigInt &);
 
    

    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
};
 
BigInt::BigInt(string & s){
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr){
    do{
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char *s){
    digits = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt & a){
    digits = a.digits;
}
 
bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigInt & a){
    return a.digits.size();
}
int BigInt::operator[](const int index)const{
    if(digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigInt &a, const BigInt &b){
    return a.digits == b.digits;
}
bool operator!=(const BigInt & a,const BigInt &b){
    return !(a == b);
}
bool operator<(const BigInt&a,const BigInt&b){
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt&a,const BigInt&b){
    return b < a;
}
bool operator>=(const BigInt&a,const BigInt&b){
    return !(a < b);
}
bool operator<=(const BigInt&a,const BigInt&b){
    return !(a > b);
}
 
BigInt &BigInt::operator=(const BigInt &a){
    digits = a.digits;
    return *this;
}
 
BigInt &BigInt::operator++(){
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9;i++)
        digits[i] = 0;
    if(i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp){
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}
 
BigInt &BigInt::operator--(){
    if(digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n;i++)
        digits[i] = 9;
    digits[i]--;
    if(n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp){
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}
 
BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}
 
BigInt &operator-=(BigInt&a,const BigInt &b){
    if(a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}
 
BigInt &operator*=(BigInt &a, const BigInt &b)
{
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}
 
BigInt &operator/=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i]  < b;i--){
        t *= 10;
        t += a.digits[i] ;
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat;i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}
BigInt operator/(const BigInt &a,const BigInt &b){
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}
 
BigInt &operator%=(BigInt& a,const BigInt &b){
    if(Null(b))
        throw("Arithmetic Error: Division By 0");
    if(a < b){
        a = BigInt();
        return a;
    }
    if(a == b){
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b;i--){
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--){
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t;cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt &a,BigInt &b){
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}
 
BigInt &operator^=(BigInt & a,const BigInt & b){
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while(!Null(Exponent)){
        if(Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt operator^(BigInt & a,BigInt & b){
    BigInt temp(a);
    temp ^= b;
    return temp;
}
 
void divide_by_2(BigInt & a){
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0;i--){
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while(a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}
 
BigInt sqrt(BigInt & a){
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while(left <= right){
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if(prod <= a){
            v = mid;
            ++mid;
            left = mid;
        }
        else{
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}
 
BigInt NthCatalan(int n){
    BigInt a(1),b;
    for (int i = 2; i <= n;i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n;i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}
 
BigInt NthFibonacci(int n){
    BigInt a(1), b(1), c;
    if(!n)
        return c;
    n--;
    while(n--){
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}
 
BigInt Factorial(int n){
    BigInt f(1);
    for (int i = 2; i <= n;i++)
        f *= i;
    return f;
}
 
istream &operator>>(istream &in,BigInt&a){
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}
 
ostream &operator<<(ostream &out,const BigInt &a){
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}

}


BigInt base[61];
BigInt add[61];
void init() {
  base[0] = 1;
  for (int i = 2; i < 61; i+= 2) {
    base[i] = (base[i - 2] * (i - 1) * i / (i / 2) / (i / 2));
  }

  for (int i = 2; i < 61; i += 2) {
    add[i] = 1;
    for (int j = i / 2 + 1; j <= i; j++) {
      add[i] *= j;
      if ((j & 1) == 0) {
        add[i] /= (j / 2);
      }
    }
    for (int j = 1; j <= i / 4; j++) {
      add[i] /= j;
    }
  }
}


void solve() {
  din(int, n)

  BigInt add_num = add[n];
  BigInt alex("0"), boris("0");
  bool turn_alex = true;
  while (n > 0) {
    if (turn_alex) {
      alex += base[n - 2];
    } else {
      boris += base[n - 2];
    }
    turn_alex = !turn_alex;
    n -= 2;
  }

  add_num = (add_num - alex - boris - 1) / 2;
  BigInt mod((unsigned long long)kMod);
  alex = (alex + add_num);
  boris = (boris + add_num);
  if (alex > mod) alex %= mod;
  if (boris > mod) boris %= mod;

  cout << alex << " " << boris << " 1\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  

#endif

  init();

  din(int, tc)

  while (tc--) {
    solve();
  }
  
  return 0;
}