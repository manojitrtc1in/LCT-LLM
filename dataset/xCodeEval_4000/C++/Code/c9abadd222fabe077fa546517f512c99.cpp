#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <numeric>
#include <cassert>
#include <random>
#include <stdarg.h>
#include <string.h>
#include <stack>
#include <string>
#include <map>
#include <stdio.h>
#include <fstream>
#include <limits.h>
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <functional>


#define int long long int


#define DEBUG
#define NULL 0

#include <iostream>
#include <vector>
using namespace std;


vector<int> indexOf(char* str, char* pattern)
{
	vector<int> v;
	int slen = strlen(str);
	int patlen = strlen(pattern);
	for(int i = 0; i<slen; i++) {
		bool match = true;
		for(int j = 0; j<patlen; j++) {
			if(str[i+j] != pattern[j]) {
				match = false;
			}
		}
		if(match) {
			v.push_back(i);
		}
	}
	return v;
}


int maxBorder(char* a)
{
	int len = strlen(a);

	char* pref = new char[len];
	char* suff = new char[len];

	int max = 0;

	for(int i = 0; i<len; i++) {
		copy(a, a+i, pref);
		pref[i] = '\0';

		copy(a+len-i, a+len, suff);
		suff[i] = '\0';

		if(!strcmp(pref, suff)) {
			max = strlen(pref);
		}
	}

	delete[] pref;
	delete[] suff;
	return max;
}

int* getBordersArray(char* str)
{
	int len = strlen(str);
	int* res = new int[len]();
	char* buf = new char[len];
	for(int i = 0; i<len; i++) {
		copy(str, str+i+1, buf);
		buf[i+1] = '\0';
		int max = maxBorder(buf);
		res[i] = max;
	}
	return res;
}

int* getBordersArrayDP(char* str)
{
	int len = strlen(str);
	int* dp = new int[len]();
	for(int i = 1; i<len; i++) {
		int index = dp[i-1];
		while(1) {
			if(str[index] == str[i]) {
				dp[i] = index + 1;
				break;
			}
			if(index > 0) {
				index = dp[index - 1];
			} else {
				break;
			}
		}
	}
	return dp;
}



ostream_iterator<int> oi(cout, " ");

class Pair;


class Item
{
	friend ostream &operator<< ( ostream & out, const Pair & c );
	friend istream &operator>> ( istream & out, Pair & c );

public:
	Item(string des) {
		description = des;
	}

	int keyF() {
		key = description.length();
		return key;
	}

	string toString() {
		return description;
	}

	int key;

	string description;
};

ostream & operator<<( ostream & out, const Item & c  )
{
	out << c.description;
	return out;
}

istream & operator>>( istream & in, Item & c  )
{
	in>>c.description;
	return in;
}


ostream & operator<<( ostream & out, pair<int, int>& c  )
{
	out << "<" <<c.first << ", ";
	out << c.second << ">" << endl;
	return out;
}

istream & operator>>( istream & in, pair<int, int>& c  )
{
	in>>c.first;
	in>>c.second;
	return in;
}


void print()
{
	std::cout << endl;
}


template<typename A>
void print(A value)
{
	std::cout << value;
}

template<typename A, typename B>
void print(A value1, B value2)
{
	cout << value1 << " " << value2;
}

template<typename A, typename B, typename C>
void print(A value1, B value2, C value3)
{
	cout << value1 << " " << value2 << " " << value3;
}

template<typename A, typename B, typename C, typename D>
void print(A value1, B value2, C value3, D value4)
{
	cout << value1 << " " << value2 << " " << value3 << " " << value4;
}



template<typename E>
E read()
{
	E value;
	cin >> value;
	return value;
}

string readString()
{
	char* s = new char[1000];
	fgets(s, 1000, stdin);
	return string(s);
}

template<typename A>
void println(A value)
{
	std::cout << value << endl;
}

template<typename A, typename B>
void println(A value1, B value2)
{
	cout << value1 << " " << value2 << endl;
}

template<typename A, typename B, typename C>
void println(A value1, B value2, C value3)
{
	cout << value1 << " " << value2 << " " << value3 << endl;
}

