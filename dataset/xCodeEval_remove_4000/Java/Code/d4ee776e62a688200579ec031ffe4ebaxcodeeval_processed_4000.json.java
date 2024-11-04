import java.util.*;
import java.io.*;
import java.math.*;

public class f {

    static int n, m;
    static SuperBIT bit;
    
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        n = in.nextInt();
        m = in.nextInt();
        
        bit = new SuperBIT(n + 2);
        char[] str = in.next().toCharArray();
        
        int[] nexts = new int[n];
        int[] prevs = new int[n];
        int[] idxs = new int[256];
        boolean[] valid = new boolean[n];
        Arrays.fill(valid, true);
        id9<Integer, Integer>[] treaps = new id9[256];
        for (int i = 0; i < 256; i++)
            treaps[i] = new id9<>();
        Arrays.fill(nexts, -1);
        Arrays.fill(idxs, -1);
        for (int i = 0; i < n; i++) {
            int c = (int) str[i];
            treaps[c] = treaps[c].add(i);
            prevs[i] = idxs[c];
            if (idxs[c] != -1)
                nexts[idxs[c]] = i;
            idxs[c] = i;
        }
        
        for (int i = 0; i < m; i++) {
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            int c = (int) in.next().charAt(0);
            int v = findFirst(treaps[c], left, right);
            int off = 0;
            while (v != -1) {
                int idx = getIndex(v) + off++;
                if (idx > right) break;
                valid[v] = false;
                treaps[c] = treaps[c].remove(v);
                bit.update(v + 1, n + 1, -1);
                
                if (prevs[v] != -1)
                    nexts[prevs[v]] = nexts[v];
                if (nexts[v] != -1)
                    prevs[nexts[v]] = prevs[v];
                
                v = nexts[v];
            }
        }
        
        for (int i = 0; i < n; i++)
            if (valid[i])
                out.print(str[i]);
        out.println();
        
