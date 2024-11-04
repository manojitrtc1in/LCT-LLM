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


#define int long long int

#define fillvec(a) generate(a->begin(), a->end(), [] () -> int{return rand()%10;});
#define fillar(a, n) generate(a, a+n, [] () -> int{return rand()%10;});

#define printvec(a) std::for_each(a.begin(), a.end(), [] (int x){cout << x << " ";});
#define printar(a, n) std::for_each(a, a+n, [] (int x){cout << x << " ";});

#define inint(a) std::generate(&(a.array[0]), &(a.array[a.size]), [] ()->int{int a; cin >> a; return a;});
#define inDouble(a) std::generate(&(a.array[0]), &(a.array[a.size]), [] ()->double{double a; cin >> a; return a;});
#define inPair(a) std::generate(&(a.array[0]), &(a.array[a.size]), [] ()->Pair{Pair a(0, 0); cin >> a; return a;});

#define DEBUG
#define NULL 0

#include <iostream>
#include <vector>
using namespace std;

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




template<typename E>
void print(E value)
{
	cout << value;
}

template<typename E>
void print(E value1, E value2)
{
	cout << value1 << " " << value2;
}

template<typename E>
void print(E value1, E value2, E value3)
{
	cout << value1 << " " << value2 << " " << value3;
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

template<typename E>
void println(E value)
{
	cout << value << endl;
}

template<typename E>
void println(E value1, E value2)
{
	cout << value1 << " " << value2<< endl;
}

template<typename E>
void println(E value1, E value2, E value3)
{
	cout << value1 << " " << value2 << " " << value3<< endl;
}


template<typename E>
void println(E value1, E value2, E value3, E value4)
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
		capacity = 0;
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
vector<E> Array<E>::toVector()
{
	vector<E> res = vector<E>(size);
	for(int i =0; i<res.size(); i++) {
		res[i] = array[i];
	}
	return res;
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
	void print();

	Matrix<E>(int r, int c) {
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

	Matrix<E>(int minBound, int maxBound, int _rows, int _columns) {
		rows = _rows;
		columns = _columns;
		int size = _rows*_columns;
		array = Array<E>(minBound, maxBound, size);
	}

private:
};


template <typename E>
E& Matrix<E>::get(int x, int y)
{
#ifdef DEBUG
	if(x>=columns || x<0) {
		assert(0);
	}
	if(y>=rows || y<0) {
		assert(0);
	}
	return array.array[x+y*columns];
#endif

#ifndef DEBUG
	return array.array[x+y*columns];
#endif
}

template <typename E>
void Matrix<E>::print(void)
{
	for(size_t y = 0; y<rows; y++) {
		for(size_t x = 0; x<columns; x++) {
			int index = x+y*columns;
			cout << array.array[index] << " ";
		}
		cout << endl;
	}
}

template <typename E>
void Matrix<E>::set(int x, int y, E& value)
{
#ifdef DEBUG
	if(x>=columns || x<0) {
		assert(0);
	}
	if(y>=rows || y<0) {
		assert(0);
	}
	array.array[x+y*columns] = value;
#endif
#ifndef DEBUG
	array.array[x+y*columns] = value;
#endif
}

#define getA(array, i) (array.array[(i)])
#define setA(array, i, value) (array.array[(i)] = value)
#define getM(matrix, i, j) (matrix.array.array[i+j*matrix.columns])
#define setM(matrix, i, j, value) (matrix.array.array[i+j*matrix.columns] = value)

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

int fact(int n){
	if(n == 1){
		return 1;
	}
	else{
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

vector<pair<int, int> > factorize(int n)
{
	vector<pair<int, int> > res = vector<pair<int, int> >();
	for(int i = 2; i<sqrt((double)n)+1; i++) {
		if(n%i == 0) {
			pair<int, int> comp = make_pair(i, 1);
			n/=i;
			while(n%i == 0) {
				comp.second++;
				n/=i;
			}
			res.push_back(comp);
		}
	}

	if(n>1) {
		res.push_back(make_pair(n, 1));
	}
	return res;
}

int euler(int n)
{
	vector<pair<int, int> > fact = factorize(n);
	int res = 1;
	for(unsigned int i = 0; i<fact.size(); i++) {
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

vector<int> enumerateDivisors(int n)
{
	vector<pair<int, int> > divs = factorize(n);
	vector<int> totals = vector<int>(divs.size()+1);
	totals[0] = 1;
	for(unsigned int i = 1; i < divs.size()+1; i++) {
		totals[i]=totals[i-1]*(divs[i-1].second+1);
	}

	vector<int> res = vector<int>();
	for(int i = 0; i<totals[totals.size()-1]; i++) {
		vector<int> values = vector<int>(divs.size());
		for(unsigned int j = 0; j<values.size(); j++) {
			values[j] = (i/totals[j])%(divs[j].second+1);
		}
		int r = 1;
		for(unsigned int i = 0; i<values.size(); i++) {
			r*=bpow(divs[i].first, values[i]);
		}
		res.push_back(r);
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

bool good(Array<int> params, int v){
	return v>=5;
}

int booleanAnswerBinarySearch(Array<int> params, int left, int right, bool (*f)(Array<int> params, int v)){
	if(f(params, left) && !f(params, left-1)){
		return left;
	}
	
	if(f(params, right) && !f(params, right+1)){
		return right;
	}
	
	int middle = (left+right)/2;
	int g = f(params, middle);
	if(g){
		return booleanAnswerBinarySearch(params, left, middle, f);
	}
	else{
		return booleanAnswerBinarySearch(params, middle+1, right, f);
	}
}



vector< vector<int> > enumetarePermutation(int n){
	int fac = fact(n);
	vector<int> v;
	for(int i = 0; i<n; i++){
		v.push_back(i+1);
	}
	vector< vector <int> > res;
	res.push_back(v);
	for(int i = 0; i<fac-1; i++){
		next_permutation(v.begin(), v.end());
		res.push_back(v);
	}
	return res;
}

int fun(pair<int, int> a, pair<int, int> b){
	if (a.first > b.first){
		return 1;
	}
	else{
		if(a.first < b.first){
			return -1;
		}
		else{
			if(a.second < b.second){
				return 1;
			}
			else{
				if(a.second > b.second){
					return -1;
				}
				else{
					return 0;
				}
			}
		}
	}
}

vector<int> runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = upperBound;
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
	  
	  vector<int> res;
	  for (int m = 0; m <= upperBoundSquareRoot; m++) {
		  if(isComposite[m] == 0 && m!=1){
			  res.push_back(m);
		  }
	  }
	  
      return res;
}


int pl(int val, Array<int> res){
	int pos = res.leftBinarySearch(val);
	int plus = res[pos]-val;
	return plus;
}


#undef int
int main(void)
{
#define int long long int
	vector<int> rrr = runEratosthenesSieve(1000000);
	Array<int> res(rrr.size());
	for(int i = 0; i<rrr.size(); i++){
		res[i] = rrr[i];
	}
	
	
	for(int i = 0; i<rrr.size(); i++){
		

	}
	

	
	int n;
	int m;
	cin >> n >> m;
	Matrix<int> mat(n, m);
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			int val = 5;
			scanf("%d", &val);
			mat.set(j, i, val);
		}
	}
	
	

	
	int min = 100000;
	
	for(int i = 0; i<n; i++){
		int summ = 0;
		for(int j = 0; j<m; j++){
			int val = mat.get(j, i);
			summ+=pl(val, res);
			

		}
		if(summ < min){
			min = summ;
		}
	}
	
	

	
	
	for(int j = 0; j<m; j++){
		int summ = 0;
		for(int i = 0; i<n; i++){
			int val = mat.get(j, i);
			summ+=pl(val, res);
			

		}
		if(summ < min){
			min = summ;
		}
	}
	
	print(min);
}
