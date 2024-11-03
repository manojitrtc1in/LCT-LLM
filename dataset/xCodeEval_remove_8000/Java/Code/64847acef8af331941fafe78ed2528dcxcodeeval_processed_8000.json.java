import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.lang.reflect.Array;
import java.util.ListIterator;
import java.util.Spliterators;
import java.util.function.IntConsumer;
import java.util.AbstractList;
import java.util.InputMismatchException;
import java.util.function.UnaryOperator;
import java.util.AbstractCollection;
import java.util.IllegalFormatException;
import java.io.PrintWriter;
import java.util.function.Predicate;
import java.util.Collection;
import java.util.Set;
import java.util.logging.Logger;
import java.io.Serializable;
import java.util.Objects;
import java.util.List;
import java.io.Writer;
import java.util.Queue;
import java.util.Spliterator;
import java.util.stream.IntStream;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.RandomAccess;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.function.Consumer;
import java.util.Spliterator.OfInt;
import java.util.Comparator;
import java.util.Collections;
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
            int n = in.nextInt();

            ArrayList<List<Integer>> solutions = new ArrayList<>();
            int[] cs = in.id21(n);

            for (int i = 1; i <= n; i++) {
                

                int loc = 0;
                for (int j = 0; j < n; j++) {
                    if (cs[j] == i) {
                        loc = j;
                    }
                }

                

                ArrayList<Integer> solution = new ArrayList<>();
                if ((i + n) % 2 == 0) {

                    for (int j = 0; j < loc; j++) {
                        solution.add(1);
                    }

                    if (n - (loc) - (i - 1) != 0) {
                        solution.add(n - (loc) - (i - 1));
                    }

                    for (int j = 1; j < i; j++) {
                        solution.add(1);
                    }
                    if (solution.size() > 1) {
                        solutions.add(solution);
                        apply(cs, solution);
                    }
                } else {
                    for (int j = 1; j < i; j++) {
                        solution.add(1);
                    }

                    

                    int steps = loc + 2 - i;
                    solution.add(steps);

                    if (n - (loc + 1) != 0) {
                        solution.add(n - (loc + 1));
                    }
                    if (solution.size() > 1) {
                        solutions.add(solution);
                        apply(cs, solution);
                    }
                }
            }

            out.println(solutions.size());

            for (var s : solutions) {
                out.print(s.size() + " ");
                out.println(s.toArray());
            }


        }

        public void apply(int[] cs, ArrayList<Integer> solution) {
            ArrayList<ArrayList<Integer>> slices = new ArrayList<>();
            Queue<Integer> c = new LinkedList<>();

            for (int i : cs) {
                c.offer(i);
            }

            for (int i : solution) {
                ArrayList<Integer> slice = new ArrayList<>();
                for (int j = 0; j < i; j++) {
                    slice.add(c.poll());
                }
                slices.add(slice);
            }

            var rev = Lists.reverse(slices);

            ArrayList<Integer> output = new ArrayList<>();
            for (var sl : rev) {
                output.addAll(sl);
            }

            for (int i = 0; i < cs.length; i++) {
                cs[i] = output.get(i);
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

        public static <T extends Object> T id37(T reference) {
            if (reference == null) {
                throw new NullPointerException();
            }
            return reference;
        }

        public static int id32(int index, int size) {
            return id32(index, size, "index");
        }

        public static int id32(int index, int size, String desc) {
            

            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException(id4(index, size, desc));
            }
            return index;
        }

        private static String id4(int index, int size, String desc) {
            if (index < 0) {
                return Strings.id20("%s (%s) must not be negative", desc, index);
            } else if (size < 0) {
                throw new IllegalArgumentException("negative size: " + size);
            } else { 

                return Strings.id20("%s (%s) must be less than size (%s)", desc, index, size);
            }
        }

        public static int id18(int index, int size) {
            return id18(index, size, "index");
        }

        public static int id18(int index, int size, String desc) {
            

            if (index < 0 || index > size) {
                throw new IndexOutOfBoundsException(id14(index, size, desc));
            }
            return index;
        }

        private static String id14(int index, int size, String desc) {
            if (index < 0) {
                return Strings.id20("%s (%s) must not be negative", desc, index);
            } else if (size < 0) {
                throw new IllegalArgumentException("negative size: " + size);
            } else { 

                return Strings.id20("%s (%s) must not be greater than size (%s)", desc, index, size);
            }
        }

        public static void id27(int start, int end, int size) {
            

            if (start < 0 || end < start || end > size) {
                throw new IndexOutOfBoundsException(id23(start, end, size));
            }
        }

        private static String id23(int start, int end, int size) {
            if (start < 0 || start > size) {
                return id14(start, size, "start index");
            }
            if (end < 0 || end > size) {
                return id14(end, size, "end index");
            }
            

            return Strings.id20("end index (%s) must not be less than start index (%s)", end, start);
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

    static final class Lists {
        private Lists() {
        }

        public static <T> List<T> reverse(List<T> list) {
            if (list instanceof ImmutableList) {
                return ((ImmutableList<T>) list).reverse();
            } else if (list instanceof Lists.ReverseList) {
                return ((Lists.ReverseList<T>) list).id2();
            } else if (list instanceof RandomAccess) {
                return new Lists.id44<>(list);
            } else {
                return new Lists.ReverseList<>(list);
            }
        }

        static boolean equalsImpl(List<?> thisList, Object other) {
            if (other == Preconditions.id37(thisList)) {
                return true;
            }
            if (!(other instanceof List)) {
                return false;
            }
            List<?> otherList = (List<?>) other;
            int size = thisList.size();
            if (size != otherList.size()) {
                return false;
            }
            if (thisList instanceof RandomAccess && otherList instanceof RandomAccess) {
                

                for (int i = 0; i < size; i++) {
                    if (!id43.equal(thisList.get(i), otherList.get(i))) {
                        return false;
                    }
                }
                return true;
            } else {
                return Iterators.elementsEqual(thisList.iterator(), otherList.iterator());
            }
        }

        static int id1(List<?> list, Object element) {
            if (list instanceof RandomAccess) {
                return id38(list, element);
            } else {
                ListIterator<?> listIterator = list.listIterator();
                while (listIterator.hasNext()) {
                    if (id43.equal(element, listIterator.next())) {
                        return listIterator.previousIndex();
                    }
                }
                return -1;
            }
        }

        private static int id38(List<?> list, Object element) {
            int size = list.size();
            if (element == null) {
                for (int i = 0; i < size; i++) {
                    if (list.get(i) == null) {
                        return i;
                    }
                }
            } else {
                for (int i = 0; i < size; i++) {
                    if (element.equals(list.get(i))) {
                        return i;
                    }
                }
            }
            return -1;
        }

        static int id13(List<?> list, Object element) {
            if (list instanceof RandomAccess) {
                return id28(list, element);
            } else {
                ListIterator<?> listIterator = list.listIterator(list.size());
                while (listIterator.hasPrevious()) {
                    if (id43.equal(element, listIterator.previous())) {
                        return listIterator.nextIndex();
                    }
                }
                return -1;
            }
        }

        private static int id28(List<?> list, Object element) {
            if (element == null) {
                for (int i = list.size() - 1; i >= 0; i--) {
                    if (list.get(i) == null) {
                        return i;
                    }
                }
            } else {
                for (int i = list.size() - 1; i >= 0; i--) {
                    if (element.equals(list.get(i))) {
                        return i;
                    }
                }
            }
            return -1;
        }

        private static class ReverseList<T> extends AbstractList<T> {
            private final List<T> forwardList;

            ReverseList(List<T> forwardList) {
                this.forwardList = Preconditions.id37(forwardList);
            }

            List<T> id2() {
                return forwardList;
            }

            private int reverseIndex(int index) {
                int size = size();
                Preconditions.id32(index, size);
                return (size - 1) - index;
            }

            private int reversePosition(int index) {
                int size = size();
                Preconditions.id18(index, size);
                return size - index;
            }

            public void add(int index, T element) {
                forwardList.add(reversePosition(index), element);
            }

            public void clear() {
                forwardList.clear();
            }

            public T remove(int index) {
                return forwardList.remove(reverseIndex(index));
            }

            protected void removeRange(int fromIndex, int toIndex) {
                subList(fromIndex, toIndex).clear();
            }

            public T set(int index, T element) {
                return forwardList.set(reverseIndex(index), element);
            }

            public T get(int index) {
                return forwardList.get(reverseIndex(index));
            }

            public int size() {
                return forwardList.size();
            }

            public List<T> subList(int fromIndex, int toIndex) {
                Preconditions.id27(fromIndex, toIndex, size());
                return reverse(forwardList.subList(reversePosition(toIndex), reversePosition(fromIndex)));
            }

            public Iterator<T> iterator() {
                return listIterator();
            }

            public ListIterator<T> listIterator(int index) {
                int start = reversePosition(index);
                final ListIterator<T> forwardIterator = forwardList.listIterator(start);
                return new ListIterator<T>() {

                    boolean id29;


                    public void add(T e) {
                        forwardIterator.add(e);
                        forwardIterator.previous();
                        id29 = false;
                    }


                    public boolean hasNext() {
                        return forwardIterator.hasPrevious();
                    }


                    public boolean hasPrevious() {
                        return forwardIterator.hasNext();
                    }


                    public T next() {
                        if (!hasNext()) {
                            throw new NoSuchElementException();
                        }
                        id29 = true;
                        return forwardIterator.previous();
                    }


                    public int nextIndex() {
                        return reversePosition(forwardIterator.nextIndex());
                    }


                    public T previous() {
                        if (!hasPrevious()) {
                            throw new NoSuchElementException();
                        }
                        id29 = true;
                        return forwardIterator.next();
                    }


                    public int previousIndex() {
                        return nextIndex() - 1;
                    }


                    public void remove() {
                        id15.checkRemove(id29);
                        forwardIterator.remove();
                        id29 = false;
                    }


                    public void set(T e) {
                        Preconditions.checkState(id29);
                        forwardIterator.set(e);
                    }
                };
            }

        }

        private static class id44<T> extends Lists.ReverseList<T> implements RandomAccess {
            id44(List<T> forwardList) {
                super(forwardList);
            }

        }

    }

    static abstract class id19<E> extends id10<E> implements ListIterator<E> {
        protected id19() {
        }

        public final void add(E e) {
            throw new UnsupportedOperationException();
        }

        public final void set(E e) {
            throw new UnsupportedOperationException();
        }

    }

    static interface id17 {
    }

    static final class Sets {
        private Sets() {
        }

        static int id34(Set<?> s) {
            int hashCode = 0;
            for (Object o : s) {
                hashCode += o != null ? o.hashCode() : 0;

                hashCode = ~~hashCode;
                

            }
            return hashCode;
        }

        static boolean equalsImpl(Set<?> s, Object object) {
            if (s == object) {
                return true;
            }
            if (object instanceof Set) {
                Set<?> o = (Set<?>) object;

                try {
                    return s.size() == o.size() && s.containsAll(o);
                } catch (NullPointerException | ClassCastException ignored) {
                    return false;
                }
            }
            return false;
        }

    }

    static final class ObjectArrays {
        private ObjectArrays() {
        }

        public static <T> T[] newArray(T[] reference, int length) {
            return Platform.newArray(reference, length);
        }

    }

    static abstract class id36<E> extends id19<E> {
        private final int size;
        private int position;

        protected abstract E get(int index);

        protected id36(int size) {
            this(size, 0);
        }

        protected id36(int size, int position) {
            Preconditions.id18(position, size);
            this.size = size;
            this.position = position;
        }

        public final boolean hasNext() {
            return position < size;
        }

        public final E next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            return get(position++);
        }

        public final int nextIndex() {
            return position;
        }

        public final boolean hasPrevious() {
            return position > 0;
        }

        public final E previous() {
            if (!hasPrevious()) {
                throw new NoSuchElementException();
            }
            return get(--position);
        }

        public final int previousIndex() {
            return position - 1;
        }

    }

    static abstract class id10<E> implements Iterator<E> {
        protected id10() {
        }

        public final void remove() {
            throw new UnsupportedOperationException();
        }

    }

    static final class id26 {
        private id26() {
        }

        static <T> Spliterator<T> indexed(int size, int extraCharacteristics, IntFunction<T> function) {
            return indexed(size, extraCharacteristics, function, null);
        }

        static <T> Spliterator<T> indexed(
                int size,
                int extraCharacteristics,
                IntFunction<T> function,
                Comparator<? super T> comparator) {
            if (comparator != null) {
                Preconditions.checkArgument((extraCharacteristics & Spliterator.SORTED) != 0);
            }
            class WithCharacteristics implements Spliterator<T> {
                private final Spliterator.OfInt delegate;

                WithCharacteristics(Spliterator.OfInt delegate) {
                    this.delegate = delegate;
                }


                public boolean tryAdvance(Consumer<? super T> action) {
                    return delegate.tryAdvance((IntConsumer) i -> action.accept(function.apply(i)));
                }


                public void id5(Consumer<? super T> action) {
                    delegate.id5((IntConsumer) i -> action.accept(function.apply(i)));
                }


                public Spliterator<T> trySplit() {
                    Spliterator.OfInt split = delegate.trySplit();
                    return (split == null) ? null : new WithCharacteristics(split);
                }


                public long estimateSize() {
                    return delegate.estimateSize();
                }


                public int characteristics() {
                    return Spliterator.ORDERED
                            | Spliterator.SIZED
                            | Spliterator.SUBSIZED
                            | extraCharacteristics;
                }


                public Comparator<? super T> getComparator() {
                    if (hasCharacteristics(Spliterator.SORTED)) {
                        return comparator;
                    } else {
                        throw new IllegalStateException();
                    }
                }
            }
            return new WithCharacteristics(IntStream.range(0, size).spliterator());
        }

    }

    static final class id43 extends id33 {
        private id43() {
        }

        public static boolean equal(Object a, Object b) {
            return a == b || (a != null && a.equals(b));
        }

    }

    static 

    abstract class ImmutableList<E> extends ImmutableCollection<E> implements List<E>, RandomAccess {
        public static <E> ImmutableList<E> of() {
            return (ImmutableList<E>) id30.EMPTY;
        }

        public static <E> ImmutableList<E> of(E element) {
            return new id12<E>(element);
        }

        ImmutableList() {
        }

        public id10<E> iterator() {
            return listIterator();
        }

        public id19<E> listIterator() {
            return listIterator(0);
        }

        public id19<E> listIterator(int index) {
            return new id36<E>(size(), index) {

                protected E get(int index) {
                    return ImmutableList.this.get(index);
                }
            };
        }

        public void forEach(Consumer<? super E> consumer) {
            Preconditions.id37(consumer);
            int n = size();
            for (int i = 0; i < n; i++) {
                consumer.accept(get(i));
            }
        }

        public int indexOf(Object object) {
            return (object == null) ? -1 : Lists.id1(this, object);
        }

        public int id11(Object object) {
            return (object == null) ? -1 : Lists.id13(this, object);
        }

        public boolean contains(Object object) {
            return indexOf(object) >= 0;
        }

        public ImmutableList<E> subList(int fromIndex, int toIndex) {
            Preconditions.id27(fromIndex, toIndex, size());
            int length = toIndex - fromIndex;
            if (length == size()) {
                return this;
            } else if (length == 0) {
                return of();
            } else if (length == 1) {
                return of(get(fromIndex));
            } else {
                return id3(fromIndex, toIndex);
            }
        }

        ImmutableList<E> id3(int fromIndex, int toIndex) {
            return new SubList(fromIndex, toIndex - fromIndex);
        }

        public final boolean addAll(int index, Collection<? extends E> newElements) {
            throw new UnsupportedOperationException();
        }

        public final E set(int index, E element) {
            throw new UnsupportedOperationException();
        }

        public final void add(int index, E element) {
            throw new UnsupportedOperationException();
        }

        public final E remove(int index) {
            throw new UnsupportedOperationException();
        }

        public final void replaceAll(UnaryOperator<E> operator) {
            throw new UnsupportedOperationException();
        }

        public final void sort(Comparator<? super E> c) {
            throw new UnsupportedOperationException();
        }

        public Spliterator<E> spliterator() {
            return id26.indexed(size(), ImmutableCollection.id24, this::get);
        }

        int id8(Object[] dst, int offset) {
            

            int size = size();
            for (int i = 0; i < size; i++) {
                dst[offset + i] = get(i);
            }
            return offset + size;
        }

        public ImmutableList<E> reverse() {
            return (size() <= 1) ? this : new ImmutableList.id31<E>(this);
        }

        public boolean equals(Object obj) {
            return Lists.equalsImpl(this, obj);
        }

        public int hashCode() {
            int hashCode = 1;
            int n = size();
            for (int i = 0; i < n; i++) {
                hashCode = 31 * hashCode + get(i).hashCode();

                hashCode = ~~hashCode;
                

            }
            return hashCode;
        }

        class SubList extends ImmutableList<E> {
            final transient int offset;
            final transient int length;

            SubList(int offset, int length) {
                this.offset = offset;
                this.length = length;
            }

            public int size() {
                return length;
            }

            public E get(int index) {
                Preconditions.id32(index, length);
                return ImmutableList.this.get(index + offset);
            }

            public ImmutableList<E> subList(int fromIndex, int toIndex) {
                Preconditions.id27(fromIndex, toIndex, length);
                return ImmutableList.this.subList(fromIndex + offset, toIndex + offset);
            }

        }

        private static class id31<E> extends ImmutableList<E> {
            private final transient ImmutableList<E> forwardList;

            id31(ImmutableList<E> id42) {
                this.forwardList = id42;
            }

            private int reverseIndex(int index) {
                return (size() - 1) - index;
            }

            private int reversePosition(int index) {
                return size() - index;
            }

            public ImmutableList<E> reverse() {
                return forwardList;
            }

            public boolean contains(Object object) {
                return forwardList.contains(object);
            }

            public int indexOf(Object object) {
                int index = forwardList.id11(object);
                return (index >= 0) ? reverseIndex(index) : -1;
            }

            public int id11(Object object) {
                int index = forwardList.indexOf(object);
                return (index >= 0) ? reverseIndex(index) : -1;
            }

            public ImmutableList<E> subList(int fromIndex, int toIndex) {
                Preconditions.id27(fromIndex, toIndex, size());
                return forwardList.subList(reversePosition(toIndex), reversePosition(fromIndex)).reverse();
            }

            public E get(int index) {
                Preconditions.id32(index, size());
                return forwardList.get(reverseIndex(index));
            }

            public int size() {
                return forwardList.size();
            }

        }

    }

    static 

    abstract class ImmutableSet<E> extends ImmutableCollection<E> implements Set<E> {
        ImmutableSet() {
        }

        boolean id22() {
            return false;
        }

        public boolean equals(Object object) {
            if (object == this) {
                return true;
            } else if (object instanceof ImmutableSet
                    && id22()
                    && ((ImmutableSet<?>) object).id22()
                    && hashCode() != object.hashCode()) {
                return false;
            }
            return Sets.equalsImpl(this, object);
        }

        public int hashCode() {
            return Sets.id34(this);
        }

        public abstract id10<E> iterator();

    }

    static abstract class id33 {
    }

    static 

    

    

    abstract class ImmutableCollection<E> extends AbstractCollection<E> implements Serializable {
        static final int id24 = Spliterator.IMMUTABLE | Spliterator.NONNULL | Spliterator.ORDERED;
        private static final Object[] EMPTY_ARRAY = {};

        ImmutableCollection() {
        }

        public abstract id10<E> iterator();

        public Spliterator<E> spliterator() {
            return Spliterators.spliterator(this, id24);
        }

        public final Object[] toArray() {
            return toArray(EMPTY_ARRAY);
        }

        public final <T> T[] toArray(T[] other) {
            Preconditions.id37(other);
            int size = size();

            if (other.length < size) {
                Object[] internal = internalArray();
                if (internal != null) {
                    return Platform.copy(internal, id7(), id35(), other);
                }
                other = ObjectArrays.newArray(other, size);
            } else if (other.length > size) {
                other[size] = null;
            }
            id8(other, 0);
            return other;
        }

        Object[] internalArray() {
            return null;
        }

        int id7() {
            throw new UnsupportedOperationException();
        }

        int id35() {
            throw new UnsupportedOperationException();
        }

        public abstract boolean contains(Object object);

        public final boolean add(E e) {
            throw new UnsupportedOperationException();
        }

        public final boolean remove(Object object) {
            throw new UnsupportedOperationException();
        }

        public final boolean addAll(Collection<? extends E> newElements) {
            throw new UnsupportedOperationException();
        }

        public final boolean removeAll(Collection<?> oldElements) {
            throw new UnsupportedOperationException();
        }

        public final boolean removeIf(Predicate<? super E> filter) {
            throw new UnsupportedOperationException();
        }

        public final boolean retainAll(Collection<?> id40) {
            throw new UnsupportedOperationException();
        }

        public final void clear() {
            throw new UnsupportedOperationException();
        }

        int id8(Object[] dst, int offset) {
            for (E e : this) {
                dst[offset++] = e;
            }
            return offset;
        }

    }

    static final class id15 {
        static void checkRemove(boolean canRemove) {
            Preconditions.checkState(canRemove, "no calls to next() since the last call to remove()");
        }

    }

    static class id30<E> extends ImmutableList<E> {
        static final ImmutableList<Object> EMPTY = new id30<>(new Object[0]);
        final transient Object[] array;

        id30(Object[] array) {
            this.array = array;
        }

        public int size() {
            return array.length;
        }

        Object[] internalArray() {
            return array;
        }

        int id7() {
            return 0;
        }

        int id35() {
            return array.length;
        }

        int id8(Object[] dst, int dstOff) {
            System.arraycopy(array, 0, dst, dstOff, array.length);
            return dstOff + array.length;
        }

        public E get(int index) {
            return (E) array[index];
        }

        public id19<E> listIterator(int index) {
            

            

            return (id19<E>) Iterators.forArray(array, 0, array.length, index);
        }

        public Spliterator<E> spliterator() {
            return Spliterators.spliterator(array, ImmutableCollection.id24);
        }

    }

    static interface Nullable {
    }

    static final class Platform {
        static <T> T[] newArray(T[] reference, int length) {
            Class<?> type = reference.getClass().getComponentType();

            

            


            T[] result = (T[]) Array.newInstance(type, length);
            return result;
        }

        static <T> T[] copy(Object[] source, int from, int to, T[] id39) {
            return Arrays.copyOfRange(source, from, to, (Class<? extends T[]>) id39.getClass());
        }

        private Platform() {
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

        public int[] id21(int n) {
            int[] array = new int[n];
            for (int i = 0; i < n; ++i) array[i] = nextInt();
            return array;
        }

        public interface id41 {
            public boolean id6(int ch);

        }

    }

    static final class Strings {
        private Strings() {
        }

        public static String id20(
                String template, Object... args) {
            template = String.valueOf(template); 


            if (args == null) {
                args = new Object[]{"(Object[])null"};
            } else {
                for (int i = 0; i < args.length; i++) {
                    args[i] = id9(args[i]);
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

        private static String id9(Object o) {
            if (o == null) {
                return "null";
            }
            try {
                return o.toString();
            } catch (Exception e) {
                

                String id25 =
                        o.getClass().getName() + '@' + Integer.toHexString(System.identityHashCode(o));
                

                Logger.getLogger("com.google.common.base.Strings")
                        .log(Level.WARNING, "Exception during id20 for " + id25, e);
                return "<" + id25 + " threw " + e.getClass().getName() + ">";
            }
        }

    }

    static interface id0 {
    }

    static final class Verify {
        private Verify() {
        }

    }

    static interface NonNull {
    }

    static final class Iterators {
        private Iterators() {
        }

        static <T> id19<T> id16() {
            return (id19<T>) Iterators.ArrayItr.EMPTY;
        }

        public static boolean elementsEqual(Iterator<?> iterator1, Iterator<?> iterator2) {
            while (iterator1.hasNext()) {
                if (!iterator2.hasNext()) {
                    return false;
                }
                Object o1 = iterator1.next();
                Object o2 = iterator2.next();
                if (!id43.equal(o1, o2)) {
                    return false;
                }
            }
            return !iterator2.hasNext();
        }

        static <T> id19<T> forArray(
                final T[] array, final int offset, int length, int index) {
            Preconditions.checkArgument(length >= 0);
            int end = offset + length;

            

            Preconditions.id27(offset, end, array.length);
            Preconditions.id18(index, length);
            if (length == 0) {
                return id16();
            }
            return new Iterators.ArrayItr<T>(array, offset, length, index);
        }

        public static <T> id10<T> singletonIterator(final T value) {
            return new id10<T>() {
                boolean done;


                public boolean hasNext() {
                    return !done;
                }


                public T next() {
                    if (done) {
                        throw new NoSuchElementException();
                    }
                    done = true;
                    return value;
                }
            };
        }

        private static final class ArrayItr<T> extends id36<T> {
            static final id19<Object> EMPTY = new Iterators.ArrayItr<>(new Object[0], 0, 0, 0);
            private final T[] array;
            private final int offset;

            ArrayItr(T[] array, int offset, int length, int index) {
                super(length, index);
                this.array = array;
                this.offset = offset;
            }

            protected T get(int index) {
                return array[offset + index];
            }

        }

    }

    static 

    final class id12<E> extends ImmutableList<E> {
        final transient E element;

        id12(E element) {
            this.element = Preconditions.id37(element);
        }

        public E get(int index) {
            Preconditions.id32(index, 1);
            return element;
        }

        public id10<E> iterator() {
            return Iterators.singletonIterator(element);
        }

        public Spliterator<E> spliterator() {
            return Collections.singleton(element).spliterator();
        }

        public int size() {
            return 1;
        }

        public ImmutableList<E> subList(int fromIndex, int toIndex) {
            Preconditions.id27(fromIndex, toIndex, 1);
            return (fromIndex == toIndex) ? ImmutableList.<E>of() : this;
        }

        public String toString() {
            return '[' + element.toString() + ']';
        }

    }
}
