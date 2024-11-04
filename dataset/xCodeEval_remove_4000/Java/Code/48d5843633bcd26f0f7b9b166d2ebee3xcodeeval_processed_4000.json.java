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
        id21 solver = new id21();
        solver.solve(1, in, out);
        out.close();
    }

    static class id21 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] input = in.id15(n);

            Multiset<Integer> ii = id37.create();
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

            for (var mcs : ii.entrySet()) {
                int v = mcs.getElement();
                int c = mcs.getCount();
                if (leftovers > 0) {
                    

                    int assigned = c;
                    assigned = Math.min(assigned, leftovers);
                    assigned = Math.min(assigned, k);
                    leftovers -= assigned;
                    colors[v] = leftovers;
                    upTo[v] = assigned;
                } else {
                    upTo[v] = 0;
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

    static final class Strings {
        private Strings() {
        }

        public static String id13(
                String template, Object... args) {
            template = String.valueOf(template); 


            if (args == null) {
                args = new Object[]{"(Object[])null"};
            } else {
                for (int i = 0; i < args.length; i++) {
                    args[i] = id8(args[i]);
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

        private static String id8(Object o) {
            if (o == null) {
                return "null";
            }
            try {
                return o.toString();
            } catch (Exception e) {
                

                String id17 =
                        o.getClass().getName() + '@' + Integer.toHexString(System.identityHashCode(o));
                

                Logger.getLogger("com.google.common.base.Strings")
                        .log(Level.WARNING, "Exception during id13 for " + id17, e);
                return "<" + id17 + " threw " + e.getClass().getName() + ">";
            }
        }

    }

    static final class id11 {
        static int id34(int value, String name) {
            if (value < 0) {
                throw new IllegalArgumentException(name + " cannot be negative but was: " + value);
            }
            return value;
        }

        static void checkRemove(boolean canRemove) {
            Preconditions.checkState(canRemove, "no calls to next() since the last call to remove()");
        }

    }

    static abstract class id22 {
    }

    static final class Ints extends id44 {
        public static final int id42 = 1 << (Integer.SIZE - 2);

        private Ints() {
        }

        public static int id33(long value) {
            if (value > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (value < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            return (int) value;
        }

    }

    static abstract class id44 {
    }

    static final class id28 {
        private id28() {
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

        static <E> boolean id19(Multiset<E> self, Collection<? extends E> elements) {
            Preconditions.id35(self);
            Preconditions.id35(elements);
            if (elements instanceof Multiset) {
                return id19(self, cast(elements));
            } else if (elements.isEmpty()) {
                return false;
            } else {
                return Iterators.addAll(self, elements.iterator());
            }
        }

        private static <E> boolean id19(Multiset<E> self, Multiset<? extends E> elements) {
            if (elements.isEmpty()) {
                return false;
            }
            elements.id12(self::add);
            return true;
        }

        static boolean id29(Multiset<?> self, Collection<?> id14) {
            Collection<?> collection =
                    (id14 instanceof Multiset)
                            ? ((Multiset<?>) id14).elementSet()
                            : id14;

            return self.elementSet().removeAll(collection);
        }

        static boolean id43(Multiset<?> self, Collection<?> id7) {
            Preconditions.id35(id7);
            Collection<?> collection =
                    (id7 instanceof Multiset)
                            ? ((Multiset<?>) id7).elementSet()
                            : id7;

            return self.elementSet().retainAll(collection);
        }

        static <E> int id10(Multiset<E> self, E element, int count) {
            id11.id34(count, "count");

            int oldCount = self.count(element);

            int delta = count - oldCount;
            if (delta > 0) {
                self.add(element, delta);
            } else if (delta < 0) {
                self.remove(element, -delta);
            }

            return oldCount;
        }

        static <E> boolean id10(Multiset<E> self, E element, int oldCount, int newCount) {
            id11.id34(oldCount, "oldCount");
            id11.id34(newCount, "newCount");

            if (self.count(element) == oldCount) {
                self.setCount(element, newCount);
                return true;
            } else {
                return false;
            }
        }

        static <E> Spliterator<E> id20(Multiset<E> multiset) {
            Spliterator<Multiset.Entry<E>> id24 = multiset.entrySet().spliterator();
            return id18.flatMap(
                    id24,
                    entry -> Collections.nCopies(entry.getCount(), entry.getElement()).spliterator(),
                    Spliterator.SIZED
                            | (id24.characteristics()
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

        abstract static class ElementSet<E> extends Sets.id40<E> {
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

        abstract static class EntrySet<E> extends Sets.id40<Multiset.Entry<E>> {
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

    static final class Maps {
        private Maps() {
        }

        public static <K, V> HashMap<K, V> id5(int expectedSize) {
            return new HashMap<>(capacity(expectedSize));
        }

        static int capacity(int expectedSize) {
            if (expectedSize < 3) {
                id11.id34(expectedSize, "expectedSize");
                return expectedSize + 1;
            }
            if (expectedSize < Ints.id42) {
                

                

                

                return (int) ((float) expectedSize / 0.75F + 1.0F);
            }
            return Integer.MAX_VALUE; 

        }

        static <V> V safeGet(Map<?, V> map, Object key) {
            Preconditions.id35(map);
            try {
                return map.get(key);
            } catch (ClassCastException | NullPointerException e) {
                return null;
            }
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

        public static void checkArgument(boolean b, String id30, int p1) {
            if (!b) {
                throw new IllegalArgumentException(Strings.id13(id30, p1));
            }
        }

        public static void checkArgument(boolean b, String id30, long p1) {
            if (!b) {
                throw new IllegalArgumentException(Strings.id13(id30, p1));
            }
        }

        public static void checkState(boolean expression, Object errorMessage) {
            if (!expression) {
                throw new IllegalStateException(String.valueOf(errorMessage));
            }
        }

        public static <T extends Object> T id35(T reference) {
            if (reference == null) {
                throw new NullPointerException();
            }
            return reference;
        }

    }

    static final class id37<E> extends id2<E> {
        public static <E> id37<E> create() {
            return new id37<E>();
        }

        private id37() {
            super(new HashMap<E, Count>());
        }

        private id37(int distinctElements) {
            super(Maps.<E, Count>id5(distinctElements));
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

        public int id3(int delta) {
            return value += delta;
        }

        public void set(int newValue) {
            value = newValue;
        }

        public int id31(int newValue) {
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
        private InputReader.id41 filter;

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
            while (id6(c)) {
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
            } while (!id6(c));
            return res * sgn;
        }

        public boolean id6(int c) {
            if (filter != null) {
                return filter.id6(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int[] id15(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface id41 {
            public boolean id6(int ch);

        }

    }

    static final class Objects extends id22 {
        private Objects() {
        }

        public static boolean equal(Object a, Object b) {
            return a == b || (a != null && a.equals(b));
        }

    }

    static abstract class id2<E> extends id0<E> implements Serializable {
        private transient Map<E, Count> id25;
        private transient long size;

        protected id2(Map<E, Count> id25) {
            Preconditions.checkArgument(id25.isEmpty());
            this.id25 = id25;
        }

        public Set<Multiset.Entry<E>> entrySet() {
            return super.entrySet();
        }

        Iterator<E> elementIterator() {
            final Iterator<Map.Entry<E, Count>> id39 = id25.entrySet().iterator();
            return new Iterator<E>() {
                Map.Entry<E, Count> toRemove;


                public boolean hasNext() {
                    return id39.hasNext();
                }


                public E next() {
                    final Map.Entry<E, Count> mapEntry = id39.next();
                    toRemove = mapEntry;
                    return mapEntry.getKey();
                }


                public void remove() {
                    id11.checkRemove(toRemove != null);
                    size -= toRemove.getValue().id31(0);
                    id39.remove();
                    toRemove = null;
                }
            };
        }

        Iterator<Multiset.Entry<E>> entryIterator() {
            final Iterator<Map.Entry<E, Count>> id39 = id25.entrySet().iterator();
            return new Iterator<Multiset.Entry<E>>() {
                Map.Entry<E, Count> toRemove;


                public boolean hasNext() {
                    return id39.hasNext();
                }


                public Multiset.Entry<E> next() {
                    final Map.Entry<E, Count> mapEntry = id39.next();
                    toRemove = mapEntry;
                    return new id28.AbstractEntry<E>() {

                        public E getElement() {
                            return mapEntry.getKey();
                        }


                        public int getCount() {
                            Count count = mapEntry.getValue();
                            if (count == null || count.get() == 0) {
                                Count frequency = id25.get(getElement());
                                if (frequency != null) {
                                    return frequency.get();
                                }
                            }
                            return (count == null) ? 0 : count.get();
                        }
                    };
                }


                public void remove() {
                    id11.checkRemove(toRemove != null);
                    size -= toRemove.getValue().id31(0);
                    id39.remove();
                    toRemove = null;
                }
            };
        }

        public void id12(ObjIntConsumer<? super E> action) {
            Preconditions.id35(action);
            id25.forEach((element, count) -> action.accept(element, count.get()));
        }

        public void clear() {
            for (Count frequency : id25.values()) {
                frequency.set(0);
            }
            id25.clear();
            size = 0L;
        }

        int distinctElements() {
            return id25.size();
        }

        public int size() {
            return Ints.id33(size);
        }

        public Iterator<E> iterator() {
            return new id27();
        }

        public int count(Object element) {
            Count frequency = Maps.safeGet(id25, element);
            return (frequency == null) ? 0 : frequency.get();
        }

        public int add(E element, int occurrences) {
            if (occurrences == 0) {
                return count(element);
            }
            Preconditions.checkArgument(occurrences > 0, "occurrences cannot be negative: %s", occurrences);
            Count frequency = id25.get(element);
            int oldCount;
            if (frequency == null) {
                oldCount = 0;
                id25.put(element, new Count(occurrences));
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
            Count frequency = id25.get(element);
            if (frequency == null) {
                return 0;
            }

            int oldCount = frequency.get();

            int numberRemoved;
            if (oldCount > occurrences) {
                numberRemoved = occurrences;
            } else {
                numberRemoved = oldCount;
                id25.remove(element);
            }

            frequency.add(-numberRemoved);
            size -= numberRemoved;
            return oldCount;
        }

        public int setCount(E element, int count) {
            id11.id34(count, "count");

            Count existingCounter;
            int oldCount;
            if (count == 0) {
                existingCounter = id25.remove(element);
                oldCount = id31(existingCounter, count);
            } else {
                existingCounter = id25.get(element);
                oldCount = id31(existingCounter, count);

                if (existingCounter == null) {
                    id25.put(element, new Count(count));
                }
            }

            size += (count - oldCount);
            return oldCount;
        }

        private static int id31(Count i, int count) {
            if (i == null) {
                return 0;
            }

            return i.id31(count);
        }

        private class id27 implements Iterator<E> {
            final Iterator<Map.Entry<E, Count>> entryIterator;
            Map.Entry<E, Count> currentEntry;
            int id38;
            boolean canRemove;

            id27() {
                this.entryIterator = id25.entrySet().iterator();
            }

            public boolean hasNext() {
                return id38 > 0 || entryIterator.hasNext();
            }

            public E next() {
                if (id38 == 0) {
                    currentEntry = entryIterator.next();
                    id38 = currentEntry.getValue().get();
                }
                id38--;
                canRemove = true;
                return currentEntry.getKey();
            }

            public void remove() {
                id11.checkRemove(canRemove);
                int frequency = currentEntry.getValue().get();
                if (frequency <= 0) {
                    throw new ConcurrentModificationException();
                }
                if (currentEntry.getValue().id3(-1) == 0) {
                    entryIterator.remove();
                }
                size--;
                canRemove = false;
            }

        }

    }

    static final class id18 {
        private id18() {
        }

        static <InElementT, OutElementT> Spliterator<OutElementT> flatMap(
                Spliterator<InElementT> id23,
                Function<? super InElementT, Spliterator<OutElementT>> function,
                int topCharacteristics,
                long topSize) {
            Preconditions.checkArgument(
                    (topCharacteristics & Spliterator.SUBSIZED) == 0,
                    "flatMap does not support SUBSIZED characteristic");
            Preconditions.checkArgument(
                    (topCharacteristics & Spliterator.SORTED) == 0,
                    "flatMap does not support SORTED characteristic");
            Preconditions.id35(id23);
            Preconditions.id35(function);
            return new id18.id1<InElementT, OutElementT>(
                    null, id23, function, topCharacteristics, topSize);
        }

        abstract static class id32<
                InElementT, OutElementT, OutSpliteratorT extends Spliterator<OutElementT>> implements Spliterator<OutElementT> {
            OutSpliteratorT prefix;
            final Spliterator<InElementT> from;
            final Function<? super InElementT, OutSpliteratorT> function;
            final id18.id32.Factory<InElementT, OutSpliteratorT> factory;
            int characteristics;
            long estimatedSize;

            id32(
                    OutSpliteratorT prefix,
                    Spliterator<InElementT> from,
                    Function<? super InElementT, OutSpliteratorT> function,
                    id18.id32.Factory<InElementT, OutSpliteratorT> factory,
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

            public final void id4(Consumer<? super OutElementT> action) {
                if (prefix != null) {
                    prefix.id4(action);
                    prefix = null;
                }
                from.id4(
                        fromElement -> {
                            Spliterator<OutElementT> elements = function.apply(fromElement);
                            if (elements != null) {
                                elements.id4(action);
                            }
                        });
                estimatedSize = 0;
            }

            public final OutSpliteratorT trySplit() {
                Spliterator<InElementT> fromSplit = from.trySplit();
                if (fromSplit != null) {
                    int splitCharacteristics = characteristics & ~Spliterator.SIZED;
                    long id26 = estimateSize();
                    if (id26 < Long.MAX_VALUE) {
                        id26 /= 2;
                        this.estimatedSize -= id26;
                        this.characteristics = splitCharacteristics;
                    }
                    OutSpliteratorT result =
                            factory.id36(
                                    this.prefix, fromSplit, function, splitCharacteristics, id26);
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
                OutSpliteratorT id36(
                        OutSpliteratorT prefix,
                        Spliterator<InElementT> fromSplit,
                        Function<? super InElementT, OutSpliteratorT> function,
                        int splitCharacteristics,
                        long id26);

            }

        }

        static final class id1<InElementT, OutElementT> extends id18.id32<InElementT, OutElementT, Spliterator<OutElementT>> {
            id1(
                    Spliterator<OutElementT> prefix,
                    Spliterator<InElementT> from,
                    Function<? super InElementT, Spliterator<OutElementT>> function,
                    int characteristics,
                    long estimatedSize) {
                super(
                        prefix, from, function, id18.id1::new, characteristics, estimatedSize);
            }

        }

    }

    static final class Iterators {
        private Iterators() {
        }

        public static boolean removeAll(Iterator<?> removeFrom, Collection<?> id14) {
            Preconditions.id35(id14);
            boolean result = false;
            while (removeFrom.hasNext()) {
                if (id14.contains(removeFrom.next())) {
                    removeFrom.remove();
                    result = true;
                }
            }
            return result;
        }

        public static <T> boolean addAll(Collection<T> addTo, Iterator<? extends T> iterator) {
            Preconditions.id35(addTo);
            Preconditions.id35(iterator);
            boolean wasModified = false;
            while (iterator.hasNext()) {
                wasModified |= addTo.add(iterator.next());
            }
            return wasModified;
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

        default void id12(ObjIntConsumer<? super E> action) {
            Preconditions.id35(action);
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
            Preconditions.id35(action);
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
            return id28.id20(this);
        }

        interface Entry<E> {
            E getElement();

            int getCount();

            boolean equals(Object o);

            int hashCode();

            String toString();

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

    static abstract class id0<E> extends AbstractCollection<E> implements Multiset<E> {
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
            return id28.id10(this, element, count);
        }

        public boolean setCount(E element, int oldCount, int newCount) {
            return id28.id10(this, element, oldCount, newCount);
        }

        public final boolean addAll(Collection<? extends E> id16) {
            return id28.id19(this, id16);
        }

        public final boolean removeAll(Collection<?> id14) {
            return id28.id29(this, id14);
        }

        public final boolean retainAll(Collection<?> id7) {
            return id28.id43(this, id7);
        }

        public abstract void clear();

        public Set<E> elementSet() {
            Set<E> result = elementSet;
            if (result == null) {
                elementSet = result = id9();
            }
            return result;
        }

        Set<E> id9() {
            return new ElementSet();
        }

        abstract Iterator<E> elementIterator();

        public Set<Multiset.Entry<E>> entrySet() {
            Set<Multiset.Entry<E>> result = entrySet;
            if (result == null) {
                entrySet = result = id45();
            }
            return result;
        }

        Set<Multiset.Entry<E>> id45() {
            return new EntrySet();
        }

        abstract Iterator<Multiset.Entry<E>> entryIterator();

        abstract int distinctElements();

        public final boolean equals(Object object) {
            return id28.equalsImpl(this, object);
        }

        public final int hashCode() {
            return entrySet().hashCode();
        }

        public final String toString() {
            return entrySet().toString();
        }

        class ElementSet extends id28.ElementSet<E> {
            Multiset<E> multiset() {
                return id0.this;
            }

            public Iterator<E> iterator() {
                return elementIterator();
            }

        }

        class EntrySet extends id28.EntrySet<E> {
            Multiset<E> multiset() {
                return id0.this;
            }

            public Iterator<Multiset.Entry<E>> iterator() {
                return entryIterator();
            }

            public int size() {
                return distinctElements();
            }

        }

    }

    static final class Sets {
        private Sets() {
        }

        static boolean id29(Set<?> set, Iterator<?> iterator) {
            boolean changed = false;
            while (iterator.hasNext()) {
                changed |= set.remove(iterator.next());
            }
            return changed;
        }

        static boolean id29(Set<?> set, Collection<?> collection) {
            Preconditions.id35(collection); 

            if (collection instanceof Multiset) {
                collection = ((Multiset<?>) collection).elementSet();
            }
            
            if (collection instanceof Set && collection.size() > set.size()) {
                return Iterators.removeAll(set.iterator(), collection);
            } else {
                return id29(set, collection.iterator());
            }
        }

        abstract static class id40<E> extends AbstractSet<E> {
            public boolean removeAll(Collection<?> c) {
                return id29(this, c);
            }

            public boolean retainAll(Collection<?> c) {
                return super.retainAll(Preconditions.id35(c)); 

            }

        }

    }
}