        out.close();
    }

    static int findFirst(id9<Integer, Integer> t, int left, int right) {
        if (t.size() == 0) return -1;
        return bs(t, 0, t.size() - 1, left, right);
    }
    
    static int bs(id9<Integer, Integer> t, int min, int max, int left, int right) {
        if (min + 1 >= max) {
            int tmp = t.get(min).key;
            int idx = getIndex(tmp);
            if (idx >= left && idx <= right)
                return tmp;
            tmp = t.get(max).key;
            idx = getIndex(tmp);
            if (idx >= left && idx <= right)
                return tmp;
            return -1;
        }
        int mid = (min + max) / 2;
        int idx = getIndex(t.get(mid).key);
        if (idx < left)
            return bs(t, mid, max, left, right);
        return bs(t, min, mid, left, right);
    }
    
    static int getIndex(int i) {
        return i + (int) bit.query(i + 1, i + 1);
    }
    static class id9<K, V> {
        private final Comparator<? super K> comparator;
        Node<K,V> root;
        Random random;
        long king;
        
        public id9() {
            comparator = null;
            random = new Random();
            king = -1;
        }
        public id9(Comparator<? super K> comparator) {
            this.comparator = comparator;
            random = new Random();
            king = -1;
        }
        public id9(id9<K,V> treap) {
            comparator = treap.comparator;
            random = treap.random;
            king = treap.king;
            root = treap.root;
            if (root != null)
                root = new Node<K,V>(root);
        }
        public id9<K,V> add(K key) {
            return put(key, null);
        }
        public id9<K,V> put(K key, V val) {
            id9<K,V> treap = new id9<K,V>(this);
            treap.root = add(treap.root, key, val);
            return treap;
        }
        private Node<K,V> add(Node<K,V> cur, K key, V val) {
            if (cur == null)
                return new Node<K,V>(key, val, random.nextLong() & 0x7FFFFFFFFFFFFFFFL);
            int comp = compareKeys(key, cur.key);
            if (comp == 0) return cur;
            if (comp < 0) {
                cur.id1();
                cur.left = add(cur.left, key, val);
                return rotateLeft(cur);
            } else {
                cur.id3();
                cur.right = add(cur.right, key, val);
                return rotateRight(cur);
            }
        }
        private Node<K,V> rotateLeft(Node<K,V> cur) {
            if (cur.left == null || cur.left.p > cur.p) {
                cur.update();
                return cur;
            }
            Node<K,V> c = cur.left;
            c.id3();
            cur.left = c.right;
            c.right = cur;
            cur.update();
            c.update();
            return c;
        }
        private Node<K,V> rotateRight(Node<K,V> cur) {
            if (cur.right == null || cur.right.p > cur.p) {
                cur.update();
                return cur;
            }
            Node<K,V> c = cur.right;
            c.id3();
            cur.right = c.left;
            c.left = cur;
            cur.update();
            c.update();
            return c;
        }
        public id9<K,V> remove(K key) {
            Node<K,V> node = find(key);
            if (node == null) return this;
            id9<K,V> treap = makeRoot(key);
            treap.root.update();
            treap.root.cloneChildren();
            treap.root = meld(treap.root.left, treap.root.right);
            return treap;
        }
        private Node<K,V> meld(Node<K,V> left, Node<K,V> right) {
            if (left == null || right == null)
                return left == null ? right : left;
            if (left.p <= right.p) {
                left.id3();
                left.right = meld(left.right, right);
                left.update();
                return left;
            } else {
                right.id1();
                right.left = meld(left, right.left);
                right.update();
                return right;
            }
        }
        public id9<K,V> makeRoot(K key) {
            id9<K,V> treap = new id9<K,V>(this);
            treap.root = makeRoot(treap.root, key);
            return treap;
        }
        private Node<K,V> makeRoot(Node<K,V> cur, K key) {
            if (cur == null)
                return cur;
            int comp = compareKeys(key, cur.key);
            if (comp < 0) {
                cur.id1();
                cur.left = makeRoot(cur.left, key);
                cur.update();
                return rotateLeft(cur);
            } else if (comp > 0) {
                cur.id3();
                cur.right = makeRoot(cur.right, key);
                cur.update();
                return rotateRight(cur);
            }
            cur.p = king--;
            cur.update();
            return cur;
        }
        public Node<K,V> find(K key) {
            Node<K,V> cur = root;
            while (cur != null) {
                cur.update();
                int comp = compareKeys(key, cur.key);
                if (comp == 0) break;
                cur = comp < 0 ? cur.left : cur.right;
            }
            return cur;
        }
        boolean contains(K key) {
            return containsKey(key);
        }
        boolean containsKey(K key) {
            return find(key) != null;
        }
        public K ceiling(K key) {
            return id7(key);
        }
        public K id7(K key) {
            Node<K,V> tmp = id0(key);
            return tmp == null ? null : tmp.key;
        }
        public K higher(K key) {
            return higherKey(key);
        }
        public K higherKey(K key) {
            Node<K,V> tmp = higherNode(key);
            return tmp == null ? null : tmp.key;
        }
        public K floor(K key) {
            return floorKey(key);
        }
        public K floorKey(K key) {
            Node<K,V> tmp = floorNode(key);
            return tmp == null ? null : tmp.key;
        }
        public K lower(K key) {
            return lowerKey(key);
        }
        public K lowerKey(K key) {
            Node<K,V> tmp = lowerNode(key);
            return tmp == null ? null : tmp.key;
        }
        public K first(K key) {
            return firstKey(key);
        }
        public K firstKey(K key) {
            Node<K,V> tmp = firstNode();
            return tmp == null ? null : tmp.key;
        }
        public K last(K key) {
            return lastKey(key);
        }
        public K lastKey(K key) {
            Node<K,V> tmp = lastNode();
            return tmp == null ? null : tmp.key;
        }
        public Node<K,V> id0(K key) {
            return id0(root, key);
        }
        private Node<K,V> id0(Node<K,V> cur, K key) {
            if (cur == null)
                return cur;
            int comp = compareKeys(key, cur.key);
            if (comp < 0) {
                Node<K, V> better = id0(cur.left, key);
                if (better != null) return better;
            } else if (comp > 0) {
                return id0(cur.right, key);
            }
            return cur;
        }
        public Node<K,V> higherNode(K key) {
            return higherNode(root, key);
        }
        private Node<K,V> higherNode(Node<K,V> cur, K key) {
            if (cur == null)
                return cur;
            int comp = compareKeys(key, cur.key);
            if (comp < 0) {
                Node<K, V> better = higherNode(cur.left, key);
                if (better != null) return better;
            } else if (comp >= 0) {
                return higherNode(cur.right, key);
            }
            return cur;
        }
        public Node<K,V> floorNode(K key) {
            return floorNode(root, key);
        }
        private Node<K,V> floorNode(Node<K,V> cur, K key) {
            if (cur == null)
                return cur;
            int comp = compareKeys(key, cur.key);
            if (comp < 0) {
                return floorNode(cur.left, key);
            } else if (comp > 0) {
                Node<K,V> better = floorNode(cur.right, key);
                if (better != null) return better;
            }
            return cur;
        }
        public Node<K,V> lowerNode(K key) {
            return lowerNode(root, key);
        }
        private Node<K,V> lowerNode(Node<K,V> cur, K key) {
            if (cur == null)
                return cur;
            int comp = compareKeys(key, cur.key);
            if (comp <= 0) {
                return lowerNode(cur.left, key);
            } else if (comp > 0) {
                Node<K,V> better = lowerNode(cur.right, key);
                if (better != null) return better;
            }
            return cur;
        }
        public Node<K,V> get(int idx) {
            Node<K,V> cur = root;
            while (cur != null) {
                cur.update();
                int left = getSize(cur.left);
                if (left == idx) break;
                if (idx < left) {
                    cur = cur.left;
                } else {
                    cur = cur.right;
                    idx -= left + 1;
                }
            }
            return cur;
        }
        public Node<K,V> firstNode() {
            Node<K,V> cur = root;
            while (cur != null && cur.left != null)
                cur = cur.left;
            return cur;
        }
        public Node<K,V> lastNode() {
            Node<K,V> cur = root;
            while (cur != null && cur.right != null)
                cur = cur.right;
            return cur;
        }
        public int getSize(Node<K, V> node) {
            return node == null ? 0 : node.size;
        }
        public int size() {
            return getSize(root);
        }
        @SuppressWarnings("unchecked")
        private int compareKeys(K a, K b) {
            if (comparator != null)
                return comparator.compare(a, b);
            return ((Comparable<? super K>) a).compareTo(b);
        }
        
        @SuppressWarnings("unchecked")
        class Node<K, V> {
            private Node<K,V> left = null, right = null;
            public K key;
            public V val;
            private long p;
            private int size;
            
            public Node(K key, V val) {
                this.key = key;
                this.val = val;
                update();
                resetPriority();
            }
            public Node(K key, V val, long p) {
                this.key = key;
                this.val = val;
                this.p = p;
                update();
            }
            public Node(Node<K,V> node) {
                key = node.key;
                val = node.val;
                left = node.left;
                right = node.right;
                size = node.size;
                p = node.p;
            }
            private void cloneChildren() {
                id1();
                id3();
            }
            private void id1() {
                if (left != null)
                    left = new Node<K,V>(left);
            }
            private void id3() {
                if (right != null)
                    right = new Node<K,V>(right);
            }
            private void resetPriority() {
                p = id9.this.random.nextLong() & 0x7FFFFFFFFFFFFFFFL;
            }
            private void update() {
                size = 1;
                if (left != null) size += left.size;
                if (right != null) size += right.size;
            }
        }
    }
