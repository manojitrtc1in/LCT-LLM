#ifdef _MSC_VER






#pragma warning(disable:4018)  

#pragma warning(disable:4996)  

template<typename _Type>
int __builtin_popcount(_Type x) {
  static int count[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
  };
  int c = 0;
  while ( x ) {
    c += count[x & 0xFF];
    x >>= 8;
  }
  return c;
}
template<typename _Type>
int __builtin_clz(_Type x) {
  static int lead[128] = {
    8, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
  };
  int c = 0;
  for ( int shift = 8 * sizeof(_Type) - 8; shift >= 0; shift -= 8 ) {
    int w = (x >> shift) & 0xFF;
    c += lead[w];
    if ( w ) break;
  }
  return c;
}
#endif  


#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <sstream>
#include <complex>
#include <limits>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <time.h>
using namespace std;



#define SIZE(N, V) int N = static_cast<int>((V).size())
#define GSIZE(N, V) (N) = static_cast<int>((V).size())
#define ALL(V) (V).begin(), (V).end()
#define UNIQUE(C) {sort(ALL(C)); C.resize(unique(ALL(C)) - C.begin());}
#define CAST(X, Y) {stringstream ss; ss << (X); ss >> (Y);}
typedef long long i64;
const i64 ooLL = 0x3f3f3f3f3f3f3f3fLL;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
static char stringReader[2097152];
static inline bool ReadLine() {
  char* ptr = fgets(stringReader, sizeof(stringReader), stdin);
  if ( ptr == 0 ) return false;
  int N = strlen(stringReader);
  if ( stringReader[N - 1] == '\n' ) stringReader[N - 1] = 0;
  return true;
}
#define InLine(X) string X; ReadLine(); X = stringReader
#define InString1(X) string X; scanf("%s", stringReader); X = stringReader
#define InString2(X, Y) string X, Y; scanf("%s", stringReader); X = stringReader; scanf("%s", stringReader); Y = stringReader
#define InString3(X, Y, Z) string X, Y, Z; scanf("%s", stringReader); X = stringReader; scanf("%s", stringReader); Y = stringReader; scanf("%s", stringReader); Z = stringReader
#define InDouble1(X) double X; scanf("%lf", &X)
#define InDouble2(X, Y) double X, Y; scanf("%lf%lf", &X, &Y)
#define InDouble3(X, Y, Z) double X, Y, Z; scanf("%lf%lf%lf", &X, &Y, &Z)
#define InI641(X) i64 X; scanf("%lld", &X)
#define InI642(X, Y) i64 X, Y; scanf("%lld%lld", &X, &Y)
#define InI643(X, Y, Z) i64 X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define InInt1(X) int X; scanf("%I64d", &X)
#define InInt2(X, Y) int X, Y; scanf("%I64d%I64d", &X, &Y)
#define InInt3(X, Y, Z) int X, Y, Z; scanf("%I64d%I64d%I64d", &X, &Y, &Z)
#define InVectorString(X, N) vector<string> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%s", stringReader), X[i_##X] = stringReader
#define InVectorDouble(X, N) vector<double> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lf", &X[i_##X])
#define InVectorI64(X, N) vector<i64> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lld", &X[i_##X])
#define InVectorInt(X, N) vector<int> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%I64d", &X[i_##X])
#define WhileTests() int TESTS; ReadLine(); CAST(stringReader, TESTS); for ( int test = 1; test <= TESTS; ++test )
#define WhileInI641(X) for ( i64 X, test = 1; scanf("%lld", &X) == 1 && (X); ++test )
#define WhileInI642(X, Y) for ( i64 X, Y, test = 1; scanf("%lld%lld", &X, &Y) == 2 && (X|Y); ++test )
#define WhileInI643(X, Y, Z) for ( i64 X, Y, Z, test = 1; scanf("%lld%lld%lld", &X, &Y, &Z) == 3 && (X|Y|Z); ++test )
#define WhileInInt1(X) for ( int X, test = 1; scanf("%I64d", &X) == 1 && (X); ++test )
#define WhileInInt2(X, Y) for ( int X, Y, test = 1; scanf("%I64d%I64d", &X, &Y) == 2 && (X|Y); ++test )
#define WhileInInt3(X, Y, Z) for ( int X, Y, Z, test = 1; scanf("%I64d%I64d%I64d", &X, &Y, &Z) == 3 && (X|Y|Z); ++test )
#define WhileInGlobalI641(X) for ( int test = 1; scanf("%lld", &X) == 1 && (X); ++test )
#define WhileInGlobalI642(X, Y) for ( int test = 1; scanf("%lld%lld", &X, &Y) == 2 && (X|Y); ++test )
#define WhileInGlobalI643(X, Y, Z) for ( int test = 1; scanf("%lld%lld%lld", &X, &Y, &Z) == 3 && (X|Y|Z); ++test )
#define WhileInGlobalInt1(X) for ( int test = 1; scanf("%I64d", &X) == 1 && (X); ++test )
#define WhileInGlobalInt2(X, Y) for ( int test = 1; scanf("%I64d%I64d", &X, &Y) == 2 && (X|Y); ++test )
#define WhileInGlobalInt3(X, Y, Z) for ( int test = 1; scanf("%I64d%I64d%I64d", &X, &Y, &Z) == 3 && (X|Y|Z); ++test )



template<typename _Type>
struct PointVector2D {
  _Type x, y;
  explicit PointVector2D<_Type>(_Type _x = 0, _Type _y = 0) : x(_x), y(_y) {}
};
template<typename _Type>
double Distance(const PointVector2D<_Type>& p0, const PointVector2D<_Type>& p1) {
  double dx = p0.x - p1.x;
  double dy = p0.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}
