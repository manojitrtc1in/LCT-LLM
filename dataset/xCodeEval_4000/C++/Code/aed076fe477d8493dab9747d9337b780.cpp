#ifndef BIG_INT_H
#define BIG_INT_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>

using namespace std;
#define ll long long

class BigInt {
	std::string value; 

	bool isNeg; 


	static BigInt karatsuba_mul(const BigInt& a, const BigInt& b); 


public:
	BigInt(); 

	BigInt(long x); 

	BigInt(const std::string& value); 

	BigInt(const BigInt& bigInt); 


	const std::string& getValue() const; 


	const bool getIsNeg() const; 

	void setIsNeg(bool isNeg); 


	int sign() const; 

	const bool isEven() const; 


	BigInt abs() const; 

	BigInt pow(long n) const; 

	BigInt sqrt(long n = 2) const; 


	

	const bool operator==(const BigInt& bigInt) const;
	const bool operator!=(const BigInt& bigInt) const;

	const bool operator<(const BigInt& bigInt) const;
	const bool operator>(const BigInt& bigInt) const;
	const bool operator<=(const BigInt& bigInt) const;
	const bool operator>=(const BigInt& bigInt) const;

	

	BigInt& operator=(const BigInt& bigInt);

	

	BigInt operator+() const&&;
	BigInt operator-() const&&;

	

	BigInt operator+(const BigInt& bigInt) const;
	BigInt operator-(const BigInt& bigInt) const;
	BigInt operator*(const BigInt& bigInt) const;
	BigInt operator/(const BigInt& bigInt) const;
	BigInt operator%(const BigInt& bigInt) const;
	BigInt operator<<(size_t n) const;
	BigInt operator>>(size_t n) const;

	

	BigInt& operator+=(const BigInt& bigInt);
	BigInt& operator-=(const BigInt& bigInt);
	BigInt& operator*=(const BigInt& bigInt);
	BigInt& operator/=(const BigInt& bigInt);
	BigInt& operator%=(const BigInt& bigInt);
	BigInt& operator<<=(size_t n);
	BigInt& operator>>=(size_t n);

	

	BigInt& operator++(); 

	BigInt& operator--(); 


	

	BigInt operator++(int); 

	BigInt operator--(int); 



	friend std::ostream& operator<<(std::ostream& stream, const BigInt& bigInt); 

	friend std::istream& operator>>(std::istream& stream, BigInt& bigInt); 

};
#endif
BigInt::BigInt() {
	this->isNeg = false;
	this->value = "0";
}



BigInt::BigInt(long x) {
	this->isNeg = x < 0;
	this->value = std::to_string(isNeg ? -x : x);
}



BigInt::BigInt(const std::string& value) {
	if (!value.length()) {
		this->value = "0";
		isNeg = false;

		return;
	}

	isNeg = value[0] == '-';
	this->value = value.substr(isNeg);

	

	int count = 0;
	while (this->value[count] == '0' && this->value.length() - count > 1)
		count++;

	this->value = this->value.substr(count); 


	

	for (size_t i = 0; i < this->value.length(); i++)
		if (this->value[i] < '0' || this->value[i] > '9')
			throw std::string("BigInt(const string &value) - string contain incorrect characters: ") + this->value;
}



BigInt::BigInt(const BigInt& bigInt) {
	this->value = bigInt.getValue();
	this->isNeg = bigInt.getIsNeg();
}



const std::string& BigInt::getValue() const {
	return value;
}



const bool BigInt::getIsNeg() const {
	return isNeg;
}



void BigInt::setIsNeg(bool isNeg) {
	this->isNeg = isNeg;
}



int BigInt::sign() const {
	return (1 - 2 * isNeg) * (value != "0");
}



const bool BigInt::isEven() const {
	return (value[value.length() - 1] - '0') % 2 == 0;
}



BigInt BigInt::abs() const {
	return BigInt(value);
}



BigInt BigInt::pow(long n) const {
	if (!n)
		return 1;

	if (n & 1)
		return pow(n - 1) * *this;
	else {
		BigInt tmp = pow(n / 2);
		return tmp * tmp;
	}
}



