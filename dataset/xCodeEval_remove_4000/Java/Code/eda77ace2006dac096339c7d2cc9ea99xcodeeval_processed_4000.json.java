import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.ListIterator;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.util.Map.Entry;
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
            id9 solver = new id9();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id9 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Point[] pts = new Point[n];
            for (int i = 0; i < n; i++) {
                int x = in.readInt();
                int y = in.readInt();
                pts[i] = new Point(x, y);
            }

            Map<Integer, List<Point>> id10 = Arrays.stream(pts).collect(Collectors.groupingBy(x -> x.x));
            Map<Integer, List<Point>> id7 = Arrays.stream(pts).collect(Collectors.groupingBy(x -> x.y));

            List<XLine> xLines = new ArrayList<>(n);
            List<YLine> yLines = new ArrayList<>(n);
            for (Map.Entry<Integer, List<Point>> entry : id7.entrySet()) {
                int y = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.x - b.x);
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.x + 1 < next.x) {
                        XLine line = new XLine(last.x + 1, next.x - 1, y);
                        xLines.add(line);
                    }
                }
            }

            for (Map.Entry<Integer, List<Point>> entry : id10.entrySet()) {
                int x = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.y - b.y);
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.y + 1 < next.y) {
                        YLine line = new YLine(last.y + 1, next.y - 1, x);
                        yLines.add(line);
                    }
                }
            }


            int xCnt = xLines.size();
            int yCnt = yLines.size();
            List<int[]> edges = new ArrayList<>(xCnt * yCnt);
            for (int i = 0; i < xCnt; i++) {
                for (int j = 0; j < yCnt; j++) {
                    XLine xLine = xLines.get(i);
                    YLine yLine = yLines.get(j);
                    if (between(xLine.y, yLine.b, yLine.t) &&
                            between(yLine.x, xLine.l, xLine.r)) {
                        edges.add(new int[]{i, j});
                    }
                }
            }

            id14 match = new id14(xLines.size(), yLines.size());
            for (int[] e : edges) {
                match.addEdge(e[0], e[1]);
            }

            match.solve();
            boolean[][] id13 = match.id13();
            List<XLine> id16 = new ArrayList<>(n);
            List<YLine> id11 = new ArrayList<>(n);

            int cnt = 0;
            for (Map.Entry<Integer, List<Point>> entry : id7.entrySet()) {
                int y = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.x - b.x);
                int l, r;
                l = r = list.get(0).x;
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.x + 1 < next.x) {
                        if (id13[0][cnt]) {
                            id16.add(new XLine(l, r, y));
                            l = r = next.x;
                        } else {
                            r = next.x;
                        }
                        cnt++;
                    } else {
                        r = next.x;
                    }
                }
                id16.add(new XLine(l, r, y));
            }

            cnt = 0;
            for (Map.Entry<Integer, List<Point>> entry : id10.entrySet()) {
                int x = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.y - b.y);
                int b, t;
                b = t = list.get(0).y;
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.y + 1 < next.y) {
                        if (id13[1][cnt]) {
                            id11.add(new YLine(b, t, x));
                            b = t = next.y;
                        } else {
                            t = next.y;
                        }
                        cnt++;
                    } else {
                        t = next.y;
                    }
                }
                id11.add(new YLine(b, t, x));
            }

            out.println(id16.size());
            for (XLine line : id16) {
                out.append(line.l).append(' ').append(line.y).append(' ').append(line.r).append(' ').append(line.y).println();
            }
            out.println(id11.size());
            for (YLine line : id11) {
                out.append(line.x).append(' ').append(line.b).append(' ').append(line.x).append(' ').append(line.t).println();
            }
        }

        public boolean between(int a, int l, int r) {
            return l <= a && a <= r;
        }

    }

    static class id14 {
        private List<id1>[] g;
        private id5 dinic;
        private int[] id6;
        private int[] id2;
        int l;
        int r;

        private int id4(int i) {
            return i;
        }

        private int id8(int i) {
            return i + l;
        }

        private int id12() {
            return l + r;
        }

        private int id17() {
            return id12() + 1;
        }

        public id14(int l, int r) {
            this.l = l;
            this.r = r;
            id6 = new int[l];
            id2 = new int[r];
            g = IntegerFlow.createFlow(id17() + 1);
            dinic = new id5();
            for (int i = 0; i < l; i++) {
                IntegerFlow.addEdge(g, id12(), id4(i), 1);
            }
            for (int i = 0; i < r; i++) {
                IntegerFlow.addEdge(g, id8(i), id17(), 1);
            }
        }

        public void addEdge(int u, int v) {
            IntegerFlow.addEdge(g, id4(u), id8(v), 1);
        }

        public int solve() {
            Arrays.fill(id6, -1);
            Arrays.fill(id2, -1);
            dinic.apply(g, id12(), id17(), l);
            int ans = 0;
            for (int i = 0; i < l; i++) {
                for (id1 e : g[id4(i)]) {
                    if (e.real && e.flow == 1) {
                        ans++;
                        int to = e.to - id8(0);
                        id6[i] = to;
                        id2[to] = i;
                        break;
                    }
                }
            }
            return ans;
        }

        public boolean[][] id13() {
            boolean[] lVis = new boolean[l];
            boolean[] rVis = new boolean[r];
            for (int i = 0; i < r; i++) {
                if (id2[i] == -1) {
                    dfsRight(i, lVis, rVis);
                }
            }

            boolean[] left = new boolean[l];
            boolean[] right = new boolean[r];
            for (int i = 0; i < l; i++) {
                left[i] = lVis[i];
            }
            for (int i = 0; i < right.length; i++) {
                right[i] = !rVis[i];
            }

            return new boolean[][]{left, right};
        }

        private void dfsRight(int i, boolean[] lVis, boolean[] rVis) {
            if (rVis[i]) {
                return;
            }
            rVis[i] = true;
            for (id1 e : g[id8(i)]) {
                if (e.real) {
                    continue;
                }
                dfsLeft(e.to - id4(0), lVis, rVis);
            }
        }

        private void dfsLeft(int i, boolean[] lVis, boolean[] rVis) {
            if (id6[i] == -1) {
                return;
            }
            if (lVis[i]) {
                return;
            }
            lVis[i] = true;
            dfsRight(id6[i], lVis, rVis);
        }

    }

    static interface IntegerDeque extends IntegerStack {
        int removeFirst();

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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
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

    static class id1<T extends id1<T>> extends DirectedEdge {
        public int flow;
        public boolean real;
        public T rev;

        public id1(int to, int flow, boolean real) {
            super(to);
            this.flow = flow;
            this.real = real;
        }

        public String toString() {
            return rev.to + "-[" + flow + "/" + (flow + rev.flow) + "]->" + to;
        }

    }

    static class id5 implements id15 {
        List<id1>[] g;
        int s;
        int t;
        IntegerDeque deque;
        int[] dists;
        ListIterator<id1>[] iterators;

        public id5() {
        }

        public void ensure(int vertexNum) {
            if (dists != null && dists.length >= vertexNum) {
                return;
            }
            deque = new id0(vertexNum);
            dists = new int[vertexNum];
            iterators = new ListIterator[vertexNum];
        }

        public int send(int root, int flow) {
            if (root == t) {
                return flow;
            }
            int snapshot = flow;
            while (iterators[root].hasNext()) {
                id1 e = iterators[root].next();
                int remain;
                if (dists[e.to] + 1 != dists[root] || (remain = e.rev.flow) == 0) {
                    continue;
                }
                int sent = send(e.to, Math.min(flow, remain));
                flow -= sent;
                IntegerFlow.send(e, sent);
                if (flow == 0) {
                    iterators[root].previous();
                    break;
                }
            }
            return snapshot - flow;
        }

        public int apply(List<id1>[] g, int s, int t, int send) {
            ensure(g.length);
            this.s = s;
            this.t = t;
            this.g = g;
            int flow = 0;
            while (flow < send) {
                IntegerFlow.id3(g, t, dists, Integer.MAX_VALUE, deque);
                if (dists[s] == Integer.MAX_VALUE) {
                    break;
                }
                for (int i = 0; i < g.length; i++) {
                    iterators[i] = g[i].listIterator();
                }
                flow += send(s, send - flow);
            }
            return flow;
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

    static class XLine {
        int l;
        int r;
        int y;

        public XLine(int l, int r, int y) {
            this.l = l;
            this.r = r;
            this.y = y;
        }

    }

    static class IntegerFlow {
        public static <T extends id1> void send(T edge, int flow) {
            edge.flow += flow;
            edge.rev.flow -= flow;
        }

        public static id1 addEdge(List<id1>[] g, int s, int t, int cap) {
            id1 real = new id1(t, 0, true);
            id1 virtual = new id1(s, cap, false);
            real.rev = virtual;
            virtual.rev = real;
            g[s].add(real);
            g[t].add(virtual);
            return real;
        }

        public static List<id1>[] createFlow(int n) {
            return createGraph(n);
        }

        private static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

        public static <T extends id1> void id3(List<T>[] g, int s, int[] dist, int inf, IntegerDeque deque) {
            Arrays.fill(dist, 0, g.length, inf);
            dist[s] = 0;
            deque.clear();
            deque.addLast(s);
            while (!deque.isEmpty()) {
                int head = deque.removeFirst();
                for (T e : g[head]) {
                    if (!DigitUtils.equal(e.flow, 0) && dist[e.to] == inf) {
                        dist[e.to] = dist[head] + 1;
                        deque.addLast(e.to);
                    }
                }
            }
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static boolean equal(int a, int b) {
            return a == b;
        }

    }

    static interface IntegerStack {
        void addLast(int x);

        boolean isEmpty();

        void clear();

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

    static class YLine {
        int t;
        int b;
        int x;

        public YLine(int b, int t, int x) {
            this.t = t;
            this.b = b;
            this.x = x;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static interface id15 {
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

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }
}