template<typename _Type>
_Type DistanceSq(const PointVector2D<_Type>& p0, const PointVector2D<_Type>& p1) {
  _Type dx = p0.x - p1.x;
  _Type dy = p0.y - p1.y;
  return dx * dx + dy * dy;
}
template<typename _Type>
PointVector2D<_Type> operator-(const PointVector2D<_Type>& u, const PointVector2D<_Type>& v) {
  return PointVector2D<_Type>(u.x - v.x, u.y - v.y);
}
template<typename _Type>
bool operator==(const PointVector2D<_Type>& u, const PointVector2D<_Type>& v) {
  return u.x == v.x && u.y == v.y;
}
template<typename _Type>
bool operator!=(const PointVector2D<_Type>& u, const PointVector2D<_Type>& v) {
  return !(u == v);
}
template<typename _Type>
_Type operator%(const PointVector2D<_Type>& u, const PointVector2D<_Type>& v) {
  return u.x * v.y - u.y * v.x;
}
typedef enum eOrientation {
  CCW = -1, COLINE, CW
};
template<typename _Type>
int Orientation(const PointVector2D<_Type>& p0, const PointVector2D<_Type>& p1, const PointVector2D<_Type>& p2) {
  _Type cross = (p2 - p0) % (p1 - p0);
  if ( cross < 0 ) return CCW;
  if ( cross > 0 ) return CW;
  return COLINE;
}
template<typename _Type>
_Type operator*(const PointVector2D<_Type>& u, const PointVector2D<_Type>& v) {
  return u.x * v.x + u.y * v.y;
}
template<typename _Type>
PointVector2D<_Type> operator+(const PointVector2D<_Type>& u, const PointVector2D<_Type>& v) {
  return PointVector2D<_Type>(u.x + v.x, u.y + v.y);
}
template<typename _Type>
bool IsInSegment(const PointVector2D<_Type>& p1, const PointVector2D<_Type>& p2, const PointVector2D<_Type>& pt) {
  _Type minX = min(p1.x, p2.x);
  _Type minY = min(p1.y, p2.y);
  _Type maxX = max(p1.x, p2.x);
  _Type maxY = max(p1.y, p2.y);
  return pt.x >= minX && pt.x <= maxX && pt.y >= minY && pt.y <= maxY;
}

struct Segment {
  PointVector2D<i64> a, b;
};

bool check(const Segment& A, const Segment& B, const Segment& C) {
  if ( A.a != B.a ) return false;
  PointVector2D<i64> p0 = A.a;
  PointVector2D<i64> p1 = A.b;
  PointVector2D<i64> p2 = B.b;
  if ( Orientation(p0, p1, p2) == COLINE ) return false;
  if ( (p1 - p0) * (p2 - p0) < 0 ) return false;
  PointVector2D<i64> i0, i1;
  if ( Orientation(p0, p1, C.a) == COLINE && Orientation(p0, p1, C.b) == COLINE ) return false;
  if ( Orientation(p0, p2, C.a) == COLINE && Orientation(p0, p2, C.b) == COLINE ) return false;
  if ( Orientation(p0, p1, C.a) == COLINE ) i0 = C.a;
  else if ( Orientation(p0, p1, C.b) == COLINE ) i0 = C.b;
  else return false;
  if ( Orientation(p0, p2, C.a) == COLINE ) i1 = C.a;
  else if ( Orientation(p0, p2, C.b) == COLINE ) i1 = C.b;
  else return false;
  if ( i0 == i1 ) return false;
  if ( !IsInSegment(p0, p1, i0) ) return false;
  if ( !IsInSegment(p0, p2, i1) ) return false;
  i64 d00 = DistanceSq(p0, i0);
  i64 d01 = DistanceSq(p1, i0);
  i64 d10 = DistanceSq(p0, i1);
  i64 d11 = DistanceSq(p2, i1);
  if ( 16 * min(d00, d01) < max(d00, d01) ) return false;
  if ( 16 * min(d10, d11) < max(d10, d11) ) return false;
  return true;
}

bool testcase(Segment& A, Segment& B, Segment& C) {
  if ( check(A, B, C) ) return true;
  swap(A.a, A.b);
  if ( check(A, B, C) ) return true;
  swap(B.a, B.b);
  if ( check(A, B, C) ) return true;
  swap(A.a, A.b);
  if ( check(A, B, C) ) return true;
  return false;
}

int main() {
#ifdef ZYX_MACHINE
  freopen("xxx.in", "rt", stdin);
#ifndef _DEBUG
  freopen("xxx.out", "wt", stdout);
#endif  

#endif  

  WhileTests() {
    Segment A, B, C;
    
    int x;
    scanf("%d", &x); A.a.x = x;
    scanf("%d", &x); A.a.y = x;
    scanf("%d", &x); A.b.x = x;
    scanf("%d", &x); A.b.y = x;
    scanf("%d", &x); B.a.x = x;
    scanf("%d", &x); B.a.y = x;
    scanf("%d", &x); B.b.x = x;
    scanf("%d", &x); B.b.y = x;
    scanf("%d", &x); C.a.x = x;
    scanf("%d", &x); C.a.y = x;
    scanf("%d", &x); C.b.x = x;
    scanf("%d", &x); C.b.y = x;
    if ( testcase(A, B, C) ) printf("YES\n");
    else if ( testcase(A, C, B) ) printf("YES\n");
    else if ( testcase(B, A, C) ) printf("YES\n");
    else if ( testcase(B, C, A) ) printf("YES\n");
    else if ( testcase(C, A, B) ) printf("YES\n");
    else if ( testcase(C, B, A) ) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}












