import java.io.*;
import java.util.*;


public class CF1672D {

    private String solveOne(int n, int[] a, int[] b) {
        List<Pair> grA = groups(a);
        List<Pair> grB = groups(b);
        if (grA.size() < grB.size()) {
            return ("NO");

        }
        int pa = grA.size() - 1;
        int pb = grB.size() - 1;
        MultiSet<Integer> opened = MultiSet.UNORDERED();
        while (pb >= 0 && pa >= 0) {
            Pair pairB = grB.get(pb);
            Pair pairA = grA.get(pa);


            if (pairB.val == pairA.val) {
                


                boolean invariant = pairB.cnt >= pairA.cnt;

                if (!invariant) {










                    try {
                        opened.removeAmount(pairB.val,  pairA.cnt - pairB.cnt);
                    } catch (RuntimeException e){
                        return ("NO");
                    }
                    

                } else {
                    opened.add(pairB.val, pairB.cnt - pairA.cnt);
                }
                pb--;
                pa--;
            } else {
                if (opened.get(pairA.val) < pairA.cnt) {
                    return ("NO");

                } else {
                    opened.removeAmount(pairA.val, pairA.cnt);
                    

                    pa--;
                }
            }
        }
        if (pb > -1) {
            return ("NO");

        }
        while (pa >= 0) {
            Pair pairA = grA.get(pa);
            if (opened.get(pairA.val) < pairA.cnt) {
                return ("NO");

            } else {
                opened.removeAmount(pairA.val, pairA.cnt);
                

                pa--;
            }
        }

        return (opened.size() == 0 ? "YES" : "NO");











    }

    int[] randomArray(Random r, int n, int from, int upTo){
        int[] ans = new int[n];
        for(int i  = 0; i < n ; i ++) {
            ans[i] = from + r.nextInt(upTo - from);
        }
        return ans;
    }
    class Segment { int left; int right;

        public Segment(int left, int right) {
            this.left = left;
            this.right = right;
        }

        @Override
        public String toString() {
            return "Segment{" +
                    "left=" + left +
                    ", right=" + right +
                    '}';
        }
    }
    int[] doRandomShift(Random rand, int[] a, int shift, List<Segment> toFill){
        int n = a.length;
        int[] b = a.clone();
        for (int i = 0; i < shift; i++) {
            List<Segment> possible = new ArrayList<>();
            for(int l = 0 ; l < n; l ++) {
                for(int r = 0; r < n; r++){
                    if(l < r && b[l] == b[r] && r + 1 - l > 2) {
                        possible.add(new Segment(l, r));
                    }
                }
            }
            if(possible.isEmpty()){
                break;
            } else {
                Segment s = possible.get(rand.nextInt(possible.size()));
                int temp = b[s.left];
                java.lang.System.arraycopy(b, s.left + 1, b, s.left, s.right - s.left);
                b[s.right] = temp;
                toFill.add(s);
            }
        }
        return b;
    }

    private void solve() {
        boolean CORRECTNESS_TEST = false;
        if (!CORRECTNESS_TEST) {
            int t = nextInt();
            for (int tt = 0; tt < t; tt++) {
                int n = nextInt();
                int[] a = nextIntArr(n);
                int[] b = nextIntArr(n);
                String res = solveOne(n, a, b);
                System.out.println(res);
            }
        } else {
            Random r = new Random(42);
            int t = 1_000_000;
            for (int tt = 0; tt < t; tt++) {
                int n = 5 + r.nextInt(6);
                int[] a = randomArray(r, n, 1, 10);
                int shifts = 5 + r.nextInt(6);
                List<Segment> segments = new ArrayList<>();
                int[] b = doRandomShift(r, a, shifts, segments);
                String ans = solveOne(n, a, b);
                if(!Objects.equals(ans, "YES")) {
                    throw new AssertionRuntimeException(tt, "YES", ans, a, b, segments);
                }

            }
        }
    }

    class AssertionRuntimeException extends RuntimeException {










        AssertionRuntimeException(int testCase,
                                  Object expected,
                                  Object actual, Object... input) {
            super("Testcase: " + testCase + "\n expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
        }
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
    }

    private List<Pair> groups(int[] a) {
        int n = a.length;
        List<Pair> ans = new ArrayList<>();
        int curCnt = 0;
        for (int i = 0; i < n; i++) {
            if ((i == 0 || a[i - 1] != a[i])) {
                curCnt = 0;
            }
            curCnt++;
            if ((i == n - 1 || a[i + 1] != a[i])) {
                ans.add(new Pair(a[i], curCnt, i));
            }
        }
        return ans;
    }

    class Pair {
        int val;
        int cnt;
        int indR;

        public Pair(int val, int cnt, int indR) {
            this.val = val;
            this.cnt = cnt;
            this.indR = indR;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "val=" + val +
                    ", cnt=" + cnt +
                    ", indR=" + indR +
                    '}';
        }
    }

    static class MultiSet<T> implements Iterable<T> {

        static <T> MultiSet<T> ORDERED(Comparator<T> comparator) {
            MultiSet<T> tMultiSet = new MultiSet<>();
            tMultiSet.map = new TreeMap<>(comparator);
            return tMultiSet;
        }

        static <T> MultiSet<T> UNORDERED() {
            MultiSet<T> tMultiSet = new MultiSet<>();
            tMultiSet.map = new HashMap<>();
            return tMultiSet;
        }

