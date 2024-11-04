import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Random;
import java.util.TreeSet;
import java.io.OutputStreamWriter;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.io.UncheckedIOException;
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
            DRainbowRectangles solver = new DRainbowRectangles();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DRainbowRectangles {
        int mod = (int) 1e9 + 7;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int l = in.readInt();

            Point[] pts = new Point[n];
            IntegerArrayList xs = new IntegerArrayList();
            IntegerArrayList ys = new IntegerArrayList();
            for (int i = 0; i < n; i++) {
                pts[i] = new Point();
                pts[i].x = in.readInt();
                pts[i].y = in.readInt();
                pts[i].c = in.readInt() - 1;
                xs.add(pts[i].x);
                ys.add(pts[i].y);
            }
            xs.add(0);
            xs.add(l - 1);
            ys.add(0);
            ys.add(l - 1);
            xs.unique();
            ys.unique();

            for (Point pt : pts) {
                pt.x = xs.binarySearch(pt.x);
                pt.y = ys.binarySearch(pt.y);
            }

            int[] xArrays = xs.toArray();
            int m = xArrays.length;
            int[] yArrays = ys.toArray();

            int[] up = new int[yArrays.length];
            int[] bot = new int[yArrays.length];
            for (int i = 0; i < bot.length; i++) {
                if (i == 0) {
                    bot[i] = 1;
                } else {
                    bot[i] = yArrays[i] - yArrays[i - 1];
                }

                if (i == bot.length - 1) {
                    up[i] = 1;
                } else {
                    up[i] = yArrays[i + 1] - yArrays[i];
                }
            }

            int[] left = new int[m];
            int[] right = new int[m];
            for (int i = 0; i < m; i++) {
                if (i == 0) {
                    left[i] = 1;
                } else {
                    left[i] = xArrays[i] - xArrays[i - 1];
                }

                if (i == m - 1) {
                    right[i] = 1;
                } else {
                    right[i] = xArrays[i + 1] - xArrays[i];
                }
            }
            LongPreSum rPs = new LongPreSum(i -> right[i], right.length);

            Point[] ptsSortByY = pts.clone();
            Point[] ptsSortByX = pts.clone();
            Arrays.sort(ptsSortByY, (a, b) -> Integer.compare(a.y, b.y));
            Arrays.sort(ptsSortByX, (a, b) -> Integer.compare(a.x, b.x));
            TreeSet<Point>[] sets = new TreeSet[k];
            for (int i = 0; i < k; i++) {
                sets[i] = new TreeSet<>((a, b) -> a.x == b.x ? Integer.compare(a.y, b.y) : Integer.compare(a.x, b.x));
            }

            int[] next = new int[m];
            long[] remains = new long[m];
            Counter counter = new Counter(k);

            SegmentBeat sb = new SegmentBeat(0, m - 1);
            long ans = 0;
            for (int i = 0; i < yArrays.length; i++) {
                for (TreeSet<Point> set : sets) {
                    set.clear();
                }

                

                counter.clear();
                Range2DequeAdapter<Point> tail = new Range2DequeAdapter<>(x -> ptsSortByX[x], 0, ptsSortByX.length - 1);
                Range2DequeAdapter<Point> head = new Range2DequeAdapter<>(x -> ptsSortByX[x], 0, ptsSortByX.length - 1);
                int last = 0;
                for (int j = 0; j < m; j++) {
                    while (!head.isEmpty() && head.peekFirst().x < j) {
                        Point h = head.removeFirst();
                        if (h.y < i) {
                            continue;
                        }
                        counter.remove(h.c);
                    }
                    while (!tail.isEmpty() && counter.distinct < k) {
                        Point h = tail.removeFirst();
                        if (h.y < i) {
                            continue;
                        }
                        last = h.x;
                        counter.add(h.c);
                    }
                    if (counter.distinct == k) {
                        next[j] = last;
                    } else {
                        next[j] = m;
                    }
                    remains[j] = rPs.post(next[j]);
                }
                for (Point pt : pts) {
                    if (pt.y < i) {
                        continue;
                    }
                    sets[pt.c].add(pt);
                }

                sb.init(0, m - 1, x -> left[x], x -> remains[x]);
                Range2DequeAdapter<Point> top = new Range2DequeAdapter<>(x -> ptsSortByY[x], 0, ptsSortByY.length - 1);
                for (int j = yArrays.length - 1; j >= i; j--) {
                    while (!top.isEmpty() && top.peekLast().y > j) {
                        Point back = top.removeLast();
                        sets[back.c].remove(back);
                        Point floor = sets[back.c].floor(back);
                        Point ceil = sets[back.c].ceiling(back);
                        int from = floor == null ? 0 : floor.x + 1;
                        long min = ceil == null ? 0 : rPs.post(ceil.x);
                        sb.updateMin(from, m - 1, 0, m - 1, min);
                    }
                    

                    long contrib = sb.querySum(0, m - 1, 0, m - 1) % mod * up[j] % mod * bot[i] % mod;
                    ans += contrib;
                }
            }

            ans %= mod;
            out.println(ans);
        }

    }

    static class Point {
        int x;
        int y;
        int c;

    }

    static class LongPreSum {
        private long[] pre;
        private int n;

        public LongPreSum(int n) {
            pre = new long[n];
        }

        public void populate(IntToLongFunction a, int n) {
            this.n = n;
            if (n == 0) {
                return;
            }
            pre[0] = a.apply(0);
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a.apply(i);
            }
        }

        public LongPreSum(IntToLongFunction a, int n) {
            this(n);
            populate(a, n);
        }

        public long prefix(int i) {
            i = Math.min(i, n - 1);
            if (i < 0) {
                return 0;
            }
            return pre[i];
        }

        public long post(int i) {
            return prefix(n) - prefix(i - 1);
        }

    }

    static class Range2DequeAdapter<T> implements SimplifiedDeque<T> {
        IntFunction<T> data;
        int l;
        int r;

        public Range2DequeAdapter(IntFunction<T> data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekFirst() {
            return data.apply(l);
        }

        public T removeFirst() {
            return data.apply(l++);
        }

        public T peekLast() {
            return data.apply(r);
        }

        public T removeLast() {
            return data.apply(r--);
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data.apply(iter++);
                }
            };
        }

    }

    static class Randomized {
        public static void shuffle(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return RandomWrapper.INSTANCE.nextInt(l, r);
        }

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
    }

    static class SequenceUtils {
        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
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

    static interface IntToLongFunction {
        long apply(int x);

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
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

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
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

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerArrayList list) {
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

        public int binarySearch(int x) {
            return Arrays.binarySearch(data, 0, size, x);
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static class SegmentBeat implements Cloneable {
        private SegmentBeat left;
        private SegmentBeat right;
        private long first;
        private long second;
        private long firstCnt;
        private static long inf = (long) 2e18;
        private static int mod = (int) 1e9 + 7;
        private static Modular modular = new Modular(mod);
        private long sum;

        private void setMin(long x) {
            if (first <= x) {
                return;
            }
            sum -= (first - x) * firstCnt;
            sum = modular.valueOf(sum);
            first = x;
        }

        public void pushUp() {
            first = Math.max(left.first, right.first);
            second = Math.max(left.first == first ? left.second : left.first, right.first == first ? right.second : right.first);
            firstCnt = (left.first == first ? left.firstCnt : 0) + (right.first == first ? right.firstCnt : 0);
            sum = (left.sum + right.sum) % mod;
        }

        public void pushDown() {
            left.setMin(first);
            right.setMin(first);
        }

        public SegmentBeat(int l, int r) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left = new SegmentBeat(l, m);
                right = new SegmentBeat(m + 1, r);
                pushUp();
            } else {
            }
        }

        public void init(int l, int r, IntToLongFunction size, IntToLongFunction remain) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left.init(l, m, size, remain);
                right.init(m + 1, r, size, remain);
                pushUp();
            } else {
                first = remain.apply(l);
                second = -inf;
                firstCnt = size.apply(l);
                sum = first * firstCnt % mod;
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void updateMin(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                if (first <= x) {
                    return;
                }
                if (second < x) {
                    setMin(x);
                    return;
                }
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            left.updateMin(ll, rr, l, m, x);
            right.updateMin(ll, rr, m + 1, r, x);
            pushUp();
        }

        public long querySum(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return sum;
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            return left.querySum(ll, rr, l, m) +
                    right.querySum(ll, rr, m + 1, r);
        }

        private SegmentBeat deepClone() {
            SegmentBeat seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected SegmentBeat clone() {
            try {
                return (SegmentBeat) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append(sum).append(",");
                return;
            }
            pushDown();
            left.toString(builder);
            right.toString(builder);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            deepClone().toString(builder);
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }

    }

    static class Counter {
        int[] cnts;
        int distinct;

        public Counter(int n) {
            cnts = new int[n];
        }

        public void clear() {
            Arrays.fill(cnts, 0);
            distinct = 0;
        }

        public void add(int x) {
            cnts[x]++;
            if (cnts[x] == 1) {
                distinct++;
            }
        }

        public void remove(int x) {
            cnts[x]--;
            if (cnts[x] == 0) {
                distinct--;
            }
        }

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
    }
}

