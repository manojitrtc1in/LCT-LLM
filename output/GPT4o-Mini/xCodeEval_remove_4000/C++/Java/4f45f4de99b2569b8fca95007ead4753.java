import java.util.*;

public class 4f45f4de99b2569b8fca95007ead4753xcodeeval_processed_4000.json {
    static final int MOD = 1000000007;
    static final long MODL = 1000000000000000003L;
    static final double eps = 1e-8;

    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static long MIN(long x, long y) { return Math.min(x, y); }
    static long MAX(long x, long y) { return Math.max(x, y); }

    static void id1(long[] x, long y) { if (x[0] > y) x[0] = y; }
    static void id0(long[] x, long y) { if (x[0] < y) x[0] = y; }

    static int SIZE(List<?> x) { return x.size(); }
    static int LENGTH(String x) { return x.length(); }
    static Pair MP(int x, int y) { return new Pair(x, y); }

    static int BINT(int x) { return 1 << x; }
    static long BLLD(int x) { return 1L << x; }
    static boolean id9(int s, int x) { return (s & BINT(x)) != 0; }
    static boolean id5(long s, int x) { return (s & BLLD(x)) != 0; }

    static long LOWBIT(long x) { return (x ^ (x - 1)) & x; }
    static int BITCOUNT(long x) { return (x == 0) ? 0 : (1 + BITCOUNT(x & (x - 1))); }

    static final double PI = Math.acos(-1.0);
    static final double EPS = 1e-5;

    static long SQR(long x) { return x * x; }
    static long POW(long x, long y) {
        if (y == 0) return 1;
        else if ((y & 1) == 0) {
            return SQR(POW(x, y >> 1));
        } else return POW(x, y ^ 1) * x;
    }

    static long GCD(long x, long y) {
        if (x < 0) return GCD(-x, y);
        if (y < 0) return GCD(x, -y);
        return (y == 0) ? x : GCD(y, x % y);
    }

    static long LCM(long x, long y) {
        if (x < 0) return LCM(-x, y);
        if (y < 0) return LCM(x, -y);
        return x * (y / GCD(x, y));
    }

    static long EEA(long a, long b, long[] x, long[] y) {
        if (a < 0) {
            long d = EEA(-a, b, x, y);
            x[0] = -x[0];
            return d;
        }
        if (b < 0) {
            long d = EEA(a, -b, x, y);
            y[0] = -y[0];
            return d;
        }
        if (b == 0) {
            x[0] = 1; y[0] = 0; return a;
        } else {
            long d = EEA(b, a % b, x, y);
            long t = x[0]; x[0] = y[0]; y[0] = t - (a / b) * y[0];
            return d;
        }
    }

    static List<Pair> id2(long x) {
        List<Pair> ret = new ArrayList<>();
        if (x < 0) x = -x;
        for (long i = 2; x > 1; ) {
            if (x % i == 0) {
                int count = 0;
                while (x % i == 0) {
                    x /= i;
                    count++;
                }
                ret.add(MP((int) i, count));
            }
            i++;
            if (i > x / i) i = x;
        }
        return ret;
    }

