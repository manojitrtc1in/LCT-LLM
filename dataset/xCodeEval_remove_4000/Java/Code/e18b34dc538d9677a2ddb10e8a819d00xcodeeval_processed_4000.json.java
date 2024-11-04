import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;


public class id15 implements Runnable{

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private static long BASE = 1000 * 1000 * 1000 + 7, PHI = BASE - 1;
    private static long MODULO = BASE;

    

    private void solve() {
        int n = readInt();
        int m = readInt();
        int q = readInt();

        int[] p = id14(n);
        int[] a = id14(m);

        int[] pIndexes = new int[n];
        for (int i = 0; i < n; ++i) {
            pIndexes[p[i]] = i;
        }

        for (int j = 0; j < m; ++j){
            a[j] = pIndexes[a[j]];
        }

        Point[] queries = id39(q);



        String answers = getAnswer(n, p, m, a, q, queries);



        out.println(answers);
    }

    static String getAnswer(
            int n, int[] p,
            int m, int[] a,
            int q, Point[] queries) {

        int[] counts = new int[n];
        for (int value : a) {
            counts[value]++;
        }

        int[][] indexes = new int[n][];
        for (int i = 0; i < n; ++i) {
            indexes[i] = new int[counts[i]];
        }

        for (int j = m - 1; j >= 0; --j) {
            indexes[a[j]][--counts[a[j]]] = j;
        }

        final int INF = m + 1;

        final int MAX_BIT = 19;
        int[][] table = new int[MAX_BIT][m + 2];
        for (int[] row : table) {
            Arrays.fill(row, INF);
        }

        for (int j = 0; j < m; ++j) {
            int value = a[j];
            if (value == n - 1) {
                table[0][j] = INF;
            } else {
                int[] nextIndexes = indexes[value + 1];
                int index = Arrays.binarySearch(nextIndexes, j);
                index = ~index;

                if (index < nextIndexes.length) {
                    table[0][j] = nextIndexes[index];
                } else {
                    table[0][j] = INF;
                }
            }
        }

        for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
            for (int j = 0; j < m; ++j) {
                table[bit + 1][j] = table[bit][table[bit][j]];
            }
        }

        int[] lastIndexes = new int[m];
        Arrays.fill(lastIndexes, INF);

        int[] zeroIndexes = indexes[0];
        for (int j = 0; j < m; ++j) {
            int cur = j;
            int value = a[j];

            int delta = n - value - 1;
            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                if (checkBit(delta, bit)) {
                    cur = table[bit][cur];
                }
            }

            if (cur == INF) continue;
            if (a[cur] != n - 1) continue;

            if (a[j] == 0) {
                lastIndexes[j] = cur;
            } else {
                int zero = Arrays.binarySearch(zeroIndexes, cur);
                if (zero < 0) {
                    zero = ~zero;
                }

                if (zero == zeroIndexes.length) continue;

                cur = zeroIndexes[zero];

                int need = a[j] - 1;
                for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                    if (checkBit(need, bit)) {
                        cur = table[bit][cur];
                    }
                }

