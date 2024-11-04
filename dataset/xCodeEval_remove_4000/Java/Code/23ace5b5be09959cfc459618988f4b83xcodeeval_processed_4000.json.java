import java.io.*;
import java.lang.reflect.Constructor;
import java.util.*;

public class CodeD {
    private static final boolean id7 = true;

    static final SuperWriter sw = new SuperWriter(System.out);

    static final SuperScanner sc = new SuperScanner();

    static class PrimeTester {
        static long mulMod(long a, long b, long n) {
            if (((a | b) >>> 31 != 0)) {
                long answer = a * b;
                if ((b == 0) || (answer / b == a)) {
                    return answer % n;
                }
            } else {
                return (a * b) % n;
            }
            long result = 0;
            if(a < b) { long tmp = a; a = b; b = tmp; }
            for(; b != 0; b >>= 1) {
                if((b & 1) != 0) {
                    result += a; if(Long.compareUnsigned(result, n) >= 0) result -= n;
                }
                a <<= 1; if(Long.compareUnsigned(a, n) >= 0) a -= n;
            }
            return result;
        }

        static long powMod(long a, long exp, long n) {
            long result = 1;
            for(; exp != 0; exp >>= 1) {
                if((exp & 1) != 0) {
                    result = mulMod(result, a, n);
                }
                a = mulMod(a, a, n);
            }
            return result;
        }

        static boolean id21(long n, long a) {
            long d = n-1, x;
            int s = 0, r;
            while ((d & 1) == 0 && d != 0){ s++; d >>= 1;}
            while (a >= n) a >>= 1;
            x = powMod(a, d, n);
            if (x != 1 && x != n-1) {
                r = 1;
                while (r <= s-1 && x != n-1) {
                    x = mulMod(x, x, n);
                    if (x == 1) return false; else r++;
                }
                if (x != n-1) return false;
            }
            return true;
        }

        static boolean isPrime(long n) {
            if (n <= 1) return false;
            if (n <= 3) return true;
            if ((n & 1) == 0) return false;
            return id21(n, 2) && id21(n, 3)
                    && id21(n, 5) && id21(n, 7)
                    && (n < 3215031751L || (id21(n, 11)
                    && (n < 2152302898747L || (id21(n, 13)
                    && (n < 3474749660383L || (id21(n, 17)
                    && (n < 341550071728321L || (id21(n, 23)))))))));
        }
    }

    static class id9 {
        static long gcd(long u, long v) {
            while(u != 0){v %= u; long tmp = u; u = v; v = tmp;} return v;
        }

        static long f(long x, long c, long n) {
            long result = PrimeTester.mulMod(x, x, n);
            result += c; if(result >= n) result -= n;
            return result;
        }

        static long id6(long n) {
            for (int c = 1;;) {
                long x = 2, y = 2, pot = 1, lam = 1, d;
                do {
                    if(pot == lam) {x = y; pot <<= 1; lam = 0;}
                    y = f(y,c,n);
                    lam++;
                    d = gcd(x >= y ? x - y : y - x, n);
                } while (d == 1);
                if (d != n) return d; else c++;
            }
        }

        static void factor(long n, Map <Long, Integer> factors)
        {
            if(n == 1)
                return;
            if(PrimeTester.isPrime(n))
            {
                if(factors.containsKey(n))
                    factors.put(n, factors.get(n) + 1);
                else
                    factors.put(n, 1);
            }
            else
            {
                long fact = id6(n);
                factor(fact, factors);
                factor(n / fact, factors);
            }
        }

        static int id24(long n)
        {
            if(n == 1)
                return 0;
            if(PrimeTester.isPrime(n))
            {
                return 1;
            }
            else
            {
                long fact = id6(n);
                return id24(fact) + id24(n / fact);
            }
        }
    }

    static int[] primes;

    static int id19(int a) {
        int powerCount = 0;
        for (int prime : primes) {
            if (prime > a) {
                break;
            }
            while (a % prime == 0) {
                a /= prime;
                powerCount++;
            }
        }
        if (a != 1) {
            powerCount++;
        }
        return powerCount;
    }

    public static void solve() {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        if (a == 1 && b == 1) {
            sw.printLine("NO");
            return;
        }
        if (k == 1) {
            if (a != b && ((a % b) == 0)) {
                sw.printLine("YES");
                return;
            }
            if (a != b && ((b % a) == 0)) {
                sw.printLine("YES");
                return;
            }
            sw.printLine("NO");
            return;
        }
        int powerCounts = id19(a) + id19(b);
        if (k <= powerCounts) {
            sw.printLine("YES");
        } else {
            sw.printLine("NO");
        }
    }

