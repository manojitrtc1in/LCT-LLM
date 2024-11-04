import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.*;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.InputStream;


public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        id13 solver = new id13();
        solver.solve(1, in, out);
        out.close();
    }
}

class id13 {

































    int n, m, tNeed;
    int tPlain, tUp, tDown;
    int[][] h;
    int[][] id14;
    int[][] id2;
    int[][] id24;
    int[][] id19;
    

    id15 set = new id15();

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.readInt();
        m = in.readInt();
        tNeed = in.readInt();
        tPlain = in.readInt();
        tUp = in.readInt();
        tDown = in.readInt();
        h = IOUtils.id5(in, n, m);
        id14 = new int[n][m];
        id2 = new int[n][m];
        id24 = new int[m][n];
        id19 = new int[m][n];
        id18();
        int id11 = -1, id22 = -1;
        int id3 = -1, id16 = -1;
        int bestDiff = (int) 1e9;
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1 + 2; r2 < n; r2++) {
                set.clear();
                for (int c1 = 0, c2 = 2; c2 < m; c1++, c2++) {
                    set.add(zip(id6(r1, r2, c1), c1));
                    long toFind = zip(tNeed - id0(r1, r2, c2), -1);
                    long ceiling = set.ceiling(toFind);
                    if (set.id9()) {
                        int diff = Math.abs(value(toFind) - value(ceiling));
                        if (diff < bestDiff) {
                            bestDiff = diff;
                            id11 = r1;             id22 = r2;
                            id3 = index(ceiling); id16 = c2;
                        }
                    }
                    long floor = set.floor(toFind);
                    if (set.id9()) {
                        int diff = Math.abs(value(toFind) - value(floor));
                        if (diff < bestDiff) {
                            bestDiff = diff;
                            id11 = r1;           id22 = r2;
                            id3 = index(floor); id16 = c2;
                        }
                    }
                }
            }
        }
        out.printLine(id11 + 1, id3 + 1, id22 + 1, id16 + 1);
    }

    private long zip(int a, int b) {
        return ((long)a << 32) | (b & 0x00000000FFFFFFFFL);
    }

    private int value(long z) {
        return (int) (z >>> 32);
    }

    private int index(long z) {
        return (int) z;
    }

    private int id6(int r1, int r2, int c1) {
        return id10(r2, c1, m-1)
                + id20(c1, r1, r2)
                + id21(r1, c1, m-1);
    }

    private int id0(int r1, int r2, int c2) {
        return - id10(r2, c2, m-1)
                + id12(c2, r1, r2)
                - id21(r1, c2, m-1);
    }

    private int id10(int r, int c1, int c2) {
        return id14[r][c1] - id14[r][c2];
    }

    private int id21(int r, int c1, int c2) {
        return id2[r][c2] - id2[r][c1];
    }

    private int id12(int c, int r1, int r2) {
        return id24[c][r2] - id24[c][r1];
    }

    private int id20(int c, int r1, int r2) {
        return id19[c][r1] - id19[c][r2];
    }

    private void id18() {
        for (int r = 0; r < n; r++) {
            for (int c = 1; c < m; c++) {
                int val = id2[r][c-1];
                if (h[r][c-1] < h[r][c]) {
                    val += tUp;
                } else if (h[r][c-1] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                id2[r][c] = val;
            }
        }
        for (int r = 0; r < n; r++) {
            for (int c = m-2; c >= 0; c--) {
                int val = id14[r][c+1];
                if (h[r][c+1] < h[r][c]) {
                    val += tUp;
                } else if (h[r][c+1] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                id14[r][c] = val;
            }
        }
        for (int c = 0; c < m; c++) {
            for (int r = 1; r < n; r++) {
                int val = id24[c][r-1];
                if (h[r-1][c] < h[r][c]) {
                    val += tUp;
                } else if (h[r-1][c] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                id24[c][r] = val;
            }
        }
        for (int c = 0; c < m; c++) {
            for (int r = n-2; r >= 0; r--) {
                int val = id19[c][r+1];
                if (h[r+1][c] < h[r][c]) {
                    val += tUp;
                } else if (h[r+1][c] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                id19[c][r] = val;
            }
        }
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private id26 filter;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (id4(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!id4(c));
        return res * sgn;
    }

    public boolean id4(int c) {
        if (filter != null)
            return filter.id4(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface id26 {
        public boolean id4(int ch);
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object...objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object...objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class IOUtils {

    public static int[] id1(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static int[][] id5(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = id1(in, columnCount);
        return table;
    }

}

class id15 {
    private static final int id25 = 10;
    private static final double id7 = 2.0;

    private static final boolean BLACK = false;
    private static final boolean RED = true;

    private static class Node {
        private long key;
        private Node left;
        private Node right;
        private Node p;
        private boolean color;

        private Node(long key, Node left, Node right, Node p, boolean color) {
            this.key = key;
            this.left = left;
            this.right = right;
            this.p = p;
            this.color = color;
        }
    }

    

    private Node[] nodes;
    private final Node NULL;

    

    private int totalNodes;
    private int removedNodes;

    private Node root;
    private boolean id9;

    public id15() {
        this(id25);
    }

    public id15(int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity must be non-negative");
        }
        capacity++;
        nodes = new Node[capacity];
        totalNodes = 0;
        removedNodes = 0;
        NULL = new Node((long) 0, null, null, null, BLACK);
        NULL.left = NULL.right = NULL.p = NULL;
        nodes[0] = NULL;
        root = NULL;
        id9 = false;
    }

    public int size() {
        return totalNodes - removedNodes;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean contains(long element) {
        Node x = root;
        while (x != NULL) {
            if (element < x.key) {
                x = x.left;
            } else if (element > x.key) {
                x = x.right;
            } else {
                return true;
            }
        }
        return false;
    }

    public long[] toArray() {
        long[] result = new long[size()];
        Node x = firstNode();
        for (int i = 0; x != NULL; x = id23(x), i++) {
            result[i] = x.key;
        }
        return result;
    }

    public boolean add(long element) {
        Node y = NULL;
        Node x = root;
        while (x != NULL) {
            

            y = x;
            if (element < x.key) {
                x = x.left;
            } else if (element > x.key) {
                x = x.right;
            } else {
                return false;
            }
        }
        if (totalNodes == nodes.length - 1) {
            enlarge();
        }
        Node z = new Node(element, NULL, NULL, y, RED);
        nodes[++totalNodes] = z;
        if (y == NULL) {
            root = z;
        } else {
            if (element < y.key) {
                y.left = z;
            } else {
                y.right = z;
            }
        }
        id17(z);
        return true;
    }

    public boolean remove(long element) {
        Node z = root;
        while (z != NULL) {
            if (element < z.key) {
                z = z.left;
            } else if (element > z.key) {
                z = z.right;
            } else {
                removeNode(z);
                return true;
            }
        }
        return false;
    }

    private void removeNode(Node z) {
        Node y = (z.left == NULL || z.right == NULL) ? z : id23(z);
        Node x = (y.left!= NULL) ? y.left : y.right;
        x.p = y.p;
        if (y.p == NULL) {
            root = x;
        } else {
            if (y == y.p.left) {
                y.p.left = x;
            } else {
                y.p.right = x;
            }
        }
        if (y != z) {
            z.key = y.key;
        }
        

        if (y.color == BLACK) {
            id8(x);
        }
        removedNodes++;
    }

    private Node id23(Node x) {
        if (x.right != NULL) {
            x = x.right;
            while (x.left != NULL) {
                x = x.left;
            }
            return x;
        } else {
            Node y = x.p;
            while (y != NULL && x == y.right) {
                

                x = y;
                y = y.p;
            }
            return y;
        }
    }

    @SuppressWarnings("PointlessBooleanExpression")
    private void id17(Node z) {
        while (z.p.color == RED) {
            if (z.p == z.p.p.left) {
                Node y = z.p.p.right;
                if (y.color == RED) {
                    z.p.color = BLACK;
                    y.color = BLACK;
                    z.p.p.color = RED;
                    z = z.p.p;
                } else {
                    if (z == z.p.right) {
                        z = z.p;
                        rotateLeft(z);
                    }
                    z.p.color = BLACK;
                    z.p.p.color = RED;
                    rotateRight(z.p.p);
                }
            } else {
                Node y = z.p.p.left;
                if (y.color == RED) {
                    z.p.color = BLACK;
                    y.color = BLACK;
                    z.p.p.color = RED;
                    z = z.p.p;
                } else {
                    if (z == z.p.left) {
                        z = z.p;
                        rotateRight(z);
                    }
                    z.p.color = BLACK;
                    z.p.p.color = RED;
                    rotateLeft(z.p.p);
                }
            }
        }
        root.color = BLACK;
    }

    @SuppressWarnings("PointlessBooleanExpression")
    private void id8(Node x) {
        while (x != root && x.color == BLACK) {
            if (x == x.p.left) {
                Node w = x.p.right;
                if (w.color == RED) {
                    w.color = BLACK;
                    x.p.color = RED;
                    rotateLeft(x.p);
                    w = x.p.right;
                }
                if (w.left.color == BLACK && w.right.color == BLACK) {
                    w.color = RED;
                    x = x.p;
                } else {
                    if (w.right.color == BLACK) {
                        w.left.color = BLACK;
                        w.color = RED;
                        rotateRight(w);
                        w = x.p.right;
                    }
                    w.color = x.p.color;
                    x.p.color = BLACK;
                    w.right.color = BLACK;
                    rotateLeft(x.p);
                    x = root;
                }
            } else {
                Node w = x.p.left;
                if (w.color == RED) {
                    w.color = BLACK;
                    x.p.color = RED;
                    rotateRight(x.p);
                    w = x.p.left;
                }
                if (w.left.color == BLACK && w.right.color == BLACK) {
                    w.color = RED;
                    x = x.p;
                } else {
                    if (w.left.color == BLACK) {
                        w.right.color = BLACK;
                        w.color = RED;
                        rotateLeft(w);
                        w = x.p.left;
                    }
                    w.color = x.p.color;
                    x.p.color = BLACK;
                    w.left.color = BLACK;
                    rotateRight(x.p);
                    x = root;
                }
            }
        }
        x.color = BLACK;
    }

    private void rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        if (y.left != NULL) {
            y.left.p = x;
        }
        y.p = x.p;
        if (x.p == NULL) {
            root = y;
        } else {
            if (x == x.p.left) {
                x.p.left = y;
            } else {
                x.p.right = y;
            }
        }
        y.left = x;
        x.p = y;
    }

    private void rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        if (y.right != NULL) {
            y.right.p = x;
        }
        y.p = x.p;
        if (x.p == NULL) {
            root = y;
        } else {
            if (x == x.p.right) {
                x.p.right = y;
            } else {
                x.p.left = y;
            }
        }
        y.right = x;
        x.p = y;
    }

    public void clear() {
        NULL.color = BLACK;
        NULL.left = NULL.right = NULL.p = NULL;
        totalNodes = 0;
        removedNodes = 0;
        root = NULL;
        id9 = false;
    }

    private void enlarge() {
        int newLength = Math.max(nodes.length + 1, (int) (nodes.length * id7));
        nodes = Arrays.copyOf(nodes, newLength);
    }

    private Node firstNode() {
        Node x = root;
        while (x.left != NULL) {
            x = x.left;
        }
        return x;
    }

    private Node lastNode() {
        Node x = root;
        while (x.right != NULL) {
            x = x.right;
        }
        return x;
    }

    public long getFirst() {
        if (root == NULL) {
            id9 = false;
            return NULL.key;
        }
        final Node x = firstNode();
        id9 = true;
        return x.key;
    }

    public long getLast() {
        if (root == NULL) {
            id9 = false;
            return NULL.key;
        }
        final Node x = lastNode();
        id9 = true;
        return x.key;
    }

    public long removeFirst() {
        if (root == NULL) {
            id9 = false;
            return NULL.key;
        }
        final Node x = firstNode();
        id9 = true;
        final long removedElement = x.key;
        removeNode(x);
        return removedElement;
    }

    public long removeLast() {
        if (root == NULL) {
            id9 = false;
            return NULL.key;
        }
        final Node x = lastNode();
        id9 = true;
        final long removedElement = x.key;
        removeNode(x);
        return removedElement;
    }

    public long floor(long element) {
        Node x = root;
        while (x != NULL) {
            if (element > x.key) {
                if (x.right != NULL) {
                    x = x.right;
                } else {
                    id9 = true;
                    return x.key;
                }
            } else if (element < x.key) {
                if (x.left != NULL) {
                    x = x.left;
                } else {
                    Node y = x.p;
                    while (y != NULL && x == y.left) {
                        

                        x = y;
                        y = y.p;
                    }
                    id9 = (y != NULL);
                    return y.key;
                }
            } else {
                id9 = true;
                return x.key;
            }
        }
        id9 = false;
        return NULL.key;
    }

    public long ceiling(long element) {
        Node x = root;
        while (x != NULL) {
            if (element < x.key) {
                if (x.left != NULL) {
                    x = x.left;
                } else {
                    id9 = true;
                    return x.key;
                }
            } else if (element > x.key) {
                if (x.right != NULL) {
                    x = x.right;
                } else {
                    Node y = x.p;
                    while (y != NULL && x == y.right) {
                        

                        x = y;
                        y = y.p;
                    }
                    id9 = (y != NULL);
                    return y.key;
                }
            } else {
                id9 = true;
                return x.key;
            }
        }
        id9 = false;
        return NULL.key;
    }

    public long lower(long element) {
        Node x = root;
        while (x != NULL) {
            if (element > x.key) {
                if (x.right != NULL) {
                    x = x.right;
                } else {
                    id9 = true;
                    return x.key;
                }
            } else {
                if (x.left != NULL) {
                    x = x.left;
                } else {
                    Node y = x.p;
                    while (y != NULL && x == y.left) {
                        

                        x = y;
                        y = y.p;
                    }
                    id9 = (y != NULL);
                    return y.key;
                }
            }
        }
        id9 = false;
        return NULL.key;
    }

    public long higher(long element) {
        Node x = root;
        while (x != NULL) {
            if (element < x.key) {
                if (x.left != NULL) {
                    x = x.left;
                } else {
                    id9 = true;
                    return x.key;
                }
            } else {
                if (x.right != NULL) {
                    x = x.right;
                } else {
                    Node y = x.p;
                    while (y != NULL && x == y.right) {
                        

                        x = y;
                        y = y.p;
                    }
                    id9 = (y != NULL);
                    return y.key;
                }
            }
        }
        id9 = false;
        return NULL.key;
    }

    public boolean id9() {
        return id9;
    }
}
