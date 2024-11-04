import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

public class Main {
    private static FastReader sc = new FastReader(System.in);
    private static OutputWriter out = new OutputWriter(System.out);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        int[] arr = new int[n];
        HashMap<Integer, Integer> idx = new HashMap<>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            idx.put(arr[i], i);
        }

        RedBlackBST<Integer, Integer> set = new RedBlackBST<>();
        int[] greaterOnLeft = new int[n];
        set.put(arr[0], 0);
        for (int i = 1; i < n; i++) {
            int x = arr[i];
            int g;
            if (set.ceiling(x) == null) g = 0;
            else g = set.size() - set.rank(set.ceiling(x));
            greaterOnLeft[i] = g;
            set.put(arr[i], 0);
        }



        int[] onRight = new int[n];
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            onRight[i] += cnt;
            if (greaterOnLeft[i] == 0) cnt++;
        }

        set = new RedBlackBST<>();
        for (int i = 0; i < n; i++) {
            if (greaterOnLeft[i] == 1) {
                int g = set.ceiling(arr[i]);


                onRight[idx.get(g)]++;
            }
            set.put(arr[i], 0);
        }



        TreeSet<Integer> tree = new TreeSet<>();
        tree.add(arr[0]);
        int[] onLeft = new int[n];
        onLeft[0] = 1;
        for (int i = 1; i < n; i++) {
            if (tree.ceiling(arr[i]) == null) onLeft[i] = onLeft[i - 1] + 1;
            else onLeft[i] = onLeft[i - 1];
            tree.add(arr[i]);
        }



        int ans = onRight[0];
        int element = arr[0];
        for (int i = 1; i < n; i++) {
            if (ans < onLeft[i - 1] + onRight[i]) {
                ans = onLeft[i - 1] + onRight[i];
                element = arr[i];
            } else if (ans == onLeft[i - 1] + onRight[i]) {
                element = Math.min(element, arr[i]);
            }
        }
        System.out.println(element);
    }
}

class RedBlackBST<Key extends Comparable<Key>, Value> {

    private static final boolean RED = true;
    private static final boolean BLACK = false;

    private Node root;     


    

    private class Node {
        private Key key;           

        private Value val;         

        private Node left, right;  

        private boolean color;     

        private int size;          


        public Node(Key key, Value val, boolean color, int size) {
            this.key = key;
            this.val = val;
            this.color = color;
            this.size = size;
        }
    }

    
    public RedBlackBST() {
    }

    
    

    private boolean isRed(Node x) {
        if (x == null) return false;
        return x.color == RED;
    }

    

    private int size(Node x) {
        if (x == null) return 0;
        return x.size;
    }


    
    public int size() {
        return size(root);
    }

    
    public boolean isEmpty() {
        return root == null;
    }


    

    
    public Value get(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to get() is null");
        return get(root, key);
    }

    

    private Value get(Node x, Key key) {
        while (x != null) {
            int cmp = key.compareTo(x.key);
            if (cmp < 0) x = x.left;
            else if (cmp > 0) x = x.right;
            else return x.val;
        }
        return null;
    }

    
    public boolean contains(Key key) {
        return get(key) != null;
    }

    

    
    public void put(Key key, Value val) {
        if (key == null) throw new IllegalArgumentException("first argument to put() is null");
        if (val == null) {
            delete(key);
            return;
        }

        root = put(root, key, val);
        root.color = BLACK;
        

    }

    

    private Node put(Node h, Key key, Value val) {
        if (h == null) return new Node(key, val, RED, 1);

        int cmp = key.compareTo(h.key);
        if (cmp < 0) h.left = put(h.left, key, val);
        else if (cmp > 0) h.right = put(h.right, key, val);
        else h.val = val;

        

        if (isRed(h.right) && !isRed(h.left)) h = rotateLeft(h);
        if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
        if (isRed(h.left) && isRed(h.right)) flipColors(h);
        h.size = size(h.left) + size(h.right) + 1;

        return h;
    }

    

    
    public void deleteMin() {
        if (isEmpty()) throw new NoSuchElementException("BST underflow");

        

        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = deleteMin(root);
        if (!isEmpty()) root.color = BLACK;
        

    }

    

    private Node deleteMin(Node h) {
        if (h.left == null)
            return null;

        if (!isRed(h.left) && !isRed(h.left.left))
            h = moveRedLeft(h);

        h.left = deleteMin(h.left);
        return balance(h);
    }


    
    public void deleteMax() {
        if (isEmpty()) throw new NoSuchElementException("BST underflow");

        

        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = deleteMax(root);
        if (!isEmpty()) root.color = BLACK;
        

    }

    

