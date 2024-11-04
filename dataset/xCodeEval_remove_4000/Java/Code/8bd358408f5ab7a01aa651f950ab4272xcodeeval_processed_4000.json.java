import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class F implements Runnable{

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private static long MODULO = 1000 * 1000 * 1000 + 7;

    class Query {
        int start, end;
        int value;

        public Query(int start, int end, int x) {
            this.start = start;
            this.end = end;
            this.value = x;
        }
    }

    

    private void solve() {
        int n = readInt();
        int q = readInt();
        int[] a = id2(n);

        Query[] queries = new Query[q];
        for (int i = 0; i < q; ++i) {
            String type = readString();
            int start = readInt() - 1;
            int end = readInt() - 1;
            int x = (type.charAt(0) == 'T' ? -1 : readInt());
            queries[i] = new Query(start, end, x);
        }

        long[] answers = getAnswers(n, a, q, queries);
        for (long answer : answers) {
            out.println(answer);
        }
    }

    static final int MAX_X = 300;

    static int[] primes;
    static long[] masks;

    static int id24;
    static long[] id9, id37;

    static int[] rootLogs;

    static {
        primes = id21(MAX_X);
        masks = new long[MAX_X + 1];

        for (int i = 0; i < primes.length; ++i) {
            int prime = primes[i];
            for (int x = prime; x <= MAX_X; x += prime) {
                masks[x] |= (1L << i);
            }
        }

        final long root = id40();

        id24 = 40 * 1000;
        id9 = new long[id24 + 1];
        id37 = new long[id24];

        id9[0] = 1;
        for (int i = 1; i <= id24; ++i) {
            id9[i] = mult(id9[i - 1], root);
        }

        final long blockPower = id9[id24];

        id37[0] = 1;
        for (int i = 1; i < id24; ++i) {
            id37[i] = mult(id37[i - 1], blockPower);
        }

        Map<Long, Integer> id26 = new HashMap<>();
        for (int power = 0; power < id24; ++power) {
            id26.put(id9[power], power);
        }

        long[] id38 = new long[id24];

        long id41 = inverse(blockPower);

        id38[0] = 1;
        for (int i = 1; i < id24; ++i) {
            id38[i] = mult(id38[i - 1], id41);
        }

        rootLogs = new int[MAX_X + 1];
        for (int x = 1; x <= MAX_X; ++x) {
            rootLogs[x] = id28(x, id26, id38);
        }
    }

    static int id28(long x, Map<Long, Integer> id26, long[] id38) {
        for (int block = 0; block < id24; ++block) {
            Integer smallLog = id26.get(mult(x, id38[block]));
            if (smallLog != null) {
                return block * id24 + smallLog;
            }
        }

        return -1;
    }

    static long id40() {
        long id29 = MODULO - 1;
        long[] id0 = id49(id29);

        root_for:
        for (long root = 1; root < MODULO; ++root) {
            for (long divisor : id0) {
                if (divisor != id29 && binpow(root, divisor) == 1) continue root_for;
            }

            return root;
        }

        return -1;
    }

    static final int id52 = (int)MODULO - 1;

    static int powerAdd(int a, int b) {
        return (a + b) % id52;
    }

    static int powerSubtract(int a, int b) {
        return powerAdd(a, id52 - b);
    }

    static int powerMult(long a, long b) {
        return (int)((a * b) % id52);
    }

    long[] getAnswers(int n, int[] a, int q, Query[] queries) {
        List<Long> answers = new ArrayList<>();

        int[] id22 = new int[primes.length];
        for (int i = 0; i < primes.length; ++i) {
            int prime = primes[i];
            id22[i] = powerSubtract(rootLogs[prime - 1], rootLogs[prime]);
        }

        final int maskSize = 16;
        final int id47 = (1 << maskSize), maskFilter = id47 - 1;
        final int blocksCount = Long.SIZE / maskSize;

        int[][] id35 = new int[4][1 << 16];
        for (int blockIndex = 0, blockStart = 0; blockIndex < blocksCount; ++blockIndex, blockStart += maskSize) {
            for (int mask = 0; mask < id47; ++mask) {
                int result = 0;
                for (int bit = 0; bit < maskSize && blockStart + bit < id22.length; ++bit) {
                    if (checkBit(mask, bit)) {
                        result = powerAdd(result, id22[bit + blockStart]);
                    }
                }

                id35[blockIndex][mask] = result;
            }
        }

        SegmentTree tree = new SegmentTree(n);
        tree.buildArray(a);

        for (Query query : queries) {
            if (query.value == -1) {
                SegmentTree.Vertex result = tree.getSegment(query.start, query.end);

                int answerLog = result.value;

                long answerMask = result.mask;
                for (int blockIndex = 0; blockIndex < blocksCount; ++blockIndex, answerMask >>= maskSize) {
                    int blockMask = (int)(answerMask & maskFilter);
                    answerLog = powerAdd(answerLog, id35[blockIndex][blockMask]);
                }

                int largeLog = answerLog / id24;
                int smallLog = answerLog % id24;

                long answer = mult(id37[largeLog], id9[smallLog]);
                answers.add(answer);
            } else {
                tree.updateSegment(query.start, query.end, query.value);
            }
        }

        return castLong(answers);
    }

    static class SegmentTree {

        int size;

        class Vertex {
            int value;
            long mask;

            int lazyValue;
            long lazyMask;

            int length;

            Vertex left, right;

            Vertex() {
                clearBase();
            }

            void clearBase() {
                value = 0;
                mask = 0;
            }

            int getValue() {
                return powerAdd(powerMult(lazyValue, length), value);
            }

            long getMask() {
                return lazyMask | mask;
            }

            void clearLazy() {
                lazyValue = 0;
                lazyMask = 0;
            }

            void updateLazy(int value) {
                lazyValue = powerAdd(lazyValue, rootLogs[value]);
                lazyMask |= masks[value];
            }

            void update() {
                clearBase();
                updateFrom(left);
                updateFrom(right);
            }

            void updateFrom(Vertex source) {
                value = powerAdd(value, source.getValue());
                mask |= source.getMask();
            }

            void push() {
                if (lazyMask != 0) {
                    left.pushFrom(this);
                    right.pushFrom(this);
                    clearLazy();
                }
            }

            void pushFrom(Vertex source) {
                lazyValue = powerAdd(lazyValue, source.lazyValue);
                lazyMask |= source.lazyMask;
            }
        }

        Vertex root;


        public SegmentTree(int n) {
            this.size = n;
        }

        int[] a;
        public void buildArray(int[] a) {
            this.a = a;
            this.root = buildTree(0, size);
        }

        private Vertex buildTree(int left, int right) {
            Vertex v = new Vertex();

            v.clearLazy();
            v.length = right - left;

            if (left + 1 == right) {
                int element = a[left];
                v.value = rootLogs[element];
                v.mask = masks[element];
            } else {
                int mid = (left + right) >> 1;

                v.left = buildTree(left, mid);
                v.right = buildTree(mid, right);

                v.update();
            }

            return v;
        }

        int start, end;

        int value;
        public void updateSegment(int start, int end, int value) {
            this.start = start;
            this.end = end + 1;
            this.value = value;

            id42(root, 0, size);
        }

        private void id42(Vertex v, int left, int right) {
            if (start <= left && right <= end) {
                v.updateLazy(value);
            } else {
                int mid = (left + right) >> 1;

                v.push();

                if (start < mid) id42(v.left, left, mid);
                if (mid < end) id42(v.right, mid, right);

                v.update();
            }
        }

        Vertex result = new Vertex();

        public Vertex getSegment(int start, int end) {
            this.start = start;
            this.end = end + 1;

            this.result.clearBase();

            id10(root, 0, size);

            return result;
        }

        private void id10(Vertex v, int left, int right) {
            if (start <= left && right <= end) {
                result.updateFrom(v);
            } else {
                int mid = (left + right) >> 1;

                v.push();

                if (start < mid) id10(v.left, left, mid);
                if (mid < end) id10(v.right, mid, right);

                v.update();
            }
        }
    }

    


    private final static boolean id5 = true;
    private final boolean id11 = !new File("input.txt").exists();



    private final static int id18 = 128;

    private final static boolean id34 = false;

    


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

    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    @SuppressWarnings("unused")
    void yesNo(boolean yes) {
        out.println(yes ? "YES" : "NO");
    }

    


    public void run(){
        try{
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
        new Thread(null, new F(), "", id18 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id11){
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
        if (id11){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String id39() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = id39();
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
    private char[][] id27(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id8();
        }

        return field;
    }

    


    private long id23() {
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

        if (!id34) {
            return Integer.parseInt(readString());
        } else {
            return (int) id23();
        }
    }

    private int[] id2(int size) {
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
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id20(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] id44(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id14(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id34) {
            return Long.parseLong(readString());
        } else {
            return id23();
        }
    }

    @SuppressWarnings("unused")
    private long[] id16(int size) {
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
    private BigInteger id33() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal id30() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] id48(int size) {
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
            id31(from, to);
            id31(to, from);
        }

        public void id31(int from, int to) {
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
    private final static int id32 = 0, id15 = 1;

    @SuppressWarnings("unused")
    private int[][] id13(int vertexNumber, int edgesNumber) {
        return id13(vertexNumber, edgesNumber, id15, false);
    }

    private int[][] id13(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id31(from, to);
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
    private Edge[][] id36(int vertexNumber, int edgesNumber) {
        return id36(vertexNumber, edgesNumber, id15, false);
    }

    private Edge[][] id36(int vertexNumber, int edgesNumber,
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

    


    private static class id43 {

        @SuppressWarnings("unused")
        static Comparator<id43> increaseComparator = new Comparator<F.id43>() {
            @Override
            public int compare(F.id43 id25, F.id43 id17) {
                int value1 = id25.value;
                int value2 = id17.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id25.index;
                int index2 = id17.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static Comparator<id43> id1 = new Comparator<F.id43>() {
            @Override
            public int compare(F.id43 id25, F.id43 id17) {
                int value1 = id25.value;
                int value2 = id17.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id25.index;
                int index2 = id17.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static id43[] from(int[] array) {
            id43[] iip = new id43[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id43(array[i], i);
            }

            return iip;
        }

        int value, index;

        id43(int value, int index) {
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
    private id43[] id3(int size) {
        id43[] array = new id43[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id43(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id51 = 12;

        private int precision;
        private String format, id50;

        {
            precision = id51;

            format = createFormat(precision);
            id50 = format + " ";
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
            id50 = format + " ";
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

        void id45(double d){
            printf(id50, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id45(d[i]);
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

        
        private static final long id46 = -6463830523020118289L;

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
    private static Point id19(int[] array) {
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
    private static int[] id21(int n) {
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
    static int[] id49(int value) {
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
    static long[] id49(long value) {
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