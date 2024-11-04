import java.io.*;
import java.text.MessageFormat;
import java.util.*;
import java.util.function.Predicate;
import java.util.function.ToIntFunction;


public class id26 {

    final boolean id16 = java.lang.System.getProperty("id16") != null;
    final boolean id5 = false;
    final Random r = new Random(42);
    id23 bs = new id23();

    private int id13(int testCase, int n, List<Segment> reds, List<Segment> blues) {
        id2 ans = new id2(n);

        for (Segment r : reds) {
            for (Segment b : blues) {
                if (in(r, b) || in(b, r)) {
                    ans.union(r.id, b.id);
                }
            }
        }

        return ans.getAmount();
    }

    boolean in(Segment f, Segment s) {
        return f.from <= s.from && s.from <= f.to || f.from <= s.to && s.to <= f.to;
    }

    private int solveOne(int testCase, int n, List<Segment> reds, List<Segment> blues) {

        id2 ans = new id2(n);

        List[][] combinations = new List[][]{{reds, blues}, {blues, reds}};
        for (List[] comb : combinations) {
            List<Segment> id22 = (List<Segment>) comb[0];
            List<Segment> id34 = (List<Segment>) comb[1];

            

            

            

            

            

            

            

            

            

            

            


            

            List<ToIntFunction<Segment>> id25 = new ArrayList<>();
            id25.add((Segment item) -> item.from);
            id25.add((Segment item) -> item.to);

            for (ToIntFunction<Segment> keyExtractor : id25) {
                List<Segment> id14 = new ArrayList<>(id34);
                id14.sort(Comparator.comparingInt(keyExtractor));

                List<IndexSegments> toCompress = new ArrayList<>();
                for (final Segment segment : id22) {
                    IndexSegments newItem = new IndexSegments();
                    newItem.l = bs.lowerBound(-1, id14.size(),
                            itemIndex -> segment.from <= keyExtractor.applyAsInt(id14.get(itemIndex))
                    );
                    newItem.r = bs.upperBound(-1, id14.size(),
                            itemIndex -> keyExtractor.applyAsInt(id14.get(itemIndex)) <= segment.to
                    );
                    newItem.id = segment.id;
                    if (newItem.l <= newItem.r) {
                        toCompress.add(newItem);
                    }
                }

                

                List<IndexSegments> merged = id18(
                        toCompress,
                        ans::union
                );

                

                for (IndexSegments seg : merged) {
                    int id31 = seg.id;
                    

                    int id8 = id14.get(seg.l).id;
                    ans.union(id31, id8);
                    for (int i = seg.l + 1; i <= seg.r; i++) {
                        int id = id14.get(i).id;
                        ans.union(id31, id);
                    }
                }


            }


        }


        return ans.getAmount();

    }

    @FunctionalInterface
    static interface id17 {
        void send(int id1, int id2);
    }

    List<IndexSegments> id18(
            List<IndexSegments> intervals,
            id17 merger
    ) {
        Deque<IndexSegments> stack = new ArrayDeque<IndexSegments>();

        Collections.sort(intervals, new Comparator<IndexSegments>() {
                    public int compare(IndexSegments p1, IndexSegments p2) {
                        return Integer.compare(p1.l, p2.l);
                    }
                }
        );

        if (intervals.size() < 1) {
            return intervals;
        }
        stack.addFirst(intervals.get(0));

        for (int j = 1; j < intervals.size(); j++) {
            IndexSegments current = intervals.get(j);
            IndexSegments top = stack.getFirst();
            if (top.r < current.l) {
                stack.push(current);
            } else


            {
                merger.send(top.id, current.id);

                IndexSegments merged = new IndexSegments();
                merged.id = top.id;
                merged.l = Math.min(top.l, current.l);
                merged.r = Math.max(top.r, current.r);

                stack.removeFirst();
                stack.addFirst(merged);
            }
        }
        return new ArrayList<IndexSegments>(stack);
    }

    static class id2 {
        private int[] rank, parent;
        private int amount;

        public id2(int amount) {
            this.rank = new int[amount];
            this.parent = new int[amount];
            this.amount = amount;
            for (int i = 0; i < amount; i++) {
                parent[i] = i;
            }
        }

        public boolean id19(int u, int v) {
            return find(u) == find(v);
        }

        public int find(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }

        public void union(int x, int y) {
            

            int xRoot = find(x), yRoot = find(y);

            

            

            if (xRoot == yRoot)
                return;

            

            if (rank[xRoot] < rank[yRoot])

                

                

                parent[xRoot] = yRoot;

                

            else if (rank[xRoot] > rank[yRoot])

                

                

                parent[yRoot] = xRoot;

            else 

            {
                

                

                parent[yRoot] = xRoot;

                

                

                rank[xRoot]++;
            }
            amount--;
        }

        public int getAmount() {
            return amount;
        }
    }

    static class id23 {

        private int upperBound(int inclusiveLeft, int exclusiveRight, Predicate<Integer> predicate) {
            while (exclusiveRight - inclusiveLeft > 1) {
                int middle = inclusiveLeft + (exclusiveRight - inclusiveLeft) / 2;
                if (predicate.test(middle)) {
                    inclusiveLeft = middle;
                } else {
                    exclusiveRight = middle;
                }
            }
            return inclusiveLeft;
        }

