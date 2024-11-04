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



void dprintf(char* format, ...) {
  fprintf(stderr, "DEBUG: ");
  va_list argp; va_start(argp, format);
  vfprintf(stderr, format, argp); va_end(argp);
  fprintf(stderr, "\n");
}





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
#define InInt1(X) int X; scanf("%d", &X)
#define InInt2(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define InInt3(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define InVectorLine(X, N) vector<string> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) ReadLine(), X[i_##X] = stringReader;
#define InVectorString(X, N) vector<string> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%s", stringReader), X[i_##X] = stringReader
#define InVectorDouble(X, N) vector<double> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lf", &X[i_##X])
#define InVectorI64(X, N) vector<i64> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lld", &X[i_##X])
#define InVectorInt(X, N) vector<int> X(N); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%d", &X[i_##X])
#define InVectorGlobalLine(X, N) X.assign(N, ""); for ( int i_##X = 0; i_##X < N; ++i_##X ) ReadLine(), X[i_##X] = stringReader;
#define InVectorGlobalString(X, N) X.assign(N, ""); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%s", stringReader), X[i_##X] = stringReader
#define InVectorGlobalDouble(X, N) X.assign(N, 0); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lf", &X[i_##X])
#define InVectorGlobalI64(X, N) X.assign(N, 0); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lld", &X[i_##X])
#define InVectorGlobalInt(X, N) X.assign(N, 0); for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%d", &X[i_##X])
#define InArrayLine(X, N, MAX_N) string X[MAX_N]; for ( int i_##X = 0; i_##X < N; ++i_##X ) ReadLine(), X[i_##X] = stringReader;
#define InArrayString(X, N, MAX_N) string X[MAX_N]; for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%s", stringReader), X[i_##X] = stringReader
#define InArrayDouble(X, N, MAX_N) double X[MAX_N]; for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lf", &X[i_##X])
#define InArrayI64(X, N, MAX_N) i64 X[MAX_N]; for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lld", &X[i_##X])
#define InArrayInt(X, N, MAX_N) int X[MAX_N]; for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%d", &X[i_##X])
#define InArrayLineGlobal(X, N) for ( int i_##X = 0; i_##X < N; ++i_##X ) ReadLine(), X[i_##X] = stringReader;
#define InArrayStringGlobal(X, N) for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%s", stringReader), X[i_##X] = stringReader
#define InArrayDoubleGlobal(X, N) for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lf", &X[i_##X])
#define InArrayI64Global(X, N) for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%lld", &X[i_##X])
#define InArrayIntGlobal(X, N) for ( int i_##X = 0; i_##X < N; ++i_##X ) scanf("%d", &X[i_##X])
#define WhileTests() int TOTAL_TEST_CASES; ReadLine(); sscanf(stringReader, "%d", &TOTAL_TEST_CASES); for ( int current_test_case = 1; current_test_case <= TOTAL_TEST_CASES; ++current_test_case )
#define WhileInString(X) int current_test_case = 1; for ( string X; scanf("%s", &X) == 1 && (X != ""); ++current_test_case )
#define WhileInI641(X) int current_test_case = 1; for ( i64 X; scanf("%lld", &X) == 1 && (X); ++current_test_case )
#define WhileInI642(X, Y) int current_test_case = 1; for ( i64 X, Y, current_test_case = 1; scanf("%lld%lld", &X, &Y) == 2 && (X|Y); ++current_test_case )
#define WhileInI643(X, Y, Z) int current_test_case = 1; for ( i64 X, Y, Z, current_test_case = 1; scanf("%lld%lld%lld", &X, &Y, &Z) == 3 && (X|Y|Z); ++current_test_case )
#define WhileInInt1(X) for ( int X, current_test_case = 1; scanf("%d", &X) == 1 && (X); ++current_test_case )
#define WhileInInt2(X, Y) for ( int X, Y, current_test_case = 1; scanf("%d%d", &X, &Y) == 2 && (X|Y); ++current_test_case )
#define WhileInInt3(X, Y, Z) for ( int X, Y, Z, current_test_case = 1; scanf("%d%d%d", &X, &Y, &Z) == 3 && (X|Y|Z); ++current_test_case )
#define WhileInGlobalI641(X) for ( int current_test_case = 1; scanf("%lld", &X) == 1 && (X); ++current_test_case )
#define WhileInGlobalI642(X, Y) for ( int current_test_case = 1; scanf("%lld%lld", &X, &Y) == 2 && (X|Y); ++current_test_case )
#define WhileInGlobalI643(X, Y, Z) for ( int current_test_case = 1; scanf("%lld%lld%lld", &X, &Y, &Z) == 3 && (X|Y|Z); ++current_test_case )
#define WhileInGlobalInt1(X) for ( int current_test_case = 1; scanf("%d", &X) == 1 && (X); ++current_test_case )
#define WhileInGlobalInt2(X, Y) for ( int current_test_case = 1; scanf("%d%d", &X, &Y) == 2 && (X|Y); ++current_test_case )
#define WhileInGlobalInt3(X, Y, Z) for ( int current_test_case = 1; scanf("%d%d%d", &X, &Y, &Z) == 3 && (X|Y|Z); ++current_test_case )
#define WhileInStringEOF(X) int current_test_case = 1; for ( string X; scanf("%s", &X) == 1; ++current_test_case )
#define WhileInI641EOF(X) int current_test_case = 1; for ( i64 X; scanf("%lld", &X) == 1; ++current_test_case )
#define WhileInI642EOF(X, Y) int current_test_case = 1; for ( i64 X, Y, current_test_case = 1; scanf("%lld%lld", &X, &Y) == 2; ++current_test_case )
#define WhileInI643EOF(X, Y, Z) int current_test_case = 1; for ( i64 X, Y, Z, current_test_case = 1; scanf("%lld%lld%lld", &X, &Y, &Z) == 3; ++current_test_case )
#define WhileInInt1EOF(X) for ( int X, current_test_case = 1; scanf("%d", &X) == 1; ++current_test_case )
#define WhileInInt2EOF(X, Y) for ( int X, Y, current_test_case = 1; scanf("%d%d", &X, &Y) == 2; ++current_test_case )
#define WhileInInt3EOF(X, Y, Z) for ( int X, Y, Z, current_test_case = 1; scanf("%d%d%d", &X, &Y, &Z) == 3; ++current_test_case )
#define WhileInGlobalI641EOF(X) for ( int current_test_case = 1; scanf("%lld", &X) == 1; ++current_test_case )
#define WhileInGlobalI642EOF(X, Y) for ( int current_test_case = 1; scanf("%lld%lld", &X, &Y) == 2; ++current_test_case )
#define WhileInGlobalI643EOF(X, Y, Z) for ( int current_test_case = 1; scanf("%lld%lld%lld", &X, &Y, &Z) == 3; ++current_test_case )
#define WhileInGlobalInt1EOF(X) for ( int current_test_case = 1; scanf("%d", &X) == 1; ++current_test_case )
#define WhileInGlobalInt2EOF(X, Y) for ( int current_test_case = 1; scanf("%d%d", &X, &Y) == 2; ++current_test_case )
#define WhileInGlobalInt3EOF(X, Y, Z) for ( int current_test_case = 1; scanf("%d%d%d", &X, &Y, &Z) == 3; ++current_test_case )



i64 size(i64 n, i64 m) {
  if ( n <= 0 || m <= 0 ) return 0;
  return n * m;
}



int main() {
#ifdef ZYX_MACHINE
  freopen("xxx.in", "rt", stdin);
#ifndef _DEBUG
  freopen("xxx.out", "wt", stdout);
#endif  

#endif  

  WhileTests() {
    InInt2(N, M);
    InInt2(x1, y1);
    InInt2(x2, y2);
    int dx = max(x1, x2) - min(x1, x2);
    int dy = max(y1, y2) - min(y1, y2);
    i64 sol = size(N, M);
    sol -= size(N - dx, M - dy) * 2;
    sol += size(N - dx * 2, M - dy * 2);
#ifdef ZYX_MACHINE
    printf("%lld\n", sol);
#else
    printf("%I64d\n", sol);
#endif
  }
  return 0;
}








