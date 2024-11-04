import java.awt.geom.Point2D;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.function.Supplier;

public class Main {
  final static int INF = 1 << 28;
  final static long MOD = 1_000_000_007;
  final static double EPS = 1e-9;
  final static double id5 = (1.0 + Math.sqrt(5)) / 2.0;
  Scanner sc = new Scanner(System.in);

  public static void main(String[] args) {
    new Main().run();
  }

  class En {
    int depth;
    int x, y, r;

    En(int a, int b, int c) {
      x = a;
      y = b;
      r = c;
    }

    boolean isIn(En e) {
      return GeomUtils.abs(e.x - x, e.y - y) < r;
    }

    double sum() {
      return Math.PI * r * r;
    }
  }

  double cal(ArrayList<En> list_) {
    ArrayList<En> list = new ArrayList<>(list_);
    list.sort(Comparator.comparingInt(a -> -a.r));
    double sum = 0;
    ArrayList<En> next = new ArrayList<>();
    for (En en : list) {
      int maxDepth = 0;
      for (En d : next) {
        if (d.isIn(en)) {
          maxDepth = Math.max(maxDepth, d.depth);
        }
      }
      ++maxDepth;
      en.depth = maxDepth;
      next.add(en);
      if (en.depth % 2 == 1) {
        sum += en.sum();
      } else {
        sum -= en.sum();
      }
    }
    return sum;
  }

  double id7(ArrayList<En> next, En en) {
    int maxDepth = 0;
    for (En d : next) {
      if (d.isIn(en)) {
        maxDepth = Math.max(maxDepth, d.depth);
      }
    }
    ++maxDepth;
    if (maxDepth % 2 == 1) {
      return en.sum();
    } else {
      return -en.sum();
    }
  }

  void add(ArrayList<En> next, En en) {
    int maxDepth = 0;
    for (En d : next) {
      if (d.isIn(en)) {
        maxDepth = Math.max(maxDepth, d.depth);
      }
    }
    ++maxDepth;
    en.depth = maxDepth;
    next.add(en);
  }

  void run() {
    int n = ni();
    double sum = 0;
    ArrayList<En> list = new ArrayList<>();
    for (int i = 0; i < n; ++i) {
      int x, y, r;
      x = ni();
      y = ni();
      r = ni();
      En en = new En(x, y, r);
      list.add(en);
    }
    list.sort(Comparator.comparingInt(a -> -a.r));
    ArrayList<En> left = new ArrayList<>();
    ArrayList<En> right = new ArrayList<>();
    double ls = 0;
    double rs = 0;
    for (En en : list) {
      double l = id7(left, en);
      double r = id7(right, en);
      if (l >= r) {
        add(left, en);
        ls += l;
      } else {
        add(right, en);
        rs += r;
      }
    }
    System.out.printf("%.10f\n", ls + rs);
  }

  int ni() {
    return Integer.parseInt(sc.next());
  }

