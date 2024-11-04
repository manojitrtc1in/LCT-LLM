import java.awt.Point;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class id21 implements Runnable{

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    

    private void solve() {
        int t = readInt();
        while (t --> 0) {
            solveTest();
        }
    }

    void solveTest() {
        int n = readInt();
        int[] a = id2(n);

        int[] answer = new int[n];
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            answer[i] = a[j] * (i < j ? -1 : 1);
        }

        out.printlnAll(answer);
    }

    


    private final static boolean id5 = true;
    private final boolean id9 = !new File("input.txt").exists();



    private final static int id15 = 128;

    private final static boolean id26 = false;

    


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
    boolean yesNo(boolean yes) {
        out.println(yes ? "YES" : "NO");
        return yes;
    }

    


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
        new Thread(null, new id21(), "", id15 * (1L << 20)).start();
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

    @SuppressWarnings("unused")
    private void debug(Object... objects){
        if (id9){
            for (Object o: objects){
                System.err.println(o.toString());
            }
        }
    }

    


    private String delim = " ";

    private String id28() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = id28();
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
    private char[][] id20(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id8();
        }

        return field;
    }

    


    private long id19() {
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

        if (!id26) {
            return Integer.parseInt(readString());
        } else {
            return (int) id19();
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

    private int[] id12(int size) {
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id17(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] id30(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id12(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id26) {
            return Long.parseLong(readString());
        } else {
            return id19();
        }
    }

    @SuppressWarnings("unused")
    private long[] id14(int size) {
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
    private BigInteger id25() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal id22() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] id33(int size) {
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
            id23(from, to);
            id23(to, from);
        }

        public void id23(int from, int to) {
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
    private final static int id24 = 0, id13 = 1;

    @SuppressWarnings("unused")
    private int[][] id11(int vertexNumber, int edgesNumber) {
        return id11(vertexNumber, edgesNumber, id13, false);
    }

    private int[][] id11(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id23(from, to);
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
    private Edge[][] id27(int vertexNumber, int edgesNumber) {
        return id27(vertexNumber, edgesNumber, id13, false);
    }

    private Edge[][] id27(int vertexNumber, int edgesNumber,
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

    


    private static class id29 {

        @SuppressWarnings("unused")
        static Comparator<id29> increaseComparator = (indexPair1, indexPair2) -> {
            int value1 = indexPair1.value;
            int value2 = indexPair2.value;

            if (value1 != value2) {
                return value1 - value2;
            }

            int index1 = indexPair1.index;
            int index2 = indexPair2.index;

            return index1 - index2;
        };

        @SuppressWarnings("unused")
        static Comparator<id29> id1 = (indexPair1, indexPair2) -> {
            int value1 = indexPair1.value;
            int value2 = indexPair2.value;

            if (value1 != value2) {
                return -(value1 - value2);
            }

            int index1 = indexPair1.index;
            int index2 = indexPair2.index;

            return index1 - index2;
        };

        @SuppressWarnings("unused")
        static id29[] from(int[] array) {
            id29[] iip = new id29[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id29(array[i], i);
            }

            return iip;
        }

        int value, index;

        id29(int value, int index) {
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
    private id29[] id3(int size) {
        id29[] array = new id29[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id29(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id36 = 12;

        private int precision;
        private String format, id35;

        {
            precision = id36;

            format = createFormat(precision);
            id35 = format + " ";
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
            id35 = format + " ";
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

        void id31(double d){
            printf(id35, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id31(d[i]);
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

        
        private static final long id32 = -6463830523020118289L;

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

    


    @SuppressWarnings("unused")
    private static boolean isPrime(int x) {
        if (x < 2) return false;
        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0) return false;
        }

        return true;
    }

    @SuppressWarnings("unused")
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

    


    @SuppressWarnings("unused")
    int[] id34(int value) {
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
    long[] id34(long value) {
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