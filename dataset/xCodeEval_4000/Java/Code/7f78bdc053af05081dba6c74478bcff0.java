import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
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
            DPowerTower solver = new DPowerTower();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DPowerTower {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] w = new int[n];
            for (int i = 0; i < n; i++) {
                w[i] = in.readInt();
            }



















            IntegerModPowerLink link = new IntegerModPowerLink(i -> w[i]);
            int q = in.readInt();
            for (int i = 0; i < q; i++) {
                int l = in.readInt() - 1;
                int r = in.readInt() - 1;
                int ans = link.query(l, r, m);
                out.println(ans);
            }
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    }

    static interface IntegerEntryIterator {
        boolean hasNext();

        void next();

        int getEntryKey();

        int getEntryValue();

    }

    static class IntegerHashMap {
        private int[] slot;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public IntegerHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new int[cap + 1];
            values = new int[cap + 1];
            removed = new boolean[cap + 1];
            this.rehash = rehash;
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
            values = Arrays.copyOf(values, newSize);
            removed = Arrays.copyOf(removed, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private void rehash() {
            int[] newSlots = new int[Math.max(16, slot.length * 2)];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
                if (slot[i] == 0) {
                    continue;
                }
                int head = slot[i];
                while (head != 0) {
                    int n = next[head];
                    int s = hash(keys[head]) & newMask;
                    next[head] = newSlots[s];
                    newSlots[s] = head;
                    head = n;
                }
            }
            this.slot = newSlots;
            this.mask = newMask;
        }

        private int hash(int x) {
            int h = Integer.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void put(int x, int y) {
            put(x, y, true);
        }

        public void put(int x, int y, boolean cover) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                values[alloc] = y;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                    values[alloc] = y;
                } else if (cover) {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public int getOrDefault(int x, int def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        private int findIndexOrLastEntry(int s, int x) {
            int iter = slot[s];
            while (keys[iter] != x) {
                if (next[iter] != 0) {
                    iter = next[iter];
                } else {
                    return iter;
                }
            }
            return iter;
        }

        public IntegerEntryIterator iterator() {
            return new IntegerEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int getEntryKey() {
                    return keys[readIndex];
                }


                public int getEntryValue() {
                    return values[readIndex];
                }


                public void next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    readIndex = index;
                    index++;
                }
            };
        }

        public String toString() {
            IntegerEntryIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.getEntryKey()).append("->").append(iterator.getEntryValue()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static class MillerRabin {
        Modular modular;
        Power power;
        Random random = new Random();

        public boolean mr(int n, int s) {
            if (n <= 1) {
                return false;
            }
            if (n == 2) {
                return true;
            }
            if (n % 2 == 0) {
                return false;
            }
            int m = n - 1;
            while (m % 2 == 0) {
                m /= 2;
            }
            modular = new Modular(n);
            power = new Power(modular);
            for (int i = 0; i < s; i++) {
                int x = random.nextInt(n - 2) + 2;
                if (!mr0(x, n, m)) {
                    return false;
                }
            }
            return true;
        }

        private boolean mr0(int x, int n, int m) {
            return test(power.pow(x, m), m, n);
        }

        private boolean test(int y, int exp, int n) {
            int y2 = modular.mul(y, y);
            if (!(exp == n - 1 || test(y2, exp * 2, n))) {
                return false;
            }
            if (exp != n - 1 && y2 != 1) {
                return true;
            }
            if (y != 1 && y != n - 1) {
                return false;
            }
            return true;
        }

    }

    static class CachedEulerFunction {
        private static int boundary = 1 << 16;
        private static MultiplicativeFunctionSieve sieve = new MultiplicativeFunctionSieve(boundary, false, true, false);
        private static IntegerHashMap map = new IntegerHashMap(64, true);
        private static PollardRho rho = new PollardRho();

        public static int get(int x) {
            if (x <= boundary) {
                return sieve.euler[x];
            }
            int ans = map.getOrDefault(x, -1);
            if (ans == -1) {
                int factor = rho.findPrimeFactor(x);
                int y = x;
                int exp = 1;
                while (y % factor == 0) {
                    y /= factor;
                    exp *= factor;
                }
                ans = get(y) * (exp - exp / factor);
                map.put(x, ans);
            }
            return ans;
        }

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class GCDs {
        private GCDs() {
        }

        public static int gcd(int a, int b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static int gcd0(int a, int b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

    }

    static class PollardRho {
        MillerRabin mr = new MillerRabin();
        Random random = new Random(1);

        public int findFactor(int n) {
            if (mr.mr(n, 5)) {
                return n;
            }
            while (true) {
                int f = rho(n);
                if (f != n) {
                    return f;
                }
            }
        }

        public int findPrimeFactor(int n) {
            int ans = findFactor(n);
            return ans == n ? ans : findPrimeFactor(ans);
        }

        private int rho(int n) {
            if (n % 2 == 0) {
                return 2;
            }
            if (n % 3 == 0) {
                return 3;
            }
            int x = 0, y = x, t, q = 1, c = random.nextInt(n - 1) + 1;
            for (int k = 2; ; k <<= 1, y = x, q = 1) {
                for (int i = 1; i <= k; ++i) {
                    x = DigitUtils.mod((long) x * x + c, n);
                    q = DigitUtils.mod((long) q * Math.abs(x - y), n);
                    if ((i & 127) == 0) {
                        t = GCDs.gcd(q, n);
                        if (t > 1) {
                            return t;
                        }
                    }
                }
                if ((t = GCDs.gcd(q, n)) > 1) {
                    return t;
                }
            }
        }

    }

    static class MultiplicativeFunctionSieve {
        public int[] primes;
        public boolean[] isComp;
        public int primeLength;
        public int[] mobius;
        public int[] euler;
        public int[] factors;
        public int[] smallestPrimeFactor;
        public int[] numberOfSmallestPrimeFactor;

        public MultiplicativeFunctionSieve(int limit, boolean enableMobius, boolean enableEuler, boolean enableFactors) {
            isComp = new boolean[limit + 1];
            primes = new int[limit + 1];
            numberOfSmallestPrimeFactor = new int[limit + 1];
            smallestPrimeFactor = new int[limit + 1];
            primeLength = 0;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[primeLength++] = i;
                    numberOfSmallestPrimeFactor[i] = smallestPrimeFactor[i] = i;
                }
                for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    smallestPrimeFactor[pi] = primes[j];
                    numberOfSmallestPrimeFactor[pi] = smallestPrimeFactor[i] == primes[j]
                            ? (numberOfSmallestPrimeFactor[i] * numberOfSmallestPrimeFactor[primes[j]])
                            : numberOfSmallestPrimeFactor[primes[j]];
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }

            if (enableMobius) {
                mobius = new int[limit + 1];
                mobius[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        mobius[i] = -1;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] != smallestPrimeFactor[i]) {
                            mobius[i] = 0;
                        } else {
                            mobius[i] = mobius[numberOfSmallestPrimeFactor[i]] * mobius[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }

            if (enableEuler) {
                euler = new int[limit + 1];
                euler[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        euler[i] = i - 1;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] == i) {
                            euler[i] = i - i / smallestPrimeFactor[i];
                        } else {
                            euler[i] = euler[numberOfSmallestPrimeFactor[i]] * euler[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }

            if (enableFactors) {
                factors = new int[limit + 1];
                factors[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        factors[i] = 2;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] == i) {
                            factors[i] = 1 + factors[i / smallestPrimeFactor[i]];
                        } else {
                            factors[i] = factors[numberOfSmallestPrimeFactor[i]]
                                    * factors[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }
        }

    }

    static interface IntegerFunction {
        int apply(int x);

    }

    static class Power {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

    }

    static class IntegerModPowerLink {
        private IntegerFunction f;
        private static int limit = Integer.MAX_VALUE;

        public IntegerModPowerLink(IntegerFunction f) {
            this.f = f;
        }

        private int test(int l, int r) {
            int val = f.apply(l);
            if (l == r) {
                return val;
            }
            if (val == 1) {
                return val;
            }
            int prev = test(l + 1, r);
            return prev < limit ? DigitUtils.limitPow(val, prev, limit) : limit;
        }

        public int query(int l, int r, int m) {
            int val = f.apply(l);
            if (l == r) {
                return DigitUtils.mod(val, m);
            }
            if (val == 1) {
                return DigitUtils.mod(val, m);
            }
            if (m == 1) {
                return 0;
            }
            int t = test(l + 1, Math.min(l + 5, r));
            if (t < limit) {
                return DigitUtils.modPow(val, t, m);
            }
            int expMod = CachedEulerFunction.get(m);
            int exp = query(l + 1, r, expMod);
            exp += expMod;
            return DigitUtils.modPow(val, exp, m);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(long x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return (int) x;
        }

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static int limitPow(int x, long n, int limit) {
            if (n == 0) {
                return Math.min(1, limit);
            }
            int ans = limitPow(x, n / 2, limit);
            ans = (int) Math.min((long) ans * ans, limit);
            if (n % 2 == 1) {
                ans = (int) Math.min((long) ans * x, limit);
            }
            return ans;
        }

        public static int modPow(int x, long n, int m) {
            if (n == 0) {
                return DigitUtils.mod(1, m);
            }
            int ans = modPow(x, n / 2, m);
            ans = DigitUtils.mod((long) ans * ans, m);
            if (n % 2 == 1) {
                ans = DigitUtils.mod((long) ans * x, m);
            }
            return ans;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
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
}

