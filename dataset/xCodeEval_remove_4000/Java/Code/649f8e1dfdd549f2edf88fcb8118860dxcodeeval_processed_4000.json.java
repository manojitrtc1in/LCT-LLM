import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            id2 solver = new id2();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id2 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            id5 sieve = new id5(1000000);
            id13 allPrime = Factorization.id12(1000000);
            id20 id4 = new id20(sieve.id9() + 1, false);
            for (int i = 0, end = sieve.id9(); i < end; i++) {
                id4.put(sieve.get(i), i);
            }
            id4.put(1, sieve.id9());
            List<id8>[] g = Graph.id15(id4.size());

            IntegerList collect = new IntegerList(2);
            for (int i = 0; i < n; i++) {
                int x = a[i];
                collect.clear();
                for (IntegerIterator iterator = allPrime.iterator(x); iterator.hasNext(); ) {
                    int p = iterator.next();
                    int cnt = 0;
                    while (x % p == 0) {
                        x /= p;
                        cnt ^= 1;
                    }
                    if (cnt == 1) {
                        collect.add(p);
                    }
                }
                if (collect.size() == 0) {
                    out.println(1);
                    return;
                }
                if (collect.size() == 1) {
                    collect.add(1);
                }
                

                

                Graph.id11(g, id4.get(collect.get(0)), id4.get(collect.get(1)));
            }

            IntegerList circle = new IntegerList(n);
            id1 minCircle = new id1(g);
            minCircle.optimize(sieve.id9(), circle);
            for (int i = 0; sieve.get(i) < 1000; i++) {
                minCircle.optimize(i, circle);
            }

            if (circle.size() == 0) {
                out.println(-1);
                return;
            }
            out.println(circle.size());
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class Graph {
        public static void id11(List<id8>[] g, int s, int t) {
            id8 toT = new id8(t);
            id8 toS = new id8(s);
            toT.rev = toS;
            toS.rev = toT;
            g[s].add(toT);
            g[t].add(toS);
        }

        public static List<id8>[] id15(int n) {
            List<id8>[] ans = new List[n];
            for (int i = 0; i < n; i++) {
                ans[i] = new ArrayList<>();
            }
            return ans;
        }

    }

    static class id5 {
        private int[] primes;
        private boolean[] isComp;
        private int primeLength;

        public int id9() {
            return primeLength;
        }

        public int get(int k) {
            return primes[k];
        }

        public id5(int limit) {
            isComp = new boolean[limit + 1];
            primes = new int[limit + 1];
            primeLength = 0;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[primeLength++] = i;
                }
                for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }
        }

    }

    static class id1 {
        private List<id8>[] g;
        int[] dist;
        int[] prev;
        id8[] tag;
        IntegerDeque dq;

        public id1(List<id8>[] g) {
            this.g = g;
            int n = g.length;
            dist = new int[n];
            prev = new int[n];
            tag = new id8[n];
            dq = new id0(n);
        }

        private void collect(int root, IntegerList circle) {
            while (root != -1) {
                circle.add(root);
                root = prev[root];
            }
        }

        public boolean optimize(int root, IntegerList circle) {
            Arrays.fill(dist, -1);
            Arrays.fill(prev, -1);
            Arrays.fill(tag, null);
            dq.clear();

            dist[root] = 0;
            boolean ans = false;
            for (id8 e : g[root]) {
                if (dist[e.to] != -1) {
                    if (e.to == root && (circle.size() == 0 || circle.size() > 1)) {
                        circle.clear();
                        circle.add(root);
                        ans = true;
                    }
                    if (circle.size() == 0 || circle.size() > 2) {
                        circle.clear();
                        circle.add(root);
                        circle.add(e.to);
                        ans = true;
                    }
                    continue;
                }
                dist[e.to] = 1;
                tag[e.to] = e;
                prev[e.to] = root;
                dq.addLast(e.to);
            }

            if (circle.size() == 1 || circle.size() == 2) {
                return ans;
            }

            id8 cross = null;
            int best = circle.size() == 0 ? g.length + 1 : circle.size();
            while (!dq.isEmpty()) {
                int head = dq.removeFirst();
                for (id8 e : g[head]) {
                    if (dist[e.to] != -1) {
                        if (e.to != root && tag[e.to] != tag[head] && best > dist[head] + dist[e.to] + 1) {
                            best = dist[head] + dist[e.to] + 1;
                            cross = e;
                        }
                        continue;
                    }
                    dist[e.to] = dist[head] + 1;
                    tag[e.to] = tag[head];
                    prev[e.to] = head;
                    dq.addLast(e.to);
                }
            }

            if (cross != null && (circle.size() == 0 || best < circle.size())) {
                circle.clear();
                collect(cross.to, circle);
                circle.pop();
                int size = circle.size();
                collect(cross.rev.to, circle);
                SequenceUtils.reverse(circle.getData(), size, circle.size() - 1);
                ans = true;
            }
            return ans;
        }

    }

    static class Hasher {
        private long time = System.nanoTime() + System.currentTimeMillis();

        private int shuffle(long x) {
            x += time;
            x += 0x9e3779b97f4a7c15L;
            x = (x ^ (x >>> 30)) * 0xbf58476d1ce4e5b9L;
            x = (x ^ (x >>> 27)) * 0x94d049bb133111ebL;
            return (int) (x ^ (x >>> 31));
        }

        public int hash(int x) {
            return shuffle(x);
        }

    }

    static class id13 {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public id13(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
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

    static class id8 extends DirectedEdge {
        public id8 rev;

        public id8(int to) {
            super(to);
        }

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
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

    static class id20 {
        private int[] slot;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;
        private Hasher hasher = new Hasher();

        public id20(int cap, boolean rehash) {
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
            return hasher.hash(x);
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

        public int id7(int x, int def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = id10(s, x);
            return keys[index] == x ? values[index] : def;
        }

        public int get(int x) {
            return id7(x, 0);
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

        public id16 iterator() {
            return new id16() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int id14() {
                    return keys[readIndex];
                }


                public int id17() {
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

        public int size() {
            return size;
        }

        public String toString() {
            id16 iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.id14()).append("->").append(iterator.id17()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static interface IntegerDeque extends IntegerStack {
        int removeFirst();

    }

    static class id18 {
        private static int[] primes = new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

        public static long[] id3(long n) {
            long[] ans = new long[2];
            ans[0] = 1;
            for (int i = 0; i < primes.length; i++) {
                if (DigitUtils.id19(ans[0], primes[i], n)) {
                    break;
                }
                ans[0] *= primes[i];
                ans[1]++;
            }
            return ans;
        }

    }

    static interface id16 {
        boolean hasNext();

        void next();

        int id14();

        int id17();

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static boolean id19(long a, long b, long limit) {
            if (limit < 0) {
                limit = -limit;
            }
            if (a < 0) {
                a = -a;
            }
            if (b < 0) {
                b = -b;
            }
            if (a == 0 || b == 0) {
                return false;
            }
            

            return a > limit / b;
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void reverse(int[] data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

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

    static class id0 implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public id0(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = id0.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
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
                throw new ArrayIndexOutOfBoundsException("invalid index " + i);
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

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public int pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static interface IntegerStack {
        void addLast(int x);

        boolean isEmpty();

        void clear();

    }

    static class Factorization {
        public static id13 id12(int n) {
            int id6 = (int) id18.id3(n)[1];
            id13 stack = new id13(n + 1, n * id6);
            boolean[] isComp = new boolean[n + 1];
            for (int i = 2; i <= n; i++) {
                if (isComp[i]) {
                    continue;
                }
                for (int j = i; j <= n; j += i) {
                    isComp[j] = true;
                    stack.addLast(j, i);
                }
            }
            return stack;
        }

    }
}
