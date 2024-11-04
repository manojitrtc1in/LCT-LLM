

#ifdef _WIN32
#pragma warning(disable:4996)
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <queue>
#include <iostream>
using namespace std;

FILE* _fin = stdin;
FILE* _fout = stdout;
#define PI 3.141592653589793238462643383279502884197169399375105820974
#define ten5p1 100001
#define ten6p1 1000001
#define ten8p1 100000001
#define ten9p1 1000000001
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define rep(var,n) for(int var=0;var<n;++var)
#define repi(n) rep(i,n)
#define repj(n) rep(j,n)
#define repi1(n) for(int i=1;i<n;++i)
#define repj1(n) for(int j=1;j<n;++j)
int _min(int a, int b) { return a <= b ? a : b; }
ll _min(ll a, ll b) { return a <= b ? a : b; }
int _max(int a, int b) { return a >= b ? a : b; }
ll _max(ll a, ll b) { return a >= b ? a : b; }
void zero(int* data, int n) { memset(data, 0, sizeof(int) * n); }
void zero(ll* data, int n) { memset(data, 0, sizeof(ll) * n); }
void zero(unsigned long long* data, int n) { memset(data, 0, sizeof(unsigned long long) * n); }
void zero(char* data, int n) { memset(data, 0, sizeof(char) * n); }
char readc() { char var; fscanf(_fin, "%c", &var); return var; }
int readi() { int var; fscanf(_fin, "%d", &var); return var; }
double readlf() { double var; fscanf(_fin, "%lf", &var); return var; }
ll readll() { ll var; fscanf(_fin, "%lld", &var); return var; }
void repread(int* data, int n) { repi(n) data[i] = readi(); }
void repread(ll* data, int n) { repi(n) data[i] = readll(); }
int reads(char* str, int maxsize)
{
	for (;;) { if (fgets(str, maxsize, _fin) == NULL) break; if (str[0] != '\n' && str[0] != '\r') break; }
	int slen = strlen(str); if (slen == 0) return 0;
	if (str[slen - 1] == '\n' || str[slen - 1] == '\r') str[--slen] = 0;
	return slen;
}

#define writec(var) fprintf(_fout,"%c",var)
#define writecsp(var) fprintf(_fout,"%c ",var)
#define writecln(var) fprintf(_fout,"%c\n",var)
#define writei(var) fprintf(_fout,"%d",var)
#define writeisp(var) fprintf(_fout,"%d ",var)
#define writellsp(var) fprintf(_fout,"%lld ",var)
#define writeiln(var) fprintf(_fout,"%d\n",var)
#define writellln(var) fprintf(_fout,"%lld\n",var)
#define writeulln(var) fprintf(_fout,"%llu\n",var)
#define writefln(var) fprintf(_fout,"%f\n",var)
#define writes(str) fprintf(_fout,"%s",str)
#define writesp() fprintf(_fout," ")
#define writeln() fprintf(_fout,"\n")
#define RUN_LOCAL(testfilename) {_fin = fopen(testfilename, "r"); if(_fin==NULL) _fin=stdin;}
#define swap(type,a, b) {type t=a;a=b;b=t;}
#define sort(data,n) std::sort(data,data+n)


ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return (a / g) * b; }
void reverse(char* data, int n) { int k = n >> 1; repi(k) { char tmp = data[i]; data[i] = data[n - i - 1]; data[n - i - 1] = tmp; } }
void reverse(int* data, int n) { int k = n >> 1; repi(k) { int tmp = data[i]; data[i] = data[n - i - 1]; data[n - i - 1] = tmp; } }
void reverse(ll* data, int n) { int k = n >> 1; repi(k) { ll tmp = data[i]; data[i] = data[n - i - 1]; data[n - i - 1] = tmp; } }

#define _Vec(type, name) \
struct name { type* data; int size; int n; };\
void init(name* t, int size) { t->data = (type*)malloc(sizeof(type) * size); t->size = size; t->n = 0; }\
void resize(name* t) { int ns = t->size * 1.2f + 1; t->data = (type*)realloc(t->data, sizeof(type) * ns); t->size = ns; }\
void add(name* t, type val) { if (t->n >= t->size) resize(t); int k = t->n; t->data[k] = val; t->n = k + 1; }\
void free(name* t) { free(t->data);}
_Vec(int, Veci)
_Vec(long long, Vecll)
_Vec(char*, Vecs)

