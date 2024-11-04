import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.function.ObjIntConsumer;
import java.util.function.Function;
import java.util.logging.Level;
import java.util.HashSet;
import java.util.AbstractCollection;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.LinkedHashSet;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            var tc = in.nextInt();
            for (int i = 0; i < tc; i++) {
                solution(i, in, out);
            }
        }

        void solution(int testNumber, InputReader in, OutputWriter out) {
            String s = in.readLine();
            Multiset<Character> m = id39.create();
            for (char c : s.toCharArray()) {
                m.add(c);
            }

            var lhs = new LinkedHashSet<Character>();

            for (char c : new StringBuilder(s).reverse().toString().toCharArray()) {
                lhs.add(c);
            }

            Multiset<Character> finalC = id39.create();
            int divs = lhs.size();
            for (char c : lhs) {
                finalC.add(c, m.count(c) / divs);
                divs--;
            }
            int i;
            for (i = 0; !finalC.isEmpty(); i++) {
                char c = s.charAt(i);
                finalC.remove(c);
            }

            var revOrder = lhs.toArray(new Character[lhs.size()]);
            var ordered = ArrayUtils.toPrimitive(revOrder);
            ArrayUtils.reverse(ordered);
            

            var k = new StringBuilder(s.substring(0, i));
            var c = new StringBuilder(s.substring(0, i));
            for (char r : ordered) {
                var kv = new StringBuilder();
                for (char cr : c.toString().toCharArray()) {
                    if (cr != r) {
                        kv.append(cr);
                    }
                }

                c = kv;
                k.append(c);
            }

            if (k.toString().equals(s)) {
                out.println(s.substring(0, i) + " " + String.valueOf(ordered));
            } else {
                out.println(-1);
            }
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

        public int id5(int delta) {
            return value += delta;
        }

        public void set(int newValue) {
            value = newValue;
        }

        public int id33(int newValue) {
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

    static final class id30 {
        private id30() {
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

        static <E> boolean id21(Multiset<E> self, Collection<? extends E> elements) {
            Preconditions.id37(self);
            Preconditions.id37(elements);
            if (elements instanceof Multiset) {
                return id21(self, cast(elements));
            } else if (elements.isEmpty()) {
                return false;
            } else {
                return Iterators.addAll(self, elements.iterator());
            }
        }

        private static <E> boolean id21(Multiset<E> self, Multiset<? extends E> elements) {
            if (elements.isEmpty()) {
                return false;
            }
            elements.id13(self::add);
            return true;
        }

        static boolean id31(Multiset<?> self, Collection<?> id16) {
            Collection<?> collection =
                    (id16 instanceof Multiset)
                            ? ((Multiset<?>) id16).elementSet()
                            : id16;

            return self.elementSet().removeAll(collection);
        }

        static boolean id45(Multiset<?> self, Collection<?> id9) {
            Preconditions.id37(id9);
            Collection<?> collection =
                    (id9 instanceof Multiset)
                            ? ((Multiset<?>) id9).elementSet()
                            : id9;

            return self.elementSet().retainAll(collection);
        }

        static <E> int id12(Multiset<E> self, E element, int count) {
            id14.id36(count, "count");

            int oldCount = self.count(element);

            int delta = count - oldCount;
            if (delta > 0) {
                self.add(element, delta);
            } else if (delta < 0) {
                self.remove(element, -delta);
            }

            return oldCount;
        }

        static <E> boolean id12(Multiset<E> self, E element, int oldCount, int newCount) {
            id14.id36(oldCount, "oldCount");
            id14.id36(newCount, "newCount");

            if (self.count(element) == oldCount) {
                self.setCount(element, newCount);
                return true;
            } else {
                return false;
            }
        }

        static <E> Spliterator<E> id22(Multiset<E> multiset) {
            Spliterator<Multiset.Entry<E>> id26 = multiset.entrySet().spliterator();
            return id19.flatMap(
                    id26,
                    entry -> Collections.nCopies(entry.getCount(), entry.getElement()).spliterator(),
                    Spliterator.SIZED
                            | (id26.characteristics()
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

        abstract static class ElementSet<E> extends Sets.id42<E> {
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

        abstract static class EntrySet<E> extends Sets.id42<Multiset.Entry<E>> {
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

        public static <K, V> HashMap<K, V> id7(int expectedSize) {
            return new HashMap<>(capacity(expectedSize));
        }

        static int capacity(int expectedSize) {
            if (expectedSize < 3) {
                id14.id36(expectedSize, "expectedSize");
                return expectedSize + 1;
            }
            if (expectedSize < Ints.id44) {
                

                

                

                return (int) ((float) expectedSize / 0.75F + 1.0F);
            }
            return Integer.MAX_VALUE; 

        }

        static <V> V safeGet(Map<?, V> map, Object key) {
            Preconditions.id37(map);
            try {
                return map.get(key);
            } catch (ClassCastException | NullPointerException e) {
                return null;
            }
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

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
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
            return id30.id12(this, element, count);
        }

        public boolean setCount(E element, int oldCount, int newCount) {
            return id30.id12(this, element, oldCount, newCount);
        }

        public final boolean addAll(Collection<? extends E> id17) {
            return id30.id21(this, id17);
        }

        public final boolean removeAll(Collection<?> id16) {
            return id30.id31(this, id16);
        }

        public final boolean retainAll(Collection<?> id9) {
            return id30.id45(this, id9);
        }

        public abstract void clear();

        public Set<E> elementSet() {
            Set<E> result = elementSet;
            if (result == null) {
                elementSet = result = id11();
            }
            return result;
        }

        Set<E> id11() {
            return new ElementSet();
        }

        abstract Iterator<E> elementIterator();

        public Set<Multiset.Entry<E>> entrySet() {
            Set<Multiset.Entry<E>> result = entrySet;
            if (result == null) {
                entrySet = result = id47();
            }
            return result;
        }

        Set<Multiset.Entry<E>> id47() {
            return new EntrySet();
        }

        abstract Iterator<Multiset.Entry<E>> entryIterator();

        abstract int distinctElements();

        public final boolean equals(Object object) {
            return id30.equalsImpl(this, object);
        }

        public final int hashCode() {
            return entrySet().hashCode();
        }

        public final String toString() {
            return entrySet().toString();
        }

        class ElementSet extends id30.ElementSet<E> {
            Multiset<E> multiset() {
                return id0.this;
            }

            public Iterator<E> iterator() {
                return elementIterator();
            }

        }

        class EntrySet extends id30.EntrySet<E> {
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

    static abstract class id3<E> extends id0<E> implements Serializable {
        private transient Map<E, Count> id27;
        private transient long size;

        protected id3(Map<E, Count> id27) {
            Preconditions.checkArgument(id27.isEmpty());
            this.id27 = id27;
        }

        public Set<Multiset.Entry<E>> entrySet() {
            return super.entrySet();
        }

        Iterator<E> elementIterator() {
            final Iterator<Map.Entry<E, Count>> id41 = id27.entrySet().iterator();
            return new Iterator<E>() {
                Map.Entry<E, Count> toRemove;


                public boolean hasNext() {
                    return id41.hasNext();
                }


                public E next() {
                    final Map.Entry<E, Count> mapEntry = id41.next();
                    toRemove = mapEntry;
                    return mapEntry.getKey();
                }


                public void remove() {
                    id14.checkRemove(toRemove != null);
                    size -= toRemove.getValue().id33(0);
                    id41.remove();
                    toRemove = null;
                }
            };
        }

        Iterator<Multiset.Entry<E>> entryIterator() {
            final Iterator<Map.Entry<E, Count>> id41 = id27.entrySet().iterator();
            return new Iterator<Multiset.Entry<E>>() {
                Map.Entry<E, Count> toRemove;


                public boolean hasNext() {
                    return id41.hasNext();
                }


                public Multiset.Entry<E> next() {
                    final Map.Entry<E, Count> mapEntry = id41.next();
                    toRemove = mapEntry;
                    return new id30.AbstractEntry<E>() {

                        public E getElement() {
                            return mapEntry.getKey();
                        }


                        public int getCount() {
                            Count count = mapEntry.getValue();
                            if (count == null || count.get() == 0) {
                                Count frequency = id27.get(getElement());
                                if (frequency != null) {
                                    return frequency.get();
                                }
                            }
                            return (count == null) ? 0 : count.get();
                        }
                    };
                }


                public void remove() {
                    id14.checkRemove(toRemove != null);
                    size -= toRemove.getValue().id33(0);
                    id41.remove();
                    toRemove = null;
                }
            };
        }

        public void id13(ObjIntConsumer<? super E> action) {
            Preconditions.id37(action);
            id27.forEach((element, count) -> action.accept(element, count.get()));
        }

        public void clear() {
            for (Count frequency : id27.values()) {
                frequency.set(0);
            }
            id27.clear();
            size = 0L;
        }

        int distinctElements() {
            return id27.size();
        }

        public int size() {
            return Ints.id35(size);
        }

        public Iterator<E> iterator() {
            return new id29();
        }

        public int count(Object element) {
            Count frequency = Maps.safeGet(id27, element);
            return (frequency == null) ? 0 : frequency.get();
        }

        public int add(E element, int occurrences) {
            if (occurrences == 0) {
                return count(element);
            }
            Preconditions.checkArgument(occurrences > 0, "occurrences cannot be negative: %s", occurrences);
            Count frequency = id27.get(element);
            int oldCount;
            if (frequency == null) {
                oldCount = 0;
                id27.put(element, new Count(occurrences));
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
            Count frequency = id27.get(element);
            if (frequency == null) {
                return 0;
            }

            int oldCount = frequency.get();

            int numberRemoved;
            if (oldCount > occurrences) {
                numberRemoved = occurrences;
            } else {
                numberRemoved = oldCount;
                id27.remove(element);
            }

            frequency.add(-numberRemoved);
            size -= numberRemoved;
            return oldCount;
        }

        public int setCount(E element, int count) {
            id14.id36(count, "count");

            Count existingCounter;
            int oldCount;
            if (count == 0) {
                existingCounter = id27.remove(element);
                oldCount = id33(existingCounter, count);
            } else {
                existingCounter = id27.get(element);
                oldCount = id33(existingCounter, count);

                if (existingCounter == null) {
                    id27.put(element, new Count(count));
                }
            }

            size += (count - oldCount);
            return oldCount;
        }

        private static int id33(Count i, int count) {
            if (i == null) {
                return 0;
            }

            return i.id33(count);
        }

        private class id29 implements Iterator<E> {
            final Iterator<Map.Entry<E, Count>> entryIterator;
            Map.Entry<E, Count> currentEntry;
            int id40;
            boolean canRemove;

            id29() {
                this.entryIterator = id27.entrySet().iterator();
            }

            public boolean hasNext() {
                return id40 > 0 || entryIterator.hasNext();
            }

            public E next() {
                if (id40 == 0) {
                    currentEntry = entryIterator.next();
                    id40 = currentEntry.getValue().get();
                }
                id40--;
                canRemove = true;
                return currentEntry.getKey();
            }

            public void remove() {
                id14.checkRemove(canRemove);
                int frequency = currentEntry.getValue().get();
                if (frequency <= 0) {
                    throw new ConcurrentModificationException();
                }
                if (currentEntry.getValue().id5(-1) == 0) {
                    entryIterator.remove();
                }
                size--;
                canRemove = false;
            }

        }

    }

    static final class Strings {
        private Strings() {
        }

        public static String id15(
                String template, Object... args) {
            template = String.valueOf(template); 


            if (args == null) {
                args = new Object[]{"(Object[])null"};
            } else {
                for (int i = 0; i < args.length; i++) {
                    args[i] = id10(args[i]);
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

        private static String id10(Object o) {
            if (o == null) {
                return "null";
            }
            try {
                return o.toString();
            } catch (Exception e) {
                

                String id18 =
                        o.getClass().getName() + '@' + Integer.toHexString(System.identityHashCode(o));
                

                Logger.getLogger("com.google.common.base.Strings")
                        .log(Level.WARNING, "Exception during id15 for " + id18, e);
                return "<" + id18 + " threw " + e.getClass().getName() + ">";
            }
        }

    }

    static abstract class id46 {
    }

    static final class Objects extends id23 {
        private Objects() {
        }

        public static boolean equal(Object a, Object b) {
            return a == b || (a != null && a.equals(b));
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

        default void id13(ObjIntConsumer<? super E> action) {
            Preconditions.id37(action);
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
            Preconditions.id37(action);
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
            return id30.id22(this);
        }

        interface Entry<E> {
            E getElement();

            int getCount();

            boolean equals(Object o);

            int hashCode();

            String toString();

        }

    }

    static final class id14 {
        static int id36(int value, String name) {
            if (value < 0) {
                throw new IllegalArgumentException(name + " cannot be negative but was: " + value);
            }
            return value;
        }

        static void checkRemove(boolean canRemove) {
            Preconditions.checkState(canRemove, "no calls to next() since the last call to remove()");
        }

    }

    static final class Sets {
        private Sets() {
        }

        static boolean id31(Set<?> set, Iterator<?> iterator) {
            boolean changed = false;
            while (iterator.hasNext()) {
                changed |= set.remove(iterator.next());
            }
            return changed;
        }

        static boolean id31(Set<?> set, Collection<?> collection) {
            Preconditions.id37(collection); 

            if (collection instanceof Multiset) {
                collection = ((Multiset<?>) collection).elementSet();
            }
            
            if (collection instanceof Set && collection.size() > set.size()) {
                return Iterators.removeAll(set.iterator(), collection);
            } else {
                return id31(set, collection.iterator());
            }
        }

        abstract static class id42<E> extends AbstractSet<E> {
            public boolean removeAll(Collection<?> c) {
                return id31(this, c);
            }

            public boolean retainAll(Collection<?> c) {
                return super.retainAll(Preconditions.id37(c)); 

            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.id43 filter;

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
            while (id8(c)) {
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
            } while (!id8(c));
            return res * sgn;
        }

        public boolean id8(int c) {
            if (filter != null) {
                return filter.id8(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String id2() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r') {
                    buf.appendCodePoint(c);
                }
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = id2();
            while (s.trim().length() == 0) {
                s = id2();
            }
            return s;
        }

        public interface id43 {
            public boolean id8(int ch);

        }

    }

    static final class Ints extends id46 {
        public static final int id44 = 1 << (Integer.SIZE - 2);

        private Ints() {
        }

        public static int id35(long value) {
            if (value > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            if (value < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            return (int) value;
        }

    }

    static final class Iterators {
        private Iterators() {
        }

        public static boolean removeAll(Iterator<?> removeFrom, Collection<?> id16) {
            Preconditions.id37(id16);
            boolean result = false;
            while (removeFrom.hasNext()) {
                if (id16.contains(removeFrom.next())) {
                    removeFrom.remove();
                    result = true;
                }
            }
            return result;
        }

        public static <T> boolean addAll(Collection<T> addTo, Iterator<? extends T> iterator) {
            Preconditions.id37(addTo);
            Preconditions.id37(iterator);
            boolean wasModified = false;
            while (iterator.hasNext()) {
                wasModified |= addTo.add(iterator.next());
            }
            return wasModified;
        }

    }

    static final class id19 {
        private id19() {
        }

        static <InElementT, OutElementT> Spliterator<OutElementT> flatMap(
                Spliterator<InElementT> id25,
                Function<? super InElementT, Spliterator<OutElementT>> function,
                int topCharacteristics,
                long topSize) {
            Preconditions.checkArgument(
                    (topCharacteristics & Spliterator.SUBSIZED) == 0,
                    "flatMap does not support SUBSIZED characteristic");
            Preconditions.checkArgument(
                    (topCharacteristics & Spliterator.SORTED) == 0,
                    "flatMap does not support SORTED characteristic");
            Preconditions.id37(id25);
            Preconditions.id37(function);
            return new id19.id1<InElementT, OutElementT>(
                    null, id25, function, topCharacteristics, topSize);
        }

        abstract static class id34<
                InElementT, OutElementT, OutSpliteratorT extends Spliterator<OutElementT>> implements Spliterator<OutElementT> {
            OutSpliteratorT prefix;
            final Spliterator<InElementT> from;
            final Function<? super InElementT, OutSpliteratorT> function;
            final id19.id34.Factory<InElementT, OutSpliteratorT> factory;
            int characteristics;
            long estimatedSize;

            id34(
                    OutSpliteratorT prefix,
                    Spliterator<InElementT> from,
                    Function<? super InElementT, OutSpliteratorT> function,
                    id19.id34.Factory<InElementT, OutSpliteratorT> factory,
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

            public final void id6(Consumer<? super OutElementT> action) {
                if (prefix != null) {
                    prefix.id6(action);
                    prefix = null;
                }
                from.id6(
                        fromElement -> {
                            Spliterator<OutElementT> elements = function.apply(fromElement);
                            if (elements != null) {
                                elements.id6(action);
                            }
                        });
                estimatedSize = 0;
            }

            public final OutSpliteratorT trySplit() {
                Spliterator<InElementT> fromSplit = from.trySplit();
                if (fromSplit != null) {
                    int splitCharacteristics = characteristics & ~Spliterator.SIZED;
                    long id28 = estimateSize();
                    if (id28 < Long.MAX_VALUE) {
                        id28 /= 2;
                        this.estimatedSize -= id28;
                        this.characteristics = splitCharacteristics;
                    }
                    OutSpliteratorT result =
                            factory.id38(
                                    this.prefix, fromSplit, function, splitCharacteristics, id28);
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
                OutSpliteratorT id38(
                        OutSpliteratorT prefix,
                        Spliterator<InElementT> fromSplit,
                        Function<? super InElementT, OutSpliteratorT> function,
                        int splitCharacteristics,
                        long id28);

            }

        }

        static final class id1<InElementT, OutElementT> extends id19.id34<InElementT, OutElementT, Spliterator<OutElementT>> {
            id1(
                    Spliterator<OutElementT> prefix,
                    Spliterator<InElementT> from,
                    Function<? super InElementT, Spliterator<OutElementT>> function,
                    int characteristics,
                    long estimatedSize) {
                super(
                        prefix, from, function, id19.id1::new, characteristics, estimatedSize);
            }

        }

    }

    static class ArrayUtils {
        public static final char[] id4 = new char[0];

        public static void reverse(final char[] array) {
            if (array == null) {
                return;
            }
            reverse(array, 0, array.length);
        }

        public static void reverse(final char[] array, final int id20, final int id24) {
            if (array == null) {
                return;
            }
            int i = Math.max(id20, 0);
            int j = Math.min(array.length, id24) - 1;
            char tmp;
            while (j > i) {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                j--;
                i++;
            }
        }

        public static char[] toPrimitive(final Character[] array) {
            if (array == null) {
                return null;
            } else if (array.length == 0) {
                return id4;
            }
            final char[] result = new char[array.length];
            for (int i = 0; i < array.length; i++) {
                result[i] = array[i].charValue();
            }
            return result;
        }

        public ArrayUtils() {
        }

    }

    static final class id39<E> extends id3<E> {
        public static <E> id39<E> create() {
            return new id39<E>();
        }

        private id39() {
            super(new HashMap<E, Count>());
        }

        private id39(int distinctElements) {
            super(Maps.<E, Count>id7(distinctElements));
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

        public static void checkArgument(boolean b, String id32, int p1) {
            if (!b) {
                throw new IllegalArgumentException(Strings.id15(id32, p1));
            }
        }

        public static void checkArgument(boolean b, String id32, long p1) {
            if (!b) {
                throw new IllegalArgumentException(Strings.id15(id32, p1));
            }
        }

        public static void checkState(boolean expression, Object errorMessage) {
            if (!expression) {
                throw new IllegalStateException(String.valueOf(errorMessage));
            }
        }

        public static <T extends Object> T id37(T reference) {
            if (reference == null) {
                throw new NullPointerException();
            }
            return reference;
        }

    }

    static abstract class id23 {
    }
}