static class SuperBIT {
  long[] dataMul, dataAdd;
  SuperBIT(int n) {
    dataMul = new long[n];
    dataAdd = new long[n];
  }
  void update(int left, int right, long val) {
    internalUpdate(left, val, -val * (left-1));
    internalUpdate(right, -val, val * right);
  }
  void internalUpdate(int at, long mul, long add) {
    while (at < dataMul.length) {
      dataMul[at] += mul;
      dataAdd[at] += add;
      at |= (at + 1);
    }
  }
  long query(int at) {
    long mul = 0;
    long add = 0;
    int start = at;
    while(at >= 0) {
      mul += dataMul[at];
      add += dataAdd[at];
      at = (at & (at + 1)) -1;
    }
    return mul * start + add;
  }
  long query(int left, int right) {
    if (left > right) {
      int temp = left;
      left = right;
      right = temp;
    }
    return query(right) - (left > 0 ? query(left-1) : 0);
  }
  long[] indices; 

  

  

  

  

  public SuperBIT(long[] indices) {
    this.indices = indices;
    dataMul = new long[indices.length];
    dataAdd = new long[indices.length];
  }
 
  

  

  int binSearch(int ind) {
    int low = 0;
    int high = dataMul.length-1;
    while(low < high) {
      int mid = (low + high+1)/2;
      if(indices[mid] == ind)
        return mid;
      else if(indices[mid] < ind) 
        low = mid;
      else if(indices[mid] > ind) 
        high = mid-1;
    }
    if(indices[low] > ind)
      --low;
    return low;
  }
  
  

