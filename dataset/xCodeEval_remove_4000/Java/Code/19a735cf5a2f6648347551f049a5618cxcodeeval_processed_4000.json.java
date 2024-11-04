import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.util.InputMismatchException;
import java.util.logging.Level;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.IllegalFormatException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.logging.Logger;
import java.io.Serializable;
import java.util.List;
import java.io.Writer;
import java.util.Queue;
import java.util.Comparator;
import java.util.ArrayDeque;
import java.util.Collections;
import java.util.ConcurrentModificationException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int id36 = in.nextInt();
            long initCost = in.nextInt();
            long perMinute = in.nextInt();

            long mod = (long) Math.pow(10, 9) + 7;

            PriorityQueue<Integer> start = new PriorityQueue<>();
            PriorityQueue<Integer> end = new PriorityQueue<>();

            for (int i = 0; i < id36; i++) {
                int s = in.nextInt();
                int e = in.nextInt();
                start.add(s);
                end.add(e);
            }


            id42<Integer> returns = id42.create();
            id42<Integer> rentals = id42.create();

            while (!end.isEmpty()) {
                int nextE = end.peek();

                if (start.peek() != null && start.peek() <= end.peek()) {
                    int nextS = start.peek();
                    

                    start.poll();
                    if (returns.isEmpty()) {
                        

                        rentals.add(nextS);
                    } else {
                        

                        

                        int r = returns.peekLast();

                        

                        


                        

                        

                        

                        


                        long id41 = (nextS - r) * perMinute;
                        if (initCost <= id41) {
                            rentals.add(nextS);
                        } else {
                            returns.pollLast();
                        }
                    }
                } else {
                    

                    

                    returns.add(nextE);
                    end.poll();
                }
            }

            

            long id58 = 0;
            long lastTick = 0;
            BigInteger acc = BigInteger.ZERO;
            while (!returns.isEmpty()) {
                Integer nextS = rentals.peekFirst();
                Integer nextE = returns.peekFirst();

                if (nextS != null && nextS <= nextE) {
                    acc = acc.add(BigInteger.valueOf(initCost));
                    acc = acc.add(BigInteger.valueOf((nextS - lastTick) * id58 * perMinute));
                    id58++;
                    rentals.pollFirst();
                    lastTick = nextS;
                } else {
                    acc = acc.add(BigInteger.valueOf((nextE - lastTick) * id58 * perMinute));
                    id58--;
                    returns.pollFirst();
                    lastTick = nextE;
                }

                acc = acc.mod(BigInteger.valueOf(mod));
            }

            out.println(acc);

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id54 filter;

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
            while (id11(c)) {
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
            } while (!id11(c));
            return res * sgn;
        }

        public boolean id11(int c) {
            if (filter != null) {
                return filter.id11(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface id54 {
            public boolean id11(int ch);

        }

    }

    static final class id42<E> extends AbstractQueue<E> {
        private final Heap minHeap;
        private final Heap maxHeap;
        final int maximumSize;
        private Object[] queue;
        private int size;
        private int modCount;
        private static final int id31 = 0x55555555;
        private static final int id5 = 0xaaaaaaaa;
        private static final int id52 = 11;

        public static <E extends Comparable<E>> id42<E> create() {
            return new id42.Builder<Comparable>(Ordering.natural()).create();
        }

        private id42(id42.Builder<? super E> builder, int queueSize) {
            Ordering<E> ordering = builder.ordering();
            this.minHeap = new Heap(ordering);
            this.maxHeap = new Heap(ordering.reverse());
            minHeap.otherHeap = maxHeap;
            maxHeap.otherHeap = minHeap;

            this.maximumSize = builder.maximumSize;
            

            this.queue = new Object[queueSize];
        }

        public int size() {
            return size;
        }

        public boolean add(E element) {
            offer(element);
            return true;
        }

        public boolean addAll(Collection<? extends E> newElements) {
            boolean modified = false;
            for (E element : newElements) {
                offer(element);
                modified = true;
            }
            return modified;
        }

        public boolean offer(E element) {
            Preconditions.id47(element);
            modCount++;
            int insertIndex = size++;

            id16();

            

            

            id4(insertIndex).bubbleUp(insertIndex, element);
            return size <= maximumSize || pollLast() != element;
        }

        public E poll() {
            return isEmpty() ? null : id38(0);
        }

        E elementData(int index) {
            return (E) queue[index];
        }

        public E peek() {
            return isEmpty() ? null : elementData(0);
        }

        private int id43() {
            switch (size) {
                case 1:
                    return 0; 

                case 2:
                    return 1; 

                default:
                    

                    

                    return (maxHeap.compareElements(1, 2) <= 0) ? 1 : 2;
            }
        }

        public E pollFirst() {
            return poll();
        }

        public E peekFirst() {
            return peek();
        }

        public E pollLast() {
            return isEmpty() ? null : id38(id43());
        }

        public E peekLast() {
            return isEmpty() ? null : elementData(id43());
        }

        id42.MoveDesc<E> removeAt(int index) {
            Preconditions.id25(index, size);
            modCount++;
            size--;
            if (size == index) {
                queue[size] = null;
                return null;
            }
            E id26 = elementData(size);
            int id9 = id4(size).id34(id26);
            if (id9 == index) {
                

                

                

                queue[size] = null;
                return null;
            }
            E id33 = elementData(size);
            queue[size] = null;
            id42.MoveDesc<E> changes = fillHole(index, id33);
            if (id9 < index) {
                

                if (changes == null) {
                    

                    return new id42.MoveDesc<E>(id26, id33);
                } else {
                    

                    

                    return new id42.MoveDesc<E>(id26, changes.replaced);
                }
            }
            

            return changes;
        }

        private id42.MoveDesc<E> fillHole(int index, E id33) {
            Heap heap = id4(index);
            

            

            

            

            

            

            

            int vacated = heap.id21(index);
            

            int id40 = heap.id48(vacated, id33);
            if (id40 == vacated) {
                

                

                

                return heap.id45(index, vacated, id33);
            } else {
                return (id40 < index) ? new id42.MoveDesc<E>(id33, elementData(index)) : null;
            }
        }

        private E id38(int index) {
            E value = elementData(index);
            removeAt(index);
            return value;
        }

        private Heap id4(int i) {
            return id37(i) ? minHeap : maxHeap;
        }

        static boolean id37(int index) {
            int oneBased = ~~(index + 1); 

            Preconditions.checkState(oneBased > 0, "negative index");
            return (oneBased & id31) > (oneBased & id5);
        }

        public Iterator<E> iterator() {
            return new QueueIterator();
        }

        public void clear() {
            for (int i = 0; i < size; i++) {
                queue[i] = null;
            }
            size = 0;
        }

        public Object[] toArray() {
            Object[] copyTo = new Object[size];
            System.arraycopy(queue, 0, copyTo, 0, size);
            return copyTo;
        }

        static int id50(
                int id0, int maximumSize, Iterable<?> initialContents) {
            

            int result =
                    (id0 == id42.Builder.id28)
                            ? id52
                            : id0;

            

            if (initialContents instanceof Collection) {
                int initialSize = ((Collection<?>) initialContents).size();
                result = Math.max(result, initialSize);
            }

            

            return id46(result, maximumSize);
        }

        private void id16() {
            if (size > queue.length) {
                int newCapacity = id6();
                Object[] newQueue = new Object[newCapacity];
                System.arraycopy(queue, 0, newQueue, 0, queue.length);
                queue = newQueue;
            }
        }

        private int id6() {
            int oldCapacity = queue.length;
            int newCapacity =
                    (oldCapacity < 64) ? (oldCapacity + 1) * 2 : IntMath.checkedMultiply(oldCapacity / 2, 3);
            return id46(newCapacity, maximumSize);
        }

        private static int id46(int queueSize, int maximumSize) {
            return Math.min(queueSize - 1, maximumSize) + 1; 

        }

        public static final class Builder<B> {
            private static final int id28 = -1;
            private final Comparator<B> comparator;
            private int expectedSize = id28;
            private int maximumSize = Integer.MAX_VALUE;

            private Builder(Comparator<B> comparator) {
                this.comparator = Preconditions.id47(comparator);
            }

            public <T extends B> id42<T> create() {
                return create(Collections.<T>emptySet());
            }

            public <T extends B> id42<T> create(Iterable<? extends T> initialContents) {
                id42<T> queue =
                        new id42<T>(
                                this, id50(expectedSize, maximumSize, initialContents));
                for (T element : initialContents) {
                    queue.offer(element);
                }
                return queue;
            }

            

            private <T extends B> Ordering<T> ordering() {
                return Ordering.from((Comparator<T>) comparator);
            }

        }

        static class MoveDesc<E> {
            final E id33;
            final E replaced;

            MoveDesc(E id33, E replaced) {
                this.id33 = id33;
                this.replaced = replaced;
            }

        }

        private class Heap {
            final Ordering<E> ordering;
            Heap otherHeap;

            Heap(Ordering<E> ordering) {
                this.ordering = ordering;
            }

            int compareElements(int a, int b) {
                return ordering.compare(elementData(a), elementData(b));
            }

            id42.MoveDesc<E> id45(int removeIndex, int vacated, E id33) {
                int crossOver = crossOver(vacated, id33);
                if (crossOver == vacated) {
                    return null;
                }
                

                

                E parent;
                

                

                

                if (crossOver < removeIndex) {
                    

                    

                    parent = elementData(removeIndex);
                } else {
                    parent = elementData(id59(removeIndex));
                }
                

                if (otherHeap.id48(crossOver, id33) < removeIndex) {
                    return new id42.MoveDesc<E>(id33, parent);
                } else {
                    return null;
                }
            }

            void bubbleUp(int index, E x) {
                int crossOver = id7(index, x);

                Heap heap;
                if (crossOver == index) {
                    heap = this;
                } else {
                    index = crossOver;
                    heap = otherHeap;
                }
                heap.id48(index, x);
            }

            int id48(int index, E x) {
                while (index > 2) {
                    int id24 = id44(index);
                    E e = elementData(id24);
                    if (ordering.compare(e, x) <= 0) {
                        break;
                    }
                    queue[index] = e;
                    index = id24;
                }
                queue[index] = x;
                return index;
            }

            int findMin(int index, int len) {
                if (index >= size) {
                    return -1;
                }
                Preconditions.checkState(index > 0);
                int limit = Math.min(index, size - len) + len;
                int minIndex = index;
                for (int i = index + 1; i < limit; i++) {
                    if (compareElements(i, minIndex) < 0) {
                        minIndex = i;
                    }
                }
                return minIndex;
            }

            int id57(int index) {
                return findMin(id22(index), 2);
            }

            int id13(int index) {
                int id49 = id22(index);
                if (id49 < 0) {
                    return -1;
                }
                return findMin(id22(id49), 4);
            }

            int id7(int index, E x) {
                if (index == 0) {
                    queue[0] = x;
                    return 0;
                }
                int parentIndex = id59(index);
                E parentElement = elementData(parentIndex);
                if (parentIndex != 0) {
                    

                    

                    

                    

                    int id51 = id59(parentIndex);
                    int id32 = id39(id51);
                    if (id32 != parentIndex && id22(id32) >= size) {
                        E id17 = elementData(id32);
                        if (ordering.compare(id17, parentElement) < 0) {
                            parentIndex = id32;
                            parentElement = id17;
                        }
                    }
                }
                if (ordering.compare(parentElement, x) < 0) {
                    queue[index] = parentElement;
                    queue[parentIndex] = x;
                    return parentIndex;
                }
                queue[index] = x;
                return index;
            }

            int id34(E id26) {
                int parentIndex = id59(size);
                if (parentIndex != 0) {
                    int id51 = id59(parentIndex);
                    int id32 = id39(id51);
                    if (id32 != parentIndex && id22(id32) >= size) {
                        E id17 = elementData(id32);
                        if (ordering.compare(id17, id26) < 0) {
                            queue[id32] = id26;
                            queue[size] = id17;
                            return id32;
                        }
                    }
                }
                return size;
            }

            int crossOver(int index, E x) {
                int id2 = id57(index);
                

                

                if ((id2 > 0) && (ordering.compare(elementData(id2), x) < 0)) {
                    queue[index] = elementData(id2);
                    queue[id2] = x;
                    return id2;
                }
                return id7(index, x);
            }

            int id21(int index) {
                int id14;
                while ((id14 = id13(index)) > 0) {
                    queue[index] = elementData(id14);
                    index = id14;
                }
                return index;
            }

            private int id22(int i) {
                return i * 2 + 1;
            }

            private int id39(int i) {
                return i * 2 + 2;
            }

            private int id59(int i) {
                return (i - 1) / 2;
            }

            private int id44(int i) {
                return id59(id59(i)); 

            }

        }

        private class QueueIterator implements Iterator<E> {
            private int cursor = -1;
            private int nextCursor = -1;
            private int id55 = modCount;
            private Queue<E> id1;
            private List<E> skipMe;
            private E id35;
            private boolean canRemove;

            public boolean hasNext() {
                id12();
                id10(cursor + 1);
                return (nextCursor < size()) || ((id1 != null) && !id1.isEmpty());
            }

            public E next() {
                id12();
                id10(cursor + 1);
                if (nextCursor < size()) {
                    cursor = nextCursor;
                    canRemove = true;
                    return elementData(cursor);
                } else if (id1 != null) {
                    cursor = size();
                    id35 = id1.poll();
                    if (id35 != null) {
                        canRemove = true;
                        return id35;
                    }
                }
                throw new NoSuchElementException("iterator moved past last element in queue.");
            }

            public void remove() {
                id19.checkRemove(canRemove);
                id12();
                canRemove = false;
                id55++;
                if (cursor < size()) {
                    id42.MoveDesc<E> moved = removeAt(cursor);
                    if (moved != null) {
                        if (id1 == null) {
                            id1 = new ArrayDeque<E>();
                            skipMe = new ArrayList<E>(3);
                        }
                        if (!id56(skipMe, moved.id33)) {
                            id1.add(moved.id33);
                        }
                        if (!id56(id1, moved.replaced)) {
                            skipMe.add(moved.replaced);
                        }
                    }
                    cursor--;
                    nextCursor--;
                } else { 

                    Preconditions.checkState(removeExact(id35));
                    id35 = null;
                }
            }

            private boolean id56(Iterable<E> elements, E target) {
                for (Iterator<E> it = elements.iterator(); it.hasNext(); ) {
                    E element = it.next();
                    if (element == target) {
                        it.remove();
                        return true;
                    }
                }
                return false;
            }

            private boolean removeExact(Object target) {
                for (int i = 0; i < size; i++) {
                    if (queue[i] == target) {
                        removeAt(i);
                        return true;
                    }
                }
                return false;
            }

            private void id12() {
                if (modCount != id55) {
                    throw new ConcurrentModificationException();
                }
            }

            private void id10(int c) {
                if (nextCursor < c) {
                    if (skipMe != null) {
                        while (c < size() && id56(skipMe, elementData(c))) {
                            c++;
                        }
                    }
                    nextCursor = c;
                }
            }

        }

    }

    static interface id29 {
    }

    static interface id23 {
    }

    static interface Nullable {
    }

    static interface id3 {
    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static interface id60 {
    }

    static final class Verify {
        private Verify() {
        }

    }

    static final class Strings {
        private Strings() {
        }

        public static String id27(
                String template, Object... args) {
            template = String.valueOf(template); 


            if (args == null) {
                args = new Object[]{"(Object[])null"};
            } else {
                for (int i = 0; i < args.length; i++) {
                    args[i] = id15(args[i]);
                }
            }

            

            StringBuilder builder = new StringBuilder(template.length() + 16 * args.length);
            int templateStart = 0;
            int i = 0;
            while (i < args.length) {
                int placeholderStart = template.indexOf("%s", templateStart);
                if (placeholderStart == -1) {
                    break;
                }
                builder.append(template, templateStart, placeholderStart);
                builder.append(args[i++]);
                templateStart = placeholderStart + 2;
            }
            builder.append(template, templateStart, template.length());

            

            if (i < args.length) {
                builder.append(" [");
                builder.append(args[i++]);
                while (i < args.length) {
                    builder.append(", ");
                    builder.append(args[i++]);
                }
                builder.append(']');
            }

            return builder.toString();
        }

        private static String id15(Object o) {
            try {
                return String.valueOf(o);
            } catch (Exception e) {
                

                String id30 =
                        o.getClass().getName() + '@' + Integer.toHexString(System.identityHashCode(o));
                

                Logger.getLogger("com.google.common.base.Strings")
                        .log(Level.WARNING, "Exception during id27 for " + id30, e);
                return "<" + id30 + " threw " + e.getClass().getName() + ">";
            }
        }

    }

    static final class id19 {
        static void checkRemove(boolean canRemove) {
            Preconditions.checkState(canRemove, "no calls to next() since the last call to remove()");
        }

    }

    static final class ReverseOrdering<T> extends Ordering<T> implements Serializable {
        final Ordering<? super T> forwardOrder;

        ReverseOrdering(Ordering<? super T> forwardOrder) {
            this.forwardOrder = Preconditions.id47(forwardOrder);
        }

        public int compare(T a, T b) {
            return forwardOrder.compare(b, a);
        }




        public <S extends T> Ordering<S> reverse() {
            return (Ordering<S>) forwardOrder;
        }

        public int hashCode() {
            return -forwardOrder.hashCode();
        }

        public boolean equals(Object object) {
            if (object == this) {
                return true;
            }
            if (object instanceof ReverseOrdering) {
                ReverseOrdering<?> that = (ReverseOrdering<?>) object;
                return this.forwardOrder.equals(that.forwardOrder);
            }
            return false;
        }

        public String toString() {
            return forwardOrder + ".reverse()";
        }

    }

    static interface Weak {
    }

    static abstract class Ordering<T> implements Comparator<T> {
        

        public static <C extends Comparable> Ordering<C> natural() {
            return (Ordering<C>) NaturalOrdering.INSTANCE;
        }

        public static <T> Ordering<T> from(Comparator<T> comparator) {
            return (comparator instanceof Ordering)
                    ? (Ordering<T>) comparator
                    : new ComparatorOrdering<T>(comparator);
        }

        protected Ordering() {
        }

        public <S extends T> Ordering<S> reverse() {
            return new ReverseOrdering<S>(this);
        }




        public abstract int compare(T left, T right);

    }

    static final class Preconditions {
        private Preconditions() {
        }

        public static void checkState(boolean expression) {
            if (!expression) {
                throw new IllegalStateException();
            }
        }

        public static void checkState(boolean expression, Object errorMessage) {
            if (!expression) {
                throw new IllegalStateException(String.valueOf(errorMessage));
            }
        }

        public static <T> T id47(T reference) {
            if (reference == null) {
                throw new NullPointerException();
            }
            return reference;
        }

        public static int id25(int index, int size) {
            return id25(index, size, "index");
        }

        public static int id25(int index, int size, String desc) {
            

            if (index < 0 || index > size) {
                throw new IndexOutOfBoundsException(id20(index, size, desc));
            }
            return index;
        }

        private static String id20(int index, int size, String desc) {
            if (index < 0) {
                return Strings.id27("%s (%s) must not be negative", desc, index);
            } else if (size < 0) {
                throw new IllegalArgumentException("negative size: " + size);
            } else { 

                return Strings.id27("%s (%s) must not be greater than size (%s)", desc, index, size);
            }
        }

    }

    static 

    final class NaturalOrdering extends Ordering<Comparable> implements Serializable {
        static final NaturalOrdering INSTANCE = new NaturalOrdering();

        public int compare(Comparable left, Comparable right) {
            Preconditions.id47(left); 

            Preconditions.id47(right);
            return left.compareTo(right);
        }

        public <S extends Comparable> Ordering<S> reverse() {
            return (Ordering<S>) id18.INSTANCE;
        }

        public String toString() {
            return "Ordering.natural()";
        }

        private NaturalOrdering() {
        }

    }

    static final class IntMath {
        public static int checkedMultiply(int a, int b) {
            long result = (long) a * b;
            id8.id53(result == (int) result, "checkedMultiply", a, b);
            return (int) result;
        }

        private IntMath() {
        }

    }

    static final class ComparatorOrdering<T> extends Ordering<T> implements Serializable {
        final Comparator<T> comparator;

        ComparatorOrdering(Comparator<T> comparator) {
            this.comparator = Preconditions.id47(comparator);
        }

        public int compare(T a, T b) {
            return comparator.compare(a, b);
        }

        public boolean equals(Object object) {
            if (object == this) {
                return true;
            }
            if (object instanceof ComparatorOrdering) {
                ComparatorOrdering<?> that = (ComparatorOrdering<?>) object;
                return this.comparator.equals(that.comparator);
            }
            return false;
        }

        public int hashCode() {
            return comparator.hashCode();
        }

        public String toString() {
            return comparator.toString();
        }

    }

    static final class id8 {
        static void id53(boolean condition, String methodName, int a, int b) {
            if (!condition) {
                throw new ArithmeticException("overflow: " + methodName + "(" + a + ", " + b + ")");
            }
        }

        private id8() {
        }

    }

    static 

    final class id18 extends Ordering<Comparable> implements Serializable {
        static final id18 INSTANCE = new id18();

        public int compare(Comparable left, Comparable right) {
            Preconditions.id47(left); 

            if (left == right) {
                return 0;
            }

            return right.compareTo(left);
        }

        public <S extends Comparable> Ordering<S> reverse() {
            return Ordering.natural();
        }

        public String toString() {
            return "Ordering.natural().reverse()";
        }

        private id18() {
        }

    }
}