  void debug(Object... os) {
    System.err.println(Arrays.deepToString(os));
  }

  
  long gcd(long a, long b) {
    if (b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

  
  Pair<Long, Long> id8(long m, long n) {
    long[][] mat = id2(m, n);
    return new Pair<>(mat[0][0], mat[0][1]);
  }

  long[][] id2(long m, long n) {
    if (n == 0) {
      return new long[][]{{1, 0}, {0, 1}};
    }
    long k = m / n;
    long[][] K = new long[][]{{0, 1}, {1, -k}};
    long[][] r = id2(n, m % n);
    long[][] dst = new long[2][2];
    for (int y = 0; y < 2; ++y)
      for (int x = 0; x < 2; ++x)
        for (int i = 0; i < 2; ++i)
          dst[y][x] += r[y][i] * K[i][x];
    return dst;
  }

  
  long pow(long a, long r) {
    long sum = 1;
    while (r > 0) {
      if ((r & 1) == 1) {
        sum *= a;
        sum %= MOD;
      }
      a *= a;
      a %= MOD;
      r >>= 1;
    }
    return sum;
  }

  
  long C(int n, int r) {
    long sum = 1;
    for (int i = n; 0 < i; --i) {
      sum *= i;
      sum %= MOD;
    }
    long s = 1;
    for (int i = r; 0 < i; --i) {
      s *= i;
      s %= MOD;
    }
    sum *= pow(s, MOD - 2);
    sum %= MOD;

    long t = 1;
    for (int i = n - r; 0 < i; --i) {
      t *= i;
      t %= MOD;
    }
    sum *= pow(t, MOD - 2);
    sum %= MOD;

    return sum;
  }

  
  double id3(double left, double right, Function<Double, Double> f, Comparator<Double> comp) {
    double c1 = id4(left, right, 1, id5);
    double c2 = id4(left, right, id5, 1);
    double d1 = f.apply(c1);
    double d2 = f.apply(c2);
    while (right - left > 1e-9) {
      if (comp.compare(d1, d2) > 0) {
        right = c2;
        c2 = c1;
        d2 = d1;
        c1 = id4(left, right, 1, id5);
        d1 = f.apply(c1);
      } else {
        left = c1;
        c1 = c2;
        d1 = d2;
        c2 = id4(left, right, id5, 1);
        d2 = f.apply(c2);
      }
    }
    return right;
  }

  
  double id4(double a, double b, double m, double n) {
    return (n * a + m * b) / (m + n);
  }

  
  int next_perm(int v) {
    int t = (v | (v - 1)) + 1;
    return t | ((((t & -t) / (v & -v)) >> 1) - 1);
  }

  static class Util {
    static <T extends Comparable<T>> T max(T a, T b) {
      if (a.compareTo(b) > 0) {
        return a;
      } else {
        return b;
      }
    }

    static <T extends Comparable<T>> T min(T a, T b) {
      if (a.compareTo(b) < 0) {
        return a;
      } else {
        return b;
      }
    }
  }

  
  static class Line {
    double a;
    double b;
    double c;

    
    Line(double a, double b, double c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }

    
    static Line fromPoints(double x1, double y1, double x2, double y2) {
      double dx = x2 - x1;
      double dy = y2 - y1;
      return new Line(dy, -dx, dx * y1 - dy * x1);
    }

    
    Point2D id9(Line l) {
      double d = a * l.b - l.a * b;
      if (d == 0.0) {
        return null;
      }
      double x = (b * l.c - l.b * c) / d;
      double y = (l.a * c - a * l.c) / d;
      return new Point2D.Double(x, y);
    }

    @Override
    public String toString() {
      return "a = " + a + ", b = " + b + ", c = " + c;
    }
  }

  static class id1 {
    int x1;
    int x2;

    

    id1(int x1, int x2) {
      this.x1 = x1;
      this.x2 = x2;
    }

    boolean isCross(id1 l) {
      return isCross(l.x1, l.x2);
    }

    boolean isCross(int y1, int y2) {
      boolean ret = x1 < y2 && y1 < x2;
      assert ret == new LineSegment(x1, 0, x2, 0).intersects(new LineSegment(y1, 0, y2, 0));
      return ret;
    }
  }

  
  static public class LineSegment {
    double x1;
    double y1;
    double x2;
    double y2;

    LineSegment(double x1, double y1, double x2, double y2) {
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
    }

    Line toLine() {
      return Line.fromPoints(x1, y1, x2, y2);
    }

    boolean intersects(Line l) {
      double t1 = l.a * x1 + l.b * y1 + l.c;
      double t2 = l.a * x2 + l.b * y2 + l.c;
      return t1 * t2 <= 0;
    }

    boolean intersects(LineSegment s) {
      return bothSides(s) && s.bothSides(this);
    }

    

    private boolean bothSides(LineSegment s) {
      double id0 = GeomUtils.ccw(x1, y1, s.x1, s.y1, x2, y2);
      double id11 = GeomUtils.ccw(x1, y1, s.x2, s.y2, x2, y2);
      if (id0 == 0 && id11 == 0) { 

        

        

        return internal(s.x1, s.y1) || internal(s.x2, s.y2);
      } else { 

        

        return id0 * id11 <= 0;
      }
    }

    

    private boolean internal(double x, double y) {
      

      return GeomUtils.dot(x1 - x, y1 - y, x2 - x, y2 - y) <= 0;
    }

    public Point2D id9(Line l) {
      if (!intersects(l)) {
        return null; 

      }
      return l.id9(toLine());
    }

    public Point2D id9(LineSegment s) {
      if (!intersects(s)) {
        return null; 

      }
      return s.toLine().id9(toLine());
    }

    
    double distance(double x0, double y0) {
      

      if (GeomUtils.dot(x2 - x1, y2 - y1, x0 - x1, y0 - y1) < EPS) {
        return GeomUtils.abs(x0 - x1, y0 - y1);
      }
      if (GeomUtils.dot(x1 - x2, y1 - y2, x0 - x2, y0 - y2) < EPS) {
        return GeomUtils.abs(x0 - x2, y0 - y2);
      }
      

      return Math.abs(GeomUtils.cross(x2 - x1, y2 - y1, x0 - x1, y0 - y1)) / GeomUtils.abs(x2 - x1, y2 - y1);
    }

    double distance(LineSegment l) {
      if (this.intersects(l)) {
        return 0.0;
      }
      double min = Double.MAX_VALUE;
      min = Math.min(min, distance(l.x1, l.y1));
      min = Math.min(min, distance(l.x2, l.y2));
      min = Math.min(min, l.distance(x1, y1));
      min = Math.min(min, l.distance(x2, y2));
      return min;
    }

    @Override
    public String toString() {
      return "(" + x1 + ", " + y1 + ") - (" + x2 + ", " + y2 + ")";
    }
  }

  
  static class GeomUtils {
    

    static double cross(double x1, double y1, double x2, double y2) {
      return x1 * y2 - x2 * y1;
    }

    

    static double dot(double x1, double y1, double x2, double y2) {
      return x1 * x2 + y1 * y2;
    }

    

    

    static double ccw(double x1, double y1, double x2, double y2,
                      double x3, double y3) {
      return cross(x2 - x1, y2 - y1, x3 - x2, y3 - y2);
    }

    static double ccw(Point2D p1, Point2D p2, Point2D p3) {
      return ccw(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY());
    }

    

    static double abs(double x, double y) {
      return Math.sqrt(x * x + y * y);
    }
  }

  
  static class FastScanner {
    private final InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    public FastScanner(InputStream in) {
      this.in = in;
    }

    private static boolean id12(int c) {
      return 33 <= c && c <= 126;
    }

    private boolean id10() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (id10()) return buffer[ptr++];
      else return -1;
    }

    private void id6() {
      while (id10() && !id12(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      id6();
      return id10();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (id12(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    public long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
      long n = 0;
      boolean minus = false;
      int b = readByte();
      if (b == '-') {
        minus = true;
        b = readByte();
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException();
      }
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !id12(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }
  }

  static class Pair<F extends Comparable<F>, S extends Comparable<S>> implements Comparable<Pair<F, S>> {
    F f;
    S s;

    Pair() {
    }

    Pair(F f, S s) {
      this.f = f;
      this.s = s;
    }

    Pair(Pair<F, S> p) {
      f = p.f;
      s = p.s;
    }

    @Override
    public int compareTo(Pair<F, S> p) {
      if (f.compareTo(p.f) != 0) {
        return f.compareTo(p.f);
      }
      return s.compareTo(p.s);
    }

    @Override
    public int hashCode() {
      return f.hashCode() ^ s.hashCode();
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null || this.f == null || this.s == null) {
        return false;
      }
      if (this.getClass() != o.getClass()) {
        return false;
      }
      Pair p = (Pair) o;
      return this.f.equals(p.f) && this.s.equals(p.s);
    }

    @Override
    public String toString() {
      return "{" + f.toString() + ", " + s.toString() + "}";
    }
  }

  class BIT<T> {
    int n;
    ArrayList<T> bit;
    BiFunction<T, T, T> bif;

    
    BIT(int n, BiFunction<T, T, T> bif, Supplier<T> sup) {
      this.n = n;
      bit = new ArrayList<>(n + 1);
      for (int i = 0; i < n + 1; ++i) {
        bit.add(sup.get());
      }
      this.bif = bif;
    }

    
    void set(int i, T v) {
      for (int x = i; x <= n; x += x & -x) {
        bit.set(x, bif.apply(bit.get(x), v));
      }
    }

    
    T reduce(T defaultValue, int i) {
      T ret = defaultValue;
      for (int x = i; x > 0; x -= x & -x) {
        ret = bif.apply(ret, bit.get(x));
      }
      return ret;
    }
  }

  class SegmentTree<T> {
    int n;
    ArrayList<T> dat;
    BiFunction<T, T, T> bif;
    Supplier<T> sup;

    
    SegmentTree(int n_, BiFunction<T, T, T> bif, Supplier<T> sup) {
      n = 1;
      while (n < n_) n *= 2;

      dat = new ArrayList<>(2 * n - 1);
      for (int i = 0; i < 2 * n - 1; ++i) {
        dat.add(sup.get());
      }
      this.bif = bif;
      this.sup = sup;
    }

    
    void set(int k, T v) {
      k += n - 1;
      dat.set(k, v);
      while (k > 0) {
        k = (k - 1) / 2;
        dat.set(k, bif.apply(dat.get(k * 2 + 1), dat.get(k * 2 + 2)));
      }
    }

    
    T reduce(int l, int r) {
      return _reduce(l, r, 0, 0, n);
    }

    T _reduce(int a, int b, int k, int l, int r) {
      if (r <= a || b <= l) return sup.get();
      if (a <= l && r <= b) return dat.get(k);
      T vl = _reduce(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = _reduce(a, b, k * 2 + 2, (l + r) / 2, r);
      return bif.apply(vl, vr);
    }
  }

  class UnionFind {
    int[] par;

    UnionFind(int n) {
      par = new int[n];
      for (int i = 0; i < n; ++i) {
        par[i] = i;
      }
    }

    int find(int x) {
      if (par[x] == x) {
        return x;
      }
      return par[x] = find(x);
    }

    boolean same(int x, int y) {
      return find(x) == find(y);
    }

    void union(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) {
        return;
      }
      par[x] = y;
    }
  }
}

