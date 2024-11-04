






using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

class BigInteger {
private:
    static const int base = 1e4;
    static const bool long_div  = false;
    static const bool long_mult = false;
    vector <long long> num = {0};
    char sign = 0;


    void update(bool lazy = false) {
        for (size_t i = 0; i < num.size(); ++i) {
            if (i+1 == num.size() && num[i] == -1) break;
            if (num[i] < 0) {
                if (i+1 == num.size()) num.push_back(0);
                int c = ((-num[i]) / base);
                if ((-num[i]) % base != 0) c++;
                num[i] += base * c;
                num[i+1] -= c;
            } else
            if (num[i] >= base) {
                if (i+1 == num.size()) num.push_back(0);
                num[i+1] += num[i] / base;
                num[i] %= base;
            } else {
                if (lazy) break;
            }
        }
        if (num.back() < 0) {
            sign = -sign;
            for (auto &i : num) i = -i;
            for (size_t i = 0; i+1 < num.size(); ++i) {
                if (num[i] < 0) {
                    num[i] += base;
                    num[i+1]--;
                }
            }
        }
        while (num.size() > 1 && num.back() == 0) num.pop_back();
        for (auto i : num) {
            assert(0 <= i && i < base);
        }
        if (num.size() == 1 && num.back() == 0) sign = 0;
    }

    void add(const BigInteger& x, int S, bool lazy = false) {
        if (sign == 0) {
            *this = x;
            sign *= S;
            return ;
        }
        if (x.num.size() > num.size()) {
            num.resize(x.num.size());
        }
        for (size_t i = 0; i < num.size() && i < x.num.size(); ++i) {
            num[i] += S * x.num[i];
        }
        update(lazy);
    }

    void div(BigInteger x, bool div) {
        if (sign == 0) {
            return ;
        }
        if (div) sign *= x.sign;
        x = x.abs();
        BigInteger cur, res;
        for (int i = num.size()-1; i >= 0; --i) {
            cur *= base, cur += num[i];
            if (cur < x) {
                res *= base;
                continue;
            }
            int l = 1, r = base - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (cur < x.abs() * mid) {
                    r = mid-1;
                } else {
                    l = mid;
                }
            }
            cur -= x * l;
            res *= base, res += l;
        }
        if (div) {
            res.sign = sign;
            res.update();
            this -> operator=(res);
        } else {
            cur.sign = sign;
            cur.update();
            this -> operator=(cur);
        }
    }
