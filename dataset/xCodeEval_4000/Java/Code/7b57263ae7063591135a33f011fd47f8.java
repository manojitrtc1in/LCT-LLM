
import java.io.*;
import java.util.*;

public class Test {

    private static int MAX = (int)1e6;
    private static int HORIZONTAL = 1;
    private static int VERTICAL_RIGHT = 0;
    private static int VERTICAL_LEFT = 2;


    public static void main(String[] args) throws IOException {

     


        


        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String line = reader.readLine();

        String[] s = line.split("\\s");

        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);

        List<Horizontal> horizontal = new ArrayList<>();

        for (int i = 0; i < n; i++) {

            line = reader.readLine();

            s = line.split("\\s");

            int y = Integer.parseInt(s[0]);
            int lx = Integer.parseInt(s[1]);
            int rx = Integer.parseInt(s[2]);

            horizontal.add(new Horizontal(y, lx, rx));
        }

        List<Vertical> vertical = new ArrayList<>();

        for (int i = 0; i < m; i++ ) {
            line = reader.readLine();

            s = line.split("\\s");

            int x = Integer.parseInt(s[0]);
            int ly = Integer.parseInt(s[1]);
            int ry = Integer.parseInt(s[2]);

            vertical.add(new Vertical(x, ly, ry));
        }

        long ans = solve(horizontal, vertical);

