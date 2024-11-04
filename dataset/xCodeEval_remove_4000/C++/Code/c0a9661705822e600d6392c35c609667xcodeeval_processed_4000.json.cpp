







using namespace std;



class Bint
{
public:
	Bint(): s(0), n() {}
	Bint(const std::string&);
	Bint(long long);

	Bint(const Bint& b): s(b.s), n(b.n) {}
	const Bint& operator=(const Bint& b) {s = b.s; n = b.n; return *this;}


	Bint(Bint&& b): s {b.s}, n {std::move(b.n)} {}
	const Bint& operator=(Bint&& b) {s = b.s; std::swap(n, b.n); return *this;}


	Bint operator+(const Bint& b) const;
	Bint operator-(const Bint& b) const {return *this + (-b);}
	Bint operator-()              const {return Bint(-s, n);}
	Bint operator*(const Bint& b) const;
	Bint operator/(const Bint& b) const;
	Bint operator%(const Bint& b) const;

	bool operator==(const Bint& b) const {return s == b.s && n == b.n;}
	bool operator!=(const Bint& b) const {return !(*this == b);}
	bool operator< (const Bint& b) const;
	bool operator<=(const Bint& b) const {return *this == b || *this < b;}
	bool operator> (const Bint& b) const {return !(*this <= b);}
	bool operator>=(const Bint& b) const {return !(*this < b);}

	const Bint& operator+=(const Bint& b) {*this = *this + b; return *this;}
	const Bint& operator-=(const Bint& b) {*this = *this - b; return *this;}
	const Bint& operator*=(const Bint& b) {*this = *this * b; return *this;}
	const Bint& operator/=(const Bint& b) {*this = *this / b; return *this;}
	const Bint& operator%=(const Bint& b) {*this = *this % b; return *this;}

	Bint& operator++()    {*this += 1; return *this;}
	Bint& operator--()    {*this -= 1; return *this;}
	Bint  operator++(int) {Bint t(*this); *this += 1; return t;}
	Bint  operator--(int) {Bint t(*this); *this -= 1; return t;}

	friend std::ostream& operator<<(std::ostream&, const Bint&);

	long long  toLong()         const;
	Bint       Bpow(int pot)    const;
	size_t     id5() const {return n.size();}
	long long  id3()    const;
	Bint       abs()            const {return Bint(s != 0, n);}
	Bint       reverse()        const {std::string t; t.assign(n.rbegin(), n.rend()); return Bint(s, t);}
	bool       isPalindrome()   const {return *this == this->reverse();}
	bool       isEven()         const {return (n[0] - '0') % 2 == 0;}
	bool       isOdd()          const {return (n[0] - '0') % 2 == 1;}
	Bint       factorial()      const;
	bool       isPrime()        const;

private:
	int s;         

	std::string n; 


	Bint(int i, const std::string& str): s(i), n(str) {};
};

std::istream& operator>>(std::istream&, Bint&);

inline long long  toLong(const Bint& b)         {return b.toLong();}
inline Bint       Bpow(const Bint& b, int p)    {return b.Bpow(p);}
inline size_t     id5(const Bint& b) {return b.id5();}
inline long long  id3(const Bint& b)    {return b.id3();}
inline Bint       abs(const Bint& b)            {return b.abs();}
inline Bint       reverse(const Bint& b)        {return b.reverse();}
inline bool       isPalindrome(const Bint& b)   {return b.isPalindrome();}
inline bool       isEven(const Bint& b)         {return b.isEven();}
inline bool       isOdd(const Bint& b)          {return b.isOdd();}
inline Bint       factorial(const Bint& b)      {return b.factorial();}
inline bool       isPrime(const Bint& b)        {return b.isPrime();}

static bool lt(const string& n1, const string& n2)
{
	if (n1.size() < n2.size()) return true;
	if (n1.size() > n2.size()) return false;
	if (n1.size() == 0) return false;

	for (int i = n1.size() - 1; i >= 0; --i)
	{
		if (n1[i] < n2[i]) return true;
		if (n1[i] > n2[i]) return false;
	}

	return false;
}

static string id4(long long a)
{
	string n;

	if (a <= 9999999999) n.reserve(10);
	else              n.reserve(20);

	while (a) {n += a % 10 + '0'; a /= 10;}

	return n;
}

static const string maxlong = id4(std::numeric_limits<long long>::max() - 1);
static const int id2 = maxlong.size();

static long long id7(const string& n)
{
	if (lt(maxlong, n))
	{cerr << "Can't be expressed as long long: " << n << endl; exit(1);}

	long long res = 0, p = 1;
	for (size_t i = 0; i < n.size(); i++) {res += (n[i] - '0') * p; p *= 10;}

	return res;
}