public:
    BigInteger() {
    }
    BigInteger(const int x) {
        num[0] = x;
        if (x != 0) sign = 1;
        update();
    }
    BigInteger(const size_t x) {
        num[0] = x % base;
        num.push_back(x / base);
        sign = 1;
        update();
    }
    BigInteger(const long long x) {
        if (x < 0) sign = -1;
        long long X = std::abs(x);
        while (X >= base) {
            num.back() = X % base;
            X /= base;
            num.push_back(0);
        }
        num.back() = X;
        update();
    }
    BigInteger(const unsigned long long x) {
        if (x != 0) sign = 1;
        unsigned long long X = x;
        while (X >= base) {
            num.back() = X % base;
            X /= base;
            num.push_back(0);
        }
        num.back() = X;
        update();
    }
    BigInteger& operator=(const int x) {
        num.resize(1);
        if (x != 0) sign = 1;
        num[0] = x;
        update();
        return *this;
    }

    explicit operator bool() const {
        return !(num.size() == 1 && num[0] == 0);
    }

    BigInteger abs() const {
        BigInteger copy = *this;
        if (copy < 0) copy *= -1;
        return copy;
    }

    bool operator== (const BigInteger& x) const {
        if (sign != x.sign || num.size() != x.num.size()) return false;
        for (size_t i = 0; i < num.size(); ++i) {
            if (num[i] != x.num[i]) return false;
        }
        return true;
    }
    bool operator!= (const BigInteger& x) const {
        return !(this -> operator==(x));
    }
    bool operator< (const BigInteger& x) const {
        if (sign < x.sign) return true;
        if (sign > x.sign) return false;
        if (sign == 0) return false;
        if (num.size() == x.num.size()) {
            for (int i = num.size()-1; i >= 0; --i) {
                if (num[i] != x.num[i]) {
                    return (num[i] < x.num[i]) ^ (sign == -1);
                    break;
                }
            }
            return false;
        } else {
            return (num.size() < x.num.size()) ^ (sign == -1);
        }
    }
    bool operator> (const BigInteger& x) const {
        return !(this -> operator<(x) || this -> operator==(x));
    }
    bool operator>= (const BigInteger& x) const {
        return !(this -> operator<(x));
    }
    bool operator<= (const BigInteger& x) const {
        return !(this -> operator>(x));
    }

    BigInteger& operator+= (const int x) {
        add(x, 1);
        return *this;
    }
    BigInteger& operator-= (const int x) {
        add(x, -1);
        return *this;
    }
    BigInteger& operator*= (const short x) {
        for (size_t i = 0; i < num.size(); ++i) {
            num[i] *= x;
        }
        update();
        return *this;
    }
    BigInteger& operator*= (const int x) {
        if (x <= 10000) {
            this -> operator*= (static_cast <short> (x));
        } else {
            this -> operator*= (BigInteger(x));
        }
        return *this;
    }
    BigInteger& operator/= (const int x) {
        assert(x != 0);
        div(x, true);
        return *this;
    }
    BigInteger& operator%= (const int x) {
        assert(x != 0);
        div(x, false);
        return *this;
    }
    BigInteger& operator+= (const BigInteger& x) {
        add(x, (sign == 0 || x.sign == sign ? 1 : -1));
        return *this;
    }
    BigInteger& operator-= (const BigInteger& x) {
        this -> operator+=(-x);
        return *this;
    }
    BigInteger& operator*= (BigInteger x) {

        if (long_mult) {
            BigInteger res = 0;
            sign *= x.sign;
            x = x.abs();
            for (int i = num.size()-1; i >= 0; --i) {
                res *= base;
                res += x * num[i];
            }
            res.sign = sign;
            *this = res;
        } else {
            assert(false);
        }

        return *this;
    }
    BigInteger& operator/= (const BigInteger& x) {
        assert(x != 0);
        if (long_div) {
            div(x, true);
        } else {
            assert(false);
        }
        return *this;
    }
    BigInteger& operator%= (const BigInteger& x) {
        assert(x != 0);
        BigInteger copy = *this;
        copy /= x;
        copy *= x;
        this -> operator-= (copy);
        return *this;
    }
    BigInteger& operator++() {
        add(1, sign >= 0 ? 1 : -1, true);
        return *this;
    }
    BigInteger& operator--() {
        add(1, sign >= 0 ? -1 : 1, true);
        return *this;
    }
    BigInteger operator++(int) {
        BigInteger copy = *this;
        add(1, sign >= 0 ? 1 : -1, true);
        return copy;
    }
    BigInteger operator--(int) {
        BigInteger copy = *this;
        add(1, sign >= 0 ? -1 : 1, true);
        return copy;
    }

    BigInteger operator- () const {
        BigInteger copy = *this;
        copy.sign *= -1;
        return copy;
    }
    BigInteger operator+ (const BigInteger& x) const {
        BigInteger copy = *this;
        copy += x;
        return copy;
    }
    BigInteger operator- (const BigInteger& x) const {
        BigInteger copy = *this;
        copy -= x;
        return copy;
    }
    BigInteger operator* (const BigInteger& x) const {
        BigInteger copy = *this;
        copy *= x;
        return copy;
    }
    BigInteger operator/ (const BigInteger& x) const {
        assert(x != 0);
        BigInteger copy = *this;
        copy /= x;
        return copy;
    }
    BigInteger operator% (const BigInteger& x) const {
        assert(x != 0);
        BigInteger copy = *this;
        copy %= x;
        return copy;
    }

    BigInteger operator+ (const int x) const {
        BigInteger copy = *this;
        copy += x;
        return copy;
    }
    BigInteger operator- (const int x) const {
        BigInteger copy = *this;
        copy -= x;
        return copy;
    }
    BigInteger operator* (const int x) const {
        BigInteger copy = *this;
        copy *= x;
        return copy;
    }
    BigInteger operator/ (const int x) const {
        assert(x != 0);
        BigInteger copy = *this;
        copy /= x;
        return copy;
    }
    BigInteger operator% (const int x) const {
        assert(x != 0);
        BigInteger copy = *this;
        copy %= x;
        return copy;
    }

    string toString() const {
        if (sign == 0) return "0";
        string s = "";
        if (sign == -1) s += "-";
        for (int i = num.size()-1; i >= 0; --i) {
            if (i != static_cast <int> (num.size())-1) {
                int t = base;
                while (t > 1) {
                    t /= 10;
                    if (num[i] < t) s += "0";
                }
            }
            if (num[i] != 0) s += std::to_string(num[i]);
        }
        return s;
    }

};

