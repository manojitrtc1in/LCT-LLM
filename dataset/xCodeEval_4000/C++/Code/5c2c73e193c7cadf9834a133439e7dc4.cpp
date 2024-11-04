using namespace std;

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>


#include <cstdlib>
#include <set>
#include <queue>
#include <ctime>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include  <tgmath.h>
#include <algorithm>
#include <iterator>
#include <map>
#include "numeric"
#include "stack"
#include <iomanip>
#include <utility>
#include "math.h"
#include <assert.h>
#include <bitset>
#include <string>
#include <fstream>


typedef long long ll;
typedef long double ld;







template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void __print(int x) { cerr << x; }

void __print(long x) { cerr << x; }

void __print(long long x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(unsigned long x) { cerr << x; }

void __print(unsigned long long x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;


template<class T>
void re(T &x) { cin >> x; }

template<class T>
void read(vector<T> &a) { for (auto &x : a) re(x); }












bool Prime(string t) {
    int x = (t[0] - '0') * 10 + t[1] - '0';
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int changchar(char s) {
    if (s == '0') {
        return 0;
    }
    if (s == '1') {
        return 1;
    }
    if (s == '2') {
        return 2;
    }
    if (s == '3') {
        return 3;
    }
    if (s == '4') {
        return 4;
    }
    if (s == '5') {
        return 5;
    }
    if (s == '6') {
        return 6;
    }
    if (s == '7') {
        return 7;
    }
    if (s == '8') {
        return 8;
    }
    if (s == '9') {
        return 9;
    }
    return 0;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return 0;
        }
    }
    return 1;
}



const long long inf = 1e18;


struct segment {
    int a, id;
};
struct segment2 {
    int s, e;
};

bool operator<(segment a, segment b) {
    return a.a > b.a;
}



typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vivi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;



#define all(a) a.begin() , a.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ins insert

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)




double upp(double x , int n){
    double xx = x;
    F0R(i , n - 1){
        xx *= x;
    }
    return xx;
}

double takeOne(double a){
    string s = to_string(a);
    int index = 0;
    F0R(i , sz(s)){
        if(s[i] == '.'){
            index = i + 2;
            break;
        }
    }
    if(s[index] < '4'){
        string ans = "";
        F0R(j , index){
            ans += s[j];
        }
        double anss = stod(ans);
        return anss;
    }
    FORd(i , index , sz(s)){
        if(s[i] >= '5'){
            if(s[i - 1] != '9'){
                s[i - 1]++;
            }
        }
    }
    string ans1 = "";
    F0R(i , index){
        ans1 += s[i];
    }
    double ans = stod(ans1);
    return ans;
}

double takeTwo(double a){
    string s = to_string(a);
    int index = 0;
    F0R(i , sz(s)){
        if(s[i] == '.'){
            index = i + 2;
            index++;
            break;
        }
    }
    if(s[index] < '4'){
        string ans = "";
        F0R(j , index){
            ans += s[j];
        }
        double anss = stod(ans);
        return anss;
    }
    FORd(i , index , sz(s)){
        if(s[i] >= '5'){
            if(s[i - 1] != '9'){
                s[i - 1]++;
            }
        }
    }
    string ans1 = "";
    F0R(i , index){
        ans1 += s[i];
    }
    double ans = stod(ans1);
    return ans;
}