static string add(const string& n1, const string& n2)
{
	const string& min = n1.size() < n2.size() ? n1 : n2;
	const string& max = n1.size() < n2.size() ? n2 : n1;

	int minsize = min.size();
	int maxsize = max.size();

	string res;
	res.reserve(maxsize + 1);

	int c = 0;
	for (int j = 0; j < minsize; ++j)
	{
		int s = c + max[j] + min[j] - 2 * '0';
		c = s / 10;
		res += '0' + s % 10;
	}
	for (int j = minsize; j < maxsize; ++j)
	{
		int s = c + max[j] - '0';
		c = s / 10;
		res += '0' + s % 10;
	}
	if (c) res += '0' + c;

	return res;
}

static string sub(const string& n1, const string& n2, bool id6)
{
	const string& min = id6 ? n1 : n2;
	const string& max = id6 ? n2 : n1;

	int minsize = min.size();
	int maxsize = max.size();

	string res;
	res.reserve(maxsize);

	int s, c = 0;
	for (int j = 0; j < minsize; ++j)
	{
		s = c + max[j] - min[j];
		if (s < 0) {c = -1; s += 10;}
		else    c = 0;
		res += '0' + s;
	}
	for (int j = minsize; j < maxsize; ++j)
	{
		s = c + max[j] - '0';
		if (s < 0) {c = -1; s += 10;}
		else    c = 0;
		res += '0' + s;
	}

	int ressize = res.size();
	int i = 0;
	while (res[ressize - 1 - i] == '0') ++i;
	if (i > 0) res.erase(ressize - i, i);

	return res;
}

static string mul(const string& n1, char n2, int p)
{
	int id1 = n1.size();

	string res;
	res.reserve(id1 + p + 1);

	while (p--) res += '0';

	int f = n2 - '0';
	int c = 0;
	for (int j = 0; j < id1; ++j)
	{
		int s = c + f * (n1[j] - '0');
		c = s / 10;
		res += '0' + s % 10;
	}
	if (c) res += '0' + c;

	return res;
}

Bint::Bint(const string& str) : s(1), n()
{
	string t(str);

	if (t[0] == '-') {s = -1; t.erase(0, 1);}

	int i = 0;
	while (t[i] == '0') ++i;
	if (i > 0) t.erase(0, i);

	if (t.size() == 0) {s = 0; return;}

	n.assign(t.rbegin(), t.rend()); 

}

Bint::Bint(long long a): s(0), n()
{
	if (a == 0) return;

	if (a < 0) {s = -1; a *= -1;}
	else    s = 1;

	n = id4(a);
}

Bint Bint::operator+(const Bint& b) const
{
	if (s == 0)   return b;
	if (b.s == 0) return *this;

	


	Bint sum;
	if (s == b.s)
	{
		sum.n = add(n, b.n);
		sum.s = s;
	}
	else
	{
		if (n == b.n) return 0;

		bool id0 = lt(n, b.n);
		sum.n = sub(n, b.n, id0);
		sum.s = id0 ? b.s : s;
	}

	return sum;
}

Bint Bint::operator*(const Bint& b) const
{
	if (s == 0 || b.s == 0) return 0;

	if (b.n == "1" || n == "1")
	{
		if (b == 1)      return  *this;
		if (b == -1)     return -*this;
		if (*this == 1)  return  b;
		if (*this == -1) return -b;
	}

	int maxLen = n.size() > b.n.size() ? n.size() : b.n.size();
	if (maxLen < id2 / 2) 

	{
		return s * id7(n) * b.s * id7(b.n);
	}
	else 

	{
		Bint res;
		if (s == b.s) res.s = 1;
		else       res.s = -1;

		res.n = mul(n, b.n[0], 0);

		int bnsize = b.n.size();
		for (int i = 1; i < bnsize; ++i) res.n = add(res.n, mul(n, b.n[i], i));

		return res;
	}
}

Bint Bint::operator/(const Bint& b) const
{
	if (b.s == 0) {cerr << "Division by zero error\n"; exit(1);}
	if (s == 0 || lt(n, b.n)) return 0;
	if (b.n == "1")
	{
		if (b.s == 1) return  *this;
		if (b.s == -1) return -*this;
	}

	if (lt(this->n, maxlong) && lt(b.n, maxlong)) 

	{
		return s * id7(n) / (b.s * id7(b.n));
	}
	else 

	{
		Bint bb = b.abs();
		vector<Bint> tab(11);
		for (int i = 0; i < 11; ++i) tab[i] = Bint(i) * bb;

		Bint ratio(0), resi(1, n.substr(n.size() - b.n.size(), b.n.size()));
		for (int i = n.size() - b.n.size(); i >= 0; --i)
		{
			int count = 0;
			while (tab[count] < resi) ++count;
			if (tab[count] != resi)   --count;

			ratio = ratio * Bint(10) + Bint(count);
			if (count) resi = resi - tab[count];

			if (i > 0) resi = resi * Bint(10) + Bint(n[i - 1] - '0');
		}

		if (s != b.s) ratio.s = -1;

		return ratio;
	}
}