bool operator== (const int x, const BigInteger& y) {
    return BigInteger(x) == y;
}

BigInteger operator+ (const int x, const BigInteger& y) {
    BigInteger copy = y;
    copy += x;
    return copy;
}
BigInteger operator- (const int x, const BigInteger& y) {
    BigInteger copy = y;
    copy -= x;
    return copy;
}
BigInteger operator* (const int x, const BigInteger& y) {
    BigInteger copy = y;
    copy *= x;
    return copy;
}
BigInteger operator/ (const int x, const BigInteger& y) {
    assert(y != 0);
    BigInteger copy = x;
    copy /= y;
    return copy;
}
BigInteger operator% (const int x, const BigInteger& y) {
    assert(y != 0);
    BigInteger copy = x;
    copy %= y;
    return copy;
}

BigInteger gcd(BigInteger a, BigInteger b) {
    b = b.abs();
    while (a != 0 && b != 0) {
        a %= b;
        if (a != 0) b %= a;
    }
    if (a == 0) a = b;
    assert(a > 0);
    a = a.abs();
    return a;
}

ostream& operator<<(ostream& os, const BigInteger& x) {
    os << x.toString();
    return os;
}
istream& operator>>(istream& is, BigInteger& x)
{
    string s;
    is >> s;
    for (size_t i = (s[0] == '-' ? 1 : 0); i < s.size(); ++i) {
        x *= (10);
        x += (s[i]-'0');
    }
    if (s[0] == '-') x *= -1;
    return is;
}
void swap(BigInteger &a, BigInteger &b) {
    BigInteger c = a;
    a = b;
    b = c;
}
const BigInteger operator"" _bi(const unsigned long long x) {
    return BigInteger(x);
}



class Rational {
private:
    BigInteger p, q;

    void reduce() {
        BigInteger x = gcd(p, q);
        assert(x != 0);
        p /= x;
        q /= x;
    }
public:
    Rational() {
        p = 0;
        q = 1;
    }
    Rational(const int x) {
        p = x;
        q = 1;
    }
    Rational(const BigInteger& x) {
        p = x;
        q = 1;
    }

    string asDecimal(const size_t precision = 0) const {
        BigInteger res = p / q;
        BigInteger x = p % q, y = 1;
        for (size_t i = 0; i < precision+1; ++i) {
            x *= 10;
        }
        for (size_t i = 0; i+1 < precision+1; ++i) {
            y *= 10;
        }
        x /= q;
        if (x % 10 < 5)  x /= 10;
                    else x /= 10, ++x;
        if (x >= y) {
            x -= y;
            ++res;
        }
        if (precision == 0) return res.toString();
        string add = x.toString();
        string u = "";
        while (u.size() + add.size() < precision) {
            u += "0";
        }
        return res.toString() + "." + u + add;
    }

    explicit operator double() const {
        double x = 0.0;
        string t = asDecimal(30);
        size_t i, o = 0;
        for (i = 0; o < 30 && i < t.size() && t[i] != '.'; ++i, ++o) {
            x *= 10.0;
            x += t[i] - '0';
        }
        if (i < t.size()) {
            double e = 1.0;
            for (++i; o < 30 && i < t.size(); ++i, ++o) {
                e /= 10.0;
                x += e * (t[i] - '0');
            }
        }
        return x;
    }

    bool operator< (const Rational& x) const {
        return p*x.q < x.p*q;
    }
    bool operator== (const Rational& x) const {
        return p == x.p && q == x.q;
    }
    bool operator!= (const Rational& x) const {
        return !this -> operator==(x);
    }
    bool operator> (const Rational& x) const {
        return !(this -> operator<(x) || this -> operator==(x));
    }
    bool operator<= (const Rational& x) const {
        return !this -> operator>(x);
    }
    bool operator>= (const Rational& x) const {
        return !this -> operator<(x);
    }

