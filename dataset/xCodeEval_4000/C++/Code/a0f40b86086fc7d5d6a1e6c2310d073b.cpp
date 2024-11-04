


#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>
#include <iomanip>
#include <limits>
#include <bitset>
#include <ostream>
#include <sstream>
#include <cassert>

using namespace std;






#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define cp(a,b)			((conj(a)*(b)).imag()) 

#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()
#define vi vector<int>


typedef long long ll;
typedef long double ld;

class big_integer {
    

    static const int BASE = 1000000000;

    

    std::vector<int> _digits;

    

    bool _is_negative;

    void _remove_leading_zeros();
    void _shift_right();

public:
    

    class divide_by_zero: public std::exception {  };

    big_integer();
    big_integer(std::string);
    big_integer(signed char);
    big_integer(unsigned char);
    big_integer(signed short);
    big_integer(unsigned short);
    big_integer(signed int);
    big_integer(unsigned int);
    big_integer(signed long);
    big_integer(unsigned long);
    big_integer(signed long long);
    big_integer(unsigned long long);

    friend std::ostream& operator <<(std::ostream&, const big_integer&);
    operator std::string() const;
    const big_integer operator +() const;
    const big_integer operator -() const;
    const big_integer operator ++();
    const big_integer operator ++(int);
    const big_integer operator --();
    const big_integer operator --(int);
    friend bool operator ==(const big_integer&, const big_integer&);
    friend bool operator <(const big_integer&, const big_integer&);
    friend bool operator !=(const big_integer&, const big_integer&);
    friend bool operator <=(const big_integer&, const big_integer&);
    friend bool operator >(const big_integer&, const big_integer&);
    friend bool operator >=(const big_integer&, const big_integer&);
    friend const big_integer operator +(big_integer, const big_integer&);
    big_integer& operator +=(const big_integer&);
    friend const big_integer operator -(big_integer, const big_integer&);
    big_integer& operator -=(const big_integer&);
    friend const big_integer operator *(const big_integer&, const big_integer&);
    big_integer& operator *=(const big_integer&);
    friend const big_integer operator /(const big_integer&, const big_integer&);
    big_integer& operator /=(const big_integer&);
    friend const big_integer operator %(const big_integer&, const big_integer&);
    big_integer& operator %=(const big_integer&);

    bool odd() const;
    bool even() const;
    const big_integer pow(big_integer) const;
};



big_integer::big_integer() {
    this->_is_negative = false;
}



big_integer::big_integer(std::string str) {
    if (str.size() == 0) {
        this->_is_negative = false;
    }
    else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->_is_negative = true;
        }
        else {
            this->_is_negative = false;
        }

        for (long long i = str.size(); i > 0; i -= 9) {
            if (i < 9)
                this->_digits.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->_digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }

        this->_remove_leading_zeros();
    }
}



void big_integer::_remove_leading_zeros() {
    while (this->_digits.size() > 1 && this->_digits.back() == 0) {
        this->_digits.pop_back();
    }

    if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}



std::ostream& operator <<(std::ostream& os, const big_integer& bi) {
    if (bi._digits.empty()) os << 0;
    else {
        if (bi._is_negative) os << '-';
        os << bi._digits.back();
        char old_fill = os.fill('0');
        for (long long i = static_cast<long long>(bi._digits.size()) - 2; i >= 0; --i) os << std::setw(9) << bi._digits[i];
        os.fill(old_fill);
    }

    return os;
}





bool operator ==(const big_integer& left, const big_integer& right) {
    if (left._is_negative != right._is_negative) return false;
    if (left._digits.empty()) {
        if (right._digits.empty() || (right._digits.size() == 1 && right._digits[0] == 0)) return true;
        else return false;
    }

    if (right._digits.empty()) {
        if (left._digits.size() == 1 && left._digits[0] == 0) return true;
        else return false;
    }

    if (left._digits.size() != right._digits.size()) return false;
    for (size_t i = 0; i < left._digits.size(); ++i) if (left._digits[i] != right._digits[i]) return false;

    return true;
}



const big_integer big_integer::operator +() const {
    return big_integer(*this);
}



const big_integer big_integer::operator -() const {
    big_integer copy(*this);
    copy._is_negative = !copy._is_negative;
    return copy;
}



bool operator <(const big_integer& left, const big_integer& right) {
    if (left == right) return false;
    if (left._is_negative) {
        if (right._is_negative) return ((-right) < (-left));
        else return true;
    }
    else if (right._is_negative) return false;
    else {
        if (left._digits.size() != right._digits.size()) {
            return left._digits.size() < right._digits.size();
        }
        else {
            for (long long i = left._digits.size() - 1; i >= 0; --i) {
                if (left._digits[i] != right._digits[i]) return left._digits[i] < right._digits[i];
            }

            return false;
        }
    }
}