template<typename A, typename B, typename C, typename D>
void println(A value1, B value2, C value3, D value4)
{
	cout << value1 << " " << value2 << " " << value3 << " " << value4 << endl;
}



int randomint(int min, int max)
{
	if(max == min) {
		return max;
	}
	return rand()%(max-min+1)+min;
}


class Pair
{
	friend ostream &operator<< ( ostream & out, const Pair & c );
	friend istream &operator>> ( istream & out, Pair & c );

public:
	Pair(Item* p);
	int key;
	Item* value;
};

Pair::Pair(Item* b)
{
	key = b->key;
	value = b;
}

ostream & operator<<( ostream & out, const Pair& c  )
{
	out<< "(" << c.value->key << " -> " << (c.value->toString()) << ")";
	return out;
}


ostream & operator<<( ostream & out, string& c  )
{
	out << c.data() << endl;
	return out;
}


template<typename E>
class Array
{
public:
	int size;
	Array<E>(int _capacity) {
		capacity = _capacity;
		array = new E[capacity];
		size = capacity;
		for(int i =0; i<size; i++) {
			array[i] = NULL;
		}
	}

	void sort() {
		std::sort(&array[0], &array[size]);
	}


	Array() {
		capacity = 4;
		array = new E[capacity];
		size = 0;
	}

	Array(vector<E>& vect) {
		int _size = vect.size();
		capacity = _size*2;
		size = _size;
		array = new E[capacity];
		for(int i =0; i<size; i++) {
			array[i] = vect[i];
		}
	}

	Array(int minBound, int maxBound, int _size) {
		srand(_size);
		capacity = _size*2;
		size = _size;
		array = new E[capacity];
		for(int i = 0; i<size; i++) {
			array[i] = randomint(minBound, maxBound);
		}
	}

	void add(E item);
	int leftBinarySearch(E& item);
	int rightBinarySearch(E& item);
	pair<int, int> equalRange(E& item);
	bool binarySearch(E& item);
	E* begin();
	E* end();
	vector<E> toVector();
	void toString();
	E& operator[](int i);
	E& index(int i);
	E* array;
	void null(void) {
		for(int i =0; i<size; i++) {
			array[i] = NULL;
		}
	}
private:
	int capacity;
	void ensureCapacity(int cap);
};


template <typename E>
void Array<E>::ensureCapacity(int cap)
{
	capacity = capacity*2;
	E* newArray = new E[capacity];
	memcpy(newArray, array, sizeof(E)*size);
	delete[] array;
	array = newArray;
}

template <typename E>
void Array<E>::toString()
{
	int i = 0;
	E* begin = array;
	cout << "[";
	while(i<size) {
		if(i == size-1) {
			cout << *array;
		} else {
			cout << *array << " ";
		}
		array++;
		i++;
	}
	cout << "]";
	cout << endl;
	array = begin;
}

template <typename E>
void Array<E>::add(E item)
{
	if(capacity<size+1) {
		ensureCapacity(size+1);
	}
	array[size] = item;
	size++;
}


template <typename E>
E* Array<E>::begin()
{
	return array;
}

template <typename E>
E* Array<E>::end()
{
	return array + size;
}

template <typename E>
int Array<E>::leftBinarySearch(E& item)
{
	return lower_bound(array, array+size, item)-array;
}


template <typename E>
int Array<E>::rightBinarySearch(E& item)
{
	return upper_bound(array, array+size, item)-array;
}

template <typename E>
pair<int, int> Array<E>::equalRange(E& item)
{
	pair<int*, int*> p(0, 0);
	p = equal_range(array, array + size, item);
	return make_pair(p.first - array, p.second - array);
}


template <typename E>
bool Array<E>::binarySearch(E& item)
{
	return binary_search(array, array + size, item);
}

template <typename E>
vector<E> Array<E>::toVector()
{
	vector<E> res = vector<E>(size);
	for(int i =0; i<res.size(); i++) {
		res[i] = array[i];
	}
	return res;
}


template<typename T>
ostream & operator<<( ostream & out, Array<T>& c  )
{
	for(int i = 0; i<c.size; i++) {
		out << c[i] << " ";
	}
	return out;
}

ostream & operator<<( ostream & out, Array< pair<int, int> >& c  )
{
	for(int i = 0; i<c.size; i++) {
		out << c[i];
	}
	return out;
}

