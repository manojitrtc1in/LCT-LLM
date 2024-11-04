import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;


public class id17 {

    final boolean id14 = java.lang.System.getProperty("id14") != null;

    private void solveOne(int testCase) {
        Interactor interactor = getInteractor();
        interactor.startInteraction();
        int n = interactor.vertexCnt();
        int m = interactor.edgeCnt();
        char[] forest = new char[m];
        Arrays.fill(forest, '1');
        

        int id15 = interactor.id15(forest);
        int[] weights = new int[m];
        

        for (int i = 0; i < m; i++) {
            Arrays.fill(forest, '0');
            forest[i] = '1';
            weights[i] = interactor.id15(forest);
        }

        int id16 = id15;
        id23[] id10 = id8(weights);

        Arrays.fill(forest, '1');
        

        for (int i = 0; i < m - 1; i++) { 

            id23 id27 = id10[i];
            int vertex = id27.ind;
            int weight = id27.val;
            forest[vertex] = '0';
            int id22 = interactor.id15(forest);
            if (id16 - id22 == weight) {
                forest[vertex] = '1';
            } else {
                id16 = id22;
            }
        }

        interactor.ans(id16);
    }

    Interactor getInteractor(){
        return id14 ? new id21() : new LocalInteractor();
    }

    interface Interactor {
        void startInteraction();

        int edgeCnt();

        int vertexCnt();

        int id15(char[] forest);

        void ans(int val);
    }

    class LocalInteractor implements Interactor {
        int vertexCnt;
        int edgeCnt;
        Edge[] edges;
        int MinSF;

        Comparator<Edge> minFirst = Comparator.comparing(e -> e.weight);
        Comparator<Edge> maxFirst = minFirst.reversed();

        @Override
        public void startInteraction() {
            vertexCnt = nextInt();
            edgeCnt = nextInt();
            edges = new Edge[edgeCnt];
            for (int i = 0; i < edgeCnt; i++) {
                edges[i] = id25();
            }
            char[] s = new char[edgeCnt];
            Arrays.fill(s, '1');
            MinSF = MSF(vertexCnt, edges, s, minFirst);
        }

        @Override
        public int edgeCnt() {
            return edgeCnt;
        }

        @Override
        public int vertexCnt() {
            return vertexCnt;
        }

        @Override
        public int id15(char[] forest) {
            return MSF(vertexCnt, edges, forest, maxFirst);
        }

        @Override
        public void ans(int val) {
            java.lang.System.out.println("Expected: "  + MinSF);
            java.lang.System.out.println("Actual: "  + val);
            java.lang.System.out.println(MinSF == val ? "OK" : "Wrong answer!");
        }
    }

    private int MSF(int vertexes, Edge[] copy, char[] filter, Comparator<Edge> comp) {
        Edge[] edges = new Edge[copy.length];
        int p = 0 ;
        for (Edge e : copy) {
            if(filter[e.id] == '1') {
                edges[p++] = e;
            }
        }
        edges = Arrays.copyOf(edges, p);

        Arrays.sort(edges, comp);
        id2 dus = new id2(vertexes);
        int ans = 0;
        for (Edge edge : edges) {
            int from = edge.from;
            int to = edge.to;
            if (!dus.id18(from, to)) {
                dus.union(to, from);
                ans += edge.weight;
            }
        }
        return ans;
    }

    class id21 implements Interactor {
        int vertexCnt;
        int edgeCnt;

        @Override
        public void startInteraction() {
            vertexCnt = nextInt();
            edgeCnt = nextInt();
        }

        @Override
        public int edgeCnt() {
            return edgeCnt;
        }

        @Override
        public int vertexCnt() {
            return vertexCnt;
        }

        public int id15(char[] forest) {
            System.out.print("? ");
            System.out.println(String.valueOf(forest));
            System.out.flush();
            return nextInt();
        }

        public void ans(int val) {
            System.out.println("! " + val);
        }
    }


    static class id23 {
        int val;
        int ind;

        public id23(int val, int ind) {
            this.val = val;
            this.ind = ind;
        }

        public int getVal() {
            return val;
        }

        public int getInd() {
            return ind;
        }
    }

    class Edge {
        int id;
        int from;
        int to;
        int weight;
    }

    id23[] id8(int[] a) {
        id23[] val = new id23[a.length];
        for (int i = 0; i < a.length; i++) {
            val[i] = new id23(a[i], i);
        }
        Arrays.sort(val, Comparator.comparing(id23::getVal).reversed());
        return val;
    }

    private void solve() {
        int t = 1;

        for (int testCase = 0; testCase < t; testCase++) {
            solveOne(testCase);
        }
    }

    class id2 {
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

        public boolean id18(int u, int v) {
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


    class id7 extends RuntimeException {

        id7(String testName,
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

    private int id26(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id14) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id14) {
            _______debug("{0}", String.valueOf(o));
        }
    }

    int id = 0;

    private Edge id25() {

        int from = nextInt() - 1;
        int to = nextInt() - 1;
        int weight = nextInt();
        Edge ans = new Edge();
        ans.id = this.id++;
        ans.from = from;
        ans.to = to;
        ans.weight = weight;
        return ans;
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

    private int[] id32(int n) {
        return System.in.id1(n);
    }

    private long[] id35(int n) {
        return System.in.id19(n);
    }

    public static void main(String[] args) {
        new id17().run();
    }

    static class System {
        private static id20 in;
        private static id28 out;
    }

    private void run() {
        final boolean USE_IO = id14;
        if (USE_IO) {
            System.in = new id20(java.lang.System.in);
            System.out = new id28(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id20(new FileInputStream(nameIn));
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

    private static class id20 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id34 filter;

        public id20(InputStream stream) {
            this.stream = stream;
        }

        public double[] id5(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id31(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id9(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id9(columnCount);
            }
            return table;
        }

        public int[][] id13(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id5(columnCount);
            }
            return table;
        }

        public long[][] id3(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id19(columnCount);
            }
            return table;
        }

        public String[][] id29(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id31(columnCount);
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

        public long[] id19(int size) {
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

        public int id33() {
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

        private String id6() {
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
            String s = id6();
            while (s.trim().length() == 0) {
                s = id6();
            }
            return s;
        }

        public String readLine(boolean id30) {
            if (id30) {
                return readLine();
            } else {
                return id6();
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

        public id34 getFilter() {
            return filter;
        }

        public void setFilter(id34 filter) {
            this.filter = filter;
        }

        public interface id34 {
            public boolean id12(int ch);
        }
    }

}