        private int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
            while (inclusiveRight - exclusiveLeft > 1) {
                int middle = exclusiveLeft + (inclusiveRight - exclusiveLeft) / 2;
                if (predicate.test(middle)) {
                    inclusiveRight = middle;
                } else {
                    exclusiveLeft = middle;
                }
            }
            return inclusiveRight;
        }

    }


    Segment readSegment(int id) {
        return new Segment(id, nextInt(), nextInt());
    }

    static class IndexSegments {
        public int id;
        public int l;
        public int r;
    }

    class Segment {
        int id;

        int from;
        int to;

        public Segment(int id, int from, int to) {
            this.id = id;
            this.from = from;
            this.to = to;
        }

        @Override
        public String toString() {
            return "Segment{" +
                    "id=" + id +
                    ", from=" + from +
                    ", to=" + to +
                    "}\n";
        }
    }


    private void solve() {
        if (id5) {
            int t = 10_000;
            for (int testCase = 0; testCase < t; testCase++) {
                int n = 3 + r.nextInt(3);
                List<Segment> reds = new ArrayList<>();
                List<Segment> blues = new ArrayList<>();
                for (int id = 0; id < n; id++) {
                    int color = r.nextInt(2);
                    int from = 1 + r.nextInt(10);
                    int to = 1 + r.nextInt(10);
                    if(from > to) {
                        int temp = from;
                        from = to;
                        to = temp;
                    }
                    Segment s = new Segment(id, from, to);
                    if (color == 0) reds.add(s);
                    else blues.add(s);
                }
                String r_ = reds.toString();
                String b_ = blues.toString();
                int expected = id13(testCase, n, reds, blues);
                int actual = solveOne(testCase, n, reds, blues);
                if(expected != actual) {
                    throw new id9(
                            this.getClass().getSimpleName(),
                            testCase,
                            expected,
                            actual,
                            n,
                            r_,
                            b_
                    );
                }

            }


        } else {
            int t = nextInt();
            for (int testCase = 0; testCase < t; testCase++) {
                int n = nextInt();
                List<Segment> reds = new ArrayList<>();
                List<Segment> blues = new ArrayList<>();
                for (int id = 0; id < n; id++) {
                    int color = nextInt();
                    if (color == 0) reds.add(readSegment(id));
                    else blues.add(readSegment(id));
                }
                int actual = solveOne(testCase, n, reds, blues);
                System.out.println(actual);
            }
        }
    }

    class id9 extends RuntimeException {

        id9(String testName,
                                  int testCase,
                                  Object expected,
                                  Object actual, Object... input) {
            super("Testcase: " + testCase + "\n expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
        }
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
    }

    private void assertThat(boolean b, String s) {
        if (!b) throw new RuntimeException(s);
    }

    private int id27(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id16) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id16) {
            _______debug("{0}", String.valueOf(o));
        }
    }

    private int nextInt() {
        return System.in.readInt();
    }

    private long nextLong() {
        return System.in.readLong();
    }

    private String nextString() {
        return System.in.readString();
    }

    private int[] id33(int n) {
        return System.in.id1(n);
    }

    private long[] id37(int n) {
        return System.in.id20(n);
    }

    public static void main(String[] args) {
        new id26().run();
    }

    static class System {
        private static id21 in;
        private static id28 out;
    }

    private void run() {
        final boolean USE_IO = id16;
        if (USE_IO) {
            System.in = new id21(java.lang.System.in);
            System.out = new id28(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id21(new FileInputStream(nameIn));
                System.out = new id28(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id28 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id28() {
            this(java.lang.System.out);
        }

        public id28(OutputStream os) {
            this.out = os;
        }

        public id28(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id28 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id28 print(char c) {
            return print((byte) c);
        }

        public id28 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id28 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id28 print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
            return this;
        }

        

        public id28 print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
            return this;
        }

        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }

        public id28 print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerFlush();
            if (x < 0) {
                print((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public id28 print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerFlush();
            if (x < 0) {
                print((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public id28 print(double x, int precision) {
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            print((long) x).print(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                print((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public id28 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id28 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id28 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id28 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id28 println(char c) {
            return print(c).println();
        }

        public id28 println(int x) {
            return print(x).println();
        }

        public id28 println(long x) {
            return print(x).println();
        }

        public id28 println(String x) {
            return print(x).println();
        }

        public id28 println(Object x) {
            return print(x.toString()).println();
        }

        public id28 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id28 println() {
            return print((byte) '\n');
        }

        public id28 printf(String format, Object... args) {
            return print(String.format(format, args));
        }

        private void innerFlush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerFlush");
            }
        }

        public void flush() {
            innerFlush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class id21 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id36 filter;

        public id21(InputStream stream) {
            this.stream = stream;
        }

        public double[] id6(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id32(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id10(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id10(columnCount);
            }
            return table;
        }

        public int[][] id15(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id6(columnCount);
            }
            return table;
        }

        public long[][] id3(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id20(columnCount);
            }
            return table;
        }

        public String[][] id29(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id32(columnCount);
            }
            return table;
        }

        public String readText() {
            StringBuilder result = new StringBuilder();
            while (true) {
                int character = read();
                if (character == '\r') {
                    continue;
                }
                if (character == -1) {
                    break;
                }
                result.append((char) character);
            }
            return result.toString();
        }

        public void id24(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id20(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id1(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        public int id35() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id12(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id12(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id12(c));
            return res.toString();
        }

        public char[] id4() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id12(c));
            char[] resArr = new char[res.length()];
            res.getChars(0, res.length(), resArr, 0);
            return resArr;
        }

        public boolean id12(int c) {
            if (filter != null) {
                return filter.id12(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id7() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = id7();
            while (s.trim().length() == 0) {
                s = id7();
            }
            return s;
        }

        public String readLine(boolean id30) {
            if (id30) {
                return readLine();
            } else {
                return id7();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id12(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id12(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!id12(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean id11() {
            int value;
            while (id12(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id36 getFilter() {
            return filter;
        }

        public void setFilter(id36 filter) {
            this.filter = filter;
        }

        public interface id36 {
            public boolean id12(int ch);
        }
    }

}