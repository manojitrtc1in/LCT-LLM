import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
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
            id0 solver = new id0();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id0 {
        Debug debug = new Debug(false);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int x = in.readInt();

            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.readInt();
            }

            State.x = x;
            State.function = i -> a[i];

            Segment segment = new Segment(1, n);

            debug.debug("segment", segment);
            State query = new State();
            for (int i = 0; i < m; i++) {
                int t = in.readInt();
                if (t == 1) {
                    int index = in.readInt();
                    int y = in.readInt();
                    a[index] = y;
                    segment.update(index, index, 1, n);
                } else {
                    int l = in.readInt();
                    int r = in.readInt();
                    query.init(l);
                    segment.query(l, r, 1, n, query);
                    long ans = query.way;
                    out.println(ans);
                }
            }
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (!x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

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

    static interface id1 {
        int apply(int x);

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

    static interface IntegerStack {
    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    static class State {
        public static id1 function;
        public static int x;
        public int l;
        public int r;
        public long way;
        public IntegerList pre = new IntegerList(20);
        public IntegerList post = new IntegerList(20);
        private static State tmp = new State();
        private static int[] buf = new int[20];

        public void init(int l) {
            this.l = l;
            this.r = l - 1;
            pre.clear();
            post.clear();
            way = 0;
        }

        private static void copy(State a, State b) {
            b.l = a.l;
            b.r = a.r;
            b.way = a.way;

            IntegerList swap = a.pre;
            a.pre = b.pre;
            b.pre = swap;

            swap = a.post;
            a.post = b.post;
            b.post = swap;
        }

        public void mergeInto(State b) {
            merge(this, b, tmp);
            copy(tmp, this);
            return;
        }

        public void singlePoint() {
            int val = function.apply(l);
            if (val >= x) {
                way = 1;
            } else {
                way = 0;
            }
            pre.clear();
            post.clear();
            pre.add(l);
            post.add(l);
        }

        public static void merge(State a, State b, State result) {
            result.pre.clear();
            result.post.clear();
            result.l = a.l;
            result.r = b.r;
            result.way = a.way + b.way;

            b.pre.toArray(buf);
            int n = a.post.size();
            int m = b.pre.size();
            for (int i = 0; i < m; i++) {
                buf[i] = function.apply(buf[i]);
                if (i > 0) {
                    buf[i] |= buf[i - 1];
                }
            }
            int leftMask = 0;
            id2 dq = new id2(i -> a.post.get(i), 0, a.post.size() - 1);
            int lastEnd = a.r;
            int rightEnd = b.r;
            for (int i = m - 1; i >= 0; i--) {
                int index = b.pre.get(i);
                while (!dq.isEmpty() && (leftMask | buf[i]) < x) {
                    lastEnd = dq.peekFirst();
                    leftMask |= function.apply(dq.removeFirst());
                }
                if ((leftMask | buf[i]) < x) {
                    break;
                }
                result.way += (long) (rightEnd - index + 1) * (lastEnd - a.l + 1);
                rightEnd = index - 1;
            }

            result.pre.addAll(a.pre);
            int mask = combine(a.pre);
            for (int i = 0; mask < x && i < m; i++) {
                int index = b.pre.get(i);
                int val = function.apply(index);
                if ((mask | val) != mask) {
                    mask |= val;
                    result.pre.add(index);
                }
            }
            mask = combine(b.post);
            result.post.addAll(b.post);
            for (int i = 0; mask < x && i < n; i++) {
                int index = a.post.get(i);
                int val = function.apply(index);
                if ((mask | val) != mask) {
                    mask |= val;
                    result.post.add(index);
                }
            }
        }

        public static int combine(IntegerList list) {
            int ans = 0;
            for (int i = list.size() - 1; i >= 0; i--) {
                ans |= function.apply(list.get(i));
            }
            return ans;
        }

        public String toString() {
            return String.format("[%d,%d]=%d", l, r, way);
        }

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
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

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public int[] toArray(int[] arr) {
            if (arr.length < size) {
                arr = new int[size];
            }
            System.arraycopy(data, 0, arr, 0, size);
            return arr;
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static interface id3 {
        int apply(int x);

    }

    static class id2 implements IntegerDeque {
        id3 function;
        int l;
        int r;

        public id2(id3 function, int l, int r) {
            this.function = function;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public int peekFirst() {
            return function.apply(l);
        }

        public int removeFirst() {
            return function.apply(l++);
        }

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private State state;

        public void pushUp() {
            State.merge(left.state, right.state, state);
        }

        public void pushDown() {
        }

        public void modify() {
            state.singlePoint();
        }

        public Segment(int l, int r) {
            state = new State();
            state.l = l;
            state.r = r;
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {
                modify();
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                modify();
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m);
            right.update(ll, rr, m + 1, r);
            pushUp();
        }

        public void query(int ll, int rr, int l, int r, State state) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                state.mergeInto(this.state);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.query(ll, rr, l, m, state);
            right.query(ll, rr, m + 1, r, state);
        }

        private Segment deepClone() {
            Segment seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected Segment clone() {
            try {
                return (Segment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append(state).append(",");
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

