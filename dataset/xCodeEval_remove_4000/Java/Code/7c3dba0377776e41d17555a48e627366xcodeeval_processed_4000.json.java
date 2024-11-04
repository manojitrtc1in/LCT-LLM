import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ListIterator;
import java.util.AbstractList;
import java.util.InputMismatchException;
import java.util.Deque;
import java.util.NoSuchElementException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Collection;
import java.io.IOException;
import java.util.List;
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
        PrintWriter out = new PrintWriter(outputStream);
        id10 solver = new id10();
        solver.solve(1, in, out);
        out.close();
    }

    static class id10 {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = in.id14(n, 1);
            int[] b = new int[n + 1];
            if (n >= 0) System.arraycopy(a, 1, b, 1, n);
            MergeSort.sort(b, 1, n, Comparator.reverseOrder());
            int max = ArrayAlgorithm.getMax(a, 1, n);
            if (max < 0) {
                out.println(max);
                return;
            }
            int defAns = b[1];
            for (int i = 2; i <= MaxMin.Min(n, m); i++) {
                if (b[i] < 0) break;
                defAns += b[i];
            }
            SBTree<Integer>[] setB = new SBTree[n + 1];
            SBTree<Integer>[] setA = new SBTree[n + 1];
            for (int i = 1; i <= n; i++) {
                setA[i] = new SBTree<>(true);
                setB[i] = new SBTree<>(true);
            }
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    setA[i].add(a[j]);
                }
                for (int j = i - 1; j >= 1; j--) {
                    setB[i].add(a[j]);
                }
            }
            int ans = defAns;
            for (int i = 1; i <= n; i++)
                for (int j = i + m - 1; j <= n; j++) {
                    int res = 0;
                    TreeList<Integer> listIn = new TreeList<>();
                    TreeList<Integer> listOut = new TreeList<>();

                    for (int k = i; k <= j; k++) listIn.add(a[k]);
                    Collections.sort(listIn);
                    for (int k = 0; k < listIn.size(); k++)
                        if (k < m) listOut.add(listIn.get(k));
                        else
                            res += listIn.get(k);
                    for (int k = 1; k <= m; k++) {
                        if (k > setA[j].size()) break;
                        listOut.add(setA[j].id28(setA[j].size() - k + 1));
                    }

                    for (int k = 1; k <= m; k++) {
                        if (k > setB[i].size()) break;
                        listOut.add(setB[i].id28(setB[i].size() - k + 1));
                    }
                    listOut.sort(Collections.reverseOrder());
                    for (int k = 0; k <= MaxMin.Min(listOut.size() - 1, m - 1); k++) {
                        if (res + listOut.get(k) < res) break;
                        res += listOut.get(k);
                    }
                    ans = MaxMin.Max(ans, res);
                }
            out.println(ans);
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
            return new TreeList.id12<>(this, fromIndex);
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
            private boolean id7;
            private TreeList.AVLNode<E> right;
            private boolean id18;
            private int height;
            private int relativePosition;
            private E value;

            private AVLNode(final int relativePosition, final E obj,
                            final TreeList.AVLNode<E> rightFollower, final TreeList.AVLNode<E> leftFollower) {
                this.relativePosition = relativePosition;
                value = obj;
                id18 = true;
                id7 = true;
                right = rightFollower;
                left = leftFollower;
            }

            private AVLNode(final Collection<? extends E> coll) {
                this(coll.iterator(), 0, coll.size() - 1, 0, null, null);
            }

            private AVLNode(final Iterator<? extends E> iterator, final int start, final int end,
                            final int id13, final TreeList.AVLNode<E> prev, final TreeList.AVLNode<E> next) {
                final int mid = start + (end - start) / 2;
                if (start < mid) {
                    left = new TreeList.AVLNode<>(iterator, start, mid - 1, mid, prev, this);
                } else {
                    id7 = true;
                    left = prev;
                }
                value = iterator.next();
                relativePosition = mid - id13;
                if (mid < end) {
                    right = new TreeList.AVLNode<>(iterator, mid + 1, end, mid, this, next);
                } else {
                    id18 = true;
                    right = next;
                }
                id16();
            }

            E getValue() {
                return value;
            }

            void setValue(final E obj) {
                this.value = obj;
            }

            TreeList.AVLNode<E> get(final int index) {
                final int id17 = index - relativePosition;

                if (id17 == 0) {
                    return this;
                }

                final TreeList.AVLNode<E> nextNode = id17 < 0 ? id26() : id27();
                if (nextNode == null) {
                    return null;
                }
                return nextNode.get(id17);
            }

            int indexOf(final Object object, final int index) {
                if (id26() != null) {
                    final int result = left.indexOf(object, index + left.relativePosition);
                    if (result != -1) {
                        return result;
                    }
                }
                if (value == null ? value == object : value.equals(object)) {
                    return index;
                }
                if (id27() != null) {
                    return right.indexOf(object, index + right.relativePosition);
                }
                return -1;
            }

            void toArray(final Object[] array, final int index) {
                array[index] = value;
                if (id26() != null) {
                    left.toArray(array, index + left.relativePosition);
                }
                if (id27() != null) {
                    right.toArray(array, index + right.relativePosition);
                }
            }

            TreeList.AVLNode<E> next() {
                if (id18 || right == null) {
                    return right;
                }
                return right.min();
            }

            TreeList.AVLNode<E> previous() {
                if (id7 || left == null) {
                    return left;
                }
                return left.max();
            }

            TreeList.AVLNode<E> insert(final int index, final E obj) {
                final int id17 = index - relativePosition;

                if (id17 <= 0) {
                    return id1(id17, obj);
                }
                return id11(id17, obj);
            }

            private TreeList.AVLNode<E> id1(final int id17, final E obj) {
                if (id26() == null) {
                    setLeft(new TreeList.AVLNode<>(-1, obj, this, left), null);
                } else {
                    setLeft(left.insert(id17, obj), null);
                }

                if (relativePosition >= 0) {
                    relativePosition++;
                }
                final TreeList.AVLNode<E> ret = balance();
                id16();
                return ret;
            }

            private TreeList.AVLNode<E> id11(final int id17, final E obj) {
                if (id27() == null) {
                    setRight(new TreeList.AVLNode<>(+1, obj, right, this), null);
                } else {
                    setRight(right.insert(id17, obj), null);
                }
                if (relativePosition < 0) {
                    relativePosition--;
                }
                final TreeList.AVLNode<E> ret = balance();
                id16();
                return ret;
            }

            private TreeList.AVLNode<E> id26() {
                return id7 ? null : left;
            }

            private TreeList.AVLNode<E> id27() {
                return id18 ? null : right;
            }

            private TreeList.AVLNode<E> max() {
                return id27() == null ? this : right.max();
            }

            private TreeList.AVLNode<E> min() {
                return id26() == null ? this : left.min();
            }

            TreeList.AVLNode<E> remove(final int index) {
                final int id17 = index - relativePosition;

                if (id17 == 0) {
                    return removeSelf();
                }
                if (id17 > 0) {
                    setRight(right.remove(id17), right.right);
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    setLeft(left.remove(id17), left.left);
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                id16();
                return balance();
            }

            private TreeList.AVLNode<E> removeMax() {
                if (id27() == null) {
                    return removeSelf();
                }
                setRight(right.removeMax(), right.right);
                if (relativePosition < 0) {
                    relativePosition++;
                }
                id16();
                return balance();
            }

            private TreeList.AVLNode<E> removeMin() {
                if (id26() == null) {
                    return removeSelf();
                }
                setLeft(left.removeMin(), left.left);
                if (relativePosition > 0) {
                    relativePosition--;
                }
                id16();
                return balance();
            }

            private TreeList.AVLNode<E> removeSelf() {
                if (id27() == null && id26() == null) {
                    return null;
                }
                if (id27() == null) {
                    if (relativePosition > 0) {
                        left.relativePosition += relativePosition;
                    }
                    left.max().setRight(null, right);
                    return left;
                }
                if (id26() == null) {
                    right.relativePosition += relativePosition - (relativePosition < 0 ? 0 : 1);
                    right.min().setLeft(null, left);
                    return right;
                }

                if (id24() > 0) {
                    

                    final TreeList.AVLNode<E> rightMin = right.min();
                    value = rightMin.value;
                    if (id7) {
                        left = rightMin.left;
                    }
                    right = right.removeMin();
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    

                    final TreeList.AVLNode<E> leftMax = left.max();
                    value = leftMax.value;
                    if (id18) {
                        right = leftMax.right;
                    }
                    final TreeList.AVLNode<E> leftPrevious = left.left;
                    left = left.removeMax();
                    if (left == null) {
                        

                        

                        left = leftPrevious;
                        id7 = true;
                    }
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                id16();
                return this;
            }

            private TreeList.AVLNode<E> balance() {
                switch (id24()) {
                    case 1:
                    case 0:
                    case -1:
                        return this;
                    case -2:
                        if (left.id24() > 0) {
                            setLeft(left.rotateLeft(), null);
                        }
                        return rotateRight();
                    case 2:
                        if (right.id24() < 0) {
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

            private int setOffset(final TreeList.AVLNode<E> node, final int id8) {
                if (node == null) {
                    return 0;
                }
                final int oldOffset = getOffset(node);
                node.relativePosition = id8;
                return oldOffset;
            }

            private void id16() {
                height = Math.max(
                        id26() == null ? -1 : id26().height,
                        id27() == null ? -1 : id27().height) + 1;
            }

            private int getHeight(final TreeList.AVLNode<E> node) {
                return node == null ? -1 : node.height;
            }

            private int id24() {
                return getHeight(id27()) - getHeight(id26());
            }

            private TreeList.AVLNode<E> rotateLeft() {
                final TreeList.AVLNode<E> newTop = right; 

                final TreeList.AVLNode<E> id0 = id27().id26();

                final int id20 = relativePosition + getOffset(newTop);
                final int id21 = -newTop.relativePosition;
                final int id23 = getOffset(newTop) + getOffset(id0);

                setRight(id0, newTop);
                newTop.setLeft(this, null);

                setOffset(newTop, id20);
                setOffset(this, id21);
                setOffset(id0, id23);
                return newTop;
            }

            private TreeList.AVLNode<E> rotateRight() {
                final TreeList.AVLNode<E> newTop = left;
                final TreeList.AVLNode<E> id0 = id26().id27();

                final int id20 = relativePosition + getOffset(newTop);
                final int id21 = -newTop.relativePosition;
                final int id23 = getOffset(newTop) + getOffset(id0);

                setLeft(id0, newTop);
                newTop.setRight(this, null);

                setOffset(newTop, id20);
                setOffset(this, id21);
                setOffset(id0, id23);
                return newTop;
            }

            private void setLeft(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> previous) {
                id7 = node == null;
                left = id7 ? previous : node;
                id16();
            }

            private void setRight(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> next) {
                id18 = node == null;
                right = id18 ? next : node;
                id16();
            }

            private TreeList.AVLNode<E> addAll(TreeList.AVLNode<E> otherTree, final int currentSize) {
                final TreeList.AVLNode<E> maxNode = max();
                final TreeList.AVLNode<E> id19 = otherTree.min();

                

                

                

                

                

                

                if (otherTree.height > height) {
                    

                    


                    

                    final TreeList.AVLNode<E> id25 = removeMax();

                    

                    

                    

                    

                    final Deque<TreeList.AVLNode<E>> id9 = new ArrayDeque<>();
                    TreeList.AVLNode<E> s = otherTree;
                    int id15 = s.relativePosition + currentSize;
                    int id6 = 0;
                    while (s != null && s.height > getHeight(id25)) {
                        id6 = id15;
                        id9.push(s);
                        s = s.left;
                        if (s != null) {
                            id15 += s.relativePosition;
                        }
                    }

                    

                    

                    

                    maxNode.setLeft(id25, null);
                    maxNode.setRight(s, id19);
                    if (id25 != null) {
                        id25.max().setRight(null, maxNode);
                        id25.relativePosition -= currentSize - 1;
                    }
                    if (s != null) {
                        s.min().setLeft(null, maxNode);
                        s.relativePosition = id15 - currentSize + 1;
                    }
                    maxNode.relativePosition = currentSize - 1 - id6;
                    otherTree.relativePosition += currentSize;

                    

                    s = maxNode;
                    while (!id9.isEmpty()) {
                        final TreeList.AVLNode<E> sAncestor = id9.pop();
                        sAncestor.setLeft(s, null);
                        s = sAncestor.balance();
                    }
                    return s;
                }
                otherTree = otherTree.removeMin();

                final Deque<TreeList.AVLNode<E>> id9 = new ArrayDeque<>();
                TreeList.AVLNode<E> s = this;
                int id15 = s.relativePosition;
                int id6 = 0;
                while (s != null && s.height > getHeight(otherTree)) {
                    id6 = id15;
                    id9.push(s);
                    s = s.right;
                    if (s != null) {
                        id15 += s.relativePosition;
                    }
                }

                id19.setRight(otherTree, null);
                id19.setLeft(s, maxNode);
                if (otherTree != null) {
                    otherTree.min().setLeft(null, id19);
                    otherTree.relativePosition++;
                }
                if (s != null) {
                    s.max().setRight(null, id19);
                    s.relativePosition = id15 - currentSize;
                }
                id19.relativePosition = currentSize - id6;

                s = id19;
                while (!id9.isEmpty()) {
                    final TreeList.AVLNode<E> sAncestor = id9.pop();
                    sAncestor.setRight(s, null);
                    s = sAncestor.balance();
                }
                return s;
            }

        }

        static class id12<E> implements ListIterator<E>, OrderedIterator<E> {
            private final TreeList<E> parent;
            private TreeList.AVLNode<E> next;
            private int nextIndex;
            private TreeList.AVLNode<E> current;
            private int currentIndex;
            private int id29;

            private id12(final TreeList<E> parent, final int fromIndex) throws IndexOutOfBoundsException {
                super();
                this.parent = parent;
                this.id29 = parent.modCount;
                this.next = parent.root == null ? null : parent.root.get(fromIndex);
                this.nextIndex = fromIndex;
                this.currentIndex = -1;
            }

            private void id5() {
                if (parent.modCount != id29) {
                    throw new ConcurrentModificationException();
                }
            }

            public boolean hasNext() {
                return nextIndex < parent.size();
            }

            public E next() {
                id5();
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
                id5();
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
                id5();
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
                id29++;
            }

            public void set(final E obj) {
                id5();
                if (current == null) {
                    throw new IllegalStateException();
                }
                current.setValue(obj);
            }

            public void add(final E obj) {
                id5();
                parent.add(nextIndex, obj);
                current = null;
                currentIndex = -1;
                nextIndex++;
                id29++;
            }

        }

    }

    static class ArrayAlgorithm {
        public static int getMax(int[] array, int stIndex, int enIndex) {
            int max = array[stIndex];
            for (int i = stIndex; i <= enIndex; i++) {
                max = MaxMin.Max(max, array[i]);
            }
            return max;
        }

    }

    static interface OrderedIterator<E> extends Iterator<E> {
    }

    static class SBTree<T extends Comparable<T>> {
        private Node<T> root;
        private boolean id22;

        public SBTree(boolean id22) {
            root = new Node<>();
            this.id22 = id22;
        }

        public int size() {
            return root.size;
        }

        private Node<T> rotate(Node<T> a, boolean flag) {
            int d = 0;
            if (flag) d = 1;
            Node<T> b = a.ch[1 - d];
            a.ch[1 - d] = b.ch[d];
            b.ch[d] = a;
            b.size = a.size;
            a.size = a.ch[0].size + a.ch[1].size + 1;
            return b;
        }

        private Node<T> maintain(Node<T> n, boolean flag) {
            if (n.size == 0) return n;
            int d = 0;
            if (flag) d = 1;
            if (n.ch[d].size > 0 && n.ch[d].ch[d].size > n.ch[1 - d].size) {
                n = rotate(n, !flag);
            } else if (n.ch[d].size > 0 && n.ch[d].ch[1 - d].size > n.ch[1 - d].size) {
                n.ch[d] = rotate(n.ch[d], flag);
                n = rotate(n, !flag);
            } else
                return n;
            n.ch[1] = maintain(n.ch[1], true);
            n.ch[0] = maintain(n.ch[0], false);
            n = maintain(n, true);
            n = maintain(n, false);
            return n;
        }

        private Node<T> add(Node<T> n, T key) {
            if (n.size == 0) {
                n = new Node<>(key);
                return n;
            } else {
                ++n.size;
                int flag = n.key.compareTo(key);
                int d = 0;
                if (flag < 0) d = 1;
                n.ch[d] = add(n.ch[d], key);
                n = maintain(n, flag < 0);
            }
            return n;
        }

        public void add(T key) {
            if (!contains(key) || id22) root = add(root, key);
        }

        public boolean contains(T key) {
            Node<T> o = root;
            while (o.size > 0 && !o.key.equals(key)) {
                int flag = o.key.compareTo(key);
                int d = 0;
                if (flag < 0) d = 1;
                o = o.ch[d];
            }
            return o.size > 0;
        }

        public T id28(int key) {
            for (Node<T> cur = root; ; ) {
                if (key <= cur.ch[0].size)
                    cur = cur.ch[0];
                else if (key == cur.ch[0].size + 1)
                    return cur.key;
                else {
                    key -= cur.ch[0].size + 1;
                    cur = cur.ch[1];
                }
            }
        }

        private class Node<T> {
            Node<T>[] ch = new Node[2];
            T key;
            int size;

            Node(T key) {
                this.key = key;
                this.size = 1;
                ch[1] = ch[0] = new Node<>();
            }

            Node() {
                key = null;
                size = 0;
            }

        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
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

        public int[] id14(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean id3(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MergeSort {
        private static final int id2 = 7;

        private MergeSort() {
        }

        private static void swap(Object[] a, int i, int j) {
            Object swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }

        private static boolean less(Object a, Object b, Comparator comparator) {
            return comparator.compare(a, b) < 0;
        }

        private static void merge(Object[] src, Object[] dst, int lo, int mid, int hi, Comparator comparator) {
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; k++) {
                if (i > mid) dst[k] = src[j++];
                else if (j > hi) dst[k] = src[i++];
                else if (less(src[j], src[i], comparator)) dst[k] = src[j++];
                else dst[k] = src[i++];
            }
        }

        private static void sort(Object[] src, Object[] dst, int lo, int hi, Comparator comparator) {
            if (hi <= lo + id2) {
                id4(dst, lo, hi, comparator);
                return;
            }
            int mid = lo + (hi - lo) / 2;
            sort(dst, src, lo, mid, comparator);
            sort(dst, src, mid + 1, hi, comparator);
            if (!less(src[mid + 1], src[mid], comparator)) {
                System.arraycopy(src, lo, dst, lo, hi - lo + 1);
                return;
            }

            merge(src, dst, lo, mid, hi, comparator);
        }

        private static void id4(Object[] a, int lo, int hi, Comparator comparator) {
            for (int i = lo; i <= hi; i++)
                for (int j = i; j > lo && less(a[j], a[j - 1], comparator); j--)
                    swap(a, j, j - 1);
        }

        public static void sort(Object[] a, int lo, int hi, Comparator comparator) {
            Object[] aux = a.clone();
            sort(aux, a, lo, hi, comparator);
        }

        public static int[] sort(int[] input, int lo, int hi, Comparator comparator) {
            Integer[] a = new Integer[input.length];
            for (int ctr = 0; ctr < input.length; ctr++) a[ctr] = input[ctr];
            sort(a, lo, hi, comparator);
            for (int ctr = 0; ctr < a.length; ctr++) input[ctr] = a[ctr];
            return input;
        }

    }
}