    private Node deleteMax(Node h) {
        if (isRed(h.left))
            h = rotateRight(h);

        if (h.right == null)
            return null;

        if (!isRed(h.right) && !isRed(h.right.left))
            h = moveRedRight(h);

        h.right = deleteMax(h.right);

        return balance(h);
    }

    
    public void delete(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to delete() is null");
        if (!contains(key)) return;

        

        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;

        root = delete(root, key);
        if (!isEmpty()) root.color = BLACK;
        

    }

    

    private Node delete(Node h, Key key) {
        


        if (key.compareTo(h.key) < 0) {
            if (!isRed(h.left) && !isRed(h.left.left))
                h = moveRedLeft(h);
            h.left = delete(h.left, key);
        } else {
            if (isRed(h.left))
                h = rotateRight(h);
            if (key.compareTo(h.key) == 0 && (h.right == null))
                return null;
            if (!isRed(h.right) && !isRed(h.right.left))
                h = moveRedRight(h);
            if (key.compareTo(h.key) == 0) {
                Node x = min(h.right);
                h.key = x.key;
                h.val = x.val;
                

                

                h.right = deleteMin(h.right);
            } else h.right = delete(h.right, key);
        }
        return balance(h);
    }

    

    

    private Node rotateRight(Node h) {
        

        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = x.right.color;
        x.right.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    

    private Node rotateLeft(Node h) {
        

        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = x.left.color;
        x.left.color = RED;
        x.size = h.size;
        h.size = size(h.left) + size(h.right) + 1;
        return x;
    }

    

    private void flipColors(Node h) {
        

        

        

        

        h.color = !h.color;
        h.left.color = !h.left.color;
        h.right.color = !h.right.color;
    }

    

    

    private Node moveRedLeft(Node h) {
        

        


        flipColors(h);
        if (isRed(h.right.left)) {
            h.right = rotateRight(h.right);
            h = rotateLeft(h);
            flipColors(h);
        }
        return h;
    }

    

    

    private Node moveRedRight(Node h) {
        

        

        flipColors(h);
        if (isRed(h.left.left)) {
            h = rotateRight(h);
            flipColors(h);
        }
        return h;
    }

    

    private Node balance(Node h) {
        


        if (isRed(h.right)) h = rotateLeft(h);
        if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
        if (isRed(h.left) && isRed(h.right)) flipColors(h);

        h.size = size(h.left) + size(h.right) + 1;
        return h;
    }


    

    
    public int height() {
        return height(root);
    }

    private int height(Node x) {
        if (x == null) return -1;
        return 1 + Math.max(height(x.left), height(x.right));
    }

    

    
    public Key min() {
        if (isEmpty()) throw new NoSuchElementException("calls min() with empty symbol table");
        return min(root).key;
    }

    

    private Node min(Node x) {
        

        if (x.left == null) return x;
        else return min(x.left);
    }

    
    public Key max() {
        if (isEmpty()) throw new NoSuchElementException("calls max() with empty symbol table");
        return max(root).key;
    }

    

    private Node max(Node x) {
        

        if (x.right == null) return x;
        else return max(x.right);
    }


    
    public Key floor(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to floor() is null");
        if (isEmpty()) throw new NoSuchElementException("calls floor() with empty symbol table");
        Node x = floor(root, key);
        if (x == null) return null;
        else return x.key;
    }

    

    private Node floor(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp < 0) return floor(x.left, key);
        Node t = floor(x.right, key);
        if (t != null) return t;
        else return x;
    }

    
    public Key ceiling(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
        if (isEmpty()) throw new NoSuchElementException("calls ceiling() with empty symbol table");
        Node x = ceiling(root, key);
        if (x == null) return null;
        else return x.key;
    }

    

