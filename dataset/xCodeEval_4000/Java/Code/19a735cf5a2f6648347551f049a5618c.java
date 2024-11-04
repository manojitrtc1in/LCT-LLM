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
            int numTvShows = in.nextInt();
            long initCost = in.nextInt();
            long perMinute = in.nextInt();

            long mod = (long) Math.pow(10, 9) + 7;

            PriorityQueue<Integer> start = new PriorityQueue<>();
            PriorityQueue<Integer> end = new PriorityQueue<>();

            for (int i = 0; i < numTvShows; i++) {
                int s = in.nextInt();
                int e = in.nextInt();
                start.add(s);
                end.add(e);
            }


            MinMaxPriorityQueue<Integer> returns = MinMaxPriorityQueue.create();
            MinMaxPriorityQueue<Integer> rentals = MinMaxPriorityQueue.create();

            while (!end.isEmpty()) {
                int nextE = end.peek();

                if (start.peek() != null && start.peek() <= end.peek()) {
                    int nextS = start.peek();
                    

                    start.poll();
                    if (returns.isEmpty()) {
                        

                        rentals.add(nextS);
                    } else {
                        

                        

                        int r = returns.peekLast();

                        

                        


                        

                        

                        

                        


                        long costOfRental = (nextS - r) * perMinute;
                        if (initCost <= costOfRental) {
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

            

            long currRenting = 0;
            long lastTick = 0;
            BigInteger acc = BigInteger.ZERO;
            while (!returns.isEmpty()) {
                Integer nextS = rentals.peekFirst();
                Integer nextE = returns.peekFirst();

                if (nextS != null && nextS <= nextE) {
                    acc = acc.add(BigInteger.valueOf(initCost));
                    acc = acc.add(BigInteger.valueOf((nextS - lastTick) * currRenting * perMinute));
                    currRenting++;
                    rentals.pollFirst();
                    lastTick = nextS;
                } else {
                    acc = acc.add(BigInteger.valueOf((nextE - lastTick) * currRenting * perMinute));
                    currRenting--;
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static final class MinMaxPriorityQueue<E> extends AbstractQueue<E> {
        private final Heap minHeap;
        private final Heap maxHeap;
        final int maximumSize;
        private Object[] queue;
        private int size;
        private int modCount;
        private static final int EVEN_POWERS_OF_TWO = 0x55555555;
        private static final int ODD_POWERS_OF_TWO = 0xaaaaaaaa;
        private static final int DEFAULT_CAPACITY = 11;

        public static <E extends Comparable<E>> MinMaxPriorityQueue<E> create() {
            return new MinMaxPriorityQueue.Builder<Comparable>(Ordering.natural()).create();
        }

        private MinMaxPriorityQueue(MinMaxPriorityQueue.Builder<? super E> builder, int queueSize) {
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
            Preconditions.checkNotNull(element);
            modCount++;
            int insertIndex = size++;

            growIfNeeded();

            

            

            heapForIndex(insertIndex).bubbleUp(insertIndex, element);
            return size <= maximumSize || pollLast() != element;
        }

        public E poll() {
            return isEmpty() ? null : removeAndGet(0);
        }

        E elementData(int index) {
            return (E) queue[index];
        }

        public E peek() {
            return isEmpty() ? null : elementData(0);
        }

        private int getMaxElementIndex() {
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
            return isEmpty() ? null : removeAndGet(getMaxElementIndex());
        }

        public E peekLast() {
            return isEmpty() ? null : elementData(getMaxElementIndex());
        }

        MinMaxPriorityQueue.MoveDesc<E> removeAt(int index) {
            Preconditions.checkPositionIndex(index, size);
            modCount++;
            size--;
            if (size == index) {
                queue[size] = null;
                return null;
            }
            E actualLastElement = elementData(size);
            int lastElementAt = heapForIndex(size).swapWithConceptuallyLastElement(actualLastElement);
            if (lastElementAt == index) {
                

                

                

                queue[size] = null;
                return null;
            }
            E toTrickle = elementData(size);
            queue[size] = null;
            MinMaxPriorityQueue.MoveDesc<E> changes = fillHole(index, toTrickle);
            if (lastElementAt < index) {
                

                if (changes == null) {
                    

                    return new MinMaxPriorityQueue.MoveDesc<E>(actualLastElement, toTrickle);
                } else {
                    

                    

                    return new MinMaxPriorityQueue.MoveDesc<E>(actualLastElement, changes.replaced);
                }
            }
            

            return changes;
        }

        private MinMaxPriorityQueue.MoveDesc<E> fillHole(int index, E toTrickle) {
            Heap heap = heapForIndex(index);
            

            

            

            

            

            

            

            int vacated = heap.fillHoleAt(index);
            

            int bubbledTo = heap.bubbleUpAlternatingLevels(vacated, toTrickle);
            if (bubbledTo == vacated) {
                

                

                

                return heap.tryCrossOverAndBubbleUp(index, vacated, toTrickle);
            } else {
                return (bubbledTo < index) ? new MinMaxPriorityQueue.MoveDesc<E>(toTrickle, elementData(index)) : null;
            }
        }

        private E removeAndGet(int index) {
            E value = elementData(index);
            removeAt(index);
            return value;
        }

        private Heap heapForIndex(int i) {
            return isEvenLevel(i) ? minHeap : maxHeap;
        }

        static boolean isEvenLevel(int index) {
            int oneBased = ~~(index + 1); 

            Preconditions.checkState(oneBased > 0, "negative index");
            return (oneBased & EVEN_POWERS_OF_TWO) > (oneBased & ODD_POWERS_OF_TWO);
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

        static int initialQueueSize(
                int configuredExpectedSize, int maximumSize, Iterable<?> initialContents) {
            

            int result =
                    (configuredExpectedSize == MinMaxPriorityQueue.Builder.UNSET_EXPECTED_SIZE)
                            ? DEFAULT_CAPACITY
                            : configuredExpectedSize;

            

            if (initialContents instanceof Collection) {
                int initialSize = ((Collection<?>) initialContents).size();
                result = Math.max(result, initialSize);
            }

            

            return capAtMaximumSize(result, maximumSize);
        }

        private void growIfNeeded() {
            if (size > queue.length) {
                int newCapacity = calculateNewCapacity();
                Object[] newQueue = new Object[newCapacity];
                System.arraycopy(queue, 0, newQueue, 0, queue.length);
                queue = newQueue;
            }
        }

        private int calculateNewCapacity() {
            int oldCapacity = queue.length;
            int newCapacity =
                    (oldCapacity < 64) ? (oldCapacity + 1) * 2 : IntMath.checkedMultiply(oldCapacity / 2, 3);
            return capAtMaximumSize(newCapacity, maximumSize);
        }

        private static int capAtMaximumSize(int queueSize, int maximumSize) {
            return Math.min(queueSize - 1, maximumSize) + 1; 

        }

        public static final class Builder<B> {
            private static final int UNSET_EXPECTED_SIZE = -1;
            private final Comparator<B> comparator;
            private int expectedSize = UNSET_EXPECTED_SIZE;
            private int maximumSize = Integer.MAX_VALUE;

            private Builder(Comparator<B> comparator) {
                this.comparator = Preconditions.checkNotNull(comparator);
            }

            public <T extends B> MinMaxPriorityQueue<T> create() {
                return create(Collections.<T>emptySet());
            }

            public <T extends B> MinMaxPriorityQueue<T> create(Iterable<? extends T> initialContents) {
                MinMaxPriorityQueue<T> queue =
                        new MinMaxPriorityQueue<T>(
                                this, initialQueueSize(expectedSize, maximumSize, initialContents));
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
            final E toTrickle;
            final E replaced;

            MoveDesc(E toTrickle, E replaced) {
                this.toTrickle = toTrickle;
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

            MinMaxPriorityQueue.MoveDesc<E> tryCrossOverAndBubbleUp(int removeIndex, int vacated, E toTrickle) {
                int crossOver = crossOver(vacated, toTrickle);
                if (crossOver == vacated) {
                    return null;
                }
                

                

                E parent;
                

                

                

                if (crossOver < removeIndex) {
                    

                    

                    parent = elementData(removeIndex);
                } else {
                    parent = elementData(getParentIndex(removeIndex));
                }
                

                if (otherHeap.bubbleUpAlternatingLevels(crossOver, toTrickle) < removeIndex) {
                    return new MinMaxPriorityQueue.MoveDesc<E>(toTrickle, parent);
                } else {
                    return null;
                }
            }

            void bubbleUp(int index, E x) {
                int crossOver = crossOverUp(index, x);

                Heap heap;
                if (crossOver == index) {
                    heap = this;
                } else {
                    index = crossOver;
                    heap = otherHeap;
                }
                heap.bubbleUpAlternatingLevels(index, x);
            }

            int bubbleUpAlternatingLevels(int index, E x) {
                while (index > 2) {
                    int grandParentIndex = getGrandparentIndex(index);
                    E e = elementData(grandParentIndex);
                    if (ordering.compare(e, x) <= 0) {
                        break;
                    }
                    queue[index] = e;
                    index = grandParentIndex;
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

            int findMinChild(int index) {
                return findMin(getLeftChildIndex(index), 2);
            }

            int findMinGrandChild(int index) {
                int leftChildIndex = getLeftChildIndex(index);
                if (leftChildIndex < 0) {
                    return -1;
                }
                return findMin(getLeftChildIndex(leftChildIndex), 4);
            }

            int crossOverUp(int index, E x) {
                if (index == 0) {
                    queue[0] = x;
                    return 0;
                }
                int parentIndex = getParentIndex(index);
                E parentElement = elementData(parentIndex);
                if (parentIndex != 0) {
                    

                    

                    

                    

                    int grandparentIndex = getParentIndex(parentIndex);
                    int uncleIndex = getRightChildIndex(grandparentIndex);
                    if (uncleIndex != parentIndex && getLeftChildIndex(uncleIndex) >= size) {
                        E uncleElement = elementData(uncleIndex);
                        if (ordering.compare(uncleElement, parentElement) < 0) {
                            parentIndex = uncleIndex;
                            parentElement = uncleElement;
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

            int swapWithConceptuallyLastElement(E actualLastElement) {
                int parentIndex = getParentIndex(size);
                if (parentIndex != 0) {
                    int grandparentIndex = getParentIndex(parentIndex);
                    int uncleIndex = getRightChildIndex(grandparentIndex);
                    if (uncleIndex != parentIndex && getLeftChildIndex(uncleIndex) >= size) {
                        E uncleElement = elementData(uncleIndex);
                        if (ordering.compare(uncleElement, actualLastElement) < 0) {
                            queue[uncleIndex] = actualLastElement;
                            queue[size] = uncleElement;
                            return uncleIndex;
                        }
                    }
                }
                return size;
            }

            int crossOver(int index, E x) {
                int minChildIndex = findMinChild(index);
                

                

                if ((minChildIndex > 0) && (ordering.compare(elementData(minChildIndex), x) < 0)) {
                    queue[index] = elementData(minChildIndex);
                    queue[minChildIndex] = x;
                    return minChildIndex;
                }
                return crossOverUp(index, x);
            }

            int fillHoleAt(int index) {
                int minGrandchildIndex;
                while ((minGrandchildIndex = findMinGrandChild(index)) > 0) {
                    queue[index] = elementData(minGrandchildIndex);
                    index = minGrandchildIndex;
                }
                return index;
            }

            private int getLeftChildIndex(int i) {
                return i * 2 + 1;
            }

            private int getRightChildIndex(int i) {
                return i * 2 + 2;
            }

            private int getParentIndex(int i) {
                return (i - 1) / 2;
            }

            private int getGrandparentIndex(int i) {
                return getParentIndex(getParentIndex(i)); 

            }

        }

        private class QueueIterator implements Iterator<E> {
            private int cursor = -1;
            private int nextCursor = -1;
            private int expectedModCount = modCount;
            private Queue<E> forgetMeNot;
            private List<E> skipMe;
            private E lastFromForgetMeNot;
            private boolean canRemove;

            public boolean hasNext() {
                checkModCount();
                nextNotInSkipMe(cursor + 1);
                return (nextCursor < size()) || ((forgetMeNot != null) && !forgetMeNot.isEmpty());
            }

            public E next() {
                checkModCount();
                nextNotInSkipMe(cursor + 1);
                if (nextCursor < size()) {
                    cursor = nextCursor;
                    canRemove = true;
                    return elementData(cursor);
                } else if (forgetMeNot != null) {
                    cursor = size();
                    lastFromForgetMeNot = forgetMeNot.poll();
                    if (lastFromForgetMeNot != null) {
                        canRemove = true;
                        return lastFromForgetMeNot;
                    }
                }
                throw new NoSuchElementException("iterator moved past last element in queue.");
            }

            public void remove() {
                CollectPreconditions.checkRemove(canRemove);
                checkModCount();
                canRemove = false;
                expectedModCount++;
                if (cursor < size()) {
                    MinMaxPriorityQueue.MoveDesc<E> moved = removeAt(cursor);
                    if (moved != null) {
                        if (forgetMeNot == null) {
                            forgetMeNot = new ArrayDeque<E>();
                            skipMe = new ArrayList<E>(3);
                        }
                        if (!foundAndRemovedExactReference(skipMe, moved.toTrickle)) {
                            forgetMeNot.add(moved.toTrickle);
                        }
                        if (!foundAndRemovedExactReference(forgetMeNot, moved.replaced)) {
                            skipMe.add(moved.replaced);
                        }
                    }
                    cursor--;
                    nextCursor--;
                } else { 

                    Preconditions.checkState(removeExact(lastFromForgetMeNot));
                    lastFromForgetMeNot = null;
                }
            }

            private boolean foundAndRemovedExactReference(Iterable<E> elements, E target) {
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

            private void checkModCount() {
                if (modCount != expectedModCount) {
                    throw new ConcurrentModificationException();
                }
            }

            private void nextNotInSkipMe(int c) {
                if (nextCursor < c) {
                    if (skipMe != null) {
                        while (c < size() && foundAndRemovedExactReference(skipMe, elementData(c))) {
                            c++;
                        }
                    }
                    nextCursor = c;
                }
            }

        }

    }

    static interface MonotonicNonNull {
    }

    static interface GwtCompatible {
    }

    static interface Nullable {
    }

    static interface CanIgnoreReturnValue {
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

    static interface VisibleForTesting {
    }

    static final class Verify {
        private Verify() {
        }

    }

    static final class Strings {
        private Strings() {
        }

        public static String lenientFormat(
                String template, Object... args) {
            template = String.valueOf(template); 


            if (args == null) {
                args = new Object[]{"(Object[])null"};
            } else {
                for (int i = 0; i < args.length; i++) {
                    args[i] = lenientToString(args[i]);
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

        private static String lenientToString(Object o) {
            try {
                return String.valueOf(o);
            } catch (Exception e) {
                

                String objectToString =
                        o.getClass().getName() + '@' + Integer.toHexString(System.identityHashCode(o));
                

                Logger.getLogger("com.google.common.base.Strings")
                        .log(Level.WARNING, "Exception during lenientFormat for " + objectToString, e);
                return "<" + objectToString + " threw " + e.getClass().getName() + ">";
            }
        }

    }

    static final class CollectPreconditions {
        static void checkRemove(boolean canRemove) {
            Preconditions.checkState(canRemove, "no calls to next() since the last call to remove()");
        }

    }

    static final class ReverseOrdering<T> extends Ordering<T> implements Serializable {
        final Ordering<? super T> forwardOrder;

        ReverseOrdering(Ordering<? super T> forwardOrder) {
            this.forwardOrder = Preconditions.checkNotNull(forwardOrder);
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

        public static <T> T checkNotNull(T reference) {
            if (reference == null) {
                throw new NullPointerException();
            }
            return reference;
        }

        public static int checkPositionIndex(int index, int size) {
            return checkPositionIndex(index, size, "index");
        }

        public static int checkPositionIndex(int index, int size, String desc) {
            

            if (index < 0 || index > size) {
                throw new IndexOutOfBoundsException(badPositionIndex(index, size, desc));
            }
            return index;
        }

        private static String badPositionIndex(int index, int size, String desc) {
            if (index < 0) {
                return Strings.lenientFormat("%s (%s) must not be negative", desc, index);
            } else if (size < 0) {
                throw new IllegalArgumentException("negative size: " + size);
            } else { 

                return Strings.lenientFormat("%s (%s) must not be greater than size (%s)", desc, index, size);
            }
        }

    }

    static 

    final class NaturalOrdering extends Ordering<Comparable> implements Serializable {
        static final NaturalOrdering INSTANCE = new NaturalOrdering();

        public int compare(Comparable left, Comparable right) {
            Preconditions.checkNotNull(left); 

            Preconditions.checkNotNull(right);
            return left.compareTo(right);
        }

        public <S extends Comparable> Ordering<S> reverse() {
            return (Ordering<S>) ReverseNaturalOrdering.INSTANCE;
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
            MathPreconditions.checkNoOverflow(result == (int) result, "checkedMultiply", a, b);
            return (int) result;
        }

        private IntMath() {
        }

    }

    static final class ComparatorOrdering<T> extends Ordering<T> implements Serializable {
        final Comparator<T> comparator;

        ComparatorOrdering(Comparator<T> comparator) {
            this.comparator = Preconditions.checkNotNull(comparator);
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

    static final class MathPreconditions {
        static void checkNoOverflow(boolean condition, String methodName, int a, int b) {
            if (!condition) {
                throw new ArithmeticException("overflow: " + methodName + "(" + a + ", " + b + ")");
            }
        }

        private MathPreconditions() {
        }

    }

    static 

    final class ReverseNaturalOrdering extends Ordering<Comparable> implements Serializable {
        static final ReverseNaturalOrdering INSTANCE = new ReverseNaturalOrdering();

        public int compare(Comparable left, Comparable right) {
            Preconditions.checkNotNull(left); 

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

        private ReverseNaturalOrdering() {
        }

    }
}

