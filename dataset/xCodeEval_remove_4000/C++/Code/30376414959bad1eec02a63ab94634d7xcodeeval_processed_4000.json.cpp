










template<typename _Type>
int id2(_Type x) {
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
int id1(_Type x) {
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





























using namespace std;








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
bool id0(const PointVector2D<_Type>& p1, const PointVector2D<_Type>& p2, const PointVector2D<_Type>& pt) {
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
  if ( !id0(p0, p1, i0) ) return false;
  if ( !id0(p0, p2, i1) ) return false;
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

  freopen("xxx.in", "rt", stdin);

  freopen("xxx.out", "wt", stdout);




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












