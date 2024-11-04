import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.util.List;
import java.io.Closeable;
import java.util.Comparator;
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
            id9 solver = new id9();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id9 {
        Debug debug = new Debug(true);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int k = in.ri();
            int[] d = in.ri(k);
            int n2 = n * (n - 1) / 2;
            int ck = k * (k - 1) / 2;
            id2 usList = new id2(n2);
            id2 vsList = new id2(n2);
            id4 wsList = new id4(n2);
            id2 edgeList = new id2(ck);
            List<Edge> outside = new ArrayList<>(n2);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (i >= k && j >= k) {
                        Edge e = new Edge(i, j, in.ri());
                        outside.add(e);
                    } else {
                        usList.add(i);
                        vsList.add(j);
                        wsList.add(in.ri());
                    }
                    if (i < k && j < k) {
                        edgeList.add(usList.size() - 1);
                    }
                }
            }
            DSU dsu = new DSU(n);
            dsu.init();
            outside.sort(Comparator.comparingInt(x -> x.w));

            debug.debug("size", usList.size());
            for (Edge e : outside) {
                if (dsu.find(e.a) == dsu.find(e.b)) {
                    continue;
                }
                dsu.merge(e.a, e.b);
                usList.add(e.a);
                vsList.add(e.b);
                wsList.add(e.w);
            }
            int[] us = usList.toArray();
            int[] vs = vsList.toArray();
            long[] ws = wsList.toArray();
            int[] edges = edgeList.toArray();
            int m = edges.length;
            long inf = (long) 1e9;
            long[] wsSnapshot = ws.clone();
            int[] type = new int[us.length];
            for (int i = 0; i < us.length; i++) {
                if (us[i] < k && vs[i] >= k) {
                    type[i] = us[i];
                } else if (vs[i] < k && us[i] >= k) {
                    type[i] = vs[i];
                } else {
                    type[i] = k;
                }
            }
            debug.debug("size", us.length);
            long best = inf;
            for (int i = 0; i < 1 << m; i++) {
                boolean ok = true;
                dsu.init();
                System.arraycopy(wsSnapshot, 0, ws, 0, ws.length);
                int[] cap = new int[k + 1];
                System.arraycopy(d, 0, cap, 0, k);
                cap[k] = n;
                for (int j = 0; j < m; j++) {
                    int e = edges[j];
                    if (Bits.get(i, j) == 0) {
                        ws[e] += inf;
                    } else {
                        int u = us[e];
                        int v = vs[e];
                        ws[e] -= inf;
                        cap[u]--;
                        cap[v]--;
                        if (dsu.find(u) == dsu.find(v)) {
                            ok = false;
                        }
                        dsu.merge(u, v);
                    }
                }
                for (int j = 0; j < ws.length; j++) {
                    ws[j] = -ws[j];
                }
                for (int j = 0; j <= k; j++) {
                    if (cap[j] < 0) {
                        ok = false;
                    }
                }
                if (!ok) {
                    continue;
                }
                id8 container = id8.id6(type, cap);
                id8 tree = id8.id7(n, new int[][]{us, vs});
                id3 mi = new id3(us.length, ws);
                boolean[] sol = mi.intersect(container, tree);
                long sum = 0;
                int occur = 0;
                for (int j = 0; j < sol.length; j++) {
                    if (sol[j]) {
                        occur++;
                        sum += ws[j];
                    }
                }
                sum = -sum;
                sum += Integer.bitCount(i) * inf;
                if (sum >= inf || occur < n - 1) {
                    continue;
                }
                best = Math.min(best, sum);
            }
            out.println(best);
        }

    }

    static class id4 implements Cloneable {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public id4(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public id4(long[] data) {
            this(0);
            addAll(data);
        }

        public id4(id4 list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public id4() {
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

        public void add(long x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(long[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(long[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(id4 list) {
            addAll(list.data, 0, list.size);
        }

        public long[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof id4)) {
                return false;
            }
            id4 other = (id4) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Long.hashCode(data[i]);
            }
            return h;
        }

        public id4 clone() {
            id4 ans = new id4();
            ans.addAll(this);
            return ans;
        }

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static interface IntegerStack {
    }

    static class id5 {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public void clear() {
            alloc = 0;
            Arrays.fill(heads, 0, stackNum, 0);
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public id5(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                if (isEmpty(i)) {
                    continue;
                }
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static class id1 {
        protected id0 dq;
        protected int[] dists;
        protected boolean[] added;
        protected boolean[][] adj1;
        protected boolean[][] adj2;
        protected int n;
        protected boolean[] x1;
        protected boolean[] x2;
        protected static int distInf = (int) 1e9;
        protected int[] pre;
        protected Consumer<boolean[]> callback;
        protected static Consumer<boolean[]> nilCallback = x -> {
        };

        public void setCallback(Consumer<boolean[]> callback) {
            if (callback == null) {
                callback = nilCallback;
            }
            this.callback = callback;
        }

        public id1(int n) {
            this.n = n;
            dq = new id0(n);
            dists = new int[n];
            added = new boolean[n];
            adj1 = new boolean[n][];
            adj2 = new boolean[n][];
            x1 = new boolean[n];
            x2 = new boolean[n];
            pre = new int[n];
            setCallback(nilCallback);
        }

        protected boolean adj(int i, int j) {
            if (added[i]) {
                return adj1[i][j];
            } else {
                return adj2[j][i];
            }
        }

        protected boolean expand(id8 a, id8 b, int round) {
            Arrays.fill(x1, false);
            Arrays.fill(x2, false);
            a.prepare(added);
            b.prepare(added);
            a.extend(added, x1);
            b.extend(added, x2);
            for (int i = 0; i < n; i++) {
                if (x1[i] && x2[i]) {
                    pre[i] = -1;
                    xorPath(i);
                    return true;
                }
            }

            for (int i = 0; i < n; i++) {
                if (added[i]) {
                    Arrays.fill(adj1[i], false);
                    Arrays.fill(adj2[i], false);
                }
            }

            a.computeAdj(added, adj1);
            b.computeAdj(added, adj2);
            Arrays.fill(dists, distInf);
            Arrays.fill(pre, -1);
            dq.clear();
            for (int i = 0; i < n; i++) {
                if (added[i]) {
                    continue;
                }
                

                if (x1[i]) {
                    dists[i] = 0;
                    dq.addLast(i);
                }
            }

            int tail = -1;
            while (!dq.isEmpty()) {
                int head = dq.removeFirst();
                if (x2[head]) {
                    tail = head;
                    break;
                }
                for (int j = 0; j < n; j++) {
                    if (added[head] != added[j] && adj(head, j) && dists[j] > dists[head] + 1) {
                        dists[j] = dists[head] + 1;
                        dq.addLast(j);
                        pre[j] = head;
                    }
                }
            }

            if (tail == -1) {
                return false;
            }

            xorPath(tail);
            return true;
        }

        protected void xorPath(int tail) {
            boolean[] last1 = new boolean[n];
            boolean[] last2 = new boolean[n];
            for (boolean add = true; tail != -1; tail = pre[tail], add = !add) {
                assert added[tail] != add;
                added[tail] = add;
                if (add) {
                    adj1[tail] = last1;
                    adj2[tail] = last2;
                } else {
                    last1 = adj1[tail];
                    last2 = adj2[tail];
                    adj1[tail] = null;
                    adj2[tail] = null;
                }
            }
        }

        public boolean[] intersect(id8 a, id8 b) {
            Arrays.fill(added, false);
            int round = 0;
            callback.accept(added);
            while (expand(a, b, round)) {
                round++;
                callback.accept(added);
            }
            return added;
        }

    }

    static class Edge {
        int a;
        int b;
        int w;

        public Edge(int a, int b, int w) {
            this.a = a;
            this.b = b;
            this.w = w;
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int get(int x, int i) {
            return (x >>> i) & 1;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class DSU {
        protected int[] p;
        public int[] size;
        protected int n;

        public DSU(int n) {
            p = new int[n];
            size = new int[n];
        }

        public void init() {
            init(p.length);
        }

        public void init(int n) {
            this.n = n;
            for (int i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 1;
            }
        }

        public final int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            find(p[a]);
            preAccess(a);
            return p[a] = p[p[a]];
        }

        protected void preAccess(int a) {

        }

        protected void preMerge(int a, int b) {
            size[a] += size[b];
        }

        public final void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }

            if (size[a] < size[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            preMerge(a, b);
            p[b] = a;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(p, n));
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int id10 = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(id10 * 2);
        private static Field id11;
        private char[] charBuf = new char[id10 * 2];
        private byte[] byteBuf = new byte[id10 * 2];

        static {
            try {
                id11 = StringBuilder.class.getSuperclass().getDeclaredField("value");
                id11.setAccessible(true);
            } catch (Exception e) {
                id11 = null;
            }
            id11 = null;
        }

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < id10) {
                return;
            }
            flush();
        }

        public FastOutput(OutputStream writer) {
            this.writer = writer;
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (id11 != null) {
                    try {
                        byte[] value = (byte[]) id11.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        id11 = null;
                    }
                }
                if (id11 == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        

                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));


                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class id2 implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public id2(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public id2(int[] data) {
            this(0);
            addAll(data);
        }

        public id2(id2 list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public id2() {
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

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(id2 list) {
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
            if (!(obj instanceof id2)) {
                return false;
            }
            id2 other = (id2) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public id2 clone() {
            id2 ans = new id2();
            ans.addAll(this);
            return ans;
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

        public static boolean equal(long[] a, int al, int ar, long[] b, int bl, int br) {
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

    static class id3 extends id1 {
        protected long[] weight;
        protected long[] pathWeight;
        protected static final long weightInf = (long) 1e18;
        protected boolean[] inq;
        protected long[] fixWeight;

        public id3(int n, long[] weight) {
            super(n);
            this.weight = weight;
            pathWeight = new long[n];
            inq = new boolean[n];
            fixWeight = new long[n];
        }

        protected boolean expand(id8 a, id8 b, int round) {
            a.prepare(added);
            b.prepare(added);
            Arrays.fill(x1, false);
            Arrays.fill(x2, false);
            a.extend(added, x1);
            b.extend(added, x2);

            for (int i = 0; i < n; i++) {
                if (added[i]) {
                    Arrays.fill(adj1[i], false);
                    Arrays.fill(adj2[i], false);
                    fixWeight[i] = weight[i];
                } else {
                    fixWeight[i] = -weight[i];
                }
            }

            a.computeAdj(added, adj1);
            b.computeAdj(added, adj2);
            Arrays.fill(dists, id1.distInf);
            Arrays.fill(pathWeight, weightInf);
            Arrays.fill(pre, -1);
            dq.clear();
            for (int i = 0; i < n; i++) {
                if (added[i]) {
                    continue;
                }
                

                if (x1[i]) {
                    dists[i] = 0;
                    pathWeight[i] = fixWeight[i];
                    dq.addLast(i);
                    inq[i] = true;
                }
            }

            while (!dq.isEmpty()) {
                int head = dq.removeFirst();
                inq[head] = false;

                for (int j = 0; j < n; j++) {
                    if (added[head] != added[j] && adj(head, j)) {
                        int comp = Long.compare(pathWeight[j], pathWeight[head] + fixWeight[j]);
                        if (comp == 0) {
                            comp = Integer.compare(dists[j], dists[head] + 1);
                        }
                        if (comp <= 0) {
                            continue;
                        }
                        dists[j] = dists[head] + 1;
                        pathWeight[j] = pathWeight[head] + fixWeight[j];
                        pre[j] = head;
                        if (!inq[j]) {
                            inq[j] = true;
                            dq.addLast(j);
                        }
                    }
                }
            }

            int tail = -1;
            for (int i = 0; i < n; i++) {
                if (!x2[i] || !x1[i] && pre[i] == -1) {
                    continue;
                }
                if (tail == -1 || pathWeight[i] < pathWeight[tail] || pathWeight[i] == pathWeight[tail] &&
                        dists[i] < dists[tail]) {
                    tail = i;
                }
            }
            if (tail == -1) {
                return false;
            }

            xorPath(tail);
            return true;
        }

    }

    static class id0 implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public id0(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = id0.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
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

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
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

        public int ri() {
            return readInt();
        }

        public int[] ri(int n) {
            int[] ans = new int[n];
            populate(ans);
            return ans;
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, int x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

    }

    static interface id8 {
        void computeAdj(boolean[] added, boolean[][] adj);

        void extend(boolean[] added, boolean[] extendable);

        void prepare(boolean[] added);

        static id8 id6(int[] type, int[] cap) {
            int[] size = new int[cap.length];
            return new id8() {
                

                public void computeAdj(boolean[] added, boolean[][] adj) {
                    for (int i = 0; i < added.length; i++) {
                        if (!added[i]) {
                            continue;
                        }
                        for (int j = 0; j < added.length; j++) {
                            if (added[j]) {
                                continue;
                            }
                            if (size[type[j]] < cap[type[j]] ||
                                    type[i] == type[j]) {
                                adj[i][j] = true;
                            }
                        }
                    }
                }

                

                public void extend(boolean[] added, boolean[] extendable) {
                    for (int i = 0; i < added.length; i++) {
                        if (!added[i] && size[type[i]] < cap[type[i]]) {
                            extendable[i] = true;
                        }
                    }
                }


                public void prepare(boolean[] added) {
                    Arrays.fill(size, 0);
                    for (int i = 0; i < added.length; i++) {
                        if (added[i]) {
                            size[type[i]]++;
                        }
                    }
                }
            };
        }

        static id8 id7(int n, int[][] edges) {
            return new id8() {
                DSU dsu = new DSU(n);
                id5 g = new id5(n, edges[0].length);
                id2 inset = new id2(edges[0].length);
                int[] p = new int[n];
                int[] depth = new int[n];

                public void dfs(int root, int fa, int d) {
                    p[root] = fa;
                    depth[root] = d;
                    for (IntegerIterator iterator = g.iterator(root); iterator.hasNext(); ) {
                        int e = iterator.next();
                        if (e == fa) {
                            continue;
                        }
                        dfs(opponent(e, root), e, d + 1);
                    }
                }

                public int opponent(int i, int root) {
                    return edges[0][i] == root ? edges[1][i] : edges[0][i];
                }

                

                public void computeAdj(boolean[] added, boolean[][] adj) {
                    int[] id12 = inset.getData();
                    int m = inset.size();
                    for (int i = 0; i < added.length; i++) {
                        if (added[i]) {
                            continue;
                        }
                        if (dsu.find(edges[0][i]) != dsu.find(edges[1][i])) {
                            for (int j = 0; j < m; j++) {
                                adj[id12[j]][i] = true;
                            }
                        } else {
                            int a = edges[0][i];
                            int b = edges[1][i];
                            while (a != b) {
                                if (depth[a] < depth[b]) {
                                    int tmp = a;
                                    a = b;
                                    b = tmp;
                                }
                                adj[p[a]][i] = true;
                                a = opponent(p[a], a);
                            }
                        }
                    }
                }


                

                public void extend(boolean[] added, boolean[] extendable) {
                    for (int i = 0; i < added.length; i++) {
                        if (!added[i]) {
                            extendable[i] = dsu.find(edges[0][i]) != dsu.find(edges[1][i]);
                        }
                    }
                }

                

                public void prepare(boolean[] added) {
                    g.clear();
                    dsu.init();
                    inset.clear();
                    for (int i = 0; i < added.length; i++) {
                        if (added[i]) {
                            dsu.merge(edges[0][i], edges[1][i]);
                            g.addLast(edges[0][i], i);
                            g.addLast(edges[1][i], i);
                            inset.add(i);
                        }
                    }
                    Arrays.fill(p, -1);
                    for (int i = 0; i < n; i++) {
                        if (p[i] == -1) {
                            dfs(i, -1, 0);
                        }
                    }
                }
            };
        }

    }
}