BigInt BigInt::sqrt(long n) const {
	if (n < 2)
		throw std::string("BigInt::sqrt() - n must be 2 or more");

	if (isNeg && ((n & 1) == 0))
		throw std::string("BigInt::sqrt() - value must be positive");

	size_t length = (value.length() + 1) / 2;
	size_t index = 0;

	std::string v(length, '0');

	while (index < length) {
		v[index] = '9';

		while (BigInt(v).pow(n) > this->abs() && v[index] > '0')
			v[index]--;

		index++;
	}

	return isNeg ? std::string("-") + v : v;
}



const bool BigInt::operator==(const BigInt& bigInt) const {
	return (value == bigInt.getValue()) && (isNeg == bigInt.getIsNeg());
}



const bool BigInt::operator!=(const BigInt& bigInt) const {
	return !(*this == bigInt);
}



const bool BigInt::operator<(const BigInt& bigInt) const {
	std::string value2 = bigInt.getValue(); 

	size_t len1 = value.length(); 

	size_t len2 = value2.length(); 


	

	if (isNeg == bigInt.getIsNeg()) {
		

		if (len1 != len2)
			return (len1 < len2) ^ isNeg; 


		size_t i = 0;

		

		while (i < len1 && value[i] == value2[i])
			i++;

		

		return (i < len1) && ((value[i] < value2[i]) ^ isNeg);
	}

	return isNeg; 

}



const bool BigInt::operator>(const BigInt& bigInt) const {
	return !(*this < bigInt || *this == bigInt);
}



const bool BigInt::operator<=(const BigInt& bigInt) const {
	return *this < bigInt || *this == bigInt;
}



const bool BigInt::operator>=(const BigInt& bigInt) const {
	return *this > bigInt || *this == bigInt;
}



BigInt& BigInt::operator=(const BigInt& bigInt) {
	value = bigInt.getValue();
	isNeg = bigInt.getIsNeg();

	return *this;
}



BigInt BigInt::operator-() const&& {
	return BigInt(isNeg ? value : std::string("-") + value);
}



BigInt BigInt::operator+() const&& {
	return BigInt(*this);
}



BigInt BigInt::karatsuba_mul(const BigInt& a, const BigInt& b) {
	std::string v1 = a.getValue();
	std::string v2 = b.getValue();

	size_t len1 = v1.length();
	size_t len2 = v2.length();
	size_t len = std::max(len1, len2);

	if (len1 + len2 < 9)
		return stol(a.getValue()) * stol(b.getValue());

	len += len % 2;
	size_t n = len / 2;

	BigInt Xr(len1 > n ? v1.substr(len1 - n, n) : v1);
	BigInt Xl(a >> n);
	BigInt Yr(len2 > n ? v2.substr(len2 - n, n) : v2);
	BigInt Yl(b >> n);

	BigInt P1 = karatsuba_mul(Xl, Yl);
	BigInt P2 = karatsuba_mul(Xr, Yr);
	BigInt P3 = karatsuba_mul(Xl + Xr, Yl + Yr);

	return (P1 << len) + ((P3 - P2 - P1) << n) + P2;
}




BigInt BigInt::operator+(const BigInt& bigInt) const {
	bool isAddOp = !(bigInt.getIsNeg() ^ isNeg); 


	if (isAddOp) {
		std::string num2 = bigInt.getValue(); 


		size_t len1 = value.length(); 

		size_t len2 = num2.length(); 

		size_t length = 1 + std::max(len1, len2);  


		char* res = new char[length + 1]; 


		res[length - 1] = res[length] = '\0';

		for (size_t i = 0; i < length - 1; i++) {
			int j = length - 1 - i;
			res[j] += ((i < len2) ? (num2[len2 - 1 - i] - '0') : 0) + ((i < len1) ? (value[len1 - 1 - i] - '0') : 0); 

			res[j - 1] = res[j] / 10; 

			res[j] = res[j] % 10 + '0'; 

		}

		res[0] += '0';

		return BigInt(isNeg ? std::string("-") + std::string(res) : std::string(res)); 

	}
	else
		return isNeg ? (bigInt - (-BigInt(*this))) : (*this - (-BigInt(bigInt))); 

}



