import javafx.util.Pair;

import java.io.*;
import java.util.*;
import java.util.function.Function;

public class Main {
    private final static InputReader ir = new InputReader(System.in);
    private final static OutputWriter ow = new OutputWriter(System.out);
    private final static int INF = Integer.MAX_VALUE;
    private final static int NINF = Integer.MIN_VALUE;
    private final static double PI = Math.PI;

    public static void main(String[] args) throws IOException {
        try {
            task();
        } finally {
            boolean exc = false;
            try {
                ir.close();
            } catch (IOException e) {
                e.printStackTrace();
                exc = true;
            }
            try {
                ow.close();
            } catch (IOException e) {
                e.printStackTrace();
                exc = true;
            }
            if (exc) System.exit(1);
        }
    }

    private static void task() throws IOException {
        int n = ir.nextInt(), m = ir.nextInt();
        int[][] a = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = ir.nextInt();
            }
        }
        int[] cnt = new int[n];
        for (int i = 0; i < m; ++i) {
            int jmax = 0;
            for (int j = 0; j < n; ++j) {
                if (a[i][j] > a[i][jmax]) {
                    jmax = j;
                }
            }
            cnt[jmax]++;
        }
        

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > cnt[ans])
                ans = i;
        }

        ow.print(ans + 1);
    }

    private static int max(int... objects) {
        if (objects.length == 0)
            throw new IllegalArgumentException("objects.length == 0");
        int max = objects[0];
        for (int i = 1; i < objects.length; ++i) {
            if (max < objects[i])
                max = objects[i];
        }
        return max;
    }

    private static int min(int... objects) {
        if (objects.length == 0)
            throw new IllegalArgumentException("objects.length == 0");
        int min = objects[0];
        for (int i = 1; i < objects.length; ++i) {
            if (min > objects[i])
                min = objects[i];
        }
        return min;
    }

    private static long pow(int x, int n) {
        if (x == 0) return 0;
        if (x == 1 || n == 0) return 1;
        if (x == 2) return x << (n - 1);
        if (n == 1) return x;
        long t = pow(x, n / 2);
        if (n % 2 == 0) return t * t;
        else return t * t * x;
    }

    private static double pow(double x, int n) {
        if (x == 0.0) return 0;
        if (x == 1.0 || n == 0) return 1;
        if (n == 1) return x;
        double t = pow(x, n / 2);
        if (n % 2 == 0) return t * t;
        else return t * t * x;
    }

    private static int abs(int a) {
        return (a >= 0 ? a : -a);
    }
}

class id4 {
    private int[] array;
    private int len;
    private int[] max;
    private int[] min;

    public id4(int[] arr, boolean useIt) {
        if (useIt)
            array = arr;
        else {
            array = new int[arr.length];
            System.arraycopy(arr, 0, array, 0, arr.length);
        }
        len = (int) Math.sqrt(array.length) + 1;
        max = new int[len];
        min = new int[len];
        for (int i = 0; i < array.length; ++i) {
            max[i / len] = min[i / len] = array[i];
        }
        for (int i = 0; i < array.length; ++i) {
            max[i / len] = Math.max(max[i / len], array[i]);
            min[i / len] = Math.min(min[i / len], array[i]);
        }
    }

    public int get(int i) {
        if (i <= 0 || i >= array.length)
            throw new IndexOutOfBoundsException("Index: " + i);
        return array[i];
    }

    public int length() {
        return array.length;
    }

    public int max(int l, int r) {
        int cl = l / len, cr = r / len;
        int m = array[l];
        if (cl == cr) {
            for (int i = l; i <= r; ++i) {
                if (array[i] > m) m = array[i];
            }
        } else {
            for (int i = l, end = (cl + 1) * len - 1; i <= end; ++i)
                if (array[i] > m) m = array[i];
            for (int i = cl + 1; i <= cr - 1; ++i)
                if (max[i] > m) m = max[i];
            for (int i = cr * len; i <= r; ++i)
                if (array[i] > m) m = array[i];
        }
        return m;
    }

    public int min(int l, int r) {
        int cl = l / len, cr = r / len;
        int m = array[l];
        if (cl == cr) {
            for (int i = l; i <= r; ++i) {
                if (array[i] < m) m = array[i];
            }
        } else {
            for (int i = l, end = (cl + 1) * len - 1; i <= end; ++i)
                if (array[i] < m) m = array[i];
            for (int i = cl + 1; i <= cr - 1; ++i)
                if (min[i] < m) m = min[i];
            for (int i = cr * len; i <= r; ++i)
                if (array[i] < m) m = array[i];
        }
        return m;
    }
}

class InputReader implements AutoCloseable {
    private final InputStream in;
    private int capacity;
    private byte[] buffer;
    private int len = 0;
    private int cur = 0;

    public InputReader(InputStream stream) {
        this(stream, 100_000);
    }

    public InputReader(InputStream stream, int capacity) {
        this.in = stream;
        this.capacity = capacity;
        buffer = new byte[capacity];
    }