#define _ispal(type, name) int name(type* a, type* b, int n){repi(n){if (a[i] != b[n - i - 1]){return 0;}}return 1;}
_ispal(int, ispali)
_ispal(char, ispalc)

#define _Pair(type, name) struct name{type x, y;}; \
int cmp_##name(const void* _a, const void* _b)\
{\
	name* a = (name*)_a;name* b = (name*)_b;\
	if (a->x < b->x) return -1;\
	else\
	{\
		if (a->x == b->x)\
		{\
			if (a->y == b->y) return 0;\
			if (a->y < b->y) return -1;\
			else return 1;\
		}\
		else\
		{\
			return 1;\
		}\
	}\
}\
void sort_##name(name* d, int n){qsort(d, n, sizeof(name), cmp_##name);}
	_Pair(int, Pairi)
	_Pair(double,Pairlf)


	int cmp_Str(const void* _a, const void* _b) { char* a = *((char**)_a); char* b = *((char**)_b); return strcmp(a, b); }
void sort_Str(char** str, int n) { qsort(str, n, sizeof(char*), cmp_Str); }

ll expmod(ll x, ll n, ll m) {
	ll ans = 1;
	for (; n;) {
		if (n & 1) ans = (ans * x) % m;
		x = (x * x) % m;
		n >>= 1;
	}
	return ans;
}

ll combmod(ll n, ll k, ll m) {
	ll ret = 1;
	ll div = 1;
	for (ll i = 0; i < k; ++i) {
		ret = (ret * (n - i) % m) % m;
		div = (div * (i + 1)) % m;
	}
	div = expmod(div, m - 2, m) % m;
	return (ret * div) % m;
}

int next_perm(int* data, int n)
{
	

	int rootidx = -1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (data[i] < data[i + 1])
		{
			rootidx = i;
			break;
		}
	}

	if (rootidx == -1) return 0;

	int ceilingidx = rootidx + 1;
	

	for (int i = rootidx + 2; i < n; ++i)
	{
		if (data[i] > data[rootidx] && data[i] < data[ceilingidx])
		{
			ceilingidx = i;
		}
	}

	swap(int, data[rootidx], data[ceilingidx]);
	sort(&data[rootidx + 1], n - rootidx - 1);
	return 1;
}
int count_digits(ll a)
{
	int k = 0;
	for (;;)
	{
		if (a == 0)break;
		k++;
		a /= 10;
	}
	return k;
}


int bs_exists(int* data, int n, int val)
{
	int left = 0;
	int right = n - 1;
	for (; left < right;)
	{
		int mid = (left + right + 1) >> 1;
		if (data[mid] <= val) left = mid;
		else right = mid - 1;
	}
	return right;
}

ll simple_factorial(int x)
{
	ll f = 1.0;
	repi(x)
	{
		f *= (i + 1);
	}
	return f;
}

unsigned long long djb2(char* data, int n)
{
	unsigned long long h = 5381;
	for (int i = 0; i < n; ++i) h = (h << 5) + h + data[i];
	return h;
}

struct Hashcount
{
	int* count;
	unsigned long long* keys;
	int size_bits;
};
void init(Hashcount* h, int size_bits)
{
	h->size_bits = size_bits;
	int size = 1 << h->size_bits;
	h->count = (int*)malloc(sizeof(int) * size);
	zero(h->count, size);
	h->keys = (unsigned long long*)malloc(sizeof(unsigned long long) * size);
	zero(h->keys, size);
}
int set(Hashcount* h, unsigned long long key)
{
	

	int index = (key * 2654435761) >> (64 - h->size_bits);
	int size = 1 << h->size_bits;
	for (int i = 0; i < size; i++)
	{
		if (h->keys[index] == key) 

		{
			h->count[index]++;
			return index;
		}

		if (h->keys[index] == 0) 

		{
			h->count[index] = 1;
			h->keys[index] = key;
			return index;
		}

		index++;
		index &= size - 1;
	}

	return -1;

}
int get(Hashcount* h, unsigned long long key)
{
	int index = (key * 2654435761) >> (64 - h->size_bits);
	int size = 1 << h->size_bits;
	for (int i = 0; i < size; i++)
	{
		if (h->keys[index] == key)

		{
			return h->count[index];
		}

		if (h->keys[index] == 0) return 0;


		index++;
		index &= size - 1;
	}
	return 0;
}


