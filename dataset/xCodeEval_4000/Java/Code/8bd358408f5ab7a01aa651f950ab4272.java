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
        int[] a = readIntArray(n);

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

    static int powerBlockSize;
    static long[] smallPowers, largePowers;

    static int[] rootLogs;

    static {
        primes = getPrimes(MAX_X);
        masks = new long[MAX_X + 1];

        for (int i = 0; i < primes.length; ++i) {
            int prime = primes[i];
            for (int x = prime; x <= MAX_X; x += prime) {
                masks[x] |= (1L << i);
            }
        }

        final long root = findPrimitiveRoot();

        powerBlockSize = 40 * 1000;
        smallPowers = new long[powerBlockSize + 1];
        largePowers = new long[powerBlockSize];

        smallPowers[0] = 1;
        for (int i = 1; i <= powerBlockSize; ++i) {
            smallPowers[i] = mult(smallPowers[i - 1], root);
        }

        final long blockPower = smallPowers[powerBlockSize];

        largePowers[0] = 1;
        for (int i = 1; i < powerBlockSize; ++i) {
            largePowers[i] = mult(largePowers[i - 1], blockPower);
        }

        Map<Long, Integer> smallPowerLogs = new HashMap<>();
        for (int power = 0; power < powerBlockSize; ++power) {
            smallPowerLogs.put(smallPowers[power], power);
        }

        long[] inverseLargePowers = new long[powerBlockSize];

        long inverseBlockPower = inverse(blockPower);

        inverseLargePowers[0] = 1;
        for (int i = 1; i < powerBlockSize; ++i) {
            inverseLargePowers[i] = mult(inverseLargePowers[i - 1], inverseBlockPower);
        }

        rootLogs = new int[MAX_X + 1];
        for (int x = 1; x <= MAX_X; ++x) {
            rootLogs[x] = discreteLog(x, smallPowerLogs, inverseLargePowers);
        }
    }

    static int discreteLog(long x, Map<Long, Integer> smallPowerLogs, long[] inverseLargePowers) {
        for (int block = 0; block < powerBlockSize; ++block) {
            Integer smallLog = smallPowerLogs.get(mult(x, inverseLargePowers[block]));
            if (smallLog != null) {
                return block * powerBlockSize + smallLog;
            }
        }

        return -1;
    }

    static long findPrimitiveRoot() {
        long moduloPhi = MODULO - 1;
        long[] divisors = getDivisors(moduloPhi);

        root_for:
        for (long root = 1; root < MODULO; ++root) {
            for (long divisor : divisors) {
                if (divisor != moduloPhi && binpow(root, divisor) == 1) continue root_for;
            }

            return root;
        }

        return -1;
    }

    static final int MODULO_PHI = (int)MODULO - 1;

    static int powerAdd(int a, int b) {
        return (a + b) % MODULO_PHI;
    }

    static int powerSubtract(int a, int b) {
        return powerAdd(a, MODULO_PHI - b);
    }

    static int powerMult(long a, long b) {
        return (int)((a * b) % MODULO_PHI);
    }

    long[] getAnswers(int n, int[] a, int q, Query[] queries) {
        List<Long> answers = new ArrayList<>();

        int[] primePhiLogs = new int[primes.length];
        for (int i = 0; i < primes.length; ++i) {
            int prime = primes[i];
            primePhiLogs[i] = powerSubtract(rootLogs[prime - 1], rootLogs[prime]);
        }

        final int maskSize = 16;
        final int masksCount = (1 << maskSize), maskFilter = masksCount - 1;
        final int blocksCount = Long.SIZE / maskSize;

        int[][] primePhiLogsByMasks = new int[4][1 << 16];
        for (int blockIndex = 0, blockStart = 0; blockIndex < blocksCount; ++blockIndex, blockStart += maskSize) {
            for (int mask = 0; mask < masksCount; ++mask) {
                int result = 0;
                for (int bit = 0; bit < maskSize && blockStart + bit < primePhiLogs.length; ++bit) {
                    if (checkBit(mask, bit)) {
                        result = powerAdd(result, primePhiLogs[bit + blockStart]);
                    }
                }

                primePhiLogsByMasks[blockIndex][mask] = result;
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
                    answerLog = powerAdd(answerLog, primePhiLogsByMasks[blockIndex][blockMask]);
                }

                int largeLog = answerLog / powerBlockSize;
                int smallLog = answerLog % powerBlockSize;

                long answer = mult(largePowers[largeLog], smallPowers[smallLog]);
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

            updateTreeSegment(root, 0, size);
        }

        private void updateTreeSegment(Vertex v, int left, int right) {
            if (start <= left && right <= end) {
                v.updateLazy(value);
            } else {
                int mid = (left + right) >> 1;

                v.push();

                if (start < mid) updateTreeSegment(v.left, left, mid);
                if (mid < end) updateTreeSegment(v.right, mid, right);

                v.update();
            }
        }

        Vertex result = new Vertex();

        public Vertex getSegment(int start, int end) {
            this.start = start;
            this.end = end + 1;

            this.result.clearBase();

            getTreeSegment(root, 0, size);

            return result;
        }

        private void getTreeSegment(Vertex v, int left, int right) {
            if (start <= left && right <= end) {
                result.updateFrom(v);
            } else {
                int mid = (left + right) >> 1;

                v.push();

                if (start < mid) getTreeSegment(v.left, left, mid);
                if (mid < end) getTreeSegment(v.right, mid, right);

                v.update();
            }
        }
    }

    


    private final static boolean MULTIPLE_TESTS = true;
    private final boolean ONLINE_JUDGE = !new File("input.txt").exists();



    private final static int MAX_STACK_SIZE = 128;

    private final static boolean OPTIMIZE_READ_NUMBERS = false;

    


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

            if (ONLINE_JUDGE) {
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
                } while (MULTIPLE_TESTS);
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
        new Thread(null, new F(), "", MAX_STACK_SIZE * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (ONLINE_JUDGE){
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
        if (ONLINE_JUDGE){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String readNullableLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = readNullableLine();
        if (null == line) throw new EOFException();
        return line;
    }

    private String readString() {
        while(!tok.hasMoreTokens()){
            tok = new StringTokenizer(readLine(), delim);
        }

        return tok.nextToken(delim);
    }

    


    private final char NOT_A_SYMBOL = '\0';

    @SuppressWarnings("unused")
    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return NOT_A_SYMBOL;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] readCharArray() {
        return readLine().toCharArray();
    }

    @SuppressWarnings("unused")
    private char[][] readCharField(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = readCharArray();
        }

        return field;
    }

    


    private long optimizedReadLong() {
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

        if (!OPTIMIZE_READ_NUMBERS) {
            return Integer.parseInt(readString());
        } else {
            return (int) optimizedReadLong();
        }
    }

    private int[] readIntArray(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    @SuppressWarnings("unused")
    private int[] readSortedIntArray(int size) {
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

    private int[] readIntArrayWithDecrease(int size) {
        int[] array = readIntArray(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] readIntMatrix(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = readIntArray(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] readIntMatrixWithDecrease(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = readIntArrayWithDecrease(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!OPTIMIZE_READ_NUMBERS) {
            return Long.parseLong(readString());
        } else {
            return optimizedReadLong();
        }
    }

    @SuppressWarnings("unused")
    private long[] readLongArray(int size) {
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
    private double[] readDoubleArray(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private BigInteger readBigInteger() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal readBigDecimal() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] readPointArray(int size) {
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
            addDirectedEdge(from, to);
            addDirectedEdge(to, from);
        }

        public void addDirectedEdge(int from, int to) {
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
    private final static int ZERO_INDEXATION = 0, ONE_INDEXATION = 1;

    @SuppressWarnings("unused")
    private int[][] readUnweightedGraph(int vertexNumber, int edgesNumber) {
        return readUnweightedGraph(vertexNumber, edgesNumber, ONE_INDEXATION, false);
    }

    private int[][] readUnweightedGraph(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.addDirectedEdge(from, to);
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
    private Edge[][] readWeightedGraph(int vertexNumber, int edgesNumber) {
        return readWeightedGraph(vertexNumber, edgesNumber, ONE_INDEXATION, false);
    }

    private Edge[][] readWeightedGraph(int vertexNumber, int edgesNumber,
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

    


    private static class IntIndexPair {

        @SuppressWarnings("unused")
        static Comparator<IntIndexPair> increaseComparator = new Comparator<F.IntIndexPair>() {
            @Override
            public int compare(F.IntIndexPair indexPair1, F.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return value1 - value2;

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static Comparator<IntIndexPair> decreaseComparator = new Comparator<F.IntIndexPair>() {
            @Override
            public int compare(F.IntIndexPair indexPair1, F.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static IntIndexPair[] from(int[] array) {
            IntIndexPair[] iip = new IntIndexPair[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new IntIndexPair(array[i], i);
            }

            return iip;
        }

        int value, index;

        IntIndexPair(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        @SuppressWarnings("unused")
        int getRealIndex() {
            return index + 1;
        }
    }

    @SuppressWarnings("unused")
    private IntIndexPair[] readIntIndexArray(int size) {
        IntIndexPair[] array = new IntIndexPair[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new IntIndexPair(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int DEFAULT_PRECISION = 12;

        private int precision;
        private String format, formatWithSpace;

        {
            precision = DEFAULT_PRECISION;

            format = createFormat(precision);
            formatWithSpace = format + " ";
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
            formatWithSpace = format + " ";
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

        void printWithSpace(double d){
            printf(formatWithSpace, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                printWithSpace(d[i]);
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

        
        private static final long serialVersionUID = -6463830523020118289L;

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
    private static Point getMinMax(int[] array) {
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
    private static int[] getPrimes(int n) {
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
    static int[] getDivisors(int value) {
        List<Integer> divisors = new ArrayList<>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                divisors.add(divisor);
                if (divisor * divisor != value) {
                    divisors.add(value / divisor);
                }
            }
        }

        return castInt(divisors);
    }

    @SuppressWarnings("unused")
    static long[] getDivisors(long value) {
        List<Long> divisors = new ArrayList<>();
        for (long divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                divisors.add(divisor);
                if (divisor * divisor != value) {
                    divisors.add(value / divisor);
                }
            }
        }

        return castLong(divisors);
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