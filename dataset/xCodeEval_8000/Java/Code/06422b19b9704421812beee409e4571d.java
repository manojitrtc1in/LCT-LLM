import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.SortedSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            try {
                int n = in.readInt();
                int[] a = in.readIntArray(n), b = in.readIntArray(n);
                int idx = 0;
                long[] dp = new long[n];
                dp[0] = 0;
                ConvexHull2D cht = new ConvexHull2D();
                for (int i = 1; i < n; i++) {
                    cht.insert(new Line(b[i - 1], dp[i - 1]));
                    dp[i] = cht.query(a[i]);
                }
                long res = dp[n - 1];
                out.printLine(res);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    static class ConvexHull2D {
        private NavigableSet<Line> slopes;
        private LongComparator comparator;

        public ConvexHull2D() {
            this(LongComparator.DEFAULT);
        }

        public ConvexHull2D(LongComparator comparator) {
            slopes = new TreapSet<>((o1, o2) -> {
                if (o1.equals(Line.qline) || o2.equals(Line.qline)) {
                    return Double.compare(o1.xleft, o2.xleft);
                }
                return -comparator.compare(o1.m, o2.m);
            });
            this.comparator = comparator;
        }

        private Line next(Line l) {
            return slopes.higher(l);
        }

        private Line prev(Line l) {
            return slopes.lower(l);
        }

        private boolean bad(Line it) {
            Line suc = next(it);
            if (it.equals(slopes.first())) {
                if (suc == null) {
                    return false;
                }
                return it.m == suc.m && comparator.compare(it.q, suc.q) >= 0;
            }
            Line pre = prev(it);
            assert (pre != null);
            if (suc == null) {
                return it.m == pre.m && comparator.compare(it.q, pre.q) >= 0;
            }
            return new Rational(it.q - suc.q, suc.m - it.m)
                    .compareTo(new Rational(pre.q - it.q, it.m - pre.m)) <= 0;
        }

        public void insert(Line e) {
            slopes.add(e);
            if (bad(e)) {
                slopes.remove(e);
                return;
            }
            while (next(e) != null && bad(next(e))) {
                slopes.remove(next(e));
            }
            if (next(e) != null) {
                next(e).recalcxleft(e);
            }
            while (e != slopes.first() && bad(prev(e))) {
                slopes.remove(prev(e));
            }
            if (e != slopes.first()) {
                e.recalcxleft(prev(e));
            } else {
                e.xleft = Line.ninf;
            }
        }

        public long query(long x) {
            Line.qline.xleft = x;
            Line e = slopes.floor(Line.qline);
            assert e != null;
            return e.m * x + e.q;
        }

    }

    static class IntegerUtils {
        public static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                long temp = a % b;
                a = b;
                b = temp;
            }
            return a;
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

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class TreapSet<K> implements NavigableSet<K> {
        protected static final Random rnd = new Random(239);
        protected final Node nullNode;
        protected final Comparator<? super K> comparator;
        protected Node root;
        private final K from;
        private final K to;
        private final boolean fromInclusive;
        private final boolean toInclusive;

        public TreapSet() {
            this((Comparator<? super K>) null);
        }

        public TreapSet(Comparator<? super K> comparator) {
            this(null, null, false, false, comparator, null, null);
        }

        public TreapSet(Iterable<? extends K> collection) {
            this(collection, null);
        }

        public TreapSet(Iterable<? extends K> collection, Comparator<? super K> comparator) {
            this(comparator);
            addAll(collection);
        }

        protected TreapSet(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator,
                           Node root, Node nullNode) {
            this.comparator = comparator;
            this.from = from;
            this.to = to;
            this.fromInclusive = fromInclusive;
            this.toInclusive = toInclusive;
            if (nullNode == null) {
                nullNode = new NullNode();
            }
            if (root == null) {
                root = nullNode;
            }
            this.root = root;
            this.nullNode = nullNode;
        }

        public boolean addAll(Iterable<? extends K> collection) {
            boolean result = false;
            for (K element : collection) {
                result |= add(element);
            }
            return result;
        }

        public K lower(K k) {
            Node target = root.lower(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }

        private boolean belongs(K key) {
            int valueFrom = compare(from, key);
            int valueTo = compare(key, to);
            return (valueFrom < 0 || valueFrom == 0 && fromInclusive) && (valueTo < 0 || valueTo == 0 && toInclusive);
        }

        public K floor(K k) {
            Node target = root.floor(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }

        public K ceiling(K k) {
            Node target = root.ceil(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }

        public K higher(K k) {
            Node target = root.higher(k);
            if (target == nullNode) {
                return null;
            }
            if (belongs(target.key)) {
                return target.key;
            }
            return null;
        }

        public K pollFirst() {
            K first = first();
            if (first == null) {
                throw new NoSuchElementException();
            }
            root.erase(first);
            return first;
        }

        public K pollLast() {
            K last = last();
            if (last == null) {
                throw new NoSuchElementException();
            }
            root.erase(last);
            return last;
        }

        public int size() {
            if (from == null && to == null) {
                return root.size;
            }
            if (from == null) {
                Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
                if (to == nullNode) {
                    return 0;
                }
                return root.indexOf(to) + 1;
            }
            if (to == null) {
                Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
                if (from == nullNode) {
                    return 0;
                }
                return root.size - root.indexOf(from);
            }
            Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
            if (from == nullNode || !belongs(from.key)) {
                return 0;
            }
            Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
            return root.indexOf(to) - root.indexOf(from) + 1;
        }

        public boolean isEmpty() {
            return size() == 0;
        }

        public boolean contains(Object o) {
            return belongs((K) o) && root.search((K) o) != nullNode;
        }

        public Iterator<K> iterator() {
            return new Iterator<K>() {
                private K current = first();

                public boolean hasNext() {
                    return current != null;
                }

                public K next() {
                    K result = current;
                    current = higher(current);
                    return result;
                }

                public void remove() {
                    TreapSet.this.remove(current);
                }
            };
        }

        public Object[] toArray() {
            Object[] array = new Object[size()];
            int index = 0;
            for (K key : this) {
                array[index++] = key;
            }
            return array;
        }

        public <T> T[] toArray(T[] a) {
            if (a.length < size()) {
                throw new IllegalArgumentException();
            }
            int index = 0;
            for (K key : this) {
                a[index++] = (T) key;
            }
            return a;
        }

        public boolean add(K k) {
            if (k == null) {
                throw new NullPointerException();
            }
            if (contains(k)) {
                return false;
            }
            root = root.insert(createNode(k));
            return true;
        }

        protected Node createNode(K k) {
            return new Node(k, rnd.nextLong());
        }

        public boolean remove(Object o) {
            if (!contains(o)) {
                return false;
            }
            root = root.erase((K) o);
            return true;
        }

        public boolean containsAll(Collection<?> c) {
            for (Object o : c) {
                if (!contains(o)) {
                    return false;
                }
            }
            return true;
        }

        public boolean addAll(Collection<? extends K> c) {
            return addAll((Iterable<? extends K>) c);
        }

        public boolean retainAll(Collection<?> c) {
            List<K> toRemove = new ArrayList<>();
            for (K key : this) {
                if (!c.contains(key)) {
                    toRemove.add(key);
                }
            }
            return removeAll(toRemove);
        }

        public boolean removeAll(Collection<?> c) {
            boolean result = false;
            for (Object o : c) {
                result |= remove(o);
            }
            return result;
        }

        public void clear() {
            retainAll(Collections.emptySet());
        }

        public NavigableSet<K> descendingSet() {
            throw new UnsupportedOperationException();
        }

        public Iterator<K> descendingIterator() {
            return new Iterator<K>() {
                private K current = last();

                public boolean hasNext() {
                    return current != null;
                }

                public K next() {
                    K result = current;
                    current = lower(current);
                    return result;
                }

                public void remove() {
                    TreapSet.this.remove(current);
                }
            };
        }

        public NavigableSet<K> subSet(K fromElement, boolean fromInclusive, K toElement, boolean toInclusive) {
            return new TreapSet<>(fromElement, toElement, fromInclusive, toInclusive, comparator, root, nullNode);
        }

        public NavigableSet<K> headSet(K toElement, boolean inclusive) {
            return subSet(null, false, toElement, inclusive);
        }

        public NavigableSet<K> tailSet(K fromElement, boolean inclusive) {
            return subSet(fromElement, inclusive, null, false);
        }

        public Comparator<? super K> comparator() {
            return comparator;
        }

        public SortedSet<K> subSet(K fromElement, K toElement) {
            return subSet(fromElement, true, toElement, false);
        }

        public SortedSet<K> headSet(K toElement) {
            return subSet(null, false, toElement, false);
        }

        public SortedSet<K> tailSet(K fromElement) {
            return tailSet(fromElement, true);
        }

        public K first() {
            if (isEmpty()) {
                return null;
            }
            if (from == null) {
                return root.first().key;
            }
            if (fromInclusive) {
                return ceiling(from);
            }
            return higher(from);
        }

        public K last() {
            if (isEmpty()) {
                return null;
            }
            if (to == null) {
                return root.last().key;
            }
            if (toInclusive) {
                return floor(to);
            }
            return lower(to);
        }

        protected int compare(K first, K second) {
            if (first == null || second == null) {
                return -1;
            }
            if (comparator != null) {
                return comparator.compare(first, second);
            }
            return ((Comparable<? super K>) first).compareTo(second);
        }

        protected class Node {
            protected final K key;
            protected final long priority;
            protected Node left;
            protected Node right;
            protected int size;

            protected Node(K key, long priority) {
                this.key = key;
                this.priority = priority;
                left = nullNode;
                right = nullNode;
                size = 1;
            }

            protected Object[] split(K key) {
                if (compare(key, this.key) < 0) {
                    Object[] result = left.split(key);
                    left = (Node) result[1];
                    result[1] = this;
                    updateSize();
                    return result;
                }
                Object[] result = right.split(key);
                right = (Node) result[0];
                result[0] = this;
                updateSize();
                return result;
            }

            protected void updateSize() {
                size = left.size + right.size + 1;
            }

            protected Node insert(Node node) {
                if (node.priority > priority) {
                    Object[] result = split(node.key);
                    node.left = (Node) result[0];
                    node.right = (Node) result[1];
                    node.updateSize();
                    return node;
                }
                if (compare(node.key, this.key) < 0) {
                    left = left.insert(node);
                    updateSize();
                    return this;
                }
                right = right.insert(node);
                updateSize();
                return this;
            }

            protected Node merge(Node left, Node right) {
                if (left == nullNode) {
                    return right;
                }
                if (right == nullNode) {
                    return left;
                }
                if (left.priority > right.priority) {
                    left.right = left.right.merge(left.right, right);
                    left.updateSize();
                    return left;
                }
                right.left = right.left.merge(left, right.left);
                right.updateSize();
                return right;
            }

            protected Node erase(K key) {
                int value = compare(key, this.key);
                if (value == 0) {
                    return merge(left, right);
                }
                if (value < 0) {
                    left = left.erase(key);
                    updateSize();
                    return this;
                }
                right = right.erase(key);
                updateSize();
                return this;
            }

            protected Node lower(K key) {
                if (compare(key, this.key) <= 0) {
                    return left.lower(key);
                }
                Node result = right.lower(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }

            protected Node floor(K key) {
                if (compare(key, this.key) < 0) {
                    return left.floor(key);
                }
                Node result = right.floor(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }

            protected Node higher(K key) {
                if (compare(key, this.key) >= 0) {
                    return right.higher(key);
                }
                Node result = left.higher(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }

            protected Node ceil(K key) {
                if (compare(key, this.key) > 0) {
                    return right.ceil(key);
                }
                Node result = left.ceil(key);
                if (result == nullNode) {
                    return this;
                }
                return result;
            }

            protected Node first() {
                if (left == nullNode) {
                    return this;
                }
                return left.first();
            }

            protected Node last() {
                if (right == nullNode) {
                    return this;
                }
                return right.last();
            }

            protected Node search(K key) {
                int value = compare(key, this.key);
                if (value == 0) {
                    return this;
                }
                if (value < 0) {
                    return left.search(key);
                }
                return right.search(key);
            }

            public int indexOf(Node node) {
                if (this == node) {
                    return left.size;
                }
                if (compare(node.key, this.key) > 0) {
                    return left.size + 1 + right.indexOf(node);
                }
                return left.indexOf(node);
            }

        }

        private class NullNode extends Node {
            private Object[] splitResult = new Object[2];

            private NullNode() {
                super(null, Long.MIN_VALUE);
                left = this;
                right = this;
                size = 0;
            }

            protected Object[] split(K key) {
                splitResult[0] = splitResult[1] = this;
                return splitResult;
            }

            protected Node insert(Node node) {
                return node;
            }

            protected Node erase(K key) {
                return this;
            }

            protected Node lower(K key) {
                return this;
            }

            protected Node floor(K key) {
                return this;
            }

            protected Node higher(K key) {
                return this;
            }

            protected Node ceil(K key) {
                return this;
            }

            protected Node first() {
                throw new NoSuchElementException();
            }

            protected Node last() {
                throw new NoSuchElementException();
            }

            protected void updateSize() {
            }

            protected Node search(K key) {
                return this;
            }

        }

    }

    static class BigInt extends Number implements Comparable<BigInt> {
        private static final long mask = (1L << 32) - 1;
        private int sign;
        private int len;
        private int[] dig;

        public BigInt(final int sign, final int[] v, final int len) {
            assign(sign, v, len);
        }

        public BigInt(final int sign, final byte[] v, int vlen) {
            while (vlen > 1 && v[vlen - 1] == 0) --vlen;
            dig = new int[(vlen + 3) / 4];
            assign(sign, v, vlen);
        }

        public BigInt(final int sign, final int val) {
            dig = new int[1];
            uassign(sign, val);
        }

        public BigInt(final int sign, final long val) {
            dig = new int[2];
            uassign(sign, val);
        }

        public BigInt(final int val) {
            dig = new int[1];
            assign(val);
        }

        public BigInt(final long val) {
            dig = new int[2];
            assign(val);
        }

        public BigInt(final String s) {
            assign(s);
        }

        public BigInt(final char[] s) {
            assign(s);
        }

        public static BigInt valueOf(long val) {
            return new BigInt(val);
        }

        private int parse(final char[] s, int from, final int to) {
            int res = s[from] - '0';
            while (++from < to) res = res * 10 + s[from] - '0';
            return res;
        }

        private void mulAdd(final int add) {
            long carry = 0;
            for (int i = 0; i < len; i++) {
                carry = 1000000000 * (dig[i] & mask) + carry;
                dig[i] = (int) carry;
                carry >>>= 32;
            }
            if (carry != 0) dig[len++] = (int) carry;
            carry = (dig[0] & mask) + add;
            dig[0] = (int) carry;
            if ((carry >>> 32) != 0) {
                int i = 1;
                while (i < len && ++dig[i] == 0) {
                    ++i;
                }
                if (i == len) dig[len++] = 1; 

            }
        }

        private void realloc(final int newLen) {
            final int[] res = new int[newLen];
            System.arraycopy(dig, 0, res, 0, len);
            dig = res;
        }

        public BigInt assign(final int sign, final int[] v, final int len) {
            this.sign = sign;
            this.len = len;
            dig = v;
            return this;
        }

        public BigInt assign(final int sign, final byte[] v, final int vlen) {
            len = (vlen + 3) / 4;
            if (len > dig.length) dig = new int[len + 2];
            this.sign = sign;
            int tmp = vlen / 4, j = 0;
            for (int i = 0; i < tmp; i++, j += 4)
                dig[i] = v[j + 3] << 24 | (v[j + 2] & 0xFF) << 16 | (v[j + 1] & 0xFF) << 8 | v[j] & 0xFF;
            if (tmp != len) {
                tmp = v[j++] & 0xFF;
                if (j < vlen) {
                    tmp |= (v[j++] & 0xFF) << 8;
                    if (j < vlen) tmp |= (v[j] & 0xFF) << 16;
                }
                dig[len - 1] = tmp;
            }
            return this;
        }

        public BigInt assign(final String s) {
            return assign(s.toCharArray());
        }

        public BigInt assign(final char[] s) {
            sign = s[0] == '-' ? -1 : 1;

            len = s.length + (sign - 1 >> 1);
            final int alloc = len < 10 ? 1 : (int) (len * 3402L >>> 10) + 32 >>> 5; 

            if (dig == null || alloc > dig.length) dig = new int[alloc];

            int j = len % 9;
            if (j == 0) j = 9;
            j -= (sign - 1 >> 1);

            dig[0] = parse(s, 0 - (sign - 1 >> 1), j);
            for (len = 1; j < s.length; )
                mulAdd(parse(s, j, j += 9));
            return this;
        }

        public BigInt uassign(final int s, final int val) {
            sign = s;
            len = 1;
            dig[0] = val;
            return this;
        }

        public BigInt uassign(final int s, final long val) {
            sign = s;
            len = 2;
            if (dig.length < 2) realloc(2);
            dig[0] = (int) (val & mask);
            dig[1] = (int) (val >>> 32);
            if (dig[1] == 0) --len;
            return this;
        }

        public BigInt assign(final int val) {
            return uassign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        public BigInt assign(final long val) {
            return uassign(val < 0 ? -1 : 1, val < 0 ? -val : val);
        }

        public boolean isZero() {
            return len == 1 && dig[0] == 0;
        }

        public BigInt setToZero() {
            dig[0] = 0;
            len = 1;
            sign = 1; 

            return this;
        }

        public int compareAbsTo(final BigInt a) {
            if (len > a.len) return 1;
            if (len < a.len) return -1;
            for (int i = len - 1; i >= 0; i--)
                if (dig[i] != a.dig[i])
                    if ((dig[i] & mask) > (a.dig[i] & mask)) return 1;
                    else return -1;
            return 0;
        }

        public int compareTo(final BigInt a) {
            if (sign < 0) {
                if (a.sign < 0 || a.isZero()) return -compareAbsTo(a);
                return -1;
            }
            if (a.sign > 0 || a.isZero()) return compareAbsTo(a);
            return 1;
        }

        public boolean equals(final BigInt a) {
            if (len != a.len) return false;
            if (isZero() && a.isZero()) return true;
            if ((sign ^ a.sign) < 0) return false; 

            for (int i = 0; i < len; i++) if (dig[i] != a.dig[i]) return false;
            return true;
        }

        public boolean equals(final Object o) {
            if (o instanceof BigInt) return equals((BigInt) o);
            return false;
        }

        public int hashCode() {
            int hash = 0; 

            for (int i = 0; i < len; i++) hash = (int) (31 * hash + (dig[i] & mask));
            return sign * hash; 

        }

        public byte byteValue() {
            return (byte) (sign * (dig[0] & 0x7F));
        }

        public short shortValue() {
            return (short) (sign * (dig[0] & 0x7FFF));
        }

        public int intValue() {
            return sign * (dig[0] & 0x7FFFFFFF); 

        }

        public long longValue() {
            return len == 1 ? sign * (dig[0] & mask) : sign * ((dig[1] & 0x7FFFFFFFL) << 32 | (dig[0] & mask));
        }

        public float floatValue() {
            final int s = Integer.numberOfLeadingZeros(dig[len - 1]);
            if (len == 1 && s >= 8) return sign * dig[0];

            int bits = dig[len - 1]; 

            if (s <= 8) bits >>>= 8 - s;
            else bits = bits << s - 8 | dig[len - 2] >>> 32 - (s - 8); 

            bits ^= 1L << 23; 


            final int exp = (int) (((32 - s + 32L * (len - 1)) - 1 + 127) & 0xFF);
            bits |= exp << 23; 

            bits |= sign & (1 << 31); 


            return Float.intBitsToFloat(bits);
        }

        public double doubleValue() {
            if (len == 1) return sign * (dig[0] & mask);

            final int s = Integer.numberOfLeadingZeros(dig[len - 1]);
            if (len == 2 && 32 - s + 32 <= 53) return sign * ((long) dig[1] << 32 | (dig[0] & mask));

            long bits = (long) dig[len - 1] << 32 | (dig[len - 2] & mask); 

            if (s <= 11) bits >>>= 11 - s;
            else bits = bits << s - 11 | dig[len - 3] >>> 32 - (s - 11); 

            bits ^= 1L << 52; 


            final long exp = ((32 - s + 32L * (len - 1)) - 1 + 1023) & 0x7FF;
            bits |= exp << 52; 

            bits |= (long) sign & (1L << 63); 


            return Double.longBitsToDouble(bits);
        }

        public BigInt umul(final long mul) {
            if (mul == 0) {
                setToZero();
                return this;
            }
            if (len + 2 >= dig.length) realloc(2 * len + 1);

            final long mh = mul >>> 32, ml = mul & mask;
            long carry = 0, next = 0, tmp;
            for (int i = 0; i < len; i++) {
                carry = carry + next; 

                tmp = (dig[i] & mask) * ml;
                next = (dig[i] & mask) * mh;
                dig[i] = (int) (tmp + carry);
                carry = (tmp >>> 32) + (carry >>> 32) + ((tmp & mask) + (carry & mask) >>> 32);
            }
            carry = carry + next;
            dig[len++] = (int) carry;
            dig[len++] = (int) (carry >>> 32);

            while (len > 1 && dig[len - 1] == 0) --len;
            return this;
        }

        public BigInt mul(final long mul) {
            if (isZero()) return this; 

            if (mul < 0) {
                sign = -sign;
                umul(-mul);
            } else umul(mul);
            return this;
        }

        public String toString() {
            if (isZero()) return "0";

            int top = len * 10 + 1;
            final char[] buf = new char[top];
            Arrays.fill(buf, '0');
            final int[] cpy = Arrays.copyOf(dig, len);
            while (true) {
                final int j = top;
                for (long tmp = toStringDiv(); tmp > 0; tmp /= 10)
                    buf[--top] += tmp % 10; 

                if (len == 1 && dig[0] == 0) break;
                else top = j - 13;
            }
            if (sign < 0) buf[--top] = '-';
            System.arraycopy(cpy, 0, dig, 0, len = cpy.length);
            return new String(buf, top, buf.length - top);
        }

        private long toStringDiv() {
            final int pow5 = 1_220_703_125, pow2 = 1 << 13;
            int nextq = 0;
            long rem = 0;
            for (int i = len - 1; i > 0; i--) {
                rem = (rem << 32) + (dig[i] & mask);
                final int q = (int) (rem / pow5);
                rem = rem % pow5;
                dig[i] = nextq | q >>> 13;
                nextq = q << 32 - 13;
            }
            rem = (rem << 32) + (dig[0] & mask);
            final int mod2 = dig[0] & pow2 - 1;
            dig[0] = nextq | (int) (rem / pow5 >>> 13);
            rem = rem % pow5;
            

            

            final long pow10 = (long) pow5 * pow2;
            rem = (rem - pow5 * (mod2 - rem) % pow10 * 67) % pow10;
            if (rem < 0) rem += pow10;
            if (dig[len - 1] == 0 && len > 1)
                if (dig[--len - 1] == 0 && len > 1)
                    --len;
            return rem;
        }

    }

    static class Rational implements Comparable<Rational> {
        public final long numerator;
        public final long denominator;

        public Rational(long numerator, long denominator) {
            if (denominator == 0) {
                throw new IllegalArgumentException();
            }
            long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
            if (denominator > 0) {
                this.numerator = numerator / gcd;
                this.denominator = denominator / gcd;
            } else {
                this.numerator = -numerator / gcd;
                this.denominator = -denominator / gcd;
            }
        }

        public String toString() {
            return numerator + " " + denominator;
        }

        public int compareTo(Rational other) {


            return BigInt.valueOf(numerator).mul(other.denominator)
                    .compareTo(BigInt.valueOf(other.numerator).mul(denominator));
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Rational rational = (Rational) o;
            if (denominator != rational.denominator) {
                return false;
            }
            return numerator == rational.numerator;
        }

        public int hashCode() {
            int result = (int) (numerator ^ (numerator >>> 32));
            result = 31 * result + (int) (denominator ^ (denominator >>> 32));
            return result;
        }

    }

    static interface LongComparator {
        LongComparator DEFAULT = Long::compare;

        int compare(long first, long second);

    }

    static class Line {
        static final double ninf = Double.NEGATIVE_INFINITY;
        static Line qline = new Line(0, 0);
        long m;
        long q;
        double xleft;

        public Line(long _m, long _q) {
            this.m = _m;
            this.q = _q;
            xleft = ninf;
        }

        void recalcxleft(Line pre) {
            xleft = -(double) (pre.q - q) / (pre.m - m);
        }

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

        public int[] readIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = readInt();
            }
            return array;
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

        public int readInt() {
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

        public interface SpaceCharFilter {
            boolean isSpaceChar(int ch);

        }

    }
}

