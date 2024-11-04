import java.awt.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.List;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class E implements Runnable{

    private final static Random rnd = new Random();

    

    

    

    

    


    class Trie {

        Node root = new Node();

        class Node {
            char letter;
            Node link;

            Node parent;

            List<Node> go;
            List<Node> childs;

            int index;

            Node() {
                this.letter = 0;
                this.childs = null;
                this.go = null;
                this.index = -1;
            }

            Node getChild(char letter) {
                if (childs == null) childs = new ArrayList<>(1);

                for (Node child : childs) {
                    if (child.letter == letter) {
                        return child;
                    }
                }

                return null;
            }

            Node(Node parent, char letter) {
                this();
                this.parent = parent;
                this.letter = letter;
            }
        }

        void addWord(char[] word, int index) {
            Node cur = root;
            for (char letter : word) {
                Node child = cur.getChild(letter);
                if (child == null) {
                    child = new Node(cur, letter);
                    cur.childs.add(child);
                }

                cur = child;
            }

            cur.index = index;
        }

        Node getLink(Node cur) {
            if (cur.link != null) return cur.link;

            if (cur.parent == null || cur.parent == root) {
                return cur.link = root;
            }

            return cur.link = go(getLink(cur.parent), cur.letter);
        }

        Node go(Node cur, char letter) {
            if (cur.go == null) {
                if (cur.childs != null) {
                    cur.go = new ArrayList<>(cur.childs);
                } else {
                    cur.go = new ArrayList<>(1);
                }
            }

            Node next = null;
            for (Node node : cur.go) {
                if (node.letter == letter) {
                    next = node;
                    break;
                }
            }

            if (next == null) {
                if (cur == root) {
                    next = root;
                } else {
                    next = go(getLink(cur), letter);
                    if (next != null && next != root) {
                        cur.go.add(next);
                    }
                }
            }

            return next;
        }
    }

    private void solve() {
        int n = readInt();
        int k = readInt();

        String input = readLine();
        char[] disk = (input + input).toCharArray();
        int length = n * k;

        Trie trie = new Trie();

        int words = readInt();
        for (int i = 0; i < words; ++i) {
            char[] word = id8();

            trie.addWord(word, i);
        }

        int[] indexes = new int[length + length];

        Trie.Node cur = trie.root;
        for (int i = 0; i < k - 1; ++i) {
            cur = trie.go(cur, disk[i]);
        }

        for (int i = k - 1; i < disk.length; ++i) {
            cur = trie.go(cur, disk[i]);
            indexes[i] = cur.index;
        }

        Set<Integer>[] games = new Set[k];
        for (int i = 0; i < k; ++i) {
            games[i] = new HashSet<>();
        }

        for (int i = k - 1; i < length + k - 1; ++i) {
            if (indexes[i] == -1) continue;
            games[(i - k + 1) % k].add(indexes[i]);
        }

        List<Integer> answer = null;
        for (int start = 0; start < k; ++start) {
            if (games[start].size() == n) {
                answer = new ArrayList<>();
                for (int i = 0, end = start + k - 1; i < n; ++i, end += k) {
                    answer.add(indexes[end]);
                }
                break;
            }
        }

        if (answer == null) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int game : answer) {
                out.print((game + 1) + " ");
            }
            out.println();
        }
    }

    


    private final static boolean id2 = false;
    private final static boolean id5 = true;
    private final boolean id9 = System.getProperty("id9") != null;

    private final static int id14 = 128;

    private final static boolean id23 = false;

    


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
        new Thread(null, new E(), "", id14 * (1L << 20)).start();
    }

    


    private void init() throws FileNotFoundException{
        Locale.setDefault(Locale.US);

        if (id9){
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

        if (!id23) {
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

    private int[][] id25(int rowsCount, int columnsCount) {
        int[][] matrix = new int[rowsCount][];

        for (int rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
            matrix[rowIndex] = id11(columnsCount);
        }

        return matrix;
    }

    


    private long readLong() {
        if (!id23) {
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

    


    private BigInteger id22() {
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

    private Point[] id28(int size) {
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

    


    private static class id24 {

        static Comparator<id24> increaseComparator = new Comparator<E.id24>() {

            @Override
            public int compare(E.id24 id19, E.id24 id13) {
                int value1 = id19.value;
                int value2 = id13.value;

                if (value1 != value2) return value1 - value2;

                int index1 = id19.index;
                int index2 = id13.index;

                return index1 - index2;
            }
        };

        static Comparator<id24> id0 = new Comparator<E.id24>() {

            @Override
            public int compare(E.id24 id19, E.id24 id13) {
                int value1 = id19.value;
                int value2 = id13.value;

                if (value1 != value2) return -(value1 - value2);

                int index1 = id19.index;
                int index2 = id13.index;

                return index1 - index2;
            }
        };

        int value, index;

        id24(int value, int index) {
            super();
            this.value = value;
            this.index = index;
        }

        int id6() {
            return index + 1;
        }
    }

    private id24[] id3(int size) {
        id24[] array = new id24[size];

        for (int index = 0; index < size; ++index) {
            array[index] = new id24(readInt(), index);
        }

        return array;
    }

    


    private static class OutputWriter extends PrintWriter {

        final int id30 = 12;

        private int precision;
        private String format, id29;

        {
            precision = id30;

            format = createFormat(precision);
            id29 = format + " ";
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
            id29 = format + " ";
        }

        String createFormat(int precision){
            return "%." + precision + "f";
        }

        @Override
        public void print(double d){
            printf(format, d);
        }

        void id26(double d){
            printf(id29, d);
        }

        void printAll(double...d){
            for (int i = 0; i < d.length - 1; ++i){
                id26(d[i]);
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

        
        private static final long id27 = -6463830523020118289L;

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

    private static Point id15(int[] array) {
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

    


    private static class IdMap<KeyType> extends HashMap<KeyType, Integer> {

        
        private static final long id27 = -3793737771950984481L;

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

