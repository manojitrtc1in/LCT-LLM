import java.io.*;
import java.text.MessageFormat;
import java.util.*;
import java.util.function.Predicate;


public class C {

    final boolean id11 = java.lang.System.getProperty("id11") != null;

    private void id17(int testCase) {
        int n = nextInt();
        int m = nextInt();
        int[] a = id22(m);
        List<Schedule> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            Schedule schedule = new Schedule();
            schedule.type = i;
            list.add(schedule);
        }














        for (int i : a) {
            list.get(i - 1).id15++;
        }

        if (n == 1) {
            System.out.println(list.get(0).value());
            return;
        }


        PriorityQueue<Schedule> ans = new PriorityQueue<>(new Comparator<Schedule>() {
            @Override
            public int compare(Schedule o1, Schedule o2) {
                int comp = Integer.compare(o1.value(), o2.value());
                if (comp != 0) {
                    return comp;
                }
                return Integer.compare(o1.type, o2.type);
            }
        });

        for (int i = 1; i <= n; i++) {
            Schedule schedule = new Schedule();
            schedule.type = i;
            ans.add(schedule);
        }


    }

    private int id10(int testCase, int n, int m, int[] a) {

        int finalAns = Integer.MAX_VALUE;

        int id1 = 1;
        for (int i = 0; i < m; i++) id1 *= n;

        for (int nMask = 0; nMask < id1; nMask++) {

            int id14 = nMask;

            int[] ans = new int[n];

            for (int i = 0; i < m; i++, id14 /= n) {
                int j = id14 % n;
                if (a[i] - 1 == j) {
                    ans[j]++;
                } else {
                    ans[j] += 2;
                }
            }

            int max = Integer.MIN_VALUE;
            for (int i : ans) {
                max = Math.max(max, i);
            }
            finalAns = Math.min(finalAns, max);
        }

        return finalAns;
    }

    private int solveOne(int testCase, int n, int m, int[] a) {

        List<Schedule> list = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            Schedule schedule = new Schedule();
            schedule.type = i;
            list.add(schedule);
        }
        for (int i : a) {
            list.get(i - 1).id15++;
        }

        if (n == 1) {
            return list.get(0).value();
        }

        TreeSet<Schedule> tree = new TreeSet<>(new Comparator<Schedule>() {
            @Override
            public int compare(Schedule o1, Schedule o2) {
                int comp = Integer.compare(o1.value(), o2.value());
                if (comp != 0) {
                    return comp;
                }
                return Integer.compare(o1.type, o2.type);
            }
        });

        tree.addAll(list);

        while (true) {
            Schedule scheduleMin = tree.pollFirst();
            Schedule scheduleMax = tree.pollLast();

            int maxVal = scheduleMax.value();
            int minVal = scheduleMin.value();







            int minus =  minVal + 2 <= maxVal - 1 && scheduleMax.id15 >= 1 ? 1 : 0;

            if (minus != 0) {
                scheduleMax.id15 -= minus;
                scheduleMin.id18 += minus;
            }
            tree.add(scheduleMax);
            tree.add(scheduleMin);

            if (minus == 0) {
                break;
            }

        }

        return tree.last().value();


    }

    private int upperBound(int inclusiveLeft, int exclusiveRight, Predicate<Integer> predicate) {
        while (exclusiveRight - inclusiveLeft > 1) {
            int middle = inclusiveLeft + (exclusiveRight - inclusiveLeft) / 2;
            if (predicate.test(middle)) {
                inclusiveLeft = middle;
            } else {
                exclusiveRight = middle;
            }
        }
        return inclusiveLeft;
    }

    class Schedule {
        int type;
        int id15;
        int id18;
        boolean odd;

        int value() {
            return id15 + 2 * id18;
        }
    }

    boolean id8 = false;
    Random r = new Random(42);
    private void solve() {
        if (id8) {
            int t = 10000;
            for (int testCase = 0; testCase < t; testCase++) {
                int n = 4;
                int m = 6;

                int[] a = new int[m];
                for (int i = 0; i < m; i++) {
                    a[i] = 1 + r.nextInt(n);
                }

                int expected =  id10(testCase, n, m, a);
                int actual = solveOne(testCase, n, m, a);
                if(expected != actual) {
                    throw new id5("here", testCase, expected, actual,n, m,  a);
                }
            }


        } else {
            int t = nextInt();
            for (int testCase = 0; testCase < t; testCase++) {
                int n = nextInt();
                int m = nextInt();
                int[] a = id22(m);
                int actual = solveOne(testCase, n, m, a);
                System.out.println(actual);
            }
        }
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

    private int id16(long a) {
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

    private int[] id22(int n) {
        return System.in.id0(n);
    }

    private long[] id25(int n) {
        return System.in.id12(n);
    }

    public static void main(String[] args) {
        new C().run();
    }

    static class System {
        private static id13 in;
        private static id19 out;
    }

    private void run() {
        final boolean USE_IO = id11;
        if (USE_IO) {
            System.in = new id13(java.lang.System.in);
            System.out = new id19(java.lang.System.out);
            solve();
            System.out.flush();
        } else {
            final String nameIn = "input.txt";
            final String nameOut = "output.txt";
            try {
                System.in = new id13(new FileInputStream(nameIn));
                System.out = new id19(new PrintStream(nameOut));
                solve();
                System.out.flush();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    private static class id19 {
        private static final int BUF_SIZE = 8192;
        private final byte[] buf = new byte[BUF_SIZE];
        private final OutputStream out;
        private int ptr = 0;

        private id19() {
            this(java.lang.System.out);
        }

        public id19(OutputStream os) {
            this.out = os;
        }

        public id19(String path) {
            try {
                this.out = new FileOutputStream(path);
            } catch (FileNotFoundException e) {
                throw new RuntimeException("FastWriter");
            }
        }

        public id19 print(byte b) {
            buf[ptr++] = b;
            if (ptr == BUF_SIZE) innerFlush();
            return this;
        }

        public id19 print(char c) {
            return print((byte) c);
        }

        public id19 print(char[] s) {
            for (char c : s) {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            }
            return this;
        }

        public id19 print(String s) {
            s.chars().forEach(c -> {
                buf[ptr++] = (byte) c;
                if (ptr == BUF_SIZE) innerFlush();
            });
            return this;
        }

        

        public id19 print0(char[] s) {
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

        

        public id19 print0(String s) {
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

        public id19 print(int x) {
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

        public id19 print(long x) {
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

        public id19 print(double x, int precision) {
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

        public id19 println(char c) {
            return print(c).println();
        }

        public id19 println(int x) {
            return print(x).println();
        }

        public id19 println(long x) {
            return print(x).println();
        }

        public id19 println(String x) {
            return print(x).println();
        }

        public id19 println(Object x) {
            return print(x.toString()).println();
        }

        public id19 println(double x, int precision) {
            return print(x, precision).println();
        }

        public id19 println() {
            return print((byte) '\n');
        }

        public id19 printf(String format, Object... args) {
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

    private static class id13 {
        private boolean finished = false;

        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private id24 filter;

        public id13(InputStream stream) {
            this.stream = stream;
        }

        public double[] id3(int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = readDouble();
            }
            return array;
        }

        public String[] id21(int size) {
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

        public long[] id12(int size) {
            long[] array = new long[size];
            for (int i = 0; i < size; i++) {
                array[i] = readLong();
            }
            return array;
        }

        public int[] id0(int size) {
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

        public int id23() {
            while (isWhitespace(peek())) {
                read();
            }
            return peek();
        }

        public int readInt() {
            int c = read();
            while (id9(c)) {
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
            } while (!id9(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (id9(c)) {
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
            } while (!id9(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id9(c));
            return res.toString();
        }

        public char[] id2() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!id9(c));
            char[] resArr = new char[res.length()];
            res.getChars(0, res.length(), resArr, 0);
            return resArr;
        }

        public boolean id9(int c) {
            if (filter != null) {
                return filter.id9(c);
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

        public String readLine(boolean id20) {
            if (id20) {
                return readLine();
            } else {
                return id4();
            }
        }

        public char readCharacter() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            return (char) c;
        }

        public double readDouble() {
            int c = read();
            while (id9(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!id9(c) && c != '.') {
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
                while (!id9(c)) {
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
            while (id9(value = peek()) && value != -1) {
                read();
            }
            return value == -1;
        }

        public String next() {
            return readString();
        }

        public id24 getFilter() {
            return filter;
        }

        public void setFilter(id24 filter) {
            this.filter = filter;
        }

        public interface id24 {
            public boolean id9(int ch);
        }
    }

}