int sub(Hashcount* h, unsigned long long key)
{
	int index = (key * 2654435761) >> (64 - h->size_bits);
	int size = 1 << h->size_bits;
	for (int i = 0; i < size; i++)
	{
		if (h->keys[index] == key)

		{
			--h->count[index];
			if (h->count[index] < 0) h->count[index] = 0;
			return h->count[index];
		}

		if (h->keys[index] == 0) return 0;


		index++;
		index &= size - 1;
	}
	return 0;
}

struct Hashsum
{
	long long* sum;
	unsigned long long* keys;
	int size_bits;
};
void init(Hashsum* h, int size_bits)
{
	h->size_bits = size_bits;
	int size = 1 << h->size_bits;
	h->sum = (long long*)malloc(sizeof(long long) * size);
	zero(h->sum, size);
	h->keys = (unsigned long long*)malloc(sizeof(unsigned long long) * size);
	zero(h->keys, size);
}

int add(Hashsum* h, unsigned long long key, long long val)
{
	

	int index = (key * 2654435761) >> (64 - h->size_bits);
	int size = 1 << h->size_bits;
	for (int i = 0; i < size; i++)
	{
		if (h->keys[index] == key) 

		{
			h->sum[index] += val;
			return index;
		}

		if (h->keys[index] == 0) 

		{
			h->sum[index] = val;
			h->keys[index] = key;
			return index;
		}

		index++;
		index &= size - 1;
	}

	return -1;

}

void reset(Hashsum* h)
{
	int size = 1 << h->size_bits;
	zero(h->sum, size);
	zero(h->keys, size);
}

long long get(Hashsum* h, unsigned long long key)
{
	int index = (key * 2654435761) >> (64 - h->size_bits);
	int size = 1 << h->size_bits;
	for (int i = 0; i < size; i++)
	{
		if (h->keys[index] == key)

		{
			return h->sum[index];
		}

		if (h->keys[index] == 0) return 0;


		index++;
		index &= size - 1;
	}
	return 0;
}

void shuffleidx(int* idx, int n)
{
	repi(n) idx[i] = i;
	repi(n)
	{
		int j = i + rand() % (n - i);
		int tmp = idx[i];
		idx[i] = idx[j];
		idx[j] = tmp;
	}
}

const ll MOD  = 1e9 + 7;





struct Vertex
{
	int idx;
	long long dist;
};

void pop(Vertex* heap, int* _nheap)
{
	int nheap = *_nheap;
	if (nheap < 2) return;
	heap[1] = heap[--nheap];
	*_nheap = nheap;
	int k = 1;
	for (;;)
	{
		int child = k << 1;
		if (child >= nheap) break;

		if (child + 1 < nheap && heap[child + 1].dist <= heap[child].dist) child++;

		if (heap[k].dist <= heap[child].dist) break;


		Vertex tmp = heap[k];
		heap[k] = heap[child];
		heap[child] = tmp;
		k = child;

		k = child;
	}

}

void add(Vertex* heap, int* _nheap, int idx, ll dist)
{
	int nheap = *_nheap;
	heap[nheap].idx = idx;
	heap[nheap].dist = dist;

	int k = nheap;
	for (;;)
	{
		if (k <= 1) break;
		int parent = k >> 1;
		if (heap[parent].dist <= heap[k].dist) break;
		Vertex tmp = heap[k];
		heap[k] = heap[parent];
		heap[parent] = tmp;
		k = parent;
	}

	*_nheap = nheap + 1;
}









int main()
{

	RUN_LOCAL("inputx.txt");
	int t = readi();
	rep(_t, t)
	{
		int n = readi();
		static int a[ten5p1];
		repread(a, n);
		sort(a, n);
		
		ll best = LLONG_MIN;
		for (int i=0;i<=5;++i)
		{
			int neg = i;
			int pos = 5-i;
			long long m = 1;
			for (int k = 0; k < neg; ++k)
			{
				m *= a[k];
			}
			for (int k = 0; k < pos; ++k)
			{
				m *= a[n-k-1];
			}
			if (m > best)
			{
				best = m;
			}
		}
		printf("%lld\n", best);
	}
	

	
	return 0;
}
