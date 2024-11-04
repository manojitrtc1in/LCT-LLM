import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.Collection;
import java.util.AbstractList;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Deque;
import java.util.concurrent.ThreadLocalRandom;
import java.util.ArrayDeque;
import java.util.NoSuchElementException;
import java.util.ConcurrentModificationException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        id22 solver = new id22();
        solver.solve(1, in, out);
        out.close();
    }

    static class id22 {
        private static final int MAXA = (int) 2e5 + 10;
        private InputReader in;
        private PrintWriter out;
        private int[] a;
        private int[] cnt;
        private int n;
        private int pos;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            a = in.id12(n, 1);
            cnt = new int[MAXA];
            QuickSort.sort(a, 1, n);

            int l = 1, r = n;
            while (l != r) {
                if (l == r - 1) {
                    if (ch(r)) l = r;
                    break;
                }
                int m = (l + r) >> 1;
                if (ch(m)) l = m;
                else r = m - 1;
            }










            out.println(l);
            ch(l);
            TreeList<Integer> ans = new TreeList<>();
            ans.add(a[pos]);
            for (int i = pos + 1; i <= pos + l - 1; i++) {
                if (a[i] != a[i - 1]) ans.add(0, a[i]);
                else ans.add(a[i]);
            }
            for (int i : ans) out.print(i + " ");
        }

        private boolean ch(int m) {
            for (int i = 1; i <= n - m + 1; i++) {
                boolean f = false;
                for (int j = i + 1; j <= i + m - 1; j++) {
                    if (a[j] - a[j - 1] > 1) {
                        i = j - 1;
                        f = true;
                        break;
                    }
                    if (a[j] != a[i] && a[j] != a[i + m - 1]) {
                        if (a[j] != a[j - 1] && a[j] != a[j + 1]) {
                            i = j - 1;
                            f = true;
                            break;
                        }
                    }
                }
                if (f) continue;
                pos = i;
                return true;
            }
            return false;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

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
            while (id3(c))
                c = read();
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

        public int[] id12(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean id3(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class ArrayAlgorithm {
        public static void shuffleArray(int[] array, int stIndex, int enIndex) {
            for (int i = enIndex; i > stIndex; i--) {
                int index = (int) id0.genInt(stIndex, i - 1);
                if (index != i) {
                    array[index] ^= array[i];
                    array[i] ^= array[index];
                    array[index] ^= array[i];
                }
            }
        }

    }

    static interface OrderedIterator<E> extends Iterator<E> {
    }

    static class id0 {
        private static long genI(long min, long max) {
            return ThreadLocalRandom.current().nextLong(min, max + 1);
        }

        public static long genInt(long min, long max) {
            if (min >= 0)
                return (genI(min, max));
            else if (max >= 0) {
                double ratio = (double) Math.abs(min) / (Math.abs(min) + max);
                ratio *= 1000000000000000000D;
                double prob = (double) (id0.genInt(1, 1000000000000000000L));
                if (Double.compare(ratio, prob) > 0) {
                    return -(genI(0, -min));
                } else {
                    return (genI(0, max));
                }
            } else
                return -(id0.genI(-min, -max));
        }

    }

    static class TreeList<E> extends AbstractList<E> {
        private TreeList.AVLNode<E> root;
        private int size;

        public TreeList() {
            super();
        }

        public TreeList(final Collection<? extends E> coll) {
            super();
            if (!coll.isEmpty()) {
                root = new TreeList.AVLNode<>(coll);
                size = coll.size();
            }
        }

        public E get(final int index) {
            return root.get(index).getValue();
        }

        public int size() {
            return size;
        }

        public Iterator<E> iterator() {
            

            return listIterator(0);
        }

        public ListIterator<E> listIterator() {
            

            return listIterator(0);
        }

        public ListIterator<E> listIterator(final int fromIndex) {
            return new TreeList.id10<>(this, fromIndex);
        }

        public int indexOf(final Object object) {
            

            if (root == null) {
                return -1;
            }
            return root.indexOf(object, root.relativePosition);
        }

        public boolean contains(final Object object) {
            return indexOf(object) >= 0;
        }

        public Object[] toArray() {
            final Object[] array = new Object[size()];
            if (root != null) {
                root.toArray(array, root.relativePosition);
            }
            return array;
        }

        public void add(final int index, final E obj) {
            modCount++;
            if (root == null) {
                root = new TreeList.AVLNode<>(index, obj, null, null);
            } else {
                root = root.insert(index, obj);
            }
            size++;
        }

        public boolean addAll(final Collection<? extends E> c) {
            if (c.isEmpty()) {
                return false;
            }
            modCount += c.size();
            final TreeList.AVLNode<E> cTree = new TreeList.AVLNode<>(c);
            root = root == null ? cTree : root.addAll(cTree, size);
            size += c.size();
            return true;
        }

        public E set(final int index, final E obj) {
            final TreeList.AVLNode<E> node = root.get(index);
            final E result = node.value;
            node.setValue(obj);
            return result;
        }

        public E remove(final int index) {
            modCount++;
            final E result = get(index);
            root = root.remove(index);
            size--;
            return result;
        }

        public void clear() {
            modCount++;
            root = null;
            size = 0;
        }

        static class AVLNode<E> {
            private TreeList.AVLNode<E> left;
            private boolean id6;
            private TreeList.AVLNode<E> right;
            private boolean id16;
            private int height;
            private int relativePosition;
            private E value;

            private AVLNode(final int relativePosition, final E obj,
                            final TreeList.AVLNode<E> rightFollower, final TreeList.AVLNode<E> leftFollower) {
                this.relativePosition = relativePosition;
                value = obj;
                id16 = true;
                id6 = true;
                right = rightFollower;
                left = leftFollower;
            }

            private AVLNode(final Collection<? extends E> coll) {
                this(coll.iterator(), 0, coll.size() - 1, 0, null, null);
            }

            private AVLNode(final Iterator<? extends E> iterator, final int start, final int end,
                            final int id11, final TreeList.AVLNode<E> prev, final TreeList.AVLNode<E> next) {
                final int mid = start + (end - start) / 2;
                if (start < mid) {
                    left = new TreeList.AVLNode<>(iterator, start, mid - 1, mid, prev, this);
                } else {
                    id6 = true;
                    left = prev;
                }
                value = iterator.next();
                relativePosition = mid - id11;
                if (mid < end) {
                    right = new TreeList.AVLNode<>(iterator, mid + 1, end, mid, this, next);
                } else {
                    id16 = true;
                    right = next;
                }
                id14();
            }

            E getValue() {
                return value;
            }

            void setValue(final E obj) {
                this.value = obj;
            }

            TreeList.AVLNode<E> get(final int index) {
                final int id15 = index - relativePosition;

                if (id15 == 0) {
                    return this;
                }

                final TreeList.AVLNode<E> nextNode = id15 < 0 ? id24() : id25();
                if (nextNode == null) {
                    return null;
                }
                return nextNode.get(id15);
            }

            int indexOf(final Object object, final int index) {
                if (id24() != null) {
                    final int result = left.indexOf(object, index + left.relativePosition);
                    if (result != -1) {
                        return result;
                    }
                }
                if (value == null ? value == object : value.equals(object)) {
                    return index;
                }
                if (id25() != null) {
                    return right.indexOf(object, index + right.relativePosition);
                }
                return -1;
            }

            void toArray(final Object[] array, final int index) {
                array[index] = value;
                if (id24() != null) {
                    left.toArray(array, index + left.relativePosition);
                }
                if (id25() != null) {
                    right.toArray(array, index + right.relativePosition);
                }
            }

            TreeList.AVLNode<E> next() {
                if (id16 || right == null) {
                    return right;
                }
                return right.min();
            }

            TreeList.AVLNode<E> previous() {
                if (id6 || left == null) {
                    return left;
                }
                return left.max();
            }

            TreeList.AVLNode<E> insert(final int index, final E obj) {
                final int id15 = index - relativePosition;

                if (id15 <= 0) {
                    return id2(id15, obj);
                }
                return id9(id15, obj);
            }

            private TreeList.AVLNode<E> id2(final int id15, final E obj) {
                if (id24() == null) {
                    setLeft(new TreeList.AVLNode<>(-1, obj, this, left), null);
                } else {
                    setLeft(left.insert(id15, obj), null);
                }

                if (relativePosition >= 0) {
                    relativePosition++;
                }
                final TreeList.AVLNode<E> ret = balance();
                id14();
                return ret;
            }

            private TreeList.AVLNode<E> id9(final int id15, final E obj) {
                if (id25() == null) {
                    setRight(new TreeList.AVLNode<>(+1, obj, right, this), null);
                } else {
                    setRight(right.insert(id15, obj), null);
                }
                if (relativePosition < 0) {
                    relativePosition--;
                }
                final TreeList.AVLNode<E> ret = balance();
                id14();
                return ret;
            }

            private TreeList.AVLNode<E> id24() {
                return id6 ? null : left;
            }

            private TreeList.AVLNode<E> id25() {
                return id16 ? null : right;
            }

            private TreeList.AVLNode<E> max() {
                return id25() == null ? this : right.max();
            }

            private TreeList.AVLNode<E> min() {
                return id24() == null ? this : left.min();
            }

            TreeList.AVLNode<E> remove(final int index) {
                final int id15 = index - relativePosition;

                if (id15 == 0) {
                    return removeSelf();
                }
                if (id15 > 0) {
                    setRight(right.remove(id15), right.right);
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    setLeft(left.remove(id15), left.left);
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                id14();
                return balance();
            }

            private TreeList.AVLNode<E> removeMax() {
                if (id25() == null) {
                    return removeSelf();
                }
                setRight(right.removeMax(), right.right);
                if (relativePosition < 0) {
                    relativePosition++;
                }
                id14();
                return balance();
            }

            private TreeList.AVLNode<E> removeMin() {
                if (id24() == null) {
                    return removeSelf();
                }
                setLeft(left.removeMin(), left.left);
                if (relativePosition > 0) {
                    relativePosition--;
                }
                id14();
                return balance();
            }

            private TreeList.AVLNode<E> removeSelf() {
                if (id25() == null && id24() == null) {
                    return null;
                }
                if (id25() == null) {
                    if (relativePosition > 0) {
                        left.relativePosition += relativePosition;
                    }
                    left.max().setRight(null, right);
                    return left;
                }
                if (id24() == null) {
                    right.relativePosition += relativePosition - (relativePosition < 0 ? 0 : 1);
                    right.min().setLeft(null, left);
                    return right;
                }

                if (id21() > 0) {
                    

                    final TreeList.AVLNode<E> rightMin = right.min();
                    value = rightMin.value;
                    if (id6) {
                        left = rightMin.left;
                    }
                    right = right.removeMin();
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    

                    final TreeList.AVLNode<E> leftMax = left.max();
                    value = leftMax.value;
                    if (id16) {
                        right = leftMax.right;
                    }
                    final TreeList.AVLNode<E> leftPrevious = left.left;
                    left = left.removeMax();
                    if (left == null) {
                        

                        

                        left = leftPrevious;
                        id6 = true;
                    }
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                id14();
                return this;
            }

            private TreeList.AVLNode<E> balance() {
                switch (id21()) {
                    case 1:
                    case 0:
                    case -1:
                        return this;
                    case -2:
                        if (left.id21() > 0) {
                            setLeft(left.rotateLeft(), null);
                        }
                        return rotateRight();
                    case 2:
                        if (right.id21() < 0) {
                            setRight(right.rotateRight(), null);
                        }
                        return rotateLeft();
                    default:
                        throw new RuntimeException("tree inconsistent!");
                }
            }

            private int getOffset(final TreeList.AVLNode<E> node) {
                if (node == null) {
                    return 0;
                }
                return node.relativePosition;
            }

            private int setOffset(final TreeList.AVLNode<E> node, final int id7) {
                if (node == null) {
                    return 0;
                }
                final int oldOffset = getOffset(node);
                node.relativePosition = id7;
                return oldOffset;
            }

            private void id14() {
                height = Math.max(
                        id24() == null ? -1 : id24().height,
                        id25() == null ? -1 : id25().height) + 1;
            }

            private int getHeight(final TreeList.AVLNode<E> node) {
                return node == null ? -1 : node.height;
            }

            private int id21() {
                return getHeight(id25()) - getHeight(id24());
            }

            private TreeList.AVLNode<E> rotateLeft() {
                final TreeList.AVLNode<E> newTop = right; 

                final TreeList.AVLNode<E> id1 = id25().id24();

                final int id18 = relativePosition + getOffset(newTop);
                final int id19 = -newTop.relativePosition;
                final int id20 = getOffset(newTop) + getOffset(id1);

                setRight(id1, newTop);
                newTop.setLeft(this, null);

                setOffset(newTop, id18);
                setOffset(this, id19);
                setOffset(id1, id20);
                return newTop;
            }

            private TreeList.AVLNode<E> rotateRight() {
                final TreeList.AVLNode<E> newTop = left;
                final TreeList.AVLNode<E> id1 = id24().id25();

                final int id18 = relativePosition + getOffset(newTop);
                final int id19 = -newTop.relativePosition;
                final int id20 = getOffset(newTop) + getOffset(id1);

                setLeft(id1, newTop);
                newTop.setRight(this, null);

                setOffset(newTop, id18);
                setOffset(this, id19);
                setOffset(id1, id20);
                return newTop;
            }

            private void setLeft(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> previous) {
                id6 = node == null;
                left = id6 ? previous : node;
                id14();
            }

            private void setRight(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> next) {
                id16 = node == null;
                right = id16 ? next : node;
                id14();
            }

            private TreeList.AVLNode<E> addAll(TreeList.AVLNode<E> otherTree, final int currentSize) {
                final TreeList.AVLNode<E> maxNode = max();
                final TreeList.AVLNode<E> id17 = otherTree.min();

                

                

                

                

                

                

                if (otherTree.height > height) {
                    

                    


                    

                    final TreeList.AVLNode<E> id23 = removeMax();

                    

                    

                    

                    

                    final Deque<TreeList.AVLNode<E>> id8 = new ArrayDeque<>();
                    TreeList.AVLNode<E> s = otherTree;
                    int id13 = s.relativePosition + currentSize;
                    int id5 = 0;
                    while (s != null && s.height > getHeight(id23)) {
                        id5 = id13;
                        id8.push(s);
                        s = s.left;
                        if (s != null) {
                            id13 += s.relativePosition;
                        }
                    }

                    

                    

                    

                    maxNode.setLeft(id23, null);
                    maxNode.setRight(s, id17);
                    if (id23 != null) {
                        id23.max().setRight(null, maxNode);
                        id23.relativePosition -= currentSize - 1;
                    }
                    if (s != null) {
                        s.min().setLeft(null, maxNode);
                        s.relativePosition = id13 - currentSize + 1;
                    }
                    maxNode.relativePosition = currentSize - 1 - id5;
                    otherTree.relativePosition += currentSize;

                    

                    s = maxNode;
                    while (!id8.isEmpty()) {
                        final TreeList.AVLNode<E> sAncestor = id8.pop();
                        sAncestor.setLeft(s, null);
                        s = sAncestor.balance();
                    }
                    return s;
                }
                otherTree = otherTree.removeMin();

                final Deque<TreeList.AVLNode<E>> id8 = new ArrayDeque<>();
                TreeList.AVLNode<E> s = this;
                int id13 = s.relativePosition;
                int id5 = 0;
                while (s != null && s.height > getHeight(otherTree)) {
                    id5 = id13;
                    id8.push(s);
                    s = s.right;
                    if (s != null) {
                        id13 += s.relativePosition;
                    }
                }

                id17.setRight(otherTree, null);
                id17.setLeft(s, maxNode);
                if (otherTree != null) {
                    otherTree.min().setLeft(null, id17);
                    otherTree.relativePosition++;
                }
                if (s != null) {
                    s.max().setRight(null, id17);
                    s.relativePosition = id13 - currentSize;
                }
                id17.relativePosition = currentSize - id5;

                s = id17;
                while (!id8.isEmpty()) {
                    final TreeList.AVLNode<E> sAncestor = id8.pop();
                    sAncestor.setRight(s, null);
                    s = sAncestor.balance();
                }
                return s;
            }

        }

        static class id10<E> implements ListIterator<E>, OrderedIterator<E> {
            private final TreeList<E> parent;
            private TreeList.AVLNode<E> next;
            private int nextIndex;
            private TreeList.AVLNode<E> current;
            private int currentIndex;
            private int id26;

            private id10(final TreeList<E> parent, final int fromIndex) throws IndexOutOfBoundsException {
                super();
                this.parent = parent;
                this.id26 = parent.modCount;
                this.next = parent.root == null ? null : parent.root.get(fromIndex);
                this.nextIndex = fromIndex;
                this.currentIndex = -1;
            }

            private void id4() {
                if (parent.modCount != id26) {
                    throw new ConcurrentModificationException();
                }
            }

            public boolean hasNext() {
                return nextIndex < parent.size();
            }

            public E next() {
                id4();
                if (!hasNext()) {
                    throw new NoSuchElementException("No element at index " + nextIndex + ".");
                }
                if (next == null) {
                    next = parent.root.get(nextIndex);
                }
                final E value = next.getValue();
                current = next;
                currentIndex = nextIndex++;
                next = next.next();
                return value;
            }

            public boolean hasPrevious() {
                return nextIndex > 0;
            }

            public E previous() {
                id4();
                if (!hasPrevious()) {
                    throw new NoSuchElementException("Already at start of list.");
                }
                if (next == null) {
                    next = parent.root.get(nextIndex - 1);
                } else {
                    next = next.previous();
                }
                final E value = next.getValue();
                current = next;
                currentIndex = --nextIndex;
                return value;
            }

            public int nextIndex() {
                return nextIndex;
            }

            public int previousIndex() {
                return nextIndex() - 1;
            }

            public void remove() {
                id4();
                if (currentIndex == -1) {
                    throw new IllegalStateException();
                }
                parent.remove(currentIndex);
                if (nextIndex != currentIndex) {
                    

                    nextIndex--;
                }
                

                

                next = null;
                current = null;
                currentIndex = -1;
                id26++;
            }

            public void set(final E obj) {
                id4();
                if (current == null) {
                    throw new IllegalStateException();
                }
                current.setValue(obj);
            }

            public void add(final E obj) {
                id4();
                parent.add(nextIndex, obj);
                current = null;
                currentIndex = -1;
                nextIndex++;
                id26++;
            }

        }

    }

    static class QuickSort {
        public static void sort(int[] list, int lowIndex, int highIndex) {
            ArrayAlgorithm.shuffleArray(list, lowIndex, highIndex);
            Arrays.sort(list, lowIndex, highIndex + 1);
        }

    }
}

