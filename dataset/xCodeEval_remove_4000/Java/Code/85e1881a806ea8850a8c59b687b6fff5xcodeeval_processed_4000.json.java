import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;

public class Main implements Runnable{

    

    

    

    

    


    private final static Random rnd = new Random();
    private final static String fileName = "";
    
    static class Point {
        int x, y;
        int index;
        
        Point(int x, int y) {
            this.x = x;
            this.y = y;
            this.index = -1;
        }
    }

    private void solve() {
        int k = readInt();
        Point[] specials = new Point[k];
        for (int i = 0; i < k; ++i) {
            specials[i] = new Point(i, readInt());
            specials[i].index = i;
        }
        
        Mapper xMapper = new Mapper(k);
        Mapper yMapper = new Mapper(k);
        
        for (Point special : specials) {
            xMapper.add(special.x);
            yMapper.add(special.y);
        }
        
        for (Point p : xMapper.build()) {
            specials[p.y].x = p.index;   
        }
        
        for (Point p : yMapper.build()) {
            specials[p.y].y = p.index;
        }
        
        int xSize = xMapper.size(), ySize = yMapper.size();
        
        id34 dp = new id34(ySize);
        Arrays.sort(specials, new Comparator<Point>() {
           
           @Override
           public int compare(Point p1, Point p2) {
               if (p1.x != p2.x) return p1.x - p2.x;
               return p1.y - p2.y;
           }
        });
        
        int[] dpArray = new int[k];
        for (Point special : specials) {
            int maxWay = dp.get(special.y - 1);
            int dpValue = dpArray[special.index] = maxWay + 1;
            dp.update(special.y, dpValue);
        }
        
        id34 reverseDp = new id34(ySize);
        
        for (Point special : specials) {
            special.x = xSize - 1 - special.x;
            special.y = ySize - 1 - special.y;
        }
        
        Arrays.sort(specials, new Comparator<Point>() {
           
           @Override
           public int compare(Point p1, Point p2) {
               if (p1.x != p2.x) return p1.x - p2.x;
               return p1.y - p2.y;
           }
        });
        
        int[] id31 = new int[k];
        for (Point special : specials) {
            int maxWay = reverseDp.get(special.y - 1);
            int dpValue = id31[special.index] = maxWay + 1;
            reverseDp.update(special.y, dpValue);
        }
        
        int maxWay = 0;
        for (int i = 0; i < k; ++i) {
            maxWay = max(maxWay, dpArray[i] + id31[i]);
        }
        
        int[] counts = new int[k + 1];
        for (int i = 0; i < k; ++i) {
            if (dpArray[i] + id31[i] == maxWay) {
                counts[dpArray[i]]++;
            }
        }
        
        int[] answers = new int[k];
        for (int i = 0; i < k; ++i) {
            if (dpArray[i] + id31[i] == maxWay) {
                if (counts[dpArray[i]] == 1) answers[i] = 3;
                else answers[i] = 2;
            } else {
                answers[i] = 1;
            }
        }
        
        for (int answer : answers) {
            out.print(answer);
        }
        out.println();
    }
    
    class id34 {
        
        int size;
        int[] tree;
        
        id34(int size) {
            this.size = size;
            this.tree = new int[size];
        }
        
        void update(int index, int value) {
            for (; index < size; index |= (index + 1)) {
                tree[index] = max(tree[index], value);
            }
        }
        
        int get(int index) {
            int result = 0;
            for (; index >= 0; index &= (index + 1), --index) {
                result = max(result, tree[index]);     
            }
            
            return result;
        }
    }
    
    class Mapper {
        
        Point[] values;
        int index;
        
        Mapper(int size) {
            this.values = new Point[size];
            this.index = 0;
        }
        
        void add(int value) {
            values[index] = new Point(value, index);
            ++index;
        }
        
        Point[] build() {
            Arrays.sort(values, new Comparator<Point>() {
                public int compare(Point p1, Point p2) {
                    return p1.x - p2.x;
                }
            });
            
            for (int i = 0, index = 0; i < values.length; ++i) {
                if (i > 0 && values[i - 1].x != values[i].x) {
                    ++index;
                }
                
                values[i].index = index;
            }
            
            return values;
        }
        
        int size() {
            return index + 1;
        }
    }

    


    private final static boolean id2 = false;
    private final static boolean id5 = false;
    private final boolean id9 = System.getProperty("id9") != null;

    private final static int id14 = 128;

    private final static boolean id24 = true;

    


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
        new Thread(null, new Main(), "", id14 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new OutputWriter(System.out);
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

    


    private int[][] id15(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id1(columnsCount);
        }

        return matrix;
    }

    private int[][] id26(int rowsCount, int columnsCount) {
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

    private Point[] id29(int size) {
        Point[] array = new Point[size];

        for (int index = 0; index < size; ++index){
            array[index] = readPoint();
            array[index].index = index;
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

    


    private static class id25 {

        static Comparator<id25> increaseComparator = new Comparator<id25>() {

            @Override
            public int compare(id25 id19, id25 id13) {
                int value1 = id19.value;
                int value2 = id13.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id19.index;
                int index2 = id13.index;

                return index1 - index2;
            }
        };

        static Comparator<id25> id0 = new Comparator<id25>() {

            @Override
            public int compare(id25 id19, id25 id13) {
                int value1 = id19.value;
                int value2 = id13.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id19.index;
                int index2 = id13.index;

                return index1 - index2;
            }
        };

        static id25[] from(int[] array) {
            id25[] iip = new id25[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id25(array[i], i);
            }

            return iip;
        }

        int value, index;

        id25(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id6() {
            return index + 1;
        }
    }

    private id25[] id3(int size) {
        id25[] array = new id25[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id25(readInt(), index);
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

        void id27(double d){
            printf(id32, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id27(d[i]);
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

        
        private static final long id28 = -6463830523020118289L;

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

        public static <ValueType> MultiSet<ValueType> id30() {
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

        
        private static final long id28 = -3793737771950984481L;

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