BigInt BigInt::operator-(const BigInt& bigInt) const {
	if (*this == bigInt)
		return 0; 


	

	if (!isNeg && !bigInt.getIsNeg()) {
		std::string value2 = bigInt.getValue(); 


		size_t len1 = value.length(); 

		size_t len2 = value2.length(); 

		size_t length = std::max(len1, len2); 

		bool isNegRes = bigInt > * this; 


		int* a = new int[length], * b = new int[length]; 

		a[0] = b[0] = 0; 


		char* res = new char[length + 1]; 

		res[length - 1] = res[length] = '\0'; 


		int sign = (2 * isNegRes - 1); 


		for (size_t i = 0; i < length - 1; i++) {
			a[i] += (i < len1) ? (value[len1 - 1 - i] - '0') : 0; 

			b[i] += (i < len2) ? (value2[len2 - 1 - i] - '0') : 0; 


			b[i + 1] = -isNegRes; 

			a[i + 1] = isNegRes - 1; 


			res[length - 1 - i] += 10 + sign * (b[i] - a[i]);
			res[length - 1 - i - 1] = res[length - 1 - i] / 10;
			res[length - 1 - i] = res[length - 1 - i] % 10 + '0';
		}

		

		a[length - 1] += (length - 1 < len1) * (value[0] - '0');
		b[length - 1] += (length - 1 < len2) * (value2[0] - '0');

		

		res[0] += sign * (b[length - 1] - a[length - 1]) + '0';

		return BigInt(isNegRes ? std::string("-") + std::string(res) : std::string(res)); 

	}
	else 

		return isNeg && bigInt.getIsNeg() ? (-BigInt(bigInt) - (-BigInt(*this))) : (*this + -BigInt(bigInt));
}



BigInt BigInt::operator*(const BigInt& bigInt) const {
	if (value == "0" || bigInt.getValue() == "0")
		return 0; 


	std::string value2 = bigInt.getValue(); 


	size_t len1 = value.length(); 

	size_t len2 = value2.length(); 

	size_t length = len1 + len2 + 1; 

	bool isNegRes = isNeg ^ bigInt.getIsNeg(); 


	if (length < 10) { 

		long res = stol(value) * stol(value2);
		return BigInt(isNegRes ? -res : res);
	}
	else if (length < 2000) { 

		int* a = new int[length], * b = new int[length]; 


		char* res = new char[length + 1];; 

		res[length] = '\0'; 


		

		for (size_t i = 0; i < length; i++) {
			a[i] = (i < len1) ? (value[len1 - 1 - i] - '0') : 0;
			b[i] = (i < len2) ? (value2[len2 - 1 - i] - '0') : 0;
			res[i] = 0;
		}

		

		for (size_t i = 0; i < len1; i++) {
			for (size_t j = 0; j < len2; j++) {
				res[length - 1 - (i + j)] += a[i] * b[j];
				res[length - 1 - (i + j + 1)] += res[length - 1 - (i + j)] / 10;
				res[length - 1 - (i + j)] %= 10;
			}
		}

		

		for (size_t i = 0; i < length; i++)
			res[length - 1 - i] += '0';

		return BigInt(isNegRes ? std::string("-") + std::string(res) : std::string(res)); 

	}
	else { 

		BigInt res = karatsuba_mul(*this, bigInt);
		return isNegRes ? -BigInt(res) : res;
	}
}



BigInt BigInt::operator/(const BigInt& bigInt) const {
	std::string value1 = value;
	std::string value2 = bigInt.getValue(); 


	if (value2[0] == '0')
		throw std::string("Division by zero!"); 


	if (value[0] == '0')
		return 0; 


	if (value2 == "1")
		return BigInt(bigInt.getIsNeg() ? -BigInt(*this) : *this); 


	size_t zeroes = 0;
	while (value2[value2.length() - 1 - zeroes] == '0')
		zeroes++;

	if (zeroes >= value.length())
		return 0;

	

	if (zeroes) {
		value1 = value1.substr(0, value1.length() - zeroes);
		value2 = value2.substr(0, value2.length() - zeroes);
	}

	bool isNegRes = isNeg ^ bigInt.getIsNeg(); 


	BigInt tmp(value2);

	size_t divider_length = value2.length(); 

	long divider_v = divider_length > 8 ? 0 : atol(value2.c_str()); 


	size_t length = value1.length(); 

	size_t index = 0; 


	std::string div; 

	std::string v; 


	

	while (BigInt(v) < tmp && index < length)
		v += value1[index++];

	do {
		int count = 0; 


		

		if (BigInt(v) >= tmp) {
			if (divider_length > 8) { 

				BigInt mod = v;

				while (mod >= tmp) {
					mod -= tmp;
					count++;
				}

				v = mod.getValue();
			}
			else {
				long mod = stol(v);
				count = mod / divider_v;
				v = std::to_string(mod % divider_v);
			}
		}

		div += count + '0'; 


		if (index <= length)
			v += value1[index++]; 

	} while (index <= length);

	return BigInt(isNegRes && div != "0" ? std::string("-") + div : div); 

}



