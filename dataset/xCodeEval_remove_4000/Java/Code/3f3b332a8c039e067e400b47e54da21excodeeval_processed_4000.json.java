

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.*;

import static java.util.Arrays.*;


public class id9 {

    static class SegmentTree {
        static int size = 1;
        public long[] SegmentTree(int n) {
            size = 1;
            while (size < n) size *= 2;
            long[] st = new long[2 * size];
            return st;
        }

        void set1(int ind, long val, long[] st, int x, int l, int r) {
            if (r - l == 1) {
                st[x] = val;
                return;
            }
            int m = (l + r) / 2;
            if (ind < m) {
                set1(ind, val, st, 2 * x + 1, l, m);
            } else {
                set1(ind, val, st, 2 * x + 2, m, r);
            }
            st[x] = Math.max(st[2 * x + 1] , st[2 * x + 2]);
        }

        void set(int ind, long val,long[] st) {
            set1(ind, val, st, 0, 0, size);
        }

        void id8(int start, int end, long[] st, int l, int r, int x, long[] res) {
            if (r <= start || l >= end) {
                return;
            }
            if (l >= start && r <= end) {
                res[0] =Math.max(res[0],st[x]);
                return;
            }
            int m = (l + r) / 2;
            id8(start, end, st, l, m, 2 * x + 1, res);
            id8(start, end, st, m, r, 2 * x + 2, res);
        }

        long getMax(int l, int r,long[] st) {
            long[] res = new long[1];
            res[0] = Long.MIN_VALUE;
            id8(l, r, st, 0, size, 0, res);
            return res[0];
        }

        void build(long[] arr, int n,long[] st) {
            int[] ind = new int[1];
            ind[0] = 0;
            Build1(st, arr, 0, size, 0, ind);
        }

        private void Build1(long[] st, long[] arr, int l, int r, int x, int[] ind) {
            if (r - l == 1) {
                if (ind[0] < arr.length) {
                    st[x] = arr[ind[0]++];
                }
                return;
            }
            int m = (l + r) / 2;
            Build1(st, arr, l, m, 2 * x + 1, ind);
            Build1(st, arr, m, r, 2 * x + 2, ind);
            st[x] =Math.max(st[2 * x + 1] ,st[2 * x + 2]);
        }
    }

    public static void main(String[] args) throws IOException {
        Reader scan = new Reader();
        FastPrinter out = new FastPrinter();
        int tt = scan.nextInt();
        outer:
        for (int tc = 1; tc <= tt; tc++) {
            int n = scan.nextInt();
            long[] arr = scan.id16(n);
            int[] prevGreater = new int[n];
            int[] nextGreater = new int[n];
            id3(arr, prevGreater, n);
            id4(arr, nextGreater, n);
            long[] prefix = new long[n];
            long[] suffix = new long[n];
            long min=arr[0];
            for (int i = 0; i < n; i++) {
                prefix[i] = arr[i];
                if (i != 0) {
                    prefix[i] += prefix[i - 1];
                   min=Math.min(arr[i],min);
                }

            }
            for (int i = n - 1; i >= 0; i--) {
                suffix[i] = arr[i];
                if (i != n - 1) {
                    suffix[i] += suffix[i + 1];
                }
            }
            SegmentTree st=new SegmentTree();
            long[] st1=st.SegmentTree(n);
            Arrays.fill(st1,Long.MIN_VALUE);
            long[] st2=st.SegmentTree(n);
            Arrays.fill(st2,Long.MIN_VALUE);
            st.build(prefix,n,st1);
            st.build(suffix,n,st2);
            for (int i = 0; i < n; i++) {
                

                long id14 = st.getMax(i,nextGreater[i],st1);
                id14 -= prefix[i];
                if (id14 > 0) {
                    out.println("NO");
                    continue outer;
                }
                

                id14 = st.getMax(prevGreater[i] + 1, i+1,st2);
                id14 -= suffix[i];
                if (id14 > 0) {
                    out.println("NO");
                    continue outer;
                }
            }
            out.println("YES");
            out.flush();
        }
        out.close();
    }

    private static void id4(long[] arr, int[] nextGreater, int n) {
        Stack<Integer> st = new Stack<>();
        nextGreater[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (st.size() > 0 && arr[st.peek()] <= arr[i]) {
                st.pop();
            }
            nextGreater[i] = (st.size() == 0) ? n : st.peek();
            st.push(i);
        }
    }

    private static void id3(long[] arr, int[] prevGreater, int n) {
        Stack<Integer> st = new Stack<>();
        prevGreater[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (st.size() > 0 && arr[st.peek()] <= arr[i]) {
                st.pop();
            }
            prevGreater[i] = (st.size() == 0) ? -1 : st.peek();
            st.push(i);
        }
    }


    static class Reader {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private static final long id11 = 922337203685477580L;
        private static final int id2 = 7;
        private static final int id1 = 8;

        public Reader(InputStream in) {
            this.in = in;
        }

        public Reader() {
            this(System.in);
        }

        private boolean id15() {
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
            if (id15()) return buffer[ptr++];
            else return -1;
        }

        private static boolean id17(int c) {
            return 33 <= c && c <= 126;
        }

        public boolean hasNext() {
            while (id15() && !id17(buffer[ptr])) ptr++;
            return id15();
        }

        public String next() {
            if (!hasNext())
                throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (id17(b)) {
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
                    if (n >= id11) {
                        if (n == id11) {
                            if (minus) {
                                if (digit <= id1) {
                                    n = -n * 10 - digit;
                                    b = readByte();
                                    if (!id17(b)) {
                                        return n;
                                    } else if (b < '0' || '9' < b) {
                                        throw new NumberFormatException(
                                                String.format("not number"));
                                    }
                                }
                            } else {
                                if (digit <= id2) {
                                    n = n * 10 + digit;
                                    b = readByte();
                                    if (!id17(b)) {
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
                } else if (b == -1 || !id17(b)) {
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

        public long[] id16(int length) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextLong();
            return array;
        }

        public long[] id16(int length, java.util.function.LongUnaryOperator map) {
            long[] array = new long[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsLong(this.nextLong());
            return array;
        }

        public int[] id7(int length) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextInt();
            return array;
        }

        public int[][] id6(int length, int width) {
            int[][] arrays = new int[width][length];
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < width; j++)
                    arrays[j][i] = this.nextInt();
            }
            return arrays;
        }

        public int[] id7(int length, java.util.function.IntUnaryOperator map) {
            int[] array = new int[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsInt(this.nextInt());
            return array;
        }

        public double[] id13(int length) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = this.nextDouble();
            return array;
        }

        public double[] id13(int length, java.util.function.DoubleUnaryOperator map) {
            double[] array = new double[length];
            for (int i = 0; i < length; i++)
                array[i] = map.applyAsDouble(this.nextDouble());
            return array;
        }

        public long[][] id5(int height, int width) {
            long[][] mat = new long[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextLong();
                }
            return mat;
        }

        public int[][] id0(int height, int width) {
            int[][] mat = new int[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextInt();
                }
            return mat;
        }

        public double[][] id12(int height, int width) {
            double[][] mat = new double[height][width];
            for (int h = 0; h < height; h++)
                for (int w = 0; w < width; w++) {
                    mat[h][w] = this.nextDouble();
                }
            return mat;
        }

        public char[][] id10(int height, int width) {
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
