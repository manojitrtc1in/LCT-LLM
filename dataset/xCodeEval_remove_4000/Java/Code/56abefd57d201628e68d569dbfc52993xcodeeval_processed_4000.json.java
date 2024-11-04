import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            PrintWriter out = new PrintWriter(outputStream);
            id2 solver = new id2();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id2 {
        public void solve(int testNumber, FastInput in, PrintWriter out) {
            int n = in.readInt();
            long[] a = new long[n];
            in.populate(a);
            int m = in.readInt();
            id3.Query[] qs = new id3.Query[m];
            for (int i = 0; i < m; i++) {
                qs[i] = new id3.Query(in.readInt() - 1, in.readInt() - 1);
            }
            id3.solve(a, qs);
            for (id3.Query q : qs) {
                out.println(q.ans);
            }
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

    static class CompareUtils {
        private static final int id5 = 8;

        private CompareUtils() {
        }

        public static void insertSort(int[] data, IntegerComparator cmp, int l, int r) {
            for (int i = l + 1; i <= r; i++) {
                int j = i;
                int val = data[i];
                while (j > l && cmp.compare(data[j - 1], val) > 0) {
                    data[j] = data[j - 1];
                    j--;
                }
                data[j] = val;
            }
        }

        public static void quickSort(int[] data, IntegerComparator cmp, int f, int t) {
            if (t - f <= id5) {
                insertSort(data, cmp, f, t - 1);
                return;
            }
            SequenceUtils.swap(data, f, RandomWrapper.INSTANCE.nextInt(f, t - 1));
            int l = f;
            int r = t;
            int m = l + 1;
            while (m < r) {
                int c = cmp.compare(data[m], data[l]);
                if (c == 0) {
                    m++;
                } else if (c < 0) {
                    SequenceUtils.swap(data, l, m);
                    l++;
                    m++;
                } else {
                    SequenceUtils.swap(data, m, --r);
                }
            }
            quickSort(data, cmp, f, l);
            quickSort(data, cmp, m, t);
        }

    }

    static class id1 implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public id1(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public id1(int[] data) {
            this(0);
            addAll(data);
        }

        public id1(id1 list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public id1() {
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

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(id1 list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof id1)) {
                return false;
            }
            id1 other = (id1) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public id1 clone() {
            id1 ans = new id1();
            ans.addAll(this);
            return ans;
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

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

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static class id3 {
        static long inf = (long) 2e18;

        public static void solve(long[] a, id3.Query[] qs) {
            for (id3.Query q : qs) {
                q.ans = inf;
            }
            id3.Query[] sorted = qs.clone();
            Arrays.sort(sorted, (x, y) -> Integer.compare(x.r, y.r));
            solve0(a, sorted);
            long[] b = a.clone();
            long max = (long) 1e18;
            for (int i = 0; i < b.length; i++) {
                b[i] = max - b[i];
            }
            solve0(b, sorted);
        }

        private static void solve0(long[] a, id3.Query[] qs) {
            int n = a.length;
            id1[] ceil = new id1[n];
            id1 buf = new id1(60);
            for (int i = 0; i < n; i++) {
                ceil[i] = new id1();
            }
            int[] indices = IntStream.range(0, n).toArray();
            CompareUtils.quickSort(indices, (i, j) -> a[i] == a[j] ? Integer.compare(i, j) : -Long.compare(a[i], a[j]), 0, n);

            id3.SegmentBS segBS = new id3.SegmentBS(0, n - 1);
            segBS.reset(0, n - 1, inf);
            for (int i : indices) {
                long threshold = inf - 1;
                int j = segBS.query(0, i, 0, n - 1, threshold);
                buf.clear();
                while (j != -1) {
                    buf.add(j);
                    

                    

                    threshold = DigitUtils.id0(a[j] + a[i], 2);
                    j = segBS.query(0, j - 1, 0, n - 1, threshold);
                }
                ceil[i].addAll(buf);
                segBS.update(i, i, 0, n - 1, a[i]);
            }

            id3.Segment id4 = new id3.Segment(0, n - 1);
            int l = 0;
            for (int i = 0; i < n; i++) {
                for (int t = 0; t < ceil[i].size(); t++) {
                    int j = ceil[i].get(t);
                    id4.update(0, j, 0, n - 1, a[j] - a[i]);
                }
                while (l < qs.length && qs[l].r == i) {
                    qs[l].ans = Math.min(qs[l].ans, id4.query(qs[l].l, qs[l].l, 0, n - 1));
                    l++;
                }
            }
        }

        public static class Query {
            public int l;
            public int r;
            public long ans;

            public Query(int l, int r) {
                this.l = l;
                this.r = r;
            }

        }

        static class Segment implements Cloneable {
            private id3.Segment left;
            private id3.Segment right;
            private long min;

            private void modify(long x) {
                min = Math.min(min, x);
            }

            public void pushUp() {
            }

            public void pushDown() {
                left.modify(min);
                right.modify(min);
                min = inf;
            }

            public Segment(int l, int r) {
                min = inf;
                if (l < r) {
                    int m = DigitUtils.floorAverage(l, r);
                    left = new id3.Segment(l, m);
                    right = new id3.Segment(m + 1, r);
                    pushUp();
                } else {
                }
            }

            private boolean covered(int ll, int rr, int l, int r) {
                return ll <= l && rr >= r;
            }

            private boolean noIntersection(int ll, int rr, int l, int r) {
                return ll > r || rr < l;
            }

            public void update(int ll, int rr, int l, int r, long x) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    modify(x);
                    return;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                left.update(ll, rr, l, m, x);
                right.update(ll, rr, m + 1, r, x);
                pushUp();
            }

            public long query(int ll, int rr, int l, int r) {
                if (noIntersection(ll, rr, l, r)) {
                    return inf;
                }
                if (covered(ll, rr, l, r)) {
                    return min;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                return Math.min(left.query(ll, rr, l, m),
                        right.query(ll, rr, m + 1, r));
            }

            private id3.Segment deepClone() {
                id3.Segment seg = clone();
                if (seg.left != null) {
                    seg.left = seg.left.deepClone();
                }
                if (seg.right != null) {
                    seg.right = seg.right.deepClone();
                }
                return seg;
            }

            protected id3.Segment clone() {
                try {
                    return (id3.Segment) super.clone();
                } catch (CloneNotSupportedException e) {
                    throw new RuntimeException(e);
                }
            }

            private void toString(StringBuilder builder) {
                if (left == null && right == null) {
                    builder.append(min).append(",");
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

        static class SegmentBS implements Cloneable {
            private id3.SegmentBS left;
            private id3.SegmentBS right;
            private long min;

            private void modify(long x) {
                min = x;
            }

            public void pushUp() {
                min = Math.min(left.min, right.min);
            }

            public void pushDown() {
            }

            public SegmentBS(int l, int r) {
                if (l < r) {
                    int m = DigitUtils.floorAverage(l, r);
                    left = new id3.SegmentBS(l, m);
                    right = new id3.SegmentBS(m + 1, r);
                    pushUp();
                } else {

                }
            }

            public void reset(int l, int r, long x) {
                if (l < r) {
                    int m = DigitUtils.floorAverage(l, r);
                    left.reset(l, m, x);
                    right.reset(m + 1, r, x);
                    pushUp();
                } else {
                    min = x;
                }
            }

            private boolean covered(int ll, int rr, int l, int r) {
                return ll <= l && rr >= r;
            }

            private boolean noIntersection(int ll, int rr, int l, int r) {
                return ll > r || rr < l;
            }

            public void update(int ll, int rr, int l, int r, long x) {
                if (noIntersection(ll, rr, l, r)) {
                    return;
                }
                if (covered(ll, rr, l, r)) {
                    modify(x);
                    return;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                left.update(ll, rr, l, m, x);
                right.update(ll, rr, m + 1, r, x);
                pushUp();
            }

            public int query(int ll, int rr, int l, int r, long threshold) {
                if (noIntersection(ll, rr, l, r) || min > threshold) {
                    return -1;
                }
                if (covered(ll, rr, l, r) && l == r) {
                    return l;
                }
                pushDown();
                int m = DigitUtils.floorAverage(l, r);
                int ans = right.query(ll, rr, m + 1, r, threshold);
                if (ans == -1) {
                    ans = left.query(ll, rr, l, m, threshold);
                }
                return ans;
            }

            private id3.SegmentBS deepClone() {
                id3.SegmentBS seg = clone();
                if (seg.left != null) {
                    seg.left = seg.left.deepClone();
                }
                if (seg.right != null) {
                    seg.right = seg.right.deepClone();
                }
                return seg;
            }

            protected id3.SegmentBS clone() {
                try {
                    return (id3.SegmentBS) super.clone();
                } catch (CloneNotSupportedException e) {
                    throw new RuntimeException(e);
                }
            }

            private void toString(StringBuilder builder) {
                if (left == null && right == null) {
                    builder.append(min).append(",");
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

        public void populate(long[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readLong();
            }
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long id0(long a, long b) {
            return ceilDiv(a, b) - 1;
        }

        public static long floorDiv(long a, long b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static long ceilDiv(long a, long b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            long c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }
}