    private Node ceiling(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp > 0) return ceiling(x.right, key);
        Node t = ceiling(x.left, key);
        if (t != null) return t;
        else return x;
    }

    
    public Key select(int k) {
        if (k < 0 || k >= size()) {
            throw new IllegalArgumentException("argument to select() is invalid: " + k);
        }
        Node x = select(root, k);
        return x.key;
    }

    

    private Node select(Node x, int k) {
        

        

        int t = size(x.left);
        if (t > k) return select(x.left, k);
        else if (t < k) return select(x.right, k - t - 1);
        else return x;
    }

    
    public int rank(Key key) {
        if (key == null) throw new IllegalArgumentException("argument to rank() is null");
        return rank(key, root);
    }

    

    private int rank(Key key, Node x) {
        if (x == null) return 0;
        int cmp = key.compareTo(x.key);
        if (cmp < 0) return rank(key, x.left);
        else if (cmp > 0) return 1 + size(x.left) + rank(key, x.right);
        else return size(x.left);
    }

    

    
    public Iterable<Key> keys() {
        if (isEmpty()) return new LinkedList<>();
        return keys(min(), max());
    }

    
    public Iterable<Key> keys(Key lo, Key hi) {
        if (lo == null) throw new IllegalArgumentException("first argument to keys() is null");
        if (hi == null) throw new IllegalArgumentException("second argument to keys() is null");

        Queue<Key> queue = new LinkedList<>();
        

        keys(root, queue, lo, hi);
        return queue;
    }

    

    

    private void keys(Node x, Queue<Key> queue, Key lo, Key hi) {
        if (x == null) return;
        int cmplo = lo.compareTo(x.key);
        int cmphi = hi.compareTo(x.key);
        if (cmplo < 0) keys(x.left, queue, lo, hi);
        if (cmplo <= 0 && cmphi >= 0) queue.add(x.key);
        if (cmphi > 0) keys(x.right, queue, lo, hi);
    }

    
    public int size(Key lo, Key hi) {
        if (lo == null) throw new IllegalArgumentException("first argument to size() is null");
        if (hi == null) throw new IllegalArgumentException("second argument to size() is null");

        if (lo.compareTo(hi) > 0) return 0;
        if (contains(hi)) return rank(hi) - rank(lo) + 1;
        else return rank(hi) - rank(lo);
    }


    
    private boolean check() {
        return isBST() && isSizeConsistent() && isRankConsistent() && is23() && isBalanced();
    }

    

    

    private boolean isBST() {
        return isBST(root, null, null);
    }

    

    

    

    private boolean isBST(Node x, Key min, Key max) {
        if (x == null) return true;
        if (min != null && x.key.compareTo(min) <= 0) return false;
        if (max != null && x.key.compareTo(max) >= 0) return false;
        return isBST(x.left, min, x.key) && isBST(x.right, x.key, max);
    }

    

    private boolean isSizeConsistent() {
        return isSizeConsistent(root);
    }

    private boolean isSizeConsistent(Node x) {
        if (x == null) return true;
        if (x.size != size(x.left) + size(x.right) + 1) return false;
        return isSizeConsistent(x.left) && isSizeConsistent(x.right);
    }

    

    private boolean isRankConsistent() {
        for (int i = 0; i < size(); i++)
            if (i != rank(select(i))) return false;
        for (Key key : keys())
            if (key.compareTo(select(rank(key))) != 0) return false;
        return true;
    }

    

    

    private boolean is23() {
        return is23(root);
    }

    private boolean is23(Node x) {
        if (x == null) return true;
        if (isRed(x.right)) return false;
        if (x != root && isRed(x) && isRed(x.left))
            return false;
        return is23(x.left) && is23(x.right);
    }

    

    private boolean isBalanced() {
        int black = 0;     

        Node x = root;
        while (x != null) {
            if (!isRed(x)) black++;
            x = x.left;
        }
        return isBalanced(root, black);
    }

    

    private boolean isBalanced(Node x, int black) {
        if (x == null) return black == 0;
        if (!isRed(x)) black--;
        return isBalanced(x.left, black) && isBalanced(x.right, black);
    }
}

class FastReader {
    private boolean finished = false;

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public FastReader(InputStream stream) {
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

    public int peek() {
        if (numChars == -1) {
            return -1;
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar];
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
            if (c == ',') {
                c = read();
            }
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
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

    public String nextString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        if (filter != null) {
            return filter.isSpaceChar(c);
        }
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String readLine0() {
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

    public String nextLine() {
        String s = readLine0();
        while (s.trim().length() == 0)
            s = readLine0();
        return s;
    }

    public String nextLine(boolean ignoreEmptyLines) {
        if (ignoreEmptyLines) {
            return nextLine();
        } else {
            return readLine0();
        }
    }

    public BigInteger nextBigInteger() {
        try {
            return new BigInteger(nextString());
        } catch (NumberFormatException e) {
            throw new InputMismatchException();
        }
    }

    public char nextCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

    public double nextDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c == 'e' || c == 'E') {
                return res * Math.pow(10, nextInt());
            }
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public boolean isExhausted() {
        int value;
        while (isSpaceChar(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return nextString();
    }

    public SpaceCharFilter getFilter() {
        return filter;
    }

    public void setFilter(SpaceCharFilter filter) {
        this.filter = filter;
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

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

}