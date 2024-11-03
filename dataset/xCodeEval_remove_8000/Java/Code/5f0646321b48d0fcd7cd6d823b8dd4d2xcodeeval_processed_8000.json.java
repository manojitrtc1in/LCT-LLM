import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class C implements Runnable{

    

    

    

    

    


    private final static boolean id6 = false;
    private final static boolean id9 = true;
    private final boolean id19 = !new File("input.txt").exists();



    private final static int id29 = 128;

    private final static boolean id52 = false;

    


    private final static Random rnd = new Random();
    private final static String fileName = "";
    
    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    

    private void solve() {
        long x = readInt();
        int d = readInt();

        final int MAX_N = 10 * 1000;
        for (int blocks = 1; blocks <= MAX_N; ++blocks) {
            long binSum = x + blocks;
            if (Long.bitCount(binSum) > blocks) {
                continue;
            }

            if (checkBit(binSum, 0)) continue;

            PriorityQueue<Integer> queue = new PriorityQueue<>();
            for (int bit = 0; bit < 40; ++bit) {
                if (checkBit(binSum, bit)) {
                    queue.add(bit);
                }
            }

            int oneCount = 0;
            while (oneCount + queue.size() < blocks) {
                int bit = queue.poll();
                if (bit == 1) {
                    ++oneCount;
                } else {
                    queue.add(bit - 1);
                    queue.add(bit - 1);
                }
            }

            List<Integer> blockSizes = new ArrayList<>();
            for (int i = 0; i < oneCount; ++i) blockSizes.add(1);
            while (queue.size() > 0) {
                blockSizes.add(queue.poll());
            }

            long totalSize = 0;
            for (int size : blockSizes) totalSize += size;

            if (totalSize > MAX_N) continue;

            long[] answer = new long[(int)totalSize];

            long value = 1;
            for (int i = 0, index = 0; i < blockSizes.size(); ++i) {
                int size = blockSizes.get(i);
                for (int j = 0; j < size; ++j, ++index) {
                    answer[index] = value;
                }

                value += d;
            }

            out.println(totalSize);
            out.printlnAll(answer);
            return;
        }

        out.println(-1);
    }

    


    private static long add(long a, long b) { return (a + b) % MODULO; }
    private static long subtract(long a, long b) { return add(a, MODULO - b % MODULO); }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id19) {
                solve();
            } else {
                do {
                    try {
                        timeInit();
                        solve();
                        time();

                        out.println();
                        out.flush();
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (id6) break;
                        else throw e;
                    }
                } while (id9);
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
        new Thread(null, new C(), "", id29 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id19){
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
        if (id19){
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
                tok = new StringTokenizer(readLine(), delim);
            }

            return tok.nextToken(delim);
        } catch (NullPointerException e) {
            return null;
        }
    }

    


    private final char id11 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id11;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id14() {
        return readLine().toCharArray();
    }

    private char[][] id44(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id14();
        }

        return field;
    }

    


    private long id38() {
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

        if (!id52) {
            return Integer.parseInt(readString());
        } else {
            return (int) id38();
        }
    }

    private int[] id2(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id21(int size) {
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

    private int[] id24(int size) {
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id33(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

    private int[][] id58(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id24(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id52) {
            return Long.parseLong(readString());
        } else {
            return id38();
        }
    }

    private long[] id27(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id8(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id51() {
        return new BigInteger(readString());
    }

    private BigDecimal id47() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id65(int size) {
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
            graph[index] = new ArrayList<Integer>();
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
                edges[v] = new ArrayList<Integer>();
            }

            return new GraphBuilder(edges);
        }

        private GraphBuilder(List<Integer>[] edges) {
            this.size = edges.length;
            this.edges = edges;
        }

        public void addEdge(int from, int to) {
            id48(from, to);
            id48(to, from);
        }

        public void id48(int from, int to) {
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

    private final static int id49 = 0, id26 = 1;

    private int[][] id23(int vertexNumber, int edgesNumber) {
        return id23(vertexNumber, edgesNumber, id26, false);
    }

    private int[][] id23(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id48(from, to);
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

    private Edge[][] id53(int vertexNumber, int edgesNumber) {
        return id53(vertexNumber, edgesNumber, id26, false);
    }

    private Edge[][] id53(int vertexNumber, int edgesNumber,
                                       int indexation, boolean directed) {
        @SuppressWarnings("unchecked")
        List<Edge>[] graph = new List[vertexNumber];
        for (int v = 0; v < vertexNumber; ++v) {
            graph[v] = new ArrayList<Edge>();
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

    


    private static class id57 {

        static Comparator<id57> increaseComparator = new Comparator<C.id57>() {

            @Override
            public int compare(C.id57 id40, C.id57 id28) {
                int value1 = id40.value;
                int value2 = id28.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id40.index;
                int index2 = id28.index;

                return index1 - index2;
            }
        };

        static Comparator<id57> id1 = new Comparator<C.id57>() {

            @Override
            public int compare(C.id57 id40, C.id57 id28) {
                int value1 = id40.value;
                int value2 = id28.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id40.index;
                int index2 = id28.index;

                return index1 - index2;
            }
        };

        static id57[] from(int[] array) {
            id57[] iip = new id57[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id57(array[i], i);
            }

            return iip;
        }

        int value, index;

        id57(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id10() {
            return index + 1;
        }
    }

    private id57[] id7(int size) {
        id57[] array = new id57[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id57(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id72 = 12;

        private int precision;
        private String format, id70;

        {
            precision = id72;

            format = createFormat(precision);
            id70 = format + " ";
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
            id70 = format + " ";
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

        void id60(double d){
            printf(id70, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id60(d[i]);
            }

            print(d[d.length - 1]);
        }

        void printlnAll(double... d){
            printAll(d);
            println();
        }
        
        void printAll(int... array) {
        	for (int value : array) {
        		print(value + " ");
        	}
        }
        
        void printlnAll(int... array) {
        	printAll(array);
        	println();
        }
        
        void printAll(long... array) {
        	for (long value : array) {
        		print(value + " ");
        	}
        }
        
        void printlnAll(long... array) {
        	printAll(array);
        	println();
        }
    }

    


    private static class RuntimeIOException extends RuntimeException {

        
        private static final long id61 = -6463830523020118289L;

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

    


    private static int getBit(long mask, int bit) { return (int)((mask >> bit) & 1); }
    private static boolean checkBit(long mask, int bit){
        return getBit(mask, bit) != 0;
    }

    


    private static long getSum(int[] array) {
        long sum = 0;
        for (int value: array) {
            sum += value;
        }

        return sum;
    }

    private static Point id32(int[] array) {
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

    


    private static boolean isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) return false;
        }

        return true;
    }
    private static int[] id35(int n) {
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

    


    int[] id66(int value) {
        List<Integer> id0 = new ArrayList<Integer>();
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

    


    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }




    private interface MultiSet<ValueType> {

        int size();

        void inc(ValueType value);
        boolean dec(ValueType value);

        int count(ValueType value);
    }

    private static abstract class id34
            <ValueType, MapType extends Map<ValueType, Integer>>
            implements MultiSet<ValueType> {

        protected final MapType map;
        protected int size;

        protected id34(MapType map) {
            this.map = map;
            this.size = 0;
        }

        public int size() {
            return size;
        }

        public void inc(ValueType value) {
            int count = count(value);
            map.put(value, count + 1);

            ++size;
        }

        public boolean dec(ValueType value) {
            int count = count(value);
            if (count == 0) return false;

            if (count == 1) map.remove(value);
            else map.put(value, count - 1);

            --size;
            return true;
        }

        public int count(ValueType value) {
            Integer count = map.get(value);
            return (count == null ? 0 : count);
        }
    }

    private static class id59<ValueType>
            extends id34<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> id67() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new id59<ValueType>(map);
        }

        id59(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private interface id41<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class id25<ValueType>
            extends id34<ValueType, NavigableMap<ValueType, Integer>>
            implements id41<ValueType> {

        id25(NavigableMap<ValueType, Integer> map) {
            super(map);
        }

        @Override
        public ValueType min() {
            return (size == 0 ? null : map.firstKey());
        }

        @Override
        public ValueType max() {
            return (size == 0 ? null : map.lastKey());
        }

        @Override
        public ValueType pollMin() {
            ValueType first = min();
            if (first != null) dec(first);
            return first;
        }

        @Override
        public ValueType pollMax() {
            ValueType last = max();
            dec(last);
            return last;
        }

        @Override
        public ValueType lower(ValueType value) {
            return map.lowerKey(value);
        }

        @Override
        public ValueType floor(ValueType value) {
            return map.floorKey(value);
        }

        @Override
        public ValueType ceiling(ValueType value) {
            return map.ceilingKey(value);
        }

        @Override
        public ValueType higher(ValueType value) {
            return map.higherKey(value);
        }
    }

    private static class id73<ValueType>
            extends id25<ValueType> {

        public static <ValueType> id41<ValueType> id67() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new id73<ValueType>(map);
        }

        id73(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id61 = -3793737771950984481L;

        public IdMap() {
            super();
        }

        int register(KeyType key) {
            Integer id = super.get(key);
            if (id == null) {
                super.put(key, id = size());
            }

            return id;
        }

        int getId(KeyType key) {
            return get(key);
        }
    }

    


    private static class id39<ValueType extends Comparable<ValueType>> {

        private List<ValueType> values;

        public id39() {
            this.values = new ArrayList<ValueType>();
        }

        void addValue(ValueType value) {
            values.add(value);
        }

        IdMap<ValueType> build() {
            Collections.sort(values);

            IdMap<ValueType> ids = new IdMap<ValueType>();
            List<ValueType> uniqueValues = new ArrayList<ValueType>();

            for (int index = 0; index < values.size(); ++index) {
                ValueType value = values.get(index);
                if (index == 0 || values.get(index - 1).compareTo(value) != 0) {
                    ids.register(value);
                    uniqueValues.add(value);
                }
            }
            
            values = uniqueValues;

            return ids;
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

    


    
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }

    


    interface Rmq {
        int getMin(int left, int right);
        int id16(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id36;
        int[][] table;

        int id20(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id36 = new int[n + 1];
            id36[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id36[i] = id36[i - 1];
                int length = (1 << id36[i]);
                if (length + length <= i) ++id36[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = id20(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id16(int left, int right) {
            int length = (right - left + 1);

            int bit = id36[length];
            int segmentLength = (1 << bit);

            return id20(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id16(left, right)];
        }
    }

    private static Rmq id62(int[] array) {
        return new SparseTable(array).build();
    }

    


    interface Lca {
        Lca build(int root);
        int lca(int a, int b);

        int height(int v);
    }

    private static class id31 implements Lca {

        int n;
        int[][] graph;

        id31(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;

        int[] order;
        int[] heights;
        int[] first;

        Rmq rmq;

        @Override
        public id31 build(int root) {
            this.order = new int[n + n];
            this.heights = new int[n];

            this.first = new int[n];
            Arrays.fill(first, -1);

            this.time = 0;
            dfs(root, 0);

            int[] id68 = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                id68[i] = heights[order[i]];
            }

            this.rmq = id62(id68);
            return this;
        }

        void dfs(int from, int height) {
            first[from] = time;
            order[time] = from;
            heights[from] = height;
            ++time;

            for (int to : graph[from]) {
                if (first[to] == -1) {
                    dfs(to, height + 1);

                    order[time] = from;
                    ++time;
                }
            }
        }

        @Override
        public int lca(int a, int b) {
            int aFirst = first[a], bFirst = first[b];
            int left = min(aFirst, bFirst), right = max(aFirst, bFirst);

            int orderIndex = rmq.id16(left, right);
            return order[orderIndex];
        }

        @Override
        public int height(int v) {
            return heights[v];
        }
    }

    private static class id43 implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        id43(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        @Override
        public Lca build(int root) {
            this.h = new int[n];

            this.parents = new int[MAX_BIT][n];
            Arrays.fill(parents[0], -1);

            Queue<Integer> queue = new ArrayDeque<Integer>();

            queue.add(root);
            add(root, root);

            while (queue.size() > 0) {
                int from = queue.poll();
                for (int to : graph[from]) {
                    if (parents[0][to] == -1) {
                        add(from, to);
                        queue.add(to);
                    }
                }
            }

            return this;
        }

        void add(int parent, int v) {
            h[v] = h[parent] + 1;
            parents[0][v] = parent;
            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                parents[bit + 1][v] = parents[bit][parents[bit][v]];
            }
        }

        @Override
        public int lca(int a, int b) {
            if (h[a] < h[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            int delta = h[a] - h[b];
            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                if (delta >= (1 << bit)) {
                    delta -= (1 << bit);
                    a = parents[bit][a];
                }
            }

            if (a == b) return a;

            for (int bit = MAX_BIT - 1; bit >= 0; --bit) {
                int nextA = parents[bit][a], nextB = parents[bit][b];
                if (nextA != nextB) {
                    a = nextA;
                    b = nextB;
                }
            }

            return parents[0][a];
        }

        @Override
        public int height(int v) {
            return h[v];
        }
    }

    private static Lca id55(int[][] graph, int root) {
        return new id31(graph).build(root);
    }

    


    private static class id75 {

        int n;
        int[][] graph;

        id75(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        id75 build() {
            calculateTimes();
            id42();

            return this;
        }

        void calculateTimes() {
            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            this.used = new boolean[n];
            id3(0, -1);
        }

        void id3(int from, int parent) {
            used[from] = true;

            up[from] = tin[from] = time;
            ++time;

            for (int to : graph[from]) {
                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    id3(to, from);
                    up[from] = min(up[from], up[to]);
                }
            }
        }

        int[] components;
        int[][] componentsGraph;

        int component(int v) { return components[v]; }

        int[][] toGraph() {
            return componentsGraph;
        }

        void id42() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    id64(v, v);
                }
            }

            GraphBuilder graphBuilder = GraphBuilder.createInstance(n);

            Set<Point> edges = new HashSet<Point>();
            for (int from = 0; from < n; ++from) {
                int fromComponent = components[from];

                for (int to : graph[from]) {
                    int toComponent = components[to];
                    if (fromComponent == toComponent) continue;

                    Point edge = new Point(fromComponent, toComponent);
                    if (edges.add(edge)) graphBuilder.id48(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void id64(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    id64(to, color);
                }
            }
        }
    }

    


    private static class id22 {

        static class Edge {
            int to;
            int index;

            Edge(int to, int index) {
                this.to = to;
                this.index = index;
            }
        }

        int n, m;
        List<Edge>[] graph;
        List<Edge> edges;

        id22(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge id76 = new Edge(to, m);
            Edge id45 = new Edge(from, m + 1);

            edges.add(id76);
            edges.add(id45);

            graph[from].add(id76);
            graph[to].add(id45);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] id13;

        boolean[] id4() {
            this.id13 = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    id15(v, -1);
                }
            }

            return id13;
        }

        void id15(int from, int parent) {
            used[from] = true;
            parents[from] = parent;

            ++time;
            up[from] = tin[from] = time;

            int childrenCount = 0;

            for (Edge e : graph[from]) {
                int to = e.to;

                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    ++childrenCount;

                    id15(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        id13[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                id13[from] = true;
            }
        }

        int[] edgeColors;
        int id54;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.id54 = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++id54;
                    id74(v, id54, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void id74(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++id54;
                        paintEdge(e.index, newColor);
                        id74(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        id74(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] id30() {
            Set<Integer>[] id69 = new Set[n];
            for (int v = 0; v < n; ++v) {
                id69[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    id69[v].add(edgeColors[e.index]);
                }
            }

            return id69;
        }

        id22 build() {
            id4();
            paintEdges();
            id5();

            return this;
        }

        int[][] componentsGraph;

        void id5() {
            Set<Integer>[] id69 = id30();

            int id12 = id69.length;
            int size = id69.length + id54 + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < id69.length; ++v) {
                for (int edgeColor : id69[v]) {
                    graphBuilder.addEdge(v, edgeColor + id12);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        int[][] toGraph() {
            return componentsGraph;
        }
    }

    


    private static class DSU {

        int[] sizes;

        int[] ranks;
        int[] parents;

        static DSU createInstance(int size) {
            int[] sizes = new int[size];
            Arrays.fill(sizes, 1);

            return new DSU(sizes);
        }

        DSU(int[] sizes) {
            this.sizes = sizes;

            int size = sizes.length;

            this.ranks = new int[size];
            Arrays.fill(ranks, 1);

            this.parents = castInt(order(size));
        }

        int get(int v) {
            if (v == parents[v]) return v;
            return parents[v] = get(parents[v]);
        }

        boolean union(int a, int b) {
            a = get(a);
            b = get(b);

            if (a == b) return false;

            if (ranks[a] < ranks[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }

            parents[b] = a;
            sizes[a] += sizes[b];

            if (ranks[a] == ranks[b]) ++ranks[a];

            return true;
        }
    }

    

    
    static abstract class SegmentTree {
    	
    	int size;
    	boolean lazySupported; 
    	
    	boolean[] lazy;
    	long[] values;
    	
    	long[] tree;
    	
    	SegmentTree(int n, boolean lazySupported) {
    		this.size = n;
    		this.lazySupported = lazySupported;
    		
    		int treeSize = size << 2;
    		
    		this.tree = new long[treeSize];
    		
    		if (lazySupported) {
        		this.lazy = new boolean[treeSize];
        		this.values = new long[treeSize];	
    		}
    	}
    	
    	SegmentTree(int[] a, boolean lazySupported) {
    		this(a.length, lazySupported);
    	}
    	
    	abstract void updateValue(int v, int left, int right, long value);
    	
    	void id63(int v, long value) {
    		throw new UnsupportedOperationException();
    	}
    	
    	void pushVertex(int v, int vLeft, int vRight) {
    		if (lazy[v]) {
    			id63(vLeft, values[v]);
    			id63(vRight, values[v]);
    			
    			lazy[v] = false;
    			values[v] = 0;
    		}
    	}
    	
    	abstract void updateVertex(int v, int vLeft, int vRight);
    	
    	int[] a;
    	void buildTree(int[] a) {
    		this.a = a;
    		
    		buildTree(1, 0, size - 1);
    	}
    	
    	void buildTree(int v, int left, int right) {
    		if (left == right) {
    			updateValue(v, left, right, a[left]);
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			buildTree(vLeft, left, mid);
    			buildTree(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	long value;
    	
    	int index;
    	void updateIndex(int index, long value) {
    		this.index = index;
    		this.value = value;
    		
    		id71(1, 0, size - 1);
    	}
    	
    	void id71(int v, int left, int right) {
    		if (left == right) {
    			updateValue(v, left, right, value);
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			if (index <= mid) id71(vLeft, left, mid);
    			else id71(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int start, end;
    	void updateSegment(int start, int end, long value) {
    		this.start = start;
    		this.end = end;
    		this.value = value;
    		
    		id56(1, 0, size - 1);
    	}
    	
    	void id56(int v, int left, int right) {
    		if (start <= left && right <= end) {
    			if (lazySupported) {
    				id63(v, value);
    			} else {
    				updateValue(v, left, right, value);
    			}
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			if (lazySupported) pushVertex(v, vLeft, vRight);
    			
    			if (start <= mid) id56(vLeft, left, mid);
    			if (mid < end) id56(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	abstract void initResult(long... id17);
    	
    	abstract void id46(int v, int left, int right);
    	
    	void getIndex(int index, long... id17) {
    		this.index = index;
    		
    		initResult(id17);
    		
    		id37(1, 0, size - 1);
    	}
    	
    	void id37(int v, int left, int right) {
    		if (lazySupported) {
    			if (left == right) {
    				id46(v, left, right);
    			} else {
    				int mid = (left + right) >> 1;
    				int vLeft = (v << 1), vRight = (vLeft + 1);
    				
    				pushVertex(v, vLeft, vRight);
    				
    				if (index <= mid) id37(vLeft, left, mid);
    				else id37(vRight, mid + 1, right);
    				
    				updateVertex(v, vLeft, vRight);	
    			}
    		} else {
    			while (left <= right) {
        			id46(v, left, right);
        			
        			if (left == right) break;
        			
    				int mid = (left + right) >> 1;
    				int vLeft = (v << 1), vRight = (vLeft + 1);
    				
        			if (index <= mid) {
        				v = vLeft;
        				right = mid;
        			} else {
        				v = vRight;
        				left = mid + 1;
        			}
    			}
    		}
    	}
    	
    	void getSegment(int start, int end, long... id17) {
    		this.start = start;
    		this.end = end;
    		
    		initResult(id17);
    		
    		id18(1, 0, size - 1);
    	}
    	
    	void id18(int v, int left, int right) {
    		if (start <= left && right <= end) {
    			id46(v, left, right);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				if (start <= mid) id18(vLeft, left, mid);
				if (mid < end) id18(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int[] toArray() {
    		this.a = new int[size];
    		
    		id50(1, 0, size - 1);
    		
    		return a;
    	}
    	
    	void id50(int v, int left, int right) {
    		if (left == right) {
    			a[left] = (int)(tree[v]);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				id50(vLeft, left, mid);
				id50(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    }
    
    

}