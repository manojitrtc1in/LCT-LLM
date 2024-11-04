import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
import java.util.BitSet;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id24 solver = new id24();
        solver.solve(1, in, out);
        out.close();
    }

    static class id24 {
        static final int mod = 998244353;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Modular.initialize(mod);
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            int jm = in.nextInt();
            int[] qs = in.id12(jm);
            Arrays.sort(qs);
            int highest = qs[qs.length - 1];
            int[] qsr = ArrayUtils.id11(qs, highest);
            int numHighest = qs.length - qsr.length;
            var s = Modular.factorial(jm);
            if (numHighest > 1) {
                out.println(s);
                return;
            }

            if (qsr.length == 0) {
                out.println(s);
                return;
            }
            int secondHighest = qsr[qsr.length - 1];
            int[] qsh = ArrayUtils.id11(qsr, secondHighest);
            int id3 = qsr.length - qsh.length;
            if (highest - secondHighest > 1) {
                out.println(0);
                return;
            }

            

            s = (int) Modular.subtract(s, Modular.factorial(jm - 1));
            int numChoices = qsh.length;
            for (int i = 1; i < jm - id3; i++) {
                int after = i;
                int before = jm - 1 - i;
                s = Math.floorMod(s - ((Modular.factorial(before) * (Modular.permute(numChoices, after)))), mod);
            }
            out.println(Math.floorMod(s, mod));
        }

    }

    static interface id25 {
        boolean hasNext();

        long next();

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id31 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
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

        public int nextInt() {
            int c = read();
            while (id6(c)) {
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
            } while (!id6(c));
            return res * sgn;
        }

        public boolean id6(int c) {
            if (filter != null) {
                return filter.id6(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] id12(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface id31 {
            public boolean id6(int ch);

        }

    }

    static final class Longs {
        private Longs() {
        }

        public static int compare(long a, long b) {
            return (a < b) ? -1 : ((a > b) ? 1 : 0);
        }

    }

    static final class id29 {
        private id29() {
        }

        private static long flip(long a) {
            return a ^ Long.MIN_VALUE;
        }

        public static int compare(long a, long b) {
            return Longs.compare(flip(a), flip(b));
        }

        public static long remainder(long dividend, long divisor) {
            if (divisor < 0) { 

                if (compare(dividend, divisor) < 0) {
                    return dividend; 

                } else {
                    return dividend - divisor; 

                }
            }

            

            if (dividend >= 0) {
                return dividend % divisor;
            }

            
            long quotient = ((dividend >>> 1) / divisor) << 1;
            long rem = dividend - quotient * divisor;
            return rem - (compare(rem, divisor) >= 0 ? divisor : 0);
        }

    }

    static class id9 implements id4, id26 {
        private static final int id28 = 10;
        private static final double id8 = 2.0;
        private static final int id16 = 0x811c9dc5;
        private static final int id30 = 0x01000193;
        private long[] array;
        private int size;

        public id9() {
            this(id28);
        }

        public id9(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new long[capacity];
            size = 0;
        }

        public id9(id7 collection) {
            size = collection.size();
            array = new long[size];
            int i = 0;
            for (id25 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id9(long[] srcArray) {
            size = srcArray.length;
            array = new long[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id9(Collection<Long> javaCollection) {
            size = javaCollection.size();
            array = new long[size];
            int i = 0;
            for (long element : javaCollection) {
                array[i++] = element;
            }
        }

        public int size() {
            return size;
        }

        public id25 iterator() {
            return new id20();
        }

        public boolean add(long element) {
            if (size == array.length) {
                enlarge();
            }
            array[size++] = element;
            return true;
        }

        public long get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return array[index];
        }

        public long set(int index, long element) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            final long oldElement = array[index];
            array[index] = element;
            return oldElement;
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id8));
            long[] newArray = new long[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public void enlarge(int newSize) {
            newSize = Math.max(size + 1, newSize);
            long[] newArray = new long[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
            size = newSize;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id9 that = (id9) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < size; i++) {
                if (array[i] != that.array[i]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id16;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id13.getHash(array[i])) * id30;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < size; i++) {
                sb.append(array[i]);
                if (i < size - 1) {
                    sb.append(", ");
                }
            }
            sb.append(']');
            return sb.toString();
        }

        private class id20 implements id25 {
            private int curIndex = 0;

            public boolean hasNext() {
                return curIndex < size;
            }

            public long next() {
                if (curIndex == size) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return array[curIndex++];
            }

        }

    }

    static interface id7 {
        int size();

        id25 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class LongMath {
        static final long id19 = 3037000499L;
        private static final int id27 = ~((1 << 1) | (1 << 7) | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19) | (1 << 23)
                | (1 << 29));
        private static final long[][] id0 = {
                {291830, 126401071349994536L},
                {885594168, 725270293939359937L, 3569819667048198375L},
                {273919523040L, 15, 7363882082L, 992620450144556L},
                {47636622961200L, 2, 2570940, 211991001, 3749873356L},
                {
                        7999252175582850L,
                        2,
                        4130806001517L,
                        149795463772692060L,
                        186635894390467037L,
                        3967304179347715805L
                },
                {
                        585226005592931976L,
                        2,
                        123635709730000L,
                        9233062284813009L,
                        43835965440333360L,
                        761179012939631437L,
                        1263739024124850375L
                },
                {Long.MAX_VALUE, 2, 325, 9375, 28178, 450775, 9780504, 1795265022}
        };

        public static boolean isPrime(long n) {
            if (n < 2) {
                id5.id15("n", n);
                return false;
            }
            if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
                return true;
            }

            if ((id27 & (1 << (n % 30))) != 0) {
                return false;
            }
            if (n % 7 == 0 || n % 11 == 0 || n % 13 == 0) {
                return false;
            }
            if (n < 17 * 17) {
                return true;
            }

            for (long[] baseSet : id0) {
                if (n <= baseSet[0]) {
                    for (int i = 1; i < baseSet.length; i++) {
                        if (!LongMath.id23.test(baseSet[i], n)) {
                            return false;
                        }
                    }
                    return true;
                }
            }
            throw new AssertionError();
        }

        private LongMath() {
        }

        private enum id23 {
            
            SMALL {
                long mulMod(long a, long b, long m) {
                    
                    return (a * b) % m;
                }


                long squareMod(long a, long m) {
                    return (a * a) % m;
                }
            },
            
            LARGE {
                
                private long plusMod(long a, long b, long m) {
                    return (a >= m - b) ? (a + b - m) : (a + b);
                }

                
                private long id17(long a, long m) {
                    int id34 = 32;
                    do {
                        int shift = Math.min(id34, Long.numberOfLeadingZeros(a));
                        

                        

                        a = id29.remainder(a << shift, m);
                        id34 -= shift;
                    } while (id34 > 0);
                    return a;
                }


                long mulMod(long a, long b, long m) {
                    long aHi = a >>> 32; 

                    long bHi = b >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 

                    long bLo = b & 0xFFFFFFFFL; 


                    
                    long result = id17(aHi * bHi , m); 

                    result += aHi * bLo; 

                    if (result < 0) {
                        result = id29.remainder(result, m);
                    }
                    

                    result += aLo * bHi; 

                    result = id17(result, m); 

                    return plusMod(result, id29.remainder(aLo * bLo , m), m);
                }


                long squareMod(long a, long m) {
                    long aHi = a >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 


                    
                    long result = id17(aHi * aHi , m); 

                    long hiLo = aHi * aLo * 2;
                    if (hiLo < 0) {
                        hiLo = id29.remainder(hiLo, m);
                    }
                    

                    result += hiLo; 

                    result = id17(result, m); 

                    return plusMod(result, id29.remainder(aLo * aLo , m), m);
                }
            },
            ;

            static boolean test(long base, long n) {
                

                

                return ((n <= id19) ? SMALL : LARGE).testWitness(base, n);
            }

            abstract long mulMod(long a, long b, long m);

            abstract long squareMod(long a, long m);

            private long powMod(long a, long p, long m) {
                long res = 1;
                for (; p != 0; p >>= 1) {
                    if ((p & 1) != 0) {
                        res = mulMod(res, a, m);
                    }
                    a = squareMod(a, m);
                }
                return res;
            }

            private boolean testWitness(long base, long n) {
                int r = Long.numberOfTrailingZeros(n - 1);
                long d = (n - 1) >> r;
                base %= n;
                if (base == 0) {
                    return true;
                }
                

                long a = powMod(base, d, n);
                

                

                

                if (a == 1) {
                    return true;
                }
                int j = 0;
                while (a != n - 1) {
                    if (++j == r) {
                        return false;
                    }
                    a = squareMod(a, n);
                }
                return true;
            }

        }

    }

    static interface id4 extends id7 {
        int size();

        id25 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id22 {
        private static final double id1 = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private id22() {
        }

        private static int id18(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (id1 * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, id18(a.length));
        }

        private static void quickSort(int[] a, int left, int right, int depth, int maxDepth) {
            if (right - left <= 1) {
                return;
            }
            if (depth > maxDepth) {
                heapSort(a, left, right - left);
                return;
            }
            final int pivot = a[left + rnd.nextInt(right - left)];
            int i = left;
            int j = right - 1;
            do {
                while (a[i] < pivot) i++;
                while (pivot < a[j]) j--;
                if (i <= j) {
                    int tmp = a[i];
                    a[i++] = a[j];
                    a[j--] = tmp;
                }
            } while (i <= j);
            quickSort(a, left, j + 1, depth + 1, maxDepth);
            quickSort(a, i, right, depth + 1, maxDepth);
        }

        private static void heapSort(int[] a, int offset, int size) {
            

            for (int i = (size >>> 1) - 1; i >= 0; i--) {
                down(a, i, offset, size);
            }
            for (int i = size - 1; i > 0; i--) {
                int tmp = a[offset];
                a[offset] = a[offset + i];
                a[offset + i] = tmp;
                down(a, 0, offset, i);
            }
        }

        private static void down(int[] a, int index, int offset, int size) {
            final int element = a[offset + index];
            final int firstLeaf = (size >>> 1);
            while (index < firstLeaf) {
                int largestChild = (index << 1) + 1;
                if (largestChild + 1 < size && a[offset + largestChild + 1] > a[offset + largestChild]) {
                    largestChild++;
                }
                if (a[offset + largestChild] <= element) {
                    break;
                }
                a[offset + index] = a[offset + largestChild];
                index = largestChild;
            }
            a[offset + index] = element;
        }

    }

    static interface id26 extends id7 {
        int size();

        id25 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class id13 {
        private id13() {
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static final class id5 {
        static long id15(String role, long x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        private id5() {
        }

    }

    static class ArrayUtils {
        public static final int id33 = -1;

        public static int getLength(final Object array) {
            if (array == null) {
                return 0;
            }
            return Array.getLength(array);
        }

        public static BitSet indexesOf(final int[] array, final int id2) {
            return indexesOf(array, id2, 0);
        }

        public static BitSet indexesOf(final int[] array, final int id2, int startIndex) {
            final BitSet bitSet = new BitSet();

            if (array == null) {
                return bitSet;
            }

            while (startIndex < array.length) {
                startIndex = indexOf(array, id2, startIndex);

                if (startIndex == id33) {
                    break;
                }

                bitSet.set(startIndex);
                ++startIndex;
            }

            return bitSet;
        }

        public static int indexOf(final int[] array, final int id2, int startIndex) {
            if (array == null) {
                return id33;
            }
            if (startIndex < 0) {
                startIndex = 0;
            }
            for (int i = startIndex; i < array.length; i++) {
                if (id2 == array[i]) {
                    return i;
                }
            }
            return id33;
        }

        static Object removeAll(final Object array, final BitSet indices) {
            if (array == null) {
                return null;
            }

            final int srcLength = getLength(array);
            

            









            final int id21 = indices.cardinality(); 

            final Object result = Array.newInstance(array.getClass().getComponentType(), srcLength - id21);
            int srcIndex = 0;
            int destIndex = 0;
            int count;
            int set;
            while ((set = indices.nextSetBit(srcIndex)) != -1) {
                count = set - srcIndex;
                if (count > 0) {
                    System.arraycopy(array, srcIndex, result, destIndex, count);
                    destIndex += count;
                }
                srcIndex = indices.nextClearBit(set);
            }
            count = srcLength - srcIndex;
            if (count > 0) {
                System.arraycopy(array, srcIndex, result, destIndex, count);
            }
            return result;
        }

        public static int[] id11(final int[] array, final int element) {
            return (int[]) removeAll((Object) array, indexesOf(array, element));
        }

        public ArrayUtils() {
        }

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            id22.sort(a);
        }

    }

    static class Modular {
        public static int MOD;
        public static int SAVE_INV = 1000005;
        public static long[] save_inv = new long[SAVE_INV];
        static id9 _factorial;
        static id9 id10;
        static long id32 = 1;

        public static long subtract(long val, long other) {
            return Math.floorMod(val - other, MOD);
        }

        public static long multiply(long val, long other) {
            return Math.floorMod(val * other, MOD);
        }

        public static void initialize(int mod) {
            MOD = mod;
            

            assert LongMath.isPrime(mod);

            save_inv[0] = 0;
            save_inv[1] = 1;

            for (int i = 2; i < SAVE_INV; i++)
                save_inv[i] = multiply(save_inv[MOD % i], (MOD - MOD / i));
        }

        public static long getInverse(long val) {
            if (val < SAVE_INV)
                return save_inv[(int) val];

            long product = 1;
            long v = val;

            while (v >= SAVE_INV) {
                product = (long) multiply(product, MOD - MOD / v);
                v = MOD % v;
            }

            return multiply(product, save_inv[(int) v]);
        }

        static void id14(long maximum) {
            if (_factorial == null) {
                _factorial = new id9(2);
                id10 = new id9(2);

                _factorial.add(1);
                _factorial.add(1);

                id10.add(1);
                id10.add(1);
            }

            if (maximum <= id32)
                return;

            

            maximum += maximum / 16;
            _factorial.enlarge((int) (maximum + 1));
            id10.enlarge((int) (maximum + 1));

            for (long i = id32 + 1; i <= maximum; i++)
                _factorial.set((int) i, (long) multiply(i, _factorial.get((int) (i - 1))));

            id10.set((int) maximum, getInverse(_factorial.get((int) maximum)));

            for (long i = maximum - 1; i > id32; i--)
                id10.set((int) i, (long) multiply(i + 1, id10.get((int) (i + 1))));

            id32 = maximum;
        }

        public static long factorial(long n) {
            if (n < 0) return 0;
            id14(n);
            return _factorial.get((int) n);
        }

        public static long permute(long n, long r) {
            if (r < 0 || r > n) return 0;
            id14(n);
            return multiply(_factorial.get((int) n), id10.get((int) (n - r)));
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}

