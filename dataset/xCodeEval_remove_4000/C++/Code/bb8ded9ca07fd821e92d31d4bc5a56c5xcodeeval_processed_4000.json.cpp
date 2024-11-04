





























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






static char stringReader[2097152];
static inline bool ReadLine() {
  char* ptr = fgets(stringReader, sizeof(stringReader), stdin);
  if ( ptr == 0 ) return false;
  int N = strlen(stringReader);
  if ( stringReader[N - 1] == '\n' ) stringReader[N - 1] = 0;
  return true;
}



























































































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

  freopen("xxx.in", "rt", stdin);
  



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