  long queryCompr(int index) {
    return query(binSearch(index));
  }
  long queryCompr(int left, int right) {
    return query(binSearch(left), binSearch(right));
  }
  

  

  void updateCompr(int index, long val) {
    int ind = binSearch(index);
    update(ind, ind, val);
  }
  void updateCompr(int left, int right, long val) {
    update(binSearch(left), binSearch(right), val);
  } 
}
    static Random rand = new Random();
    static void sort(int[] a) {
        int n = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
    }
    static void sort(long[] a) {
        int n = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            long tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
    }
    static void sort(double[] a) {
        int n = a.length;
        for (int i = a.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1);
            double tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    static long lcm(long a, long b) { return a / gcd(a, b) * b; }
    static long[] id6(long a, long b) {
        if (b == 0) return new long[] { a, 1, 0 };
        long[] ans = id6(b, a % b);
        long temp = ans[1] - ans[2] * (a / b);
        ans[1] = ans[2];  ans[2] = temp;
        return ans;
    }
    static long modInverse(long a, long m) {
        return ((id6(a, m)[1] % m) + m) % m;
    }
    static class IntList {
        static int[] EMPTY = {};
        int[] a = EMPTY;
        int n = 0;
        void add(int v) {
            if (n >= a.length)
                a = Arrays.copyOf(a, (n << 2) + 8);
            a[n++] = v;
        }
        int get(int idx) {
            return a[idx];
        }
        int size() {
            return n;
        }
    }
    static class id5 {
        int[] s, r;	
	public id5(int n) {
            s = new int[n]; r = new int[n];
            for (int i = 0; i < n; i++) s[i] = i;
        }	
        public int find(int i) { return s[i] == i ? i : (s[i] = find(s[i])); }
	public void union(int a, int b) {
            if(r[a = find(a)] == r[b = find(b)]) r[a]++;
            if(r[a] >= r[b]) s[b] = a; else s[a] = b;
        }
    }
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        public FastScanner(InputStream i) {
            br = new BufferedReader(new InputStreamReader(i));
            st = new StringTokenizer("");
        }
        public String next() throws IOException {
            if(st.hasMoreTokens())
                return st.nextToken();
            else
                st = new StringTokenizer(br.readLine());
            return next();
        }
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public int[] id2(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt() - 1;
            return arr;
        }
        public int[] id4(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }
        public int[][] id4(int n, int m) throws IOException {
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    arr[i][j] = nextInt();
            return arr;
        }
        public long[] id11(int n) throws IOException {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextLong();
            return arr;
        }
        public long[][] id11(int n, int m) throws IOException {
            long[][] arr = new long[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    arr[i][j] = nextLong();
            return arr;
        }
        public double[] id10(int n) throws IOException {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextDouble();
            return arr;
        }
        public double[][] id10(int n, int m) throws IOException {
            double[][] arr = new double[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    arr[i][j] = nextDouble();
            return arr;
        }
        public char[][] id8(int n, int m) throws IOException {
            char[][] arr = new char[n][];
            for (int i = 0; i < n; i++)
                arr[i] = next().toCharArray();
            return arr;
        }
    }
}