bool operator !=(const big_integer& left, const big_integer& right) {
    return !(left == right);
}



bool operator <=(const big_integer& left, const big_integer& right) {
    return (left < right || left == right);
}



bool operator >(const big_integer& left, const big_integer& right) {
    return !(left <= right);
}



bool operator >=(const big_integer& left, const big_integer& right) {
    return !(left < right);
}



const big_integer operator +(big_integer left, const big_integer& right) {
    if (left._is_negative) {
        if (right._is_negative) return -(-left + (-right));
        else return right - (-left);
    }
    else if (right._is_negative) return left - (-right);
    int carry = 0;
    for (size_t i = 0; i < std::max(left._digits.size(), right._digits.size()) || carry != 0; ++i) {
        if (i == left._digits.size()) left._digits.push_back(0);
        left._digits[i] += carry + (i < right._digits.size() ? right._digits[i] : 0);
        carry = left._digits[i] >= big_integer::BASE;
        if (carry != 0) left._digits[i] -= big_integer::BASE;
    }

    return left;
}



big_integer& big_integer::operator +=(const big_integer& value) {
    return *this = (*this + value);
}



const big_integer big_integer::operator++() {
    return (*this += 1);
}



big_integer::operator std::string() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}



big_integer::big_integer(signed char c) {
    if (c < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(c));
}



big_integer::big_integer(unsigned char c) {
    this->_is_negative = false;
    this->_digits.push_back(c);
}



big_integer::big_integer(signed short s) {
    if (s < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(s));
}



big_integer::big_integer(unsigned short s) {
    this->_is_negative = false;
    this->_digits.push_back(s);
}



big_integer::big_integer(signed int i) {
    if (i < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(i) % big_integer::BASE);
    i /= big_integer::BASE;
    if (i != 0) this->_digits.push_back(std::abs(i));
}



big_integer::big_integer(unsigned int i) {
    this->_digits.push_back(i % big_integer::BASE);
    i /= big_integer::BASE;
    if (i != 0) this->_digits.push_back(i);
}



big_integer::big_integer(signed long l) {
    if (l < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(l) % big_integer::BASE);
    l /= big_integer::BASE;
    if (l != 0) this->_digits.push_back(std::abs(l));
}



big_integer::big_integer(unsigned long l) {
    this->_digits.push_back(l % big_integer::BASE);
    l /= big_integer::BASE;
    if (l != 0) this->_digits.push_back(l);
}



big_integer::big_integer(signed long long l) {
    if (l < 0) { this->_is_negative = true; l = -l; }
    else this->_is_negative = false;
    do {
        this->_digits.push_back(l % big_integer::BASE);
        l /= big_integer::BASE;
    } while (l != 0);
}



big_integer::big_integer(unsigned long long l) {
    this->_is_negative = false;
    do {
        this->_digits.push_back(l % big_integer::BASE);
        l /= big_integer::BASE;
    } while (l != 0);
}



const big_integer big_integer::operator ++(int) {
    *this += 1;
    return *this - 1;
}



const big_integer big_integer::operator --() {
    return *this -= 1;
}



const big_integer big_integer::operator --(int) {
    *this -= 1;
    return *this + 1;
}



const big_integer operator -(big_integer left, const big_integer& right) {
    if (right._is_negative) return left + (-right);
    else if (left._is_negative) return -(-left + right);
    else if (left < right) return -(right - left);
    int carry = 0;
    for (size_t i = 0; i < right._digits.size() || carry != 0; ++i) {
        left._digits[i] -= carry + (i < right._digits.size() ? right._digits[i] : 0);
        carry = left._digits[i] < 0;
        if (carry != 0) left._digits[i] += big_integer::BASE;
    }

    left._remove_leading_zeros();
    return left;
}



big_integer& big_integer::operator -=(const big_integer& value) {
    return *this = (*this - value);
}



const big_integer operator *(const big_integer& left, const big_integer& right) {
    big_integer result;
    result._digits.resize(left._digits.size() + right._digits.size());
    for (size_t i = 0; i < left._digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < right._digits.size() || carry != 0; ++j) {
            long long cur = result._digits[i + j] +
                            left._digits[i] * 1LL * (j < right._digits.size() ? right._digits[j] : 0) + carry;
            result._digits[i + j] = static_cast<int>(cur % big_integer::BASE);
            carry = static_cast<int>(cur / big_integer::BASE);
        }
    }

    result._is_negative = left._is_negative != right._is_negative;
    result._remove_leading_zeros();
    return result;
}



big_integer& big_integer::operator *=(const big_integer& value) {
    return *this = (*this * value);
}



