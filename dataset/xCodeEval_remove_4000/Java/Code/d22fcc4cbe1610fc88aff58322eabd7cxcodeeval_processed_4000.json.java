import java.io.*;
import java.util.*;




public class id19 {

    private void solveOne() {
        int n = nextInt();
        int l = nextInt();
        int r = nextInt();
        int[] a = id21(n);

        


        MultiSet left = new MultiSet();
        for (int i = 0; i < l; i++) {
            left.add(a[i]);
        }

        MultiSet right = new MultiSet();
        for (int i = l; i < n; i++) {
            right.add(a[i]);
        }

        

        Map<Integer, Integer> intersection = new HashMap<>();
        for (int val : left.map.keySet()) {
            if (right.map.containsKey(val)) {
                intersection.put(val, Math.min(left.map.get(val), right.map.get(val)));
            }
        }

        for (int val : intersection.keySet()) {
            int cnt = intersection.get(val);

            left.removeAmount(val, cnt);
            right.removeAmount(val, cnt);

        }

        

        if(left.size() == right.size()) {
            

            System.out.println(left.size());
            return;
        }

        

        if (left.size() < right.size()) {
            MultiSet temp = left;
            left = right;
            right = temp;
        }

        int move = (left.size() - right.size()) / 2;


        

        List<id24> list = new ArrayList<>();
        for (int val : left.map.keySet()) {
            int cnt = left.map.get(val);
            list.add(new id24(val, cnt));
        }

        list.sort(Comparator.comparingInt(id24::getCnt).reversed());


        

        int ans = 0;
        for (id24 valToCnt : list) {
            int val = valToCnt.val;
            int cnt = valToCnt.cnt;
            int canMove = cnt / 2;
            if (canMove < move) {
                ans += canMove;
                move -= canMove;
            } else  {
                ans += move;
                move = 0;
            }
        }

        

        ans += 2 * move;

        

        ans += Math.min(left.size(), right.size());

        System.out.println(ans);



    }

    class id24 {
        int val;
        int cnt;

        public id24(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }

        public int getVal() {
            return val;
        }

        public int getCnt() {
            return cnt;
        }
    }

    class MultiSet {

        Map<Integer, Integer> map = new HashMap<>();
        int size = 0;

        void add(int val) {
            map.merge(val, 1, Integer::sum);
            size++;
        }

        void remove(int val) {
            removeAmount(val, 1);
        }

        void removeAmount(int val, int cnt) {
            Objects.requireNonNull(map.get(val));
            if (map.get(val) < cnt) {
                throw new RuntimeException(
                        String.format("Trying to remove the amount %d, while %d only available %d!", cnt, val, map.get(val))
                );
            }
            map.merge(val, -cnt, Integer::sum);
            size -= cnt;
        }


        int size() {
            return size;
        }

    }

    private void solve() {
        int t = nextInt();
        for (int tt = 0; tt < t; tt++) {
            solveOne();
        }
    }

    class id5 extends RuntimeException {

        id5(Object expected,
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

    private int[] id21(int n) {
        return System.in.id1(n);
    }

    private long[] id25(int n) {
        return System.in.id10(n);
    }

    public static void main(String[] args) {
        new id19().run();
    }

    static class System {
        private static id11 in;
        private static id16 out;
    }

    private void run() {
        System.in = new id11(java.lang.System.in);
        System.out = new id16(java.lang.System.out);
        solve();
        System.out.flush();
    }

    private static class id16 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id16() {
            this(java.lang.System.out);
        }

        public id16(OutputStream os) {
            this.out = os;
        }

        public id16(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id16 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public id16 print(char c) {
            return print((byte) c);
        }

        public id16 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public id16 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public id16 print0(char[] s) {
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

        

        public id16 print0(String s) {
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

        public id16 print(int x) {
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

        public id16 print(long x) {
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

        public id16 print(double x, int precision) {
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

        public id16 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id16 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id16 println(char c) {
            return print(c).println();
        }

        public id16 println(int x) {
            return print(x).println();
        }

        public id16 println(long x) {
            return print(x).println();
        }

        public id16 println(String x) {
            return print(x).println();
        }

        public id16 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id16 println() {
            return print((byte) '\n');
        }

        public id16 printf(String format, Object... args) {
            return print(String.format(format, args));
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

    private static class id11 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id23 filter;

        public id11(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id20(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] id6(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public void id12(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
        }

        public void id13(long[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readLong();
                }
            }
        }

        public void id15(double[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readDouble();
                }
            }
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id6(columnCount);
            }
            return table;
        }

        public int[][] id9(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id1(columnCount);
            }
            return table;
        }

        public double[][] id0(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id3(columnCount);
            }
            return table;
        }

        public long[][] id2(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = id10(columnCount);
            }
            return table;
        }

        public String[][] id17(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id20(columnCount);
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

        public void id14(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id10(int size) {
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

        public int id22() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id8(c)) {
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
            } while (!id8(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id8(c)) {
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
            } while (!id8(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id8(c));
            return res.toString();
        }

        public boolean id8(int c) {
            if (filter != null) {
                return filter.id8(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id4() {
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
            String s = id4();
            while (s.trim().length() == 0) {
                s = id4();
            }
            return s;
        }

        public String readLine(boolean id18) {
            if (id18) {
                return readLine();
            } else {
                return id4();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id8(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id8(c) && c != '.') {
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
                while (!id8(c)) {
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

        public boolean id7() {
            int value;
            while (id8(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id23 getFilter() {
            return filter;
        }

        public void setFilter(id23 filter) {
            this.filter = filter;
        }

        public interface id23 {
            public boolean id8(int ch);
        }
    }

}