        System.out.println(ans);
    }

    private static long solve(List<Horizontal> horizontal, List<Vertical> vertical)  {
        RedBlackBST<Integer, Boolean> temp = new RedBlackBST<>();
        RedBlackBST<Integer, Boolean> sweepSet = new RedBlackBST<>();

        PriorityQueue<Event> pq = new PriorityQueue<>(new Comparator<Event>() {
            @Override
            public int compare(Event e1, Event e2) {
                if (e1.y == e2.y) {

                    return Integer.compare(e1.eventType, e2.eventType);

                }

                return -Integer.compare(e1.y, e2.y);
            }
        });


        pq.add(new Event(0, MAX, HORIZONTAL, MAX, -1));
        pq.add(new Event(0, MAX, HORIZONTAL, 0, -1));
        for (Horizontal h : horizontal) {
            pq.add(new Event(h.lx, h.rx, HORIZONTAL, h.y, -1));
        }

        for (int i = 0; i < vertical.size(); i++) {
            Vertical v = vertical.get(i);
            pq.add(new Event(v.x, v.x, VERTICAL_RIGHT, v.ry, i));
            pq.add(new Event(v.x, v.x, VERTICAL_LEFT, v.ly, i));
        }


        long count = 0;


        for (;pq.size() > 0;) {

            Event event = pq.poll();

            if (event.eventType == VERTICAL_RIGHT) {
                temp.put(event.lx, true);


            } else if (event.eventType == HORIZONTAL) {
                int start = event.lx;
                int end = event.rx;

                int size = sweepSet.size(start, end);
                count += size;

                Iterable<Integer> sub = temp.keys(start, end);
                Iterator<Integer> iter = sub.iterator();
                while(iter.hasNext()) {
                    Integer x = iter.next();
                    sweepSet.put(x, true);
                    iter.remove();
                    temp.delete(x);
                }

                if (start == 0 && end == MAX && event.y != MAX) {
                    count++;
                }

            } else {
                temp.delete(event.lx);
                sweepSet.delete(event.lx);
            }
        }


        return count;
    }

    public static class Horizontal {

        Horizontal(int y, int lx, int rx) {
            this.y = y;
            this.lx = lx;
            this.rx = rx;
        }

        int y, lx, rx;
    }

    public static class Vertical {

        Vertical(int x, int ly, int ry) {
            this.x = x;
            this.ly = ly;
            this.ry = ry;
        }

        int x, ly, ry;
    }

    public static class Event {
        int lx, rx, eventType, y, value;

        Event(int lx, int rx, int eventType, int y, int value) {
            this.lx = lx;
            this.rx = rx;
            this.eventType = eventType;
            this.y = y;
            this.value = value;
        }
    }



    public static class RedBlackBST<Key extends Comparable<Key>, Value> {

        private static final boolean RED   = true;
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
                if      (cmp < 0) x = x.left;
                else if (cmp > 0) x = x.right;
                else              return x.val;
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
            if      (cmp < 0) h.left  = put(h.left,  key, val);
            else if (cmp > 0) h.right = put(h.right, key, val);
            else              h.val   = val;

            

            if (isRed(h.right) && !isRed(h.left))      h = rotateLeft(h);
            if (isRed(h.left)  &&  isRed(h.left.left)) h = rotateRight(h);
            if (isRed(h.left)  &&  isRed(h.right))     flipColors(h);
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
            


            if (key.compareTo(h.key) < 0)  {
                if (!isRed(h.left) && !isRed(h.left.left))
                    h = moveRedLeft(h);
                h.left = delete(h.left, key);
            }
            else {
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
                }
                else h.right = delete(h.right, key);
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
            


            if (isRed(h.right))                      h = rotateLeft(h);
            if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h);
            if (isRed(h.left) && isRed(h.right))     flipColors(h);

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
            else                return min(x.left);
        }

        
        public Key max() {
            if (isEmpty()) throw new NoSuchElementException("calls max() with empty symbol table");
            return max(root).key;
        }

        

        private Node max(Node x) {
            

            if (x.right == null) return x;
            else                 return max(x.right);
        }


        
        public Key floor(Key key) {
            if (key == null) throw new IllegalArgumentException("argument to floor() is null");
            if (isEmpty()) throw new NoSuchElementException("calls floor() with empty symbol table");
            Node x = floor(root, key);
            if (x == null) throw new NoSuchElementException("argument to floor() is too small");
            else           return x.key;
        }

        

        private Node floor(Node x, Key key) {
            if (x == null) return null;
            int cmp = key.compareTo(x.key);
            if (cmp == 0) return x;
            if (cmp < 0)  return floor(x.left, key);
            Node t = floor(x.right, key);
            if (t != null) return t;
            else           return x;
        }

        
        public Key ceiling(Key key) {
            if (key == null) throw new IllegalArgumentException("argument to ceiling() is null");
            if (isEmpty()) throw new NoSuchElementException("calls ceiling() with empty symbol table");
            Node x = ceiling(root, key);
            if (x == null) throw new NoSuchElementException("argument to ceiling() is too small");
            else           return x.key;
        }

        

        private Node ceiling(Node x, Key key) {
            if (x == null) return null;
            int cmp = key.compareTo(x.key);
            if (cmp == 0) return x;
            if (cmp > 0)  return ceiling(x.right, key);
            Node t = ceiling(x.left, key);
            if (t != null) return t;
            else           return x;
        }

        
        public Key select(int rank) {
            if (rank < 0 || rank >= size()) {
                throw new IllegalArgumentException("argument to select() is invalid: " + rank);
            }
            return select(root, rank);
        }

        

        

        private Key select(Node x, int rank) {
            if (x == null) return null;
            int leftSize = size(x.left);
            if      (leftSize > rank) return select(x.left,  rank);
            else if (leftSize < rank) return select(x.right, rank - leftSize - 1);
            else                      return x.key;
        }

        
        public int rank(Key key) {
            if (key == null) throw new IllegalArgumentException("argument to rank() is null");
            return rank(key, root);
        }

        

        private int rank(Key key, Node x) {
            if (x == null) return 0;
            int cmp = key.compareTo(x.key);
            if      (cmp < 0) return rank(key, x.left);
            else if (cmp > 0) return 1 + size(x.left) + rank(key, x.right);
            else              return size(x.left);
        }

        

        
        public Iterable<Key> keys() {
            if (isEmpty()) return new ArrayList<>();
            return keys(min(), max());
        }

        
        public Iterable<Key> keys(Key lo, Key hi) {
            if (lo == null) throw new IllegalArgumentException("first argument to keys() is null");
            if (hi == null) throw new IllegalArgumentException("second argument to keys() is null");

            List<Key> queue = new ArrayList<>();
            

            keys(root, queue, lo, hi);
            return queue;
        }

        

        

        private void keys(Node x, List<Key> queue, Key lo, Key hi) {
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
            else              return rank(hi) - rank(lo);
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

        

        private boolean isSizeConsistent() { return isSizeConsistent(root); }
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

        

        

        private boolean is23() { return is23(root); }
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

}
