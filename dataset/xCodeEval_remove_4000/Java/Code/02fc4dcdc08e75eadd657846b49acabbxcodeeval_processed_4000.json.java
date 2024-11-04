import java.io.*;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.function.Predicate;


public class id17 {
    


    private long id9(int n, int k, long[] b) {
        long ans = Long.MAX_VALUE;
        long mask = 1;
        for (int i = 0; i < n; i++) mask *= k;
        

        

        

        

        

        for (long set = 0; set < mask; set++) {
            long localAns = 0;
            long set_ = set;

            id13 tree = new id13(n);
            int[] bits = new int[n];
            for (int i = 0; i < n; i++) {
                int bit = id21(set_ % k);
                bits[i] = bit;
                set_ /= k;
                Range range = new Range(bit, k, i, n);

                int f = range.f;
                int s = range.s;
                int fixed_bit = range.fixed_bit;

                if (tree.at(i) < b[i]) {
                    long localStep = id30(b[i] - tree.at(i), fixed_bit + 1);
                    tree.add(f, s, localStep);
                    localAns += localStep;
                }

            }
            if (ans > localAns) {
                ans = localAns;
                System.out.println("LocalAns " + localAns + " bits = " + Arrays.toString(bits));
            }
            

        }

        return ans;
    }

    private long id23(int n, int k, long[] b) {
        long ans = Long.MAX_VALUE;




        

        

        

        

        

        for (int set = 0; set < (1 << n); set++) {
            long localAns = 0;
            int set_ = set;

            id13 tree = new id13(n);

            for (int l = 0, r = n - 1, cnt = 0; cnt < n; cnt++) {

                int i;
                if (set_ % 2 == 0 ) {
                    i = l;
                } else {
                    i = r;
                }
                set_ /= 2;



                int id14 = Math.min(i + 1, k);
                long ai = tree.at(i);

                long need = b[i] - ai;
                if(need <= 0) {
                    if(i == r) r--;
                    else  l++;
                    continue;
                }
                int upTo = Math.max(k - 1, i);
                int from = upTo + 1 - k;
                long localSteps = id30(need, id14);
                if (i == r) {
                    

                    


                    tree.add(from, upTo, localSteps);


                    localAns += localSteps;



                    r--;
                } else  {
                    

                    


                    int shift = id14 - lowerBound(0, id14,
                            stepSize -> need <= localSteps * stepSize);

                    int id35 = Math.max(r, k - 1);
                    int left = id35 + 1 - k;
                    from = Math.min(from + shift, left);
                    upTo = Math.min(upTo + shift, id35);

                    tree.add(from, upTo, localSteps);





                    localAns += localSteps;
                    l++;
                }
            }
            ans = Math.min(ans, localAns);
        }

        return ans;
    }

    class Range {
        int f;
        int s;
        int fixed_bit;

        Range(int bit, int k, int i, int n) {
            final int l = i - bit;
            final int r = l + k - 1;
            if (l < 0) {
                f = 0;
                s = k - 1;
                fixed_bit = i;
            } else if (n - 1 < r) {
                f = n - k;
                s = n - 1;
                fixed_bit = bit + (r - (n - 1));
                assertThat(fixed_bit < k);
            } else {
                f = l;
                s = r;
                fixed_bit = bit;
            }
        }
    }

    private long id22(int n, int k, long[] b) {
        long ans = 0;
        id13 tree = new id13(n);

        for (int i = n - 1; i >= k; i--) {
            long ai = tree.at(i);
            if (ai < b[i]) {
                long localAns = id30(b[i] - ai, k);
                

                

                

                tree.add(i + 1 - k , i, localAns);
                ans += localAns;
            }
        }
        long max = 0;
        for(int i = k - 1; i >= 0; i--){
            long ai = tree.at(i);
            if (ai < b[i]) {
                long localAns = id30(b[i] - ai, i + 1);
                tree.add(0 , k - 1, localAns);
                



                ans += localAns;
            }
        }

        return ans + max;

    }

