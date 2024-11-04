import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Random;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            FLineDistance solver = new FLineDistance();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FLineDistance {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long k = in.readLong();
            Point2[] pts = new Point2[n];
            for (int i = 0; i < n; i++) {
                pts[i] = new Point2(in.readInt(), in.readInt());
            }
            double ans = KthNearestLineToPoint.query(Point2.ORIGIN, pts, k,
                    1e-7, 1e-7);
            out.println(ans);
        }

    }

    static class DoubleArrayList implements Cloneable {
        private int size;
        private int cap;
        private double[] data;
        private static final double[] EMPTY = new double[0];

        public DoubleArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new double[cap];
            }
        }

        public DoubleArrayList(double[] data) {
            this(0);
            addAll(data);
        }

        public DoubleArrayList(DoubleArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public DoubleArrayList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        public void add(double x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(double[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(double[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(DoubleArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.shuffle(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public void unique() {
            if (size <= 1) {
                return;
            }

            sort();
            int wpos = 1;
            for (int i = 1; i < size; i++) {
                if (data[i] != data[wpos - 1]) {
                    data[wpos++] = data[i];
                }
            }
            size = wpos;
        }

        public int binarySearch(double x) {
            return Arrays.binarySearch(data, 0, size, x);
        }

        public double[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof DoubleArrayList)) {
                return false;
            }
            DoubleArrayList other = (DoubleArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Double.hashCode(data[i]);
            }
            return h;
        }

        public DoubleArrayList clone() {
            DoubleArrayList ans = new DoubleArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static class RandomWrapper {
        private Random random;
        public static final RandomWrapper INSTANCE = new RandomWrapper(new Random());

        public RandomWrapper() {
            this(new Random());
        }

        public RandomWrapper(Random random) {
            this.random = random;
        }

        public int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class Point2 implements Cloneable {
        public static final Point2 ORIGIN = new Point2(0, 0);
        public final double x;
        public final double y;

        public Point2(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public Point2() {
            this(0, 0);
        }

        public double square() {
            return dot(this, this);
        }

        public Point2 perpendicular() {
            return new Point2(-y, x);
        }

        public static Point2 plus(Point2 a, Point2 b) {
            return new Point2(a.x + b.x, a.y + b.y);
        }

        public static Point2 minus(Point2 a, Point2 b) {
            return new Point2(a.x - b.x, a.y - b.y);
        }

        public static Point2 mul(Point2 a, double d) {
            return new Point2(a.x * d, a.y * d);
        }

        public static double dot(Point2 a, Point2 b) {
            return a.x * b.x + a.y * b.y;
        }

        public static double dist2(Point2 a, Point2 b) {
            double dx = a.x - b.x;
            double dy = a.y - b.y;
            return dx * dx + dy * dy;
        }

        public Point2 clone() {
            try {
                return (Point2) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        public String toString() {
            return String.format("(%.6f, %.6f)", x, y);
        }

    }

    static abstract class DoubleBinarySearch {
        private final double relativeErrorTolerance;
        private final double absoluteErrorTolerance;

        public DoubleBinarySearch(double relativeErrorTolerance, double absoluteErrorTolerance) {
            this.relativeErrorTolerance = relativeErrorTolerance;
            this.absoluteErrorTolerance = absoluteErrorTolerance;
        }

        public abstract boolean check(double mid);

        public double binarySearch(double l, double r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (r - l > absoluteErrorTolerance) {
                if ((r < 0 && (r - l) < -r * relativeErrorTolerance) || (l > 0 && (r - l) < l * relativeErrorTolerance)) {
                    break;
                }

                double mid = (l + r) / 2;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return (l + r) / 2;
        }

    }

    static class SequenceUtils {
        public static boolean equal(double[] a, int al, int ar, double[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 1 << 13;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(double c) {
            cache.append(new BigDecimal(c).toPlainString());
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(double c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class Circle2 {
        public Point2 center;
        public double r;

        public Circle2(Point2 center, double r) {
            this.center = center;
            this.r = r;
        }

        public boolean contain(Point2 pt) {
            return contain(pt, true);
        }

        public boolean contain(Point2 pt, boolean includeCircle) {
            if (includeCircle) {
                return GeoConstant.sign(Point2.dist2(center, pt) - r * r) <= 0;
            } else {
                return GeoConstant.sign(Point2.dist2(center, pt) - r * r) < 0;
            }
        }

        public static int tangent(Point2 o1, double r1, Point2 o2, double r2, boolean inner, List<Point2> out1, List<Point2> out2) {
            if (inner) r2 = -r2;
            Point2 d = Point2.minus(o2, o1);
            double dr = r1 - r2, d2 = d.square(), h2 = d2 - dr * dr;
            if (d2 == 0 || h2 < 0) {
                assert (h2 != 0);
                return 0;
            }
            double sqrtH2 = Math.sqrt(h2);
            for (int sign = -1; sign <= 1; sign += 2) {
                Point2 v = Point2.plus(Point2.mul(d, dr / d2), Point2.mul(d.perpendicular(), sqrtH2 * sign / d2));
                out1.add(new Point2(o1.x + v.x * r1, o1.y + v.y * r1));
                out2.add(new Point2(o2.x + v.x * r2, o2.y + v.y * r2));
            }
            return 1 + (h2 > 0 ? 1 : 0);
        }

    }

    static class Randomized {
        public static void shuffle(double[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                double tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return RandomWrapper.INSTANCE.nextInt(l, r);
        }

    }

    static class GeoConstant {
        public static final double PREC = 1e-12;

        public static boolean isZero(double x) {
            return -PREC <= x && x <= PREC;
        }

        public static int sign(double x) {
            return isZero(x) ? 0 : x < 0 ? -1 : 1;
        }

        public static double theta(double x, double y) {
            double theta = Math.atan2(y, x);
            if (theta < 0) {
                theta += Math.PI * 2;
            }
            return theta;
        }

    }

    static class KthNearestLineToPoint {
        public static double query(Point2 center, Point2[] points, long k, double relativeError, double absoluteError) {
            int n = points.length;
            KthNearestLineToPoint.Item[] items = new KthNearestLineToPoint.Item[n];
            double farthest = 0;
            for (int i = 0; i < n; i++) {
                items[i] = new KthNearestLineToPoint.Item();
                items[i].pt = points[i];
                farthest = Math.max(farthest, Point2.dist2(items[i].pt, center));
            }
            farthest = Math.sqrt(farthest) + 1e3;

            IntegerBIT bit = new IntegerBIT(2 * n);
            DoubleArrayList dal = new DoubleArrayList(2 * n);
            List<KthNearestLineToPoint.Item> outter = new ArrayList<>(n);
            DoubleBinarySearch dbs = new DoubleBinarySearch(relativeError, absoluteError) {

                public boolean check(double mid) {
                    Circle2 c = new Circle2(center, mid);
                    List<Point2> a2 = new ArrayList<>(2);
                    List<Point2> b2 = new ArrayList<>(2);
                    outter.clear();
                    dal.clear();
                    bit.clear();
                    for (KthNearestLineToPoint.Item p : items) {
                        a2.clear();
                        b2.clear();
                        if (c.contain(p.pt)) {
                            continue;
                        }
                        outter.add(p);
                        Circle2.tangent(c.center, c.r, p.pt, 0, false, a2, b2);
                        p.t1 = GeoConstant.theta(a2.get(0).x, a2.get(0).y);
                        p.t2 = GeoConstant.theta(a2.get(1).x, a2.get(1).y);
                        dal.add(p.t1);
                        dal.add(p.t2);
                    }
                    dal.unique();
                    for (KthNearestLineToPoint.Item pt : outter) {
                        pt.l = dal.binarySearch(pt.t1) + 1;
                        pt.r = dal.binarySearch(pt.t2) + 1;
                        if (pt.l > pt.r) {
                            int tmp = pt.l;
                            pt.l = pt.r;
                            pt.r = tmp;
                        }
                    }
                    outter.sort((a, b) -> Integer.compare(a.r, b.r));
                    long noIntersect = 0;
                    for (KthNearestLineToPoint.Item pt : outter) {
                        noIntersect += bit.query(pt.l, pt.r);
                        bit.update(pt.r, 1);
                        bit.update(pt.l - 1, -1);
                    }
                    return (long) n * (n - 1) / 2 - noIntersect >= k;
                }
            };

            return dbs.binarySearch(0, farthest);
        }

        private static class Item {
            Point2 pt;
            double t1;
            double t2;
            int l;
            int r;

        }

    }

    static class IntegerBIT {
        private int[] data;
        private int n;

        public IntegerBIT(int n) {
            this.n = n;
            data = new int[n + 1];
        }

        public int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        public int query(int l, int r) {
            return query(r) - query(l - 1);
        }

        public void update(int i, int mod) {
            if (i <= 0) {
                return;
            }
            for (; i <= n; i += i & -i) {
                data[i] += mod;
            }
        }

        public void clear() {
            Arrays.fill(data, 0);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }

    }
}

