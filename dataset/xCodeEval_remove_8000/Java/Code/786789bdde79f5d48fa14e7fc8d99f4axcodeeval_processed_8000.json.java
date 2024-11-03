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

    

    

    

    

    


    private final static boolean id47 = false;
    private final static boolean id3 = true;
    private final boolean id35 = !new File("input.txt").exists();



    private final static int id73 = 128;

    private final static boolean id17 = false;

    


    private final static Random rnd = new Random();
    private final static String fileName = "";
    
    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    

    private void solve() {
        int n = readInt(), m = readInt();
        int[] a = id1(n);

        int[][] id66 = new int[n][];
        for (int i = 0; i < n; ++i) {
            List<Integer> id10 = new ArrayList<>();

            int value = a[i];
            for (int d = 2; d * d <= value; ++d) {
                while (value % d == 0) {
                    id10.add(d);
                    value /= d;
                }
            }

            if (value > 1) {
                id10.add(value);
            }

            id66[i] = castInt(id10);
        }

        int[] prefixSizes = new int[n];
        for (int i = 2; i < n; ++i) {
            prefixSizes[i] = prefixSizes[i - 2] + id66[i - 2].length;
        }

        

        int last = n - 1, lastFirst = last - last % 2, lastSecond = (last == lastFirst ? last - 1 : last);

        int firstSize = prefixSizes[lastFirst] + id66[lastFirst].length;
        int secondSize = prefixSizes[lastSecond] + id66[lastSecond].length;

        GraphBuilder graphBuilder = GraphBuilder.createInstance(firstSize);

        for (int i = 0; i < m; ++i) {
            int from = readInt() - 1, to = readInt() - 1;
            if (from % 2 == 1) {
                int tmp = from;
                from = to;
                to = tmp;
            }

            int[] id40 = id66[from];
            int fromShift = prefixSizes[from];

            int[] id79 = id66[to];
            int toShift = prefixSizes[to];

            for (int fromIndex = 0, fromV = fromShift; fromIndex < id40.length; ++fromIndex, ++fromV) {
                int id21 = id40[fromIndex];
                for (int toIndex = 0, toV = toShift; toIndex < id79.length; ++toIndex, ++toV) {
                    int id42 = id79[toIndex];

                    if (id21 == id42) {
                        graphBuilder.id60(fromV, toV);
                    }
                }
            }
        }

        Khun khun = new Khun(graphBuilder.build(), secondSize);

        int answer = khun.process();
        out.println(answer);
    }

    static class Khun {

        int[][] graph;
        int[] used;

        int[] matchedFirst;

        Khun(int[][] graph, int secondSize) {
            this.graph = graph;
            this.matchedFirst = new int[secondSize];
            this.used = new int[graph.length];
        }

        int process() {
            Arrays.fill(used, -1);
            Arrays.fill(matchedFirst, -1);

            int size = 0;
            for (int v = 0; v < graph.length; ++v) {
                if (dfs(v, v)) {
                    ++size;
                }
            }

            return size;
        }

        boolean dfs(int from, int color) {
            if (used[from] == color) return false;
            used[from] = color;

            for (int to : graph[from]) {
                if (matchedFirst[to] == -1) {
                    matchedFirst[to] = from;
                    return true;
                }
            }

            for (int to : graph[from]) {
                if (dfs(matchedFirst[to], color)) {
                    matchedFirst[to] = from;
                    return true;
                }
            }

            return false;
        }
    }

    


    long inverse(long x) {
        return binpow(x, MODULO - 2);
    }

    long binpow(long base, long power) {
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
    private static long subtract(long a, long b) { return add(a, MODULO - b % MODULO); }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    void yesNo(boolean yes) {
        out.println(yes ? "YES" : "NO");
    }

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id35) {
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
                        if (id47) break;
                        else throw e;
                    }
                } while (id3);
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
        new Thread(null, new C(), "", id73 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id35){
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
        if (id35){
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

    


    private final char id69 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id69;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id5() {
        return readLine().toCharArray();
    }

    private char[][] id80(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id5();
        }

        return field;
    }

    


    private long id13() {
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

        if (!id17) {
            return Integer.parseInt(readString());
        } else {
            return (int) id13();
        }
    }

    private int[] id1(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id7(int size) {
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

    private int[] id53(int size) {
        int[] array = id1(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id12(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id1(columnsCount);
        }

        return matrix;
    }

    private int[][] id63(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id53(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id17) {
            return Long.parseLong(readString());
        } else {
            return id13();
        }
    }

    private long[] id9(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id48(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id16() {
        return new BigInteger(readString());
    }

    private BigDecimal id59() {
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
            id60(from, to);
            id60(to, from);
        }

        public void id60(int from, int to) {
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

    private final static int id41 = 0, id71 = 1;

    private int[][] id8(int vertexNumber, int edgesNumber) {
        return id8(vertexNumber, edgesNumber, id71, false);
    }

    private int[][] id8(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id60(from, to);
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

    private Edge[][] id18(int vertexNumber, int edgesNumber) {
        return id18(vertexNumber, edgesNumber, id71, false);
    }

    private Edge[][] id18(int vertexNumber, int edgesNumber,
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

    


    private static class id43 {

        static Comparator<id43> increaseComparator = new Comparator<C.id43>() {

            @Override
            public int compare(C.id43 id56, C.id43 id72) {
                int value1 = id56.value;
                int value2 = id72.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id56.index;
                int index2 = id72.index;

                return index1 - index2;
            }
        };

        static Comparator<id43> id29 = new Comparator<C.id43>() {

            @Override
            public int compare(C.id43 id56, C.id43 id72) {
                int value1 = id56.value;
                int value2 = id72.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id56.index;
                int index2 = id72.index;

                return index1 - index2;
            }
        };

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

        int id49() {
            return index + 1;
        }
    }

    private id43[] id31(int size) {
        id43[] array = new id43[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id43(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id86 = 12;

        private int precision;
        private String format, id85;

        {
            precision = id86;

            format = createFormat(precision);
            id85 = format + " ";
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
            id85 = format + " ";
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

        void id82(double d){
            printf(id85, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id82(d[i]);
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

        
        private static final long id64 = -6463830523020118289L;

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

    private static Point id74(int[] array) {
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
    private static int[] id55(int n) {
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

    


    int[] id23(int value) {
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

    private static class id20<ValueType>
            extends id37<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> id24() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new id20<ValueType>(map);
        }

        id20(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private interface id39<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class id70<ValueType>
            extends id37<ValueType, NavigableMap<ValueType, Integer>>
            implements id39<ValueType> {

        id70(NavigableMap<ValueType, Integer> map) {
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

    private static class id26<ValueType>
            extends id70<ValueType> {

        public static <ValueType> id39<ValueType> id24() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new id26<ValueType>(map);
        }

        public static <ValueType> id39<ValueType> id24(Comparator<ValueType> comparator) {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>(comparator);
            return new id26<ValueType>(map);
        }

        id26(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id64 = -3793737771950984481L;

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

    


    private static class id77<ValueType extends Comparable<ValueType>> {

        private List<ValueType> values;

        public id77() {
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
        int id6(int left, int right);
    }

    private static class SparseTable implements Rmq {

        private static final int MAX_BIT = 20;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id76;
        int[][] table;

        int id51(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id76 = new int[n + 1];
            id76[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id76[i] = id76[i - 1];
                int length = (1 << id76[i]);
                if (length + length <= i) ++id76[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = id51(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id6(int left, int right) {
            int length = (right - left + 1);

            int bit = id76[length];
            int segmentLength = (1 << bit);

            return id51(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id6(left, right)];
        }
    }

    private static Rmq id83(int[] array) {
        return new SparseTable(array).build();
    }

    


    interface Lca {
        Lca build(int root);
        int lca(int a, int b);

        int height(int v);
    }

    private static class id11 implements Lca {

        int n;
        int[][] graph;

        id11(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;

        int[] order;
        int[] heights;
        int[] first;

        Rmq rmq;

        @Override
        public id11 build(int root) {
            this.order = new int[n + n];
            this.heights = new int[n];

            this.first = new int[n];
            Arrays.fill(first, -1);

            this.time = 0;
            dfs(root, 0);

            int[] id25 = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                id25[i] = heights[order[i]];
            }

            this.rmq = id83(id25);
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

            int orderIndex = rmq.id6(left, right);
            return order[orderIndex];
        }

        @Override
        public int height(int v) {
            return heights[v];
        }
    }

    private static class id57 implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        id57(int[][] graph) {
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

    private static Lca id19(int[][] graph, int root) {
        return new id11(graph).build(root);
    }

    


    private static class id67 {

        int n;
        int[][] graph;

        id67(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        id67 build() {
            calculateTimes();
            id78();

            return this;
        }

        void calculateTimes() {
            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            this.used = new boolean[n];
            id68(0, -1);
        }

        void id68(int from, int parent) {
            used[from] = true;

            up[from] = tin[from] = time;
            ++time;

            for (int to : graph[from]) {
                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    id68(to, from);
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

        void id78() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    id45(v, v);
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
                    if (edges.add(edge)) graphBuilder.id60(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void id45(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    id45(to, color);
                }
            }
        }
    }

    


    private static class id36 {

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

        id36(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge id28 = new Edge(to, m);
            Edge id58 = new Edge(from, m + 1);

            edges.add(id28);
            edges.add(id58);

            graph[from].add(id28);
            graph[to].add(id58);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] id32;

        boolean[] id30() {
            this.id32 = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    id50(v, -1);
                }
            }

            return id32;
        }

        void id50(int from, int parent) {
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

                    id50(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        id32[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                id32[from] = true;
            }
        }

        int[] edgeColors;
        int id81;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.id81 = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++id81;
                    id27(v, id81, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void id27(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++id81;
                        paintEdge(e.index, newColor);
                        id27(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        id27(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] id54() {
            Set<Integer>[] id84 = new Set[n];
            for (int v = 0; v < n; ++v) {
                id84[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    id84[v].add(edgeColors[e.index]);
                }
            }

            return id84;
        }

        id36 build() {
            id30();
            paintEdges();
            id2();

            return this;
        }

        int[][] componentsGraph;

        void id2() {
            Set<Integer>[] id84 = id54();

            int id4 = id84.length;
            int size = id84.length + id81 + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < id84.length; ++v) {
                for (int edgeColor : id84[v]) {
                    graphBuilder.addEdge(v, edgeColor + id4);
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
    	
    	void id22(int v, long value) {
    		throw new UnsupportedOperationException();
    	}
    	
    	void pushVertex(int v, int vLeft, int vRight) {
    		if (lazy[v]) {
    			id22(vLeft, values[v]);
    			id22(vRight, values[v]);
    			
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
    		
    		id61(1, 0, size - 1);
    	}
    	
    	void id61(int v, int left, int right) {
    		if (left == right) {
    			updateValue(v, left, right, value);
    		} else {
    			int mid = (left + right) >> 1;
    			int vLeft = (v << 1), vRight = (vLeft + 1);
    			
    			if (index <= mid) id61(vLeft, left, mid);
    			else id61(vRight, mid + 1, right);
    			
    			updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int start, end;
    	void updateSegment(int start, int end, long value) {
    		this.start = start;
    		this.end = end;
    		this.value = value;
    		
    		id62(1, 0, size - 1);
    	}

        void id62(int v, int left, int right) {
            if (start <= left && right <= end) {
                if (lazySupported) {
                    id22(v, value);
                } else {
                    updateValue(v, left, right, value);
                }
            } else {
                int mid = (left + right) >> 1;
                int vLeft = (v << 1), vRight = (vLeft + 1);

                if (lazySupported) pushVertex(v, vLeft, vRight);

                if (start <= mid) id62(vLeft, left, mid);
                if (mid < end) id62(vRight, mid + 1, right);

                updateVertex(v, vLeft, vRight);
            }
        }

        abstract void initResult(long... id33);

        abstract void id14(int v, int left, int right);

        void id52(int v, int left, int right) {
            id14(v, left, right);
        }

        void getIndex(int index, long... id33) {
            this.index = index;

            initResult(id33);

            id38(1, 0, size - 1);
        }

        void id38(int v, int left, int right) {
            if (lazySupported) {
                if (left == right) {
                    id52(v, left, right);
                } else {
                    int mid = (left + right) >> 1;
                    int vLeft = (v << 1), vRight = (vLeft + 1);

                    pushVertex(v, vLeft, vRight);

                    if (index <= mid) id38(vLeft, left, mid);
                    else id38(vRight, mid + 1, right);

                    updateVertex(v, vLeft, vRight);
                }
            } else {
                while (left <= right) {
                    id52(v, left, right);

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
    	
    	void getSegment(int start, int end, long... id33) {
    		this.start = start;
    		this.end = end;
    		
    		initResult(id33);
    		
    		id34(1, 0, size - 1);
    	}
    	
    	void id34(int v, int left, int right) {
    		if (start <= left && right <= end) {
    			id14(v, left, right);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				if (start <= mid) id34(vLeft, left, mid);
				if (mid < end) id34(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    	
    	int[] toArray() {
    		this.a = new int[size];
    		
    		id15(1, 0, size - 1);
    		
    		return a;
    	}
    	
    	void id15(int v, int left, int right) {
    		if (left == right) {
    			a[left] = (int)(tree[v]);
    		} else {
    			int mid = (left + right) >> 1;
				int vLeft = (v << 1), vRight = (vLeft + 1);
				
				if (lazySupported) pushVertex(v, vLeft, vRight);
				
				id15(vLeft, left, mid);
				id15(vRight, mid + 1, right);
				
				if (lazySupported) updateVertex(v, vLeft, vRight);
    		}
    	}
    }
    
    


    private static class Treap {

        static class Node {

            static int getCount(Node node) {
                return (node == null ? 0 : node.count);
            }

            static long getValue(Node node) {
                return (node == null ? 0 : node.value);
            }

            static long getSum(Node node) {
                return (node == null ? 0 : node.sum);
            }

            long priority;

            Node left, right;
            int count;

            long value, sum;
            boolean reversed;

            Node(long value) {
                this.priority = rnd.nextLong();
                this.count = 1;
                this.value = value;
                this.sum = value;
                this.reversed = false;
            }

            void update() {
                this.count = getCount(left) + getCount(right) + 1;
                this.sum = getSum(left) + getSum(right) + value;
            }

            void push() {
                if (reversed) {
                    Node tmp = left;
                    left = right;
                    right = tmp;

                    if (left != null) left.reversed ^= true;
                    if (right != null) right.reversed ^= true;

                    reversed = false;
                }
            }
        }

        Node root;
        Node[] splitParts;

        Treap() {
            this.root = null;
            this.splitParts = new Node[2];
        }

        void addValue(long value) {
            Node node = new Node(value);
            root = merge(root, node);
        }

        long id46(int startInclusive, int endExclusive) {
            splitClear();
            split(root, endExclusive);

            Node leftMid = splitParts[0];
            Node right = splitParts[1];

            splitClear();
            split(leftMid, startInclusive);

            Node left = splitParts[0];
            Node mid = splitParts[1];

            long result = Node.getSum(mid);

            root = merge(left, mid);
            root = merge(root, right);

            return result;
        }

        void updateValue(Node node, int index, long delta) {
            if (node == null) return;

            node.push();

            int leftCount = Node.getCount(node.left);
            if (index < leftCount) updateValue(node.left, index, delta);
            else if (index == leftCount) node.value += delta;
            else updateValue(node.right, index - leftCount - 1, delta);

            node.update();
        }

        long id75(Node node, int index) {
            Node result = id44(node, index);
            return Node.getValue(result);
        }

        Node id44(Node node, int key) {
            if (node == null) return null;

            node.push();

            int leftCount = Node.getCount(node.left);

            Node result;

            if (key < leftCount) result = id44(node.left, key);
            else if (key == leftCount) result = node;
            else result = id44(node.right, key - leftCount - 1);

            node.update();

            return result;
        }

        Node merge(Node left, Node right) {
            if (left == null) return right;
            if (right == null) return left;

            left.push();
            right.push();

            Node result;

            if (left.priority < right.priority) {
                left.right = merge(left.right, right);
                result = left;
            } else {
                right.left = merge(left, right.left);
                result = right;
            }

            result.update();

            return result;
        }

        void splitClear() {
            splitParts[0] = null;
            splitParts[1] = null;
        }

        void split(Node node, int key) {
            if (node == null) return;

            node.push();

            int leftCount = Node.getCount(node.left);
            if (key < leftCount) {
                split(node.left, key);

                node.left = splitParts[1];
                splitParts[1] = node;

            } else if (key == leftCount) {
                splitParts[0] = node.left;
                splitParts[1] = node;
                node.left = null;
            } else {
                split(node.right, key - leftCount - 1);

                node.right = splitParts[0];
                splitParts[0] = node;
            }

            node.update();
        }
    }

    


    private static int partition(int[] array, int startInclusive, int endExclusive) {
        int pivotIndex = rnd.nextInt(endExclusive - startInclusive) + startInclusive;
        return partition(array, startInclusive, endExclusive, pivotIndex);
    }

    private static int partition(int[] array, int startInclusive, int endExclusive, int pivotIndex) {
        int endInclusive = endExclusive - 1;

        int pivotValue = array[pivotIndex];
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

    private static int nthElement(int[] array, int index) {
        int left = 0, right = array.length;
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

    


    private static int[] shiftLeft(int[] a, int startInclusive, int endExclusive, int shift) {
        return shiftRight(a, startInclusive, endExclusive, -shift);
    }

    private static int[] shiftRight(int[] a, int startInclusive, int endExclusive, int shift) {
        int[] b = new int[a.length];

        for (int i = 0; i < startInclusive; ++i) b[i] = a[i];
        for (int i = endExclusive; i < a.length; ++i) b[i] = a[i];

        int length = (endExclusive - startInclusive);
        shift %= length;

        for (int i = startInclusive; i < endExclusive; ++i) {
            int i0 = i - startInclusive;
            int j0 = (i0 + shift + length) % length;
            int j = j0 + startInclusive;

            b[j] = a[i];
        }

        return b;
    }
}