import java.io.*;
import java.lang.reflect.Constructor;
import java.util.*;

public class CodeD {
    private static final boolean SHOULD_BUFFER_OUTPUT = true;

    static final SuperWriter sw = new SuperWriter(System.out);

    static final SuperScanner sc = new SuperScanner();

    static class Answer {
        SpecialNumber specialNumber;
        int x;
        int y;

        Answer(SpecialNumber specialNumber, int x, int y) {
            this.specialNumber = specialNumber;
            this.x = x;
            this.y = y;
        }

        Answer max(Answer otherAnswer) {
            SpecialNumber maxSpecialNumber = specialNumber.max(otherAnswer.specialNumber);
            if (maxSpecialNumber == specialNumber) {
                return this;
            } else {
                return otherAnswer;
            }
        }

        Answer min(Answer otherAnswer) {
            SpecialNumber minSpecialNumber = specialNumber.min(otherAnswer.specialNumber);
            if (minSpecialNumber == specialNumber) {
                return this;
            } else {
                return otherAnswer;
            }
        }

        Answer cloneAnswer() {
            return new Answer(specialNumber, x, y);
        }
    }

    static class SpecialNumber {
        int powerOfTwo;
        int sign;

        SpecialNumber(int n) {
            if (n == 0) {
                this.powerOfTwo = 0;
                this.sign = 0;
            } else if (n == 1) {
                this.powerOfTwo = 0;
                this.sign = 1;
            } else if (n == 2) {
                this.powerOfTwo = 1;
                this.sign = 1;
            } else if (n == -1) {
                this.powerOfTwo = 0;
                this.sign = -1;
            } else {
                this.powerOfTwo = 1;
                this.sign = -1;
            }
        }

        SpecialNumber(int powerOfTwo, int sign) {
            this.powerOfTwo = powerOfTwo;
            this.sign = sign;
        }

        SpecialNumber multiply(SpecialNumber other) {
            if (this.sign == 0 || other.sign == 0) {
                return new SpecialNumber(0);
            }
            return new SpecialNumber(this.powerOfTwo + other.powerOfTwo, this.sign * other.sign);
        }

        SpecialNumber max(SpecialNumber other) {
            if (this.sign == -1) {
                if (other.sign == -1) {
                    if (this.powerOfTwo < other.powerOfTwo) {
                        return this;
                    } else {
                        return other;
                    }
                }
                if (other.sign == 0) {
                    return other;
                }
                if (other.sign == 1) {
                    return other;
                }
            }
            if (this.sign == 0) {
                if (other.sign == -1) {
                    return this;
                }
                if (other.sign == 0) {
                    return this;
                }
                if (other.sign == 1) {
                    return other;
                }
            }
            if (other.sign == -1) {
                return this;
            }
            if (other.sign == 0) {
                return this;
            }
            if (this.powerOfTwo > other.powerOfTwo) {
                return this;
            }
            return other;
        }

        SpecialNumber min(SpecialNumber other) {
            if (this.sign == -1) {
                if (other.sign == -1) {
                    if (this.powerOfTwo > other.powerOfTwo) {
                        return this;
                    } else {
                        return other;
                    }
                }
                if (other.sign == 0) {
                    return this;
                }
                if (other.sign == 1) {
                    return this;
                }
            }
            if (this.sign == 0) {
                if (other.sign == -1) {
                    return other;
                }
                if (other.sign == 0) {
                    return this;
                }
                if (other.sign == 1) {
                    return this;
                }
            }
            if (other.sign == -1) {
                return other;
            }
            if (other.sign == 0) {
                return other;
            }
            if (this.powerOfTwo < other.powerOfTwo) {
                return this;
            }
            return other;
        }
    }

    static SpecialNumber[] a;
    static Answer[][][] dp;

