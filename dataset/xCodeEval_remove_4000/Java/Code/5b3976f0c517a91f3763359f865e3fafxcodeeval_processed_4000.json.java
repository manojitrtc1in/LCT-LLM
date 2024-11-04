
import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;
import java.util.zip.CRC32;

import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;


public class id16 implements Runnable {

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private static long BASE = 1000 * 1000 * 1000 + 7, PHI = BASE - 1;
    private static long MODULO = BASE;

    private void solve() {
        int tests = readInt();
        while (tests-- > 0) {
            solveTest();
        }
    }

    private void solveTest() {
        char[] s = id10();

        int id38 = 0;
        while (id38 < s.length - 1 - id38 &&
                s[id38] == s[s.length - 1 - id38]
                ) ++id38;


        int[] id13 = manacher(s);

        int leftEnd = id38 * 2 - 1;
        int rightStart = (s.length - 1 - id38) * 2 + 3;

        int bestCenter = -1, bestSize = -1, bestType = -1;

        final int EVEN = 0, ODD = 1;

        for (int i = 0; i < id13.length; ++i) {
            int size = id13[i];

            size = Math.min(size, i - leftEnd);
            size = Math.min(size, rightStart - i);

            int id1 = i - size;
            int id4 = i + size;

            int type = (i % 2);

            if (id1 == leftEnd || id4 == rightStart) {
                size /= 2;

                int totalSize = id38 + size + size - type + id38;
                if (bestSize < totalSize) {
                    bestSize = totalSize;
                    bestCenter = i;
                    bestType = type;
                }
            }
        }

        for (int i = 0; i < id38; ++i) {
            out.print(s[i]);
        }

        int leftSize = (bestCenter - leftEnd);
        int rightSize = (rightStart - bestCenter);

        int size = Math.min(leftSize, rightSize);
        for (int i = bestCenter - size + 1; i < bestCenter + size; ++i) {
            if (i % 2 == 1) {
                out.print(s[i / 2]);
            }
        }

        for (int i = s.length - id38; i < s.length; ++i) {
            out.print(s[i]);
        }
        out.println();
    }

