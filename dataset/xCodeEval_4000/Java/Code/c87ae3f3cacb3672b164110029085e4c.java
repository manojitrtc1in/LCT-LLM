

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;


import static java.util.Arrays.sort;


public class CodeforcesTemp {

    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        FastPrinter out = new FastPrinter();
        int tt = scan.nextInt();


        for (int tc = 1; tc <= tt; tc++) {
            long a = scan.nextLong();
            long b = scan.nextLong();
            long c = scan.nextLong();
            long d = scan.nextLong();
            String s = scan.next();
            long cntA1 = a + c + d;
            long cntA2 = 0;
            int n = s.length();
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == 'A') ++cntA2;
            }
            String ans = "NO";
            if (cntA1 == cntA2) {
                List<Pair> ab = new ArrayList<>();
                List<Pair> ba = new ArrayList<>();
                List<Pair> both = new ArrayList<>();
                List<Integer> li = new ArrayList<>();
                li.add(0);
                for (int i = 1; i < n; i++) {
                    if (s.charAt(i - 1) == s.charAt(i)) li.add(i);
                }
                li.add(n);
                for (int i = 1; i < li.size(); i++) {
                    int ind1 = li.get(i - 1);
                    int ind2 = li.get(i) - 1;
                    if (s.charAt(ind1) == s.charAt(ind2)) {
                        long res = (ind2 - ind1) >> 1;
                        if(res==0)continue;
                        both.add(new Pair(res, res));
                    } else {
                        long abba = (ind2 - ind1 + 1) >> 1;
                        if (s.charAt(ind1) == 'A') {
                            ab.add(new Pair(abba, abba - 1));
                        } else {
                            ba.add(new Pair(abba - 1, abba));
                        }
                    }
                }
                Collections.sort(ab,new SortByab());
                Collections.sort(ba,new SortByba());
                Collections.sort(both,new SortByab());

                int ab_ind1 = 0;
                int ba_ind2 = 0;
                while (ab_ind1 < ab.size()) {
                    if (c >= ab.get(ab_ind1).cntAB) {
                        c -= ab.get(ab_ind1).cntAB;
                    } else {
                        if(c!=0) d -= (ab.get(ab_ind1).cntAB - c) - 1;
                        else d-=ab.get(ab_ind1).cntBA;
                        c = 0;
                    }
                    ab_ind1++;
                }
                int i3 = 0;
                while (i3 < both.size()) {
                    if (c >= both.get(i3).cntAB) {
                        c -= both.get(i3).cntAB;
                    } else {
                        d -= both.get(i3).cntAB - c;
                        c = 0;
                    }
                    i3++;
                }

                while ( ba_ind2 < ba.size()) {
                    if (d >= ba.get(ba_ind2).cntBA) {
                        d -= ba.get(ba_ind2).cntBA;
                    } else {
                        if (d != 0) {
                            c -= (ba.get(ba_ind2).cntBA- d) - 1;
                            d = 0;
                        } else {
                            c -= ba.get(ba_ind2).cntAB;
                        }
                    }
                    ba_ind2++;
                }

                if (c <= 0 && d <= 0) {
                    ans = "YES";
                }
            }
            out.println(ans);
            out.flush();
        }
        out.close();
    }
    static class SortByab implements Comparator<Pair>{

        @Override
        public int compare(Pair o1, Pair o2) {
            return Long.compare(o1.cntAB,o2.cntAB);
        }
    }
    static class SortByba implements Comparator<Pair>{
        @Override
        public int compare(Pair o1, Pair o2) {
            return Long.compare(o1.cntBA,o2.cntBA);
        }
    }
    static class Pair {
        long cntAB;
        long cntBA;

        Pair(long cntAB, long cntBA) {
            this.cntAB = cntAB;
            this.cntBA = cntBA;
        }
    }

    static class Reader {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long LONG_MAX_TENTHS = 922337203685477580L;
        private static final int LONG_MAX_LAST_DIGIT = 7;
        private static final int LONG_MIN_LAST_DIGIT = 8;

        public Reader(InputStream in) {
            this.in = in;
        }

        public Reader() {
            this(System.in);
        }

        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
            return hasNextByte();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext())
                throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    int digit = b - '0';
                    if (n >= LONG_MAX_TENTHS) {
                        if (n == LONG_MAX_TENTHS) {
                            if (minus) {
                                if (digit <= LONG_MIN_LAST_DIGIT) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!isPrintableChar(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            } else {
                                if (digit <= LONG_MAX_LAST_DIGIT) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!isPrintableChar(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            }
                        }
                        throw new ArithmeticException(
                                String.format(" overflows long."));
                    }
                    n = n * 10 + digit;
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }

        public int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
                throw new NumberFormatException();
            return (int) nl;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long[] nextLongArray(int length) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] nextLongArray(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] nextIntArray(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] nextIntArrayMulti(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] nextIntArray(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] nextDoubleArray(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] nextDoubleArray(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] nextLongMatrix(int height, int width) {
            long[][] mat = new long[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextLong();
                }
            return mat;
        }

        public int[][] nextIntMatrix(int height, int width) {
            int[][] mat = new int[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextInt();
                }
            return mat;
        }

        public double[][] nextDoubleMatrix(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] nextCharMatrix(int height, int width) {
            char[][] mat = new char[height][width];
            for (int h = 0; h < height; h++) {
                String s = this.next();
                for (int w = 0; w < width; w++) {
                    mat[h][w] = s.charAt(w);
                }
            }
            return mat;
        }
    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(PrintStream stream) {
            super(stream);
        }

        public FastPrinter() {
            super(System.out);
        }

        private static String dtos(double x, int n) {
            StringBuilder sb = new StringBuilder();
            if (x < 0) {
                sb.append('-');
                x = -x;
            }
            x += Math.pow(10, -n) / 2;
            sb.append((long) x);
            sb.append(".");
            x -= (long) x;
            for (int i = 0; i < n; i++) {
                x *= 10;
                sb.append((int) x);
                x -= (int) x;
            }
            return sb.toString();
        }

        @Override
        public void print(float f) {
            super.print(dtos(f, 20));
        }

        @Override
        public void println(float f) {
            super.println(dtos(f, 20));
        }

        @Override
        public void print(double d) {
            super.print(dtos(d, 20));
        }

        @Override
        public void println(double d) {
            super.println(dtos(d, 20));
        }

        public void printArray(int[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(int[] array) {
            this.printArray(array, " ");
        }

        public void printArray(int[] array, String separator, java.util.function.IntUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsInt(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsInt(array[n - 1]));
        }

        public void printArray(int[] array, java.util.function.IntUnaryOperator map) {
            this.printArray(array, " ", map);
        }

        public void printArray(long[] array, String separator) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(array[i]);
                super.print(separator);
            }
            super.println(array[n - 1]);
        }

        public void printArray(long[] array) {
            this.printArray(array, " ");
        }

        public void printArray(long[] array, String separator, java.util.function.LongUnaryOperator map) {
            int n = array.length;
            for (int i = 0; i < n - 1; i++) {
                super.print(map.applyAsLong(array[i]));
                super.print(separator);
            }
            super.println(map.applyAsLong(array[n - 1]));
        }

        public void printArray(long[] array, java.util.function.LongUnaryOperator map) {
            this.printArray(array, " ", map);
        }

        public void printMatrix(int[][] arr) {
            for (int i = 0; i < arr.length; i++) {
                this.printArray(arr[i]);
            }
        }

        public void printCharMatrix(char[][] arr, int n, int m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    this.print(arr[i][j] + " ");
                }
                this.println();
            }
        }
    }

    static Random __r = new Random();

    static int randInt(int min, int max) {
        return __r.nextInt(max - min + 1) + min;
    }

    static void reverse(int[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            int swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(long[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            long swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(double[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            double swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void reverse(char[] a) {
        for (int i = 0, n = a.length, half = n / 2; i < half; ++i) {
            char swap = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = swap;
        }
    }

    static void shuffle(int[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            int swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void shuffle(long[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            long swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void shuffle(double[] a) {
        int n = a.length - 1;
        for (int i = 0; i < n; ++i) {
            int ind = randInt(i, n);
            double swap = a[i];
            a[i] = a[ind];
            a[ind] = swap;
        }
    }

    static void rsort(int[] a) {
        shuffle(a);
        sort(a);
    }

    static void rsort(long[] a) {
        shuffle(a);
        sort(a);
    }

    static void rsort(double[] a) {
        shuffle(a);
        sort(a);
    }

    static int[] copy(int[] a) {
        int[] ans = new int[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static long[] copy(long[] a) {
        long[] ans = new long[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static double[] copy(double[] a) {
        double[] ans = new double[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }

    static char[] copy(char[] a) {
        char[] ans = new char[a.length];
        for (int i = 0; i < a.length; ++i) ans[i] = a[i];
        return ans;
    }
}