BigInt BigInt::operator%(const BigInt& bigInt) const {
	std::string value2 = bigInt.getValue();

	if (value2[0] == '0')
		throw std::string("Division by zero!");

	if (value[0] == '0' || value2 == "1")
		return 0;

	if (value.length() < 9 && value2.length() < 9) {
		long res = stol(value) % stol(value2);
		return isNeg ? -res : res;
	}

	BigInt tmp(value2);

	size_t divider_length = value2.length(); 

	long divider_v = divider_length >= 9 ? 0 : atol(value2.c_str()); 


	size_t length = value.length();
	size_t index = 0;
	BigInt mod2 = value;
	std::string v;

	while (BigInt(v) < tmp && index < length)
		v += value[index++];

	do {
		if (BigInt(v) >= tmp) {
			if (divider_v)
				v = std::to_string(stol(v) % divider_v);
			else {
				BigInt mod = v;

				while (mod >= tmp)
					mod -= tmp;

				v = mod.getValue();
			}
		}

		if (index <= length) {
			mod2 = v;
			v += value[index++];
		}
	} while (index <= length);

	if (mod2.getValue() == "0")
		return 0;

	return isNeg ? -BigInt(mod2) : mod2;
}

BigInt BigInt::operator<<(size_t n) const {
	return BigInt(std::string(isNeg ? "-" : "") + value + std::string(n, '0'));
}

BigInt BigInt::operator>>(size_t n) const {
	if (n >= value.length())
		return 0;

	return BigInt(std::string(isNeg ? "-" : "") + value.substr(0, value.length() - n));
}



BigInt& BigInt::operator+=(const BigInt& bigInt) {
	return *this = *this + bigInt;
}



BigInt& BigInt::operator-=(const BigInt& bigInt) {
	return *this = *this - bigInt;
}



BigInt& BigInt::operator*=(const BigInt& bigInt) {
	return *this = *this * bigInt;
}



BigInt& BigInt::operator/=(const BigInt& bigInt) {
	return *this = *this / bigInt;
}



BigInt& BigInt::operator%=(const BigInt& bigInt) {
	return *this = *this % bigInt;
}



BigInt& BigInt::operator<<=(size_t n) {
	return *this = *this << n;
}



BigInt& BigInt::operator>>=(size_t n) {
	return *this = *this >> n;
}



BigInt& BigInt::operator++() {
	return *this = *this + 1;
}



BigInt& BigInt::operator--() {
	return *this = *this - 1;
}



BigInt BigInt::operator++(int) {
	BigInt res = *this;
	*this = *this + BigInt(1);

	return res;
}



BigInt BigInt::operator--(int) {
	BigInt res = *this;
	*this = *this - BigInt(1);

	return res;
}



std::ostream& operator<<(std::ostream& stream, const BigInt& bigInt) {
	if (bigInt.getIsNeg())
		stream << "-";

	return stream << bigInt.getValue();
}



std::istream& operator>>(std::istream& stream, BigInt& bigInt) {
	std::string value;
	stream >> value;
	bigInt = BigInt(value);

	return stream;
}
int main()
{
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        int n;
        cin >> n;
        ll a;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (a == 1)
                cnt1++;
            else if (a == 0)
                cnt2++;
        }
		BigInt res = 1;
		while (cnt2 > 0) {
			res = res * 2;
			cnt2--;
		}
		res = res * cnt1;
		cout << res << endl;
    }
    return 0;
}