import java.util.*;
import java.util.function.BinaryOperator;
import java.util.function.Predicate;

public class Main {

    public static void main(String[] args) throws Exception {
        ContestScanner in = new ContestScanner(System.in);
        ContestPrinter out = new ContestPrinter(System.out);
        Task solver = new Task();
        solver.solve(in, out);
        out.flush();
        out.close();
    }
}

class Task {

    class SegTree<S> {
        private final int n; 

        private final int size; 

        private final BinaryOperator<S> op; 

        private final S e; 

        private final S[] data;

        
        @SuppressWarnings("unchecked")
        public SegTree(int n, S e, BinaryOperator<S> op) {
            this.n = n;
            int k = 1;
            while (k < n) k <<= 1;
            this.size = k;
            this.e = e;
            this.op = op;
            this.data = (S[]) new Object[size << 1];
            Arrays.fill(data, e);
        }

        
        public SegTree(S[] dat, S e, BinaryOperator<S> op) {
            this(dat.length, e, op);
            build(dat);
        }

        private void build(S[] dat) {
            int l = dat.length;
            System.arraycopy(dat, 0, data, size, l);
            for (int i = size - 1; i > 0; i--) {
                data[i] = op.apply(data[i << 1 | 0], data[i << 1 | 1]);
            }
        }

        
        void set(int p, S x) {
            assert 0 <= p && p < n : "p=" + p;

            data[p += size] = x;
            p >>= 1;
            while (p > 0) {
                data[p] = op.apply(data[p << 1 | 0], data[p << 1 | 1]);
                p >>= 1;
            }
        }

        
        S get(int p) {
            assert 0 <= p && p < n : "p=" + p;

            return data[p + size];
        }

        
        S prod(int l, int r) {
            assert 0 <= l && l <= r && r <= n : "l=" + l + ", r=" + r;

            S sumLeft = e;
            S sumRight = e;
            l += size;
            r += size;
            while (l < r) {
                if ((l & 1) == 1) sumLeft = op.apply(sumLeft, data[l++]);
                if ((r & 1) == 1) sumRight = op.apply(data[--r], sumRight);
                l >>= 1;
                r >>= 1;
            }
            return op.apply(sumLeft, sumRight);
        }

        
        S allProd() {
            return data[1];
        }

        
        int maxRight(int l, Predicate<S> f) {
            assert 0 <= l && l <= n : "l=" + l;
            assert f.test(e);

            if (l == n) return n;
            l += size;
            S sum = e;
            do {
                l >>= Integer.numberOfTrailingZeros(l);
                if (!f.test(op.apply(sum, data[l]))) {
                    while (l < size) {
                        l = l << 1;
                        if (f.test(op.apply(sum, data[l]))) {
                            sum = op.apply(sum, data[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sum = op.apply(sum, data[l]);
                l++;
            } while ((l & -l) != l);
            return n;
        }

        
        int minLeft(int r, Predicate<S> f) {
            assert 0 <= r && r <= n : "r=" + r;
            assert f.test(e);

            if (r == 0) return 0;
            r += size;
            S sum = e;
            do {
                r--;
                while (r > 1 && (r & 1) == 1) r >>= 1;
                if (!f.test(op.apply(data[r], sum))) {
                    while (r < size) {
                        r = r << 1 | 1;
                        if (f.test(op.apply(data[r], sum))) {
                            sum = op.apply(data[r], sum);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sum = op.apply(data[r], sum);
            } while ((r & -r) != r);
            return 0;
        }

        


        private int indent = 6;

        void setIndent(int newIndent) {
            this.indent = newIndent;
        }

        @Override
        public String toString() {
            return id1();
        }

        
        String id6() {
            return id6(1, 0);
        }

        private String id6(int k, int sp) {
            if (k >= size) return indent(sp) + data[k];
            StringBuilder sb = new StringBuilder();
            sb.append(id6(k << 1 | 1, sp + indent));
            sb.append("\n");
            sb.append(indent(sp) + data[k]);
            sb.append("\n");
            sb.append(id6(k << 1 | 0, sp + indent));
            return sb.toString();
        }

        private String indent(int n) {
            StringBuilder sb = new StringBuilder();
            while (n-- > 0) sb.append(' ');
            return sb.toString();
        }

        
        String id1() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < size; i++) {
                sb.append(data[i + size]);
                if (i < size - 1) sb.append(',').append(' ');
            }
            sb.append(']');
            return sb.toString();
        }
    }

    int mod = 998244353;

    public void solve(ContestScanner in, ContestPrinter out) throws Exception {
        int n = in.nextInt();
        int q = in.nextInt();
        S[] dat = new S[n];
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            dat[i] = new S(1, 1, 1, x, x, 1);
        }
        SegTree<S> st = new SegTree<>(dat, S.E, S::op);
        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt();
                int y = in.nextInt();
                st.set(x - 1, new S(1, 1, 1, y, y, 1));
            } else {
                int l = in.nextInt() - 1;
                int r = in.nextInt();
                out.println(st.prod(l, r).cnt);
            }
        }
    }

    static class S {
        static final S E = null;
        long cnt;
        int mxLeft, mxRight;
        int leftVal, rightVal, len;

        public S(long cnt, int mxLeft, int mxRight, int leftVal, int rightVal, int len) {
            this.cnt = cnt;
            this.mxLeft = mxLeft;
            this.mxRight = mxRight;
            this.leftVal = leftVal;
            this.rightVal = rightVal;
            this.len = len;
        }

        public static S op(S s1, S s2) {
            if (s1 == E) return s2;
            if (s2 == E) return s1;
            long cnt = s1.cnt + s2.cnt + (s1.rightVal <= s2.leftVal ? 1L * s1.mxRight * s2.mxLeft : 0);
            int mxLeft = s1.mxLeft == s1.len && s1.rightVal <= s2.leftVal ? s1.mxLeft + s2.mxLeft : s1.mxLeft;
            int mxRight = s2.mxRight == s2.len && s2.leftVal >= s1.rightVal ? s2.mxRight + s1.mxRight : s2.mxRight;
            return new S(cnt, mxLeft, mxRight, s1.leftVal, s2.rightVal, s1.len + s2.len);
        }

    }

}
class ContestScanner {
    private final java.io.InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private static final long id8 = 922337203685477580L;
    private static final int id3 = 7;
    private static final int id2 = 8;

    public ContestScanner(java.io.InputStream in) {
        this.in = in;
    }

    public ContestScanner(java.io.File file) throws java.io.FileNotFoundException {
        this(new java.io.BufferedInputStream(new java.io.FileInputStream(file)));
    }

    public ContestScanner() {
        this(System.in);
    }

    private boolean id11() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (java.io.IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    private int readByte() {
        if (id11()) return buffer[ptr++];
        else return -1;
    }

    private static boolean id13(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (id11() && !id13(buffer[ptr])) ptr++;
        return id11();
    }

    public String next() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (id13(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext()) throw new java.util.NoSuchElementException();
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
                if (n >= id8) {
                    if (n == id8) {
                        if (minus) {
                            if (digit <= id2) {
                                n = -n * 10 - digit;
                                b = readByte();
                                if (!id13(b)) {
                                    return n;
                                } else if (b < '0' || '9' < b) {
                                    throw new NumberFormatException(
                                            String.format("%d%s... is not number", n, Character.toString(b))
                                    );
                                }
                            }
                        } else {
                            if (digit <= id3) {
                                n = n * 10 + digit;
                                b = readByte();
                                if (!id13(b)) {
                                    return n;
                                } else if (b < '0' || '9' < b) {
                                    throw new NumberFormatException(
                                            String.format("%d%s... is not number", n, Character.toString(b))
                                    );
                                }
                            }
                        }
                    }
                    throw new ArithmeticException(
                            String.format("%s%d%d... overflows long.", minus ? "-" : "", n, digit)
                    );
                }
                n = n * 10 + digit;
            } else if (b == -1 || !id13(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long[] id12(int length) {
        long[] array = new long[length];
        for (int i = 0; i < length; i++) array[i] = this.nextLong();
        return array;
    }

    public long[] id12(int length, java.util.function.LongUnaryOperator map) {
        long[] array = new long[length];
        for (int i = 0; i < length; i++) array[i] = map.applyAsLong(this.nextLong());
        return array;
    }

    public int[] id5(int length) {
        int[] array = new int[length];
        for (int i = 0; i < length; i++) array[i] = this.nextInt();
        return array;
    }

    public int[] id5(int length, java.util.function.IntUnaryOperator map) {
        int[] array = new int[length];
        for (int i = 0; i < length; i++) array[i] = map.applyAsInt(this.nextInt());
        return array;
    }

    public double[] id10(int length) {
        double[] array = new double[length];
        for (int i = 0; i < length; i++) array[i] = this.nextDouble();
        return array;
    }

    public double[] id10(int length, java.util.function.DoubleUnaryOperator map) {
        double[] array = new double[length];
        for (int i = 0; i < length; i++) array[i] = map.applyAsDouble(this.nextDouble());
        return array;
    }

    public long[][] id4(int height, int width) {
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

    public double[][] id9(int height, int width) {
        double[][] mat = new double[height][width];
        for (int h = 0; h < height; h++)
            for (int w = 0; w < width; w++) {
                mat[h][w] = this.nextDouble();
            }
        return mat;
    }

    public char[][] id7(int height, int width) {
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

class ContestPrinter extends java.io.PrintWriter {
    public ContestPrinter(java.io.PrintStream stream) {
        super(stream);
    }

    public ContestPrinter(java.io.File file) throws java.io.FileNotFoundException {
        super(new java.io.PrintStream(file));
    }

    public ContestPrinter() {
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
        if (n == 0) {
            super.println();
            return;
        }
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
        if (n == 0) {
            super.println();
            return;
        }
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
        if (n == 0) {
            super.println();
            return;
        }
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
        if (n == 0) {
            super.println();
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            super.print(map.applyAsLong(array[i]));
            super.print(separator);
        }
        super.println(map.applyAsLong(array[n - 1]));
    }

    public void printArray(long[] array, java.util.function.LongUnaryOperator map) {
        this.printArray(array, " ", map);
    }

    public <T> void printArray(T[] array, String separator) {
        int n = array.length;
        if (n == 0) {
            super.println();
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            super.print(array[i]);
            super.print(separator);
        }
        super.println(array[n - 1]);
    }

    public <T> void printArray(T[] array) {
        this.printArray(array, " ");
    }

    public <T> void printArray(T[] array, String separator, java.util.function.UnaryOperator<T> map) {
        int n = array.length;
        if (n == 0) {
            super.println();
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            super.print(map.apply(array[i]));
            super.print(separator);
        }
        super.println(map.apply(array[n - 1]));
    }

    public <T> void printArray(T[] array, java.util.function.UnaryOperator<T> map) {
        this.printArray(array, " ", map);
    }
}



