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

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";
    
    private final static long MODULO = 1000 * 1000 * 1000 + 7;

    final int id69 = 10;

    private void solve1() {
        for (int it = 0; it < 10; ++it) {
            int need = rnd.nextInt(10000) + 1;
            long maxTime = rnd.nextInt(10000000) + 1;
            long id45 = rnd.nextInt(10) + 1;

            int id43 = rnd.nextInt(100) + 1;
            long id16 = rnd.nextInt(10) + 1;
            long id77 = rnd.nextInt(10) + 1;

            int id7 = rnd.nextInt(100) + 1;
            long id90 = rnd.nextInt(10) + 1;
            long id51 = rnd.nextInt(10) + 1;

            long[] answer = getAnswer(need, maxTime, id45,
                    id43, id16, id77,
                    id7, id90, id51);

            long[] id59 = id52(need, maxTime, id45,
                    id43, id16, id77,
                    id7, id90, id51);

            if (answer[0] != id59[0]) {
                System.err.println("GOTCHA");

                System.err.println(Arrays.toString(answer));
                System.err.println(Arrays.toString(id59));
                System.err.println(need + " " + maxTime + " " +id16);
                System.err.println(id43 + " " + id16 + " " +id77);
                System.err.println(id7 + " " + id90 + " " +id51);
            }
        }
    }

    private void solve() {
        long need = readInt();
        long maxTime = readInt();
        long id45 = readInt();

        long id43 = readInt();
        long id16 = readInt();
        long id77 = readInt();

        long id7 = readInt();
        long id90 = readInt();
        long id51 = readInt();






























































        long[] answer = getAnswer(need, maxTime, id45,
                id43, id16, id77,
                id7, id90, id51
        );

        out.println(answer[0]);
    }

    long[] getAnswer(long need, long maxTime, long id45,
                     long id43,long id16,long id77,
                     long id7,long id90,long id51) {
        long answer = Long.MAX_VALUE;
        long firstOptimal = 0, secondOptimal = 0;
        
        for (long firstCount = 0, firstSize = 0, firstTime = 0, firstCost = 0; ;
             ++firstCount, firstSize += id43,
            firstCost += id77,
                     firstTime += id16 * id43) {

            if (firstSize >= need) {
                firstSize = need;
                firstTime = id16 * firstSize;
            }

            long id42 = maxTime - firstTime;
            long id74 = need - firstSize;
            if (id42 >= 0) {
                if (id45 <= id90) {
                    long freeTime = id45 * id74;
                    if (freeTime + firstTime <= maxTime) {
                        if (answer > firstCost) {
                            answer = firstCost;
                            firstOptimal = firstCount;
                            secondOptimal = 0;
                        }
                    }
                } else {
                    long id68 = id74 / id7;
                    long id63 = id7 * id68;
                    long id50 = id74 - id63;

                    long id81 = id63 * id90;
                    long id15 = id50 * id45;

                    if (id81 + id15 <= id42) {

                        if (answer > firstCost + id68 * id51) {
                            answer = firstCost + id68 * id51;
                            firstOptimal = firstCount;
                            secondOptimal = id68;
                        }
                    }

                    long id41 = id74 / id7;
                    if (id74 % id7 != 0) ++id41;
                    long id80 = min(id74, id7 * id41);
                    long id21 = id74 - id80;

                    long id97 = id80 * id90;
                    long id98 = id21 * id45;

                    if (id97 + id98 <= id42) {
                        if (answer > firstCost + id41 * id51) {
                            answer = firstCost + id41 * id51;
                            firstOptimal = firstCount;
                            secondOptimal = id41;
                        }

                        long id31 = ((id74 * id45 - id42));
                        long id96 = (id45 - id90) * id7;


                        long id14 = id31 / id96;
                        if (id31 < 0) id14 = 0;
                        else if (id31 % id96 != 0) {
                            id14++;
                        }
                        if (id14 >= 0) {
                            long id29 = min(id74, id7 * id14);
                            long id38 = id74 - id29;

                            long id48 = id29 * id90;
                            long id70 = id38 * id45;

                            if (id48 + id70 <= id42) {

                                if (answer > firstCost + id14 * id51) {
                                    answer = firstCost + id14 * id51;
                                    firstOptimal = firstCount;
                                    secondOptimal = id14;
                                }
                            }
                        }
                    }


                }
            }

            if (firstSize >= need) break;
        }
        
        for (long secondCount = 0, secondSize = 0, secondCost = 0, secondTime = 0; ;
             ++secondCount, secondSize += id7,
                     secondCost += id51,
                     secondTime += id90 * id7) {

            if (secondSize >= need) {
                secondSize = need;
                secondTime = id90 * secondSize;
            }

            long id42 = maxTime - secondTime;
            long id74 = need - secondSize;
            if (id42 >= 0) {
                if (id45 <= id16) {
                    long freeTime = id45 * id74;
                    if (freeTime + secondTime <= maxTime) {
                        if (answer > secondCost) {
                            answer = secondCost;
                            secondOptimal = secondCount;
                            firstOptimal = 0;
                        }
                    }
                } else {
                    long id68 = id74 / id43;
                    long id79 = id43 * id68;
                    long id50 = id74 - id79;

                    long id23 = id79 * id16;
                    long id15 = id50 * id45;

                    if (id23 + id15 <= id42) {

                        if (answer > secondCost + id68 * id77) {
                            answer = secondCost + id68 * id77;
                            secondOptimal = secondCount;
                            firstOptimal = id68;
                        }
                    }

                    long id41 = id74 / id43;
                    if (id74 % id43 != 0) ++id41;
                    long id39 = min(id74, id43 * id41);
                    long id21 = id74 - id39;

                    long id83 = id39 * id16;
                    long id98 = id21 * id45;

                    if (id83 + id98 <= id42) {
                        if (answer > secondCost + id41 * id77) {
                            answer = secondCost + id41 * id77;
                            secondOptimal = secondCount;
                            firstOptimal = id41;
                        }

                        long id31 = ((id74 * id45 - id42));
                        long id96 = (id45 - id16) * id43;


                        long id14 = id31 / id96;
                        if (id31 < 0) id14 = 0;
                        else if (id31 % id96 != 0) {
                            id14++;
                        }
                        if (id14 >= 0) {
                            long id86 = min(id74, id43 * id14);
                            long id38 = id74 - id86;

                            long id92 = id86 * id16;
                            long id70 = id38 * id45;

                            if (id92 + id70 <= id42) {

                                if (answer > secondCost + id14 * id77) {
                                    answer = secondCost + id14 * id77;
                                    secondOptimal = secondCount;
                                    firstOptimal = id14;
                                }
                            }
                        }
                    }


                }
            }

            if (secondSize >= need) break;
        }

        if (answer == Long.MAX_VALUE) {
            answer = -1;
        }

        return new long[] { answer, firstOptimal, secondOptimal };
    }

    long[] id52(int need, long maxTime, long id45,
                        int id43,long id16,long id77,
                        int id7,long id90,long id51) {
        long answer = Long.MAX_VALUE;
        long firstOptimal = 0, secondOptimal = 0;

        for (int firstCount = 0; ; ++firstCount) {
            int firstSize = min(need, firstCount * id43);
            if (firstSize >= need) firstSize = need;

            long firstTime = firstSize * id16;
            long firstCost = firstCount * id77;

            int id74 = (need - firstSize);
            for (int secondCount = 0; ; ++secondCount) {
                int secondSize = min(id74, secondCount * id7);
                if (secondSize >= id74) secondSize = id74;

                long secondTime = secondSize * id90;
                long secondCost = secondCount * id51;

                int freeSize = id74 - secondSize;
                long freeTime = freeSize * id45;

                if (firstTime + secondTime + freeTime <= maxTime) {
                    if (answer > firstCost + secondCost) {
                        answer = firstCost + secondCost;
                        firstOptimal = firstCount;
                        secondOptimal = secondCount;
                    }
                }

                if (secondSize >= id74) break;
            }

            if (firstSize >= need) break;
        }

        if (answer == Long.MAX_VALUE) {
            answer = -1;
        }

        return new long[] { answer, firstOptimal, secondOptimal };
    }

    


    private static long add(long a, long b) { return (a + b) % MODULO; }
    private static long subtract(long a, long b) { return add(a, MODULO - b) % MODULO; }
    private static long mult(long a, long b) { return (a * b) % MODULO; }

    


    private final static boolean id53 = false;
    private final static boolean id3 = false;
    private final boolean id36 = !new File("input.txt").exists();



    private final static int id87 = 128;

    private final static boolean id18 = false;

    


    public void run(){
        try{
            timeInit();
            Locale.setDefault(Locale.US);

            init();

            if (id36) {
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
                        if (id53) break;
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
        new Thread(null, new C(), "", id87 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id36){
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
        if (id36){
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

    


    private final char id78 = '\0';

    private char readChar() {
        try {
            int intValue = in.read();

            if (intValue == -1){
                return id78;
            }

            return (char) intValue;
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private char[] id5() {
        return readLine().toCharArray();
    }

    private char[][] id94(int rowsCount) {
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

        if (!id18) {
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

    private int[] id8(int size) {
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

    private int[] id58(int size) {
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

    private int[][] id71(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id58(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id18) {
            return Long.parseLong(readString());
        } else {
            return id13();
        }
    }

    private long[] id10(int size) {
        long[] array = new long[size];

        for (int index = 0; index < size; ++index){
            array[index] = readLong();
        }

        return array;
    }

    


    private double readDouble() {
        return Double.parseDouble(readString());
    }

    private double[] id54(int size) {
        double[] array = new double[size];

        for (int index = 0; index < size; ++index){
            array[index] = readDouble();
        }

        return array;
    }

    


    private BigInteger id17() {
        return new BigInteger(readString());
    }

    private BigDecimal id66() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    private Point[] id73(int size) {
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
            id67(from, to);
            id67(to, from);
        }

        public void id67(int from, int to) {
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

    private final static int id46 = 0, id84 = 1;

    private int[][] id9(int vertexNumber, int edgesNumber) {
        return id9(vertexNumber, edgesNumber, id84, false);
    }

    private int[][] id9(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id67(from, to);
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

    private Edge[][] id19(int vertexNumber, int edgesNumber) {
        return id19(vertexNumber, edgesNumber, id84, false);
    }

    private Edge[][] id19(int vertexNumber, int edgesNumber,
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

    


    private static class id47 {

        static Comparator<id47> increaseComparator = new Comparator<C.id47>() {

            @Override
            public int compare(C.id47 id62, C.id47 id85) {
                int value1 = id62.value;
                int value2 = id85.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id62.index;
                int index2 = id85.index;

                return index1 - index2;
            }
        };

        static Comparator<id47> id32 = new Comparator<C.id47>() {

            @Override
            public int compare(C.id47 id62, C.id47 id85) {
                int value1 = id62.value;
                int value2 = id85.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id62.index;
                int index2 = id85.index;

                return index1 - index2;
            }
        };

        static id47[] from(int[] array) {
            id47[] iip = new id47[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id47(array[i], i);
            }

            return iip;
        }

        int value, index;

        id47(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id55() {
            return index + 1;
        }
    }

    private id47[] id34(int size) {
        id47[] array = new id47[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id47(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id103 = 12;

        private int precision;
        private String format, id102;

        {
            precision = id103;

            format = createFormat(precision);
            id102 = format + " ";
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
            id102 = format + " ";
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

        void id99(double d){
            printf(id102, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id99(d[i]);
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

        
        private static final long id72 = -6463830523020118289L;

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

    private static Point id88(int[] array) {
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

    


    private static int[] id61(int n) {
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

    


    int[] id24(int value) {
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

    private static abstract class id40
            <ValueType, MapType extends Map<ValueType, Integer>>
            implements MultiSet<ValueType> {

        protected final MapType map;
        protected int size;

        protected id40(MapType map) {
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

    private static class id22<ValueType>
            extends id40<ValueType, Map<ValueType, Integer>> {

        public static <ValueType> MultiSet<ValueType> id25() {
            Map<ValueType, Integer> map = new HashMap<ValueType, Integer>();
            return new id22<ValueType>(map);
        }

        id22(Map<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private interface id44<ValueType> extends MultiSet<ValueType> {

        ValueType min();
        ValueType max();

        ValueType pollMin();
        ValueType pollMax();

        ValueType lower(ValueType value);
        ValueType floor(ValueType value);

        ValueType ceiling(ValueType value);
        ValueType higher(ValueType value);
    }

    private static abstract class id82<ValueType>
            extends id40<ValueType, NavigableMap<ValueType, Integer>>
            implements id44<ValueType> {

        id82(NavigableMap<ValueType, Integer> map) {
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

    private static class id27<ValueType>
            extends id82<ValueType> {

        public static <ValueType> id44<ValueType> id25() {
            NavigableMap<ValueType, Integer> map = new TreeMap<ValueType, Integer>();
            return new id27<ValueType>(map);
        }

        id27(NavigableMap<ValueType, Integer> map) {
            super(map);
        }
    }

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id72 = -3793737771950984481L;

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

    


    private static class id91<ValueType extends Comparable<ValueType>> {

        private List<ValueType> values;

        public id91() {
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

        private static final int MAX_BIT = 17;

        int n;
        int[] array;

        SparseTable(int[] array) {
            this.n = array.length;
            this.array = array;
        }

        int[] id89;
        int[][] table;

        int id57(int leftIndex, int rightIndex) {
            return (array[leftIndex] <= array[rightIndex])
                    ? leftIndex
                    : rightIndex;
        }

        SparseTable build() {
            this.id89 = new int[n + 1];
            id89[0] = 0;
            for (int i = 1; i <= n; ++i) {
                id89[i] = id89[i - 1];
                int length = (1 << id89[i]);
                if (length + length <= i) ++id89[i];
            }

            this.table = new int[MAX_BIT][n];
            table[0] = castInt(order(n));

            for (int bit = 0; bit < MAX_BIT - 1; ++bit) {
                for (int i = 0, j = (1 << bit); j < n; ++i, ++j) {
                    table[bit + 1][i] = id57(
                            table[bit][i], table[bit][j]
                    );
                }
            }

            return this;
        }

        @Override
        public int id6(int left, int right) {
            int length = (right - left + 1);

            int bit = id89[length];
            int segmentLength = (1 << bit);

            return id57(
                    table[bit][left], table[bit][right - segmentLength + 1]
            );
        }

        @Override
        public int getMin(int left, int right) {
            return array[id6(left, right)];
        }
    }

    private static Rmq id100(int[] array) {
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

            int[] id26 = new int[n + n];
            for (int i = 0; i < order.length; ++i) {
                id26[i] = heights[order[i]];
            }

            this.rmq = id100(id26);
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

    private static class id64 implements Lca {

        private static final int MAX_BIT = 20;

        int n;
        int[][] graph;

        int[] h;
        int[][] parents;

        id64(int[][] graph) {
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

    private static Lca id20(int[][] graph, int root) {
        return new id11(graph).build(root);
    }

    


    private static class id75 {

        int n;
        int[][] graph;

        id75(int[][] graph) {
            this.n = graph.length;
            this.graph = graph;
        }

        int time;
        int[] tin, up;

        boolean[] used;

        id75 build() {
            calculateTimes();
            id93();

            return this;
        }

        void calculateTimes() {
            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            this.used = new boolean[n];
            id76(0, -1);
        }

        void id76(int from, int parent) {
            used[from] = true;

            up[from] = tin[from] = time;
            ++time;

            for (int to : graph[from]) {
                if (to == parent) continue;

                if (used[to]) {
                    up[from] = min(up[from], tin[to]);
                } else {
                    id76(to, from);
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

        void id93() {
            this.components = new int[n];
            Arrays.fill(components, -1);

            for (int v = 0; v < n; ++v) {
                if (components[v] == -1) {
                    id49(v, v);
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
                    if (edges.add(edge)) graphBuilder.id67(fromComponent, toComponent);
                }
            }

            this.componentsGraph = graphBuilder.build();
        }

        void id49(int from, int color) {
            components[from] = color;
            for (int to : graph[from]) {
                if (components[to] != -1) continue;

                if (tin[from] >= up[to] && tin[to] >= up[from]) {
                    id49(to, color);
                }
            }
        }
    }

    


    private static class id37 {

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

        id37(int n) {
            this.n = n;
            this.m = 0;

            this.graph = new List[n];
            for (int v = 0; v < n; ++v) {
                graph[v] = new ArrayList<Edge>();
            }

            this.edges = new ArrayList<Edge>();
        }

        void addEdge(int from, int to) {
            Edge id30 = new Edge(to, m);
            Edge id65 = new Edge(from, m + 1);

            edges.add(id30);
            edges.add(id65);

            graph[from].add(id30);
            graph[to].add(id65);

            m += 2;
        }

        int time;

        boolean[] used;
        int[] tin, up;
        int[] parents;

        boolean[] id35;

        boolean[] id33() {
            this.id35 = new boolean[n];

            this.used = new boolean[n];
            this.parents = new int[n];
            Arrays.fill(parents, -1);

            this.tin = new int[n];
            this.up = new int[n];

            this.time = 0;

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    id56(v, -1);
                }
            }

            return id35;
        }

        void id56(int from, int parent) {
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

                    id56(to, from);
                    up[from] = min(up[from], up[to]);
                    if (up[to] >= tin[from] && parent != -1) {
                        id35[from] = true;
                    }
                }
            }

            if (parent == -1 && childrenCount > 1) {
                id35[from] = true;
            }
        }

        int[] edgeColors;
        int id95;

        int[] paintEdges() {
            this.edgeColors = new int[m];
            Arrays.fill(edgeColors, -1);

            this.id95 = -1;

            this.used = new boolean[n];

            for (int v = 0; v < n; ++v) {
                if (!used[v]) {
                    ++id95;
                    id28(v, id95, -1);
                }
            }

            return edgeColors;
        }

        void paintEdge(int edgeIndex, int color) {
            if (edgeColors[edgeIndex] != -1) return;

            edgeColors[edgeIndex] = edgeColors[edgeIndex ^ 1] = color;
        }

        void id28(int from, int color, int parent) {
            used[from] = true;

            for (Edge e : graph[from]) {
                int to = e.to;
                if (to == parent) continue;

                if (!used[to]) {
                    if (up[to] >= tin[from]) {
                        int newColor = ++id95;
                        paintEdge(e.index, newColor);
                        id28(to, newColor, from);
                    } else {
                        paintEdge(e.index, color);
                        id28(to, color, from);
                    }
                } else if (up[to] <= tin[from]){
                    paintEdge(e.index, color);
                }
            }
        }

        Set<Integer>[] id60() {
            Set<Integer>[] id101 = new Set[n];
            for (int v = 0; v < n; ++v) {
                id101[v] = new HashSet<Integer>();
                for (Edge e : graph[v]) {
                    id101[v].add(edgeColors[e.index]);
                }
            }

            return id101;
        }

        id37 build() {
            id33();
            paintEdges();
            id2();

            return this;
        }

        int[][] componentsGraph;

        void id2() {
            Set<Integer>[] id101 = id60();

            int id4 = id101.length;
            int size = id101.length + id95 + 1;

            GraphBuilder graphBuilder = GraphBuilder.createInstance(size);
            for (int v = 0; v < id101.length; ++v) {
                for (int edgeColor : id101[v]) {
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

    

}