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
        CJuryMeeting solver = new CJuryMeeting();
        solver.solve(1, in, out);
        out.close();
    }

    static class CJuryMeeting {
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
            int[] qs = in.nextIntArray(jm);
            Arrays.sort(qs);
            int highest = qs[qs.length - 1];
            int[] qsr = ArrayUtils.removeAllOccurences(qs, highest);
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
            int[] qsh = ArrayUtils.removeAllOccurences(qsr, secondHighest);
            int numSecondHighest = qsr.length - qsh.length;
            if (highest - secondHighest > 1) {
                out.println(0);
                return;
            }

            

            s = (int) Modular.subtract(s, Modular.factorial(jm - 1));
            int numChoices = qsh.length;
            for (int i = 1; i < jm - numSecondHighest; i++) {
                int after = i;
                int before = jm - 1 - i;
                s = Math.floorMod(s - ((Modular.factorial(before) * (Modular.permute(numChoices, after)))), mod);
            }
            out.println(Math.floorMod(s, mod));
        }

    }

    static interface EzLongIterator {
        boolean hasNext();

        long next();

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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
            while (isSpaceChar(c)) {
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static final class Longs {
        private Longs() {
        }

        public static int compare(long a, long b) {
            return (a < b) ? -1 : ((a > b) ? 1 : 0);
        }

    }

    static final class UnsignedLongs {
        private UnsignedLongs() {
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

    static class EzLongArrayList implements EzLongList, EzLongStack {
        private static final int DEFAULT_CAPACITY = 10;
        private static final double ENLARGE_SCALE = 2.0;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private long[] array;
        private int size;

        public EzLongArrayList() {
            this(DEFAULT_CAPACITY);
        }

        public EzLongArrayList(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new long[capacity];
            size = 0;
        }

        public EzLongArrayList(EzLongCollection collection) {
            size = collection.size();
            array = new long[size];
            int i = 0;
            for (EzLongIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public EzLongArrayList(long[] srcArray) {
            size = srcArray.length;
            array = new long[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public EzLongArrayList(Collection<Long> javaCollection) {
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

        public EzLongIterator iterator() {
            return new EzLongArrayListIterator();
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
            int newSize = Math.max(size + 1, (int) (size * ENLARGE_SCALE));
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
            EzLongArrayList that = (EzLongArrayList) o;

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
            int hash = HASHCODE_INITIAL_VALUE;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(array[i])) * HASHCODE_MULTIPLIER;
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

        private class EzLongArrayListIterator implements EzLongIterator {
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

    static interface EzLongCollection {
        int size();

        EzLongIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class LongMath {
        static final long FLOOR_SQRT_MAX_LONG = 3037000499L;
        private static final int SIEVE_30 = ~((1 << 1) | (1 << 7) | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19) | (1 << 23)
                | (1 << 29));
        private static final long[][] millerRabinBaseSets = {
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
                MathPreconditions.checkNonNegative("n", n);
                return false;
            }
            if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13) {
                return true;
            }

            if ((SIEVE_30 & (1 << (n % 30))) != 0) {
                return false;
            }
            if (n % 7 == 0 || n % 11 == 0 || n % 13 == 0) {
                return false;
            }
            if (n < 17 * 17) {
                return true;
            }

            for (long[] baseSet : millerRabinBaseSets) {
                if (n <= baseSet[0]) {
                    for (int i = 1; i < baseSet.length; i++) {
                        if (!LongMath.MillerRabinTester.test(baseSet[i], n)) {
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

        private enum MillerRabinTester {
            
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

                
                private long times2ToThe32Mod(long a, long m) {
                    int remainingPowersOf2 = 32;
                    do {
                        int shift = Math.min(remainingPowersOf2, Long.numberOfLeadingZeros(a));
                        

                        

                        a = UnsignedLongs.remainder(a << shift, m);
                        remainingPowersOf2 -= shift;
                    } while (remainingPowersOf2 > 0);
                    return a;
                }


                long mulMod(long a, long b, long m) {
                    long aHi = a >>> 32; 

                    long bHi = b >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 

                    long bLo = b & 0xFFFFFFFFL; 


                    
                    long result = times2ToThe32Mod(aHi * bHi , m); 

                    result += aHi * bLo; 

                    if (result < 0) {
                        result = UnsignedLongs.remainder(result, m);
                    }
                    

                    result += aLo * bHi; 

                    result = times2ToThe32Mod(result, m); 

                    return plusMod(result, UnsignedLongs.remainder(aLo * bLo , m), m);
                }


                long squareMod(long a, long m) {
                    long aHi = a >>> 32; 

                    long aLo = a & 0xFFFFFFFFL; 


                    
                    long result = times2ToThe32Mod(aHi * aHi , m); 

                    long hiLo = aHi * aLo * 2;
                    if (hiLo < 0) {
                        hiLo = UnsignedLongs.remainder(hiLo, m);
                    }
                    

                    result += hiLo; 

                    result = times2ToThe32Mod(result, m); 

                    return plusMod(result, UnsignedLongs.remainder(aLo * aLo , m), m);
                }
            },
            ;

            static boolean test(long base, long n) {
                

                

                return ((n <= FLOOR_SQRT_MAX_LONG) ? SMALL : LARGE).testWitness(base, n);
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

    static interface EzLongList extends EzLongCollection {
        int size();

        EzLongIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class EzIntSort {
        private static final double HEAPSORT_DEPTH_COEFFICIENT = 2.0;
        private static final Random rnd = new Random(System.nanoTime());

        private EzIntSort() {
        }

        private static int maxQuickSortDepth(int length) {
            if (length <= 1) {
                return 0;
            }
            int log = Integer.numberOfTrailingZeros(Integer.highestOneBit(length - 1)) + 1;
            return (int) (HEAPSORT_DEPTH_COEFFICIENT * log);
        }

        public static void sort(int[] a) {
            quickSort(a, 0, a.length, 0, maxQuickSortDepth(a.length));
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

    static interface EzLongStack extends EzLongCollection {
        int size();

        EzLongIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static final class PrimitiveHashCalculator {
        private PrimitiveHashCalculator() {
        }

        public static int getHash(long x) {
            return (int) x ^ (int) (x >>> 32);
        }

    }

    static final class MathPreconditions {
        static long checkNonNegative(String role, long x) {
            if (x < 0) {
                throw new IllegalArgumentException(role + " (" + x + ") must be >= 0");
            }
            return x;
        }

        private MathPreconditions() {
        }

    }

    static class ArrayUtils {
        public static final int INDEX_NOT_FOUND = -1;

        public static int getLength(final Object array) {
            if (array == null) {
                return 0;
            }
            return Array.getLength(array);
        }

        public static BitSet indexesOf(final int[] array, final int valueToFind) {
            return indexesOf(array, valueToFind, 0);
        }

        public static BitSet indexesOf(final int[] array, final int valueToFind, int startIndex) {
            final BitSet bitSet = new BitSet();

            if (array == null) {
                return bitSet;
            }

            while (startIndex < array.length) {
                startIndex = indexOf(array, valueToFind, startIndex);

                if (startIndex == INDEX_NOT_FOUND) {
                    break;
                }

                bitSet.set(startIndex);
                ++startIndex;
            }

            return bitSet;
        }

        public static int indexOf(final int[] array, final int valueToFind, int startIndex) {
            if (array == null) {
                return INDEX_NOT_FOUND;
            }
            if (startIndex < 0) {
                startIndex = 0;
            }
            for (int i = startIndex; i < array.length; i++) {
                if (valueToFind == array[i]) {
                    return i;
                }
            }
            return INDEX_NOT_FOUND;
        }

        static Object removeAll(final Object array, final BitSet indices) {
            if (array == null) {
                return null;
            }

            final int srcLength = getLength(array);
            

            









            final int removals = indices.cardinality(); 

            final Object result = Array.newInstance(array.getClass().getComponentType(), srcLength - removals);
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

        public static int[] removeAllOccurences(final int[] array, final int element) {
            return (int[]) removeAll((Object) array, indexesOf(array, element));
        }

        public ArrayUtils() {
        }

    }

    static class Arrays {
        private Arrays() {
        }

        public static void sort(int[] a) {
            EzIntSort.sort(a);
        }

    }

    static class Modular {
        public static int MOD;
        public static int SAVE_INV = 1000005;
        public static long[] save_inv = new long[SAVE_INV];
        static EzLongArrayList _factorial;
        static EzLongArrayList _inv_factorial;
        static long prepared_maximum = 1;

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

        static void prepare_factorials(long maximum) {
            if (_factorial == null) {
                _factorial = new EzLongArrayList(2);
                _inv_factorial = new EzLongArrayList(2);

                _factorial.add(1);
                _factorial.add(1);

                _inv_factorial.add(1);
                _inv_factorial.add(1);
            }

            if (maximum <= prepared_maximum)
                return;

            

            maximum += maximum / 16;
            _factorial.enlarge((int) (maximum + 1));
            _inv_factorial.enlarge((int) (maximum + 1));

            for (long i = prepared_maximum + 1; i <= maximum; i++)
                _factorial.set((int) i, (long) multiply(i, _factorial.get((int) (i - 1))));

            _inv_factorial.set((int) maximum, getInverse(_factorial.get((int) maximum)));

            for (long i = maximum - 1; i > prepared_maximum; i--)
                _inv_factorial.set((int) i, (long) multiply(i + 1, _inv_factorial.get((int) (i + 1))));

            prepared_maximum = maximum;
        }

        public static long factorial(long n) {
            if (n < 0) return 0;
            prepare_factorials(n);
            return _factorial.get((int) n);
        }

        public static long permute(long n, long r) {
            if (r < 0 || r > n) return 0;
            prepare_factorials(n);
            return multiply(_factorial.get((int) n), _inv_factorial.get((int) (n - r)));
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

