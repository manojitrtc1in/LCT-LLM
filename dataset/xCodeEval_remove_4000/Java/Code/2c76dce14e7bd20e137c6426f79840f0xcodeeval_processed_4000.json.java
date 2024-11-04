import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            id4 solver = new id4();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class id4 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();

            id9 edges = new id9(n, 2 * n);
            for (int i = 0; i < m; i++) {
                int a = in.readInt() - 1;
                int b = in.readInt() - 1;
                edges.addLast(a, b);
                edges.addLast(b, a);
            }

            ForestDiameter forestDiameter = new ForestDiameter(edges, n);
            id10 map = new id10(n, false);
            for (int i = 0; i < n; i++) {
                map.id0(forestDiameter.getCenters(i).get(0),
                        forestDiameter.getDiameter(i));
            }

            int maxDiameter = -1;
            int centerId = -1;
            for (id1 iterator = map.iterator(); iterator.hasNext(); ) {
                iterator.next();
                int key = iterator.id5();
                int value = iterator.id8();
                if (value > maxDiameter) {
                    maxDiameter = value;
                    centerId = key;
                }
            }

            List<int[]> addedEdges = new ArrayList<>(n);
            for (id1 iterator = map.iterator(); iterator.hasNext(); ) {
                iterator.next();
                int key = iterator.id5();
                if (key == centerId) {
                    continue;
                }
                addedEdges.add(SequenceUtils.wrapArray(centerId, key));
                edges.addLast(centerId, key);
                edges.addLast(key, centerId);
            }

            TreeDiameter treeDiameter = new TreeDiameter(edges, n);
            int diameter = treeDiameter.getDiameter();

            out.println(diameter);
            for (int[] edge : addedEdges) {
                out.append(edge[0] + 1).append(' ').append(edge[1] + 1).append('\n');
            }
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
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

    static class IntList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
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
                throw new ArrayIndexOutOfBoundsException();
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

        public void addAll(IntList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.id2(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public void unique() {
            if (size <= 1) {
                return;
            }

            sort();
            int wpos = 1;
            for (int i = 1; i < size; i++) {
                if (data[i] != data[wpos - 1]) {
                    data[wpos++] = data[i];
                }
            }
            size = wpos;
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

        public IntIterator iterator() {
            return new IntIterator() {
                int i = 0;


                public boolean hasNext() {
                    return i < size;
                }


                public int next() {
                    return data[i++];
                }
            };
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntList)) {
                return false;
            }
            IntList other = (IntList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + data[i];
            }
            return h;
        }

        public IntList clone() {
            IntList ans = new IntList();
            ans.addAll(this);
            return ans;
        }

    }

    static interface id1 {
        boolean hasNext();

        void next();

        int id5();

        int id8();

    }

    static interface IntIterator {
        boolean hasNext();

        int next();

    }

    static class id10 {
        private int[] slot;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public id10(int cap, boolean rehash) {
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

        public void id0(int x, int y) {
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
                int index = id3(s, x);
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

        private int id3(int s, int x) {
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

        public id1 iterator() {
            return new id1() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int id5() {
                    return keys[readIndex];
                }


                public int id8() {
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
            id1 iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.id5()).append("->").append(iterator.id8()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static class id9 {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntIterator iterator(final int queue) {
            return new IntIterator() {
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

        public id9(int qNum, int totalCapacity) {
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
                for (IntIterator iterator = iterator(i); iterator.hasNext(); ) {
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }

    static class Randomized {
        static Random random = new Random();

        public static void id2(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class TreeDiameter {
        private id9 edges;
        private int[] depth;
        private int[] parents;
        private int diameter;
        private IntList centers;
        private IntList ends;

        public int getDiameter() {
            return diameter;
        }

        public TreeDiameter(id9 edges, int n) {
            this.edges = edges;
            depth = new int[n];
            centers = new IntList(2);
            ends = new IntList(2);
            parents = new int[n];

            id6(0, -1);
            int end = 0;
            for (int i = 0; i < n; i++) {
                if (depth[i] > depth[end]) {
                    end = i;
                }
            }
            id6(end, -1);
            int another = 0;
            for (int i = 0; i < n; i++) {
                if (depth[i] > depth[another]) {
                    another = i;
                }
            }

            ends.add(end);
            ends.add(another);

            diameter = depth[another];
            for (int i = another; i != -1; i = parents[i]) {
                if (depth[i] == DigitUtils.ceilDiv(diameter, 2) ||
                        depth[i] == DigitUtils.floorDiv(diameter, 2)) {
                    centers.add(i);
                }
            }

            ends.unique();
            centers.unique();
        }

        private void id6(int root, int p) {
            parents[root] = p;
            depth[root] = p != -1 ? depth[p] + 1 : 0;
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                id6(node, root);
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

    static class ForestDiameter {
        private id9 edges;
        private int[] depth;
        private int[] parents;
        private int[] diameters;
        private IntList[] centers;
        private IntList[] ends;
        private int[] treeIds;
        private IntList collector;

        public IntList getCenters(int i) {
            return centers[i];
        }

        public int getDiameter(int i) {
            return diameters[i];
        }

        public ForestDiameter(id9 edges, int n) {
            this.edges = edges;
            depth = new int[n];
            parents = new int[n];
            centers = new IntList[n];
            ends = new IntList[n];
            treeIds = new int[n];
            diameters = new int[n];
            collector = new IntList(n);
            int idAllocator = 0;
            Arrays.fill(treeIds, -1);

            for (int j = 0; j < n; j++) {
                if (treeIds[j] != -1) {
                    continue;
                }
                IntList endList = new IntList(2);
                IntList centerList = new IntList(2);
                collector.clear();
                id7(j, -1);
                id6(j, -1);
                int end = collector.get(0);
                for (IntIterator iterator = collector.iterator(); iterator.hasNext(); ) {
                    int node = iterator.next();
                    if (depth[node] > depth[end]) {
                        end = node;
                    }
                }
                id6(end, -1);
                int another = collector.get(0);
                for (IntIterator iterator = collector.iterator(); iterator.hasNext(); ) {
                    int node = iterator.next();
                    if (depth[node] > depth[another]) {
                        another = node;
                    }
                }

                endList.add(end);
                endList.add(another);

                int diameter = depth[another];
                for (int i = another; i != -1; i = parents[i]) {
                    if (depth[i] == DigitUtils.ceilDiv(diameter, 2) ||
                            depth[i] == DigitUtils.floorDiv(diameter, 2)) {
                        centerList.add(i);
                    }
                }

                endList.unique();
                centerList.unique();

                for (IntIterator iterator = collector.iterator(); iterator.hasNext(); ) {
                    int node = iterator.next();
                    treeIds[node] = idAllocator;
                    diameters[node] = diameter;
                    ends[node] = endList;
                    centers[node] = centerList;
                }
                idAllocator++;
            }
        }

        private void id7(int root, int p) {
            collector.add(root);
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                id7(node, root);
            }
        }

        private void id6(int root, int p) {
            parents[root] = p;
            depth[root] = p != -1 ? depth[p] + 1 : 0;
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                id6(node, root);
            }
        }

    }

    static class SequenceUtils {
        public static int[] wrapArray(int... x) {
            return x;
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
}

