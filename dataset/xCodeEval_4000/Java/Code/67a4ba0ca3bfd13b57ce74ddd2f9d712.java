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

    

    

    

    

    


    static final int MAX_SIZE = 100 * 1000 + 5;

    private void solve() {
        int m = readInt();
        int n = readInt();

        int k = readInt();
        Point[] ps = readPointArray(k);

        for (Point p : ps) {
            int x = p.y;
            int y = p.x;

            p.x = x - y + MAX_SIZE;
            p.y = x + y;
        }

        int xSize = MAX_SIZE + MAX_SIZE + 1;
        List<Integer>[] xs = new List[xSize];
        for (int x = 0; x < xSize; ++x) {
            xs[x] = new ArrayList<>(1);
        }

        int ySize = MAX_SIZE + MAX_SIZE + 1;
        List<Integer>[] ys = new List[ySize];
        for (int y = 0; y < ySize; ++y) {
            ys[y] = new ArrayList<>(1);
        }

        for (int i = 0; i < ps.length; ++i) {
            Point p = ps[i];
            xs[p.x].add(i);
            ys[p.y].add(i);
        }

        final long NOT_ANSWER = -2;

        long[] answers = new long[k];
        Arrays.fill(answers, NOT_ANSWER);

        long curTime = 0;

        final int[][] steps = {
                { 0, 1 }, 

                { -1, 0 }, 

                { 0, -1 }, 

                { 1, 0 }, 

        };

        final int UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3;

        for (int curX = MAX_SIZE, curY = 0, curDir = UP; ; ) {
            int stepX = steps[curDir][0];
            int stepY = steps[curDir][1];

            if (stepX == 0) {
                if (xs[curX].size() > 0) {
                    for (int index : xs[curX]) {
                        if (answers[index] != NOT_ANSWER) continue;

                        long deltaTime = Math.abs(ps[index].y - curY);

                        answers[index] = curTime + deltaTime;
                    }
                }

                if (curDir == UP) {
                    int lastColumn = m;
                    int lastRow = curX - MAX_SIZE + lastColumn;

                    int nextXJ = curX;
                    int nextYJ = lastRow + lastColumn;

                    lastRow = n;
                    lastColumn = lastRow - curX + MAX_SIZE;

                    int nextXI = curX;
                    int nextYI = lastRow + lastColumn;

                    if (nextYJ == nextYI) {
                        break; 

                    } else if (nextYJ < nextYI){
                        curTime += (nextYJ - curY);

                        curDir = LEFT;
                        curY = nextYJ;
                    } else {
                        curTime += (nextYI - curY);

                        curDir = RIGHT;
                        curY = nextYI;
                    }
                } else {
                    int lastColumn = 0;
                    int lastRow = curX - MAX_SIZE + lastColumn;

                    int nextXJ = curX;
                    int nextYJ = lastRow + lastColumn;

                    lastRow = 0;
                    lastColumn = lastRow - curX + MAX_SIZE;

                    int nextXI = curX;
                    int nextYI = lastRow + lastColumn;

                    if (nextYJ == nextYI) {
                        break; 

                    } else if (nextYJ > nextYI){
                        curTime += Math.abs(curY - nextYJ);

                        curDir = RIGHT;
                        curY = nextYJ;
                    } else {
                        curTime += Math.abs(curY - nextYI);

                        curDir = LEFT;
                        curY = nextYI;
                    }
                }
            } else {
                if (ys[curY].size() > 0) {
                    for (int index : ys[curY]) {
                        if (answers[index] != NOT_ANSWER) continue;

                        long deltaTime = Math.abs(ps[index].x - curX);

                        answers[index] = curTime + deltaTime;
                    }
                }

                if (curDir == RIGHT) {
                    int lastColumn = m;
                    int lastRow = curY - lastColumn;

                    int nextXJ = lastRow - lastColumn + MAX_SIZE;
                    int nextYJ = curY;

                    lastRow = 0;
                    lastColumn = curY - lastRow;

                    int nextXI = lastRow - lastColumn + MAX_SIZE;
                    int nextYI = curY;

                    if (nextXJ == nextXI) {
                        break; 

                    } else if (nextXJ > nextXI){
                        curTime += Math.abs(nextXJ - curX);

                        curDir = DOWN;
                        curX = nextXJ;
                    } else {
                        curTime += Math.abs(nextXI - curX);

                        curDir = UP;
                        curX = nextXI;
                    }
                } else {
                    int lastColumn = 0;
                    int lastRow = curY - lastColumn;

                    int nextXJ = lastRow - lastColumn + MAX_SIZE;
                    int nextYJ = curY;

                    lastRow = n;
                    lastColumn = curY - lastRow;

                    int nextXI = lastRow - lastColumn + MAX_SIZE;
                    int nextYI = curY;

                    if (nextXJ == nextXI) {
                        break; 

                    } else if (nextXJ < nextXI){
                        curTime += Math.abs(curX - nextXJ);

                        curDir = UP;
                        curX = nextXJ;
                    } else {
                        curTime += Math.abs(curX - nextXI);

                        curDir = DOWN;
                        curX = nextXI;
                    }
                }
            }
        }

        for (long answer : answers) {
            out.println(answer / 2);
        }
        out.println();
    }

    


    private final static boolean FIRST_INPUT_STRING = false;
    private final static boolean MULTIPLE_TESTS = true;
    private final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private final static int MAX_STACK_SIZE = 128;

    private final static boolean OPTIMIZE_READ_NUMBERS = false;

    


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
                    } catch (NumberFormatException e) {
                        break;
                    } catch (NullPointerException e) {
                        if (FIRST_INPUT_STRING) break;
                        else throw e;
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
        new Thread(null, new C(), "", MAX_STACK_SIZE * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (ONLINE_JUDGE){
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new OutputWriter(System.out);
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
        if (ONLINE_JUDGE){
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

    


    private final char NOT_A_SYMBOL = '\0';

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

    private char[][] readCharField(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = readCharArray();
        }

        return field;
    }

    


    private long optimizedReadLong() {
        long result = 0;
        boolean started = false;
        while (true) {
            try {
                int j = in.read();
                if (-1 == j) {
                    if (started) return result;
                    throw new NumberFormatException();
                }

                if ('0' <= j && j <= '9') {
                    result = result * 10 + j - '0';
                    started = true;
                } else if (started) {
                    return result;
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

    


    private int[][] readIntMatrix(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = readIntArray(columnsCount);
        }

        return matrix;
    }

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

    private double[] readDoubleArray(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger readBigInteger() {
        return new BigInteger(readString());
    }

    private BigDecimal readBigDecimal() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] readPointArray(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
        }

        return array;
    }

    


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

    


    private static class IntIndexPair {

        static Comparator<IntIndexPair> increaseComparator = new Comparator<C.IntIndexPair>() {

            @Override
            public int compare(C.IntIndexPair indexPair1, C.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return value1 - value2;

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        static Comparator<IntIndexPair> decreaseComparator = new Comparator<C.IntIndexPair>() {

            @Override
            public int compare(C.IntIndexPair indexPair1, C.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        int value, index;

        IntIndexPair(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int getRealIndex() {
            return index + 1;
        }
    }

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

        void printWithSpace(double d){
            printf(formatWithSpace, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                printWithSpace(d[i]);
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

        
        private static final long serialVersionUID = -6463830523020118289L;

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

    


    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(long a, long b) {
        return (a == 0 ? b : gcd(b % a, a));
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long serialVersionUID = -3793737771950984481L;

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
}