                if (cur == INF) continue;
                if (a[cur] != value - 1) continue;
                lastIndexes[j] = cur;
            }
        }

        Rmq rmq = id37(lastIndexes);

        char[] answers = new char[q];
        for (int i = 0; i < q; ++i) {
            Point query = queries[i];
            int start = query.x - 1;
            int end = query.y - 1;

            int best = rmq.id9(start, end);
            int bestIndex = lastIndexes[best];

            if (bestIndex <= end) {
                answers[i] = '1';
            } else {
                answers[i] = '0';
            }
        }

        return new String(answers);
    }

    interface Rmq {

        @SuppressWarnings("unused")
        int getMin(int left, int right);
        int id9(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id23;
        int[][] table;

        int id11(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id23 = new int[n + 1];
            id23[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id23[i] = id23[i - 1];
                int length = (1 << id23[i]);
                if (length + length <= i) ++id23[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                int delta = (1 << bit);
                for (int i = 0, j = delta; j + delta <= n; ++i, ++j) {
                    table[bit + 1][i] = id11(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id9(int left, int right) {
            int length = (right - left + 1);

            int bit = id23[length];
            int segmentLength = (1 << bit);

            return id11(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id9(left, right)];
        }
    }

    private static Rmq id37(int[] array) {
        return new SparseTable(array).build();
    }

    static String id43(int n, int[] p,
                                 int m, int[] a,
                                 int q, Point[] queries) {
        char[] answers = new char[q];

        for (int it = 0; it < q; ++it) {
            int start = queries[it].x - 1, end = queries[it].y - 1;

            boolean found = false;
            for (int j = start; j <= end; ++j) {
                int value = a[j];

                int k = j;
                while (k <= end) {
                    if (a[k] == value) {
                        ++value;
                        if (value == n) break;
                    }

                    ++k;
                }

                if (a[j] > 0) {
                    value = 0;

                    while (k <= end) {
                        if (a[k] == value) {
                            ++value;
                            if (value == a[j]) break;
                        }

                        ++k;
                    }
                }

                if (k <= end) {
                    found = true;
                    break;
                }
            }

            if (found) {
                answers[it] = '1';
            } else {
                answers[it] = '0';
            }
        }

        return new String(answers);
    }


    static int square(Point zero, Point a, Point b) {
        return abs(
                det(a.x - zero.x, a.y - zero.y, b.x - zero.x, b.y - zero.y)
        );
    }

    static int det(int a, int b, int c, int d) {
        return a * d - b * c;
    }

    


    private final static boolean id5 = true;
    private final boolean id10 = !new File("input.txt").exists();



    private final static int id19 = 128;

    private final static boolean id31 = false;

    


    @SuppressWarnings("unused")
    private static long inverse(long x) {
        return binpow(x, MODULO - 2);
    }

    private static long binpow(long base, long power) {
        if (power == 0) return 1;
        if ((power & 1) == 0) {
            long half = binpow(base, power >> 1);
            return mult(half, half);
        } else {
            long prev = binpow(base, power - 1);
            return mult(prev, base);
        }
    }

    private static long add(long a, long b) { return (a + b) % MODULO; }

    @SuppressWarnings("unused")
    private static long subtract(long a, long b) { return add(a, MODULO - b % MODULO); }

    private static long mult(long a, long b) { return ((a % MODULO) * (b % MODULO)) % MODULO; }

    


    @SuppressWarnings("unused")
    void yesNo(boolean yes) {
        out.println(yes ? "YES" : "NO");
    }

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id10) {
                solve();
            } else {
                do {
                    try {
                        timeInit();
                        solve();
                        time();

                        out.println();
                        out.flush();
                    } catch (NumberFormatException | EOFException e) {
                        break;
                    }
                } while (id5);
            }

            out.close();
            time();
        }catch (Exception e){
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    


    private BufferedReader in;
    private OutputWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args){
        new Thread(null, new id15(), "", id19 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id10){
            if (fileName.isEmpty()) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new OutputWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new OutputWriter(fileName + ".out");
            }
        }else{
            in = new BufferedReader(new FileReader("input.txt"));
            out = new OutputWriter("output.txt");
        }
    }

    


    private long timeBegin;

    private void timeInit() {
        this.timeBegin = System.currentTimeMillis();
    }

    private void time(){
        long timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @SuppressWarnings("unused")
    private void debug(Object... objects){
        if (id10){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String id33() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = id33();
        if (null == line) throw new EOFException();
        return line;
    }

    private String readString() {
        while(!tok.hasMoreTokens()){
            tok = new StringTokenizer(readLine(), delim);
        }

        return tok.nextToken(delim);
    }

    


    private final char id7 = '\0';

    @SuppressWarnings("unused")
    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id7;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id8() {
        return readLine().toCharArray();
    }

    @SuppressWarnings("unused")
    private char[][] id26(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id8();
        }

        return field;
    }

    


    private long id24() {
        int sign = 1;
        long result = 0;
        boolean started = false;
        while (true) {
            try {
                int j = in.read();
                if (-1 == j) {
                    if (started) return sign * result;
                    throw new NumberFormatException();
                }

                if (j == '-') {
                    if (started) throw new NumberFormatException();
                    sign = -sign;
                }

                if ('0' <= j && j <= '9') {
                    result = result * 10 + j - '0';
                    started = true;
                } else if (started) {
                    return sign * result;
                }
            } catch (IOException e) {
                throw new RuntimeIOException(e);
            }
        }
    }

    private int readInt() {

        if (!id31) {
            return Integer.parseInt(readString());
        } else {
            return (int) id24();
        }
    }

    private int[] id1(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    @SuppressWarnings("unused")
    private int[] id12(int size) {
        Integer[] array = new Integer[size];

        for (int index = 0; index < size; ++index) {
            array[index] = readInt();
        }
        Arrays.sort(array);

        int[] sortedArray = new int[size];
        for (int index = 0; index < size; ++index) {
            sortedArray[index] = array[index];
        }

        return sortedArray;
    }

    private int[] id14(int size) {
        int[] array = id1(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id21(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id1(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] id35(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id14(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id31) {
            return Long.parseLong(readString());
        } else {
            return id24();
        }
    }

    @SuppressWarnings("unused")
    private long[] id17(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    @SuppressWarnings("unused")
    private double[] id4(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private BigInteger id30() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal id27() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] id39(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
        }

        return array;
    }

    


    @Deprecated
    @SuppressWarnings("unused")
    private List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new List[vertexNumber];

        for (int index = 0; index < vertexNumber; ++index){
            graph[index] = new ArrayList<>();
        }

        while (edgeNumber-- > 0){
            int from = readInt() - 1;
            int to = readInt() - 1;

            graph[from].add(to);
            graph[to].add(from);
        }

        return graph;
    }

    private static class GraphBuilder {

        final int size;
        final List<Integer>[] edges;

        static GraphBuilder createInstance(int size) {
            @SuppressWarnings("unchecked")
            List<Integer>[] edges = new List[size];
            for (int v = 0; v < size; ++v) {
                edges[v] = new ArrayList<>();
            }

            return new GraphBuilder(edges);
        }

        private GraphBuilder(List<Integer>[] edges) {
            this.size = edges.length;
            this.edges = edges;
        }

        public void addEdge(int from, int to) {
            id28(from, to);
            id28(to, from);
        }

        public void id28(int from, int to) {
            edges[from].add(to);
        }

        public int[][] build() {
            int[][] graph = new int[size][];
            for (int v = 0; v < size; ++v) {
                List<Integer> vEdges = edges[v];
                graph[v] = castInt(vEdges);
            }

            return graph;
        }
    }

    @SuppressWarnings("unused")
    private final static int id29 = 0, id16 = 1;

    @SuppressWarnings("unused")
    private int[][] id13(int vertexNumber, int edgesNumber) {
        return id13(vertexNumber, edgesNumber, id16, false);
    }

    private int[][] id13(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id28(from, to);
            else graphBuilder.addEdge(from, to);
        }

        return graphBuilder.build();
    }

    private static class Edge {
        int to;
        int w;

        Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    @SuppressWarnings("unused")
    private Edge[][] id32(int vertexNumber, int edgesNumber) {
        return id32(vertexNumber, edgesNumber, id16, false);
    }

    private Edge[][] id32(int vertexNumber, int edgesNumber,
                                       int indexation, boolean directed) {
        @SuppressWarnings("unchecked")
        List<Edge>[] graph = new List[vertexNumber];
        for (int v = 0; v < vertexNumber; ++v) {
            graph[v] = new ArrayList<>();
        }

        while (edgesNumber --> 0) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;
            int w = readInt();

            graph[from].add(new Edge(to, w));
            if (!directed) graph[to].add(new Edge(from, w));
        }

        Edge[][] graphArrays = new Edge[vertexNumber][];
        for (int v = 0; v < vertexNumber; ++v) {
            graphArrays[v] = graph[v].toArray(new Edge[0]);
        }

        return graphArrays;
    }

    


    private static class id34 {

        @SuppressWarnings("unused")
        static Comparator<id34> increaseComparator = new Comparator<id15.id34>() {
            @Override
            public int compare(id15.id34 id25, id15.id34 id18) {
                int value1 = id25.value;
                int value2 = id18.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id25.index;
                int index2 = id18.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static Comparator<id34> id2 = new Comparator<id15.id34>() {
            @Override
            public int compare(id15.id34 id25, id15.id34 id18) {
                int value1 = id25.value;
                int value2 = id18.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id25.index;
                int index2 = id18.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static id34[] from(int[] array) {
            id34[] iip = new id34[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id34(array[i], i);
            }

            return iip;
        }

        int value, index;

        id34(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        @SuppressWarnings("unused")
        int id6() {
            return index + 1;
        }
    }

    @SuppressWarnings("unused")
    private id34[] id3(int size) {
        id34[] array = new id34[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id34(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id42 = 12;

        private int precision;
        private String format, id41;

        {
            precision = id42;

            format = createFormat(precision);
            id41 = format + " ";
        }

        OutputWriter(OutputStream out) {
            super(out);
        }

        OutputWriter(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        int getPrecision() {
            return precision;
        }

        void setPrecision(int precision) {
            precision = max(0, precision);
            this.precision = precision;

            format = createFormat(precision);
            id41 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }

        @Override
        public void println(double d){
            print(d);
            println();
        }

        void id36(double d){
            printf(id41, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id36(d[i]);
            }

            print(d[d.length - 1]);
        }

        @SuppressWarnings("unused")
        void printlnAll(double... d){
            printAll(d);
            println();
        }

        void printAll(int... array) {
            for (int value : array) {
                print(value + " ");
            }
        }

        @SuppressWarnings("unused")
        void printlnAll(int... array) {
            printAll(array);
            println();
        }

        void printIndexes(int... indexes) {
            for (int index : indexes) {
                print((index + 1) + " ");
            }
        }

        @SuppressWarnings("unused")
        void printlnIndexes(int... indexes) {
            printIndexes(indexes);
            println();
        }

        void printAll(long... array) {
            for (long value : array) {
                print(value + " ");
            }
        }

        @SuppressWarnings("unused")
        void printlnAll(long... array) {
            printAll(array);
            println();
        }
    }

    


    private static class EOFException extends RuntimeException {

        EOFException() {
            super();
        }
    }

    private static class RuntimeIOException extends RuntimeException {

        
        private static final long id38 = -6463830523020118289L;

        RuntimeIOException(Throwable cause) {
            super(cause);
        }
    }

    

    

    


    private static void swap(int[] array, int i, int j) {
        if (i != j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    private static <T> void swap(T[] array, int i, int j) {
        if (i != j) {
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    private static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static final int[][] steps8 = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };

    @SuppressWarnings("unused")
    private static boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
        return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
    }

    private static boolean checkIndex(int index, int lim){
        return (0 <= index && index < lim);
    }

    


    private static int getBit(long mask, int bit) { return (int)((mask >> bit) & 1); }

    @SuppressWarnings("unused")
    private static boolean checkBit(long mask, int bit){
        return getBit(mask, bit) != 0;
    }

    


    @SuppressWarnings("unused")
    private static long getSum(int[] array) {
        long sum = 0;
        for (int value: array) {
            sum += value;
        }

        return sum;
    }

    @SuppressWarnings("unused")
    private static Point id20(int[] array) {
        int min = array[0];
        int max = array[0];

        for (int index = 0, size = array.length; index < size; ++index, ++index) {
            int value = array[index];

            if (index == size - 1) {
                min = min(min, value);
                max = max(max, value);
            } else {
                int otherValue = array[index + 1];

                if (value <= otherValue) {
                    min = min(min, value);
                    max = max(max, otherValue);
                } else {
                    min = min(min, otherValue);
                    max = max(max, value);
                }
            }
        }

        return new Point(min, max);
    }

    


    @SuppressWarnings("unused")
    private static boolean isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) return false;
        }

        return true;
    }

    @SuppressWarnings("unused")
    private static int[] id22(int n) {
        boolean[] used = new boolean[n];
        used[0] = used[1] = true;

        int size = 0;
        for (int i = 2; i < n; ++i) {
            if (!used[i]) {
                ++size;
                for (int j = 2 * i; j < n; j += i) {
                    used[j] = true;
                }
            }
        }

        int[] primes = new int[size];
        for (int i = 0, cur = 0; i < n; ++i) {
            if (!used[i]) {
                primes[cur++] = i;
            }
        }

        return primes;
    }

    


    @SuppressWarnings("unused")
    static int[] id40(int value) {
        List<Integer> id0 = new ArrayList<>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id0.add(divisor);
                if (divisor * divisor != value) {
                    id0.add(value / divisor);
                }
            }
        }

        return castInt(id0);
    }

    @SuppressWarnings("unused")
    static long[] id40(long value) {
        List<Long> id0 = new ArrayList<>();
        for (long divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id0.add(divisor);
                if (divisor * divisor != value) {
                    id0.add(value / divisor);
                }
            }
        }

        return castLong(id0);
    }

    


    @SuppressWarnings("unused")
    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

    


    private static int[] castInt(List<Integer> list) {
        int[] array = new int[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    @SuppressWarnings("unused")
    private static long[] castLong(List<Long> list) {
        long[] array = new long[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    


    
    @SuppressWarnings("unused")
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }

    @SuppressWarnings("unused")
    private static List<Integer> shuffled(List<Integer> list) {
        Collections.shuffle(list, rnd);
        return list;
    }
}