template<typename T>
istream & operator>>( istream & in, Array<T>& c  )
{
	for(int i = 0; i<c.size; i++) {
		in >> c[i];
	}
	return in;
}

ostream & operator<<( ostream & out, map<int, int>& c  )
{
	map<int, int>::iterator it = c.begin();
	while(it!=c.end()) {
		pair<int, int> entry = *it;
		out << entry;
		it++;
	}
	return out;
}


template <typename E>
E& Array<E>::operator[] (int i)
{
#ifdef DEBUG
	if(i<size && i>=0) {
		return array[i];
	} else {
		cout << "Array index out of bounds, index is " << i << ", size is " << size << endl;
		cout << "Array is " << endl;
		toString();
		assert(0);
	}
#endif

#ifndef DEBUG
	return array[i]
#endif
}

       template<typename E>
class Matrix
{
public:
	int rows;
	int columns;
	Array<E> array;

	E& get(int x, int y);
	void set(int x, int y, E& value);
	E& operator()(int x, int y);
	Matrix<E> transpose();

	pair<E*, E*> getRow(int y);

	Matrix<E>(int c, int r) {
		rows = r;
		columns = c;
		array = Array<E>(rows*columns);
		array.null();
	}

	void swap(Matrix<E>& other) {
		std::swap(array, other.array);
		std::swap(rows, other.rows);
		std::swap(columns, other.columns);
	}

	Matrix<E>(int _columns, int _rows, int minBound, int maxBound) {
		rows = _rows;
		columns = _columns;
		int size = _rows*_columns;
		array = Array<E>(minBound, maxBound, size);
	}

private:
};

template<typename E>
Matrix<E> Matrix<E>::transpose()
{
	Matrix<int> b(rows, columns);
	for(int x = 0; x<columns; x++) {
		for(int y = 0; y<rows; y++) {
			b(y, x) = array.array[x+y*columns];
		}
	}
	return b;
}

template <typename E>
E& Matrix<E>::operator()(int x, int y)
{
#ifdef DEBUG
	if(x>=columns || x<0) {
		cout << "x must be in range [0; " << columns - 1 << "], but it is " << x << endl;
		assert(0);
	}
	if(y>=rows || y<0) {
		cout << "y must be in range [0; " << rows - 1 << "], but it is " << y << endl;
		assert(0);
	}
	return array.array[x+y*columns];
#endif
#ifndef DEBUG
	return array.array[x+y*columns];
#endif
}



template<typename T>
istream & operator>>( istream & in, Matrix<T>& c  )
{
	for(int y = 0; y<c.rows; y++) {
		for(int x = 0; x<c.columns; x++) {
			in >> c(x, y);
		}
	}
	return in;
}


template<typename E>
pair<E*, E*> Matrix<E>::getRow(int y)
{
	E* f = array.array + y*columns;
	E* s = array.array + (y+1)*columns;
	pair<E*, E*> p(f, s);
	return p;
}


template<typename T>
ostream & operator<<( ostream & out, Matrix<T>& c  )
{
	for(size_t y = 0; y<c.rows; y++) {
		for(size_t x = 0; x<c.columns; x++) {
			out << c(x, y) << " ";
		}
		out << endl;
	}
}


int bpow(int a, int b)
{
	if(b == 0) {
		return 1;
	} else {
		if(b%2 == 0) {
			int half = bpow(a, b/2);
			return half*half;
		} else {
			return bpow(a, b-1)*a;
		}
	}
}

int fact(int n)
{
	if(n == 1) {
		return 1;
	} else {
		return n*fact(n-1);
	}
}

