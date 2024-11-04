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
        FMaximumBalancedCircle solver = new FMaximumBalancedCircle();
        solver.solve(1, in, out);
        out.close();
    }

    static class FMaximumBalancedCircle {
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
            a = in.nextIntArray(n, 1);
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
            while (isSpaceChar(c))
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
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class ArrayAlgorithm {
        public static void shuffleArray(int[] array, int stIndex, int enIndex) {
            for (int i = enIndex; i > stIndex; i--) {
                int index = (int) OneNumberGen.genInt(stIndex, i - 1);
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

    static class OneNumberGen {
        private static long genI(long min, long max) {
            return ThreadLocalRandom.current().nextLong(min, max + 1);
        }

        public static long genInt(long min, long max) {
            if (min >= 0)
                return (genI(min, max));
            else if (max >= 0) {
                double ratio = (double) Math.abs(min) / (Math.abs(min) + max);
                ratio *= 1000000000000000000D;
                double prob = (double) (OneNumberGen.genInt(1, 1000000000000000000L));
                if (Double.compare(ratio, prob) > 0) {
                    return -(genI(0, -min));
                } else {
                    return (genI(0, max));
                }
            } else
                return -(OneNumberGen.genI(-min, -max));
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
            return new TreeList.TreeListIterator<>(this, fromIndex);
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
            private boolean leftIsPrevious;
            private TreeList.AVLNode<E> right;
            private boolean rightIsNext;
            private int height;
            private int relativePosition;
            private E value;

            private AVLNode(final int relativePosition, final E obj,
                            final TreeList.AVLNode<E> rightFollower, final TreeList.AVLNode<E> leftFollower) {
                this.relativePosition = relativePosition;
                value = obj;
                rightIsNext = true;
                leftIsPrevious = true;
                right = rightFollower;
                left = leftFollower;
            }

            private AVLNode(final Collection<? extends E> coll) {
                this(coll.iterator(), 0, coll.size() - 1, 0, null, null);
            }

            private AVLNode(final Iterator<? extends E> iterator, final int start, final int end,
                            final int absolutePositionOfParent, final TreeList.AVLNode<E> prev, final TreeList.AVLNode<E> next) {
                final int mid = start + (end - start) / 2;
                if (start < mid) {
                    left = new TreeList.AVLNode<>(iterator, start, mid - 1, mid, prev, this);
                } else {
                    leftIsPrevious = true;
                    left = prev;
                }
                value = iterator.next();
                relativePosition = mid - absolutePositionOfParent;
                if (mid < end) {
                    right = new TreeList.AVLNode<>(iterator, mid + 1, end, mid, this, next);
                } else {
                    rightIsNext = true;
                    right = next;
                }
                recalcHeight();
            }

            E getValue() {
                return value;
            }

            void setValue(final E obj) {
                this.value = obj;
            }

            TreeList.AVLNode<E> get(final int index) {
                final int indexRelativeToMe = index - relativePosition;

                if (indexRelativeToMe == 0) {
                    return this;
                }

                final TreeList.AVLNode<E> nextNode = indexRelativeToMe < 0 ? getLeftSubTree() : getRightSubTree();
                if (nextNode == null) {
                    return null;
                }
                return nextNode.get(indexRelativeToMe);
            }

            int indexOf(final Object object, final int index) {
                if (getLeftSubTree() != null) {
                    final int result = left.indexOf(object, index + left.relativePosition);
                    if (result != -1) {
                        return result;
                    }
                }
                if (value == null ? value == object : value.equals(object)) {
                    return index;
                }
                if (getRightSubTree() != null) {
                    return right.indexOf(object, index + right.relativePosition);
                }
                return -1;
            }

            void toArray(final Object[] array, final int index) {
                array[index] = value;
                if (getLeftSubTree() != null) {
                    left.toArray(array, index + left.relativePosition);
                }
                if (getRightSubTree() != null) {
                    right.toArray(array, index + right.relativePosition);
                }
            }

            TreeList.AVLNode<E> next() {
                if (rightIsNext || right == null) {
                    return right;
                }
                return right.min();
            }

            TreeList.AVLNode<E> previous() {
                if (leftIsPrevious || left == null) {
                    return left;
                }
                return left.max();
            }

            TreeList.AVLNode<E> insert(final int index, final E obj) {
                final int indexRelativeToMe = index - relativePosition;

                if (indexRelativeToMe <= 0) {
                    return insertOnLeft(indexRelativeToMe, obj);
                }
                return insertOnRight(indexRelativeToMe, obj);
            }

            private TreeList.AVLNode<E> insertOnLeft(final int indexRelativeToMe, final E obj) {
                if (getLeftSubTree() == null) {
                    setLeft(new TreeList.AVLNode<>(-1, obj, this, left), null);
                } else {
                    setLeft(left.insert(indexRelativeToMe, obj), null);
                }

                if (relativePosition >= 0) {
                    relativePosition++;
                }
                final TreeList.AVLNode<E> ret = balance();
                recalcHeight();
                return ret;
            }

            private TreeList.AVLNode<E> insertOnRight(final int indexRelativeToMe, final E obj) {
                if (getRightSubTree() == null) {
                    setRight(new TreeList.AVLNode<>(+1, obj, right, this), null);
                } else {
                    setRight(right.insert(indexRelativeToMe, obj), null);
                }
                if (relativePosition < 0) {
                    relativePosition--;
                }
                final TreeList.AVLNode<E> ret = balance();
                recalcHeight();
                return ret;
            }

            private TreeList.AVLNode<E> getLeftSubTree() {
                return leftIsPrevious ? null : left;
            }

            private TreeList.AVLNode<E> getRightSubTree() {
                return rightIsNext ? null : right;
            }

            private TreeList.AVLNode<E> max() {
                return getRightSubTree() == null ? this : right.max();
            }

            private TreeList.AVLNode<E> min() {
                return getLeftSubTree() == null ? this : left.min();
            }

            TreeList.AVLNode<E> remove(final int index) {
                final int indexRelativeToMe = index - relativePosition;

                if (indexRelativeToMe == 0) {
                    return removeSelf();
                }
                if (indexRelativeToMe > 0) {
                    setRight(right.remove(indexRelativeToMe), right.right);
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    setLeft(left.remove(indexRelativeToMe), left.left);
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                recalcHeight();
                return balance();
            }

            private TreeList.AVLNode<E> removeMax() {
                if (getRightSubTree() == null) {
                    return removeSelf();
                }
                setRight(right.removeMax(), right.right);
                if (relativePosition < 0) {
                    relativePosition++;
                }
                recalcHeight();
                return balance();
            }

            private TreeList.AVLNode<E> removeMin() {
                if (getLeftSubTree() == null) {
                    return removeSelf();
                }
                setLeft(left.removeMin(), left.left);
                if (relativePosition > 0) {
                    relativePosition--;
                }
                recalcHeight();
                return balance();
            }

            private TreeList.AVLNode<E> removeSelf() {
                if (getRightSubTree() == null && getLeftSubTree() == null) {
                    return null;
                }
                if (getRightSubTree() == null) {
                    if (relativePosition > 0) {
                        left.relativePosition += relativePosition;
                    }
                    left.max().setRight(null, right);
                    return left;
                }
                if (getLeftSubTree() == null) {
                    right.relativePosition += relativePosition - (relativePosition < 0 ? 0 : 1);
                    right.min().setLeft(null, left);
                    return right;
                }

                if (heightRightMinusLeft() > 0) {
                    

                    final TreeList.AVLNode<E> rightMin = right.min();
                    value = rightMin.value;
                    if (leftIsPrevious) {
                        left = rightMin.left;
                    }
                    right = right.removeMin();
                    if (relativePosition < 0) {
                        relativePosition++;
                    }
                } else {
                    

                    final TreeList.AVLNode<E> leftMax = left.max();
                    value = leftMax.value;
                    if (rightIsNext) {
                        right = leftMax.right;
                    }
                    final TreeList.AVLNode<E> leftPrevious = left.left;
                    left = left.removeMax();
                    if (left == null) {
                        

                        

                        left = leftPrevious;
                        leftIsPrevious = true;
                    }
                    if (relativePosition > 0) {
                        relativePosition--;
                    }
                }
                recalcHeight();
                return this;
            }

            private TreeList.AVLNode<E> balance() {
                switch (heightRightMinusLeft()) {
                    case 1:
                    case 0:
                    case -1:
                        return this;
                    case -2:
                        if (left.heightRightMinusLeft() > 0) {
                            setLeft(left.rotateLeft(), null);
                        }
                        return rotateRight();
                    case 2:
                        if (right.heightRightMinusLeft() < 0) {
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

            private int setOffset(final TreeList.AVLNode<E> node, final int newOffest) {
                if (node == null) {
                    return 0;
                }
                final int oldOffset = getOffset(node);
                node.relativePosition = newOffest;
                return oldOffset;
            }

            private void recalcHeight() {
                height = Math.max(
                        getLeftSubTree() == null ? -1 : getLeftSubTree().height,
                        getRightSubTree() == null ? -1 : getRightSubTree().height) + 1;
            }

            private int getHeight(final TreeList.AVLNode<E> node) {
                return node == null ? -1 : node.height;
            }

            private int heightRightMinusLeft() {
                return getHeight(getRightSubTree()) - getHeight(getLeftSubTree());
            }

            private TreeList.AVLNode<E> rotateLeft() {
                final TreeList.AVLNode<E> newTop = right; 

                final TreeList.AVLNode<E> movedNode = getRightSubTree().getLeftSubTree();

                final int newTopPosition = relativePosition + getOffset(newTop);
                final int myNewPosition = -newTop.relativePosition;
                final int movedPosition = getOffset(newTop) + getOffset(movedNode);

                setRight(movedNode, newTop);
                newTop.setLeft(this, null);

                setOffset(newTop, newTopPosition);
                setOffset(this, myNewPosition);
                setOffset(movedNode, movedPosition);
                return newTop;
            }

            private TreeList.AVLNode<E> rotateRight() {
                final TreeList.AVLNode<E> newTop = left;
                final TreeList.AVLNode<E> movedNode = getLeftSubTree().getRightSubTree();

                final int newTopPosition = relativePosition + getOffset(newTop);
                final int myNewPosition = -newTop.relativePosition;
                final int movedPosition = getOffset(newTop) + getOffset(movedNode);

                setLeft(movedNode, newTop);
                newTop.setRight(this, null);

                setOffset(newTop, newTopPosition);
                setOffset(this, myNewPosition);
                setOffset(movedNode, movedPosition);
                return newTop;
            }

            private void setLeft(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> previous) {
                leftIsPrevious = node == null;
                left = leftIsPrevious ? previous : node;
                recalcHeight();
            }

            private void setRight(final TreeList.AVLNode<E> node, final TreeList.AVLNode<E> next) {
                rightIsNext = node == null;
                right = rightIsNext ? next : node;
                recalcHeight();
            }

            private TreeList.AVLNode<E> addAll(TreeList.AVLNode<E> otherTree, final int currentSize) {
                final TreeList.AVLNode<E> maxNode = max();
                final TreeList.AVLNode<E> otherTreeMin = otherTree.min();

                

                

                

                

                

                

                if (otherTree.height > height) {
                    

                    


                    

                    final TreeList.AVLNode<E> leftSubTree = removeMax();

                    

                    

                    

                    

                    final Deque<TreeList.AVLNode<E>> sAncestors = new ArrayDeque<>();
                    TreeList.AVLNode<E> s = otherTree;
                    int sAbsolutePosition = s.relativePosition + currentSize;
                    int sParentAbsolutePosition = 0;
                    while (s != null && s.height > getHeight(leftSubTree)) {
                        sParentAbsolutePosition = sAbsolutePosition;
                        sAncestors.push(s);
                        s = s.left;
                        if (s != null) {
                            sAbsolutePosition += s.relativePosition;
                        }
                    }

                    

                    

                    

                    maxNode.setLeft(leftSubTree, null);
                    maxNode.setRight(s, otherTreeMin);
                    if (leftSubTree != null) {
                        leftSubTree.max().setRight(null, maxNode);
                        leftSubTree.relativePosition -= currentSize - 1;
                    }
                    if (s != null) {
                        s.min().setLeft(null, maxNode);
                        s.relativePosition = sAbsolutePosition - currentSize + 1;
                    }
                    maxNode.relativePosition = currentSize - 1 - sParentAbsolutePosition;
                    otherTree.relativePosition += currentSize;

                    

                    s = maxNode;
                    while (!sAncestors.isEmpty()) {
                        final TreeList.AVLNode<E> sAncestor = sAncestors.pop();
                        sAncestor.setLeft(s, null);
                        s = sAncestor.balance();
                    }
                    return s;
                }
                otherTree = otherTree.removeMin();

                final Deque<TreeList.AVLNode<E>> sAncestors = new ArrayDeque<>();
                TreeList.AVLNode<E> s = this;
                int sAbsolutePosition = s.relativePosition;
                int sParentAbsolutePosition = 0;
                while (s != null && s.height > getHeight(otherTree)) {
                    sParentAbsolutePosition = sAbsolutePosition;
                    sAncestors.push(s);
                    s = s.right;
                    if (s != null) {
                        sAbsolutePosition += s.relativePosition;
                    }
                }

                otherTreeMin.setRight(otherTree, null);
                otherTreeMin.setLeft(s, maxNode);
                if (otherTree != null) {
                    otherTree.min().setLeft(null, otherTreeMin);
                    otherTree.relativePosition++;
                }
                if (s != null) {
                    s.max().setRight(null, otherTreeMin);
                    s.relativePosition = sAbsolutePosition - currentSize;
                }
                otherTreeMin.relativePosition = currentSize - sParentAbsolutePosition;

                s = otherTreeMin;
                while (!sAncestors.isEmpty()) {
                    final TreeList.AVLNode<E> sAncestor = sAncestors.pop();
                    sAncestor.setRight(s, null);
                    s = sAncestor.balance();
                }
                return s;
            }

        }

        static class TreeListIterator<E> implements ListIterator<E>, OrderedIterator<E> {
            private final TreeList<E> parent;
            private TreeList.AVLNode<E> next;
            private int nextIndex;
            private TreeList.AVLNode<E> current;
            private int currentIndex;
            private int expectedModCount;

            private TreeListIterator(final TreeList<E> parent, final int fromIndex) throws IndexOutOfBoundsException {
                super();
                this.parent = parent;
                this.expectedModCount = parent.modCount;
                this.next = parent.root == null ? null : parent.root.get(fromIndex);
                this.nextIndex = fromIndex;
                this.currentIndex = -1;
            }

            private void checkModCount() {
                if (parent.modCount != expectedModCount) {
                    throw new ConcurrentModificationException();
                }
            }

            public boolean hasNext() {
                return nextIndex < parent.size();
            }

            public E next() {
                checkModCount();
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
                checkModCount();
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
                checkModCount();
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
                expectedModCount++;
            }

            public void set(final E obj) {
                checkModCount();
                if (current == null) {
                    throw new IllegalStateException();
                }
                current.setValue(obj);
            }

            public void add(final E obj) {
                checkModCount();
                parent.add(nextIndex, obj);
                current = null;
                currentIndex = -1;
                nextIndex++;
                expectedModCount++;
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

