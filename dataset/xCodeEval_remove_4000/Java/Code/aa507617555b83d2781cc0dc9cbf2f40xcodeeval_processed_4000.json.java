import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class C implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";

    int modulo;
    int[][] graph;

    int[] parents;

    int[][] vertexCounts;
    long[][] id22;

    long[] answers;

    private void solve() {
        int n = readInt();
        this.modulo = readInt();
        int m = n - 1;

        GraphBuilder graphBuilder = GraphBuilder.createInstance(n + 1);
        for (int i = 0; i < m; ++i) {
            int from = readInt() - 1;
            int to = readInt() - 1;

            graphBuilder.addEdge(from, to);
        }

        final int root = 0;
        graphBuilder.addEdge(n, root);

        this.graph = graphBuilder.build();

        this.parents = new int[n + 1];
        Arrays.fill(parents, -1);

        this.vertexCounts = new int[modulo][n + 1];
        this.id22 = new long[modulo][n + 1];

        

        id33(n);
        vertexCounts[0][n]--;

        int[] counts = new int[modulo];
        long[] sums = new long[modulo];

        for (int reminder = 0; reminder < modulo; ++reminder) {
            counts[reminder] = vertexCounts[reminder][n];
            sums[reminder] = id22[reminder][n];
        }

        this.answers = new long[n];

        id38(root, counts, sums);

        long totalAnswer = getSum(answers);
        totalAnswer /= 2;

        out.println(totalAnswer);
    }

    void id38(final int from, int[] counts, long[] sums) {
        final int[] id19 = new int[modulo];
        final long[] id30 = new long[modulo];

        id30[1 % modulo] -= vertexCounts[0][from];
        for (int reminder = 0; reminder < modulo; ++reminder) {
            int parentReminder = (reminder + 1) % modulo;

            id19[parentReminder] += counts[parentReminder] - vertexCounts[reminder][from];
            id30[parentReminder] += sums[parentReminder] - id22[reminder][from];
        }

        final int[] curCounts = new int[modulo];
        final long[] id21 = new long[modulo];

        for (int reminder = 0; reminder < modulo; ++reminder) {
            int parentReminder = (reminder + modulo - 1) % modulo;

            curCounts[reminder] = vertexCounts[reminder][from] + id19[parentReminder];
            id21[reminder] = id22[reminder][from] + id30[parentReminder];
        }

        id21[1 % modulo] += id19[0];

        for (int reminder = 0; reminder < modulo; ++reminder) {
            answers[from] += id21[reminder];
        }

        for (int to : graph[from]) {
            if (to == parents[from]) continue;

            id38(to, curCounts, id21);
        }
    }

    void id33(final int from) {
        vertexCounts[0][from]++;

        for (int to : graph[from]) {
            if (to == parents[from]) continue;

            parents[to] = from;
            id33(to);

            upFrom(to);
        }
    }

    void upFrom(int v) {
        int parent = parents[v];
        if (parent == -1) return;

        for (int reminder = 0; reminder < modulo; ++reminder) {
            int parentReminder = (reminder + 1) % modulo;
            vertexCounts[parentReminder][parent] += vertexCounts[reminder][v];
            id22[parentReminder][parent] += id22[reminder][v];
        }

        id22[1 % modulo][parent] += vertexCounts[0][v];
    }

    class SegmentTree {
        int size;
        int modulo;

        int[][] id24;
        long[][] id12;

        SegmentTree(int[] a, int modulo) {
            this.size = a.length;
            this.modulo = modulo;

            this.id24 = new int[modulo][size << 2];
            this.id12 = new long[modulo][size << 2];

            build(1, 0, size - 1, a);
        }

        void build(int v, int left, int right, int[] a) {
            if (left > right) return;
            if (left == right) {
                int value = a[left];
                id24[value % modulo][v] = 1;
                id12[value % modulo][v] = value;
            } else {
                int mid = ((left + right) >> 1);
                int vLeft = (v << 1), vRight = (vLeft + 1);

                build(vLeft, left, mid, a);
                build(vRight, mid + 1, right, a);

                update(v, vLeft, vRight);
            }
        }

        void update(int v, int vLeft, int vRight) {
            for (int reminder = 0; reminder < modulo; ++reminder) {
                id24[reminder][v] = id24[reminder][vLeft] + id24[reminder][vRight];
                id12[reminder][v] = id12[reminder][vLeft] + id12[reminder][vRight];
            }
        }
    }

    


    private final static boolean id2 = false;
    private final static boolean id5 = true;
    private final boolean id9 = System.getProperty("id9") != null;

    private final static int id15 = 128;

    private final static boolean id29 = false;

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id9) {
                solve();
            } else {
                do {
                    try {
                        timeInit();
                        solve();
                        time();

                        out.println();
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (id2) break;
                        else throw e;
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
        new Thread(null, new C(), "", id15 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id9){
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

    private void debug(Object... objects){
        if (id9){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String readLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readString() {
        try {
            while(!tok.hasMoreTokens()){
                tok = new StringTokenizer(readLine());
            }

            return tok.nextToken(delim);
        } catch (NullPointerException e) {
            return null;
        }
    }

    


    private final char id7 = '\0';

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

    private char[][] id25(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id8();
        }

        return field;
    }

    


    private long id20() {
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

        if (!id29) {
            return Integer.parseInt(readString());
        } else {
            return (int) id20();
        }
    }

    private int[] id1(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id10(int size) {
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

    private int[] id11(int size) {
        int[] array = id1(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id17(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id1(columnsCount);
        }

        return matrix;
    }

    private int[][] id32(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id11(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id29) {
            return Long.parseLong(readString());
        } else {
            return id20();
        }
    }

    private long[] id13(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id4(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id28() {
        return new BigInteger(readString());
    }

    private BigDecimal id26() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id36(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
        }

        return array;
    }

    


    @Deprecated
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
            id27(from, to);
            id27(to, from);
        }

        public void id27(int from, int to) {
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

    


    private static class id31 {

        static Comparator<id31> increaseComparator = new Comparator<C.id31>() {

            @Override
            public int compare(C.id31 id23, C.id31 id14) {
                int value1 = id23.value;
                int value2 = id14.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id23.index;
                int index2 = id14.index;

                return index1 - index2;
            }
        };

        static Comparator<id31> id0 = new Comparator<C.id31>() {

            @Override
            public int compare(C.id31 id23, C.id31 id14) {
                int value1 = id23.value;
                int value2 = id14.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id23.index;
                int index2 = id14.index;

                return index1 - index2;
            }
        };

        static id31[] from(int[] array) {
            id31[] iip = new id31[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id31(array[i], i);
            }

            return iip;
        }

        int value, index;

        id31(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id6() {
            return index + 1;
        }
    }

    private id31[] id3(int size) {
        id31[] array = new id31[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id31(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id40 = 12;

        private int precision;
        private String format, id39;

        {
            precision = id40;

            format = createFormat(precision);
            id39 = format + " ";
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
            id39 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }

        void id34(double d){
            printf(id39, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id34(d[i]);
            }

            print(d[d.length - 1]);
        }

        @Override
        public void println(double d){
            printlnAll(d);
        }

        void printlnAll(double... d){
            printAll(d);
            println();
        }
    }

    


    private static class RuntimeIOException extends RuntimeException {

        
        private static final long id35 = -6463830523020118289L;

        RuntimeIOException(Throwable cause) {
            super(cause);
        }
    }

    

    

    


    private static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static final int[][] steps8 = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };

    private static boolean checkCell(int row, int rowsCount, int column, int columnsCount) {
        return checkIndex(row, rowsCount) && checkIndex(column, columnsCount);
    }

    private static boolean checkIndex(int index, int lim){
        return (0 <= index && index < lim);
    }

    


    private static boolean checkBit(int mask, int bit){
        return (mask & (1 << bit)) != 0;
    }
    private static boolean checkBit(long mask, int bit){
        return (mask & (1L << bit)) != 0;
    }

    


    private static long getSum(int[] array) {
        long sum = 0;
        for (int value: array) {
            sum += value;
        }

        return sum;
    }

    private static long getSum(long[] array) {
        long sum = 0;
        for (long value: array) {
            sum += value;
        }

        return sum;
    }

    private static Point id16(int[] array) {
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

    


    private static int[] id18(int n) {
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

    


    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

    


    private static class MultiSet<ValueType> {

        public static <ValueType> MultiSet<ValueType> id37() {
            Map<ValueType, Integer> multiset = new HashMap<>();
            return new MultiSet<>(multiset);
        }

        private final Map<ValueType, Integer> multiset;
        private int size;

        public MultiSet(Map<ValueType, Integer> multiset) {
            this.multiset = multiset;
            this.size = 0;
        }

        public int size() {
            return size;
        }

        public void inc(ValueType value) {
            int count = get(value);
            multiset.put(value, count + 1);

            ++size;
        }

        public void dec(ValueType value) {
            int count = get(value);
            if (count == 0) return;

            if (count == 1) multiset.remove(value);
            else multiset.put(value, count - 1);

            --size;
        }

        public int get(ValueType value) {
            Integer count = multiset.get(value);
            return (count == null ? 0 : count);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id35 = -3793737771950984481L;

        public IdMap() {
            super();
        }

        int getId(KeyType key) {
            Integer id = super.get(key);
            if (id == null) {
                super.put(key, id = size());
            }

            return id;
        }
    }

    


    private static int[] castInt(List<Integer> list) {
        int[] array = new int[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }

    private static long[] castLong(List<Long> list) {
        long[] array = new long[list.size()];
        for (int i = 0; i < array.length; ++i) {
            array[i] = list.get(i);
        }

        return array;
    }
}

