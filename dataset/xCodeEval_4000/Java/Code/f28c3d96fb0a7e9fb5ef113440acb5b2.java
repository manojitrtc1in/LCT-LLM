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
        CF242_D solver = new CF242_D();
        solver.solve(1, in, out);
        out.close();
    }
}

class CF242_D {

































    int n, m, tNeed;
    int tPlain, tUp, tDown;
    int[][] h;
    int[][] prefRowsLeft;
    int[][] prefRowsRight;
    int[][] prefColsDown;
    int[][] prefColsUp;
    

    EzLongTreeSet set = new EzLongTreeSet();

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.readInt();
        m = in.readInt();
        tNeed = in.readInt();
        tPlain = in.readInt();
        tUp = in.readInt();
        tDown = in.readInt();
        h = IOUtils.readIntTable(in, n, m);
        prefRowsLeft = new int[n][m];
        prefRowsRight = new int[n][m];
        prefColsDown = new int[m][n];
        prefColsUp = new int[m][n];
        precalcPrefixSums();
        int bestR1 = -1, bestR2 = -1;
        int bestC1 = -1, bestC2 = -1;
        int bestDiff = (int) 1e9;
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1 + 2; r2 < n; r2++) {
                set.clear();
                for (int c1 = 0, c2 = 2; c2 < m; c1++, c2++) {
                    set.add(zip(getSum1(r1, r2, c1), c1));
                    long toFind = zip(tNeed - getSum2(r1, r2, c2), -1);
                    long ceiling = set.ceiling(toFind);
                    if (set.wasCorrectValueReturned()) {
                        int diff = Math.abs(value(toFind) - value(ceiling));
                        if (diff < bestDiff) {
                            bestDiff = diff;
                            bestR1 = r1;             bestR2 = r2;
                            bestC1 = index(ceiling); bestC2 = c2;
                        }
                    }
                    long floor = set.floor(toFind);
                    if (set.wasCorrectValueReturned()) {
                        int diff = Math.abs(value(toFind) - value(floor));
                        if (diff < bestDiff) {
                            bestDiff = diff;
                            bestR1 = r1;           bestR2 = r2;
                            bestC1 = index(floor); bestC2 = c2;
                        }
                    }
                }
            }
        }
        out.printLine(bestR1 + 1, bestC1 + 1, bestR2 + 1, bestC2 + 1);
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

    private int getSum1(int r1, int r2, int c1) {
        return getSumLeft(r2, c1, m-1)
                + getSumUp(c1, r1, r2)
                + getSumRight(r1, c1, m-1);
    }

    private int getSum2(int r1, int r2, int c2) {
        return - getSumLeft(r2, c2, m-1)
                + getSumDown(c2, r1, r2)
                - getSumRight(r1, c2, m-1);
    }

    private int getSumLeft(int r, int c1, int c2) {
        return prefRowsLeft[r][c1] - prefRowsLeft[r][c2];
    }

    private int getSumRight(int r, int c1, int c2) {
        return prefRowsRight[r][c2] - prefRowsRight[r][c1];
    }

    private int getSumDown(int c, int r1, int r2) {
        return prefColsDown[c][r2] - prefColsDown[c][r1];
    }

    private int getSumUp(int c, int r1, int r2) {
        return prefColsUp[c][r1] - prefColsUp[c][r2];
    }

    private void precalcPrefixSums() {
        for (int r = 0; r < n; r++) {
            for (int c = 1; c < m; c++) {
                int val = prefRowsRight[r][c-1];
                if (h[r][c-1] < h[r][c]) {
                    val += tUp;
                } else if (h[r][c-1] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                prefRowsRight[r][c] = val;
            }
        }
        for (int r = 0; r < n; r++) {
            for (int c = m-2; c >= 0; c--) {
                int val = prefRowsLeft[r][c+1];
                if (h[r][c+1] < h[r][c]) {
                    val += tUp;
                } else if (h[r][c+1] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                prefRowsLeft[r][c] = val;
            }
        }
        for (int c = 0; c < m; c++) {
            for (int r = 1; r < n; r++) {
                int val = prefColsDown[c][r-1];
                if (h[r-1][c] < h[r][c]) {
                    val += tUp;
                } else if (h[r-1][c] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                prefColsDown[c][r] = val;
            }
        }
        for (int c = 0; c < m; c++) {
            for (int r = n-2; r >= 0; r--) {
                int val = prefColsUp[c][r+1];
                if (h[r+1][c] < h[r][c]) {
                    val += tUp;
                } else if (h[r+1][c] > h[r][c]) {
                    val += tDown;
                } else {
                    val += tPlain;
                }
                prefColsUp[c][r] = val;
            }
        }
    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

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
        while (isSpaceChar(c))
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
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
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

    public static int[] readIntArray(InputReader in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.readInt();
        return array;
    }

    public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
        int[][] table = new int[rowCount][];
        for (int i = 0; i < rowCount; i++)
            table[i] = readIntArray(in, columnCount);
        return table;
    }

}

class EzLongTreeSet {
    private static final int DEFAULT_CAPACITY = 10;
    private static final double ENLARGE_SCALE = 2.0;

    private static final boolean BLACK = false;
    private static final boolean RED = true;
    private static final int NULL = 0;

    

    private long[] key;
    private int[] left;
    private int[] right;
    private int[] p;
    private boolean[] color;

    private int totalNodes;
    private int removedNodes;

    private int root;
    private boolean wasCorrectValueReturned;

    public EzLongTreeSet() {
        this(DEFAULT_CAPACITY);
    }

    public EzLongTreeSet(int capacity) {
        if (capacity < 0) {
            throw new IllegalArgumentException("Capacity must be non-negative");
        }
        capacity++;
        key = new long[capacity];
        left = new int[capacity];
        right = new int[capacity];
        p = new int[capacity];
        color = new boolean[capacity];
        color[NULL] = BLACK;
        totalNodes = 0;
        removedNodes = 0;
        root = NULL;
        wasCorrectValueReturned = false;
    }

    public int size() {
        return totalNodes - removedNodes;
    }
    
    public boolean isEmpty() {
        return size() == 0;
    }
    
    public boolean contains(long element) {
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
    
    public long[] toArray() {
        long[] result = new long[size()];
        for (int i = 0, x = firstNode(); x != NULL; x = successorNode(x), i++) {
            result[i] = key[x];
        }
        return result;
    }

    public boolean add(long element) {
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
        if (totalNodes == color.length - 1) {
            enlarge();
        }
        int z = ++totalNodes;
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
        fixAfterAdd(z);
        return true;
    }
    
    public boolean remove(long element) {
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
        int y = (left[z] == NULL || right[z] == NULL) ? z : successorNode(z);
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
            fixAfterRemove(x);
        }
        removedNodes++;
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

    public void clear() {
        color[NULL] = BLACK;
        totalNodes = 0;
        removedNodes = 0;
        root = NULL;
        wasCorrectValueReturned = false;
    }

    private void enlarge() {
        int newLength = Math.max(color.length + 1, (int) (color.length * ENLARGE_SCALE));
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

    private int lastNode() {
        int x = root;
        while (right[x] != NULL) {
            x = right[x];
        }
        return x;
    }

    public long getFirst() {
        if (root == NULL) {
            wasCorrectValueReturned = false;
            return key[NULL];
        }
        final int x = firstNode();
        wasCorrectValueReturned = true;
        return key[x];
    }

    public long getLast() {
        if (root == NULL) {
            wasCorrectValueReturned = false;
            return key[NULL];
        }
        final int x = lastNode();
        wasCorrectValueReturned = true;
        return key[x];
    }

    public long removeFirst() {
        if (root == NULL) {
            wasCorrectValueReturned = false;
            return key[NULL];
        }
        final int x = firstNode();
        wasCorrectValueReturned = true;
        final long removedElement = key[x];
        removeNode(x);
        return removedElement;
    }

    public long removeLast() {
        if (root == NULL) {
            wasCorrectValueReturned = false;
            return key[NULL];
        }
        final int x = lastNode();
        wasCorrectValueReturned = true;
        final long removedElement = key[x];
        removeNode(x);
        return removedElement;
    }

    public long floor(long element) {
        int x = root;
        while (x != NULL) {
            if (element > key[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    wasCorrectValueReturned = true;
                    return key[x];
                }
            } else if (element < key[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == left[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    wasCorrectValueReturned = (y != NULL);
                    return key[y];
                }
            } else {
                wasCorrectValueReturned = true;
                return key[x];
            }
        }
        wasCorrectValueReturned = false;
        return key[NULL];
    }

    public long ceiling(long element) {
        int x = root;
        while (x != NULL) {
            if (element < key[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    wasCorrectValueReturned = true;
                    return key[x];
                }
            } else if (element > key[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == right[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    wasCorrectValueReturned = (y != NULL);
                    return key[y];
                }
            } else {
                wasCorrectValueReturned = true;
                return key[x];
            }
        }
        wasCorrectValueReturned = false;
        return key[NULL];
    }

    public long lower(long element) {
        int x = root;
        while (x != NULL) {
            if (element > key[x]) {
                if (right[x] != NULL) {
                    x = right[x];
                } else {
                    wasCorrectValueReturned = true;
                    return key[x];
                }
            } else {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    int y = p[x];
                    while (y != NULL && x == left[y]) {
                        

                        x = y;
                        y = p[y];
                    }
                    wasCorrectValueReturned = (y != NULL);
                    return key[y];
                }
            }
        }
        wasCorrectValueReturned = false;
        return key[NULL];
    }

    public long higher(long element) {
        int x = root;
        while (x != NULL) {
            if (element < key[x]) {
                if (left[x] != NULL) {
                    x = left[x];
                } else {
                    wasCorrectValueReturned = true;
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
                    wasCorrectValueReturned = (y != NULL);
                    return key[y];
                }
            }
        }
        wasCorrectValueReturned = false;
        return key[NULL];
    }

    public boolean wasCorrectValueReturned() {
        return wasCorrectValueReturned;
    }
}