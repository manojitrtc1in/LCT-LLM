#ifdef _MSC_VER
#pragma warning(disable:4996)  

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
namespace std { long long abs(long long x) { return x < 0 ? -x : x; } }
using namespace std;



void dprintf(char* format, ...) {
  fprintf(stderr, "DEBUG: ");
  va_list argp; va_start(argp, format);
  vfprintf(stderr, format, argp); va_end(argp);
  fprintf(stderr, "\n");
}
struct Exception {
  const char* message;
  const int line;
  Exception(const char* m, int l) : message(m), line(l) {}
};
#define THROW(M) throw Exception(M, __LINE__)





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
#define InString4(X, Y, Z) string X, Y, Z, W; scanf("%s", stringReader); X = stringReader; scanf("%s", stringReader); Y = stringReader; scanf("%s", stringReader); Z = stringReader; scanf("%s", stringReader); W = stringReader
#define InDouble1(X) double X; scanf("%lf", &X)
#define InDouble2(X, Y) double X, Y; scanf("%lf%lf", &X, &Y)
#define InDouble3(X, Y, Z) double X, Y, Z; scanf("%lf%lf%lf", &X, &Y, &Z)
#define InDouble4(X, Y, Z, W) double X, Y, Z, W; scanf("%lf%lf%lf%lf", &X, &Y, &Z, &W)
#define InI641(X) i64 X; scanf("%lld", &X)
#define InI642(X, Y) i64 X, Y; scanf("%lld%lld", &X, &Y)
#define InI643(X, Y, Z) i64 X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define InI644(X, Y, Z, W) i64 X, Y, Z, W; scanf("%lld%lld%lld%lld", &X, &Y, &Z, &W)
#define InInt1(X) int X; scanf("%d", &X)
#define InInt2(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define InInt3(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define InInt4(X, Y, Z, W) int X, Y, Z, W; scanf("%d%d%d%d", &X, &Y, &Z, &W)
#define InGlobalLine(X) ReadLine(); X = stringReader
#define InGlobalString1(X) scanf("%s", stringReader); X = stringReader
#define InGlobalString2(X, Y) scanf("%s", stringReader); X = stringReader; scanf("%s", stringReader); Y = stringReader
#define InGlobalString3(X, Y, Z) scanf("%s", stringReader); X = stringReader; scanf("%s", stringReader); Y = stringReader; scanf("%s", stringReader); Z = stringReader
#define InGlobalString4(X, Y, Z, W) scanf("%s", stringReader); X = stringReader; scanf("%s", stringReader); Y = stringReader; scanf("%s", stringReader); Z = stringReader; scanf("%s", stringReader); W = stringReader
#define InGlobalDouble1(X) scanf("%lf", &X)
#define InGlobalDouble2(X, Y) scanf("%lf%lf", &X, &Y)
#define InGlobalDouble3(X, Y, Z) scanf("%lf%lf%lf", &X, &Y, &Z)
#define InGlobalDouble4(X, Y, Z, W) scanf("%lf%lf%lf%lf", &X, &Y, &Z, &W)
#define InGlobalI641(X) scanf("%lld", &X)
#define InGlobalI642(X, Y) scanf("%lld%lld", &X, &Y)
#define InGlobalI643(X, Y, Z) scanf("%lld%lld%lld", &X, &Y, &Z)
#define InGlobalI644(X, Y, Z, W) scanf("%lld%lld%lld%lld", &X, &Y, &Z, &W)
#define InGlobalInt1(X) scanf("%d", &X)
#define InGlobalInt2(X, Y) scanf("%d%d", &X, &Y)
#define InGlobalInt3(X, Y, Z) scanf("%d%d%d", &X, &Y, &Z)
#define InGlobalInt4(X, Y, Z, W) scanf("%d%d%d%d", &X, &Y, &Z, &W)
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





#define SIZE(N, V) int N = static_cast<int>((V).size())
#define GSIZE(N, V) (N) = static_cast<int>((V).size())
#define ALL(V) (V).begin(), (V).end()
#define UNIQUE(C) {sort(ALL(C)); C.resize(unique(ALL(C)) - C.begin());}
#define CAST(X, Y) {stringstream ss; ss << (X); ss >> (Y);}
typedef long long i64;
const i64 ooLL = 0x3f3f3f3f3f3f3f3fLL;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;






struct Edge {
  int cost;
  int source, destination;
  bool operator<(const Edge& e) const {
    return cost < e.cost;
  }
};
int main() {
#ifdef ZYX_MACHINE
  freopen("xxx.in", "rt", stdin);
  

#endif  

  InInt1(N);
  InVectorInt(q, N);
  InInt1(M);
  vector<Edge> g(M);
  for ( int i = 0; i < M; ++i ) {
    scanf("%d%d%lld", &g[i].source, &g[i].destination, &g[i].cost);
    --g[i].source;
    --g[i].destination;
  }
  sort(ALL(g));
  i64 cost = 0;
  vector<bool> have(N);
  int total = 0;
  for ( int i = 0; i < M; ++i ) if ( !have[g[i].destination] ) {
    cost += g[i].cost;
    ++total;
    have[g[i].destination] = true;
  }
  if ( total < N - 1 ) cost = -1;
  printf("%lld\n", cost);
  return 0;
}








