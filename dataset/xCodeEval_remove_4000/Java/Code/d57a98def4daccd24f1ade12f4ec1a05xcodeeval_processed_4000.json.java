import java.io.*;
import java.text.*;
import java.util.*;
import java.util.function.*;


public class D {

    final boolean id10 = java.lang.System.getProperty("id10") != null;
    final boolean id13 = false;
    final boolean SIMULATION = false;
    final Random random = new Random(420);

    private int solveOne(int testCase) {
        int n = nextInt();
        int[] a = id19(n);
        int l = 0;
        int r = n;
        while (r - l > 1) {
            r--;
            for(int i = l; i < r; i++) {
                a[i] = a[i + 1] - a[i];
            }
            sort(a, l, r);
            l = Math.max(0, lowerBound(-1, r, mid -> a[mid] > 0) - 1);
        }

        System.out.println(a[l]);

        return 0;
    }


    int lowerBound(int exclusiveLeft, int inclusiveRight, Predicate<Integer> predicate) {
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

    void sort(int[] a, int from, int upTo) {
        for (int i = from; i < upTo; i++) {
            int j = from + random.nextInt(upTo - from);
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        Arrays.sort(a, from, upTo);
    }

    public static int[] id20(int[] a) {
        int n = a.length;
        int[] c0 = new int[0x101];
        int[] c1 = new int[0x101];
        int[] c2 = new int[0x101];
        int[] c3 = new int[0x101];
        for (int v : a) {
            c0[(v & 0xff) + 1]++;
            c1[(v >>> 8 & 0xff) + 1]++;
            c2[(v >>> 16 & 0xff) + 1]++;
            c3[(v >>> 24 ^ 0x80) + 1]++;
        }
        for (int i = 0; i < 0xff; i++) {
            c0[i + 1] += c0[i];
            c1[i + 1] += c1[i];
            c2[i + 1] += c2[i];
            c3[i + 1] += c3[i];
        }
        int[] t = new int[n];
        for (int v : a) t[c0[v & 0xff]++] = v;
        for (int v : t) a[c1[v >>> 8 & 0xff]++] = v;
        for (int v : a) t[c2[v >>> 16 & 0xff]++] = v;
        for (int v : t) a[c3[v >>> 24 ^ 0x80]++] = v;
        return a;
    }

    private int id9(int testCase) {
        return 0;
    }

    private void solve() {
        if (SIMULATION) {
            int t = 1;
            for (int testCase = 0; testCase < t; testCase++) {














                int n = (int) 200;

                int[] a = new int[n];
                a[0] = 0;
                for (int i = 1, diff = 0; i < n; i++, diff++) {
                    a[i] = a[i - 1] + diff;
                    if (a[i] > n) {
                        java.lang.System.out.println("Val = " + a[i] + " Diff  - " + diff);
                        return;
                    }
                }

























                

                



                List<Merge> merges = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    Merge m = new Merge(-1, i, null, a);
                    merges.add(m);
                }

                List<Merge> cur = merges;
                int p = 0;
                while (cur.size() > 1) {
                    java.lang.System.out.println("Oper " + p++);
                    List<Merge> local = new ArrayList<>();
                    for (int i = 1; i < cur.size(); i++) {
                        Merge m = new Merge(i - 1, i, cur, a);
                        java.lang.System.out.print(m.getVal());
                        java.lang.System.out.print(' ');
                        local.add(m);
                    }
                    java.lang.System.out.println();
                    Collections.sort(local, Comparator.comparingInt(Merge::getVal));
                    for (Merge m : local) {
                        java.lang.System.out.print(m.getVal());
                        java.lang.System.out.print(' ');
                    }
                    java.lang.System.out.println();
                    cur = local;
                }
                java.lang.System.out.println("Test: " + testCase);
                java.lang.System.out.println(Arrays.toString(a));
                java.lang.System.out.println(cur.get(0).getVal());

                int[] id17 = new int[n];
                int[] id0 = new int[n];

                dfs(cur.get(0).parent.get(cur.get(0).second), id17, id0);
                dfs(cur.get(0).parent.get(cur.get(0).first), id0, id17);

                java.lang.System.out.println(Arrays.toString(id17));
                java.lang.System.out.println(Arrays.toString(id0));


                

                

                

                

                


                


            }
        } else if (id13) {
            int t = 100_000;
            for (int testCase = 0; testCase < t; testCase++) {
                int expected = id9(testCase);
                int actual = solveOne(testCase);
                if (expected != actual) {
                    throw new id5(
                            this.getClass().getSimpleName(),
                            testCase,
                            expected,
                            actual);
                }
            }
        } else {
            int t = nextInt();
            for (int testCase = 0; testCase < t; testCase++) {
                solveOne(testCase);
            }
        }
    }

    private void dfs(Merge merge, int[] plus, int[] minus) {
        if (merge.first == -1) {
            plus[merge.second]++;
        } else {
            dfs(merge.parent.get(merge.second), plus, minus);
            dfs(merge.parent.get(merge.first), minus, plus);
        }
    }


    class Merge {

        Merge(int l, int r, List<Merge> parent, int[] a) {
            first = l;
            second = r;
            this.parent = parent;
            this.a = a;
        }

        int getVal() {
            if (ans == -1) {
                if (first == -1)
                    return ans = a[second];
                else
                    return ans = parent.get(second).getVal() - parent.get(first).getVal();
            } else {
                return ans;
            }
        }

        int ans = -1;

        int[] a;
        int first;
        int second;
        List<Merge> parent;
    }


    class id5 extends RuntimeException {

        id5(String testName,
                                  int testCase,
                                  Object expected,
                                  Object actual, Object... input) {
            super("Testcase: " + testCase + "\n expected = " + expected + ",\n actual = " + actual + ",\n " + Arrays.deepToString(input));
        }
    }

    private void assertThat(boolean b) {
        if (!b) throw new RuntimeException();
    }

    private void assertThat(boolean b, String s) {
        if (!b) throw new RuntimeException(s);
    }

    private int id14(long a) {
        assertThat(Integer.MIN_VALUE <= a && a <= Integer.MAX_VALUE,
                "Integer overflow long = [" + a + "]" + " int = [" + (int) a + "]");
        return (int) a;
    }

    void _______debug(String str, Object... os) {
        if (!id10) {
            System.out.println(MessageFormat.format(str, os));
            System.out.flush();
        }
    }

    void _______debug(Object o) {
        if (!id10) {
            _______debug("{0}", String.valueOf(o));
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

    private int[] id19(int n) {
        return System.in.id1(n);
    }

    private long[] id23(int n) {
        return System.in.id11(n);
    }

    public static void main(String[] args) {
        new D().run();
    }

    static class System {
        private static id12 in;
        private static id15 out;
    }

    private void run() {


        final boolean USE_IO = id10;
        if (USE_IO) {
            System.in = new id12(java.lang.System.in);
            System.out = new id15(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id12(new FileInputStream(nameIn));
                System.out = new id15(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }




    }

    private static class id15 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id15() {
            this(java.lang.System.out);
        }

        public id15(OutputStream os) {
            this.out = os;
        }

        public id15(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id15 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id15 print(char c) {
            return print((byte) c);
        }

        public id15 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id15 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id15 print0(char[] s) {
            if (ptr + s.length < BUF_SIZE) {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                }
            } else {
                for (char c : s) {
                    buf[ptr++] = (byte) c;
                    if (ptr == BUF_SIZE) innerFlush();
                }
            }
            return this;
        }

        

        public id15 print0(String s) {
            if (ptr + s.length() < BUF_SIZE) {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                }
            } else {
                for (int i = 0; i < s.length(); i++) {
                    buf[ptr++] = (byte) s.charAt(i);
                    if (ptr == BUF_SIZE) innerFlush();
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

        public id15 print(int x) {
            if (x == Integer.MIN_VALUE) {
                return print((long) x);
            }
            if (ptr + 12 >= BUF_SIZE) innerFlush();
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

        public id15 print(long x) {
            if (x == Long.MIN_VALUE) {
                return print("" + x);
            }
            if (ptr + 21 >= BUF_SIZE) innerFlush();
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

        public id15 print(double x, int precision) {
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

        public id15 println(char c) {
            return print(c).println();
        }

        public id15 println(int x) {
            return print(x).println();
        }

        public id15 println(long x) {
            return print(x).println();
        }

        public id15 println(String x) {
            return print(x).println();
        }

        public id15 println(Object x) {
            return print(x.toString()).println();
        }

        public id15 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id15 println() {
            return print((byte) '\n');
        }

        public id15 printf(String format, Object... args) {
            return print(String.format(format, args));
        }

        private void innerFlush() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException e) {
                throw new RuntimeException("innerFlush");
            }
        }

        public void flush() {
            innerFlush();
            try {
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException("flush");
            }
        }
    }

    private static class id12 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id22 filter;

        public id12(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id18(int size) {
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

        public long[] id11(int size) {
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

        public int id21() {
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

        public char[] id2() {
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
            char[] resArr = new char[res.length()];
            res.getChars(0, res.length(), resArr, 0);
            return resArr;
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

        public String readLine(boolean id16) {
            if (id16) {
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

        public id22 getFilter() {
            return filter;
        }

        public void setFilter(id22 filter) {
            this.filter = filter;
        }

        public interface id22 {
            public boolean id8(int ch);
        }
    }

}