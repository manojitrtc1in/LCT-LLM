import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class ProblemE implements Runnable{

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    final long INF = Long.MAX_VALUE / 3;

    long[] id1;
    Map<Long, Integer> indexes;
    int[][] moves;

    long[] values;
    int[] multiples;

    long[][] dpSum;
    int[][] dpSize;
    int[][] parents;

    boolean[][] used;

    

    private void solve() {
        int n = readInt();
        long k = readLong();
        long[] a = id16(n);
        
        if (k == 1) {
            int minIndex = 0;
            for (int i = 1; i < n; ++i) {
                if (a[minIndex] > a[i]) {
                    minIndex = i;
                }
            }
            
            out.println(1);
            out.println(minIndex + 1);
            return;
        }

        this.id1 = id41(k);
        Arrays.sort(id1);

        int size = id1.length;

        this.indexes = new HashMap<>();
        for (int i = 0; i < size; ++i) {
            indexes.put(id1[i], i);
        }

        this.values = new long[n + 1];
        this.multiples = new int[n + 1];

        for (int i = 0; i < n; ++i) {
            values[i + 1] = a[i];

            long multiple = gcd(a[i], k);
            multiples[i + 1] = indexes.get(multiple);
        }

        this.moves = new int[n + 1][size];
        for (int i = 0; i < moves.length; ++i) {
            Arrays.fill(moves[i], -1);
        }

        int[] iMoves = new int[size];
        for (int i = 0; i < size; ++i) {
            long id34 = id1[i];
            Arrays.fill(iMoves, -1);

            for (int j = 1; j < multiples.length; ++j) {
                int multiple = multiples[j];
                if (iMoves[multiple] != -1) continue;

                long id12 = id1[multiple];

                long gcd = gcd(id34, id12);
                if (gcd == 1) {
                    iMoves[multiple] = i;
                } else {
                    long divisor = id34 / gcd;
                    int index = indexes.get(divisor);


                    iMoves[multiple] = index;
                }
            }

            for (int j = 1; j < multiples.length; ++j) {
                moves[j][i] = iMoves[multiples[j]];
            }
        }

        time();

        this.dpSum = new long[n + 1][size];
        this.dpSize = new int[n + 1][size];

        for (int it = 0; it < dpSize.length; ++it) {
            Arrays.fill(dpSum[it], INF);
            Arrays.fill(dpSize[it], n + 1);
        }

        this.parents = new int[n + 1][size];
        for (int[] row : parents) {
            Arrays.fill(row, -1);
        }

        this.used = new boolean[n + 1][size];

        dpSize[0][0] = 0;
        dpSum[0][0] = 0;

        Arrays.fill(used[0], true);

        dfs(n, size - 1);

        boolean fail = dpSum[n][size - 1] == INF;

        if (fail) {
            out.println(-1);
        } else {
            int answerSize = dpSize[n][size - 1];
            out.println(answerSize);

            int[] answers = new int[answerSize];
            for (int i = n, d = size - 1, j = 0; i > 0; --i) {
                int parent = parents[i][d];
                if (parent != d) {
                    answers[j++] = i;
                    d = parent;
                }
            }

            out.printlnAll(answers);
        }
    }

    void dfs(int i, int cur) {
        if (used[i][cur]) return;

        used[i][cur] = true;

        long[] id24 = dpSum[i - 1], id27 = dpSum[i];
        int[] id22 = dpSize[i - 1], id0 = dpSize[i];

        dfs(i - 1, cur);

        id27[cur] = id24[cur];
        id0[cur] = id22[cur];
        parents[i][cur] = cur;

        final long value = values[i];



        int prev = moves[i][cur];








        if (cur != prev){




            dfs(i - 1, prev);

            int prevSize = id22[prev] + 1, curSize = id0[cur];
            long prevSum = id24[prev] + value, curSum = id27[cur];

            if (curSize > prevSize || curSize == prevSize && curSum > prevSum) {
                id0[cur] = prevSize;
                id27[cur] = prevSum;
                parents[i][cur] = prev;
            }
        }
    }

    


    private final static boolean id6 = true;
    private final boolean id10 = !new File("input.txt").exists();



    private final static int id18 = 128;

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
                } while (id6);
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
        new Thread(null, new ProblemE(), "", id18 * (1L << 20)).start();
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
        while(!tok.hasMoreTokens()){
            tok = new StringTokenizer(readLine(), delim);
        }

        return tok.nextToken(delim);
    }

    


    private final char id8 = '\0';

    @SuppressWarnings("unused")
    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id8;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id9() {
        return readLine().toCharArray();
    }

    @SuppressWarnings("unused")
    private char[][] id26(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id9();
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

        if (!id32) {
            return Integer.parseInt(readString());
        } else {
            return (int) id23();
        }
    }

    private int[] id3(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

    @SuppressWarnings("unused")
    private int[] id11(int size) {
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
        int[] array = id3(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id20(int rowsCount, int columnsCount) {
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
            matrix[rowIndex] = id14(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id32) {
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
    private double[] id5(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private BigInteger id31() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal id28() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] id40(int size) {
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

    @SuppressWarnings("unused")
    private final static int id30 = 0, id15 = 1;

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

            if (directed) graphBuilder.id29(from, to);
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
    private Edge[][] id33(int vertexNumber, int edgesNumber) {
        return id33(vertexNumber, edgesNumber, id15, false);
    }

    private Edge[][] id33(int vertexNumber, int edgesNumber,
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

    


    private static class id36 {

        @SuppressWarnings("unused")
        static Comparator<id36> increaseComparator = new Comparator<ProblemE.id36>() {
            @Override
            public int compare(ProblemE.id36 id25, ProblemE.id36 id17) {
                int value1 = id25.value;
                int value2 = id17.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id25.index;
                int index2 = id17.index;

                return index1 - index2;
            }
        };

        @SuppressWarnings("unused")
        static Comparator<id36> id2 = new Comparator<ProblemE.id36>() {
            @Override
            public int compare(ProblemE.id36 id25, ProblemE.id36 id17) {
                int value1 = id25.value;
                int value2 = id17.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id25.index;
                int index2 = id17.index;

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
        int id7() {
            return index + 1;
        }
    }

    @SuppressWarnings("unused")
    private id36[] id4(int size) {
        id36[] array = new id36[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id36(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id43 = 12;

        private int precision;
        private String format, id42;

        {
            precision = id43;

            format = createFormat(precision);
            id42 = format + " ";
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
            id42 = format + " ";
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

        void id38(double d){
            printf(id42, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id38(d[i]);
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

        
        private static final long id39 = -6463830523020118289L;

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
    int[] id41(int value) {
        List<Integer> id1 = new ArrayList<>();
        for (int divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id1.add(divisor);
                if (divisor * divisor != value) {
                    id1.add(value / divisor);
                }
            }
        }

        return castInt(id1);
    }

    @SuppressWarnings("unused")
    long[] id41(long value) {
        List<Long> id1 = new ArrayList<>();
        for (long divisor = 1; divisor * divisor <= value; ++divisor) {
            if (value % divisor == 0) {
                id1.add(divisor);
                if (divisor * divisor != value) {
                    id1.add(value / divisor);
                }
            }
        }

        return castLong(id1);
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