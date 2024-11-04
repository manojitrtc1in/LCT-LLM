import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.math.BigDecimal;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.Serializable;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            id4 solver = new id4();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class id4 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            id0 y = new id0(n);
            id0 x = new id0(n);
            for (int i = 0; i < 2 * n; i++) {
                int a = in.ri();
                int b = in.ri();
                if (a == 0) {
                    y.add(Math.abs(b));
                } else {
                    x.add(Math.abs(a));
                }
            }
            x.sort();
            y.sort();
            id6 sum = new id6();
            for (int i = 0; i < n; i++) {
                sum.add(dist(x.get(i), y.get(i)));
            }
            out.println(sum.sum());
        }

        public double dist(double x, double y) {
            return Math.sqrt(x * x + y * y);
        }

    }

    static class id6 {
        private double error;
        private double sum;

        public double sum() {
            return sum;
        }

        public void add(double x) {
            x = x - error;
            double t = sum + x;
            error = (t - sum) - x;
            sum = t;
        }

        public String toString() {
            return new BigDecimal(sum).toString();
        }

    }

    static class SequenceUtils {
        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }

    static strictfp class id9 implements Serializable, Cloneable {
        private static final int N = 624;
        private static final int M = 397;
        private static final int id3 = 0x9908b0df;
        private static final int id1 = 0x80000000;
        private static final int id11 = 0x7fffffff;
        private static final int id7 = 0x9d2c5680;
        private static final int id2 = 0xefc60000;
        private int[] mt;
        private int mti;
        private int[] mag01;
        private boolean id5;

        public Object clone() {
            try {
                id9 f = (id9) (super.clone());
                f.mt = (int[]) (mt.clone());
                f.mag01 = (int[]) (mag01.clone());
                return f;
            } catch (CloneNotSupportedException e) {
                throw new InternalError();
            } 

        }

        public id9() {
            this(System.currentTimeMillis());
        }

        public id9(long seed) {
            setSeed(seed);
        }

        public id9(int[] array) {
            setSeed(array);
        }

        public void setSeed(long seed) {
            

            

            id5 = false;

            mt = new int[N];

            mag01 = new int[2];
            mag01[0] = 0x0;
            mag01[1] = id3;

            mt[0] = (int) (seed & 0xffffffff);
            for (mti = 1; mti < N; mti++) {
                mt[mti] =
                        (1812433253 * (mt[mti - 1] ^ (mt[mti - 1] >>> 30)) + mti);
                
                
                
                
                

                
            }
        }

        public void setSeed(int[] array) {
            if (array.length == 0)
                throw new IllegalArgumentException("Array length must be greater than zero");
            int i, j, k;
            setSeed(19650218);
            i = 1;
            j = 0;
            k = (N > array.length ? N : array.length);
            for (; k != 0; k--) {
                mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >>> 30)) * 1664525)) + array[j] + j; 
                

                i++;
                j++;
                if (i >= N) {
                    mt[0] = mt[N - 1];
                    i = 1;
                }
                if (j >= array.length) j = 0;
            }
            for (k = N - 1; k != 0; k--) {
                mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >>> 30)) * 1566083941)) - i; 
                

                i++;
                if (i >= N) {
                    mt[0] = mt[N - 1];
                    i = 1;
                }
            }
            mt[0] = 0x80000000; 
        }

        public int nextInt(int n) {
            if (n <= 0)
                throw new IllegalArgumentException("n must be positive, got: " + n);

            if ((n & -n) == n)  

            {
                int y;

                if (mti >= N)   

                {
                    int kk;
                    final int[] mt = this.mt; 

                    final int[] mag01 = this.mag01; 


                    for (kk = 0; kk < N - M; kk++) {
                        y = (mt[kk] & id1) | (mt[kk + 1] & id11);
                        mt[kk] = mt[kk + M] ^ (y >>> 1) ^ mag01[y & 0x1];
                    }
                    for (; kk < N - 1; kk++) {
                        y = (mt[kk] & id1) | (mt[kk + 1] & id11);
                        mt[kk] = mt[kk + (M - N)] ^ (y >>> 1) ^ mag01[y & 0x1];
                    }
                    y = (mt[N - 1] & id1) | (mt[0] & id11);
                    mt[N - 1] = mt[M - 1] ^ (y >>> 1) ^ mag01[y & 0x1];

                    mti = 0;
                }

                y = mt[mti++];
                y ^= y >>> 11;                          

                y ^= (y << 7) & id7;       

                y ^= (y << 15) & id2;      

                y ^= (y >>> 18);                        


                return (int) ((n * (long) (y >>> 1)) >> 31);
            }

            int bits, val;
            do {
                int y;

                if (mti >= N)   

                {
                    int kk;
                    final int[] mt = this.mt; 

                    final int[] mag01 = this.mag01; 


                    for (kk = 0; kk < N - M; kk++) {
                        y = (mt[kk] & id1) | (mt[kk + 1] & id11);
                        mt[kk] = mt[kk + M] ^ (y >>> 1) ^ mag01[y & 0x1];
                    }
                    for (; kk < N - 1; kk++) {
                        y = (mt[kk] & id1) | (mt[kk + 1] & id11);
                        mt[kk] = mt[kk + (M - N)] ^ (y >>> 1) ^ mag01[y & 0x1];
                    }
                    y = (mt[N - 1] & id1) | (mt[0] & id11);
                    mt[N - 1] = mt[M - 1] ^ (y >>> 1) ^ mag01[y & 0x1];

                    mti = 0;
                }

                y = mt[mti++];
                y ^= y >>> 11;                          

                y ^= (y << 7) & id7;       

                y ^= (y << 15) & id2;      

                y ^= (y >>> 18);                        


                bits = (y >>> 1);
                val = bits % n;
            } while (bits - val + (n - 1) < 0);
            return val;
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder id10 = new StringBuilder(1 << 13);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public String next() {
            return readString();
        }

        public int ri() {
            return readInt();
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            id10.setLength(0);
            return readString(id10);
        }

    }

    static class id0 implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public id0(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public id0(int[] data) {
            this(0);
            addAll(data);
        }

        public id0(id0 list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public id0() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException("Access [" + i + "]");
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(id0 list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.shuffle(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof id0)) {
                return false;
            }
            id0 other = (id0) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public id0 clone() {
            id0 ans = new id0();
            ans.addAll(this);
            return ans;
        }

    }

    static class RandomWrapper {
        private id9 random;
        public static final RandomWrapper INSTANCE = new RandomWrapper();

        public RandomWrapper() {
            this(new id9());
        }

        public RandomWrapper(id9 random) {
            this.random = random;
        }

        public RandomWrapper(long seed) {
            this(new id9(seed));
        }

        public int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int id8 = 32 << 10;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(id8 * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < id8) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(double c) {
            cache.append(new BigDecimal(c).toPlainString());
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(double c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
        }

        public FastOutput flush() {
            try {




















                os.append(cache);


                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class Randomized {
        public static void shuffle(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return RandomWrapper.INSTANCE.nextInt(l, r);
        }

    }
}
