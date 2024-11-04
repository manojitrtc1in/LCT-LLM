import java.io.*;
import java.util.*;


public class TemplateFast {

    int[] from = new int[20_000];
    int[] to = new int[20_000];

    private void solveOne() {
        int n = nextInt();

        int m1 = nextInt();
        int m2 = nextInt();
        id2 setA = new id2(n);
        for (int qq = 0; qq < m1; qq++) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            setA.union(u, v);
        }
        id2 setB = new id2(n);
        for (int qq = 0; qq < m2; qq++) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            setB.union(u, v);
        }


        

        Map<Integer, id25> id4 = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int setId = setA.find(i);
            if (!id4.containsKey(setId)) {
                id4.put(setId, new id25());
            }
            id4.get(setId).add(i);
        }


        int h = 0;
        for (int v1 : id4.keySet()) {
            for (int v2 : id4.keySet()) {
                if (!id4.get(v1).isEmpty()
                        && !id4.get(v2).isEmpty()
                        && v1 != v2) {
                    boolean ansFound = false;
                    outer : for (int vert1 : id4.get(v1)) {
                        for (int vert2 : id4.get(v2)) {
                            if (!setB.id12(vert1, vert2)) {
                                setA.union(vert1, vert2);
                                setB.union(vert1, vert2);
                                from[h] = vert1;
                                to[h] = vert2;
                                h++;
                                ansFound = true;
                                break outer;
                            }
                        }
                    }
                    if(ansFound) {
                        id4.get(v1).addAll(id4.get(v2));
                        id4.get(v2).clear();
                    }
                }
            }
        }
























        System.out.println(h);
        for (int i = 0; i < h; i++) {
            System.out.println((from[i] + 1) + " " + (to[i] + 1));
        }


    }

    class id25 implements Iterable<Integer> {

        int size;
        id25.Node head;
        id25.Node tail;

        id25() {
            init();
        }

        void init() {
            size = 0;
            head = new id25.Node();
            tail = new id25.Node();
            head.next = tail;
            tail.prev = head;
        }

        class Node {
            int val;
            id25.Node next;
            id25.Node prev;
        }

        

        void add(int val) {
            size++;
            id25.Node last = tail.prev;
            id25.Node toAdd = new id25.Node();

            toAdd.val = val;

            toAdd.next = tail;
            toAdd.prev = last;

            last.next = toAdd;
            tail.prev = toAdd;

        }

        

        void addAll(id25 list) {
            if (!list.isEmpty()) {
                id25.Node last = tail.prev;

                id25.Node id15 = list.head.next;
                id25.Node id30 = list.tail.prev;

                id30.next = tail;
                tail.prev = id30;
                id15.prev = last;
                last.next = id15;

            }
        }

        void clear() {
            init();
        }

        int size() {
            return size;
        }

        boolean isEmpty() {
            return size() == 0;
        }

        public Iterator<Integer> iterator() {
            return new id25.id19();
        }

        class id19 implements Iterator<Integer> {

            id25.Node cur = head.next;

            @Override
            public boolean hasNext() {
                return cur != tail;
            }

            @Override
            public Integer next() {
                if (!hasNext()) {
                    throw new NoSuchElementException();
                } else {
                    int val = cur.val;
                    cur = cur.next;
                    return val;
                }
            }
        }

    }

    class id2 {
        private int[] rank, parent;
        private int amount;

        public id2(int amount) {
            this.rank = new int[amount];
            this.parent = new int[amount];
            this.amount = amount;
            for (int i = 0; i < amount; i++) {
                parent[i] = i;
            }
        }

        public boolean id12(int u, int v) {
            return find(u) == find(v);
        }

        private int find(int v) {
            if (v == parent[v])
                return v;
            return parent[v] = find(parent[v]);
        }

        public void union(int x, int y) {
            

            int xRoot = find(x), yRoot = find(y);

            

            

            if (xRoot == yRoot)
                return;

            

            if (rank[xRoot] < rank[yRoot])

                

                

                parent[xRoot] = yRoot;

                

            else if (rank[xRoot] > rank[yRoot])

                

                

                parent[yRoot] = xRoot;

            else 

            {
                

                

                parent[yRoot] = xRoot;

                

                

                rank[xRoot]++;
            }
            amount--;
        }

        public int getAmount() {
            return amount;
        }
    }


    private void solve() {
        int t = 1;

        for (int tt = 0; tt < t; tt++) {
            solveOne();
        }
    }

    class id7 extends RuntimeException {

        id7(Object expected,
                                  Object actual, Object... input) {
            super("expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
        }
    }

    private int nextInt() {
        return System.in.readInt();
    }

    private long nextLong() {
        return System.in.readLong();
    }

    private String nextString() {
        return System.in.readString();
    }

    private int[] id26(int n) {
        return System.in.id1(n);
    }

    private long[] id29(int n) {
        return System.in.id13(n);
    }


    public static void main(String[] args) {
        new TemplateFast().run();
    }

    static class System {
        private static id14 in;
        private static id21 out;
    }

    private void run() {
        System.in = new id14(java.lang.System.in);
        System.out = new id21(java.lang.System.out);
        solve();
        System.out.flush();
    }

    private static class id21 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id21() {
            this(java.lang.System.out);
        }

        public id21(OutputStream os) {
            this.out = os;
        }

        public id21(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id21 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public id21 print(char c) {
            return print((byte) c);
        }

        public id21 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public id21 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public id21 print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerflush();
                }
            }
            return this;
        }

        

        public id21 print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerflush();
                }
            }
            return this;
        }

        private static int countDigits(int l) {
            if (l >= 1000000000) return 10;
            if (l >= 100000000) return 9;
            if (l >= 10000000) return 8;
            if (l >= 1000000) return 7;
            if (l >= 100000) return 6;
            if (l >= 10000) return 5;
            if (l >= 1000) return 4;
            if (l >= 100) return 3;
            if (l >= 10) return 2;
            return 1;
        }

        public id21 print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerflush();
            if (x < 0) {
                print((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public id21 print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerflush();
            if (x < 0) {
                print((byte) '-');
                x = -x;
            }
            int d = countDigits(x);
            for (int i = ptr + d - 1; i >= ptr; i--) {
                buf[i] = (byte) ('0' + x % 10);
                x /= 10;
            }
            ptr += d;
            return this;
        }

        public id21 print(double x, int precision) {
            if (x < 0) {
                print('-');
                x = -x;
            }
            x += Math.pow(10, -precision) / 2;
            

            print((long) x).print(".");
            x -= (long) x;
            for (int i = 0; i < precision; i++) {
                x *= 10;
                print((char) ('0' + (int) x));
                x -= (int) x;
            }
            return this;
        }

        public id21 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id21 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id21 println(char c) {
            return print(c).println();
        }

        public id21 println(int x) {
            return print(x).println();
        }

        public id21 println(long x) {
            return print(x).println();
        }

        public id21 println(String x) {
            return print(x).println();
        }

        public id21 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id21 println() {
            return print((byte) '\n');
        }

        private void innerflush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerflush");
            }
        }

        public void flush() {
            innerflush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class id14 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id28 filter;

        public id14(InputStream stream) {
            this.stream = stream;
        }

        public double[] id5(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id24(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id8(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public void id16(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id17(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id20(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id8(columnCount);
            }
            return table;
        }

        public int[][] id11(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id5(columnCount);
            }
            return table;
        }

        public long[][] id3(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id13(columnCount);
            }
            return table;
        }

        public String[][] id22(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id24(columnCount);
            }
            return table;
        }

        public String readText() {
            StringBuilder result = new StringBuilder();
            while (true) {
                int character = read();
                if (character == '\r') {
                    continue;
                }
                if (character == -1) {
                    break;
                }
                result.append((char) character);
            }
            return result.toString();
        }

        public void id18(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id13(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id1(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int peek() {
            if (numChars == -1) {
                return -1;
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar];
        }

        public int id27() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id10(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!id10(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id10(c));
            return res.toString();
        }

        public boolean id10(int c) {
            if (filter != null) {
                return filter.id10(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id6() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = id6();
            while (s.trim().length() == 0) {
                s = id6();
            }
            return s;
        }

        public String readLine(boolean id23) {
            if (id23) {
                return readLine();
            } else {
                return id6();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id10(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id10(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!id10(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public boolean id9() {
            int value;
            while (id10(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id28 getFilter() {
            return filter;
        }

        public void setFilter(id28 filter) {
            this.filter = filter;
        }

        public interface id28 {
            public boolean id10(int ch);
        }
    }

}