int gcd(int a, int b)
{
	if(!b) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

Array<pair<int, int> > factorize(int n)
{
	Array<pair<int, int> > res;
	for(int i = 2; i<sqrt((double)n)+1; i++) {
		if(n%i == 0) {
			pair<int, int> comp = make_pair(i, 1);
			n/=i;
			while(n%i == 0) {
				comp.second++;
				n/=i;
			}
			res.add(comp);
		}
	}

	if(n>1) {
		res.add(make_pair(n, 1));
	}
	return res;
}

int euler(int n)
{
	Array<pair<int, int> > fact = factorize(n);
	int res = 1;
	for(unsigned int i = 0; i<fact.size; i++) {
		int factor = pow((double)fact[i].first, (double)fact[i].second)-pow((double)fact[i].first, (double)fact[i].second-1);
		res*=factor;
	}
	return res;
}

int inversePrime(int a, int m)
{
	return bpow(a, m-2)%m;
}

int inverseCoprimes(int a, int m)
{
	return bpow(a, euler(m)-1)%m;
}

int inverse(int a, int m)
{
	if(gcd(a, m) == 1) {
		return inverseCoprimes(a, m);
	} else {
		assert(0);
		return -1;
	}
}

Array<int> enumerateDivisors(int n)
{
	Array<pair<int, int> > divs = factorize(n);
	vector<int> totals = vector<int>(divs.size+1);
	totals[0] = 1;
	for(unsigned int i = 1; i < divs.size+1; i++) {
		totals[i]=totals[i-1]*(divs[i-1].second+1);
	}

	Array<int> res;
	for(int i = 0; i<totals[totals.size()-1]; i++) {
		vector<int> values = vector<int>(divs.size);
		for(unsigned int j = 0; j<values.size(); j++) {
			values[j] = (i/totals[j])%(divs[j].second+1);
		}
		int r = 1;
		for(unsigned int i = 0; i<values.size(); i++) {
			r*=bpow(divs[i].first, values[i]);
		}
		res.add(r);
	}
	return res;
}

istream& operator>>( istream& in, Pair& c  )
{
	in >> c.value->description;
	c.value->key = c.value->keyF();
	return in;
}


void reverse(char *str)
{
	char temp;
	size_t len = strlen(str) - 1;
	size_t i;
	size_t k = len;

	for(i = 0; i < len; i++) {
		temp = str[k];
		str[k] = str[i];
		str[i] = temp;
		k--;
		if(k == (len / 2)) {
			break;
		}
	}
}

map<int, int> count(Array<int> a)
{
	map<int, int> res;
	for(int i = 0; i<a.size; i++) {
		res[a[i]]++;
	}
	return res;
}

void itoa(int n, char s[])
{
	int radix = 10;
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % radix + '0';
	} while ((n /= radix) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int* vectorToArray(vector<int> v)
{
	int* a = new int[v.size()];
	for(unsigned int i = 0; i<v.size(); i++) {
		a[i] = v[i];
	}
	return a;
}

char* stringToNumber(int number)
{
	char* res = new char[100];
	itoa(number, res);
	return res;
}

int numberToString(char* str)
{
	return atoi(str);
}


int booleanAnswerBinarySearch(Array<int> params, int left, int right, bool (*f)(Array<int> params, int v))
{
	if(f(params, left) && !f(params, left-1)) {
		return left;
	}

	if(f(params, right) && !f(params, right+1)) {
		return right;
	}

	int middle = (left+right)/2;
	int g = f(params, middle);
	if(g) {
		return booleanAnswerBinarySearch(params, left, middle, f);
	} else {
		return booleanAnswerBinarySearch(params, middle+1, right, f);
	}
}

Array< Array<int> > enumerarePermutations(int n)
{
	int fac = fact(n);
	Array<int> v;
	for(int i = 0; i<n; i++) {
		v.add(i+1);
	}
	Array< Array <int> > res;
	for(int i = 0; i<fac-1; i++) {
		Array<int> c(n);
		copy(v.array, v.array + v.size, c.array);
		res.add(c);
		next_permutation(v.array, v.array + v.size);
	}
	Array<int> c(n);
	copy(v.array, v.array + v.size, c.array);
	res.add(c);
	return res;
}

template <typename T>
Array< Array<T> > enumerarePermutations(Array<T> array)
{
	int n = array.size;
	int fac = fact(n);
	Array<T> v;
	for(int i = 0; i<n; i++) {
		v.add(array[i]);
	}
	Array< Array <T> > res;
	for(int i = 0; i<fac-1; i++) {
		Array<T> c(n);
		copy(v.array, v.array + v.size, c.array);
		res.add(c);
		next_permutation(v.array, v.array + v.size);
	}
	Array<T> c(n);
	copy(v.array, v.array + v.size, c.array);
	res.add(c);
	return res;
}

Array< Array<int> > enumerareTuples(int n, int k)
{
	int q = bpow(k, n);
	Array< Array<int> > res(q);
	for(int i = 0; i<q; i++) {
		Array<int> tuple(n);
		for(int j = 0; j<n; j++) {
			tuple[j] = (i/bpow(k, j))%k;
		}
		res[i] = tuple;
	}
	return res;
}

template <typename T>
Array< Array<int> > enumerareTuples(int n, Array<T> array)
{
	int k = array.size;
	int q = bpow(k, n);
	Array< Array<T> > res(q);
	for(int i = 0; i<q; i++) {
		Array<int> tuple(n);
		for(int j = 0; j<n; j++) {
			tuple[j] = array[(i/bpow(k, j))%k];
		}
		res[i] = tuple;
	}
	return res;
}

bool* sieve(int bound)
{
	bool* array = new bool[bound+1]();
	for(int i = 2; i*i<=bound; i++) {
		if(!array[i]) {
			for(int j = i+i; j<=bound; j+=i) {
				array[j] = 1;
			}
		}
	}
	return array;
}

int f(int k)
{
	return k&(k+1);
}

string alignLeft(string a, int length, char ch)
{
	if(a.length() < length) {
		a = string(length - a.length(), ch) + a;
	}
	return a;
}

string decToRadix(int n, int radix)
{
	string res("");
	if(n == 0) {
		res.push_back('0');
		return res;
	}
	while(n) {
		int digit = n%radix;
		res.push_back((char)(digit + '0'));
		n/=radix;
	}
	reverse(res.begin(), res.end());
	return res;
}

int radixToDec(string s, int radix)
{
	int res = 0;
	reverse(s.begin(), s.end());
	for(int i = 0; i<s.length(); i++) {
		res+=(s[i]-'0')*bpow(radix, i);
	}
	return res;
}

class F
{
public:
	int (*f)(int, int);
	int (*inverse)(int, int);
	int NEUTRAL;

	F(int(*pf)(int, int), int (*pinverse)(int, int), int n) {
		f = pf;
		inverse = pinverse;
		NEUTRAL = n;
	}

	F() {
	}

	int operator()(int a, int b) {
		return f(a, b);
	}

	int inversed(int a, int b) {
		return inverse(a, b);
	}
};


class BIT
{
public:
	F f;
	Array<int> tree;
	Array<int> array;

	BIT(F func, Array<int> source) {
		Array<int> arr(source.size);
		copy(source.begin(), source.end(), arr.begin());
		array = arr;
		f = func;

		Array<int> tr(source.size);
		tree = tr;

		for(int i = 0; i<source.size; i++) {
			add(i, array[i]);
		}
	}

	void add(int i, int delta) {
		for(int u = i; u<tree.size; u = u | (u+1)) {
			tree[u]=f(tree[u], delta);
		}
	}

	int value(int l, int r) {
		return f.inversed(p(r) , p(l - 1));
	}

	int p(int v) {
		if(v < 0) {
			return 0;
		}
		if(v == 0) {
			return tree[0];
		} else {
			return f(tree[v], p((v&(v+1)) - 1));
		}
	}
};



#undef int
int main(void)
{
#define int long long int
	int n;
	cin >> n;
	Array<int> a(n);
	cin >> a;
	
	int mx = 0;
	for(int i = 0; i<a.size; i++){
		if(a[i] > mx){
			mx = a[i];
		}
	}
	
	Array<int> s;
	for(int i = 0; i<a.size; i++){
		s.add(a[i]);
	}
	
	for(int i = 0; i<a.size; i++){
		for(int j = 0; j<a.size; j++){
			if(i!=j){
				s.add(max(a[i], a[j]) - min(a[i], a[j]));
			}
		}
	}
	
	int g = gcd(s[0], s[1]);
	for(int i = 1; i<s.size; i++){
		g = gcd(g, s[i]);
	}
	
	

	int total = mx/g;
	
	for(int i = 0; i<a.size; i++){
		if(a[i]%g == 0){
			total--;
		}
	}
	
	

	if(total%2 == 0){
		println("Bob");
	}
	else{
		println("Alice");
	}
}