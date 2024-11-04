import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.List;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class E implements Runnable{

    

    

    

    

    


    @SuppressWarnings("unused")
    private final static Random rnd = new Random();
    private final static String fileName = "";

    private final static int MODULO = 1000 * 1000 * 1000 + 7;

    

    private void solve() {
        int t = readInt();
        while (t --> 0) {
            solveTest();
        }
    }

    static class Group implements Comparable<Group> {

        int[] ages;
        int start;

        long sum;

        public Group(int[] ages, int start) {
            this.ages = ages;
            this.start = start;

            this.sum = 0;
            for (int a : ages) sum += a;
        }

        int size() {
            return ages.length;
        }

        long firstAccepted() {
            return (sum - 1) / ages.length + 1;
        }

        long firstWithout(int i) {
            return (sum - ages[i] - 1) / (ages.length - 1) + 1;
        }

        @Override
        public int compareTo(Group other) {
            return Long.compare(firstAccepted(), other.firstAccepted());
        }
    }

    void solveTest() {
        int teachersCount = readInt();
        int groupsCount = readInt();

        int[] id3 = id2(teachersCount);
        Arrays.sort(id3);

        int[][] id33 = new int[groupsCount][];
        for (int i = 0; i < groupsCount; ++i) {
            id33[i] = id2(readInt());
        }

        Group[] groups = new Group[groupsCount];

        int start = 0;
        for (int i = 0; i < groupsCount; ++i) {
            groups[i] = new Group(id33[i], start);
            start += id33[i].length;
        }

        Arrays.sort(groups);

        String answer = getAnswer(teachersCount, id3.clone(), groupsCount, groups, start);
        out.println(answer);
    }

    final char possible = '1', impossible = '0';

    String getAnswer(int teachersCount, int[] id3, int groupsCount, Group[] groups, int total) {
        char[] answer = new char[total];
        Arrays.fill(answer, impossible);

        int[] matched = new int[groupsCount];
        Arrays.fill(matched, -1);

        List<Integer> failedGroups = new ArrayList<>();
        for (int t = teachersCount - 1, g = groupsCount - 1; g >= 0; --g) {
            if (groups[g].firstAccepted() <= id3[t]) {
                matched[g] = t;
                --t;
            } else {
                failedGroups.add(g);
            }
        }

        int[] leftCant = new int[groupsCount];
        Arrays.fill(leftCant, -1);

        for (int g = 0; g < groupsCount; ++g) {
            if (matched[g] < 1) {
                leftCant[g] = g;
            } else {
                int prevT = id3[matched[g] - 1];
                if (groups[g].firstAccepted() <= prevT) {
                    leftCant[g] = (0 == g ? -1 : leftCant[g - 1]);
                } else {
                    leftCant[g] = g;
                }
            }
        }

        TreeMap<Long, Integer> lowestG = new TreeMap<>();
        for (int g = groupsCount - 1; g >= 0; --g) {
            if (-1 == matched[g]) continue;

            long age = id3[matched[g]];
            lowestG.put(age, g);
        }

        for (long age : id3) {
            if (!lowestG.containsKey(age)) lowestG.put(age, -1);
        }

        if (failedGroups.isEmpty()) {
            for (int g = 0; g < groupsCount; ++g) {
                var group = groups[g];
                for (int i = 0; i < group.size(); ++i) {
                    int index = i + group.start;

                    long curMatched = id3[matched[g]];
                    long newMatched = group.firstWithout(i);

                    if (newMatched <= curMatched) {
                        answer[index] = possible;
                    } else {
                        var e = lowestG.ceilingEntry(newMatched);
                        if (null != e) {
                            int firstG = e.getValue();
                            if (-1 == firstG || leftCant[firstG] <= g) {
                                answer[index] = possible;
                            }
                        }
                    }
                }
            }
        } else if (failedGroups.size() == 1) {
            

            int f = failedGroups.get(0);

            

            var failedGroup = groups[f];
            long id25 = failedGroup.firstAccepted();

            int firstActive = (0 == f ? 1 : 0);

            for (int i = 0; i < failedGroup.size(); ++i) {
                int index = i + failedGroup.start;

                long newMatched = failedGroup.firstWithout(i);

                if (newMatched < id25) {
                    var e = lowestG.ceilingEntry(newMatched);
                    if (null != e) {
                        int firstG = e.getValue();
                        if (firstG < f && (-1 == firstG || leftCant[firstG] < firstActive)) {
                            answer[index] = possible;
                        }
                    }
                }
            }

            

            if (f != groupsCount - 1 && id25 <= id3[matched[f + 1]]) {
                for (int g = f + 1; g < groupsCount; ++g) {
                    var group = groups[g];
                    for (int i = 0; i < group.size(); ++i) {
                        int index = i + group.start;

                        long newMatched = group.firstWithout(i);

                        if (newMatched < id25) {
                            var e = lowestG.ceilingEntry(newMatched);
                            if (null != e) {
                                int firstG = e.getValue();
                                if (firstG < f && (-1 == firstG || leftCant[firstG] < firstActive)) {
                                    answer[index] = possible;
                                }
                            }
                        }
                    }
                }
            }
        }

        return new String(answer);
    }

    String id40(int teachersCount, int[] id3, int groupsCount, Group[] groups, int total) {
        char[] answer = new char[total];
        Arrays.fill(answer, impossible);

        long[] ac = new long[groupsCount];
        for (int g = 0; g < groupsCount; ++g) ac[g] = groups[g].firstAccepted();

        for (int g = 0; g < groupsCount; ++g) {
            var group = groups[g];
            for (int i = 0; i < group.size(); ++i) {
                int index = i + group.start;

                ac[g] = group.firstWithout(i);
                answer[index] = can(id3, ac) ? possible : impossible;
                ac[g] = group.firstAccepted();
            }
        }

        return new String(answer);
    }

    boolean can(int[] up, long[] down) {
        down = down.clone();
        Arrays.sort(down);

        for (int t = up.length - 1, g = down.length - 1; g >= 0; --g, --t) {
            if (up[t] < down[g]) {
                return false;
            }
        }

        return true;
    }

    static final boolean STRESS = false;

    void stress() {
        for (int test = 0; test < 100; ++test) {
            int gc = rnd.nextInt(10) + 1;
            int tc = rnd.nextInt(5) + gc;

            int[] id3 = new int[tc];
            for (int i = 0; i < tc; ++i) id3[i] = rnd.nextInt(10);
            Arrays.sort(id3);

            Group[] groups = new Group[gc];
            int start = 0;
            for (int i = 0; i < gc; ++i) {
                int size = rnd.nextInt(5) + 2;
                int firstAc = rnd.nextInt(tc);

                int[] ages = new int[size];
                Arrays.fill(ages,id3[firstAc]);

                int delta = rnd.nextInt(100);
                for (int it = 0; it < delta; ++it) {
                    int first = rnd.nextInt(size);
                    int second = rnd.nextInt(size);

                    ages[first]--;
                    ages[second]++;
                }

                groups[i] = new Group(ages, start);
                start += size;
            }

            var sortedGroups = groups.clone();
            Arrays.sort(sortedGroups);

            String answer = getAnswer(tc, id3, gc, sortedGroups, start);
            String id14 = id40(tc, id3, gc, sortedGroups, start);

            if (!answer.equals(id14)) {
                System.err.println("GOTCHA!");
                out.println(1);
                out.printlnAll(tc, gc);
                out.printlnAll(id3);
                for (Group group : groups) {
                    out.println(group.size());
                    out.printlnAll(group.ages);
                }

                out.println("===");
                out.println(answer);
                out.println(id14);
                out.println("===");

                break;
            }
        }
    }

    


    private final static boolean id6 = true;
    private final boolean id10 = !new File("input.txt").exists();



    private final static int id17 = 128;

    private final static boolean id28 = false;

    


    @SuppressWarnings("unused")
    private static int inverse(long x) {
        return binpow(x, MODULO - 2);
    }

    private static int binpow(long base, long power) {
        if (power == 0) return 1;
        if ((power & 1) == 0) {
            long half = binpow(base, power >> 1);
            return mult(half, half);
        } else {
            long prev = binpow(base, power - 1);
            return mult(prev, base);
        }
    }

    private static int add(int a, int b) { return (a + b) % MODULO; }

    @SuppressWarnings("unused")
    private static int subtract(int a, int b) { return add(a, MODULO - b % MODULO); }

    private static int mult(long a, long b) { return (int)((a * b) % MODULO); }

    


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

            if (id10) {
                solve();
            } else if (STRESS) {
                stress();
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
        new Thread(null, new E(), "", id17 * (1L << 20)).start();
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

    private String id30() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new RuntimeIOException(e);
        }
    }

    private String readLine() {
        String line = id30();
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
    private char[][] id22(int rowsCount) {
        char[][] field = new char[rowsCount][];
        for (int row = 0; row < rowsCount; ++row) {
            field[row] = id9();
        }

        return field;
    }

    


    private long id21() {
        int sign = 1;
        long result = 0;
        boolean started = false;
        while (true) {
            try {
                in.mark(20);
                int j = in.read();
                if (-1 == j || '\r' == j || '\n' == j || ' ' == j) {
                    if (started) return sign * result;
                    if (-1 == j) throw new NumberFormatException();
                    continue;
                }

                if (j == '-') {
                    if (started) throw new NumberFormatException();
                    sign = -sign;
                }

                if ('0' <= j && j <= '9') {
                    result = result * 10 + j - '0';
                    started = true;
                } else {
                    in.reset();
                    if (started) {
                        return sign * result;
                    } else {
                        throw new NumberFormatException();
                    }
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
            return (int) id21();
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

    private int[] id13(int size) {
        int[] array = id2(size);

        for (int i = 0; i < size; ++i) {
            array[i]--;
        }

        return array;
    }

    


    @SuppressWarnings("unused")
    private int[][] id18(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id2(columnsCount);
        }

        return matrix;
    }

    @SuppressWarnings("unused")
    private int[][] id32(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id13(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id28) {
            return Long.parseLong(readString());
        } else {
            return id21();
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
    private BigInteger id27() {
        return new BigInteger(readString());
    }

    @SuppressWarnings("unused")
    private BigDecimal id23() {
        return new BigDecimal(readString());
    }

    


    private Point readPoint() {
        int x = readInt();
        int y = readInt();
        return new Point(x, y);
    }

    @SuppressWarnings("unused")
    private Point[] id36(int size) {
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
            id24(from, to);
            id24(to, from);
        }

        public void id24(int from, int to) {
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
    private final static int id26 = 0, id15 = 1;

    @SuppressWarnings("unused")
    private int[][] id12(int vertexNumber, int edgesNumber) {
        return id12(vertexNumber, edgesNumber, id15, false);
    }

    private int[][] id12(int vertexNumber, int edgesNumber,
                                        int indexation, boolean directed
    ) {
        GraphBuilder graphBuilder = GraphBuilder.createInstance(vertexNumber);
        for (int i = 0; i < edgesNumber; ++i) {
            int from = readInt() - indexation;
            int to = readInt() - indexation;

            if (directed) graphBuilder.id24(from, to);
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
    private Edge[][] id29(int vertexNumber, int edgesNumber) {
        return id29(vertexNumber, edgesNumber, id15, false);
    }

    private Edge[][] id29(int vertexNumber, int edgesNumber,
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

    


    private static class id31 {

        @SuppressWarnings("unused")
        static Comparator<id31> increaseComparator = (indexPair1, indexPair2) -> {
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
        static Comparator<id31> id1 = (indexPair1, indexPair2) -> {
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
        static id31[] from(int[] array) {
            id31[] iip = new id31[array.length];
            for (int i = 0; i < array.length; ++i) {
                iip[i] = new id31(array[i], i);
            }

            return iip;
        }

        int value, index;

        id31(int value, int index) {
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
    private id31[] id4(int size) {
        id31[] array = new id31[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id31(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id39 = 12;

        private int precision;
        private String format, id38;

        {
            precision = id39;

            format = createFormat(precision);
            id38 = format + " ";
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
            id38 = format + " ";
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

        void id34(double d){
            printf(id38, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id34(d[i]);
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

        
        private static final long id35 = -6463830523020118289L;

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
    private static int[] id20(int n) {
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
    int[] id37(int value) {
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
    long[] id37(long value) {
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