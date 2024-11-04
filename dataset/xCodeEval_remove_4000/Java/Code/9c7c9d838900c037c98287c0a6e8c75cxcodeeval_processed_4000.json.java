import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.math.BigDecimal;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            id1 solver = new id1();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id1 {
        int n;

        public int id6(int i) {
            return i;
        }

        public int id5(int i) {
            return n + i;
        }

        public int id9() {
            return n + 2;
        }

        public int id3() {
            return id9() + 1;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            int a = in.readInt();
            int b = in.readInt();
            double[] p = new double[n];
            double[] u = new double[n];
            in.populate(p);
            in.populate(u);

            List<id8>[] g = DoubleFlow.id11(id3() + 1);
            for (int i = 0; i < n; i++) {
                DoubleFlow.addEdge(g, id9(), i, 1, 0);
                DoubleFlow.addEdge(g, id9(), i, 1, p[i] * u[i]);

                DoubleFlow.addEdge(g, id6(i), id5(0), 1, -p[i]);
                DoubleFlow.addEdge(g, id6(i), id5(1), 1, -u[i]);
            }
            DoubleFlow.addEdge(g, id5(0), id3(), a, 0);
            DoubleFlow.addEdge(g, id5(1), id3(), b, 0);

            id7 costFlow = new id10(g.length);
            double[] cf = costFlow.apply(g, id9(), id3(), a + b);

            double ans = -cf[1];
            out.println(ans);
        }

    }

    static interface IntegerDeque extends IntegerStack {
        int removeFirst();

    }

    static interface id7 {
        double[] apply(List<id8>[] net, int s, int t, double send);

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

        public void populate(double[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readDouble();
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

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
        }

    }

    static class DoubleFlow {
        public static <T extends id2> void send(T edge, double flow) {
            edge.flow += flow;
            edge.rev.flow -= flow;
        }

        public static id8 addEdge(List<id8>[] g, int s, int t, double cap, double cost) {
            id8 real = new id8(t, 0, true, cost);
            id8 virtual = new id8(s, cap, false, -cost);
            real.rev = virtual;
            virtual.rev = real;
            g[s].add(real);
            g[t].add(virtual);
            return real;
        }

        public static List<id8>[] id11(int n) {
            List<id8>[] g = new List[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            return g;
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

        public FastOutput append(double c) {
            cache.append(new BigDecimal(c).toPlainString());
            return this;
        }

        public FastOutput println(double c) {
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

    static class id10 implements id7 {
        private int m;
        private id4 segment;
        private double[] lastDist;
        private double[] curDist;
        private id8[] prev;
        private boolean[] inq;
        private IntegerDeque dq;
        private static final double INF = Double.MAX_VALUE / 4;
        List<id8>[] g;

        public id10(int m) {
            this.m = m - 1;
            this.segment = new id4(0, m - 1);
            lastDist = new double[m];
            curDist = new double[m];
            prev = new id8[m];
            inq = new boolean[m];
            dq = new id0(m);
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
                for (id8 e : g[head]) {
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
                for (id8 e : g[head]) {
                    double dist;
                    if (e.rev.flow == 0 || !inq[e.to] || curDist[e.to] <= (dist = curDist[head] + e.cost - lastDist[e.to] + lastDist[head])) {
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

        public double[] apply(List<id8>[] net, int s, int t, double send) {
            this.g = net;
            bf(s);
            double flow = 0;
            double cost = 0;
            while (flow < send) {
                dijkstra(s);
                if (prev[t] == null) {
                    break;
                }
                double remain = send - flow;
                for (id8 trace = prev[t]; trace != null; trace = prev[trace.to]) {
                    remain = Math.min(remain, trace.flow);
                }
                for (id8 trace = prev[t]; trace != null; trace = prev[trace.to]) {
                    cost += trace.cost * -remain;
                    DoubleFlow.send(trace, -remain);
                }
                flow += remain;
            }
            return new double[]{flow, cost};
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class id2<T extends id2<T>> extends DirectedEdge {
        public double flow;
        public boolean real;
        public T rev;

        public id2(int to, double flow, boolean real) {
            super(to);
            this.flow = flow;
            this.real = real;
        }

        public String toString() {
            return rev.to + "-[" + flow + "/" + (flow + rev.flow) + "]->" + to;
        }

    }

    static class id4 implements Cloneable {
        private static final double INF = Double.MAX_VALUE;
        private id4 left;
        private id4 right;
        private double minimum;

        public void pushUp() {
            minimum = Math.min(left.minimum, right.minimum);
        }

        public id4(int l, int r) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left = new id4(l, m);
                right = new id4(m + 1, r);
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

        public void update(int x, int l, int r, double val) {
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

        private id4 deepClone() {
            id4 seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected id4 clone() {
            try {
                return (id4) super.clone();
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

    static class id8 extends id2<id8> {
        public double cost;

        public id8(int to, double flow, boolean real, double cost) {
            super(to, flow, real);
            this.cost = cost;
        }

    }

    static interface IntegerStack {
        void addLast(int x);

        boolean isEmpty();

        void clear();

    }
}