    public static void main() {
        ArrayList<Integer> id18 = new ArrayList<>();
        for (int i = 2; i < 31650; i++) {
            if (PrimeTester.isPrime(i)) {
                id18.add(i);
            }
        }
        primes = new int[id18.size()];
        for (int i = 0; i < id18.size(); i++) {
            primes[i] = id18.get(i);
        }
        int t = sc.nextInt();
        for (int cc = 0; cc < t; cc++) {
            solve();
        }
    }

    static class LineScanner extends Scanner {
        private StringTokenizer st;

        public LineScanner(String input) {
            st = new StringTokenizer(input);
        }

        @Override
        public String next() {
            return st.hasMoreTokens() ? st.nextToken() : null;
        }

        @Override
        public String nextLine() {
            throw new RuntimeException("not supported");
        }

        public boolean hasNext() {
            return st.hasMoreTokens();
        }

        private final ArrayList<Object> temp = new ArrayList<Object>();

        private void fillTemp() {
            while (st.hasMoreTokens()) {
                temp.add(st.nextToken());
            }
        }

        public String[] id1() {
            fillTemp();
            String[] answer = new String[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = (String) temp.get(i);
            }
            temp.clear();
            return answer;
        }

        public int[] id17() {
            fillTemp();
            int[] answer = new int[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Integer.parseInt((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }

        public long[] id13() {
            fillTemp();
            long[] answer = new long[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Long.parseLong((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }

        public double[] id16() {
            fillTemp();
            double[] answer = new double[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Double.parseDouble((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }
    }

    static class SuperScanner extends Scanner {
        private InputStream stream;
        private byte[] buf = new byte[8096];
        private int curChar;
        private int numChars;

        public SuperScanner() {
            this.stream = System.in;
        }

        public int read() {
            if (numChars == -1)
                return -1;
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public static boolean id4(int c) {
            return c == '\n' || c == -1;
        }

        private final StringBuilder sb = new StringBuilder();

        @Override
        public String next() {
            int c = read();
            while (isWhitespace(c)) {
                if (c == -1) {
                    return null;
                }
                c = read();
            }
            sb.setLength(0);
            do {
                sb.append((char) c);
                c = read();
            } while (!isWhitespace(c));
            return sb.toString();
        }

        @Override
        public String nextLine() {
            sb.setLength(0);
            int c;
            while (true) {
                c = read();
                if (!id4(c)) {
                    sb.append((char) c);
                } else {
                    break;
                }
            }
            if (c == -1 && sb.length() == 0) {
                return null;
            } else {
                if (sb.length() > 0 && sb.charAt(sb.length() - 1) == '\r') {
                    return sb.substring(0, sb.length() - 1);
                } else {
                    return sb.toString();
                }
            }
        }

        public LineScanner id14() {
            String line = nextLine();
            if (line == null) {
                return null;
            } else {
                return new LineScanner(line);
            }
        }

        public LineScanner id5() {
            while (true) {
                String line = nextLine();
                if (line == null) {
                    return null;
                } else if (!line.isEmpty()) {
                    return new LineScanner(line);
                }
            }
        }

        @Override
        public int nextInt() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = (res << 3) + (res << 1);
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }

        @Override
        public long nextLong() {
            int c = read();
            while (isWhitespace(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res = (res << 3) + (res << 1);
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }
    }

    static abstract class Scanner {

        public abstract String next();

        public abstract String nextLine();

        public int id8() {
            Integer n = nextInteger();
            if (n == null) {
                sw.close();
                System.exit(0);
            }
            return n.intValue();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] id10(int n) {
            int[] res = new int[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextInt();
            return res;
        }

        public long[] id23(int n) {
            long[] res = new long[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextLong();
            return res;
        }

        public double[] id20(int n) {
            double[] res = new double[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextDouble();
            return res;
        }

        public void id2(int[] array) {
            Integer[] vals = new Integer[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public void id12(long[] array) {
            Long[] vals = new Long[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public void id3(double[] array) {
            Double[] vals = new Double[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public String[] id22(int n) {
            String[] vals = new String[n];
            for (int i = 0; i < n; i++)
                vals[i] = next();
            return vals;
        }

        public Integer nextInteger() {
            String s = next();
            if (s == null)
                return null;
            return Integer.parseInt(s);
        }

        public int[][] id0(int n, int m) {
            int[][] ans = new int[n][];
            for (int i = 0; i < n; i++)
                ans[i] = id10(m);
            return ans;
        }

        public char[][] nextGrid(int r) {
            char[][] grid = new char[r][];
            for (int i = 0; i < r; i++)
                grid[i] = next().toCharArray();
            return grid;
        }

        public static <T> T fill(T arreglo, int val) {
            if (arreglo instanceof Object[]) {
                Object[] a = (Object[]) arreglo;
                for (Object x : a)
                    fill(x, val);
            } else if (arreglo instanceof int[])
                Arrays.fill((int[]) arreglo, val);
            else if (arreglo instanceof double[])
                Arrays.fill((double[]) arreglo, val);
            else if (arreglo instanceof long[])
                Arrays.fill((long[]) arreglo, val);
            return arreglo;
        }

        public <T> T[] id15(Class<T> clazz, int size) {
            @SuppressWarnings("unchecked")
            T[] result = (T[]) java.lang.reflect.Array.newInstance(clazz, size);
            for (int c = 0; c < 3; c++) {
                Constructor<T> constructor;
                try {
                    if (c == 0)
                        constructor = clazz.getDeclaredConstructor(Scanner.class,
                                Integer.TYPE);
                    else if (c == 1)
                        constructor = clazz.getDeclaredConstructor(Scanner.class);
                    else
                        constructor = clazz.getDeclaredConstructor();
                } catch (Exception e) {
                    continue;
                }
                try {
                    for (int i = 0; i < result.length; i++) {
                        if (c == 0)
                            result[i] = constructor.newInstance(this, i);
                        else if (c == 1)
                            result[i] = constructor.newInstance(this);
                        else
                            result[i] = constructor.newInstance();
                    }
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
                return result;
            }
            throw new RuntimeException("Constructor not found");
        }

        public Collection<Integer> wrap(int[] as) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            for (int i : as)
                ans.add(i);
            return ans;
        }

        public int[] unwrap(Collection<Integer> collection) {
            int[] vals = new int[collection.size()];
            int index = 0;
            for (int i : collection)
                vals[index++] = i;
            return vals;
        }

        int testCases = Integer.MIN_VALUE;

        boolean testCases() {
            if (testCases == Integer.MIN_VALUE) {
                testCases = nextInt();
            }
            return --testCases >= 0;
        }
    }

    static class SuperWriter {

        private final PrintWriter writer;

        public SuperWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public SuperWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.flush();
            writer.close();
        }

        public void printLine(String line) {
            writer.println(line);
            if (!id7) {
                writer.flush();
            }
        }

        public void printLine(int... vals) {
            if (vals.length == 0) {
                writer.println();
            } else {
                writer.print(vals[0]);
                for (int i = 1; i < vals.length; i++)
                    writer.print(" ".concat(String.valueOf(vals[i])));
                writer.println();
            }
            if (!id7) {
                writer.flush();
            }
        }

        public void printLine(long... vals) {
            if (vals.length == 0) {
                writer.println();
            } else {
                writer.print(vals[0]);
                for (int i = 1; i < vals.length; i++)
                    writer.print(" ".concat(String.valueOf(vals[i])));
                writer.println();
            }
            if (!id7) {
                writer.flush();
            }
        }

        public void printLine(double... vals) {
            if (vals.length == 0) {
                writer.println();
            } else {
                writer.print(vals[0]);
                for (int i = 1; i < vals.length; i++)
                    writer.print(" ".concat(String.valueOf(vals[i])));
                writer.println();
            }
            if (!id7) {
                writer.flush();
            }
        }

        public void printLine(int prec, double... vals) {
            if (vals.length == 0) {
                writer.println();
            } else {
                String precision = "%." + prec + "f";
                writer.print(String.format(precision, vals[0]).replace(',', '.'));
                precision = " " + precision;
                for (int i = 1; i < vals.length; i++)
                    writer.print(String.format(precision, vals[i]).replace(',', '.'));
                writer.println();
            }
            if (!id7) {
                writer.flush();
            }
        }

        public <E> void printLine(Collection<E> vals) {
            if (vals.size() == 0) {
                writer.println();
            } else {
                int i = 0;
                for (E val : vals) {
                    if (i++ == 0) {
                        writer.print(val.toString());
                    } else {
                        writer.print(" ".concat(val.toString()));
                    }
                }
                writer.println();
            }
            if (!id7) {
                writer.flush();
            }
        }

        public void printSimple(String value) {
            writer.print(value);
            if (!id7) {
                writer.flush();
            }
        }

        public boolean id11(Number... values) {
            for (Number number : values) {
                if (number.doubleValue() != 0.0d || number.longValue() != 0) {
                    return false;
                }
            }
            close();
            System.exit(0);
            return true;
        }
    }


    public static void main(String[] args) {
        main();
        sw.close();
    }
}