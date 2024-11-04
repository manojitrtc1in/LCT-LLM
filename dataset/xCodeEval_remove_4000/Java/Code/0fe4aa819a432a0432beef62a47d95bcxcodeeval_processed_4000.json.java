import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class B implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";

    private void solve() {
        final int n = readInt();
        final int maxSkill = readInt();

        final long costFull = readInt();
        final long costMin = readInt();

        final long money = readLong();

        final int[] skills = id1(n);

        final NavigableMap<Integer, Integer> counts = new TreeMap<>();
        counts.put(0, 0);
        counts.put(maxSkill, 0);

        for (int skill : skills) {
            inc(counts, skill);
        }

        final NavigableMap<Integer, Integer> prefixCounts = new TreeMap<>();

        int curCount = 0;
        for (Map.Entry<Integer, Integer> e : counts.entrySet()) {
            curCount += e.getValue();
            prefixCounts.put(e.getKey(), curCount);
        }

        final id30[] sortedSkills = id30.from(skills);
        Arrays.sort(sortedSkills, id30.increaseComparator);

        final long[] id32 = new long[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            id32[i] = id32[i + 1] + maxSkill - sortedSkills[i].value;
        }

        final long[] id18 = new long[n];
        for (int i = 0; i < n; ++i) {
            id18[i] = (i == 0 ? 0 : id18[i - 1]) + sortedSkills[i].value;
        }

        if (money >= id32[0]) {
            long totalSum = power(maxSkill, costMin, n, costFull);
            out.println(totalSum);

            for (int i = 0; i < n; ++i) {
                out.print(maxSkill + " ");
            }
            out.println();
        } else {
            long answer = -1;
            int id29 = -1;
            int id41 = -1;

            final int id22 = counts.get(maxSkill);
            for (int id23 = id22; id23 < n; ++id23) {
                int id42 = n - id23;

                long id3 = id32[id42];
                if (id3 > money) {
                    continue;
                }

                long id34 = money - id3;

                int id37 = -1;
                for (int left = sortedSkills[0].value, right = maxSkill; left <= right; ) {
                    int mid = ((left + right) >> 1);

                    int midCount = prefixCounts.floorEntry(mid).getValue();
                    midCount = min(midCount, id42);

                    long needMoney = mid * 1L * midCount - id18[midCount - 1];
                    if (needMoney <= id34) {
                        id37 = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                long curPower = power(id37, costMin, id23, costFull);
                if (answer < curPower) {
                    answer = curPower;
                    id29 = id42;
                    id41 = id37;
                }
            }

            out.println(answer);

            int[] updatedSkills = new int[n];
            for (int i = 0; i < id29; ++i) {
                updatedSkills[sortedSkills[i].index] = id41;
            }

            for (int i = id29; i < n; ++i) {
                updatedSkills[sortedSkills[i].index] = maxSkill;
            }
            
            for (int i = 0; i < n; ++i) {
                updatedSkills[i] = max(updatedSkills[i], skills[i]);
            }

            for (int skill : updatedSkills) {
                out.print(skill + " ");
            }
            out.println();
        }
    }

    long power(int minSkill, long costMin, int maxCount, long costFull) {
        return minSkill * costMin + maxCount * costFull;
    }

    void inc(Map<Integer, Integer> counts, int value) {
        int count = counts.getOrDefault(value, 0);
        counts.put(value, count + 1);
    }

    


    private final static boolean id2 = false;
    private final static boolean id6 = true;
    private final boolean id10 = System.getProperty("id10") != null;

    private final static int id15 = 128;

    private final static boolean id28 = false;

    


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
                        if (id2) break;
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
        new Thread(null, new B(), "", id15 * (1L << 20)).start();
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

    private char[][] id24(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id9();
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

        if (!id28) {
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

    private int[][] id31(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id12(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id28) {
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

    private double[] id5(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id27() {
        return new BigInteger(readString());
    }

    private BigDecimal id25() {
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
            id26(from, to);
            id26(to, from);
        }

        public void id26(int from, int to) {
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

    


    private static class id30 {

        static Comparator<id30> increaseComparator = new Comparator<B.id30>() {

            @Override
            public int compare(B.id30 id21, B.id30 id14) {
                int value1 = id21.value;
                int value2 = id14.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id21.index;
                int index2 = id14.index;

                return index1 - index2;
            }
        };

        static Comparator<id30> id0 = new Comparator<B.id30>() {

            @Override
            public int compare(B.id30 id21, B.id30 id14) {
                int value1 = id21.value;
                int value2 = id14.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id21.index;
                int index2 = id14.index;

                return index1 - index2;
            }
        };

        static id30[] from(int[] array) {
            id30[] iip = new id30[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id30(array[i], i);
            }

            return iip;
        }

        int value, index;

        id30(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id7() {
            return index + 1;
        }
    }

    private id30[] id4(int size) {
        id30[] array = new id30[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id30(readInt(), index);
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

        void id33(double d){
            printf(id39, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id33(d[i]);
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

    


    private static int[] id19(int n) {
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

        public static <ValueType> MultiSet<ValueType> id38() {
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

