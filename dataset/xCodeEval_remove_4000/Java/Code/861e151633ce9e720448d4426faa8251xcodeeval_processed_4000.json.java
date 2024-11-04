import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class E implements Runnable{

    

    

    

    

    


    private final static boolean id7 = false;
    private final static boolean id10 = true;
    private final boolean id20 = !new File("input.txt").exists();



    private final static int id32 = 128;

    private final static boolean id57 = false;

    


    private final static Random rnd = new Random();
    private final static String fileName = "";
    
    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    int[][] graph;
    long[] values;

    long answer;

    int[] id28;
    int[] id61;

    

    private void solve() {
        int n = readInt();
        this.values = id30(n);
        for (int v = 0; v < n; ++v) {
            values[v] %= MODULO;
            if (values[v] < 0) values[v] += MODULO;
        }

        this.graph = id24(n, n - 1);

        int root = 0;

        this.id28 = new int[n];
        this.id61 = new int[n];

        id71(root, -1);

        answer = 0;

        dfsAnswer(root, -1, 0, 0);

        out.println(answer);
    }

    void dfsAnswer(int from, int parent, int id46, int id5) {
        int id85 = id61[from];
        int id86 = id28[from];

        for (int to : graph[from]) {
            if (to == parent) continue;

            dfsAnswer(to, from, id5 + id86 - id61[to], id46 + id85 - id28[to]);
        }

        long value = values[from];

        answer = add(
                answer,
                mult(value,
                    mult(id85, id46 + id5)
                )
        );

        answer = subtract(
                answer,
                mult(value,
                    mult(id86, id46 + id5)
                )
        );

        answer = add(
                answer,
                mult(value,
                        mult(id46, id85 + id86)
                )
        );

        answer = subtract(
                answer,
                mult(value,
                        mult(id5, id85 + id86)
                )
        );

        answer = add(answer, value);

        for (int to : graph[from]) {
            if (to == parent) continue;

            int id62 = id28[to];
            int id44 = id61[to];

            int id60 = id85 - id62;
            int id27 = id86 - id44;

            answer = add(
                    answer,
                    mult(value,
                            mult(id62, id60 + id27)
                    )
            );

            answer = subtract(
                    answer,
                    mult(value,
                            mult(id44, id60 + id27))
            );

            answer = add(
                    answer,
                    mult(value, id62 + id44)
            );

























        }
    }

    void id71(int from, int parent) {
        id61[from] = 1;
        id28[from]  = 0;

        for (int to : graph[from]) {
            if (to == parent) continue;

            id71(to, from);

            id61[from] += id28[to];
            id28[from] += id61[to];
        }
    }

    


    private static long add(long a, long b) { return (a + b) % MODULO; }
    private static long subtract(long a, long b) { return add(a, MODULO - b % MODULO); }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id20) {
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
                        if (id7) break;
                        else throw e;
                    }
                } while (id10);
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
        new Thread(null, new E(), "", id32 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id20){
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
        if (id20){
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

    


    private final char id12 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id12;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id15() {
        return readLine().toCharArray();
    }

    private char[][] id49(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id15();
        }

        return field;
    }

    


    private long id41() {
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

        if (!id57) {
            return Integer.parseInt(readString());
        } else {
            return (int) id41();
        }
    }

    private int[] id2(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id22(int size) {
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

    private int[] id25(int size) {
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id36(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

    private int[][] id66(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id25(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id57) {
            return Long.parseLong(readString());
        } else {
            return id41();
        }
    }

    private long[] id30(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id9(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id56() {
        return new BigInteger(readString());
    }

    private BigDecimal id52() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id74(int size) {
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
            id53(from, to);
            id53(to, from);
        }

        public void id53(int from, int to) {
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

    private final static int id54 = 0, id29 = 1;

    private int[][] id24(int vertexNumber, int edgesNumber) {
        return id24(vertexNumber, edgesNumber, id29, false);
    }

    private int[][] id24(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id53(from, to);
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

    private Edge[][] id58(int vertexNumber, int edgesNumber) {
        return id58(vertexNumber, edgesNumber, id29, false);
    }

    private Edge[][] id58(int vertexNumber, int edgesNumber,
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

    


    private static class id65 {

        static Comparator<id65> increaseComparator = new Comparator<E.id65>() {

            @Override
            public int compare(E.id65 id43, E.id65 id31) {
                int value1 = id43.value;
                int value2 = id31.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id43.index;
                int index2 = id31.index;

                return index1 - index2;
            }
        };

        static Comparator<id65> id1 = new Comparator<E.id65>() {

            @Override
            public int compare(E.id65 id43, E.id65 id31) {
                int value1 = id43.value;
                int value2 = id31.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id43.index;
                int index2 = id31.index;

                return index1 - index2;
            }
        };

        static id65[] from(int[] array) {
            id65[] iip = new id65[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id65(array[i], i);
            }

            return iip;
        }

        int value, index;

        id65(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id11() {
            return index + 1;
        }
    }

    private id65[] id8(int size) {
        id65[] array = new id65[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id65(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id81 = 12;

        private int precision;
        private String format, id79;

        {
            precision = id81;

            format = createFormat(precision);
            id79 = format + " ";
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
            id79 = format + " ";
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

        void id68(double d){
            printf(id79, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id68(d[i]);
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

        
        private static final long id69 = -6463830523020118289L;

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

    private static Point id35(int[] array) {
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
    private static int[] id38(int n) {
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

    


    int[] id75(int value) {
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

    private static abstract class id37
            <ValueType, MapType extends Map<ValueType, Integer>>
            implements MultiSet<ValueType> {

        protected final MapType map;
        protected int size;

        protected id37(MapType map) {
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

    private static class id67<ValueType>
            extends id37<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> id76() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new id67<ValueType>(map);
        }

        id67(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private interface id45<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class id26<ValueType>
            extends id37<ValueType, NavigableMap<ValueType, Integer>>
            implements id45<ValueType> {

        id26(NavigableMap<ValueType, Integer> map) {
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

    private static class id82<ValueType>
            extends id26<ValueType> {

        public static <ValueType> id45<ValueType> id76() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new id82<ValueType>(map);
        }

        id82(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id69 = -3793737771950984481L;

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

    


    private static class id42<ValueType extends Comparable<ValueType>> {

        private List<ValueType> values;

        public id42() {
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
        int id17(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id39;
        int[][] table;

        int id21(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id39 = new int[n + 1];
            id39[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id39[i] = id39[i - 1];
                int length = (1 << id39[i]);
                if (length + length <= i) ++id39[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = id21(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id17(int left, int right) {
            int length = (right - left + 1);

            int bit = id39[length];
            int segmentLength = (1 << bit);

            return id21(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id17(left, right)];
        }
    }

    private static Rmq id70(int[] array) {
        return new SparseTable(array).build();
    }

    


    interface Lca {
        Lca build(int root);
        int lca(int a, int b);

        int height(int v);
    }

    private static class id34 implements Lca {

        int n;
        int[][] graph;

        id34(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;

        int[] order;
        int[] heights;
        int[] first;

        Rmq rmq;

        @Override
        public id34 build(int root) {
            this.order = new int[n + n];
            this.heights = new int[n];

            this.first = new int[n];
            Arrays.fill(first, -1);

            this.time = 0;
            dfs(root, 0);

            int[] id77 = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                id77[i] = heights[order[i]];
            }

            this.rmq = id70(id77);
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

            int orderIndex = rmq.id17(left, right);
            return order[orderIndex];
        }

        @Override
        public int height(int v) {
            return heights[v];
        }
    }

    private static class id48 implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        id48(int[][] graph) {
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

    private static Lca id63(int[][] graph, int root) {
        return new id34(graph).build(root);
    }

    


    private static class id84 {

        int n;
        int[][] graph;

        id84(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        id84 build() {
            calculateTimes();
            id47();

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

        void id47() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    id73(v, v);
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
                    if (edges.add(edge)) graphBuilder.id53(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void id73(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    id73(to, color);
                }
            }
        }
    }

    


    private static class id23 {

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

        id23(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge id87 = new Edge(to, m);
            Edge id50 = new Edge(from, m + 1);

            edges.add(id87);
            edges.add(id50);

            graph[from].add(id87);
            graph[to].add(id50);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] id14;

        boolean[] id4() {
            this.id14 = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    id16(v, -1);
                }
            }

            return id14;
        }

        void id16(int from, int parent) {
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

                    id16(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        id14[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                id14[from] = true;
            }
        }

        int[] edgeColors;
        int id59;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.id59 = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++id59;
                    id83(v, id59, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void id83(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++id59;
                        paintEdge(e.index, newColor);
                        id83(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        id83(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] id33() {
            Set<Integer>[] id78 = new Set[n];
            for (int v = 0; v < n; ++v) {
                id78[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    id78[v].add(edgeColors[e.index]);
                }
            }

            return id78;
        }

        id23 build() {
            id4();
            paintEdges();
            id6();

            return this;
        }

        int[][] componentsGraph;

        void id6() {
            Set<Integer>[] id78 = id33();

            int id13 = id78.length;
            int size = id78.length + id59 + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < id78.length; ++v) {
                for (int edgeColor : id78[v]) {
                    graphBuilder.addEdge(v, edgeColor + id13);
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
    	
    	void id72(int v, long value) {
    		throw new UnsupportedOperationException();
    	}
    	
    	void pushVertex(int v, int vLeft, int vRight) {
    		if (lazy[v]) {
    			id72(vLeft, values[v]);
    			id72(vRight, values[v]);
    			
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
    		
    		id80(1, 0, size - 1);
    	}
    	
    	void id80(int v, int left, int right) {
    		if (left == right) {
    			updateValue(v, left, right, value);
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			if (index <= mid) id80(vLeft, left, mid);
    			else id80(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int start, end;
    	void updateSegment(int start, int end, long value) {
    		this.start = start;
    		this.end = end;
    		this.value = value;
    		
    		id64(1, 0, size - 1);
    	}
    	
    	void id64(int v, int left, int right) {
    		if (start <= left && right <= end) {
    			if (lazySupported) {
    				id72(v, value);
    			} else {
    				updateValue(v, left, right, value);
    			}
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			if (lazySupported) pushVertex(v, vLeft, vRight);
    			
    			if (start <= mid) id64(vLeft, left, mid);
    			if (mid < end) id64(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	abstract void initResult(long... id18);
    	
    	abstract void id51(int v, int left, int right);
    	
    	void getIndex(int index, long... id18) {
    		this.index = index;
    		
    		initResult(id18);
    		
    		id40(1, 0, size - 1);
    	}
    	
    	void id40(int v, int left, int right) {
    		if (lazySupported) {
    			if (left == right) {
    				id51(v, left, right);
    			} else {
    				int mid = (left + right) >> 1;
    				int vLeft = (v << 1), vRight = (vLeft + 1);
    				
    				pushVertex(v, vLeft, vRight);
    				
    				if (index <= mid) id40(vLeft, left, mid);
    				else id40(vRight, mid + 1, right);
    				
    				updateVertex(v, vLeft, vRight);	
    			}
    		} else {
    			while (left <= right) {
        			id51(v, left, right);
        			
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
    	
    	void getSegment(int start, int end, long... id18) {
    		this.start = start;
    		this.end = end;
    		
    		initResult(id18);
    		
    		id19(1, 0, size - 1);
    	}
    	
    	void id19(int v, int left, int right) {
    		if (start <= left && right <= end) {
    			id51(v, left, right);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				if (start <= mid) id19(vLeft, left, mid);
				if (mid < end) id19(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int[] toArray() {
    		this.a = new int[size];
    		
    		id55(1, 0, size - 1);
    		
    		return a;
    	}
    	
    	void id55(int v, int left, int right) {
    		if (left == right) {
    			a[left] = (int)(tree[v]);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				id55(vLeft, left, mid);
				id55(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    }
    
    

}