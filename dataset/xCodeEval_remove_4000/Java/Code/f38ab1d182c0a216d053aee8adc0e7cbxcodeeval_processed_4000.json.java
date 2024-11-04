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

    private final static int MODULO = 1000 * 1000 * 1000 + 7;

    private void solve() {
        final int schools = readInt();
        final int types = readInt();

        final long[] factorials = new long[types + 1];
        factorials[0] = 1;

        for (int i = 1; i <= types; ++i) {
            factorials[i] = mult(factorials[i - 1], i);
        }

        final long firstBase = 8725641, secondBase = 4258743;

        long[] firstHashes = new long[types];
        long[] secondHashes = new long[types];

        int[] colors = new int[types];
        Arrays.fill(colors, -1);

        int[] counts = new int[types];
        Arrays.fill(counts, 0);

        long firstPower = 1, secondPower = 1;
        for (int school = 0; school < schools; ++school) {
            int size = readInt();
            int[] pokemons = id12(size);

            for (int pokemon : pokemons) {
                if (colors[pokemon] != school) {
                    colors[pokemon] = school;
                    counts[pokemon] = 0;
                }

                ++counts[pokemon];
            }

            for (int pokemon : pokemons) {
                if (colors[pokemon] == school) {
                    firstHashes[pokemon] = add(
                            firstHashes[pokemon],
                            mult(counts[pokemon], firstPower)
                    );

                    secondHashes[pokemon] = add(
                            secondHashes[pokemon],
                            mult(counts[pokemon], secondPower)
                    );

                    colors[pokemon] = -1;
                    counts[pokemon] = 0;
                }
            }

            firstPower = mult(firstPower, firstBase);
            secondPower = mult(secondPower, secondBase);
        }

        Map<HashPair, Integer> groupSizes = new HashMap<>();
        for (int pokemon = 0; pokemon < types; ++pokemon) {
            HashPair hash = new HashPair(firstHashes[pokemon], secondHashes[pokemon]);

            int count = groupSizes.getOrDefault(hash, 0);
            groupSizes.put(hash, count + 1);
        }

        long answer = 1;
        for (Map.Entry<HashPair, Integer> hashEntry : groupSizes.entrySet()) {
            int value = hashEntry.getValue();

            answer = mult(answer, factorials[value]);
        }

        out.println(answer);
    }

    int[] id0(int size, int types) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = rnd.nextInt(types);
        }

        return array;
    }

    class HashPair {
        long firstHash, secondHash;

        public HashPair(long firstHash, long secondHash) {
            this.firstHash = firstHash;
            this.secondHash = secondHash;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            HashPair hashPair = (HashPair) o;

            if (firstHash != hashPair.firstHash) return false;
            return secondHash == hashPair.secondHash;

        }

        @Override
        public int hashCode() {
            int result = (int) (firstHash ^ (firstHash >>> 32));
            result = 576821 * result + (int) (secondHash ^ (secondHash >>> 32));
            return result;
        }
    }

    long add(long a, long b) {
        return (a + b) % MODULO;
    }

    long mult(long a, long b) {
        return (a * b) % MODULO;
    }

    


    private final static boolean id3 = false;
    private final boolean id10 = System.getProperty("id10") != null;
    private final static boolean id6 = true;

    private final static int id15 = 128;

    private final static boolean id25 = false;

    


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
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (id3) break;
                        else throw e;
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
        new Thread(null, new C(), "", id15 * (1L << 20)).start();
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

    private void debug(Object... objects){
        if (id10){
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

    


    private final char id8 = '\0';

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

    private char[][] id21(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id9();
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

        if (!id25) {
            return Integer.parseInt(readString());
        } else {
            return (int) id19();
        }
    }

    private int[] id1(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

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

    private int[] id12(int size) {
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

    private int[][] id27(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id12(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id25) {
            return Long.parseLong(readString());
        } else {
            return id19();
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

    private double[] id5(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id24() {
        return new BigInteger(readString());
    }

    private BigDecimal id22() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id30(int size) {
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

    


    private static class id26 {

        static Comparator<id26> increaseComparator = new Comparator<C.id26>() {

            @Override
            public int compare(C.id26 id20, C.id26 id14) {
                int value1 = id20.value;
                int value2 = id14.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id20.index;
                int index2 = id14.index;

                return index1 - index2;
            }
        };

        static Comparator<id26> id2 = new Comparator<C.id26>() {

            @Override
            public int compare(C.id26 id20, C.id26 id14) {
                int value1 = id20.value;
                int value2 = id14.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id20.index;
                int index2 = id14.index;

                return index1 - index2;
            }
        };

        int value, index;

        id26(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id7() {
            return index + 1;
        }
    }

    private id26[] id4(int size) {
        id26[] array = new id26[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id26(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id33 = 12;

        private int precision;
        private String format, id32;

        {
            precision = id33;

            format = createFormat(precision);
            id32 = format + " ";
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
            id32 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }

        void id28(double d){
            printf(id32, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id28(d[i]);
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

        
        private static final long id29 = -6463830523020118289L;

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

        public static <ValueType> MultiSet<ValueType> id31() {
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

        
        private static final long id29 = -3793737771950984481L;

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

