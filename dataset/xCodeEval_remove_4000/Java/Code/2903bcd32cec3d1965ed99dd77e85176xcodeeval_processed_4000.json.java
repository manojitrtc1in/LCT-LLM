import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.HashMap;
import java.util.Random;
import java.io.UncheckedIOException;
import java.util.stream.Stream;
import java.io.Closeable;
import java.util.Map;
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
            id9 solver = new id9();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id9 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int k = in.readInt();
            int[] b = new int[k];
            for (int i = 0; i < k; i++) {
                b[i] = in.readInt();
            }
            int n = in.readInt();
            int m = in.readInt();

            Modular mod = new Modular(998244353);
            Modular powMod = mod.id3();

            ModMatrix mat = new ModMatrix(k, k);
            for (int i = 0; i < k; i++) {
                mat.set(k - 1, i, b[k - i - 1]);
            }
            for (int i = k - 2; i >= 0; i--) {
                mat.set(i, i + 1, 1);
            }

            ModMatrix init = new ModMatrix(k, 1);
            init.set(k - 1, 0, 1);

            ModMatrix finalState = ModMatrix.mul(ModMatrix.pow(mat, n - 1, powMod), init, powMod);
            int t = finalState.get(0, 0);

            id7 root = new id7(mod, 3);
            int ans = root.root(m, t);
            out.println(ans);
        }

    }

    static class id11 {
        Modular mod;
        Modular powMod;
        int x;
        int invX;
        int phi;
        id19 map;
        int m;
        CachedPow pow;
        private static id20 id15 = new id20();

        public id11(int x, Modular mod) {
            this.x = x;
            this.mod = mod;
            phi = mod.getMod();
            powMod = new Modular(phi);
            if (id15.id2(x, mod.getMod()) != 1) {
                throw new IllegalArgumentException();
            }
            invX = mod.valueOf(id15.getX());
            pow = new CachedPow(invX, mod);

            m = (int) Math.ceil(Math.sqrt(phi));
            map = new id19(m, false);

            int prod = mod.valueOf(1);
            for (int i = 0; i < m; i++) {
                map.id6(prod, i);
                prod = mod.mul(prod, x);
            }
        }

        public int log(int y) {
            y = mod.valueOf(y);
            int start = 0;
            while (start * m < phi) {
                int inverse = pow.pow(powMod.valueOf(start * m));
                int val = map.id5(mod.mul(inverse, y), -1);
                if (val >= 0) {
                    return powMod.valueOf(val + start * m);
                }
                start++;
            }
            return -1;
        }

    }

    static interface id8 {
        boolean hasNext();

        void next();

        int id13();

        int id14();

    }

    static class ModMatrix {
        int[][] mat;
        int n;
        int m;

        public ModMatrix(ModMatrix model) {
            n = model.n;
            m = model.m;
            mat = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = model.mat[i][j];
                }
            }
        }

        public ModMatrix(int n, int m) {
            this.n = n;
            this.m = m;
            mat = new int[n][m];
        }

        public ModMatrix(int[][] mat) {
            if (mat.length == 0 || mat[0].length == 0) {
                throw new IllegalArgumentException();
            }
            this.n = mat.length;
            this.m = mat[0].length;
            this.mat = mat;
        }

        public void fill(int v) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = v;
                }
            }
        }

        public void asStandard(Modular mod) {
            fill(0);
            if (mod.getMod() == 1) {
                return;
            }
            for (int i = 0; i < n && i < m; i++) {
                mat[i][i] = 1;
            }
        }

        public void set(int i, int j, int val) {
            mat[i][j] = val;
        }

        public int get(int i, int j) {
            return mat[i][j];
        }

        public static ModMatrix mul(ModMatrix a, ModMatrix b, Modular modular) {
            ModMatrix c = new ModMatrix(a.n, b.m);
            for (int i = 0; i < c.n; i++) {
                for (int j = 0; j < c.m; j++) {
                    for (int k = 0; k < a.m; k++) {
                        c.mat[i][j] = modular.plus(c.mat[i][j], modular.mul(a.mat[i][k], b.mat[k][j]));
                    }
                }
            }
            return c;
        }

        public static ModMatrix pow(ModMatrix x, long n, Modular modular) {
            if (n == 0) {
                ModMatrix r = new ModMatrix(x.n, x.m);
                r.asStandard(modular);
                return r;
            }
            ModMatrix r = pow(x, n >> 1, modular);
            r = ModMatrix.mul(r, r, modular);
            if (n % 2 == 1) {
                r = ModMatrix.mul(r, x, modular);
            }
            return r;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    builder.append(mat[i][j]).append(' ');
                }
                builder.append('\n');
            }
            return builder.toString();
        }

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

    static class id16 {
        id18 mr = new id18();
        Gcd gcd = new Gcd();
        Random random = new Random();

        public int findFactor(int n) {
            if (mr.mr(n, 10)) {
                return n;
            }
            while (true) {
                int f = id0(random.nextInt(n), random.nextInt(n), n);
                if (f != -1) {
                    return f;
                }
            }
        }

        public Map<Integer, Integer> id4(int n) {
            Map<Integer, Integer> map = new HashMap();
            id4(map, n);
            return map;
        }

        private void id4(Map<Integer, Integer> map, int n) {
            if (n == 1) {
                return;
            }
            int f = findFactor(n);
            if (f == n) {
                Integer value = map.get(f);
                if (value == null) {
                    value = 1;
                }
                map.put(f, value * f);
                return;
            }
            id4(map, f);
            id4(map, n / f);
        }

        private int id0(int x, int c, int n) {
            int xi = x;
            int xj = x;
            int j = 2;
            int i = 1;
            while (i < n) {
                i++;
                xi = (int) ((long) xi * xi + c) % n;
                int g = gcd.gcd(n, Math.abs(xi - xj));
                if (g != 1 && g != n) {
                    return g;
                }
                if (i == j) {
                    j = j << 1;
                    xj = xi;
                }
            }
            return -1;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
        }

    }

    static class FastInput {
        private final InputStream is;
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

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

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

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public Modular id3() {
            return new Modular(m - 1);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class id18 {
        Modular modular;
        Power power;
        Random random = new Random();

        public boolean mr(int n, int s) {
            if (n == 2) {
                return true;
            }
            if (n % 2 == 0) {
                return false;
            }
            modular = new Modular(n);
            power = new Power(modular);
            for (int i = 0; i < s; i++) {
                int x = random.nextInt(n - 2) + 2;
                if (!mr0(x, n)) {
                    return false;
                }
            }
            return true;
        }

        private boolean mr0(int x, int n) {
            int exp = n - 1;
            while (true) {
                int y = power.pow(x, exp);
                if (y != 1 && y != n - 1) {
                    return false;
                }
                if (y != 1 || exp % 2 == 1) {
                    break;
                }
                exp = exp / 2;
            }
            return true;
        }

    }

    static class id20 {
        private long x;
        private long y;
        private long g;

        public long getX() {
            return x;
        }

        public long id2(long a, long b) {
            if (a >= b) {
                g = id1(a, b);
            } else {
                g = id1(b, a);
                long tmp = x;
                x = y;
                y = tmp;
            }
            return g;
        }

        private long id1(long a, long b) {
            if (b == 0) {
                x = 1;
                y = 0;
                return a;
            }
            long g = id1(b, a % b);
            long n = x;
            long m = y;
            x = m;
            y = n - m * (a / b);
            return g;
        }

    }

    static class CachedPow {
        private int[] first;
        private int[] second;
        private Modular mod;

        public CachedPow(int x, Modular mod) {
            this(x, mod.getMod(), mod);
        }

        public CachedPow(int x, int maxExp, Modular mod) {
            this.mod = mod;
            int k = Math.max(1, (int) DigitUtils.round(Math.sqrt(maxExp)));
            first = new int[k];
            second = new int[maxExp / k + 1];
            first[0] = 1;
            for (int i = 1; i < k; i++) {
                first[i] = mod.mul(x, first[i - 1]);
            }
            second[0] = 1;
            int step = mod.mul(x, first[k - 1]);
            for (int i = 1; i < second.length; i++) {
                second[i] = mod.mul(second[i - 1], step);
            }
        }

        public int pow(int exp) {
            return mod.mul(first[exp % first.length], second[exp / first.length]);
        }

    }

    static class Gcd {
        public int gcd(int a, int b) {
            return a >= b ? id17(a, b) : id17(b, a);
        }

        private int id17(int a, int b) {
            return b == 0 ? a : id17(b, a % b);
        }

    }

    static class id7 {
        private id11 log;
        private Modular mod;
        private Modular powMod;
        private static id20 id15 = new id20();
        private Power power;
        private int primitiveRoot;

        public id7(Modular p) {
            this(p, new PrimitiveRoot(p).id12());
        }

        public id7(Modular p, int g) {
            mod = p;
            log = new id11(g, mod);
            powMod = mod.id3();
            power = new Power(mod);
            primitiveRoot = g;
        }

        public int root(int x, int k) {
            x = mod.valueOf(x);
            k = powMod.valueOf(k);
            if (x == 0) {
                return 0;
            }
            if (k == 0) {
                if (x == 1) {
                    return 1;
                }
                return -1;
            }

            int logx = log.log(x);
            int gcd = (int) id15.id2(k, powMod.getMod());
            if (logx % gcd != 0) {
                return -1;
            }
            int loga = powMod.mul(logx / gcd, powMod.valueOf(id15.getX()));
            return power.pow(primitiveRoot, loga);
        }

    }

    static class id19 {
        private int[] slot;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public id19(int cap, boolean rehash) {
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
            return x ^ (x >>> 16);
        }

        public void id6(int x, int y) {
            put(x, y, false);
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
                int index = id10(s, x);
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

        public int id5(int x, int def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = id10(s, x);
            return keys[index] == x ? values[index] : def;
        }

        private int id10(int s, int x) {
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

        public id8 iterator() {
            return new id8() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int id13() {
                    return keys[readIndex];
                }


                public int id14() {
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
            id8 iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.id13()).append("->").append(iterator.id14()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
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

    static class PrimitiveRoot {
        private int[] factors;
        private Modular mod;
        private Power pow;
        int phi;
        private static id16 rho = new id16();

        public PrimitiveRoot(Modular x) {
            phi = x.getMod() - 1;
            mod = x;
            pow = new Power(mod);
            factors = rho.id4(phi).keySet().stream().mapToInt(Integer::intValue).toArray();
        }

        public PrimitiveRoot(int x) {
            this(new Modular(x));
        }

        public int id12() {
            return id12(2);
        }

        public int id12(int since) {
            for (int i = since; i < mod.m; i++) {
                boolean flag = true;
                for (int f : factors) {
                    if (pow.pow(i, phi / f) == 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
            return -1;
        }

    }
}