    private long solveOne(int n, int k, long[] b) {
        long ans = 0;
        id13 tree = new id13(n);

        for (int l = 0, r = n - 1; l <= r; ) {
            long al = -1;
            long ar = -1;
            while (l < n && (al = tree.at(l)) >= b[l]) l++;
            while (0 <= r && (ar = tree.at(r)) >= b[r]) r--;

            if (l > r) {
                break;
            }

            int id31 = Math.min(l + 1, k);
            int id25 = Math.min(r + 1, k);
            long id12 = id30(b[l] - al, id31);
            long id18 = id30(b[r] - ar, id25);
            int i;

            if (id12 < id18) {
                i = l;
            } else {
                i = r;
            }



            int id14 = Math.min(i + 1, k);
            long ai = tree.at(i);

            long need = b[i] - ai;
            int upTo = Math.max(k - 1, i);
            int from = upTo + 1 - k;
            long localSteps = id30(need, id14);
            if (i == r) {
                

                


                tree.add(from, upTo, localSteps);


                ans += localSteps;



                r--;
            } else  {
                

                


                int shift = id14 - lowerBound(0, id14,
                        stepSize -> need <= localSteps * stepSize);

                int id35 = Math.max(r, k - 1);
                int left = id35 + 1 - k;
                from = Math.min(from + shift, left);
                upTo = Math.min(upTo + shift, id35);

                tree.add(from, upTo, localSteps);





                ans += localSteps;
                l++;
            }
        }

        return ans;
    }


