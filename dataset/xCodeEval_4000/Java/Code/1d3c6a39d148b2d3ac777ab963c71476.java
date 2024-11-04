import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedOutputStream;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] str = in.nextLine().toCharArray();
            EzCharTreeList list = new EzCharTreeList(str);
            for (int i = 0; i < list.size() - 1; i++)
                if (list.get(i) == ',') {
                    while (list.get(i + 1) == ' ') list.removeAt(i + 1);
                    list.insert(i + 1, ' ');
                }
            int c = 0;
            for (int i = 0; i < list.size(); i++)
                if (list.get(i) == '.' && ++c % 3 == 0) {
                    if (i < 3) continue;
                    while (list.get(i - 3) == ' ') list.removeAt(i-- - 3);
                    list.insert(i++ - 2, ' ');
                }
            char last = ' ';
            for (int i = 0; i < list.size(); i++) {
                if (Character.isDigit(list.get(i)) && Character.isDigit(last) && list.get(i - 1) == ' ')
                    while (list.get(i - 2) == ' ') list.removeAt(i-- - 2);
                if (list.get(i) == ',' && (Character.isDigit(last) || last == '.'))
                    while (list.get(i - 1) == ' ') list.removeAt(--i);
                if (Character.isDigit(list.get(i)) && last == '.') while (list.get(i - 1) == ' ') list.removeAt(--i);
                if (list.get(i) != ' ') last = list.get(i);
            }
            String ans = new String(list.toArray());
            out.println(ans);
        }

    }

    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream outputStream) {
            super(new BufferedOutputStream(outputStream));
        }

        public OutputWriter(Writer writer) {
            super(writer);
        }

        public void close() {
            super.close();
        }

    }

    static interface EzCharStack extends EzCharCollection {
        int size();

        EzCharIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzCharDeque extends EzCharQueue, EzCharStack {
        int size();

        EzCharIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class EzCharTreeList implements EzCharList, EzCharDeque {
        private static final int DEFAULT_CAPACITY = 10;
        private static final double ENLARGE_SCALE = 2.0;
        private static final int HASHCODE_INITIAL_VALUE = 0x811c9dc5;
        private static final int HASHCODE_MULTIPLIER = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        private char[] value;
        private int[] subtreeSize;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;

        public EzCharTreeList() {
            this(DEFAULT_CAPACITY);
        }

        public EzCharTreeList(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            capacity++;
            value = new char[capacity];
            subtreeSize = new int[capacity];
            left = new int[capacity];
            right = new int[capacity];
            p = new int[capacity];
            color = new boolean[capacity];
            color[NULL] = BLACK;
            size = 0;
            root = NULL;
        }

        public EzCharTreeList(EzCharCollection collection) {
            this(collection.size());
            for (EzCharIterator iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public EzCharTreeList(char[] srcArray) {
            this(srcArray.length);
            for (char element : srcArray) {
                add(element);
            }
        }

        public EzCharTreeList(Collection<Character> javaCollection) {
            this(javaCollection.size());
            for (char element : javaCollection) {
                add(element);
            }
        }


        public int size() {
            return size;
        }


        public EzCharIterator iterator() {
            return new EzCharTreeListIterator();
        }


        public char[] toArray() {
            char[] result = new char[size];
            for (int i = 0, x = firstNode(); x != NULL; x = successorNode(x), i++) {
                result[i] = value[x];
            }
            return result;
        }


        public boolean add(char element) {
            final int y = lastNode();
            addAsChild(y, false, element);
            return true;
        }

        private void addAsChild(int y, boolean asLeftChild, char element) {
            if (size == color.length - 1) {
                enlarge();
            }
            int z = ++size;
            value[z] = element;
            p[z] = y;
            if (y == NULL) {
                root = z;
            } else {
                if (asLeftChild) {
                    left[y] = z;
                } else {
                    right[y] = z;
                }
            }
            left[z] = NULL;
            right[z] = NULL;
            color[z] = RED;
            subtreeSize[z] = 1;
            for (int w = p[z]; w != NULL; w = p[w]) {
                subtreeSize[w]++;
            }
            fixAfterAdd(z);
        }

        private int kThNode(int k) {
            if (k < 0 || k >= size) {
                throw new IllegalArgumentException("Index " + k + " was passed into kThNode(), size = " + size);
            }
            int x = root;
            while (true) {
                final int leftSize = subtreeSize[left[x]];
                if (k < leftSize) {
                    x = left[x];
                } else if (k > leftSize) {
                    k -= leftSize + 1;
                    x = right[x];
                } else {
                    return x;
                }
            }
        }

        private void removeNode(int z) {
            int y = (left[z] == NULL || right[z] == NULL) ? z : successorNode(z);
            for (int w = y; w != NULL; w = p[w]) {
                subtreeSize[w]--;
            }
            int x = (left[y] != NULL) ? left[y] : right[y];
            p[x] = p[y];
            if (p[y] == NULL) {
                root = x;
            } else {
                if (y == left[p[y]]) {
                    left[p[y]] = x;
                } else {
                    right[p[y]] = x;
                }
            }
            if (y != z) {
                value[z] = value[y];
            }
            

            if (color[y] == BLACK) {
                fixAfterRemove(x);
            }
            

            if (y != size) {
                

                value[y] = value[size];
                subtreeSize[y] = subtreeSize[size];
                left[y] = left[size];
                right[y] = right[size];
                p[y] = p[size];
                color[y] = color[size];
                

                p[left[size]] = y;
                p[right[size]] = y;
                

                if (left[p[size]] == size) {
                    left[p[size]] = y;
                } else {
                    right[p[size]] = y;
                }
                

                if (root == size) {
                    root = y;
                }
            }
            size--;
        }

        private int successorNode(int x) {
            if (right[x] != NULL) {
                x = right[x];
                while (left[x] != NULL) {
                    x = left[x];
                }
                return x;
            } else {
                int y = p[x];
                while (y != NULL && x == right[y]) {
                    

                    x = y;
                    y = p[y];
                }
                return y;
            }
        }

        @SuppressWarnings("PointlessBooleanExpression")
        private void fixAfterAdd(int z) {
            while (color[p[z]] == RED) {
                if (p[z] == left[p[p[z]]]) {
                    int y = right[p[p[z]]];
                    if (color[y] == RED) {
                        color[p[z]] = BLACK;
                        color[y] = BLACK;
                        color[p[p[z]]] = RED;
                        z = p[p[z]];
                    } else {
                        if (z == right[p[z]]) {
                            z = p[z];
                            rotateLeft(z);
                        }
                        color[p[z]] = BLACK;
                        color[p[p[z]]] = RED;
                        rotateRight(p[p[z]]);
                    }
                } else {
                    int y = left[p[p[z]]];
                    if (color[y] == RED) {
                        color[p[z]] = BLACK;
                        color[y] = BLACK;
                        color[p[p[z]]] = RED;
                        z = p[p[z]];
                    } else {
                        if (z == left[p[z]]) {
                            z = p[z];
                            rotateRight(z);
                        }
                        color[p[z]] = BLACK;
                        color[p[p[z]]] = RED;
                        rotateLeft(p[p[z]]);
                    }
                }
            }
            color[root] = BLACK;
        }

        @SuppressWarnings("PointlessBooleanExpression")
        private void fixAfterRemove(int x) {
            while (x != root && color[x] == BLACK) {
                if (x == left[p[x]]) {
                    int w = right[p[x]];
                    if (color[w] == RED) {
                        color[w] = BLACK;
                        color[p[x]] = RED;
                        rotateLeft(p[x]);
                        w = right[p[x]];
                    }
                    if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                        color[w] = RED;
                        x = p[x];
                    } else {
                        if (color[right[w]] == BLACK) {
                            color[left[w]] = BLACK;
                            color[w] = RED;
                            rotateRight(w);
                            w = right[p[x]];
                        }
                        color[w] = color[p[x]];
                        color[p[x]] = BLACK;
                        color[right[w]] = BLACK;
                        rotateLeft(p[x]);
                        x = root;
                    }
                } else {
                    int w = left[p[x]];
                    if (color[w] == RED) {
                        color[w] = BLACK;
                        color[p[x]] = RED;
                        rotateRight(p[x]);
                        w = left[p[x]];
                    }
                    if (color[left[w]] == BLACK && color[right[w]] == BLACK) {
                        color[w] = RED;
                        x = p[x];
                    } else {
                        if (color[left[w]] == BLACK) {
                            color[right[w]] = BLACK;
                            color[w] = RED;
                            rotateLeft(w);
                            w = left[p[x]];
                        }
                        color[w] = color[p[x]];
                        color[p[x]] = BLACK;
                        color[left[w]] = BLACK;
                        rotateRight(p[x]);
                        x = root;
                    }
                }
            }
            color[x] = BLACK;
        }

        private void rotateLeft(int x) {
            int y = right[x];
            right[x] = left[y];
            if (left[y] != NULL) {
                p[left[y]] = x;
            }
            p[y] = p[x];
            if (p[x] == NULL) {
                root = y;
            } else {
                if (x == left[p[x]]) {
                    left[p[x]] = y;
                } else {
                    right[p[x]] = y;
                }
            }
            left[y] = x;
            p[x] = y;
            subtreeSize[y] = subtreeSize[x];
            subtreeSize[x] = subtreeSize[left[x]] + subtreeSize[right[x]] + 1;
        }

        private void rotateRight(int x) {
            int y = left[x];
            left[x] = right[y];
            if (right[y] != NULL) {
                p[right[y]] = x;
            }
            p[y] = p[x];
            if (p[x] == NULL) {
                root = y;
            } else {
                if (x == right[p[x]]) {
                    right[p[x]] = y;
                } else {
                    left[p[x]] = y;
                }
            }
            right[y] = x;
            p[x] = y;
            subtreeSize[y] = subtreeSize[x];
            subtreeSize[x] = subtreeSize[left[x]] + subtreeSize[right[x]] + 1;
        }

        private void enlarge() {
            int newLength = Math.max(color.length + 1, (int) (color.length * ENLARGE_SCALE));
            value = Arrays.copyOf(value, newLength);
            subtreeSize = Arrays.copyOf(subtreeSize, newLength);
            left = Arrays.copyOf(left, newLength);
            right = Arrays.copyOf(right, newLength);
            p = Arrays.copyOf(p, newLength);
            color = Arrays.copyOf(color, newLength);
        }

        private int firstNode() {
            int x = root;
            while (left[x] != NULL) {
                x = left[x];
            }
            return x;
        }

        private int lastNode() {
            int x = root;
            while (right[x] != NULL) {
                x = right[x];
            }
            return x;
        }


        public char get(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            final int x = kThNode(index);
            return value[x];
        }


        public void insert(int index, char element) {
            if (index < 0 || index > size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            if (index == 0) {
                final int y = firstNode();
                addAsChild(y, true, element);
            } else {
                final int x = kThNode(index - 1);
                final int y = (right[x] == NULL) ? x : successorNode(x);
                

                

                

                

                addAsChild(y, x != y, element);
            }
        }


        public char removeAt(int index) {
            if (index < 0 || index >= size) {
                throw new IndexOutOfBoundsException("Index " + index + " is out of range, size = " + size);
            }
            final int x = kThNode(index);
            final char removedValue = value[x];
            removeNode(x);
            return removedValue;
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            EzCharTreeList that = (EzCharTreeList) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = successorNode(x), y = that.successorNode(y)
                    ) {
                if (value[x] != that.value[y]) {
                    return false;
                }
            }
            return true;
        }


        public int hashCode() {
            int hash = HASHCODE_INITIAL_VALUE;
            for (int x = firstNode(); x != NULL; x = successorNode(x)) {
                hash = (hash ^ PrimitiveHashCalculator.getHash(value[x])) * HASHCODE_MULTIPLIER;
            }
            return hash;
        }


        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = successorNode(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(value[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class EzCharTreeListIterator implements EzCharIterator {
            private int x;

            private EzCharTreeListIterator() {
                x = firstNode();
            }


            public boolean hasNext() {
                return x != NULL;
            }


            public char next() {
                if (x == NULL) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                final char result = value[x];
                x = successorNode(x);
                return result;
            }

        }

    }

    static final class PrimitiveHashCalculator {
        private PrimitiveHashCalculator() {
        }

        public static int getHash(char x) {
            return x;
        }

    }

    static interface EzCharQueue extends EzCharCollection {
        int size();

        EzCharIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzCharCollection {
        int size();

        EzCharIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface EzCharIterator {
        boolean hasNext();

        char next();

    }

    static class InputReader {
        BufferedReader br;

        public InputReader(InputStream inputStream) {
            br = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static interface EzCharList extends EzCharCollection {
        int size();

        EzCharIterator iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }
}