Bint Bint::operator%(const Bint& b) const
{
	if (b.s == 0) {cerr << "Division by zero error\n"; exit(1);}
	if (s == 0 || lt(n, b.n)) return *this;
	if (b.n == "1")           return 0;

	if (lt(this->n, maxlong) && lt(b.n, maxlong)) 

	{
		return s * id7(n) % id7(b.n);
	}
	else 

	{
		Bint bb = b.abs();
		vector<Bint> tab(11);
		for (int i = 0; i < 11; ++i) tab[i] = Bint(i) * bb;

		Bint ratio(0), resi(1, n.substr(n.size() - b.n.size(), b.n.size()));
		for (int i = n.size() - b.n.size(); i >= 0; --i)
		{
			int count = 0;
			while (tab[count] < resi) ++count;
			if (tab[count] != resi)   --count;

			ratio = ratio * Bint(10) + Bint(count);
			if (count) resi = resi - tab[count];

			if (i > 0) resi = resi * Bint(10) + Bint(n[i - 1] - '0');
		}

		if (resi.s != 0) resi.s = s;

		return resi;
	}
}

bool Bint::operator<(const Bint& b) const
{
	if (s < b.s) return true;
	if (s == -1 && b.s == -1 && !lt(n, b.n) && n != b.n) return true;
	if (s == 1 && b.s == 1 && lt(n, b.n)) return true;
	return false;
}

ostream& operator<<(ostream& os, const Bint& b)
{
	if (b.s == 0) {os << "0"; return os;}
	if (b.s == -1) os << "-";
	string t; t.assign(b.n.rbegin(), b.n.rend());
	os << t;
	return os;
}

istream& operator>>(istream& is, Bint& b)
{
	string t; is >> t;
	b = Bint(t);
	return is;
}

long long Bint::toLong() const
{
	return s * id7(n);
}

Bint Bint::Bpow(int p) const
{
	if (p < 0) {cerr << "Negative power not implemented error: Bpow(" << *this << "," << p << ")\n"; exit(1);}
	if (p == 0)
	{
		if (*this == 0) {cerr << "Undefined Bpow(0,0) error\n"; exit(1);}
		else return 1;
	}
	if (*this == 1) return *this;

	int sign = 1;
	if (p % 2 == 1) sign = this->s;

	Bint res(*this), a(1);
	while (p != 1)
	{
		if (p % 2 == 0) {res *= res; p /= 2;} 

		else       {--p; a *= res;}  

	}
	res *= a;
	res.s = sign;

	return res;
}

long long Bint::id3() const
{
	int nsize = n.size();
	long long sum = 0;
	for (int i = 0; i < nsize; ++i) sum += n[i] - '0';
	return sum;
}

Bint Bint::factorial() const
{
	if (s <= 0) return 1;
	Bint fact(*this), i(1);
	for (; i != *this; ++i) fact *= i;
	return fact;
}

bool Bint::isPrime() const 

{
	if (*this <= 10)
	{
		if (*this <= 1) return false; 

		if (*this <= 3) return true; 

		if (*this == 5) return true; 

		if (*this == 7) return true; 

		return false;                

	}
	if (this->isEven())             return false; 

	if (this->id3() % 3 == 0) return false; 

	if (n[0] == '5')                return false; 


	if (lt(this->n, maxlong)) 

	{
		long long test = this->toLong();
		long long num = 7;
		int w = 4;
		while (num * num <= test)
		{
			if (test % num == 0) return false; 

			num += w;                     

			w = 6 - w;                    

		}
	}
	else 

	{


		Bint num(7);
		int w = 4;
		while (num * num <= *this)
		{
			if (num.n[0] != '5' &&         

			        *this % num == 0) return false; 

			num += w;                      

			w = 6 - w;                     

		}
	}

	return true;
}

int strlen(char* s) {
	int index = 0;
	while (s[index] != '\0') {
		index++;
	}

	return index;
}

int main() {
	char s[1000001];
	cin.getline(s,1000001);

	int size = strlen(s);

	int arr[size][2];
	int index = 0;
	int vForward = 0;

	for (int i = 0; i < size; i++) {
		if (i != size - 1 && s[i] == 'v' && s[i + 1] == 'v') {
			vForward++;
		}

		if (s[i] == 'o') {
			arr[index][0] = vForward;
			index++;
		}
	}

	int backIndex = index - 1;
	int vBackward = 0;

	for (int i = size - 1; i >= 0; i--) {
		if (i != 0 && s[i] == 'v' && s[i - 1] == 'v') {
			vBackward++;
		}

		if (s[i] == 'o') {
			arr[backIndex][1] = vBackward;
			backIndex--;
		}
	}

	Bint ans = Bint(0);
	for(int i = 0; i < index; i++) {
		ans = ans + Bint((long long int)arr[i][0]*(long long int)arr[i][1]);
	}

	cout << ans;

}