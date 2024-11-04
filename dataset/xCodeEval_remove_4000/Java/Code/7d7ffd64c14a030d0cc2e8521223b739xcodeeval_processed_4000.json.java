import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CounterAttack solver = new CounterAttack();
        solver.solve(1, in, out);
        out.close();
    }

    static class CounterAttack {
        int n;
        int m;
        id16[] bad;
        id7 nVis;

        void dfs(int u, id16 comp) {
            comp.add(u);
            nVis.remove(u);
            for (int v = nVis.getFirst(); !nVis.returnedNull(); v = nVis.higher(v)) {
                if (!bad[u].binarySearch(v)) {
                    dfs(v, comp);
                }
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            bad = new id16[n + 1];
            Arrays.setAll(bad, i -> new id16());
            for (int i = 0; i < m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                bad[u].add(v);
                bad[v].add(u);
            }

            for (id16 a : bad) {
                a.sort();
            }

            nVis = new id7();
            for (int i = 1; i <= n; i++) {
                nVis.add(i);
            }

            ArrayList<id16> comps = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                if (nVis.contains(i)) {
                    id16 comp = new id16();
                    dfs(i, comp);
                    comps.add(comp);
                }
            }

            out.println(comps.size());
            for (id16 comp : comps) {
                out.print(comp.size() + " ");
                for (id15 it = comp.iterator(); it.hasNext(); ) {
                    int u = it.next();
                    out.print(u + " ");
                }
                out.println();
            }
        }

    }

    static final class id6 {
        private id6() {
        }

        public static int getHash(int x) {
            return x;
        }

    }

    static interface id15 {
        boolean hasNext();

        int next();

    }

    static class id16 implements id2, id3 {
        private static final int id18 = 10;
        private static final double id1 = 2.0;
        private static final int id10 = 0x811c9dc5;
        private static final int id19 = 0x01000193;
        private int[] array;
        private int size;

        public id16() {
            this(id18);
        }

        public id16(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            array = new int[capacity];
            size = 0;
        }

        public id16(id0 collection) {
            size = collection.size();
            array = new int[size];
            int i = 0;
            for (id15 iterator = collection.iterator(); iterator.hasNext(); ) {
                array[i++] = iterator.next();
            }
        }

        public id16(int[] srcArray) {
            size = srcArray.length;
            array = new int[size];
            System.arraycopy(srcArray, 0, array, 0, size);
        }

        public id16(Collection<Integer> javaCollection) {
            size = javaCollection.size();
            array = new int[size];
            int i = 0;
            for (int element : javaCollection) {
                array[i++] = element;
            }
        }

        public int size() {
            return size;
        }

        public id15 iterator() {
            return new id8();
        }

        public boolean add(int element) {
            if (size == array.length) {
                enlarge();
            }
            array[size++] = element;
            return true;
        }

        private void enlarge() {
            int newSize = Math.max(size + 1, (int) (size * id1));
            int[] newArray = new int[newSize];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id16 that = (id16) o;

            if (size != that.size) {
                return false;
            }
            for (int i = 0; i < size; i++) {
                if (array[i] != that.array[i]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id10;
            for (int i = 0; i < size; i++) {
                hash = (hash ^ id6.getHash(array[i])) * id19;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int i = 0; i < size; i++) {
                sb.append(array[i]);
                if (i < size - 1) {
                    sb.append(", ");
                }
            }
            sb.append(']');
            return sb.toString();
        }

        public void sort() {
            id13.id12(array, 0, size);
        }

        public int lowerBound(int val) {
            int ret = -1;
            for (int jump = size; jump >= 1; jump /= 2) {
                while (ret + jump < size && array[ret + jump] < val) {
                    ret += jump;
                }
            }
            return ret + 1;
        }

        public boolean binarySearch(int val) {
            int lb = lowerBound(val);
            return lb < size && array[lb] == val;
        }

        private class id8 implements id15 {
            private int curIndex = 0;

            public boolean hasNext() {
                return curIndex < size;
            }

            public int next() {
                if (curIndex == size) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                return array[curIndex++];
            }

        }

    }

    static final class id13 {
        private static final Random rnd = new Random();

        private id13() {
        }

        private static void randomShuffle(int[] a, int left, int right) {
            for (int i = left; i < right; i++) {
                int j = i + rnd.nextInt(right - i);
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

        public static void id12(int[] a, int left, int right) {
            if (left > right || left < 0 || right > a.length) {
                throw new IllegalArgumentException(
                        "Incorrect range [" + left + ", " + right + ") was specified for sorting, length = " + a.length);
            }
            randomShuffle(a, left, right);
            Arrays.sort(a, left, right);
        }

    }

    static class id7 implements id20 {
        private static final int id18 = 10;
        private static final double id1 = 2.0;
        private static final int id10 = 0x811c9dc5;
        private static final int id19 = 0x01000193;
        private static final boolean BLACK = false;
        private static final boolean RED = true;
        private static final int NULL = 0;
        private static final int id9 = (new int[1])[0];
        private int[] key;
        private int[] left;
        private int[] right;
        private int[] p;
        private boolean[] color;
        private int size;
        private int root;
        private boolean returnedNull;

        public id7() {
            this(id18);
        }

        public id7(int capacity) {
            if (capacity < 0) {
                throw new IllegalArgumentException("Capacity must be non-negative");
            }
            capacity++;
            key = new int[capacity];
            left = new int[capacity];
            right = new int[capacity];
            p = new int[capacity];
            color = new boolean[capacity];
            color[NULL] = BLACK;
            size = 0;
            root = NULL;
            returnedNull = false;
        }

        public id7(id0 collection) {
            this(collection.size());
            for (id15 iterator = collection.iterator(); iterator.hasNext(); ) {
                add(iterator.next());
            }
        }

        public id7(int[] srcArray) {
            this(srcArray.length);
            for (int element : srcArray) {
                add(element);
            }
        }

        public id7(Collection<Integer> javaCollection) {
            this(javaCollection.size());
            for (int element : javaCollection) {
                add(element);
            }
        }

        public int size() {
            return size;
        }

        public boolean contains(int element) {
            int x = root;
            while (x != NULL) {
                if (element < key[x]) {
                    x = left[x];
                } else if (element > key[x]) {
                    x = right[x];
                } else {
                    return true;
                }
            }
            return false;
        }

        public id15 iterator() {
            return new id14();
        }

        public boolean add(int element) {
            int y = NULL;
            int x = root;
            while (x != NULL) {
                

                y = x;
                if (element < key[x]) {
                    x = left[x];
                } else if (element > key[x]) {
                    x = right[x];
                } else {
                    return false;
                }
            }
            if (size == color.length - 1) {
                enlarge();
            }
            int z = ++size;
            key[z] = element;
            p[z] = y;
            if (y == NULL) {
                root = z;
            } else {
                if (element < key[y]) {
                    left[y] = z;
                } else {
                    right[y] = z;
                }
            }
            left[z] = NULL;
            right[z] = NULL;
            color[z] = RED;
            id11(z);
            return true;
        }

        public boolean remove(int element) {
            int z = root;
            while (z != NULL) {
                if (element < key[z]) {
                    z = left[z];
                } else if (element > key[z]) {
                    z = right[z];
                } else {
                    removeNode(z);
                    return true;
                }
            }
            return false;
        }

        private void removeNode(int z) {
            int y = (left[z] == NULL || right[z] == NULL) ? z : id17(z);
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
                key[z] = key[y];
            }
            

            if (color[y] == BLACK) {
                id4(x);
            }
            

            if (y != size) {
                

                key[y] = key[size];
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

        private int id17(int x) {
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

        private void id11(int z) {
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

        private void id4(int x) {
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
        }

        private void enlarge() {
            int newLength = Math.max(color.length + 1, (int) (color.length * id1));
            key = Arrays.copyOf(key, newLength);
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

        public int getFirst() {
            if (root == NULL) {
                returnedNull = true;
                return id9;
            }
            final int x = firstNode();
            returnedNull = false;
            return key[x];
        }

        public int higher(int element) {
            int x = root;
            while (x != NULL) {
                if (element < key[x]) {
                    if (left[x] != NULL) {
                        x = left[x];
                    } else {
                        returnedNull = false;
                        return key[x];
                    }
                } else {
                    if (right[x] != NULL) {
                        x = right[x];
                    } else {
                        int y = p[x];
                        while (y != NULL && x == right[y]) {
                            

                            x = y;
                            y = p[y];
                        }
                        if (y == NULL) {
                            returnedNull = true;
                            return id9;
                        } else {
                            returnedNull = false;
                            return key[y];
                        }
                    }
                }
            }
            returnedNull = true;
            return id9;
        }

        public boolean returnedNull() {
            return returnedNull;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            id7 that = (id7) o;

            if (size != that.size) {
                return false;
            }
            for (int x = firstNode(), y = that.firstNode();
                 x != NULL;
                

                 x = id17(x), y = that.id17(y)
            ) {
                if (key[x] != that.key[y]) {
                    return false;
                }
            }
            return true;
        }

        public int hashCode() {
            int hash = id10;
            for (int x = firstNode(); x != NULL; x = id17(x)) {
                hash = (hash ^ id6.getHash(key[x])) * id19;
            }
            return hash;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append('[');
            for (int x = firstNode(); x != NULL; x = id17(x)) {
                if (sb.length() > 1) {
                    sb.append(", ");
                }
                sb.append(key[x]);
            }
            sb.append(']');
            return sb.toString();
        }

        private class id14 implements id15 {
            private int x;

            private id14() {
                x = firstNode();
            }

            public boolean hasNext() {
                return x != NULL;
            }

            public int next() {
                if (x == NULL) {
                    throw new NoSuchElementException("Iterator doesn't have more elements");
                }
                final int result = key[x];
                x = id17(x);
                return result;
            }

        }

    }

    static interface id3 extends id0 {
        int size();

        id15 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id2 extends id0 {
        int size();

        id15 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id0 {
        int size();

        id15 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id20 extends id5 {
        int size();

        id15 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static interface id5 extends id0 {
        int size();

        id15 iterator();

        boolean equals(Object object);

        int hashCode();

        String toString();

    }

    static class InputReader {
        private final InputStream is;
        private final byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream stream) {
            is = stream;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int nextInt() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}

