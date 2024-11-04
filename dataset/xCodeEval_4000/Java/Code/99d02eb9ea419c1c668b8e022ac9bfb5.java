import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class E {
    static int n,m,q;
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
            assert (h != null) && isRed(h.left);
            

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
            assert (h != null) && isRed(h.right);
            

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
            


            if (isRed(h.right) && !isRed(h.left))    h = rotateLeft(h);
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
            if (isEmpty()) return new LinkedList<>();
            return keys(min(), max());
        }

        
        public Iterable<Key> keys(Key lo, Key hi) {
            if (lo == null) throw new IllegalArgumentException("first argument to keys() is null");
            if (hi == null) throw new IllegalArgumentException("second argument to keys() is null");

            Queue<Key> queue = new LinkedList<Key>();
            

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
    static class Cell implements Comparable<Cell> {
        int x,y;

        public Cell(int x, int y) {
            this.x=x;this.y=y;
        }
        public int distTo(Cell o) {
            return Math.abs(this.x + this.y - (o.x + o.y));
        }
        @Override
        public int compareTo(Cell o) {
            if (this.x + this.y != o.x + o.y) {
                return this.x + this.y - (o.x + o.y);
            }
            return this.x - o.x;
        }
        @Override
        public int hashCode() {
            return x*n+y;
        }
        @Override
        public boolean equals(Object o) {
            if (!(o instanceof  Cell)) return false;
            Cell c=(Cell) o;
            return c.x==x && c.y==y;
        }
    }
    static class Stair {
        int startx, starty;
        boolean startRight;
        int len;
        RedBlackBST<Cell, Integer> blocked = new RedBlackBST<>();
        public Stair(int x, int y, boolean right) {
            startx=x; starty=y; startRight=right;
            len = allCells().size();
        }
        public ArrayList<Cell> allCells() {
            ArrayList<Cell> l=new ArrayList<>();
            int x=startx, y=starty;
            boolean right=startRight;
            while (x>=0 && x<n && y>=0 && y<m) {
                l.add(new Cell(x,y));
                if (right) {y++;} else {x++;}
                right = !right;
            }
            return l;
        }
        public long initCount() {
            return (long) len*(len+1)/2 - len;
        }
        public int pos(Cell c) {  

            return c.x+c.y-startx-starty;
        }
        public int pos(int x, int y) {return pos(new Cell(x,y));}
        public long block(Cell c) {
            if (blocked.contains(c)) return 0;
            long change = 0;
            long before=0, after=0;  

            Cell prev, next;
            try {
                prev = blocked.floor(c);
            } catch (NoSuchElementException e) {
                prev = null;
            }
            try {
                next = blocked.ceiling(c);
            } catch (NoSuchElementException e) {
                next = null;
            }
            before = (prev==null)? pos(c): c.distTo(prev)-1;
            after = (next==null)? len-pos(c)-1: c.distTo(next)-1;
            change -= before * (after+1) + after * (before+1) - before*after;


            blocked.put(c, 1);
            

            

            return change;
        }
        public long block(int x, int y) {return block(new Cell(x,y));}

        public long free(Cell c) {
            if (!blocked.contains(c)) return 0;
            long change = 0;
            long before=0, after=0;  

            Cell prev, next;
            blocked.delete(c);

            try {
                prev = blocked.floor(c);
            } catch (NoSuchElementException e) {
                prev = null;
            }
            try {
                next = blocked.ceiling(c);
            } catch (NoSuchElementException e) {
                next = null;
            }
            before = (prev==null)? pos(c): c.distTo(prev)-1;
            after = (next==null)? len-pos(c)-1: c.distTo(next)-1;
            change += before * (after+1) + after * (before+1)-before*after;

            

            

            return change;
        }
        public long free(int x, int y) {return free(new Cell(x,y));}
    }

    static boolean[][] blocked;
    static ArrayList<Stair> stairs=new ArrayList<>();
    static HashMap<Cell, ArrayList<Stair>> passthu = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] str=in.readLine().split(" ");
        n=Integer.parseInt(str[0]);
        m=Integer.parseInt(str[1]);
        q=Integer.parseInt(str[2]);

        blocked = new boolean[n][m];
        long sum = 0;
        for (int j=0; j<m-1; j++) {
            Stair st = new Stair(0, j, true);
            stairs.add(st);
            for (Cell c : st.allCells()) {
                passthu.putIfAbsent(c, new ArrayList<>());
                passthu.get(c).add(st);
            }
            sum += st.initCount();
            

        }
        for (int i=0; i<n-1; i++) {
            Stair st = new Stair(i, 0, false);
            stairs.add(st);
            for (Cell c : st.allCells()) {
                passthu.putIfAbsent(c, new ArrayList<>());
                passthu.get(c).add(st);
            }
            sum += st.initCount();
            

        }
        sum += n*m;  

        


        for (int i=0;i<q;i++) {
            str=in.readLine().split(" ");
            int x=Integer.parseInt(str[0])-1;
            int y=Integer.parseInt(str[1])-1;
            Cell c=new Cell(x,y);
            

            for (Stair st : passthu.getOrDefault(c, new ArrayList<>())) {
                if (blocked[x][y]) {
                    

                    sum += st.free(c);
                } else {
                    

                    sum += st.block(c);
                    

                }
            }
            if (blocked[x][y]) {
                sum += 1;  

                blocked[x][y]=false;
            } else {
                sum -= 1;  

                blocked[x][y]=true;
            }
            System.out.println(sum);
        }
    }
}