void big_integer::_shift_right() {
    if (this->_digits.size() == 0) {
        this->_digits.push_back(0);
        return;
    }
    this->_digits.push_back(this->_digits[this->_digits.size() - 1]);
    for (size_t i = this->_digits.size() - 2; i > 0; --i) this->_digits[i] = this->_digits[i - 1];
    this->_digits[0] = 0;
}



const big_integer operator /(const big_integer& left, const big_integer& right) {
    if (right == 0) throw big_integer::divide_by_zero();
    big_integer b = right;
    b._is_negative = false;
    big_integer result, current;
    result._digits.resize(left._digits.size());
    for (long long i = static_cast<long long>(left._digits.size()) - 1; i >= 0; --i) {
        current._shift_right();
        current._digits[0] = left._digits[i];
        current._remove_leading_zeros();
        int x = 0, l = 0, r = big_integer::BASE;
        while (l <= r) {
            int m = (l + r) / 2;
            big_integer t = b * m;
            if (t <= current) {
                x = m;
                l = m + 1;
            }
            else r = m - 1;
        }

        result._digits[i] = x;
        current = current - b * x;
    }

    result._is_negative = left._is_negative != right._is_negative;
    result._remove_leading_zeros();
    return result;
}



big_integer& big_integer::operator /=(const big_integer& value) {
    return *this = (*this / value);
}



const big_integer operator %(const big_integer& left, const big_integer& right) {
    big_integer result = left - (left / right) * right;
    if (result._is_negative) result += right;
    return result;
}



big_integer& big_integer::operator %=(const big_integer& value) {
    return *this = (*this % value);
}



bool big_integer::odd() const {
    if (this->_digits.size() == 0) return false;
    return this->_digits[0] & 1;
}



bool big_integer::even() const {
    return !this->odd();
}



const big_integer big_integer::pow(big_integer n) const {
    big_integer a(*this), result(1);
    while (n != 0) {
        if (n.odd()) result *= a;
        a *= a;
        n /= 2;
    }

    return result;
}



const double PI = acos(-1);
const ll MOD = 1000000007;
const ll MOD2 = 1000000009;


const long long inf = INT64_MAX;
const int N = 150000+5000;
const double eps = 1e-18;




































































































































































int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


double euclid(int x1, int y1, int x2, int y2) {
    return sqrt(abs((x2-x1) * (x2-x1)) + abs((y2-y1) * (y2-y1)));
}

vector <bool> isPrime(N, true);

void sieveOfEratosthenes(int n)
{

    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
}

void sieve(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i*2; j <= n; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int countDivisors(int n){
    int ans = 1;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) ans += 2;
        if(i*i == n) ans--;
    }
    return ans;
}

typedef double T;
struct Vector {
    T x, y;
    Vector(T x=0, T y=0) : x(x), y(y) {}
    Vector(Vector a, Vector b) : x(b.x - a.x), y(b.y - a.y) {}

    Vector operator-(const Vector& a) const {
        return {x - a.x, y - a.y};
    }
    T len2() {
        return x*x + y*y;
    }
    T len() {
        return sqrt(len2());
    }
    

    

    T Dpr( const Vector& b) const {
        return x * b.x + y * b.y;
    }
    T Cpr(const Vector& b) const {
        return x*b.y - b.x*y;
    }
};




















































































































struct Queue {
    stack <int> st1, st2, st1_min, st2_min;
    void push(int x) {
        st1.push(x);
        if (st1_min.empty())
            st1_min.push(x);
        else
            st1_min.push(min(st1_min.top(), x));
    }
    void del_e() {
        if (st1_min.empty() && st2_min.empty()) return;
        if (!st2.empty()) {
            st2.pop();
            st2_min.pop();
            return;
        }
        while (!st1.empty()) {
            st2.push(st1.top());
            if (st2_min.empty())
                st2_min.push(st1.top());
            else
                st2_min.push(min(st2_min.top(), st1.top()));
            st1.pop();
            st1_min.pop();
        }
        st2.pop();
        st2_min.pop();
    }
    int get_min() {
        if (st1_min.empty() && st2_min.empty()) {
            return -1;
        } else if (st1_min.empty()) {
            return st2_min.top();
        } else if (st2_min.empty()) {
            return st1_min.top();
        } else {
            return min(st1_min.top(), st2_min.top());
        }
    }
};


ll binPow(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        if (n % 2 == 0) {
            ll a = binPow(x, n/2);
            return (a*a);
        } else {
            return ((binPow(x, n-1) * x));
        }
    }
}


void solve() {
    int n, m; cin >> n >> m;
    vector <int> a(n); 

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> cost(m); 

    for (int i = 0; i < m; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = cost[a[i]-1];
    }
    vector <int> ans(n);
    std::sort(a.rbegin(), a.rend());
    ll sum = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i] > cost[j]) {
            sum += cost[j];
            j++;
        } else {
            sum += a[i];
        }

    }
    cout << sum << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}
