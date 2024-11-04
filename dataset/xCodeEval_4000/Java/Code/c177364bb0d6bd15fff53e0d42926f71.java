import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
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
            DIncorrectFlow solver = new DIncorrectFlow();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DIncorrectFlow {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int src = 0;
            int dst = n - 1;
            int superSrc = n;
            int superDst = n + 1;

            List<LongCostFlowEdge>[] g = LongFlow.createCostFlow(superDst + 1);
            long[] delta = new long[n];
            LongCostFlowEdge[] normalForward = new LongCostFlowEdge[m];
            LongCostFlowEdge[] normalBack = new LongCostFlowEdge[m];
            LongCostFlowEdge[] exceedForward = new LongCostFlowEdge[m];
            LongCostFlowEdge[] exceedBack = new LongCostFlowEdge[m];

            long inf = (long) 1e18;
            long cur = 0;
            LongFlow.addCostEdge(g, dst, src, inf, 0);
            for (int i = 0; i < m; i++) {
                int a = in.readInt() - 1;
                int b = in.readInt() - 1;
                int c = in.readInt();
                int f = in.readInt();

                normalForward[i] = LongFlow.addCostEdge(g, a, b, Math.max(0, c - f), 1);
                normalBack[i] = LongFlow.addCostEdge(g, b, a, Math.min(f, c), 1);
                exceedForward[i] = LongFlow.addCostEdge(g, a, b, inf, 2);
                exceedBack[i] = LongFlow.addCostEdge(g, b, a, Math.max(0, f - c), 0);

                if (f > c) {
                    cur += f - c;
                }

                delta[a] -= f;
                delta[b] += f;
            }

            long sum = 0;
            for (int i = 0; i < n; i++) {
                if (delta[i] > 0) {
                    LongFlow.addCostEdge(g, superSrc, i, delta[i], 0);
                    sum += delta[i];
                }
                if (delta[i] < 0) {
                    LongFlow.addCostEdge(g, i, superDst, -delta[i], 0);
                }
            }

            LongMinimumCostFlow mcf = new LongDijkstraMinimumCostFlow(g.length);
            long[] cf = mcf.apply(g, superSrc, superDst, inf);
            

            if (cf[0] != sum) {
                throw new RuntimeException();
            }

            long ans = cf[1] + cur;
            out.println(ans);
        }

    }

    static interface LongMinimumCostFlow {
        long[] apply(List<LongCostFlowEdge>[] net, int s, int t, long send);

    }

    static class LongPriorityQueueBasedOnSegment implements Cloneable {
        private static final long INF = Long.MAX_VALUE;
        private LongPriorityQueueBasedOnSegment left;
        private LongPriorityQueueBasedOnSegment right;
        private long minimum;

        public void pushUp() {
            minimum = Math.min(left.minimum, right.minimum);
        }

        public LongPriorityQueueBasedOnSegment(int l, int r) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left = new LongPriorityQueueBasedOnSegment(l, m);
                right = new LongPriorityQueueBasedOnSegment(m + 1, r);
                pushUp();
            } else {

            }
        }

        public void reset(int l, int r) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left.reset(l, m);
                right.reset(m + 1, r);
                pushUp();
            } else {
                minimum = INF;
            }
        }

        public void update(int x, int l, int r, long val) {
            if (l > x || r < x) {
                return;
            }
            if (l == r) {
                minimum = val;
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            left.update(x, l, m, val);
            right.update(x, m + 1, r, val);
            pushUp();
        }

        public int pop(int l, int r) {
            if (l == r) {
                minimum = INF;
                return l;
            }
            int m = DigitUtils.floorAverage(l, r);
            int ans;
            if (left.minimum == minimum) {
                ans = left.pop(l, m);
            } else {
                ans = right.pop(m + 1, r);
            }
            pushUp();
            return ans;
        }

        private LongPriorityQueueBasedOnSegment deepClone() {
            LongPriorityQueueBasedOnSegment seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected LongPriorityQueueBasedOnSegment clone() {
            try {
                return (LongPriorityQueueBasedOnSegment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append(minimum).append(",");
                return;
            }
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

    static interface IntegerStack {
        void addLast(int x);

        boolean isEmpty();

        void clear();

    }

    static class LongCostFlowEdge extends LongFlowEdge<LongCostFlowEdge> {
        public long cost;

        public LongCostFlowEdge(int to, long flow, boolean real, long cost) {
            super(to, flow, real);
            this.cost = cost;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

        public static boolean equal(long a, long b) {
            return a == b;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
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
                    index = IntegerDequeImpl.this.next(index);
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

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
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

    static class LongFlow {
        public static <T extends LongFlowEdge> void send(T edge, long flow) {
            edge.flow += flow;
            edge.rev.flow -= flow;
        }

        public static LongCostFlowEdge addCostEdge(List<LongCostFlowEdge>[] g, int s, int t, long cap, long cost) {
            LongCostFlowEdge real = new LongCostFlowEdge(t, 0, true, cost);
            LongCostFlowEdge virtual = new LongCostFlowEdge(s, cap, false, -cost);
            real.rev = virtual;
            virtual.rev = real;
            g[s].add(real);
            g[t].add(virtual);
            return real;
        }

        public static List<LongCostFlowEdge>[] createCostFlow(int n) {
            return createGraph(n);
        }

        private static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

    }

    static class LongFlowEdge<T extends LongFlowEdge<T>> extends DirectedEdge {
        public long flow;
        public boolean real;
        public T rev;

        public LongFlowEdge(int to, long flow, boolean real) {
            super(to);
            this.flow = flow;
            this.real = real;
        }

        public String toString() {
            return rev.to + "-[" + flow + "/" + (flow + rev.flow) + "]->" + to;
        }

    }

    static class LongDijkstraMinimumCostFlow implements LongMinimumCostFlow {
        private int m;
        private LongPriorityQueueBasedOnSegment segment;
        private long[] lastDist;
        private long[] curDist;
        private LongCostFlowEdge[] prev;
        private boolean[] inq;
        private IntegerDeque dq;
        private static final long INF = Long.MAX_VALUE / 4;
        List<LongCostFlowEdge>[] g;

        public LongDijkstraMinimumCostFlow(int m) {
            this.m = m - 1;
            this.segment = new LongPriorityQueueBasedOnSegment(0, m - 1);
            lastDist = new long[m];
            curDist = new long[m];
            prev = new LongCostFlowEdge[m];
            inq = new boolean[m];
            dq = new IntegerDequeImpl(m);
        }

        private void bf(int s) {
            int n = g.length;
            dq.clear();
            for (int i = 0; i < n; i++) {
                lastDist[i] = INF;
                inq[i] = false;
            }
            lastDist[s] = 0;
            inq[s] = true;
            dq.addLast(s);
            while (!dq.isEmpty()) {
                int head = dq.removeFirst();
                inq[head] = false;
                for (LongCostFlowEdge e : g[head]) {
                    if (e.rev.flow == 0 || lastDist[e.to] <= lastDist[head] + e.cost) {
                        continue;
                    }
                    lastDist[e.to] = lastDist[head] + e.cost;
                    if (!inq[e.to]) {
                        inq[e.to] = true;
                        dq.addLast(e.to);
                    }
                }
            }
        }

        private void dijkstra(int s) {
            int n = g.length;
            segment.reset(0, m);
            for (int i = 0; i < n; i++) {
                curDist[i] = INF;
                inq[i] = true;
                prev[i] = null;
            }
            curDist[s] = 0;
            segment.update(s, 0, m, 0);

            for (int i = 0; i < n; i++) {
                int head = segment.pop(0, m);
                inq[head] = false;
                if (curDist[head] >= INF) {
                    break;
                }
                for (LongCostFlowEdge e : g[head]) {
                    long dist;
                    if (DigitUtils.equal(e.rev.flow, 0) || !inq[e.to] || curDist[e.to] <= (dist = curDist[head] + e.cost - lastDist[e.to] + lastDist[head])) {
                        continue;
                    }
                    prev[e.to] = e.rev;
                    curDist[e.to] = dist;
                    segment.update(e.to, 0, m, curDist[e.to]);
                }
            }

            for (int i = 0; i < n; i++) {
                lastDist[i] = Math.min(curDist[i] + lastDist[i], INF);
            }
        }

        public long[] apply(List<LongCostFlowEdge>[] net, int s, int t, long send) {
            this.g = net;
            bf(s);
            long flow = 0;
            long cost = 0;
            while (flow < send) {
                dijkstra(s);
                if (prev[t] == null) {
                    break;
                }
                long remain = send - flow;
                for (LongCostFlowEdge trace = prev[t]; trace != null; trace = prev[trace.to]) {
                    remain = Math.min(remain, trace.flow);
                }
                for (LongCostFlowEdge trace = prev[t]; trace != null; trace = prev[trace.to]) {
                    cost += trace.cost * -remain;
                    LongFlow.send(trace, -remain);
                }
                flow += remain;
            }
            return new long[]{flow, cost};
        }

    }

    static interface IntegerDeque extends IntegerStack {
        int removeFirst();

    }
}

