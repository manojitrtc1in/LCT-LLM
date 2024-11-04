import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.function.ObjIntConsumer;
import java.util.function.Function;
import java.util.logging.Level;
import java.util.AbstractCollection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.util.logging.Logger;
import java.io.Serializable;
import java.util.function.Consumer;
import java.util.List;
import java.io.Writer;
import java.util.Map.Entry;
import java.util.Spliterator;
import java.util.Collections;
import java.util.ConcurrentModificationException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        B2WonderfulColoring2 solver = new B2WonderfulColoring2();
        solver.solve(1, in, out);
        out.close();
    }

    static class B2WonderfulColoring2 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] input = in.nextIntArray(n);

            Multiset<Integer> ii = HashMultiset.create();
            for (int i : input) {
                ii.add(i);
            }

            int leftovers = 0;
            int filled = 0;
            for (var mcs : ii.entrySet()) {
                if (mcs.getCount() >= k) {
                    filled++;
                } else {
                    leftovers += mcs.getCount();
                }
            }
            int[] colors = new int[n + 1];
            int[] upTo = new int[n + 1];
            Arrays.fill(upTo, k);
            Arrays.fill(colors, -1);
            leftovers = ((leftovers / k) * k) + (filled * k);

            for (int i = 0; i < input.length; i++) {
                if (colors[input[i]] == -1) {
                    if (leftovers > 0) {
                        int ci = ii.count(input[i]);
                        int x = input[i];
                        int toFill = Math.min(leftovers, ci);
                        toFill = Math.min(toFill, k);
                        leftovers -= toFill;
                        colors[input[i]] = (leftovers) % k;
                        upTo[input[i]] = toFill;
                    } else {
                        upTo[input[i]] = 0;
                    }
                }
            }

            for (int i = 0; i < input.length; i++) {
                if (upTo[input[i]] > 0 && colors[input[i]] != -1) {
                    out.print(1 + (colors[input[i]] % k) + " ");
                    colors[input[i]]++;
                    upTo[input[i]]--;
                } else {
                    out.print(0 + " ");
                }
            }

            out.println();
        }

    }

    static final class Iterators {
        private Iterators() {
        }

        public static boolean removeAll(Iterator<?> removeFrom, Collection<?> elementsToRemove) {
            Preconditions.checkNotNull(elementsToRemove);
            boolean result = false;
            while (removeFrom.hasNext()) {
                if (elementsToRemove.contains(removeFrom.next())) {
                    removeFrom.remove();
                    result = true;
                }
            }
            return result;
        }

        public static <T> boolean addAll(Collection<T> addTo, Iterator<? extends T> iterator) {
            Preconditions.checkNotNull(addTo);
            Preconditions.checkNotNull(iterator);
            boolean wasModified = false;
            while (iterator.hasNext()) {
                wasModified |= addTo.add(iterator.next());
            }
            return wasModified;
        }

    }

    static final class Ints extends IntsMethodsForWeb {
        public static final int MAX_POWER_OF_TWO = 1 << (Integer.SIZE - 2);

        private Ints() {
        }

        public static int saturatedCast(long value) {
            if (value > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (value < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            return (int) value;
        }

    }

    static final class CollectSpliterators {
        private CollectSpliterators() {
        }

        static <InElementT, OutElementT> Spliterator<OutElementT> flatMap(
                Spliterator<InElementT> fromSpliterator,
                Function<? super InElementT, Spliterator<OutElementT>> function,
                int topCharacteristics,
                long topSize) {
            Preconditions.checkArgument(
                    (topCharacteristics & Spliterator.SUBSIZED) == 0,
                    "flatMap does not support SUBSIZED characteristic");
            Preconditions.checkArgument(
                    (topCharacteristics & Spliterator.SORTED) == 0,
                    "flatMap does not support SORTED characteristic");
            Preconditions.checkNotNull(fromSpliterator);
            Preconditions.checkNotNull(function);
            return new CollectSpliterators.FlatMapSpliteratorOfObject<InElementT, OutElementT>(
                    null, fromSpliterator, function, topCharacteristics, topSize);
        }

        abstract static class FlatMapSpliterator<
                InElementT, OutElementT, OutSpliteratorT extends Spliterator<OutElementT>> implements Spliterator<OutElementT> {
            OutSpliteratorT prefix;
            final Spliterator<InElementT> from;
            final Function<? super InElementT, OutSpliteratorT> function;
            final CollectSpliterators.FlatMapSpliterator.Factory<InElementT, OutSpliteratorT> factory;
            int characteristics;
            long estimatedSize;

            FlatMapSpliterator(
                    OutSpliteratorT prefix,
                    Spliterator<InElementT> from,
                    Function<? super InElementT, OutSpliteratorT> function,
                    CollectSpliterators.FlatMapSpliterator.Factory<InElementT, OutSpliteratorT> factory,
                    int characteristics,
                    long estimatedSize) {
                this.prefix = prefix;
                this.from = from;
                this.function = function;
                this.factory = factory;
                this.characteristics = characteristics;
                this.estimatedSize = estimatedSize;
            }

            public final boolean tryAdvance(Consumer<? super OutElementT> action) {
                while (true) {
                    if (prefix != null && prefix.tryAdvance(action)) {
                        if (estimatedSize != Long.MAX_VALUE) {
                            estimatedSize--;
                        }
                        return true;
                    } else {
                        prefix = null;
                    }
                    if (!from.tryAdvance(fromElement -> prefix = function.apply(fromElement))) {
                        return false;
                    }
                }
            }

            public final void forEachRemaining(Consumer<? super OutElementT> action) {
                if (prefix != null) {
                    prefix.forEachRemaining(action);
                    prefix = null;
                }
                from.forEachRemaining(
                        fromElement -> {
                            Spliterator<OutElementT> elements = function.apply(fromElement);
                            if (elements != null) {
                                elements.forEachRemaining(action);
                            }
                        });
                estimatedSize = 0;
            }

            public final OutSpliteratorT trySplit() {
                Spliterator<InElementT> fromSplit = from.trySplit();
                if (fromSplit != null) {
                    int splitCharacteristics = characteristics & ~Spliterator.SIZED;
                    long estSplitSize = estimateSize();
                    if (estSplitSize < Long.MAX_VALUE) {
                        estSplitSize /= 2;
                        this.estimatedSize -= estSplitSize;
                        this.characteristics = splitCharacteristics;
                    }
                    OutSpliteratorT result =
                            factory.newFlatMapSpliterator(
                                    this.prefix, fromSplit, function, splitCharacteristics, estSplitSize);
                    this.prefix = null;
                    return result;
                } else if (prefix != null) {
                    OutSpliteratorT result = prefix;
                    this.prefix = null;
                    return result;
                } else {
                    return null;
                }
            }

            public final long estimateSize() {
                if (prefix != null) {
                    estimatedSize = Math.max(estimatedSize, prefix.estimateSize());
                }
                return Math.max(estimatedSize, 0);
            }

            public final int characteristics() {
                return characteristics;
            }

            interface Factory<InElementT, OutSpliteratorT extends Spliterator<?>> {
                OutSpliteratorT newFlatMapSpliterator(
                        OutSpliteratorT prefix,
                        Spliterator<InElementT> fromSplit,
                        Function<? super InElementT, OutSpliteratorT> function,
                        int splitCharacteristics,
                        long estSplitSize);

            }

        }

        static final class FlatMapSpliteratorOfObject<InElementT, OutElementT> extends CollectSpliterators.FlatMapSpliterator<InElementT, OutElementT, Spliterator<OutElementT>> {
            FlatMapSpliteratorOfObject(
                    Spliterator<OutElementT> prefix,
                    Spliterator<InElementT> from,
                    Function<? super InElementT, Spliterator<OutElementT>> function,
                    int characteristics,
                    long estimatedSize) {
                super(
                        prefix, from, function, CollectSpliterators.FlatMapSpliteratorOfObject::new, characteristics, estimatedSize);
            }

        }

    }

    static final class Objects extends ExtraObjectsMethodsForWeb {
        private Objects() {
        }

        public static boolean equal(Object a, Object b) {
            return a == b || (a != null && a.equals(b));
        }

    }

    static abstract class IntsMethodsForWeb {
    }

    static final class HashMultiset<E> extends AbstractMapBasedMultiset<E> {
        public static <E> HashMultiset<E> create() {
            return new HashMultiset<E>();
        }

        private HashMultiset() {
            super(new HashMap<E, Count>());
        }

        private HashMultiset(int distinctElements) {
            super(Maps.<E, Count>newHashMapWithExpectedSize(distinctElements));
        }

    }

    static final class Count implements Serializable {
        private int value;

        Count(int value) {
            this.value = value;
        }

        public int get() {
            return value;
        }

        public void add(int delta) {
            value += delta;
        }

        public int addAndGet(int delta) {
            return value += delta;
        }

        public void set(int newValue) {
            value = newValue;
        }

        public int getAndSet(int newValue) {
            int result = value;
            value = newValue;
            return result;
        }

        public int hashCode() {
            return value;
        }

        public boolean equals(Object obj) {
            return obj instanceof Count && ((Count) obj).value == value;
        }

        public String toString() {
            return Integer.toString(value);
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

        public int[] nextIntArray(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static abstract class AbstractMapBasedMultiset<E> extends AbstractMultiset<E> implements Serializable {
        private transient Map<E, Count> backingMap;
        private transient long size;

        protected AbstractMapBasedMultiset(Map<E, Count> backingMap) {
            Preconditions.checkArgument(backingMap.isEmpty());
            this.backingMap = backingMap;
        }

        public Set<Multiset.Entry<E>> entrySet() {
            return super.entrySet();
        }

        Iterator<E> elementIterator() {
            final Iterator<Map.Entry<E, Count>> backingEntries = backingMap.entrySet().iterator();
            return new Iterator<E>() {
                Map.Entry<E, Count> toRemove;


                public boolean hasNext() {
                    return backingEntries.hasNext();
                }


                public E next() {
                    final Map.Entry<E, Count> mapEntry = backingEntries.next();
                    toRemove = mapEntry;
                    return mapEntry.getKey();
                }


                public void remove() {
                    CollectPreconditions.checkRemove(toRemove != null);
                    size -= toRemove.getValue().getAndSet(0);
                    backingEntries.remove();
                    toRemove = null;
                }
            };
        }

        Iterator<Multiset.Entry<E>> entryIterator() {
            final Iterator<Map.Entry<E, Count>> backingEntries = backingMap.entrySet().iterator();
            return new Iterator<Multiset.Entry<E>>() {
                Map.Entry<E, Count> toRemove;


                public boolean hasNext() {
                    return backingEntries.hasNext();
                }


                public Multiset.Entry<E> next() {
                    final Map.Entry<E, Count> mapEntry = backingEntries.next();
                    toRemove = mapEntry;
                    return new Multisets.AbstractEntry<E>() {

                        public E getElement() {
                            return mapEntry.getKey();
                        }


                        public int getCount() {
                            Count count = mapEntry.getValue();
                            if (count == null || count.get() == 0) {
                                Count frequency = backingMap.get(getElement());
                                if (frequency != null) {
                                    return frequency.get();
                                }
                            }
                            return (count == null) ? 0 : count.get();
                        }
                    };
                }


                public void remove() {
                    CollectPreconditions.checkRemove(toRemove != null);
                    size -= toRemove.getValue().getAndSet(0);
                    backingEntries.remove();
                    toRemove = null;
                }
            };
        }

        public void forEachEntry(ObjIntConsumer<? super E> action) {
            Preconditions.checkNotNull(action);
            backingMap.forEach((element, count) -> action.accept(element, count.get()));
        }

        public void clear() {
            for (Count frequency : backingMap.values()) {
                frequency.set(0);
            }
            backingMap.clear();
            size = 0L;
        }

        int distinctElements() {
            return backingMap.size();
        }

        public int size() {
            return Ints.saturatedCast(size);
        }

        public Iterator<E> iterator() {
            return new MapBasedMultisetIterator();
        }

        public int count(Object element) {
            Count frequency = Maps.safeGet(backingMap, element);
            return (frequency == null) ? 0 : frequency.get();
        }

        public int add(E element, int occurrences) {
            if (occurrences == 0) {
                return count(element);
            }
            Preconditions.checkArgument(occurrences > 0, "occurrences cannot be negative: %s", occurrences);
            Count frequency = backingMap.get(element);
            int oldCount;
            if (frequency == null) {
                oldCount = 0;
                backingMap.put(element, new Count(occurrences));
            } else {
                oldCount = frequency.get();
                long newCount = (long) oldCount + (long) occurrences;
                Preconditions.checkArgument(newCount <= Integer.MAX_VALUE, "too many occurrences: %s", newCount);
                frequency.add(occurrences);
            }
            size += occurrences;
            return oldCount;
        }

        public int remove(Object element, int occurrences) {
            if (occurrences == 0) {
                return count(element);
            }
            Preconditions.checkArgument(occurrences > 0, "occurrences cannot be negative: %s", occurrences);
            Count frequency = backingMap.get(element);
            if (frequency == null) {
                return 0;
            }

            int oldCount = frequency.get();

            int numberRemoved;
            if (oldCount > occurrences) {
                numberRemoved = occurrences;
            } else {
                numberRemoved = oldCount;
                backingMap.remove(element);
            }

            frequency.add(-numberRemoved);
            size -= numberRemoved;
            return oldCount;
        }

        public int setCount(E element, int count) {
            CollectPreconditions.checkNonnegative(count, "count");

            Count existingCounter;
            int oldCount;
            if (count == 0) {
                existingCounter = backingMap.remove(element);
                oldCount = getAndSet(existingCounter, count);
            } else {
                existingCounter = backingMap.get(element);
                oldCount = getAndSet(existingCounter, count);

                if (existingCounter == null) {
                    backingMap.put(element, new Count(count));
                }
            }

            size += (count - oldCount);
            return oldCount;
        }

        private static int getAndSet(Count i, int count) {
            if (i == null) {
                return 0;
            }

            return i.getAndSet(count);
        }

        private class MapBasedMultisetIterator implements Iterator<E> {
            final Iterator<Map.Entry<E, Count>> entryIterator;
            Map.Entry<E, Count> currentEntry;
            int occurrencesLeft;
            boolean canRemove;

            MapBasedMultisetIterator() {
                this.entryIterator = backingMap.entrySet().iterator();
            }

            public boolean hasNext() {
                return occurrencesLeft > 0 || entryIterator.hasNext();
            }

            public E next() {
                if (occurrencesLeft == 0) {
                    currentEntry = entryIterator.next();
                    occurrencesLeft = currentEntry.getValue().get();
                }
                occurrencesLeft--;
                canRemove = true;
                return currentEntry.getKey();
            }

            public void remove() {
                CollectPreconditions.checkRemove(canRemove);
                int frequency = currentEntry.getValue().get();
                if (frequency <= 0) {
                    throw new ConcurrentModificationException();
                }
                if (currentEntry.getValue().addAndGet(-1) == 0) {
                    entryIterator.remove();
                }
                size--;
                canRemove = false;
            }

        }

    }

    static final class Sets {
        private Sets() {
        }

        static boolean removeAllImpl(Set<?> set, Iterator<?> iterator) {
            boolean changed = false;
            while (iterator.hasNext()) {
                changed |= set.remove(iterator.next());
            }
            return changed;
        }

        static boolean removeAllImpl(Set<?> set, Collection<?> collection) {
            Preconditions.checkNotNull(collection); 

            if (collection instanceof Multiset) {
                collection = ((Multiset<?>) collection).elementSet();
            }
            
            if (collection instanceof Set && collection.size() > set.size()) {
                return Iterators.removeAll(set.iterator(), collection);
            } else {
                return removeAllImpl(set, collection.iterator());
            }
        }

        abstract static class ImprovedAbstractSet<E> extends AbstractSet<E> {
            public boolean removeAll(Collection<?> c) {
                return removeAllImpl(this, c);
            }

            public boolean retainAll(Collection<?> c) {
                return super.retainAll(Preconditions.checkNotNull(c)); 

            }

        }

    }

    static final class Maps {
        private Maps() {
        }

        public static <K, V> HashMap<K, V> newHashMapWithExpectedSize(int expectedSize) {
            return new HashMap<>(capacity(expectedSize));
        }

        static int capacity(int expectedSize) {
            if (expectedSize < 3) {
                CollectPreconditions.checkNonnegative(expectedSize, "expectedSize");
                return expectedSize + 1;
            }
            if (expectedSize < Ints.MAX_POWER_OF_TWO) {
                

                

                

                return (int) ((float) expectedSize / 0.75F + 1.0F);
            }
            return Integer.MAX_VALUE; 

        }

        static <V> V safeGet(Map<?, V> map, Object key) {
            Preconditions.checkNotNull(map);
            try {
                return map.get(key);
            } catch (ClassCastException | NullPointerException e) {
                return null;
            }
        }

    }

    static final class CollectPreconditions {
        static int checkNonnegative(int value, String name) {
            if (value < 0) {
                throw new IllegalArgumentException(name + " cannot be negative but was: " + value);
            }
            return value;
        }

        static void checkRemove(boolean canRemove) {
            Preconditions.checkState(canRemove, "no calls to next() since the last call to remove()");
        }

    }

    static final class Preconditions {
        private Preconditions() {
        }

        public static void checkArgument(boolean expression) {
            if (!expression) {
                throw new IllegalArgumentException();
            }
        }

        public static void checkArgument(boolean expression, Object errorMessage) {
            if (!expression) {
                throw new IllegalArgumentException(String.valueOf(errorMessage));
            }
        }

        public static void checkArgument(boolean b, String errorMessageTemplate, int p1) {
            if (!b) {
                throw new IllegalArgumentException(Strings.lenientFormat(errorMessageTemplate, p1));
            }
        }

        public static void checkArgument(boolean b, String errorMessageTemplate, long p1) {
            if (!b) {
                throw new IllegalArgumentException(Strings.lenientFormat(errorMessageTemplate, p1));
            }
        }

        public static void checkState(boolean expression, Object errorMessage) {
            if (!expression) {
                throw new IllegalStateException(String.valueOf(errorMessage));
            }
        }

        public static <T extends Object> T checkNotNull(T reference) {
            if (reference == null) {
                throw new NullPointerException();
            }
            return reference;
        }

    }

    static final class Multisets {
        private Multisets() {
        }

        static boolean equalsImpl(Multiset<?> multiset, Object object) {
            if (object == multiset) {
                return true;
            }
            if (object instanceof Multiset) {
                Multiset<?> that = (Multiset<?>) object;
                

                if (multiset.size() != that.size() || multiset.entrySet().size() != that.entrySet().size()) {
                    return false;
                }
                for (Multiset.Entry<?> entry : that.entrySet()) {
                    if (multiset.count(entry.getElement()) != entry.getCount()) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        static <E> boolean addAllImpl(Multiset<E> self, Collection<? extends E> elements) {
            Preconditions.checkNotNull(self);
            Preconditions.checkNotNull(elements);
            if (elements instanceof Multiset) {
                return addAllImpl(self, cast(elements));
            } else if (elements.isEmpty()) {
                return false;
            } else {
                return Iterators.addAll(self, elements.iterator());
            }
        }

        private static <E> boolean addAllImpl(Multiset<E> self, Multiset<? extends E> elements) {
            if (elements.isEmpty()) {
                return false;
            }
            elements.forEachEntry(self::add);
            return true;
        }

        static boolean removeAllImpl(Multiset<?> self, Collection<?> elementsToRemove) {
            Collection<?> collection =
                    (elementsToRemove instanceof Multiset)
                            ? ((Multiset<?>) elementsToRemove).elementSet()
                            : elementsToRemove;

            return self.elementSet().removeAll(collection);
        }

        static boolean retainAllImpl(Multiset<?> self, Collection<?> elementsToRetain) {
            Preconditions.checkNotNull(elementsToRetain);
            Collection<?> collection =
                    (elementsToRetain instanceof Multiset)
                            ? ((Multiset<?>) elementsToRetain).elementSet()
                            : elementsToRetain;

            return self.elementSet().retainAll(collection);
        }

        static <E> int setCountImpl(Multiset<E> self, E element, int count) {
            CollectPreconditions.checkNonnegative(count, "count");

            int oldCount = self.count(element);

            int delta = count - oldCount;
            if (delta > 0) {
                self.add(element, delta);
            } else if (delta < 0) {
                self.remove(element, -delta);
            }

            return oldCount;
        }

        static <E> boolean setCountImpl(Multiset<E> self, E element, int oldCount, int newCount) {
            CollectPreconditions.checkNonnegative(oldCount, "oldCount");
            CollectPreconditions.checkNonnegative(newCount, "newCount");

            if (self.count(element) == oldCount) {
                self.setCount(element, newCount);
                return true;
            } else {
                return false;
            }
        }

        static <E> Spliterator<E> spliteratorImpl(Multiset<E> multiset) {
            Spliterator<Multiset.Entry<E>> entrySpliterator = multiset.entrySet().spliterator();
            return CollectSpliterators.flatMap(
                    entrySpliterator,
                    entry -> Collections.nCopies(entry.getCount(), entry.getElement()).spliterator(),
                    Spliterator.SIZED
                            | (entrySpliterator.characteristics()
                            & (Spliterator.ORDERED | Spliterator.NONNULL | Spliterator.IMMUTABLE)),
                    multiset.size());
        }

        static <T> Multiset<T> cast(Iterable<T> iterable) {
            return (Multiset<T>) iterable;
        }

        abstract static class AbstractEntry<E> implements Multiset.Entry<E> {
            public boolean equals(Object object) {
                if (object instanceof Multiset.Entry) {
                    Multiset.Entry<?> that = (Multiset.Entry<?>) object;
                    return this.getCount() == that.getCount()
                            && Objects.equal(this.getElement(), that.getElement());
                }
                return false;
            }

            public int hashCode() {
                E e = getElement();
                return ((e == null) ? 0 : e.hashCode()) ^ getCount();
            }

            public String toString() {
                String text = String.valueOf(getElement());
                int n = getCount();
                return (n == 1) ? text : (text + " x " + n);
            }

        }

        abstract static class ElementSet<E> extends Sets.ImprovedAbstractSet<E> {
            abstract Multiset<E> multiset();

            public void clear() {
                multiset().clear();
            }

            public boolean contains(Object o) {
                return multiset().contains(o);
            }

            public boolean containsAll(Collection<?> c) {
                return multiset().containsAll(c);
            }

            public boolean isEmpty() {
                return multiset().isEmpty();
            }

            public abstract Iterator<E> iterator();

            public boolean remove(Object o) {
                return multiset().remove(o, Integer.MAX_VALUE) > 0;
            }

            public int size() {
                return multiset().entrySet().size();
            }

        }

        abstract static class EntrySet<E> extends Sets.ImprovedAbstractSet<Multiset.Entry<E>> {
            abstract Multiset<E> multiset();

            public boolean contains(Object o) {
                if (o instanceof Multiset.Entry) {
                    

                    Multiset.Entry<?> entry = (Multiset.Entry<?>) o;
                    if (entry.getCount() <= 0) {
                        return false;
                    }
                    int count = multiset().count(entry.getElement());
                    return count == entry.getCount();
                }
                return false;
            }

            public boolean remove(Object object) {
                if (object instanceof Multiset.Entry) {
                    Multiset.Entry<?> entry = (Multiset.Entry<?>) object;
                    Object element = entry.getElement();
                    int entryCount = entry.getCount();
                    if (entryCount != 0) {
                        


                        Multiset<Object> multiset = (Multiset<Object>) multiset();
                        return multiset.setCount(element, entryCount, 0);
                    }
                }
                return false;
            }

            public void clear() {
                multiset().clear();
            }

        }

    }

    static interface Multiset<E> extends Collection<E> {
        int size();

        int count(Object element);

        int add(E element, int occurrences);

        boolean add(E element);

        int remove(Object element, int occurrences);

        boolean remove(Object element);

        int setCount(E element, int count);

        boolean setCount(E element, int oldCount, int newCount);

        Set<E> elementSet();

        Set<Multiset.Entry<E>> entrySet();

        default void forEachEntry(ObjIntConsumer<? super E> action) {
            Preconditions.checkNotNull(action);
            entrySet().forEach(entry -> action.accept(entry.getElement(), entry.getCount()));
        }

        boolean equals(Object object);

        int hashCode();

        String toString();

        Iterator<E> iterator();

        boolean contains(Object element);

        boolean containsAll(Collection<?> elements);

        boolean removeAll(Collection<?> c);

        boolean retainAll(Collection<?> c);

        default void forEach(Consumer<? super E> action) {
            Preconditions.checkNotNull(action);
            entrySet()
                    .forEach(
                            entry -> {
                                E elem = entry.getElement();
                                int count = entry.getCount();
                                for (int i = 0; i < count; i++) {
                                    action.accept(elem);
                                }
                            });
        }

        default Spliterator<E> spliterator() {
            return Multisets.spliteratorImpl(this);
        }

        interface Entry<E> {
            E getElement();

            int getCount();

            boolean equals(Object o);

            int hashCode();

            String toString();

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
            if (o == null) {
                return "null";
            }
            try {
                return o.toString();
            } catch (Exception e) {
                

                String objectToString =
                        o.getClass().getName() + '@' + Integer.toHexString(System.identityHashCode(o));
                

                Logger.getLogger("com.google.common.base.Strings")
                        .log(Level.WARNING, "Exception during lenientFormat for " + objectToString, e);
                return "<" + objectToString + " threw " + e.getClass().getName() + ">";
            }
        }

    }

    static abstract class ExtraObjectsMethodsForWeb {
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static abstract class AbstractMultiset<E> extends AbstractCollection<E> implements Multiset<E> {
        private transient Set<E> elementSet;
        private transient Set<Multiset.Entry<E>> entrySet;

        public boolean isEmpty() {
            return entrySet().isEmpty();
        }

        public boolean contains(Object element) {
            return count(element) > 0;
        }

        public final boolean add(E element) {
            add(element, 1);
            return true;
        }

        public int add(E element, int occurrences) {
            throw new UnsupportedOperationException();
        }

        public final boolean remove(Object element) {
            return remove(element, 1) > 0;
        }

        public int remove(Object element, int occurrences) {
            throw new UnsupportedOperationException();
        }

        public int setCount(E element, int count) {
            return Multisets.setCountImpl(this, element, count);
        }

        public boolean setCount(E element, int oldCount, int newCount) {
            return Multisets.setCountImpl(this, element, oldCount, newCount);
        }

        public final boolean addAll(Collection<? extends E> elementsToAdd) {
            return Multisets.addAllImpl(this, elementsToAdd);
        }

        public final boolean removeAll(Collection<?> elementsToRemove) {
            return Multisets.removeAllImpl(this, elementsToRemove);
        }

        public final boolean retainAll(Collection<?> elementsToRetain) {
            return Multisets.retainAllImpl(this, elementsToRetain);
        }

        public abstract void clear();

        public Set<E> elementSet() {
            Set<E> result = elementSet;
            if (result == null) {
                elementSet = result = createElementSet();
            }
            return result;
        }

        Set<E> createElementSet() {
            return new ElementSet();
        }

        abstract Iterator<E> elementIterator();

        public Set<Multiset.Entry<E>> entrySet() {
            Set<Multiset.Entry<E>> result = entrySet;
            if (result == null) {
                entrySet = result = createEntrySet();
            }
            return result;
        }

        Set<Multiset.Entry<E>> createEntrySet() {
            return new EntrySet();
        }

        abstract Iterator<Multiset.Entry<E>> entryIterator();

        abstract int distinctElements();

        public final boolean equals(Object object) {
            return Multisets.equalsImpl(this, object);
        }

        public final int hashCode() {
            return entrySet().hashCode();
        }

        public final String toString() {
            return entrySet().toString();
        }

        class ElementSet extends Multisets.ElementSet<E> {
            Multiset<E> multiset() {
                return AbstractMultiset.this;
            }

            public Iterator<E> iterator() {
                return elementIterator();
            }

        }

        class EntrySet extends Multisets.EntrySet<E> {
            Multiset<E> multiset() {
                return AbstractMultiset.this;
            }

            public Iterator<Multiset.Entry<E>> iterator() {
                return entryIterator();
            }

            public int size() {
                return distinctElements();
            }

        }

    }
}

