import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class D implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random(23456);
    private final static String fileName = "";

    static class DSU {
        int[] parents;

        DSU(int n) {
            this.parents = castInt(order(n));
        }

        int get(int v) {
            if (v == parents[v]) return v;
            return parents[v] = get(parents[v]);
        }

        boolean union(int a, int b) {
            a = get(a);
            b = get(b);

            if (a == b) return false;

            if (rnd.nextBoolean()) {
                parents[a] = b;
            } else {
                parents[b] = a;
            }

            return true;
        }
    }

    interface DSolver {

        void init(int[][] graph);
        double getAnswer(int from, int to);
    }

    static class id44 implements DSolver {
        Point[] id23;
        int[] maxDistances;

        DSU dsu;
        int[][] graph;

        double[] id26;

        List<Integer>[] id3;
        List<Integer>[] prefs;
        double[] id33;

        Map<Point, Double> cached;

        public void init(int[][] graph) {
            int n = graph.length;

            this.dsu = new DSU(n);

            for (int from = 0; from < n; ++from) {
                for (int to : graph[from]) {
                    dsu.union(from, to);
                }
            }

            this.graph = graph;

            this.id23 = new Point[n];
            for (int v = 0; v < n; ++v) {
                id23[v] = new Point(0, 0);
            }

            this.maxDistances = new int[n];

            for (int v = 0; v < n; ++v) {
                if (v == dsu.get(v)) {
                    id11(v, -1);
                    id47(v, -1, -1);
                }
            }

            this.id26 = new double[n];
            int[] sizes = new int[n];

            this.id3 = new List[n];
            this.prefs = new List[n];
            for (int v = 0; v < n; ++v) {
                if (v == dsu.get(v)) {
                    id3[v] = new ArrayList<>();
                    prefs[v] = new ArrayList<>();
                }
            }

            this.id33 = new double[n];

            for (int v = 0; v < n; ++v) {
                int root = dsu.get(v);
                sizes[root]++;
                id26[root] += maxDistances[v];
                id3[root].add(maxDistances[v]);
                prefs[root].add(maxDistances[v]);

                id33[root] = Math.max(id33[root], maxDistances[v]);
            }

            for (int v = 0; v < n; ++v) {
                if (sizes[v] > 0) {
                    id26[v] /= sizes[v];
                    Collections.sort(id3[v]);
                    Collections.sort(prefs[v]);
                    for (int i = prefs[v].size() - 2; i >= 0; --i) {
                        prefs[v].set(i, prefs[v].get(i) + prefs[v].get(i + 1));
                    }
                }
            }

            this.cached = new HashMap<>();
        }

        void id47(int from, int parent, int id16) {
            int id1 = id16 + 1;

            maxDistances[from] = Math.max(id23[from].x, id1);

            for (int to : graph[from]) {
                if (to == parent) continue;

                int id41 = id23[to].x + 1;
                if (id23[from].x == id41) {
                    id47(to, from, max(id1, id23[from].y));
                } else {
                    id47(to, from, max(id1, id23[from].x));
                }
            }
        }

        void id11(int from, int parent) {
            int firstMax = 0, secondMax = 0;

            for (int to : graph[from]) {
                if (to == parent) continue;

                id11(to, from);

                int id38 = id23[to].x + 1;
                if (firstMax < id38) {
                    secondMax = firstMax;
                    firstMax = id38;
                } else if (secondMax < id38) {
                    secondMax = id38;
                }
            }

            id23[from].x = firstMax;
            id23[from].y = secondMax;
        }

        @Override
        public double getAnswer(int from, int to) {
            int fromRoot = dsu.get(from);
            int toRoot = dsu.get(to);

            if (fromRoot == toRoot) {
                return -1;
            }

            if (id3[fromRoot].size() > id3[toRoot].size()) {
                int tmp = fromRoot;
                fromRoot = toRoot;
                toRoot = tmp;
            }

            Double alreadyAnswer = cached.get(new Point(fromRoot, toRoot));
            if (alreadyAnswer != null) return alreadyAnswer;

            double id14 = max(id33[fromRoot], id33[toRoot]);

            double answer = 0;
            for (int i = 0; i < id3[fromRoot].size(); ++i) {
                int id34 = id3[fromRoot].get(i);

                int side = -1;
                for (int left = 0, right = id3[toRoot].size() - 1; left <= right; ) {
                    int mid = (left + right) >> 1;
                    if (id3[toRoot].get(mid) + id34  + 1 > id14) {
                        side = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }

                double curDiameter = id14 * prefs[toRoot].size();
                if (side > -1) {
                    curDiameter = (id14 * side + prefs[toRoot].get(side) + (id34 + 1) * (prefs[toRoot].size() - side));
                }

                answer += curDiameter / prefs[toRoot].size();
            }

            answer /= prefs[fromRoot].size();
            cached.put(new Point(fromRoot, toRoot), answer);
            return answer;
        }
    }

    static class id35 implements DSolver {

        int[][] graph;

        @Override
        public void init(int[][] graph) {
            this.graph = graph;
        }

        @Override
        public double getAnswer(int from, int to) {
            this.used = new boolean[graph.length];
            dfs(from);

            if (used[to]) return -1;

            List<Integer> fromVertices = new ArrayList<>();
            for (int v = 0; v < graph.length; ++v) {
                if (used[v]) fromVertices.add(v);
            }

            Arrays.fill(used, false);
            dfs(to);

            List<Integer> toVertices = new ArrayList<>();
            for (int v = 0; v < graph.length; ++v) {
                if (used[v]) toVertices.add(v);
            }

            double answer = 0;
            int count = 0;

            for (int fromV : fromVertices) {
                for (int toV : toVertices) {
                    double max = 0;

                    for (int v : fromVertices) {
                        max = max(max, id30(v, -1, 0, fromV, toV));
                    }

                    for (int v : toVertices) {
                        max = max(max, id30(v, -1, 0, toV, fromV));
                    }

                    answer += max;
                    count++;
                }
            }

            return answer / count;
        }

        int[] maxDistances;

        int id30(int from, int parent, int distance, int fromV, int toV){
            int max = distance;
            for (int to : graph[from]) {
                if (to != parent) {
                    max = max(max, id30(to, from, distance + 1, fromV, toV));
                }
            }

            if (from == fromV) {
                max = max(max, id30(toV, fromV, distance + 1, fromV, toV));
            }

            return  max;
        }

        boolean[] used;

        void dfs(int from) {
            used[from] = true;
            for (int to : graph[from]) {
                if (!used[to]) dfs(to);
            }
        }
    }

    private void solve() {
        int n = readInt();
        int m = readInt();
        int q = readInt();

        GraphBuilder graphBuilder = GraphBuilder.createInstance(n);
        for (int i = 0; i < m; ++i) {
            int from = readInt() - 1;
            int to = readInt() - 1;

            graphBuilder.addEdge(from, to);
        }

        int[][] graph = graphBuilder.build();

        DSolver solver = new id44();
        solver.init(graph);

        while (q --> 0) {
            int from = readInt() - 1;
            int to = readInt() - 1;

            double answer = solver.getAnswer(from, to);
            out.println(answer);
        }
    }



    


    private final static boolean id4 = false;
    private final static boolean id7 = true;
    private final boolean id12 = System.getProperty("id12") != null;

    private final static int id19 = 128;

    private final static boolean id32 = false;

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id12) {
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
                        if (id4) break;
                        else throw e;
                    }
                } while (id7);
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
        new Thread(null, new D(), "", id19 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id12){
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
        if (id12){
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

    


    private final char id9 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
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

    private char[][] id27(int rowsCount) {
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

        if (!id32) {
            return Integer.parseInt(readString());
        } else {
            return (int) id24();
        }
    }

    private int[] id2(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    private int[] id13(int size) {
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
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id21(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

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

    private double[] id6(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id31() {
        return new BigInteger(readString());
    }

    private BigDecimal id28() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id42(int size) {
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
            id29(from, to);
            id29(to, from);
        }

        public void id29(int from, int to) {
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

    


    private static class id36 {

        static Comparator<id36> increaseComparator = new Comparator<D.id36>() {

            @Override
            public int compare(D.id36 id25, D.id36 id18) {
                int value1 = id25.value;
                int value2 = id18.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id25.index;
                int index2 = id18.index;

                return index1 - index2;
            }
        };

        static Comparator<id36> id0 = new Comparator<D.id36>() {

            @Override
            public int compare(D.id36 id25, D.id36 id18) {
                int value1 = id25.value;
                int value2 = id18.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id25.index;
                int index2 = id18.index;

                return index1 - index2;
            }
        };

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

        int id8() {
            return index + 1;
        }
    }

    private id36[] id5(int size) {
        id36[] array = new id36[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id36(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id46 = 12;

        private int precision;
        private String format, id45;

        {
            precision = id46;

            format = createFormat(precision);
            id45 = format + " ";
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
            id45 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }

        void id39(double d){
            printf(id45, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id39(d[i]);
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

        
        private static final long id40 = -6463830523020118289L;

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

    


    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

    


    private static class MultiSet<ValueType> {

        public static <ValueType> MultiSet<ValueType> id43() {
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

        
        private static final long id40 = -3793737771950984481L;

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

    


    
    private static List<Integer> order(int n) {
        List<Integer> sequence = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            sequence.add(i);
        }

        return sequence;
    }
}