    private boolean update() {
        if (cur >= len) {
            try {
                cur = 0;
                len = in.read(buffer, 0, capacity);
                if (len <= 0)
                    return false;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }
        return true;
    }

    private int read() {
        if (update())
            return buffer[cur++];
        else return -1;
    }

    public boolean isEmpty() {
        return !update();
    }

    private boolean isSpace(int c) {
        return c == '\n' || c == '\t' || c == '\r' || c == ' ';
    }

    private boolean isEscape(int c) {
        return c == '\n' || c == '\t' || c == '\r' || c == -1;
    }

    private int id6() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public int nextInt() {
        int c = id6();
        if (c < 0)
            throw new InputMismatchException();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c == -1) break;
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = res * 10 + c - '0';
            if (res < 0)
                throw new InputMismatchException();
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

    public int[] id2() {
        List<Integer> list = new LinkedList<>();
        while (true) {
            try {
                int t = nextInt();
                list.add(t);
            } catch (InputMismatchException e) {
                break;
            }
        }
        int[] a = new int[list.size()];
        Iterator<Integer> it = list.iterator();
        for (int i = 0; it.hasNext(); ++i)
            a[i] = it.next();
        return a;
    }

    public int[] id7(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; ++i) {
            array[i] = nextInt();
        }
        return array;
    }

    public int[][] id1(int n, int m) {
        int[][] array = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                array[i][j] = nextInt();
        }
        return array;
    }

    public long nextLong() {
        int c = id6();
        if (c < 0)
            throw new InputMismatchException();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c == -1) break;
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = res * 10 + c - '0';
            if (res < 0)
                throw new InputMismatchException();
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

    public long[] id0() {
        List<Long> list = new LinkedList<>();
        while (true) {
            try {
                long t = nextLong();
                list.add(t);
            } catch (InputMismatchException e) {
                break;
            }
        }
        long[] a = new long[list.size()];
        Iterator<Long> it = list.iterator();
        for (int i = 0; it.hasNext(); ++i)
            a[i] = it.next();
        return a;
    }

    public long[] id3(int n) {
        long[] array = new long[n];
        for (int i = 0; i < n; ++i) {
            array[i] = nextLong();
        }
        return array;
    }

    public long[][] id5(int n, int m) {
        long[][] array = new long[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                array[i][j] = nextLong();
        }
        return array;
    }

    public int nextChar() {
        int c = id6();
        if (c < 0)
            throw new InputMismatchException();
        return c;
    }

    public String nextLine(int initialCapacity) {
        StringBuilder res = new StringBuilder(initialCapacity);
        int c = id6();
        do {
            res.append((char) (c));
            c = read();
        } while (!isEscape(c));
        return res.toString();
    }

    @Override
    public void close() throws IOException {
        in.close();
    }
}

class OutputWriter implements Flushable, AutoCloseable {
    private byte[] buf;
    private final int capacity;
    private int count;
    private OutputStream out;

    public OutputWriter(OutputStream stream) {
        this(stream, 10_000);
    }

    public OutputWriter(OutputStream stream, int capacity) {
        if (capacity < 0)
            throw new IllegalArgumentException("capacity < 0");
        out = stream;
        this.capacity = capacity;
        if (capacity != 0) {
            buf = new byte[capacity];
        }
    }

    public void write(int b) throws IOException {
        if (capacity != 0) {
            if (count >= capacity)
                flushBuffer();
            buf[count++] = (byte) b;
        } else {
            out.write(b);
        }
    }

    public void write(byte[] bytes, int off, int len) throws IOException {
        if (capacity != 0) {
            if (len >= capacity) {
                flushBuffer();
                out.write(bytes, off, len);
                return;
            }
            if (len > capacity - count)
                flushBuffer();
            System.arraycopy(bytes, off, buf, count, len);
            count += len;
        } else out.write(bytes, off, len);
    }

    public void write(byte[] bytes) throws IOException {
        write(bytes, 0, bytes.length);
    }

    public void println() throws IOException {
        print("\n");
    }

    public void print(Object object) throws IOException {
        write(String.valueOf(object).getBytes());
    }

    public void println(Object object) throws IOException {
        print(object);
        println();
    }

    public void print(int... ints) throws IOException {
        print(" ", ints);
    }

    public void println(int... ints) throws IOException {
        print(ints);
        println();
    }

    public void println(String separator, int... ints) throws IOException {
        print(separator, ints);
        println();
    }

    public void print(String separator, int... ints) throws IOException {
        if (ints.length == 0) throw new IllegalArgumentException("ints.length == 0");
        for (int i = 0; i < ints.length; ++i) {
            if (i != 0) print(separator);
            print(ints[i]);
        }
    }

    private void flushBuffer() throws IOException {
        if (count > 0) {
            out.write(buf, 0, count);
            count = 0;
        }
    }

    @Override
    public void flush() throws IOException {
        flushBuffer();
        out.flush();
    }

    @Override
    public void close() throws IOException {
        flush();
        out.close();
    }
}