    static Answer dp(int currentIndex, boolean alreadyStarted, boolean getMax) {
        if (currentIndex == dp.length) {
            if (!alreadyStarted) {
                return new Answer(new SpecialNumber(1), a.length, 0);
            } else {
                return new Answer(new SpecialNumber(1), 0, 0);
            }
        }
        if (dp[currentIndex][alreadyStarted ? 1 : 0][getMax ? 1 : 0] != null) {
            return dp[currentIndex][alreadyStarted ? 1 : 0][getMax ? 1 : 0];
        }
        if (!alreadyStarted) {
            Answer possibilityA1 = dp(currentIndex + 1, true, getMax).cloneAnswer();
            possibilityA1.specialNumber = possibilityA1.specialNumber.multiply(a[currentIndex]);
            possibilityA1.x = currentIndex;
            Answer possibilityA2 = dp(currentIndex + 1, true, !getMax).cloneAnswer();
            possibilityA2.specialNumber = possibilityA2.specialNumber.multiply(a[currentIndex]);
            possibilityA2.x = currentIndex;
            Answer possibilityB = dp(currentIndex + 1, false, getMax).cloneAnswer();
            Answer answer;
            if (getMax) {
                answer = possibilityA1.max(possibilityA2);
                answer = answer.max(possibilityB);
            } else {
                answer = possibilityA1.min(possibilityA2);
                answer = answer.min(possibilityB);
            }
            return dp[currentIndex][alreadyStarted ? 1 : 0][getMax ? 1 : 0] = answer;
        } else {
            Answer possibilityA1 = dp(currentIndex + 1, true, getMax).cloneAnswer();
            possibilityA1.specialNumber = possibilityA1.specialNumber.multiply(a[currentIndex]);
            Answer possibilityA2 = dp(currentIndex + 1, true, !getMax).cloneAnswer();
            possibilityA2.specialNumber = possibilityA2.specialNumber.multiply(a[currentIndex]);
            Answer possibilityB = new Answer(new SpecialNumber(1), 0, a.length - currentIndex);
            Answer answer;
            if (getMax) {
                answer = possibilityA1.max(possibilityA2);
                answer = answer.max(possibilityB);
            } else {
                answer = possibilityA1.min(possibilityA2);
                answer = answer.min(possibilityB);
            }
            return dp[currentIndex][alreadyStarted ? 1 : 0][getMax ? 1 : 0] = answer;
        }
    }

    public static void solve() {
        int n = sc.nextInt();
        a = new SpecialNumber[n];
        dp = new Answer[n][2][2];
        for (int i = 0; i < n; i++) {
            a[i] = new SpecialNumber(sc.nextInt());
        }
        Answer answer = dp(0, false, true);
        sw.printLine(answer.x, answer.y);
    }

    public static void main() {
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

        public String[] asStringArray() {
            fillTemp();
            String[] answer = new String[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = (String) temp.get(i);
            }
            temp.clear();
            return answer;
        }

        public int[] asIntArray() {
            fillTemp();
            int[] answer = new int[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Integer.parseInt((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }

        public long[] asLongArray() {
            fillTemp();
            long[] answer = new long[temp.size()];
            for (int i = 0; i < answer.length; i++) {
                answer[i] = Long.parseLong((String) temp.get(i));
            }
            temp.clear();
            return answer;
        }

        public double[] asDoubleArray() {
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

        public static boolean isLineEnd(int c) {
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
                if (!isLineEnd(c)) {
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

        public LineScanner nextLineScanner() {
            String line = nextLine();
            if (line == null) {
                return null;
            } else {
                return new LineScanner(line);
            }
        }

        public LineScanner nextNonEmptyLineScanner() {
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

        public int nextIntOrQuit() {
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

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextInt();
            return res;
        }

        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextLong();
            return res;
        }

        public double[] nextDoubleArray(int n) {
            double[] res = new double[n];
            for (int i = 0; i < res.length; i++)
                res[i] = nextDouble();
            return res;
        }

        public void sortIntArray(int[] array) {
            Integer[] vals = new Integer[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public void sortLongArray(long[] array) {
            Long[] vals = new Long[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public void sortDoubleArray(double[] array) {
            Double[] vals = new Double[array.length];
            for (int i = 0; i < array.length; i++)
                vals[i] = array[i];
            Arrays.sort(vals);
            for (int i = 0; i < array.length; i++)
                array[i] = vals[i];
        }

        public String[] nextStringArray(int n) {
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

        public int[][] nextIntMatrix(int n, int m) {
            int[][] ans = new int[n][];
            for (int i = 0; i < n; i++)
                ans[i] = nextIntArray(m);
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

        public <T> T[] nextObjectArray(Class<T> clazz, int size) {
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
            if (!SHOULD_BUFFER_OUTPUT) {
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
            if (!SHOULD_BUFFER_OUTPUT) {
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
            if (!SHOULD_BUFFER_OUTPUT) {
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
            if (!SHOULD_BUFFER_OUTPUT) {
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
            if (!SHOULD_BUFFER_OUTPUT) {
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
            if (!SHOULD_BUFFER_OUTPUT) {
                writer.flush();
            }
        }

        public void printSimple(String value) {
            writer.print(value);
            if (!SHOULD_BUFFER_OUTPUT) {
                writer.flush();
            }
        }

        public boolean ifZeroExit(Number... values) {
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
