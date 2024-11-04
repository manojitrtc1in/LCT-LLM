import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ListIterator;
import java.util.InputMismatchException;
import java.util.Deque;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
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
                int[] a = in.id0(n), b = in.id0(n);
                int idx = 0;
                long[] dp = new long[n];
                dp[0] = 0;
                id1 cht = new id1();
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

    static class ArrayDeque<T> implements Deque, List {
        private static final int id9 = 8;
        private static final int id5 = 0x811c9dc5;
        private static final int id11 = 0x01000193;
        private T[] deque;
        private int size;
        private int head;
        private int tail;
        private int mask;

        public ArrayDeque() {
            this(id9);
        }

        public ArrayDeque(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            if (capacity < 1) {
                capacity = 1;
            }
            if ((capacity & (capacity - 1)) != 0) {
                capacity = Integer.highestOneBit(capacity) << 1;
            }
            

            deque = (T[]) new Object[capacity];
            size = 0;
            head = 0;
            tail = 0;
            mask = deque.length - 1;
        }

        public ArrayDeque(T[] srcArray) {
            this(srcArray.length + 1);
            System.arraycopy(srcArray, 0, deque, 0, srcArray.length);
            tail = srcArray.length;
            size = srcArray.length;
        }

        public ArrayDeque(Collection<T> javaCollection) {
            this(javaCollection.size() + 1);
            for (T element : javaCollection) {
                deque[tail++] = element;
            }
            size = javaCollection.size();
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public boolean contains(Object element) {
            for (int i = head; i != tail; i = (i + 1) & mask) {
                if (deque[i] == element) {
                    return true;
                }
            }
            return false;
        }

        public Iterator iterator() {
            return listIterator();
        }

        public Iterator descendingIterator() {
            throw new UnsupportedOperationException();
        }

        public T[] toArray() {
            T[] result = (T[]) new Object[size];
            for (int i = head, j = 0; i != tail; i = (i + 1) & mask) {
                result[j++] = deque[i];
            }
            return result;
        }

        public Object[] toArray(Object[] a) {
            return new Object[0];
        }

        public boolean add(Object element) {
            deque[tail] = (T) element;
            tail = (tail + 1) & mask;
            size++;
            if (size == deque.length) {
                enlarge();
            }
            return true;
        }

        public boolean offer(Object o) {
            return add(o);
        }

        public Object remove() {
            return removeFirst();
        }

        public Object poll() {
            return pollFirst();
        }

        public Object element() {
            return getFirst();
        }

        public Object peek() {
            return peekFirst();
        }

        public void push(Object o) {
            addFirst(o);
        }

        public Object pop() {
            return removeFirst();
        }

        public boolean remove(Object element) {
            for (int i = head, k = 0; i != tail; i = (i + 1) & mask, k++) {
                if (deque[i] == element) {
                    if (k >= (size >>> 1)) {
                        for (int j = (i + 1) & mask; j != tail; j = (j + 1) & mask) {
                            deque[(j - 1) & mask] = deque[j];
                        }
                        tail = (tail - 1) & mask;
                    } else {
                        for (int j = (i - 1) & mask, end = (head - 1) & mask; j != end; j = (j - 1) & mask) {
                            deque[(j + 1) & mask] = deque[j];
                        }
                        head = (head + 1) & mask;
                    }
                    size--;
                    return true;
                }
            }
            return false;
        }

        public boolean addAll(Collection c) {
            if (c != null && !c.isEmpty()) {
                for (Object o : c) {
                    add(o);
                }
                return true;
            }
            return false;
        }

        public boolean retainAll(Collection c) {
            boolean result = false;
            Iterator iterator = iterator();
            while (iterator.hasNext()) {
                Object o = iterator.next();
                if (!c.contains(o)) {
                    iterator.remove();
                    result = true;
                }
            }
            return result;
        }

        public boolean removeAll(Collection c) {
            boolean result = false;
            Iterator iterator = iterator();
            while (iterator.hasNext()) {
                Object o = iterator.next();
                if (c.contains(o)) {
                    iterator.remove();
                    result = true;
                }
            }
            return result;
        }

        public boolean containsAll(Collection c) {
            for (Object o : c) {
                if (!contains(o)) {
                    return false;
                }
            }
            return true;
        }

        public boolean addAll(int index, Collection c) {
            if (c != null && !c.isEmpty()) {
                for (Object o : c) {
                    add(index++, o);
                }
                return true;
            }
            return false;
        }

        public void clear() {
            size = 0;
            head = 0;
            tail = 0;
        }

        public void addFirst(Object element) {
            head = (head - 1) & mask;
            deque[head] = (T) element;
            size++;
            if (size == deque.length) {
                enlarge();
            }
        }

        public void addLast(Object element) {
            deque[tail] = (T) element;
            tail = (tail + 1) & mask;
            size++;
            if (size == deque.length) {
                enlarge();
            }
        }

        public boolean offerFirst(Object o) {
            addFirst(o);
            return true;
        }

        public boolean offerLast(Object o) {
            addLast(o);
            return true;
        }

        public T getFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call getFirst() on empty ArrayDeque");
            }
            return deque[head];
        }

        public T getLast() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call getLast() on empty ArrayDeque");
            }
            return deque[(tail - 1) & mask];
        }

        public Object peekFirst() {
            return getFirst();
        }

        public Object peekLast() {
            return getLast();
        }

        public boolean id13(Object o) {
            for (int i = 0; i < size(); i++) {
                if (MiscUtils.equals(get(i), o)) {
                    removeAt(i);
                    return true;
                }
            }
            return false;
        }

        public boolean id6(Object o) {
            for (int i = size() - 1; i >= 0; i--) {
                if (MiscUtils.equals(get(i), o)) {
                    removeAt(i);
                    return true;
                }
            }
            return false;
        }

        public T removeFirst() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call removeFirst() on empty ArrayDeque");
            }
            final T removedElement = deque[head];
            size--;
            head = (head + 1) & mask;
            return removedElement;
        }

        public T removeLast() {
            if (size == 0) {
                throw new NoSuchElementException("Trying to call removeLast() on empty ArrayDeque");
            }
            size--;
            tail = (tail - 1) & mask;
            return deque[tail];
        }

        public Object pollFirst() {
            return removeFirst();
        }

        public Object pollLast() {
            return removeLast();
        }

        public T get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            return deque[(head + index) & mask];
        }

        public T set(int index, Object element) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            final int realIndex = (head + index) & mask;
            final T oldElement = deque[realIndex];
            deque[realIndex] = (T) element;
            return oldElement;
        }

        public void add(int index, Object element) {
            insert(index, element);
        }

        public Object remove(int index) {
            return removeAt(index);
        }

        public void insert(int index, Object element) {
            if (index < 0 || index > size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            if (index > (size >>> 1)) {
                final int realIndex = (head + index) & mask;
                for (int i = tail; i != realIndex; i = (i - 1) & mask) {
                    deque[i] = deque[(i - 1) & mask];
                }
                tail = (tail + 1) & mask;
                deque[realIndex] = (T) element;
            } else {
                head = (head - 1) & mask;
                final int realIndex = (head + index) & mask;
                for (int i = head; i != realIndex; i = (i + 1) & mask) {
                    deque[i] = deque[(i + 1) & mask];
                }
                deque[realIndex] = (T) element;
            }
            size++;
            if (size == deque.length) {
                enlarge();
            }
        }

        public T removeAt(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            final int realIndex = (head + index) & mask;
            final T removedElement = deque[realIndex];
            if (index >= (size >>> 1)) {
                for (int i = (realIndex + 1) & mask; i != tail; i = (i + 1) & mask) {
                    deque[(i - 1) & mask] = deque[i];
                }
                tail = (tail - 1) & mask;
            } else {
                for (int i = (realIndex - 1) & mask, end = (head - 1) & mask; i != end; i = (i - 1) & mask) {
                    deque[(i + 1) & mask] = deque[i];
                }
                head = (head + 1) & mask;
            }
            size--;
            return removedElement;
        }

        public int indexOf(Object element) {
            for (int i = head, j = 0; i != tail; i = (i + 1) & mask, j++) {
                if (deque[i] == element) {
                    return j;
                }
            }
            return -1;
        }

        public int id4(Object element) {
            for (int i = (tail - 1) & mask, j = size - 1, end = (head - 1) & mask; i != end; i = (i - 1) & mask, j--) {
                if (deque[i] == element) {
                    return j;
                }
            }
            return -1;
        }

        public ListIterator listIterator() {
            throw new UnsupportedOperationException();
        }

        public ListIterator listIterator(int index) {
            throw new UnsupportedOperationException();
        }

        public List subList(int fromIndex, int toIndex) {
            List list = new ArrayDeque();
            for (int i = fromIndex; i < toIndex; i++) {
                list.add(get(i));
            }
            return list;
        }

        private void enlarge() {
            int newSize = (size << 1);
            T[] newArray = (T[]) new Object[newSize];
            System.arraycopy(deque, head, newArray, 0, deque.length - head);
            System.arraycopy(deque, 0, newArray, deque.length - tail, tail);
            deque = newArray;
            head = 0;
            tail = size;
            mask = deque.length - 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            ArrayDeque that = (ArrayDeque) o;

            if (size != that.size) {
                return false;
            }
            for (int i = head, j = that.head; i != tail; i = (i + 1) & mask, j = (j + 1) & that.mask) {
                if (deque[i] != that.deque[j]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id5;
            for (int i = head; i != tail; i = (i + 1) & mask) {
                hash = (hash ^ deque[i].hashCode()) * id11;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = head; i != tail; i = (i + 1) & mask) {
                if (i != head) {
                    sb.append(", ");
                }
                sb.append(deque[i]);
            }
            sb.append(']');
            return sb.toString();
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

    static class MiscUtils {
        public static <T> boolean equals(T first, T second) {
            return first == null && second == null || first != null && first.equals(second);
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

    static class id1 {
        private ArrayDeque<Line> data;
        private LongComparator comparator;

        public id1() {
            this(LongComparator.DEFAULT);
        }

        public id1(LongComparator comparator) {
            data = new ArrayDeque<>();
            this.comparator = comparator;
        }

        private boolean badBack(Line newLine) {
            if (data.size() < 2) {
                return false;
            }
            Line secondLast = data.get(data.size() - 2), last = data.getLast();
            return new Rational(last.q - newLine.q, newLine.m - last.m)
                    .compareTo(new Rational(secondLast.q - last.q, last.m - secondLast.m)) <= 0;
        }

        public void insert(Line l) {
            assert (data.isEmpty() || comparator.compare(l.m, data.getLast().m) <= 0);
            if (!data.isEmpty() && l.m == data.getLast().m) {
                data.getLast().q = comparator.min(data.getLast().q, l.q);
                return;
            }
            while (badBack(l)) {
                data.removeLast();
            }
            if (!data.isEmpty()) {
                l.id10(data.getLast());
            }
            data.add(l);
        }

        public long query(long x) {
            while (data.size() > 1 && x > data.get(1).xleft) {
                data.removeFirst();
            }
            return data.getFirst().m * x + data.getFirst().q;
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

        default long min(long first, long second) {
            return compare(first, second) <= 0 ? first : second;
        }

    }

    static class Line {
        static final double ninf = Double.NEGATIVE_INFINITY;
        long m;
        long q;
        double xleft;

        public Line(long _m, long _q) {
            this.m = _m;
            this.q = _q;
            xleft = ninf;
        }

        void id10(Line pre) {
            xleft = -(double) (pre.q - q) / (pre.m - m);
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

        public BigInt id8() {
            dig[0] = 0;
            len = 1;
            sign = 1; 

            return this;
        }

        public int id2(final BigInt a) {
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
                if (a.sign < 0 || a.isZero()) return -id2(a);
                return -1;
            }
            if (a.sign > 0 || a.isZero()) return id2(a);
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
                id8();
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
                for (long tmp = id7(); tmp > 0; tmp /= 10)
                    buf[--top] += tmp % 10; 

                if (len == 1 && dig[0] == 0) break;
                else top = j - 13;
            }
            if (sign < 0) buf[--top] = '-';
            System.arraycopy(cpy, 0, dig, 0, len = cpy.length);
            return new String(buf, top, buf.length - top);
        }

        private long id7() {
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id12 filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] id0(int size) {
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
            while (id3(c)) {
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
            } while (!id3(c));
            return res * sgn;
        }

        public boolean id3(int c) {
            if (filter != null) {
                return filter.id3(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id12 {
            boolean id3(int ch);

        }

    }
}