    static boolean id16(long x) {
        if (x <= 1) return false;
        for (long i = 2; SQR(i) <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    static long id6(long x) {
        List<Pair> f = id2(x);
        for (Pair it : f) {
            x = x / it.first * (it.first - 1);
        }
        return x;
    }

    static long id14(long a, long b) {
        long[] x = new long[1], y = new long[1];
        EEA(a, b, x, y);
        return (x[0] != 0) ? x[0] : 1;
    }

    static int[] id15(int til, int[] length) {
        int[] foo = new int[til + 1];
        int len = 0;
        Arrays.fill(foo, 0);
        for (int i = 2; i <= til; i++) {
            if (foo[i] == 0) foo[len++] = i;
            for (int j = 0; j < len && foo[j] <= til / i; j++) {
                foo[foo[j] * i] = 1;
                if (i % foo[j] == 0) break;
            }
        }
        if (length != null) {
            length[0] = len;
        }
        foo = Arrays.copyOf(foo, len + 1);
        foo[len] = 0;
        return foo;
    }

    static long MOD_STD(long x, long m) { return (x % m + m) % m; }
    static void MOD_STD(long[] x, long m) { x[0] = (x[0] % m + m) % m; }
    static long MOD_ADD(long x, long y, long m) { return (x + y) % m; }
    static void MOD_ADD(long[] x, long y, long m) { x[0] = (x[0] + y) % m; }
    static long id4(long x, long y, long m) { return (1L * x * y) % m; }
    static void id4(long[] x, long y, long m) { x[0] = (1L * x[0] * y) % m; }
    static long id10(long x, long y, long m) {
        if (y == 0) return 1 % m;
        else if ((y & 1) == 0) {
            long z = id10(x, y >> 1, m);
            return id4(z, z, m);
        } else return id4(id10(x, y ^ 1, m), x, m);
    }

    static long id12(long x, long y, long m) {
        if (x < y) {
            long temp = x;
            x = y;
            y = temp;
        }
        long z = 0;
        while (y > 0) {
            if ((y & 1) != 0) {
                MOD_ADD(new long[]{z}, x, m);
            }
            MOD_ADD(new long[]{x}, x, m);
            y >>= 1;
        }
        return z;
    }

    static long id3(long x, long y, long m) {
        if (y == 0) return 1L % m;
        else if ((y & 1) == 0) {
            long z = id3(x, y >> 1, m);
            return id12(z, z, m);
        } else return id12(id3(x, y ^ 1, m), x, m);
    }

    static class MATX<T> {
        private long hig, wid;
        private T[] data;

        @SuppressWarnings("unchecked")
        private void __init() {
            this.data = (T[]) new Object[(int) (this.hig * this.wid)];
            Arrays.fill(this.data, null);
        }

        public MATX() {
            this.hig = this.wid = 1;
            __init();
        }

        public MATX(long _len) {
            this.hig = this.wid = _len;
            __init();
        }

        public MATX(long _hig, long _wid) {
            this.hig = _hig;
            this.wid = _wid;
            __init();
        }

        public MATX(MATX<T> rhs) {
            this.hig = rhs.hig;
            this.wid = rhs.wid;
            this.data = (T[]) new Object[(int) (this.hig * this.wid)];
            for (long x = 0; x < this.hig; x++)
                for (long y = 0; y < this.wid; y++)
                    this.data[(int) (x * this.wid + y)] = rhs.at(x, y);
        }

        public T at(long x, long y) {
            if (x >= this.hig || y >= this.wid) return null;
            return this.data[(int) (x * this.wid + y)];
        }

        public MATX<T> add(MATX<T> opn) {
            MATX<T> ret = new MATX<>(this);
            for (long x = 0; x < ret.hig; x++)
                for (long y = 0; y < ret.wid; y++)
                    ret.data[(int) (x * ret.wid + y)] = (T) ((Integer) ret.data[(int) (x * ret.wid + y)] + (Integer) opn.at(x, y));
            return ret;
        }

        public MATX<T> sub(MATX<T> opn) {
            MATX<T> ret = new MATX<>(this);
            for (long x = 0; x < ret.hig; x++)
                for (long y = 0; y < ret.wid; y++)
                    ret.data[(int) (x * ret.wid + y)] = (T) ((Integer) ret.data[(int) (x * ret.wid + y)] - (Integer) opn.at(x, y));
            return ret;
        }

        public MATX<T> mul(MATX<T> opn) {
            MATX<T> ret = new MATX<>(this.hig, opn.wid);
            long len = MIN(this.wid, opn.hig);
            for (long x = 0; x < ret.hig; x++)
                for (long y = 0; y < ret.wid; y++)
                    for (long z = 0; z < len; z++)
                        ret.data[(int) (x * ret.wid + y)] = (T) ((Integer) ret.data[(int) (x * ret.wid + y)] + (Integer) this.at(x, z) * (Integer) opn.at(z, y));
            return ret;
        }

        public void set_one() {
            for (long x = 0; x < this.hig; x++)
                for (long y = 0; y < this.wid; y++)
                    this.data[(int) (x * this.wid + y)] = (x == y) ? (T) Integer.valueOf(1) : (T) Integer.valueOf(0);
        }

        public void show() {
            for (long x = 0; x < this.hig; x++) {
                for (long y = 0; y < this.wid; y++)
                    System.out.print(this.at(x, y) + " ");
                System.out.println();
            }
        }
    }

    static class Complex<T> {
        T r, i;

        Complex(T x, T y) {
            this.r = x;
            this.i = y;
        }

        Complex<T> add(Complex<T> opn) {
            return new Complex<>((T) ((Double) this.r + (Double) opn.r), (T) ((Double) this.i + (Double) opn.i));
        }

        Complex<T> sub(Complex<T> opn) {
            return new Complex<>((T) ((Double) this.r - (Double) opn.r), (T) ((Double) this.i - (Double) opn.i));
        }

        Complex<T> mul(Complex<T> opn) {
            return new Complex<>((T) ((Double) this.r * (Double) opn.r - (Double) this.i * (Double) opn.i),
                                 (T) ((Double) this.r * (Double) opn.i + (Double) this.i * (Double) opn.r));
        }
    }

    static void id8(Complex<Double>[] f, int len, int id11) {
        for (int i = 1, j = len >> 1; i < len - 1; i++) {
            if (i < j) {
                Complex<Double> temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
            int k = len >> 1;
            while (j >= k) {
                j -= k;
                k >>= 1;
            }
            if (j < k) j += k;
        }
        for (int h = 2; h <= len; h <<= 1) {
            Complex<Double> wn = new Complex<>(Math.cos(id11 ? (-2 * PI / h) : (2 * PI / h)),
                                                Math.sin(id11 ? (-2 * PI / h) : (2 * PI / h)));
            for (int i = 0; i < len; i += h) {
                Complex<Double> wm = new Complex<>(1.0, 0.0);
                for (int j = i; j < i + (h >> 1); j++) {
                    Complex<Double> u = f[j];
                    Complex<Double> t = wm.mul(f[j + (h >> 1)]);
                    f[j] = u.add(t);
                    f[j + (h >> 1)] = u.sub(t);
                    wm = wm.mul(wn);
                }
            }
        }
        if (!id11) {
            for (int i = 0; i < len; i++)
                f[i].r = (Double) f[i].r / len;
        }
    }

    static class MILLERRABIN {
        static final int[] prime_table = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        int witness(long a, long d, long s, long n) {
            long r = id3(a, d, n);
            if (r == 1 || r == n - 1) return 0;
            for (int i = 0; i < s - 1; i++) {
                r = id12(r, r, n);
                if (r == 1) return 1;
                if (r == n - 1) return 0;
            }
            return 1;
        }

        int test(long n) {
            if (n <= 2) return 0;
            long p = n - 1, s = 0;
            while ((p & 1) == 0) {
                p >>= 1;
                s++;
            }
            for (int i = 0; i < 12 && prime_table[i] < n; i++) {
                if (witness(prime_table[i], p, s, n) != 0) return 0;
            }
            return 1;
        }
    }

    static int inf = 0x3f3f3f3f;

    static class Id13 {
        Map<Integer, Integer> foo;

        Id13() {
            foo = new HashMap<>();
        }

        void clear() {
            foo.clear();
        }

        void put(int key, int val) {
            if (val == 0) return;
            foo.put(key, foo.getOrDefault(key, 0) + val);
        }

        int pop(int key, int val) {
            int res = 0;
            if (foo.containsKey(key)) {
                if (foo.get(key) > val) {
                    res = val;
                    foo.put(key, foo.get(key) - val);
                } else {
                    res = foo.get(key);
                    foo.remove(key);
                }
            }
            return res;
        }
    }

    static Id13 open = new Id13(), close = new Id13();
    static int n;
    static long[] a = new long[110000];
    static int[] _seq = new int[50], _sup = new int[50];
    static int[] seq = new int[50], sup = new int[50];

    static int process(int from) {
        System.arraycopy(_seq, 0, seq, 0, 50);
        System.arraycopy(_sup, 0, sup, 0, 50);
        if (from + from < seq[0]) return 1;
        open.clear();
        close.clear();
        open.put(0, from - (seq[0] - from));
        close.put(0, seq[0] - from);
        for (int i = 1; i < 45; i++) {
            int ext = open.pop(i - 1, seq[i]);
            seq[i] -= ext;
            open.put(i, ext);
            ext = close.pop(i - 1, seq[i]);
            sup[i] += seq[i] - ext;
            close.put(i, ext);
            int cls = open.pop(i, sup[i]);
            sup[i + 1] += sup[i] - cls;
            close.put(i, cls);
        }
        if (sup[45] != 0) return 1;
        return 0;
    }

    static int find(int lef, int rig) {
        while (lef <= rig) {
            int mid = (lef + rig) >> 1;
            if (process(mid) == 0) {
                if (mid == lef || process(mid - 1) != 0) {
                    return mid;
                }
                rig = mid - 1;
            } else {
                lef = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
            }
            Arrays.fill(_seq, 0);
            Arrays.fill(_sup, 0);
            int cur = 0;
            for (int i = 0; i < n; i++) {
                while (a[i] >= (1L << (cur + 1))) cur++;
                if (a[i] == (1L << cur)) {
                    _seq[cur]++;
                } else {
                    _sup[cur]++;
                }
            }
            if (process(_seq[0]) != 0) {
                System.out.println("-1");
            } else {
                int hig = _seq[0];
                int low = find(1, hig);
                for (int i = low; i <= hig; i++) {
                    if (i != low) System.out.print(" ");
                    System.out.print(i);
                }
                System.out.println();
            }
        }
        scanner.close();
    }
}
