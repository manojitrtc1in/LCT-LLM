#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
 
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <regex>
#include <random>
#pragma comment(linker, "/STACK:16777216")
 
using namespace std;
 
#define pis pair<int,sint>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pull pair<ull,ull>
#define pdd pair<dd,dd>
#define ppii pair<pair<int,int>, pair<int,int>>
#define ppll pair<pair<ll,ll>, pair<ll,ll>>
#define pli pair<ll,int>
#define pib pair<int,bool>
#define tpl tuple<ll,ll,ll>
#define mp make_pair
#define fs first
#define sc second
 
typedef short int sint;
typedef double dd;
typedef long long ll;
typedef unsigned long long ull;

ll GCD (ll a, ll b)
{
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

ll powmod (ll a, ll k, ll mod)
{
    ll b = 1;
    while (k) {
        if (k%2 == 0) {
            k /= 2;
            a *= a;
            if (mod) a %= mod;
        }
        else {
            k--;
            b *= a;
            if (mod) b %= mod;
        }
    }
    return b;
}

ll inverse (ll a, ll mod, ll p = 0) 

{
    if (p == 0) p = mod;
    return powmod(a, mod-1-mod/p, mod);
}

typedef int ltype;

#define LSIZE 10
const ltype BASE = 1000000000; 

const sint BASE_POWER = 9;

class Lnum
{
    int size;
    bool minus;
    ltype z[LSIZE];
    
public:
    
    Lnum() { z[0] = 0; minus = false; size = 1;}
    Lnum(ltype n) { if (n < 0) { minus = true; n = -n; } else minus = false; z[0] = n; size = 1; }
    Lnum(ll n);
    Lnum(ull n);
    Lnum(string S);
    Lnum(const vector<int> &a);
    Lnum(int a[], int s) { size = s; for (int i=0; i<s; i++) z[i] = a[i]; minus = false; }
    
    string to_string();
    int to_int();
    ll to_long_long();
    dd to_double();
    int digits_count();
    vector<int> digits();
    
    int get_size()    const { return size; }
    ltype back()      const { return z[size-1]; }
    bool isPositive() const { return !minus; } 

    bool isNegative() const { return minus; }
    
    void set_value (int pos, ltype k) { z[pos] = k; }
    void push_back (ltype n)          { z[size++] = n; }
    void pop_back()                   { z[--size] = 0; if (!size) size++; }
    void change_sign()                { if (size != 1 || z[0]) minus = !minus; }
    void set_sign (bool sign)         { if (size == 1 && z[0] == 0) minus = false; else minus = sign; }
    
    static Lnum abs (Lnum A)  { A.set_sign(false); return A; }
    static Lnum sqrt (const Lnum &A);
    
    friend bool operator== (const Lnum &A, const Lnum &B);
    friend bool operator<  (const Lnum &A, const Lnum &B);
    friend bool operator<= (const Lnum &A, const Lnum &B) { return A < B || A == B; }
    friend bool operator>  (const Lnum &A, const Lnum &B) { return B < A; }
    friend bool operator>= (const Lnum &A, const Lnum &B) { return !(A < B); }
    friend bool operator!= (const Lnum &A, const Lnum &B) { return !(A == B); }
    
    friend ostream& operator<< (ostream &os, const Lnum &A);
    friend Lnum operator+ (Lnum A, Lnum B);
    friend Lnum operator- (Lnum A);
    friend Lnum operator- (Lnum A, Lnum B);
    friend Lnum operator* (Lnum A, ltype b);
    friend Lnum operator* (Lnum A, ll b);
    friend Lnum operator* (Lnum A, Lnum B);
    friend Lnum operator/ (Lnum A, ltype b);
    friend ltype operator% (Lnum A, ltype b);
    
    ltype operator[] (int k)   const { return z[k]; }
    Lnum& operator+= (Lnum B)  { *this = *this + B; return *this; }
    Lnum& operator-= (Lnum B)  { *this = *this - B; return *this; }
    Lnum& operator*= (ltype b) { *this = *this * b; return *this; }
    Lnum& operator*= (ll b)    { *this = *this * b; return *this; }
    Lnum& operator*= (Lnum B)  { *this = *this * B; return *this; }
    Lnum& operator/= (ltype b) { *this = *this / b; return *this; }
    
}O,one(1);

Lnum::Lnum (ll n)
{
    if (n < 0) { minus = true; n = -n; }
    else minus = false;
    size = 0;
    do {
        z[size++] = (n % BASE);
        n /= BASE;
    } while (n);
}

Lnum::Lnum (ull n)
{
    minus = false;
    size = 0;
    do {
        z[size++] = (n % BASE);
        n /= BASE;
    } while (n);
}

Lnum::Lnum (string S)
{
    if (S.empty()) { z[0] = 0; minus = false; size = 1; return; }
    if (S[0] == '-') {
        minus = true;
        S.erase(0,1);
    }
    else minus = false;
    size = 0;
    for (int i=(int)S.length(); i>0; i-=BASE_POWER) {
        if (i < BASE_POWER) z[size++] = (atoi(S.substr(0,i).c_str()));
        else z[size++] = (atoi(S.substr(i-BASE_POWER,BASE_POWER).c_str()));
    }
    while (size > 1 && z[size-1] == 0) size--;
}

Lnum::Lnum (const vector<int> &a)
{
    minus = false;
    size = 0;
    for (int i=(int)a.size()-1; i>=0; i--) {
        

        

    }
}

string Lnum::to_string()
{
    ostringstream ostr;
    if (minus) ostr << "-";
    ostr << (size ? z[size-1] : 0);
    for (int i=size-2; i>=0; i--) ostr << setfill('0') << setw(BASE_POWER) << z[i];
    
    return ostr.str();
}



int Lnum::to_int()
{
    int s = 0, k = 1;
    for (int i=0; i<size; i++) {
        s += k*z[i];
        k *= BASE;
    }
    if (minus) s = -s;
    return s;
}

ll Lnum::to_long_long()
{
    ll s = 0, k = 1;
    for (int i=0; i<size; i++) {
        s += k*z[i];
        k *= BASE;
    }
    if (minus) s = -s;
    return s;
}

dd Lnum::to_double()
{
    dd s = 0, k = 1;
    for (int i=0; i<size; i++) {
        s += k*z[i];
        k *= BASE;
    }
    if (minus) s = -s;
    return s;
}

int Lnum::digits_count()
{
    int d = BASE_POWER*(size-1);
    int n = z[size-1];
    while (n) {
        n /= 10;
        d++;
    }
    return d;
}

vector<int> Lnum::digits()
{
    vector<int> a;
    











    
    return a;
}

Lnum Lnum::sqrt (const Lnum &A) 

{
    Lnum lb(1), ub = A, ret;
    while (lb <= ub) {
        Lnum M = (lb + ub) / 2;
        Lnum N = M*M;
        if (N <= A) { ret = M; lb = M + one; }
        else ub = M - one;
    }
    return ret;
}

bool operator== (const Lnum &A, const Lnum &B) 

{
    if (A.isNegative() != B.isNegative()) return false;
    if (A.get_size() != B.get_size()) return false;
    for (int i=A.get_size()-1; i>=0; i--) if (A[i] != B[i]) return false;
    return true;
}

bool operator< (const Lnum &A, const Lnum &B) 

{
    if (A.isNegative() ^ B.isNegative()) return A.isNegative();
    if (A.get_size() > B.get_size()) return A.isNegative();
    if (A.get_size() < B.get_size()) return !A.isNegative();
    for (int i=A.get_size()-1; i>=0; i--) {
        if (A[i] > B[i]) return A.isNegative();
        if (A[i] < B[i]) return !A.isNegative();
    }
    return false;
}

ostream& operator<< (ostream &os, const Lnum &A)
{
    if (A.minus) os << "-";
    os << (A.size ? A[A.size-1] : 0);
    for (int i=A.size-2; i>=0; i--) os << setfill('0') << setw(BASE_POWER) << A[i];
    return os;
}

Lnum operator+ (Lnum A, Lnum B)
{
    ltype carry = 0; bool minus;
    if (A.isNegative() == B.isNegative()) {
        minus = A.isNegative();
        for (int i=0; i<max(A.get_size(),B.get_size()) || carry; i++) {
            if (i == A.get_size()) A.push_back(0);
            A.set_value(i, A[i] + carry + (i < B.get_size() ? B[i] : 0));
            carry = A[i] >= BASE;
            if (carry) A.set_value(i, A[i] - BASE);
        }
    }
    else if (A.isPositive()) { 

        B.change_sign();
        if (A >= B) minus = false;
        else { 

            minus = true;
            bool minus_a = A.isNegative(), minus_b = B.isNegative();
            Lnum T = A; A = B; B = T;
            A.set_sign(minus_a);
            B.set_sign(minus_b);
        }
        for (int i=0; i<B.get_size() || carry; i++) {
            A.set_value(i, A[i] - carry - (i < B.get_size() ? B[i] : 0));
            carry = A[i] < 0;
            if (carry) A.set_value(i, A[i] + BASE);
        }
        while (A.get_size() > 1 && A.back() == 0) A.pop_back();
    }
    else { 

        return B + A;
    }
    
    A.set_sign(minus);
    return A;
}

Lnum operator- (Lnum A)
{
    A.change_sign();
    return A;
}

Lnum operator- (Lnum A, Lnum B)
{
    B.change_sign();
    return A + B;
}

Lnum operator* (Lnum A, ltype b) 

{
    if (b == 0 || A == O) return O;
    
    ltype carry = 0;
    bool minus = A.isPositive() ^ (b > 0);
    if (b < 0) b = -b;
    
    for (int i=0; i<A.get_size() || carry; i++) {
        if (i == A.get_size()) A.push_back(0);
        ll cur = carry + A[i]*1ll*b;
        A.set_value(i, int(cur % BASE));
        carry = int(cur / BASE);
    }
    
    while (A.get_size() > 1 && A.back() == 0) A.pop_back();
    A.set_sign(minus);
    
    return A;
}



Lnum operator* (Lnum A, ll b)
{
    if (b == 0 || A == O) return O;
    
    ltype carry = 0;
    bool minus = A.isPositive() ^ (b > 0);
    if (b < 0) b = -b;
    
    for (int i=0; i<A.get_size() || carry; i++) {
        if (i == A.get_size()) A.push_back(0);
        ll cur = carry + A[i]*1ll*b;
        A.set_value(i, int(cur % BASE));
        carry = int(cur / BASE);
    }
    
    while (A.get_size() > 1 && A.back() == 0) A.pop_back();
    A.set_sign(minus);
    
    return A;
}

Lnum operator* (Lnum A, Lnum B)
{
    if (A == O || B == O) return O;
    
    int size_c = A.get_size()+B.get_size();
    ltype *c = new ltype[size_c];
    for (int i=0; i<size_c; i++) c[i] = 0;
    
    for (int i=0; i<A.get_size(); i++)
    for (int j=0, carry=0; j<B.get_size() || carry; j++) {
        ll cur = c[i+j] + A[i]*1ll*(j < (int)B.get_size() ? B[j] : 0) + carry;
        c[i+j] = int(cur % BASE);
        carry = int(cur / BASE);
    }
    while (size_c > 1 && c[size_c-1] == 0) size_c--;
    
    Lnum C(c, size_c);
    C.set_sign(A.isPositive() ^ B.isPositive());
    
    delete[] c;
    
    return C;
}

Lnum operator/ (Lnum A, ltype b)
{
    if (A == O) return O;
    
    ltype carry = 0;
    bool minus = A.isPositive() ^ (b > 0);
    if (b < 0) b = -b;
    
    for (int i=A.get_size()-1; i>=0; i--) {
        ll cur = A[i] + carry*1ll*BASE;
        A.set_value(i, int (cur / b));
        carry = int (cur % b);
    }
    
    while (A.get_size() > 1 && A.back() == 0) A.pop_back();
    A.set_sign(minus);
    
    return A;
}

ltype operator% (Lnum A, ltype b) 

{
    ltype carry = 0;
    for (int i=A.get_size()-1; i>=0; i--) {
        ll cur = A[i] + carry*1ll*BASE;
        A.set_value(i, int(cur / b));
        carry = int(cur % b);
    }
    if (A.isNegative()) carry = b - carry;
    if (carry == b) carry = 0;
    return carry;
}

Lnum power (Lnum A, ull k)
{
    Lnum B(1);
    
    while (k) {
        if (k%2 == 0) {
            k /= 2;
            A = A*A;
        }
        else {
            k--;
            B = B*A;
        }
    }
    if (A.isNegative() && k%2) B.change_sign();
    return B;
}

pair<Lnum,Lnum> divmod (Lnum A, Lnum B) 

{
    if (B.get_size() == 1) {
        return make_pair(A/B[0], A%B[0]);
    }
    
    bool neg_a = false, neg_b = false;
    if (A.isNegative()) {
        A.change_sign();
        neg_a = true;
    }
    if (B.isNegative()) {
        B.change_sign();
        neg_b = true;
    }
    
    Lnum lb(1), ub = A, M, res;
    while (true) {
        M = (lb + ub) / 2;
        if (B*M > A) ub = M - one;
        else { 

            if (B*(M + one) > A) { res = A - B*M; break; }
            lb = M + one;
        }
    }
    
    if (neg_a) {
        if (res == O) { if (!neg_b) M.change_sign(); }
        else {
            M = M + one;
            res = B - res;
            if (!neg_b && M != O) M.change_sign();
        }
    }
    else {
        if (neg_b && M != O) M.change_sign();
    }
    
    return make_pair(M,res);
}

int main() {
    cout.precision(12);
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    

    clock_t Total_Time = clock();
#endif
    
    const int Q = 998244353;
    int N, M; cin >> N >> M;
    ll F = 1; for (int i=1; i<=N; i++) F *= i;
    Lnum num; ll den = F;
    vector<int> A[20];
    for (int i=0; i<N; i++) {
        A[i] = vector<int>(M);
        for (int j=0; j<M; j++) cin >> A[i][j];
    }
    for (int k=0; k<M; k++) {
        F = den;
        vector<int> a;
        for (int i=0; i<N; i++) a.push_back(A[i][k]);
        sort(a.begin(),a.end());
        ll bad_prev_positions = 1;
        for (int i=0; i<N; i++) {
            int good_positions = N+1-a[i], bad_positions = N-good_positions;
            if (i != N-1) F /= (N-i);
            num += F*good_positions*bad_prev_positions;
            if (i == 0) bad_prev_positions = bad_positions;
            else bad_prev_positions *= (bad_positions-i);
        }
    }
    
    for (int k=2; k<=N; k++) {
        while (num % k == 0 && den % k == 0) { num /= k; den /= k; }
    }
    num = num % Q;
    ll n = num.to_long_long();
    den %= Q;
    cout << n*inverse(den,Q)%Q << endl;
 
#ifndef ONLINE_JUDGE
    Total_Time = clock() - Total_Time;
    cout << "\nRunning time: " << ((float)Total_Time)/CLOCKS_PER_SEC << " seconds\n";
#endif
    return 0;
}
