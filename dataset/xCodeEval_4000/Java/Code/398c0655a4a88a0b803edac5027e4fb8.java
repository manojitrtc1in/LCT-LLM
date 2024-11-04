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

    

    

    

    

    


    int n;

    private void solve() {
        this.query = 0;

        this.n = readInt();

        int left1 = 0;

        int l = 1, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(m, 1, n, n);

            if (answer < 2) {
                r = m - 1;
            } else {
                left1 = m;
                l = m + 1;
            }
        }

        int left2 = left1;

        l = left1 + 1;
        r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(m, 1, n, n);

            if (answer < 1) {
                r = m - 1;
            } else {
                left2 = m;
                l = m + 1;
            }
        }

        int right2 = n + 1;

        l = 1;
        r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(1, 1, m, n);

            if (answer < 2) {
                l = m + 1;
            } else {
                right2 = m;
                r = m - 1;
            }
        }

        int right1 = right2;

        l = 1;
        r = right2 - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(1, 1, m, n);

            if (answer < 1) {
                l = m + 1;
            } else {
                right1 = m;
                r = m - 1;
            }
        }

        int bottom1 = 0;

        l = 1;
        r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(1, m, n, n);

            if (answer < 2) {
                r = m - 1;
            } else {
                bottom1 = m;
                l = m + 1;
            }
        }

        int bottom2 = bottom1;

        l = bottom1 + 1;
        r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(1, m, n, n);

            if (answer < 1) {
                r = m - 1;
            } else {
                bottom2 = m;
                l = m + 1;
            }
        }

        int top2 = n + 1;

        l = 1;
        r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(1, 1, n, m);

            if (answer < 2) {
                l = m + 1;
            } else {
                top2 = m;
                r = m - 1;
            }
        }

        int top1 = top2;

        l = 1;
        r = top2 - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int answer = getAnswer(1, 1, n, m);

            if (answer < 1) {
                l = m + 1;
            } else {
                top1 = m;
                r = m - 1;
            }
        }

        int ansLeftRightMask = -1, ansBottomTopMask = -1;
        long answerS = 2L * n * n;

        for (int leftRightMask = 0; leftRightMask < 4; ++leftRightMask) {
            int left = (checkBit(leftRightMask, 0) ? left1 : left2);
            int right = (checkBit(leftRightMask, 1) ? right1 : right2);

            for (int bottomTopMask = 0; bottomTopMask < 4; ++bottomTopMask) {
                int bottom = (checkBit(bottomTopMask, 0) ? bottom1 : bottom2);
                int top = (checkBit(bottomTopMask, 1) ? top1 : top2);

                int curTry = getAnswer(left, bottom, right, top);
                if (curTry == 1) {
                    long s = (right - left + 1L) * (top - bottom + 1L);
                    if (s < answerS) {
                        answerS = s;
                        ansLeftRightMask = leftRightMask;
                        ansBottomTopMask = bottomTopMask;
                    }
                }
            }
        }

        int left = (checkBit(ansLeftRightMask, 0) ? left1 : left2);
        int right = (checkBit(ansLeftRightMask, 1) ? right1 : right2);
        int bottom = (checkBit(ansBottomTopMask, 0) ? bottom1 : bottom2);
        int top = (checkBit(ansBottomTopMask, 1) ? top1 : top2);

        printAnswer(left, bottom, right, top,
                left1 + left2 - left, bottom1 + bottom2 - bottom,
                right1 + right2 - right, top1 + top2 - top);
    }

    private void printAnswer(int... values) {
        printQuery("!", values);
    }

    private void printQuery(String sign, int... values) {
        out.print(sign);
        for (int value : values) {
            out.print(" " + value);
        }
        out.println();
        out.flush();
    }

    int query = 0;
    final int MAX_QUERY = 200;

    private int getAnswer(int left, int bottom, int right, int top) {
        if (left < 1 || right > n) {
            while (true);
        }

        if (bottom < 1 || top > n) {
            throw new RuntimeException();
        }

        if (left > right || bottom > top) {
            return 0;
        }

        if (query == MAX_QUERY) {
            throw new RuntimeException();
        }

        ++query;

        printQuery("?",  left, bottom, right, top);

        int answer = readInt();
        return answer;
    }

    


    private final static boolean FIRST_INPUT_STRING = false;
    private final static boolean MULTIPLE_TESTS = true;
    private final static boolean INTERACTIVE = true;
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
        new Thread(null, new B(), "", MAX_STACK_SIZE * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (INTERACTIVE || ONLINE_JUDGE){
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

        static Comparator<IntIndexPair> increaseComparator = new Comparator<B.IntIndexPair>() {

            @Override
            public int compare(B.IntIndexPair indexPair1, B.IntIndexPair indexPair2) {
                int value1 = indexPair1.value;
                int value2 = indexPair2.value;

                if (value1 != value2) return value1 - value2;

                int index1 = indexPair1.index;
                int index2 = indexPair2.index;

                return index1 - index2;
            }
        };

        static Comparator<IntIndexPair> decreaseComparator = new Comparator<B.IntIndexPair>() {

            @Override
            public int compare(B.IntIndexPair indexPair1, B.IntIndexPair indexPair2) {
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