    private int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
        while (inclusiveRight - exclusiveLeft > 1) {
            int middle = exclusiveLeft + (inclusiveRight - exclusiveLeft) / 2;
            if (predicate.test(middle)) {
                inclusiveRight = middle;
            } else {
                exclusiveLeft = middle;
            }
        }
        return inclusiveRight;
    }

    long id30(long a, long b) {
        return (a + b - 1) / b;
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
    }

    private int id21(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE);
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id11) {
            System.out.println(MessageFormat.format(str, os));
        }
    }

    void _______debug(Object o) {
        if (!id11) {
            System.out.println(o != null ? o.toString() : "null");
        }
    }


    class id13 {

        class Segment {
            public Segment(int l, int r) {
                this.l = l;
                this.r = r;
            }

            final int l;
            final int r;

            long startVal;
            long difference;

            @Override
            public String toString() {
                return "Segment{" +
                        "l=" + l +
                        ", r=" + r +
                        ", startVal=" + startVal +
                        ", difference=" + difference +
                        '}';
            }
        }

        int n;
        Segment[] tree;

        id13(int n) {
            tree = new Segment[4 * n];
            this.n = n;
            init(0, 0, n - 1);
        }

        void init(int i, int l, int r) {
            tree[i] = new Segment(l, r);
            if (l == r) {
                return;
            }
            init(2 * i + 1, l, (l + r) / 2);
            init(2 * i + 2, (l + r) / 2 + 1, r);
        }


        long at(int i) {
            assertThat(0 <= i && i < n);
            long ans = 0;
            int j = 0;
            while (j < tree.length ) {
                Segment curSeg = tree[j];
                if (curSeg == null) {
                    break;
                }
                ans += curSeg.startVal + (i - curSeg.l) * curSeg.difference;
                assertThat(ans >= 0);
                int m = (curSeg.l + curSeg.r) / 2;
                j = 2 * j + (i <= m ? 1 : 2);
                

            }
            return ans;
        }

        void add(int from, int upTo, long delta) {
            add(from, upTo, delta, delta, 0);
        }

        private void add(int from, int upTo, long start, long delta, int i) {

            final int l = tree[i].l;
            final int r = tree[i].r;

            if (from > upTo || upTo < l || r < from) {
                return;
            }

            if (from == l && upTo == r) {
                Segment seg = tree[i];
                seg.difference += delta;
                seg.startVal += start;
                return;
            }
            int tm = (l + r) / 2;
            

            int leftLen = Math.max(0, Math.min(tm, upTo) + 1 - from);
            add(from, Math.min(tm, upTo), start, delta, 2 * i + 1);
            add(Math.max(from, tm + 1), upTo, start + leftLen * delta, delta, 2 * i + 2);
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(at(i)).append(' ');
            }
            return sb.toString();
        }
    }


    private void solve() {
        if (!id19) {
            int t = !id11 ? nextInt() : 1;
            for (int tt = 0; tt < t; tt++) {
                int n = nextInt();
                int k = nextInt();
                long[] b = id34(n);


                long actualAns = id22(n, k, b);
                System.out.println(actualAns);
            }
        } else {

            Random r = new Random(42);
            for (int test = 1; test <= 10000; test++) {
                int n = 6;
                int k = 4;

                long[] b = new long[n];
                for (int i = 0; i < n; i++) b[i] = r.nextInt(2000);

                long actualAns = solveOne(n, k, b);


                long expectedAns = id23(n, k, b);
                if (actualAns != expectedAns) {
                    _______debug("RESULT: WA {0} {1} {2} -> {3}, but was {4}", n, k, Arrays.toString(b), expectedAns, actualAns);
                    

                } else {
                    _______debug("RESULT: OK {0} {1} {2} -> {3}", n, k, Arrays.toString(b), expectedAns);
                }

            }
        }

    }

    class id5 extends RuntimeException {










        id5(int testCase,
                                  Object expected,
                                  Object actual, Object... input) {
            super("Testcase: " + testCase + "\n expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
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

    private int[] id29(int n) {
        return System.in.id1(n);
    }

    private long[] id34(int n) {
        return System.in.id15(n);
    }

    public static void main(String[] args) {
        new id17().run();
    }

    static class System {
        private static id16 in;
        private static id24 out;
    }

    final boolean id19 = false;
    final boolean id11 = java.lang.System.getProperty("id11") != null;

    private void run() {
        final boolean USE_IO = id11;
        if (USE_IO) {
            System.in = new id16(java.lang.System.in);
            System.out = new id24(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id16(new FileInputStream(nameIn));
                System.out = new id24(new PrintStream(nameOut));
                solve();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } finally {
                System.out.flush();
            }
        }
    }

    private static class id24 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id24() {
            this(java.lang.System.out);
        }

        public id24(OutputStream os) {
            this.out = os;
        }

        public id24(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id24 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerflush();
            return this;
        }

        public id24 print(char c) {
            return print((byte) c);
        }

        public id24 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            }
            return this;
        }

        public id24 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerflush();
            });
            return this;
        }

        

        public id24 print0(char[] s) {
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

        

        public id24 print0(String s) {
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

        public id24 print(int x) {
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

        public id24 print(long x) {
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

        public id24 print(double x, int precision) {
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

        public id24 println(int[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id24 println(int[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id24 println(Object o) {
            return o != null ? println(o.toString()) : println("null");
        }

        public id24 println(long[] a, int from, int upTo, char separator) {
            for (int i = from; i < upTo; i++) {
                print(a[i]);
                print(separator);
            }
            print('\n');
            return this;
        }

        public id24 println(long[] a) {
            return println(a, 0, a.length, ' ');
        }

        public id24 println(char c) {
            return print(c).println();
        }

        public id24 println(int x) {
            return print(x).println();
        }

        public id24 println(long x) {
            return print(x).println();
        }

        public id24 println(String x) {
            return print(x).println();
        }

        public id24 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id24 println() {
            return print((byte) '\n');
        }

        public id24 printf(String format, Object... args) {
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

    private static class id16 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id33 filter;

        public id16(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id28(int size) {
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

        public char[][] readTable(int rowCount, int columnCount) {
            char[][] table = new char[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id6(columnCount);
            }
            return table;
        }

        public int[][] id10(int rowCount, int columnCount) {
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
                table[i] = id15(columnCount);
            }
            return table;
        }

        public String[][] id26(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.id28(columnCount);
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

        public void id20(String[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readString();
                }
            }
        }

        public long[] id15(int size) {
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

        public int id32() {
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

        public String readLine(boolean id27) {
            if (id27) {
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

        public id33 getFilter() {
            return filter;
        }

        public void setFilter(id33 filter) {
            this.filter = filter;
        }

        public interface id33 {
            public boolean id8(int ch);
        }
    }

}