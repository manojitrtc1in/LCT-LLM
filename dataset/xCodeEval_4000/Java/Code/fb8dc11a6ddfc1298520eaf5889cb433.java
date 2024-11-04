import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.IntUnaryOperator;
import java.io.IOException;
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
            EVasyaAndBigIntegers solver = new EVasyaAndBigIntegers();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EVasyaAndBigIntegers {
        Modular mod = new Modular(998244353);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            char[] data = new char[3000000];
            int aLen = in.readString(data, 0);
            int leftLen = in.readString(data, aLen);
            int rightLen = in.readString(data, aLen + leftLen);
            SAIS sais = new SAIS(data);
            int[] leftLCP = new int[aLen];
            int[] rightLCP = new int[aLen];

            int index = sais.queryRank(aLen);
            int lcp = aLen;
            for (int i = index; i >= 1 && lcp > 0; i--) {
                lcp = Math.min(lcp, sais.longestCommonPrefixBetween(i));
                int last;
                if ((last = sais.queryKth(i - 1)) < aLen) {
                    leftLCP[last] = lcp;
                }
            }
            lcp = aLen;
            for (int i = index + 1; i < data.length && lcp > 0; i++) {
                lcp = Math.min(lcp, sais.longestCommonPrefixBetween(i));
                int last;
                if ((last = sais.queryKth(i)) < aLen) {
                    leftLCP[last] = lcp;
                }
            }

            index = sais.queryRank(aLen + leftLen);
            lcp = aLen;
            for (int i = index; i >= 1 && lcp > 0; i--) {
                lcp = Math.min(lcp, sais.longestCommonPrefixBetween(i));
                int last;
                if ((last = sais.queryKth(i - 1)) < aLen) {
                    rightLCP[last] = lcp;
                }
            }
            lcp = aLen;
            for (int i = index + 1; i < data.length && lcp > 0; i++) {
                lcp = Math.min(lcp, sais.longestCommonPrefixBetween(i));
                int last;
                if ((last = sais.queryKth(i)) < aLen) {
                    rightLCP[last] = lcp;
                }
            }

            int[] dp = new int[aLen + 1];
            int[] preSum = new int[aLen + 1];
            dp[0] = 1;
            preSum[0] = 1;
            for (int i = 1; i <= aLen; i++) {
                preSum[i] = preSum[i - 1];
                int l = i - rightLen;
                int r = i - leftLen;
                if (l >= 0) {
                    lcp = rightLCP[l];
                    if (lcp < rightLen && data[l + lcp] > data[aLen + leftLen + lcp]) {
                        l++;
                    }
                } else {
                    l = 0;
                }
                if (r < 0) {
                    continue;
                }
                lcp = leftLCP[r];
                if (lcp < leftLen && data[r + lcp] < data[aLen + lcp]) {
                    r--;
                }
                if (l > r) {
                    continue;
                }
                dp[i] = interval(preSum, l, r);
                preSum[i] = mod.plus(preSum[i - 1], dp[i]);

                if (data[i - 1] == '0') {
                    preSum[i - 1] = mod.subtract(preSum[i - 1], dp[i - 1]);
                    preSum[i] = mod.subtract(preSum[i], dp[i - 1]);
                }
            }














            int ans = dp[aLen];
            out.println(ans);
        }

        public int interval(int[] preSum, int l, int r) {
            if (l == 0) {
                return preSum[r];
            }
            return mod.subtract(preSum[r], preSum[l - 1]);
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

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
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

    static class CompareUtils {
        private static final int[] BUF8 = new int[1 << 8];
        private static final IntegerList INT_LIST = new IntegerList();

        private CompareUtils() {
        }

        public static void radixSort(int[] data, int l, int r, IntUnaryOperator indexFetcher) {
            INT_LIST.clear();
            INT_LIST.expandWith(0, r - l + 1);
            int[] output = INT_LIST.getData();
            for (int i = 0; i < 4; i++) {
                int rightShift = i * 8;
                int mask = BUF8.length - 1;
                radixSort0(data, output, BUF8, l, r, (x) -> (indexFetcher.applyAsInt(x) >>> rightShift) & mask);
                System.arraycopy(output, 0, data, l, r - l + 1);
            }
        }

        private static void radixSort0(int[] data, int[] output, int[] buf, int l, int r, IntUnaryOperator indexFetcher) {
            Arrays.fill(buf, 0);
            for (int i = l; i <= r; i++) {
                buf[indexFetcher.applyAsInt(data[i])]++;
            }
            for (int i = 1; i < buf.length; i++) {
                buf[i] += buf[i - 1];
            }
            for (int i = r; i >= l; i--) {
                output[--buf[indexFetcher.applyAsInt(data[i])]] = data[i];
            }
        }

    }

    static class MultiWayIntegerDeque {
        private int[] values;
        private int[] next;
        private int[] prev;
        private int[] heads;
        private int[] tails;
        private int alloc;
        private int queueNum;

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
            prev = Arrays.copyOf(prev, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public void clear() {
            alloc = 0;
            Arrays.fill(heads, 0, queueNum, 0);
            Arrays.fill(tails, 0, queueNum, 0);
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public void expandQueueNum(int qNum) {
            if (qNum <= queueNum) {
            } else if (qNum <= heads.length) {
                Arrays.fill(heads, queueNum, qNum, 0);
                Arrays.fill(tails, queueNum, qNum, 0);
            } else {
                Arrays.fill(heads, queueNum, heads.length, 0);
                Arrays.fill(tails, queueNum, heads.length, 0);
                heads = Arrays.copyOf(heads, qNum);
                tails = Arrays.copyOf(tails, qNum);
            }
            queueNum = qNum;
        }

        public MultiWayIntegerDeque(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            prev = new int[totalCapacity + 1];
            heads = new int[qNum];
            tails = new int[qNum];
            queueNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[tails[qId]] = alloc;
            prev[alloc] = tails[qId];
            tails[qId] = alloc;
        }

        public void addFirst(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[alloc] = heads[qId];
            prev[heads[qId]] = alloc;
            heads[qId] = alloc;
        }

        public int removeFirst(int qId) {
            int ans = values[heads[qId]];
            if (heads[qId] == tails[qId]) {
                heads[qId] = tails[qId] = 0;
            } else {
                heads[qId] = next[heads[qId]];
                prev[tails[qId]] = 0;
            }
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
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

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

        public void reverse(int l, int r) {
            SequenceUtils.reverse(data, l, r);
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
                throw new ArrayIndexOutOfBoundsException("index " + i + " out of range");
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

        public void expandWith(int x, int len) {
            ensureSpace(len);
            while (size < len) {
                data[size++] = x;
            }
        }

        public int tail() {
            checkRange(0);
            return data[size - 1];
        }

        public void set(int i, int x) {
            checkRange(i);
            data[i] = x;
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

        public boolean isEmpty() {
            return size == 0;
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

    static class SAIS {
        private int l;
        private int[] rank2Index;
        private int[] index2Rank;
        private int[] lcp;
        private int[] data;
        private static final int TYPE_MINUS = 0;
        private static final int TYPE_PLUS = 1;

        public int queryRank(int i) {
            return index2Rank[i - l];
        }

        public int queryKth(int k) {
            return rank2Index[k] + l;
        }

        public int longestCommonPrefixBetween(int i) {
            return lcp[i];
        }

        public SAIS(char[] array) {
            this(array, 0, array.length - 1);
        }

        public SAIS(int[] array) {
            this(array, 0, array.length - 1);
        }

        public SAIS(char[] array, int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            this.l = l;
            int n = r - l + 1;
            data = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = array[i + l];
            }
            process();
        }

        public SAIS(int[] array, int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            int n = r - l + 1;
            data = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = array[i + l];
            }
            process();
        }

        private void process() {
            int n = data.length;
            rank2Index = new int[n];
            index2Rank = new int[n];
            lcp = new int[n];
            for (int i = 0; i < n; i++) {
                rank2Index[i] = i;
            }
            CompareUtils.radixSort(rank2Index, 0, n - 1, x -> data[x] ^ Integer.MIN_VALUE);
            int rank = 0;
            index2Rank[rank2Index[0]] = 0;
            for (int i = 1; i < data.length; i++) {
                if (data[rank2Index[i]] > data[rank2Index[i - 1]]) {
                    rank++;
                }
                index2Rank[rank2Index[i]] = rank;
            }

            System.arraycopy(index2Rank, 0, rank2Index, 0, n);
            buildSA(rank2Index, new IntegerList(n), new IntegerList(n), new MultiWayIntegerDeque(n, n), index2Rank);
            for (int i = 0; i < n; i++) {
                rank2Index[index2Rank[i]] = i;
            }
            buildLcp();
        }

        private void buildLcp() {
            int n = lcp.length;
            for (int i = 0; i < n; i++) {
                int ri = index2Rank[i];
                if (ri == 0) {
                    continue;
                }
                int j = rank2Index[ri - 1];
                int same = i == 0 ? 0 : Math.max(lcp[index2Rank[i - 1]] - 1, 0);
                while (j + same < n && i + same < n && data[j + same] == data[i + same]) {
                    same++;
                }
                lcp[index2Rank[i]] = same;
            }
        }

        private static void buildSA(int[] data, IntegerList plus, IntegerList minus, MultiWayIntegerDeque deque, int[] output) {
            int n = data.length;
            if (n == 1) {
                output[0] = 0;
                return;
            }
            byte[] type = new byte[n];
            for (int i = n - 1; i >= 0; i--) {
                if (i == n - 1 || data[i] > data[i + 1] || data[i] == data[i + 1] && type[i + 1] == TYPE_MINUS) {
                    type[i] = TYPE_MINUS;
                } else {
                    type[i] = TYPE_PLUS;
                }
            }

            plus.clear();
            minus.clear();

            

            deque.expandQueueNum(n);
            deque.clear();
            for (int i = 1; i < n; i++) {
                if (type[i - 1] == TYPE_MINUS && type[i] == TYPE_PLUS) {
                    deque.addLast(data[i], i);
                }
            }
            for (int i = 0; i < n; i++) {
                while (!deque.isEmpty(i)) {
                    plus.add(deque.removeFirst(i));
                }
            }

            if (!plus.isEmpty()) {
                induceSort(plus, minus, type, data, deque);

                minus.clear();
                minus.addAll(plus);
                plus.clear();
                for (int i = 0, until = minus.size(); i < until; i++) {
                    int index = minus.get(i);
                    if (index > 0 && type[index - 1] == TYPE_MINUS && type[index] == TYPE_PLUS) {
                        plus.add(index);
                    }
                }

                minus.clear();
                for (int i = 1; i < n; i++) {
                    if (type[i - 1] == TYPE_MINUS && type[i] == TYPE_PLUS) {
                        minus.add(i);
                    }
                }

                int[] order2Index = minus.toArray();
                int[] alias = new int[order2Index.length];
                int[] index2Order = new int[n];
                for (int i = 0; i < order2Index.length; i++) {
                    index2Order[order2Index[i]] = i;
                }
                

                int r = 0;
                alias[index2Order[plus.get(0)]] = r;
                for (int i = 1; i < order2Index.length; i++) {
                    int l1 = plus.get(i);
                    int l2 = plus.get(i - 1);
                    int r1 = index2Order[l1];
                    if (r1 + 1 == order2Index.length) {
                        r1 = n - 1;
                    } else {
                        r1 = order2Index[r1 + 1];
                    }
                    int r2 = index2Order[l2];
                    if (r2 + 1 == order2Index.length) {
                        r2 = n - 1;
                    } else {
                        r2 = order2Index[r2 + 1];
                    }
                    if (compareArray(data, l1, r1, data, l2, r2) != 0) {
                        r++;
                    }
                    alias[index2Order[plus.get(i)]] = r;
                }
                buildSA(alias, plus, minus, deque, output);
                int[] index2Rank = output;
                plus.clear();
                plus.expandWith(0, order2Index.length);
                for (int i = 0; i < order2Index.length; i++) {
                    plus.set(index2Rank[i], order2Index[i]);
                }
            }

            

            induceSort(plus, minus, type, data, deque);
            plus.reverse(0, plus.size() - 1);
            minus.reverse(0, minus.size() - 1);

            

            int[] index2Rank = output;
            int rank = 0;
            while (plus.size() + minus.size() > 0) {
                if (plus.isEmpty() || (!minus.isEmpty() && data[minus.tail()] <= data[plus.tail()])) {
                    index2Rank[minus.pop()] = rank++;
                } else {
                    index2Rank[plus.pop()] = rank++;
                }
            }

            return;
        }

        private static int compareArray(int[] a, int al, int ar, int[] b, int bl, int br) {
            for (int i = al, j = bl; i <= ar && j <= br; i++, j++) {
                if (a[i] != b[j]) {
                    return a[i] - b[j];
                }
            }
            return -((ar - al) - (br - bl));
        }

        private static void induceSort(IntegerList plus, IntegerList minus, byte[] type, int[] data, MultiWayIntegerDeque deque) {
            int n = data.length;
            deque.expandQueueNum(n);
            minus.clear();
            plus.reverse(0, plus.size() - 1);

            

            deque.clear();
            deque.addFirst(data[n - 1], n - 1);
            for (int i = 0; i < n; i++) {
                while (!deque.isEmpty(i)) {
                    int index = deque.removeFirst(i);
                    if (type[index] == TYPE_MINUS) {
                        minus.add(index);
                    }
                    if (index > 0 && type[index - 1] == TYPE_MINUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
                while (!plus.isEmpty() && data[plus.tail()] == i) {
                    int index = plus.pop();
                    if (index > 0 && type[index - 1] == TYPE_MINUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
            }
            deque.clear();
            int rightScan = minus.size() - 1;
            

            for (int i = n - 1; i >= 0; i--) {
                while (!deque.isEmpty(i)) {
                    int index = deque.removeFirst(i);
                    if (type[index] == TYPE_PLUS) {
                        plus.add(index);
                    }
                    if (index > 0 && type[index - 1] == TYPE_PLUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
                while (rightScan >= 0 && data[minus.get(rightScan)] == i) {
                    int index = minus.get(rightScan--);
                    if (index > 0 && type[index - 1] == TYPE_PLUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
            }
            plus.reverse(0, plus.size() - 1);
        }

    }
}

