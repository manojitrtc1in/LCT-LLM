import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class D implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";

    private static final int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private static final int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

    private static boolean checkLimit(int index, int start, int end) {
        if (start < end) return index <= end;
        else if (start > end) return index >= end;
        else return index == end;
    }

    private static int getStart(int step, int index, int size) {
        switch (step) {
            case 0: return index;
            case 1: return size - 1;
            case -1: return 0;
            default: return 0;
        }
    }

    private static int getEnd(int step, int start, int size) {
        if (step == 0) return start;
        else return size - 1 - start;
    }

    private static int getDelta(int step) {
        if (step == 1) return -1;
        else return 1;
    }

    private void solve() {
        int n = readInt();
        int m = readInt();
        int q = readInt();

        int[][] a = id16(n, m);

        int[][][] sides = new int[4][n][m];

        for (int direction = 0; direction < steps.length; ++direction) {
            int[] step = steps[direction];

            int iStart = getStart(step[0], 0, n);
            int iEnd = n - 1 - iStart;
            int iDelta = getDelta(step[0]);

            int jStart = getStart(step[1], 0, m);
            int jEnd = m - 1 - jStart;
            int jDelta = getDelta(step[1]);

            for (int i = iStart; checkLimit(i, iStart, iEnd); i += iDelta) {
                for (int j = jStart; checkLimit(j, jStart, jEnd); j += jDelta) {
                    if (0 == a[i][j]) sides[direction][i][j] = -1;
                    else {
                        int nextI = i + step[0];
                        int nextJ = j + step[1];

                        int prev = (
                                checkCell(nextI, n, nextJ, m)
                                        ? sides[direction][nextI][nextJ]
                                        : -1
                        );

                        int needCoordinate = (step[0] == 0 ? j : i);
                        sides[direction][i][j] = (prev == -1 ? needCoordinate : prev);
                    }
                }
            }
        }

        final int SWAP = 1, id15 = 2;

        while (q --> 0) {
            int type = readInt();
            int x = readInt() - 1;
            int y = readInt() - 1;

            if (SWAP == type) {
                a[x][y] ^= 1;

                for (int direction = 0; direction < steps.length; ++direction) {
                    int[] step = steps[direction];

                    int iStart = getStart(step[0], x, n);
                    int iEnd = getEnd(step[0], iStart, n);
                    int iDelta = getDelta(step[0]);

                    int jStart = getStart(step[1], y, m);
                    int jEnd = getEnd(step[1], jStart, m);
                    int jDelta = getDelta(step[1]);

                    for (int i = iStart; checkLimit(i, iStart, iEnd); i += iDelta) {
                        for (int j = jStart; checkLimit(j, jStart, jEnd); j += jDelta) {
                            if (0 == a[i][j]) sides[direction][i][j] = -1;
                            else {
                                int nextI = i + step[0];
                                int nextJ = j + step[1];

                                int prev = (
                                        checkCell(nextI, n, nextJ, m)
                                                ? sides[direction][nextI][nextJ]
                                                : -1
                                );

                                int needCoordinate = (step[0] == 0 ? j : i);
                                sides[direction][i][j] = (prev == -1 ? needCoordinate : prev);
                            }
                        }
                    }
                }
            } else if (id15 == type) {
                int maxSquare = 0;
                if (a[x][y] > 0) {
                    

                    int maxUp = sides[UP][x][y], minDown = sides[DOWN][x][y];
                    for (int right = y, width = 1; right <= sides[RIGHT][x][y];
                         ++right, ++width) {
                        maxUp = max(maxUp, sides[UP][x][right]);
                        minDown = min(minDown, sides[DOWN][x][right]);

                        int height = minDown - maxUp + 1;

                        maxSquare = max(maxSquare, width * height);
                    }

                    

                    maxUp = sides[UP][x][y];
                    minDown = sides[DOWN][x][y];
                    for (int left = y, width = 1; left >= sides[LEFT][x][y];
                         --left, ++width) {
                        maxUp = max(maxUp, sides[UP][x][left]);
                        minDown = min(minDown, sides[DOWN][x][left]);

                        int height = minDown - maxUp + 1;

                        maxSquare = max(maxSquare, width * height);
                    }

                    

                    int maxLeft = sides[LEFT][x][y], minRight = sides[RIGHT][x][y];
                    for (int bottom = x, height = 1; bottom <= sides[DOWN][x][y];
                         ++bottom, ++height) {
                        maxLeft = max(maxLeft, sides[LEFT][bottom][y]);
                        minRight = min(minRight, sides[RIGHT][bottom][y]);

                        int width = minRight - maxLeft + 1;

                        maxSquare = max(maxSquare, width * height);
                    }

                    

                    maxLeft = sides[LEFT][x][y];
                    minRight = sides[RIGHT][x][y];
                    for (int top = x, height = 1; top >= sides[UP][x][y];
                         --top, ++height) {
                        maxLeft = max(maxLeft, sides[LEFT][top][y]);
                        minRight = min(minRight, sides[RIGHT][top][y]);

                        int width = minRight - maxLeft + 1;

                        maxSquare = max(maxSquare, width * height);
                    }
                }

                out.println(maxSquare);
            }
        }
    }

    


    private final static boolean id2 = false;
    private final static boolean id5 = true;
    private final boolean id9 = System.getProperty("id9") != null;

    private final static int id14 = 128;

    private final static boolean id24 = false;

    


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
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (id2) break;
                        else throw e;
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
        new Thread(null, new D(), "", id14 * (1L << 20)).start();
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

    private void debug(Object... objects){
        if (id9){
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

    


    private final char id7 = '\0';

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

    private char[][] id20(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id8();
        }

        return field;
    }

    


    private long id18() {
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

        if (!id24) {
            return Integer.parseInt(readString());
        } else {
            return (int) id18();
        }
    }

    private int[] id1(int size) {
        int[] array = new int[size];

        for (int index = 0; index < size; ++index){
            array[index] = readInt();
        }

        return array;
    }

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

    private int[] id11(int size) {
        int[] array = id1(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    private int[][] id16(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id1(columnsCount);
        }

        return matrix;
    }

    private int[][] id27(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id11(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id24) {
            return Long.parseLong(readString());
        } else {
            return id18();
        }
    }

    private long[] id12(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id4(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id23() {
        return new BigInteger(readString());
    }

    private BigDecimal id21() {
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
            id22(from, to);
            id22(to, from);
        }

        public void id22(int from, int to) {
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

        static Comparator<id26> increaseComparator = new Comparator<D.id26>() {

            @Override
            public int compare(D.id26 id19, D.id26 id13) {
                int value1 = id19.value;
                int value2 = id13.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id19.index;
                int index2 = id13.index;

                return index1 - index2;
            }
        };

        static Comparator<id26> id0 = new Comparator<D.id26>() {

            @Override
            public int compare(D.id26 id19, D.id26 id13) {
                int value1 = id19.value;
                int value2 = id13.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id19.index;
                int index2 = id13.index;

                return index1 - index2;
            }
        };

        int value, index;

        id26(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id6() {
            return index + 1;
        }
    }

    private id26[] id3(int size) {
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

    private static Point id25(int[] array) {
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

    


    private static int[] id17(int n) {
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

