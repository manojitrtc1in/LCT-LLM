














using namespace std;
long long base = 10000000;
long long len = 7;
long long NumLen(long long a) {
	long long count = 0;
	if (a == 0)
		return 1;
	while (a > 0) {
		a /= 10;
		count++;
	}
	return count;
}

class BigInt;

BigInt id0(const string& l);
BigInt id0(const long long& l);
BigInt abs(const BigInt& a);

class BigInt {
public:
	bool negative = false;
	vector<long long>v;
	void Erase0() {
		vector<long long>&a = v;
		while (a.size() > 1 && a[a.size() - 1] == 0) {
			a.pop_back();
		}
	}
	BigInt EraseM()const {
		BigInt ans = *this;
		if (v.size() == 1 && v[0] == 0 && negative)
			ans.negative = false;
		return ans;
	}
	BigInt() {
		v.resize(1);
		v[0] = 0;
		negative = false;
	}
	BigInt(const long long& n) {
		(*this) = id0(n);
	}
	friend istream& operator>>(istream& in, BigInt& a) {
		a.v.clear();
		string s;
		in >> s;
		if (s[0] == '-') {
			a.negative = true;
			s.erase(s.begin());
		}
		for (int i = s.size() - 1; i >= 0; i -= len) {
			if (i >= len - 1) {
				a.v.push_back(stoll(s.substr(i - len + 1, len)));
			}
			else
			{
				a.v.push_back(stoll(s.substr(0, i + 1)));
			}
		}
		a.Erase0();
		return in;
	}
	friend ostream& operator<<(ostream& out, const BigInt& a) {
		if (a.negative) {
			out << '-';
		}
		for (int i = a.v.size() - 1; i >= 0; i--) {
			if (i < a.v.size() - 1) {
				for (int j = 0; j < len - NumLen(a.v[i]); j++) {
					out << 0;
				}
			}
			out << a.v[i];
		}
		return out;
	}
	bool operator>(const BigInt& b)const {
		if (v.size() > b.v.size())
			return true;
		if (v.size() < b.v.size())
			return false;
		if (negative&&b.negative) {
			BigInt a1 = *this;
			BigInt b1 = b;
			a1.negative = false;
			b1.negative = false;
			return b1 > a1;
		}
		if (negative) {
			return false;
		}
		if (b.negative) {
			return true;
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] > b.v[i])
				return true;
			if (v[i] < b.v[i])
				return false;
		}
		return false;
	}
	bool operator>(const long long& n)const {
		BigInt b;
		b.v.push_back(0);
		return *this > b + n;
	}
	bool operator==(const BigInt& b)const {
		return !(b > *this) && !(*this > b);
	}
	bool operator<(const BigInt& b)const {
		return (b > *this);
	}
	bool operator>=(const BigInt& b)const {
		return (*this > b) || (*this == b);
	}
	bool operator<=(const BigInt& b)const {
		return (*this < b) || (*this == b);
	}
	bool operator<(const long long& n)const {
		BigInt b;
		b = id0(n);
		return *this < b;
	}
	BigInt operator+(const long long& n)const {
		BigInt b;
		b = id0(n);
		b = b + *this;
		b.Erase0();
		return b;
	}
	BigInt operator+(const BigInt& b)const {
		if (negative && !b.negative) {
			BigInt temp = *this;
			temp.negative = false;
			return b - temp;
		}
		if (!negative&&b.negative) {
			BigInt temp = b;
			temp.negative = false;
			return *this - temp;
		}
		BigInt ans;
		if (negative) {
			ans.negative = true;
		}
		ans.v.resize(max(v.size(), b.v.size()) + 1);
		for (int i = 0; i < ans.v.size() - 1; i++) {
			if (i < v.size()) {
				ans.v[i] += v[i];
			}
			if (i < b.v.size()) {
				ans.v[i] += b.v[i];
			}
			ans.v[i + 1] = ans.v[i] / base;
			ans.v[i] %= base;
		}
		ans.Erase0();
		return ans.EraseM();
	}
	BigInt operator-(const BigInt& b)const {
		BigInt ans;
		BigInt first = *this;
		BigInt second = b;
		if (!negative && second.negative) {
			second.negative = false;
			return second + first;
		}
		if (negative && !second.negative) {
			second.negative = true;
			return first + second;
		}
		if (negative) {
			first.negative = false;
			second.negative = false;
			return second - first;
		}
		if (*this < b) {
			ans.negative = true;
			swap(first, second);
		}
		ans.v.resize(first.v.size());
		for (int i = 0; i < first.v.size(); i++) {
			ans.v[i] += first.v[i];
			if (i < second.v.size()) {
				ans.v[i] -= second.v[i];
			}
			if (ans.v[i] < 0) {
				ans.v[i + 1]--;
				ans.v[i] += base;
			}
		}
		ans.Erase0();
		return ans.EraseM();
	}
	BigInt operator*(const BigInt& b)const {
		BigInt ans;
		if (negative != b.negative) {
			ans.negative = true;
		}
		ans.v.resize(v.size() + b.v.size());
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < b.v.size(); j++) {
				ans.v[i + j] += v[i] * b.v[j];
			}
		}
		for (int i = 0; i < ans.v.size() - 1; i++) {
			ans.v[i + 1] += ans.v[i] / base;
			ans.v[i] %= base;
		}
		ans.Erase0();
		return ans.EraseM();
	}
	BigInt operator/(const long long& l)const {
		long long temp = 0;
		BigInt ans;
		long long n = l;
		if ((n < 0 && !(*this).negative) || (n > 0 && (*this).negative))
			ans.negative = true;
		n = abs(n);
		for (int i = v.size() - 1; i >= 0; i--) {
			temp *= base;
			temp += v[i];
			ans.v.push_back(temp / n);
			temp %= n;
		}
		reverse(ans.v.begin(), ans.v.end());
		ans.Erase0();
		return ans.EraseM();
	}
	long long operator%(const long long& n)const {
		long long temp = 0;
		for (int i = v.size() - 1; i >= 0; i--) {
			temp *= base;
			temp += v[i];
			temp %= n;
		}
		return temp;
	}
	BigInt operator/(const BigInt& c)const {
		BigInt left, right, middle;
		BigInt a = *this, b = c;
		if (negative != b.negative) {
			BigInt a1, b1;
			a1 = *this;
			a1.negative = false;
			b1 = b;
			b1.negative = false;
			BigInt ans = a1 / b1;
			ans.negative = true;
			return ans;
		}
		a.negative = false;
		b.negative = false;
		left.v.resize(1);
		left.v[0] = 0;
		right = a;
		right = right + 1LL;
		while (right - left > 1) {
			middle = (right + left) / 2;
			if (b*middle > a) {
				right = middle;
			}
			else
			{
				left = middle;
			}
		}
		if (left.v.size() == 1 && left.v[0] == 0 && left.negative)
			left.negative = false;
		return left.EraseM();
	}
	BigInt operator%(const BigInt& b)const {
		return (*this - *this / b * b).EraseM();
	}
	void operator=(const BigInt& b) {
		v.clear();
		v = b.v;
		negative = b.negative;
		if (v.size() == 1 && v[0] == 0 && negative)
			negative = false;
	}
	bool operator==(const long long& n)const {
		BigInt b;
		b = id0(n);
		return *this == b;
	}
	long long convertToLL() {
		long long n = 0;
		BigInt a = *this;
		for (int i = 0; i < a.v.size(); i++) {
			n += a.v[i] * pow(base, i);
		}
		return n;
	}
	BigInt BinPow(const long long& k)const {
		if (k == 0)
			return 1;
		BigInt n;
		n = *this;
		if (k == 1)
			return n;
		if (k % 2 == 0) {
			BigInt temp = n.BinPow(k / 2);
			return temp * temp;
		}
		if (k % 2 == 1) {
			BigInt temp = n.BinPow(k / 2);
			BigInt temp2 = temp * n;
			return temp2 * temp;
		}
	}
	BigInt BinPow(const BigInt& k)const {
		if (k == 0)
			return 1;
		BigInt temp;
		temp = k;
		long long n = temp.convertToLL();
		return (*this).BinPow(n);
	}
	BigInt Pow(long long k) {
		BigInt ans;
		ans.v[0] = 1;
		for (int i = 0; i < k; i++) {
			ans = ans * (*this);
		}
		return ans;
	}
	void operator=(const long long& n) {
		BigInt b;
		b = id0(n);
		*this = b;
	}
	BigInt operator-(const long long& n)const {
		BigInt b;
		b = id0(n);
		return *this - b;
	}
	BigInt operator*(const long long& n)const {
		BigInt a;
		a = id0(n);
		return a * (*this);
	}
	void operator++() {
		*this = *this + 1;
		return;
	}
	void operator--() {
		*this = *this - 1;
		return;
	}
	void operator+=(const BigInt& b) {
		(*this) = (*this) + b;
		return;
	}
	void operator-=(const BigInt& b) {
		(*this) = (*this) - b;
		return;
	}
	void operator*=(const BigInt& b) {
		(*this) = (*this) * b;
		return;
	}
	void operator/=(const BigInt& b) {
		(*this) = (*this) / b;
		return;
	}
	bool operator!=(const BigInt& b)const {
		return !(*this == b);
	}
	BigInt fact()const {
		BigInt a = *this;
		BigInt ans = 1;
		while (a > 1) {
			ans *= a;
			a = a - 1;
		}
		return ans;
	}
};
BigInt operator+(const long long& n, const BigInt& b) {
	return b + n;
}
BigInt operator-(const long long& n, const BigInt& b) {
	return (b - n)*-1;
}
BigInt operator*(const long long& n, const BigInt& b) {
	return b * n;
}
BigInt operator/(const long long& n, const BigInt& b) {
	BigInt temp;
	temp = id0(n);
	return temp / b;
}
bool operator==(const long long& n, const BigInt& b) {
	return (b == n);
}
bool operator!=(const long long& n, const BigInt& b) {
	return !(n == b);
}
string to_string(const BigInt &a) {
	string ans;
	if (a.negative) {
		ans += '-';
	}
	for (int i = a.v.size() - 1; i >= 0; i--) {
		if (i < a.v.size() - 1) {
			for (int j = 0; j < len - NumLen(a.v[i]); j++) {
				ans += '0';
			}
		}
		ans += to_string(a.v[i]);
	}
	return ans;
}
BigInt abs(const BigInt& a) {
	BigInt ans = a;
	ans.negative = false;
	return ans;
}
BigInt id0(const string& l) {
	BigInt a;
	string s = l;
	if (s[0] == '-') {
		a.negative = true;
		s.erase(s.begin());
	}
	for (int i = s.size() - 1; i >= 0; i -= len) {
		if (i >= len - 1) {
			a.v.push_back(stoll(s.substr(i - len + 1, len)));
		}
		else
		{
			a.v.push_back(stoll(s.substr(0, i + 1)));
		}
	}
	a.Erase0();
	return a;
}
BigInt id0(const long long& l) {
	string s = to_string(l);
	return id0(s);
}
BigInt BIpow(BigInt a, BigInt b) {
	return a.BinPow(b);
}
BigInt gcd(BigInt a, BigInt b) {
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	return gcd(a%b, b);
}
BigInt lcm(BigInt a, BigInt b) {
	return (a*b) / gcd(a, b);
}
int main() {
	int k;
	scanf("%d", &k);
	string s;
	cin >> s;
	if (k == 0) {
		int start = -1;
		long long temp1 = 0, temp2 = 0;
		int finish = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				finish = i;
				break;
			}
			temp2++;
		}
		if (finish == -1) {
			cout << ((long long)(s.size())*(long long)(s.size() + 1)) / 2;
			return 0;
		}
		long long ans = 0;
		while (1) {
			long long temp = finish - start - 1;
			ans += ((temp)*(temp + 1)) / 2;
			start = finish;
			bool flag = false;
			for (int i = start + 1; i <= s.size(); i++) {
				if (i == s.size()) {
					flag = true;
					finish = i;
					break;
				}
				if (s[i] == '1') {
					flag = true;
					finish = i;
					break;
				}
			}
			if (!flag)
				break;
		}
		cout << ans;
		return 0;
	}
	int count = 0;
	long long ans = 0;
	long long start = -1, finish = -1, s1 = 0, f1 = s.size() - 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			start = i;
			break;
		}
	}
	if (start == -1) {
		printf("0");
		return 0;
	}
	count = 1;
	if (count == k) {
		finish = start;
	}
	else {
		for (int i = start + 1; i < s.size(); i++) {
			if (s[i] == '1') {
				count++;
			}
			if (count == k) {
				finish = i;
				break;
			}
		}
	}
	if (finish == -1) {
		printf("0");
		return 0;
	}
	for (int i = finish + 1; i < s.size(); i++) {
		if (s[i] == '1') {
			f1 = i - 1;
			break;
		}
	}
	while (1) {
		ans += (start - s1 + 1)*(f1 - finish + 1);
		bool flag = false;
		for (int i = start + 1; i < s.size(); i++) {
			if (s[i] == '1') {
				flag = true;
				start = i;
				break;
			}
		}
		if (!flag)
			break;
		flag = false;
		for (int i = finish + 1; i < s.size(); i++) {
			if (s[i] == '1') {
				flag = true;
				finish = i;
				break;
			}
		}
		if (!flag)
			break;
		s1 = 0;
		for (int i = start - 1; i >= 0; i--) {
			if (s[i] == '1') {
				s1 = i + 1;
				break;
			}
		}
		f1 = s.size() - 1;
		for (int i = finish + 1; i < s.size(); i++) {
			if (s[i] == '1') {
				f1 = i - 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}