    int[] manacher(char[] s0) {
        int n = s0.length;
        char[] s = new char[n + n + 1];
        Arrays.fill(s, '
        for (int i = 1; i < s.length; i += 2) {
            s[i] = s0[i / 2];
        }

        int[] id13 = new int[s.length];
        for (int left = -1, right = -1, i = 0; i < s.length; ++i) {
            if (right < i) {
                left = i;
                right = i;
            }

            int delta = right - i;
            int size = Math.min(id13[left + delta], delta);

            while (i - size >= 0 && i + size < s.length && s[i - size] == s[i + size]) ++size;
            id13[i] = size;

            if (i + size - 1 > right) {
                right = i + size - 1;
                left = i - size + 1;
            }
        }

        return id13;
    }

    private static void swap(long[] array, int i, int j) {
        if (i != j) {
            long tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    private static int partition(long[] array, int startInclusive, int endExclusive) {
        int pivotIndex = rnd.nextInt(endExclusive - startInclusive) + startInclusive;
        return partition(array, startInclusive, endExclusive, pivotIndex);
    }

    private static int partition(long[] array, int startInclusive, int endExclusive, int pivotIndex) {
        int endInclusive = endExclusive - 1;

        long pivotValue = array[pivotIndex];
        swap(array, pivotIndex, endInclusive);

        int storeIndex = startInclusive;
        for (int index = startInclusive; index < endInclusive; ++index) {
            if (array[index] < pivotValue) {
                swap(array, storeIndex, index);
                ++storeIndex;
            }
        }

        swap(array, storeIndex, endInclusive);

        return storeIndex;
    }

    @SuppressWarnings("unused")
    private static long nthElement(long[] array, int index, int size) {
        int left = 0, right = size;
        while (true) {
            int mid = partition(array, left, right);

            if (mid == index) return array[mid];

            if (index < mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    


    


    private final static boolean id7 = true;
    private final boolean id11 = !new File("input.txt").exists();



    private final static int id20 = 128;

    private final static boolean id32 = false;

    


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

    private static long add(long a, long b) {
        return (a + b) % MODULO;
    }

    @SuppressWarnings("unused")
    private static long subtract(long a, long b) {
        return add(a, MODULO - b % MODULO);
    }

    private static long mult(long a, long b) {
        return ((a % MODULO) * (b % MODULO)) % MODULO;
    }

    


    @SuppressWarnings("unused")
    boolean yesNo(boolean yes) {


        out.println(yes ? "yes" : "no");
        return yes;
    }

    


    public void run() {
        try {
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id11) {
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
                } while (id7);
            }

            out.close();
            time();
        } catch (Exception e) {
            e.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    


    private BufferedReader in;
    private OutputWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new id16(), "", id20 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException {
        Locale.setDefault(Locale.US);

        if (id11) {
            if (fileName.isEmpty()) {
                in = new BufferedReader(new InputStreamReader(System.in));
                out = new OutputWriter(System.out);
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new OutputWriter(fileName + ".out");
            }
        } else {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new OutputWriter("output.txt");
        }
    }

    


    private long timeBegin;

    private void timeInit() {
        this.timeBegin = System.currentTimeMillis();
    }

    private void time() {
        long timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @SuppressWarnings("unused")
    private void debug(Object... objects) {
        if (id11) {
            for (Object o : objects) {
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String id35() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = id35();
        if (null == line) throw new EOFException();
        return line;
    }

    private String readString() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(readLine(), delim);
        }

        return tok.nextToken(delim);
    }

    


    private final char id9 = '\0';

    @SuppressWarnings("unused")
    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1) {
                return id9;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id10() {
        return readLine().toCharArray();
    }

    @SuppressWarnings("unused")
    private char[][] id26(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id10();
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
                if (-1 == j){
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

        if (!id32) {
            return Integer.parseInt(readString());
        } else {
            return (int) id24();
        }
    }

    private int[] id3(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index) {
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

    private int[] id15(int size) {
        int[] array = id3(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id22(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id3(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] id37(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id15(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id32) {
            return Long.parseLong(readString());
        } else {
            return id24();
        }
    }

    @SuppressWarnings("unused")
    private long[] id18(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index) {
            array[index] = readLong();
        }

        return array;
    }

    @SuppressWarnings("unused")
    private long[] id29(int size) {
        long[] array = id18(size);

        Long[] objArray = new Long[size];
        for (int index = 0; index < size; ++index) {
            objArray[index] = array[index];
        }

        Arrays.sort(objArray);

        for (int index = 0; index < size; ++index) {
            array[index] = objArray[index];
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    @SuppressWarnings("unused")
    private double[] id6(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index) {
            array[index] = readDouble();
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private BigInteger id31() {
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
    private Point[] id41(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index) {
            array[index] = readPoint();
        }

        return array;
    }

    


    @Deprecated
    @SuppressWarnings("unused")
    private List<Integer>[] readGraph(int vertexNumber, int edgeNumber) {
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new List[vertexNumber];

        for (int index = 0; index < vertexNumber; ++index) {
            graph[index] = new ArrayList<>();
        }

        while (edgeNumber-- > 0) {
            int from = readInt() - 1;
            int to = readInt() - 1;

            graph[from].add(to);
            graph[to].add(from);
        }

        return graph;
    }

    public long id45(int n, int k, Edge[][] graph) {
        class id33 {
            int from, to;
            int w;

            public id33(int from, int to, int w) {
                this.from = from;
                this.to = to;
                this.w = w;
            }
        }

        id33[] edges = new id33[n - 1];
        for (int v = 0, index = 0; v < n; ++v) {
            for (Edge e : graph[v]) if (v < e.to) edges[index++] = new id33(v, e.to, e.w);
        }

        long bestAnswer = 0;

        int[] degrees = new int[n];
        for (int mask = 0; mask < (1 << edges.length); ++mask){
            Arrays.fill(degrees, 0);

            long sum = 0;
            for (int bit = 0; bit < edges.length; ++bit) {
                if (checkBit(mask, bit)) {
                    sum += edges[bit].w;

                    degrees[edges[bit].from]++;
                    degrees[edges[bit].to]++;
                }
            }

            for (int v = 0; v < n; ++v) {
                if (degrees[v] > k) sum = -1;
            }

            bestAnswer = Math.max(bestAnswer, sum);
        }

        return bestAnswer;
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
    private final static int id30 = 0, id17 = 1;

    @SuppressWarnings("unused")
    private int[][] id14(int vertexNumber, int edgesNumber) {
        return id14(vertexNumber, edgesNumber, id17, false);
    }

    private int[][] id14(int vertexNumber, int edgesNumber,
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

    static class Edge {
        int to;
        int w;

        Edge(int to, int w) {
            this.to = to;
            this.w = w;
        }
    }

    @SuppressWarnings("unused")
    private Edge[][] id34(int vertexNumber, int edgesNumber) {
        return id34(vertexNumber, edgesNumber, id17, false);
    }

    private Edge[][] id34(int vertexNumber, int edgesNumber,
                                       int indexation, boolean directed) {
        @SuppressWarnings("unchecked")
        List<Edge>[] graph = new List[vertexNumber];
        for (int v = 0; v < vertexNumber; ++v) {
            graph[v] = new ArrayList<>();
        }

        while (edgesNumber-- > 0) {
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

    


    private static class id36 {

        @SuppressWarnings("unused")
        static Comparator<id36> increaseComparator = new Comparator<id16.id36>() {
            @Override
            public int compare(id16.id36 id25, id16.id36 id19) {
                int value1 = id25.value;
                int value2 = id19.value;

                if (value1 != value2)return value1 - value2;

                int index1 = id25.index;
                int index2 = id19.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static Comparator<id36> id2 = new Comparator<id16.id36>() {
            @Override
            public int compare(id16.id36 id25, id16.id36 id19) {
                int value1 = id25.value;
                int value2 = id19.value;

                if (value1 != value2)return -(value1 - value2);

                int index1 = id25.index;
                int index2 = id19.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static id36[] from(int[] array) {
            id36[] iip = new id36[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id36(array[i], i);
            }

            return iip;
        }

        int value, index;

        id36(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        @SuppressWarnings("unused")
        int id8() {
            return index + 1;
        }
    }

    @SuppressWarnings("unused")
    private id36[] id5(int size) {
        id36[] array = new id36[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id36(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id44 = 12;

        private int precision;
        private String format, id43;

        {
            precision = id44;

            format = createFormat(precision);
            id43 = format + " ";
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
            id43 = format + " ";
        }

        String createFormat(int precision) {
            return "%." + precision + "f";
        }

        @Override
        public void print(double d) {
            printf(format, d);
        }

        @Override
        public void println(double d) {
            print(d);
            println();
        }

        void id39(double d) {
            printf(id43, d);
        }

        void printAll(double... d) {
            for (int i = 0; i < d.length - 1; ++i) {
                id39(d[i]);
            }

            print(d[d.length - 1]);
        }

        @SuppressWarnings("unused")
        void printlnAll(double... d) {
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

        
        private static final long id40 = -6463830523020118289L;

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

    private static boolean checkIndex(int index, int lim) {
        return (0 <= index && index < lim);
    }

    


    private static int getBit(long mask, int bit) {
        return (int) ((mask >> bit) & 1);
    }

    @SuppressWarnings("unused")
    private static boolean checkBit(long mask, int bit) {
        return getBit(mask, bit) != 0;
    }

    


    @SuppressWarnings("unused")
    private static long getSum(int[] array) {
        long sum = 0;
        for (int value : array) {
            sum += value;
        }

        return sum;
    }

    private static long getSum(long[] array) {
        long sum = 0;
        for (long value : array) {
            sum += value;
        }

        return sum;
    }

    @SuppressWarnings("unused")
    private static Point id21(int[] array) {
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
    private static int[] id23(int n) {
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
    static int[] id42(int value) {
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
    static long[] id42(long value) {
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