    Rational operator- () const {
        Rational copy = *this;
        copy.p *= -1;
        return *this;
    }

    Rational& operator+= (const Rational& x) {
        p = p * x.q + x.p * q;
        q = q * x.q;
        reduce();
        return *this;
    }
    Rational& operator-= (const Rational& x) {
        this -> operator+ (-x);
        return *this;
    }
    Rational& operator*= (const Rational& x) {
        p = p * x.p;
        q = q * x.q;
        reduce();
        return *this;
    }
    Rational& operator/= (const Rational& x) {
        assert(x != 0);
        p = p * x.q;
        q = q * x.p;
        reduce();
        return *this;
    }

    Rational operator+ (const Rational& x) {
        Rational copy = *this;
        copy += x;
        return copy;
    }
    Rational operator- (const Rational& x) {
        Rational copy = *this;
        copy -= x;
        return copy;
    }
    Rational operator* (const Rational& x) {
        Rational copy = *this;
        copy *= x;
        return copy;
    }
    Rational operator/ (const Rational& x) {
        assert(x != 0);
        Rational copy = *this;
        copy /= x;
        return copy;
    }

    string toString() const {
        string res = q.toString();
        if (p != 1_bi) res += "/" + p.toString();
        return res;
    }
};
Rational operator+ (const int y, const Rational& x) {
    Rational copy = x;
    copy += y;
    return copy;
}
Rational operator- (const int y, const Rational& x) {
    Rational copy = -x;
    copy += y;
    return copy;
}
Rational operator* (const int y, const Rational& x) {
    Rational copy = x;
    copy *= y;
    return copy;
}
Rational operator/ (const int y, const Rational& x) {
    assert(x != 0);
    Rational copy = x;
    copy = 1 / copy;
    copy *= y;
    return copy;
}
 
class heap {
private:
	std::vector <BigInteger> a;
	
public:
	void add(BigInteger x) {
		int i = a.size();
		a.push_back(x);
		while (i > 1 && a[i] < a[i >> 1]) {
			std::swap(a[i], a[i >> 1]);
			i >>= 1;
		}
		

	}
	
	BigInteger top() {
		return a[1];
	}
	
	void get() {
		a[1] = a[a.size()-1];
		a.pop_back();
		int i = 1;
		BigInteger ok;
		do {
			ok = 0;
			if ((BigInteger) i*2+1 < (BigInteger) a.size()) {
				if (a[i*2] < a[i*2+1]) {
					if (a[i] > a[i*2]) {
						std::swap(a[i*2], a[i]);
						i = i * 2;
						ok = 1;
					}
				} else {
					if (a[i] > a[i*2+1]) {
						std::swap(a[i*2+1], a[i]);
						i = i * 2 + 1;
						ok = 1;
					}
				}
			} else
			if ((BigInteger) i*2 < (BigInteger) a.size()) {
				if (a[i*2] < a[i]) {
					std::swap(a[i*2], a[i]);
					i = i * 2;
					ok = 1;
				}
			}
		} while (ok != 0) ;
		

	}
	
	bool empty() {
		return (a.size() == 1);
	}
	
	void clear() {
		a.resize(1);
	}
};
 
int main() {
	heap id0;
	id0.clear();
	BigInteger n;
	std::cin >> n;
	for (; n > 0; n--) {
		BigInteger x;
		std::cin >> x;
		if (x != 0) id0.add(x);
	}
	BigInteger p = -100000000;
	BigInteger ans = 0;
	while (!id0.empty()) {
		if (p != id0.top()) ans++;
		p = id0.top();
		id0.get();
	}
	std::cout << ans << std::endl;
	return 0;
	
	std::string s;
	std::cin >> s;
	while (std::cin >> s) {
		BigInteger x;
		if (s == "0") {
			std::cin >> x;
			id0.add(x);
		} else
		if (s == "1") {
			if (id0.empty()) {
				std::cout << "CANNOT" << '\n';
			} else {
				std::cout << id0.top() << '\n';
				id0.get();
			}
		} else
		if (s == "CLEAR") {
			id0.clear();
		}
	}
}