        private MultiSet() {
        }

        private Map<T, Long> map;
        private int size = 0;

        boolean contains(T val) {
            return map.containsKey(val);
        }

        void add(T val) {
            map.merge(val, 1L, Long::sum);
            size++;
        }

        void add(T val, long cnt) {
            if(cnt != 0){
                map.merge(val, cnt, Long::sum);
                size += cnt;
            }
        }

        void removeOne(T val) {
            removeAmount(val, 1);
        }

        void removeAll(T val) {
            long cnt = map.get(val);
            size -= cnt;
            map.remove(val);
        }

        void removeAmount(T val, long cnt) {
            if(cnt == 0) {
                return;
            }
            Objects.requireNonNull(map.get(val));
            if (map.get(val) < cnt) {
                throw new RuntimeException(
                        String.format("Trying to remove the amount %d, while %d only available %d!", cnt, val, map.get(val))
                );
            }
            map.merge(val, -cnt, Long::sum);
            if (map.get(val) == 0) {
                map.remove(val);
            }
            size -= cnt;
        }

        long get(T val) {
            return map.getOrDefault(val, 0L);
        }


        int size() {
            return size;
        }


        @Override
        public Iterator<T> iterator() {
            return new Iterator<T>() {

                {
                    this.iterator = map.keySet().iterator();
                    if (this.iterator.hasNext()) {
                        next = this.iterator.next();
                        cnt = map.get(this.next) - 1;
                    }
                }

                long cnt;
                Iterator<T> iterator;
                T next;

                private void prepareNext() {
                    if (cnt > 0) {
                        cnt--;
                    } else {
                        if (this.iterator.hasNext()) {
                            next = this.iterator.next();
                            cnt = map.get(this.next) - 1;
                        } else {
                            next = null;
                            cnt = 0;
                        }

                    }
                }

                @Override
                public boolean hasNext() {
                    return next != null;
                }

                @Override
                public T next() {
                    T ans = next;
                    prepareNext();
                    return ans;
                }
            };
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

    private int[] nextIntArr(int n) {
        return System.in.readIntArray(n);
    }

    private long[] nextLongArr(int n) {
        return System.in.readLongArray(n);
    }

    public static void main(String[] args) {
        new CF1672D().run();
    }

    static class System {
        private static FastInputStream in;
        private static FastPrintStream out;
    }

    private void run() {
        final boolean ONLINE_JUDGE = java.lang.System.getProperty("ONLINE_JUDGE") != null;
        final boolean USE_IO = ONLINE_JUDGE;
        if (USE_IO) {
            System.in = new FastInputStream(java.lang.System.in);
            System.out = new FastPrintStream(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new FastInputStream(new FileInputStream(nameIn));
                System.out = new FastPrintStream(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class FastPrintStream {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private FastPrintStream() {
            this(java.lang.System.out);
        }

        public FastPrintStream(OutputStream os) {
            this.out = os;
        }

        public FastPrintStream(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public FastPrintStream print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public FastPrintStream print(char c) {
            return print((byte) c);
        }

        public FastPrintStream print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public FastPrintStream print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public FastPrintStream print0(char[] s) {
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

        

        public FastPrintStream print0(String s) {
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

        public FastPrintStream print(int x) {
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

        public FastPrintStream print(long x) {
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

        public FastPrintStream print(double x, int precision) {
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

        public FastPrintStream println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public FastPrintStream println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public FastPrintStream println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public FastPrintStream println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public FastPrintStream println(char c) {
            return print(c).println();
        }

        public FastPrintStream println(int x) {
            return print(x).println();
        }

        public FastPrintStream println(long x) {
            return print(x).println();
        }

        public FastPrintStream println(String x) {
            return print(x).println();
        }

        public FastPrintStream println(double x, int precision) {
            return print(x, precision).println();
        }

        public FastPrintStream println() {
            return print((byte) '\n');
        }

        public FastPrintStream printf(String format, Object... args) {
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

    private static class FastInputStream {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public FastInputStream(InputStream stream) {
            this.stream = stream;
        }

        public double[] readDoubleArray(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] readStringArray(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
        }

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readCharArray(columnCount);
            }
            return table;
        }

        public int[][] readIntTable(int rowCount, int columnCount) {
            int[][] table = new int[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readIntArray(columnCount);
            }
            return table;
        }

        public double[][] readDoubleTable(int rowCount, int columnCount) {
            double[][] table = new double[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readDoubleArray(columnCount);
            }
            return table;
        }

        public long[][] readLongTable(int rowCount, int columnCount) {
            long[][] table = new long[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = readLongArray(columnCount);
            }
            return table;
        }

        public String[][] readStringTable(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readStringArray(columnCount);
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

        public void readStringArrays(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] readLongArray(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] readIntArray(int size) {
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

        public int peekNonWhitespace() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String readLine0() {
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
            String s = readLine0();
            while (s.trim().length() == 0) {
                s = readLine0();
            }
            return s;
        }

        public String readLine(boolean ignoreEmptyLines) {
            if (ignoreEmptyLines) {
                return readLine();
            } else {
                return readLine0();
            }
        }

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
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
                while (!isSpaceChar(c)) {
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

        public boolean isExhausted() {
            int value;
            while (isSpaceChar(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public SpaceCharFilter getFilter() {
            return filter;
        }

        public void setFilter(SpaceCharFilter filter) {
            this.filter = filter;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);
        }
    }

}