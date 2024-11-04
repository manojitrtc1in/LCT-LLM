import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.Collection;
import java.util.AbstractList;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Deque;
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
        id10 solver = new id10();
        solver.solve(1, in, out);
        out.close();
    }

    static class id10 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            if (n == 3) {
                out.println("1 1 3");
                return;
            }
            if (n == 2) {
                out.println("1 2");
                return;
            }
            if (n == 1) {
                out.println(1);
                return;
            }
            TreeList<Integer> tree = new TreeList<>();
            for (int i = 1; i <= n; i++) tree.add(i);
            int cur = 2;
            while (tree.size() > 0) {
                if (tree.get(tree.size() - 1) < cur * 2) {
                    if (tree.size() == 1) {
                        out.print(tree.get(0));
                        break;
                    }
                    out.print(cur / 2 + " ");
                    tree.remove(0);
                    continue;
                }
                int last = tree.size();
                for (int i = 0; i < tree.size(); i++) {
                    if (tree.get(i) % cur != 0) {
                        tree.remove(i);
                        i--;
                    }
                }
                for (int i = 1; i <= last - tree.size(); i++) {
                    out.print(cur / 2 + " ");
                }
                cur *= 2;
            }
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
            return new TreeList.id9<>(this, fromIndex);
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
            private boolean id5;
            private TreeList.AVLNode<E> right;
            private boolean id15;
            private int height;
            private int relativePosition;
            private E value;

            private AVLNode(final int relativePosition, final E obj,
                            final TreeList.AVLNode<E> rightFollower, final TreeList.AVLNode<E> leftFollower) {
                this.relativePosition = relativePosition;
                value = obj;
                id15 = true;
                id5 = true;
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
                    id5 = true;
                    left = prev;
                }
                value = iterator.next();
                relativePosition = mid - id11;
                if (mid < end) {
                    right = new TreeList.AVLNode<>(iterator, mid + 1, end, mid, this, next);
                } else {
                    id15 = true;
                    right = next;
                }
                id13();
            }

            E getValue() {
                return value;
            }

            void setValue(final E obj) {
                this.value = obj;
            }

            TreeList.AVLNode<E> get(final int index) {
                final int id14 = index - relativePosition;

                if (id14 == 0) {
                    return this;
                }

                final TreeList.AVLNode<E> nextNode = id14 < 0 ? id22() : id23();
                if (nextNode == null) {
                    return null;
                }
                return nextNode.get(id14);
            }

            int indexOf(final Object object, final int index) {
                if (id22() != null) {
                    final int result = left.indexOf(object, index + left.relativePosition);
                    if (result != -1) {
                        return result;
                    }
                }
                if (value == null ? value == object : value.equals(object)) {
                    return index;
                }
                if (id23() != null) {
                    return right.indexOf(object, index + right.relativePosition);
                }
                return -1;
            }

            void toArray(final Object[] array, final int index) {
                array[index] = value;
                if (id22() != null) {
                    left.toArray(array, index + left.relativePosition);
                }
                if (id23() != null) {
                    right.toArray(array, index + right.relativePosition);
                }
            }

            TreeList.AVLNode<E> next() {
                if (id15 || right == null) {
                    return right;
                }
                return right.min();
            }

            TreeList.AVLNode<E> previous() {
                if (id5 || left == null) {
                    return left;
                }
                return left.max();
            }

            TreeList.AVLNode<E> insert(final int index, final E obj) {
                final int id14 = index - relativePosition;

                if (id14 <= 0) {
                    return id1(id14, obj);
                }
                return id8(id14, obj);
            }

            private TreeList.AVLNode<E> id1(final int id14, final E obj) {
                if (id22() == null) {
                    setLeft(new TreeList.AVLNode<>(-1, obj, this, left), null);
                } else {
                    setLeft(left.insert(id14, obj), null);
                }

                if (relativePosition >= 0) {
                    relativePosition++;
                }
                final TreeList.AVLNode<E> ret = balance();
                id13();
                return ret;
            }

            private TreeList.AVLNode<E> id8(final int id14, final E obj) {
                if (id23() == null) {
                    setRight(new TreeList.AVLNode<>(+1, obj, right, this), null);
                } else {
                    setRight(right.insert(id14, obj), null);
                }
                if (relativePosition < 0) {
                    relativePosition--;
                }
                final TreeList.AVLNode<E> ret = balance();
                id13();
                return ret;
            }

            private TreeList.AVLNode<E> id22() {
                return id5 ? null : left;
            }

            private TreeList.AVLNode<E> id23() {
                return id15 ? null : right;
            }

            private TreeList.AVLNode<E> max() {
                return id23() == null ? this : right.max();
            }

            private TreeList.AVLNode<E> min() {
                return id22() == null ? this : left.min();
            }

            TreeList.AVLNode<E> remove(final int index) {
                final int id14 = index - relativePosition;

                if (id14 == 0) {
                    return removeSelf();
                }
                if (id14 > 0) {
                    setRight(right.remove(id14), right.right);
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    setLeft(left.remove(id14), left.left);
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                id13();
                return balance();
            }

            private TreeList.AVLNode<E> removeMax() {
                if (id23() == null) {
                    return removeSelf();
                }
                setRight(right.removeMax(), right.right);
                if (relativePosition < 0) {
                    relativePosition++;
                }
                id13();
                return balance();
            }

            private TreeList.AVLNode<E> removeMin() {
                if (id22() == null) {
                    return removeSelf();
                }
                setLeft(left.removeMin(), left.left);
                if (relativePosition > 0) {
                    relativePosition--;
                }
                id13();
                return balance();
            }

            private TreeList.AVLNode<E> removeSelf() {
                if (id23() == null && id22() == null) {
                    return null;
                }
                if (id23() == null) {
                    if (relativePosition > 0) {
                        left.relativePosition += relativePosition;
                    }
                    left.max().setRight(null, right);
                    return left;
                }
                if (id22() == null) {
                    right.relativePosition += relativePosition - (relativePosition < 0 ? 0 : 1);
                    right.min().setLeft(null, left);
                    return right;
                }

                if (id20() > 0) {
                    

                    final TreeList.AVLNode<E> rightMin = right.min();
                    value = rightMin.value;
                    if (id5) {
                        left = rightMin.left;
                    }
                    right = right.removeMin();
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    

                    final TreeList.AVLNode<E> leftMax = left.max();
                    value = leftMax.value;
                    if (id15) {
                        right = leftMax.right;
                    }
                    final TreeList.AVLNode<E> leftPrevious = left.left;
                    left = left.removeMax();
                    if (left == null) {
                        

                        

                        left = leftPrevious;
                        id5 = true;
                    }
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                id13();
                return this;
            }

            private TreeList.AVLNode<E> balance() {
                switch (id20()) {
                    case 1:
                    case 0:
                    case -1:
                        return this;
                    case -2:
                        if (left.id20() > 0) {
                            setLeft(left.rotateLeft(), null);
                        }
                        return rotateRight();
                    case 2:
                        if (right.id20() < 0) {
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

            private int setOffset(final TreeList.AVLNode<E> node, final int id6) {
                if (node == null) {
                    return 0;
                }
                final int oldOffset = getOffset(node);
                node.relativePosition = id6;
                return oldOffset;
            }

            private void id13() {
                height = Math.max(
                        id22() == null ? -1 : id22().height,
                        id23() == null ? -1 : id23().height) + 1;
            }

            private int getHeight(final TreeList.AVLNode<E> node) {
                return node == null ? -1 : node.height;
            }

            private int id20() {
                return getHeight(id23()) - getHeight(id22());
            }

            private TreeList.AVLNode<E> rotateLeft() {
                final TreeList.AVLNode<E> newTop = right; 

                final TreeList.AVLNode<E> id0 = id23().id22();

                final int id17 = relativePosition + getOffset(newTop);
                final int id18 = -newTop.relativePosition;
                final int id19 = getOffset(newTop) + getOffset(id0);

                setRight(id0, newTop);
                newTop.setLeft(this, null);

                setOffset(newTop, id17);
                setOffset(this, id18);
                setOffset(id0, id19);
                return newTop;
            }

            private TreeList.AVLNode<E> rotateRight() {
                final TreeList.AVLNode<E> newTop = left;
                final TreeList.AVLNode<E> id0 = id22().id23();

                final int id17 = relativePosition + getOffset(newTop);
                final int id18 = -newTop.relativePosition;
                final int id19 = getOffset(newTop) + getOffset(id0);

                setLeft(id0, newTop);
                newTop.setRight(this, null);

                setOffset(newTop, id17);
                setOffset(this, id18);
                setOffset(id0, id19);
                return newTop;
            }

            private void setLeft(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> previous) {
                id5 = node == null;
                left = id5 ? previous : node;
                id13();
            }

            private void setRight(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> next) {
                id15 = node == null;
                right = id15 ? next : node;
                id13();
            }

            private TreeList.AVLNode<E> addAll(TreeList.AVLNode<E> otherTree, final int currentSize) {
                final TreeList.AVLNode<E> maxNode = max();
                final TreeList.AVLNode<E> id16 = otherTree.min();

                

                

                

                

                

                

                if (otherTree.height > height) {
                    

                    


                    

                    final TreeList.AVLNode<E> id21 = removeMax();

                    

                    

                    

                    

                    final Deque<TreeList.AVLNode<E>> id7 = new ArrayDeque<>();
                    TreeList.AVLNode<E> s = otherTree;
                    int id12 = s.relativePosition + currentSize;
                    int id4 = 0;
                    while (s != null && s.height > getHeight(id21)) {
                        id4 = id12;
                        id7.push(s);
                        s = s.left;
                        if (s != null) {
                            id12 += s.relativePosition;
                        }
                    }

                    

                    

                    

                    maxNode.setLeft(id21, null);
                    maxNode.setRight(s, id16);
                    if (id21 != null) {
                        id21.max().setRight(null, maxNode);
                        id21.relativePosition -= currentSize - 1;
                    }
                    if (s != null) {
                        s.min().setLeft(null, maxNode);
                        s.relativePosition = id12 - currentSize + 1;
                    }
                    maxNode.relativePosition = currentSize - 1 - id4;
                    otherTree.relativePosition += currentSize;

                    

                    s = maxNode;
                    while (!id7.isEmpty()) {
                        final TreeList.AVLNode<E> sAncestor = id7.pop();
                        sAncestor.setLeft(s, null);
                        s = sAncestor.balance();
                    }
                    return s;
                }
                otherTree = otherTree.removeMin();

                final Deque<TreeList.AVLNode<E>> id7 = new ArrayDeque<>();
                TreeList.AVLNode<E> s = this;
                int id12 = s.relativePosition;
                int id4 = 0;
                while (s != null && s.height > getHeight(otherTree)) {
                    id4 = id12;
                    id7.push(s);
                    s = s.right;
                    if (s != null) {
                        id12 += s.relativePosition;
                    }
                }

                id16.setRight(otherTree, null);
                id16.setLeft(s, maxNode);
                if (otherTree != null) {
                    otherTree.min().setLeft(null, id16);
                    otherTree.relativePosition++;
                }
                if (s != null) {
                    s.max().setRight(null, id16);
                    s.relativePosition = id12 - currentSize;
                }
                id16.relativePosition = currentSize - id4;

                s = id16;
                while (!id7.isEmpty()) {
                    final TreeList.AVLNode<E> sAncestor = id7.pop();
                    sAncestor.setRight(s, null);
                    s = sAncestor.balance();
                }
                return s;
            }

        }

        static class id9<E> implements ListIterator<E>, OrderedIterator<E> {
            private final TreeList<E> parent;
            private TreeList.AVLNode<E> next;
            private int nextIndex;
            private TreeList.AVLNode<E> current;
            private int currentIndex;
            private int id24;

            private id9(final TreeList<E> parent, final int fromIndex) throws IndexOutOfBoundsException {
                super();
                this.parent = parent;
                this.id24 = parent.modCount;
                this.next = parent.root == null ? null : parent.root.get(fromIndex);
                this.nextIndex = fromIndex;
                this.currentIndex = -1;
            }

            private void id3() {
                if (parent.modCount != id24) {
                    throw new ConcurrentModificationException();
                }
            }

            public boolean hasNext() {
                return nextIndex < parent.size();
            }

            public E next() {
                id3();
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
                id3();
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
                id3();
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
                id24++;
            }

            public void set(final E obj) {
                id3();
                if (current == null) {
                    throw new IllegalStateException();
                }
                current.setValue(obj);
            }

            public void add(final E obj) {
                id3();
                parent.add(nextIndex, obj);
                current = null;
                currentIndex = -1;
                nextIndex++;
                id24++;
            }

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
            while (id2(c))
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
            } while (!id2(c));
            return res * sgn;
        }

        private static boolean id2(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static interface OrderedIterator<E> extends Iterator<E> {
    }
}