void KCT(){
    vector<vector<double>> ans;
    vector<double> aa;
    double Qc = 20  , Yq = 1.2 , L = 8 , Fu = 34 , F = 21 , E = 21000 , Fv = 0.58 , DentaL = 400 , Yc = 0.9
            , Yqthep = 1.05 , Ys = 78.5;
    Fv *= F;
    double Q = Yq * Qc ;
    double Mmax = ( Q * L * L) / 8; Mmax = takeTwo(Mmax);
    double Qmax = (Q * L) / 2; Qmax = takeTwo(Qmax);
    L *= 100;
    Mmax *= 100;
    double Hmin = 5 /24 * F / E * DentaL * L / Yq;   

    double Wyc = Mmax / (Yc * F); Wyc = takeTwo(Wyc);
    double Hkt = 1.2 * sqrt((Wyc / 0.6)); Hkt = takeTwo(Hkt);  

    int H = Hkt;
    if(round(Hkt) < Hkt){
        H++;
    }
    bool okBf = 0;
    int BfAll , Tw;
    double Hw , Hf , Tf ;
    while(!okBf){
        double TwTest = 3 / 2 * Qmax / ( H * Yc * Fv); 

        double findTw = max(H / 5.5 * sqrt((F /  E)) , H  / 3.2  * sqrt((F / E))); 

        findTw = takeTwo(findTw);
        findTw *= 10;
        findTw = round(findTw);
        Tw = findTw ;
        if(Tw % 2 == 1){
            Tw++;
        }
        

        Tf = Tw + 2;
        Hw = H - 2 * (Tf / 10);
        Hf = H - (Tf / 10);
        double Bf = (Mmax * H) / (Yc * F * 2) ;
        Bf -= (((double)Tw / 10) * Hw * Hw * Hw) / 12;
        Bf *= 2 / ((Tf / 10) * Hf * Hf);
        Bf = takeTwo(Bf);
        double TestBf = sqrt((E / F)) * (Tf / 10);
        TestBf = takeTwo(TestBf);
        int s = H / 5;
        int e = H / 2;
        if(Bf <= TestBf && Bf >= s && Bf <= e){
            Bf = round(Bf);
            BfAll = Bf;
            okBf = 1;
        }else{
            H++;
        }
    }
    if(BfAll % 2 == 1){
        BfAll++;
    }
    

    

    

    Hw = takeTwo(Hw) ; Hf = takeTwo(Hf); Tf = takeTwo(Tf);
    BfAll = 22;
    double A = ((double)Tw / 10) * Hw + 2 * (Tf / 10) * BfAll; A = takeTwo(A);
    double Ix = (((double)Tw / 10) * Hw * Hw * Hw ) / 12;   

    Ix += 2 * ((BfAll * (upp(Tf / 10 , 3))) / 12)  + 2 * ((Tf / 10) * BfAll * (upp(Hf , 2) / 4));
    Ix = takeTwo(Ix);
    double Wx = Ix / (H / 2);  Wx = takeTwo(Wx);  

    double Sx = ((double)Tw / 10) * (Hw / 2) * (Hw / 4) + (Tf / 10) * BfAll * (Hf / 2); Sx = takeTwo(Sx);  

    double Sxf = (Tf / 10) * BfAll * Hf / 2;  Sxf = takeTwo(Sxf);
    double Gcd = Ys * A * 0.0001 * 1;  Gcd = takeTwo(Gcd); 

    double Gd = Yqthep * Gcd;
    debug(Gd)
    Gd = takeTwo(Gd);
    double QphayC = Qc + Gcd;  QphayC = takeTwo(QphayC);
    double Qphay = Q + Gd; Qphay = takeTwo(Qphay);
    

    L /= 100;
    double MphayMax = Qphay * upp(L , 2) / 8; MphayMax = takeTwo(MphayMax);
    double QphayMax = (Qphay * L) / 2;  QphayMax = takeTwo(QphayMax);
    double QtaiL4 = (Qphay * L / 2) - Qphay * (L / 4);  QtaiL4 = takeTwo(QtaiL4);
    double MtaiL4 = Qphay * L / 2 * L / 4 - (Qphay / 2) * upp((L / 4) , 2); MtaiL4 = takeTwo(MtaiL4);

    debug(QtaiL4)
    debug(MtaiL4)
    bool ok = 1;
    double YcF = Yc * F; YcF = takeTwo(YcF);
    double XichmaMax = MphayMax * 100 / Wx;  XichmaMax = takeTwo(XichmaMax);
    double ToMax = QphayMax * Sx / (Ix * ((double)Tw / 10)); ToMax = takeTwo(ToMax);
    double Xichma1 = MtaiL4 * 100 * Hw / (Wx * H); Xichma1 = takeTwo(Xichma1);
    double To1 = QtaiL4 * Sxf / (Ix  * ((double) Tw / 10)); To1 = takeTwo(To1);
    double ToGiua = sqrt(upp(Xichma1 , 2) + 3 * upp(To1 , 2));
    debug(ToGiua)
    ToGiua = takeTwo(ToGiua);
    

    L *= 100;
    

    double DentaLSosanh = 0.01302083 * ((QphayC / 100) * upp(L , 3)) / (E * Ix);
    DentaLSosanh *= DentaL;
    

    _print(Hw , Hf , A , Ix, Wx , Sx , Sxf , Gcd , Gd , Qphay , QphayC , MphayMax ,
           QphayMax , XichmaMax , ToMax , Xichma1 , To1 , ToGiua , DentaLSosanh);
    double Bof = (BfAll - (double)Tw / 10) / 2.0 ;




}


void decToBinary(int n)
{
    

    int binaryNum[32];

    

    int i = 0;
    while (n > 0) {

        

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

#define int64 long long

int64 Solve(int64 x, int64 n) {
    int64 answer = 0;
    vector<int> free_to_left(62, 0);
    int last = 0;
    for (int i = 0; i < 62; i += 1) {
        free_to_left[i] = last;
        last += (x & (1LL << i)) == 0;


    }
    trav(i , free_to_left){
        cout << i << " ";
    }
    cout << '\n';
    bool terminated = false;
    for (int p = 61; p >= 0; p -= 1) {
        bool has_x = !!((1LL << p) & x);
        bool has_n = !!((1LL << p) & n);
        if(has_x){
            cout << "has_x true" << " tai p : " <<p << '\n' ;
        }
        if(has_n){
            cout << "    has_n true" << " tai p : " <<p << '\n' ;
        }
        if (has_x and has_n) {
            continue;
        }

        if (has_x and not has_n) {
            cout << "da stop "  << p << '\n';
            terminated = true;
            break;
        }

        if (not has_n) {
            continue;
        }

        answer += (1LL << free_to_left[p]);
    }
    cout << answer << '\n';
    answer += terminated ^ 1;
    cout << "ans sau: "<<answer << '\n';
    return answer;
}


void solve(){
   int n;
   cin >> n;
   int index = 0;
   F0R(i , 30){
       if((1LL << i) & n){
           index = i;
       }
   }
   cout << (1LL << index) - 1 << '\n';
}






int main() {

    
















    int t;
    cin >> t;
    FOR(i , 1 , t + 1){
        solve();
    }


























    return 0;
}